#pragma once

#include "iterator.h"
#include "../shape.h"

class CompoundShape;

template<class ForwardIterator>
class DFSCompoundIterator : public Iterator{
private:
  ForwardIterator _begin;
  ForwardIterator _end;
  ForwardIterator _current;
public:
    DFSCompoundIterator(ForwardIterator begin, ForwardIterator end)
    : _begin(begin), _end(end){first();}

    void first() override {_current = _begin;}

    Shape* currentItem() const override {
      if (isDone()) {throw std::string("isDone!");}
      else{return *_current;}}

    void next() override {
      if (isDone()) {throw std::string("isDone!");}
      else{_current++;}}

    bool isDone() const override {return _current == _end;}
};
