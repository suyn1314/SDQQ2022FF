#pragma once
#include <list>
class Shape;
class CompoundShape;
class Iterator{
public:
    virtual ~Iterator() = default;
    virtual void first() = 0;
    virtual Shape* currentItem() const = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;

    class IteratorDoneException : public std::runtime_error {
      using std::runtime_error::runtime_error;
    };
};
