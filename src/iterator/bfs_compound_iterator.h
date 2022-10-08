#pragma once

#include "iterator.h"
#include "../shape.h"
#include <queue>
#include "null_iterator.h"

template<class ForwardIterator>
class BFSCompoundIterator : public Iterator{
private:
  ForwardIterator _begin;
  ForwardIterator _end;
  ForwardIterator _top;
  std::queue<Iterator*> _visit{};
  Shape* _current = nullptr;
  Iterator* _iterator = new NullIterator{};

public:
    BFSCompoundIterator(ForwardIterator begin, ForwardIterator end): _begin(begin), _end(end){first();
    }~BFSCompoundIterator() {delete _iterator;}

    void first() override {
      _visit = std::queue<Iterator*>{};
      _top = _begin;
      if (_top != _end) {SaveVisitAndCreateIterator();}
    }

    Shape* currentItem() const override {
      if (isDone()) {throw std::string("isDone!");}
      else{return _current;}}

    void next() override {
      if (isDone()) {throw std::string("isDone!");}

      if (_top != _end) {
        _top++;
        if (_top != _end) {
          SaveVisitAndCreateIterator();
          return;
        }
      }
      if (!_iterator->isDone()) {_iterator->next();}
      if (_iterator->isDone() && !_visit.empty()) {
        delete _iterator;
        _iterator = _visit.front();
        _visit.pop();
      }

      if (!_iterator->isDone()) {
        Visit(_iterator->currentItem());
      }
    }

    bool isDone() const override {return (_top == _end) && _iterator->isDone() && _visit.empty();}

    void Visit(Shape* shape) {_current = shape;}

    void PushChildToVisit(Iterator* child){
      if (!child->isDone()) {
        child->first();
        _visit.push(child);
      }
    }

    void SaveVisitAndCreateIterator(){
      Visit(*_top);
      PushChildToVisit((*_top)->createBFSIterator());
    }
};
