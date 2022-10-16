#pragma once

#include "iterator.h"
#include "../shape.h"
#include "null_iterator.h"
#include <stack>

template<class ForwardIterator>
class DFSCompoundIterator : public Iterator{
private:
  ForwardIterator _begin, _end;
  std::stack<Iterator*> _stack{};
  Shape* _current = nullptr;
  Iterator* _iterator = new NullIterator{};

public:
    DFSCompoundIterator(ForwardIterator begin, ForwardIterator end) : _begin(begin), _end(end){
      first();
    }~DFSCompoundIterator() {delete _iterator;}

    void first() override {
      _stack = std::stack<Iterator*>{};
      if(_begin != _end){SaveTopAndCreateIterator();}}

    Shape* currentItem() const override {
      if (isDone()) {throw std::string("isDone!");}
      else{return _current;}
    }

    void next() override {
      if (isDone()) {throw std::string("isDone!");}

      if (!IteratorIsDone()) {_iterator->next();}

      if (IteratorIsDone() && !_stack.empty()) {
        delete _iterator;//Need to delete iterator here!
        _iterator = _stack.top();//new iterator for stack's top!
        _stack.pop();//pop out stack top reference!
      }

      if (!IteratorIsDone()) {_current = _iterator->currentItem();}

      if (IteratorIsDone() && _stack.empty()) {
        _begin++;//Find Neighbor when stack is empty!
        if (!isDone()) {SaveTopAndCreateIterator();}
        }
    }

    bool isDone() const override { return ( _begin == _end ) && _iterator->isDone() && _stack.empty(); }

    bool IteratorIsDone(){return _iterator->isDone();}

    void PushChildToVisit(Iterator* child){
      if (!child->isDone()) {
        child->first();//go first to find next level child!
        _stack.push(child);//save this child to stack!
      }
    }

    void SaveTopAndCreateIterator(){
      _current = *_begin;//push begin position to current!
      PushChildToVisit((*_begin)->createDFSIterator());//Used createDFSIterator to next level!
    }
};
