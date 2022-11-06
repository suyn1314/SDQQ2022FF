#pragma once
#include "../null_iterator.h"
#include "./iterator_factory.h"
#include "../list_compound_iterator.h"

class ListIteratorFactory : public IteratorFactory{
    Iterator *createIterator(){return new NullIterator();}
    Iterator *createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end){
        return new ListCompoundIterator(begin, end);
    }
};
