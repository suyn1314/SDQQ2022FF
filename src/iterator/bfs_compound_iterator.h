#pragma once

#include "iterator.h"
#include "../shape.h"

class CompoundShape;

template<class ForwardIterator>
class BFSCompoundIterator : public Iterator{
private:
  const ForwardIterator& _begin;
  const ForwardIterator& _end;
  ForwardIterator _current;
public:
    BFSCompoundIterator(ForwardIterator begin, ForwardIterator end)
    : _begin(begin), _end(end){}

  /** Restarts the iteration. */
    void first() override {
      _current = _begin;
    }

    Shape* currentItem() const override {
      if (isDone()) {throw IteratorDoneException{""};}
      return *_current;
    }

    void next() override {
      if (isDone()) {throw IteratorDoneException{""};}
      ++_current;
    }

    bool isDone() const override {return *_current == *_end;}


};
