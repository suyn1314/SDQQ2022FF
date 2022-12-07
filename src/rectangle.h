#pragma once

#include <string>
#include <set>
#include "shape.h"
#include "two_dimensional_vector.h"
#include "./iterator/factory/iterator_factory.h"
#include "./visitor/shape_visitor.h"

class Rectangle : public Shape
{
private:
    TwoDimensionalVector _lengthVec;
    TwoDimensionalVector _widthVec;

public:
    Rectangle(TwoDimensionalVector lengthVec, TwoDimensionalVector widthVec) : _lengthVec(lengthVec), _widthVec(widthVec)
    {
        auto isEqual = [=](const Point *a, const Point *b) -> bool
        {
            return *a == *b;
        };

        if (isEqual(_lengthVec.a(), _widthVec.a()) ||
            isEqual(_lengthVec.b(), _widthVec.b()) ||
            isEqual(_lengthVec.b(), _widthVec.a()) ||
            isEqual(_lengthVec.a(), _widthVec.b()))
        {
            if (lengthVec.dot(&widthVec) != 0)
            {
                throw std::string("Two vectors should be orthogonal.");
            }
        }
        else
        {
            throw std::string("Two vectors should be connected.");
        }
    }
    ~Rectangle() {}

    double length() const
    {
        return _lengthVec.length();
    }

    double width() const
    {
        return _lengthVec.length();
    }

    double area() const override
    {
        return _lengthVec.length() * _widthVec.length();
    }

    double perimeter() const override
    {
        return (_lengthVec.length() + _widthVec.length()) * 2;
    }

    std::string info() const override
    {
        return "Rectangle (" + _lengthVec.info() + ", " + _widthVec.info() + ")";
    }

    Iterator *createIterator(IteratorFactory *factory) override
    {
        return factory->createIterator();
    }

    Point findFourthVertex(TwoDimensionalVector *vec1, TwoDimensionalVector *vec2)
    {
        auto isEqual = [=](const Point *a, const Point *b) -> bool
        {
            return *a == *b;
        };

        const Point *A, *B, *C;
        if (isEqual(vec1->a(), vec2->a()))
        {
            A = vec1->b();
            B = vec2->b();
            C = vec1->a();
        }
        else if (isEqual(vec1->b(), vec2->b()))
        {
            A = vec1->a();
            B = vec2->a();
            C = vec1->b();
        }
        else if (isEqual(vec1->b(), vec2->a()))
        {
            A = vec1->a();
            B = vec2->b();
            C = vec1->b();
        }
        else if (isEqual(vec1->a(), vec2->b()))
        {
            A = vec1->b();
            B = vec2->a();
            C = vec1->a();
        }
        return Point(
            A->x() + B->x() - C->x(),
            A->y() + B->y() - C->y());
    }

    std::set<Point> getPoints() override
    {
        std::set<Point> points = {
            Point(_lengthVec.a()->x(), _lengthVec.a()->y()),
            Point(_lengthVec.b()->x(), _lengthVec.b()->y()),
            Point(_widthVec.a()->x(), _widthVec.a()->y()),
            Point(_widthVec.b()->x(), _widthVec.b()->y()),
            this->findFourthVertex(&_lengthVec, &_widthVec)};
        return points;
    }

    void accept(ShapeVisitor *visitor) override
    {
        visitor->visitRectangle(this);
    }
};