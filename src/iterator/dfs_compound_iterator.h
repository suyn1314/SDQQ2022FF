#pragma once

#include "iterator.h"
#include "../shape.h"

#include <stack>
#include "null_iterator.h"

class CompoundShape;

//https://www.boost.org/doc/libs/1_63_0/libs/graph/doc/DFSVisitor.html

template<class ForwardIterator>
class DFSCompoundIterator : public Iterator{
private:
  ForwardIterator _begin;
  ForwardIterator _end;
  ForwardIterator _top{};
  std::stack<Iterator*> _visit{};
  Shape* _current = nullptr;
  Iterator* _iterator = new NullIterator{};

public:
    DFSCompoundIterator(ForwardIterator begin, ForwardIterator end) : _begin(begin), _end(end){first();
    }~DFSCompoundIterator() {delete _iterator;}

    void first() override {
      _visit = std::stack<Iterator*>{};
      _top = _begin;
      if(_top != _end){SaveVisitAndCreateIterator();}
    }

    Shape* currentItem() const override {
     if (isDone()) {throw std::string("isDone!");}
      return _current;
    }

    void next() override {
    if (isDone()) {throw std::string("isDone!");}

    if (!_iterator->isDone()) {_iterator->next();}

    if (_iterator->isDone() && !_visit.empty()) {
      delete _iterator;
      _iterator = _visit.top();
      _visit.pop();
    }

    if (!_iterator->isDone()) {Visit(_iterator->currentItem());}

    if (_iterator->isDone() && _visit.empty()) {_top++;
      if (!isDone()) {SaveVisitAndCreateIterator();}
      }
    }

    bool isDone() const override {return (_top == _end) && _iterator && _visit.empty();}

    void Visit(Shape* shape){
      _current = shape;
    }

    void PushChildToVisit(Iterator* child){
      if (!child->isDone()) {
        child->first();
        _visit.push(child);
      }
    }

    void SaveVisitAndCreateIterator(){
      Visit(*_top);
      PushChildToVisit((*_top)->createDFSIterator());
    }

};
