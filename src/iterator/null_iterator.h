#pragma once

#include "iterator.h"

class NullIterator : public Iterator{
public:
    void first() override {throw std::string("This is Null Iterator!");}

    Shape* currentItem() const override {throw std::string("This is Null Iterator!");}

    void next() override {throw std::string("This is Null Iterator!");}

    bool isDone() const override {return true;}
};
