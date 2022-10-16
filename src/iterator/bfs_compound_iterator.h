#pragma once

#include "iterator.h"
#include "../shape.h"
#include "null_iterator.h"
#include <queue>

template<class ForwardIterator>
class BFSCompoundIterator : public Iterator{
private:
  ForwardIterator _begin, _end;
  std::queue<Iterator*> _queue{};
  Shape* _current = nullptr;
  Iterator* _iterator = new NullIterator{};

public:
    BFSCompoundIterator(ForwardIterator begin, ForwardIterator end) : _begin(begin), _end(end){
      first();
    }~BFSCompoundIterator() {delete _iterator;}

    void first() override {
      _queue = std::queue<Iterator*>{};
      if(_begin != _end){SaveTopAndCreateIterator();}}

    Shape* currentItem() const override {
      if (isDone()) {throw std::string("isDone!");}
      else{return _current;}
    }

    void next() override {
      if (isDone()) {throw std::string("isDone!");}

      if (_begin != _end) {
        _begin++;//Find Neighbor until begin == end!
        if (_begin != _end) {
          SaveTopAndCreateIterator();
          return;//Need to stop running in here!
        }
      }

      if (!IteratorIsDone()) { _iterator->next(); }

      if (IteratorIsDone() && !_queue.empty()) {
        delete _iterator;//Need to delete iterator here!
        _iterator = _queue.front();//new iterator for queue's front!
        _queue.pop();//pop out queue front reference!
      }

      if (!IteratorIsDone()) { _current = _iterator->currentItem(); }
    }

    bool isDone() const override { return (_begin == _end) && _iterator->isDone() && _queue.empty(); }

    bool IteratorIsDone(){ return _iterator->isDone(); }

    void PushChildToVisit(Iterator* child){//Find the other child if child is not Done!
      if (!child->isDone()) {
        child->first();//go first to find next level child!
        _queue.push(child);//save this child to queue!
      }
    }

    void SaveTopAndCreateIterator(){
      _current = *_begin;//push top position to current!
      PushChildToVisit((*_begin)->createBFSIterator());//Used createBFSIterator to next level!
    }
};
