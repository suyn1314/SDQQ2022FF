#pragma once

#include "iterator.h"
#include "../shape.h"

class CompoundShape;

template<class ForwardIterator>
class DFSCompoundIterator : public Iterator{
private:
  const ForwardIterator& _begin;
  const ForwardIterator& _end;
  ForwardIterator _current;
public:
    DFSCompoundIterator(ForwardIterator begin, ForwardIterator end)
    : _begin(begin), _end(end){}


    void first() override {
      _current = _begin;
    }

    Shape* currentItem() const override {
      if (isDone()) {throw std::string("isDone!");}
      return *_current;
    }

    void next() override {
      if (isDone()) {throw std::string("isDone!");}
      ++_current;
    }

    bool isDone() const override {return *_current == *_end;}

};
