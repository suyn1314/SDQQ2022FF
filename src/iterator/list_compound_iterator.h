#pragma once

#include "../shape.h"
#include "iterator.h"

template <class ForwardIterator>
class ListCompoundIterator : public Iterator {
 private:
 ForwardIterator _begin, _end, _current;

 public:
  ListCompoundIterator(const ForwardIterator& begin, const ForwardIterator& end): _begin{begin}, _end{end}, _current{begin} {}

  void first() override {
    if (isDone()) {
      throw std::string("isDone!");;
    }
    _current = _begin;
  }

  void next() override {
    if (isDone()) {
      throw std::string("isDone!");;
    }
    ++_current;
  }

  Shape* currentItem() const {
    if (isDone()) {
      throw std::string("isDone!");;
    }
    return *_current;
  }

  bool isDone() const {
    return _current == _end;
  }

};
