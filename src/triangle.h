#pragma once

#include <string>
#include <set>
#include "shape.h"
#include "two_dimensional_vector.h"
#include "./iterator/factory/iterator_factory.h"
#include "./visitor/shape_visitor.h"

class Triangle : public Shape
{
private:
    TwoDimensionalVector _v1;
    TwoDimensionalVector _v2;

public:
    Triangle(TwoDimensionalVector v1, TwoDimensionalVector v2) : _v1(v1), _v2(v2)
    {
        auto isEqual = [=](const Point *a, const Point *b) -> bool
        {
            return *a == *b;
        };

        if (isEqual(v1.a(), v2.a()) ||
            isEqual(v1.b(), v2.b()) ||
            isEqual(v1.b(), v2.a()) ||
            isEqual(v1.a(), v2.b()))
        {
            if (v1.cross(&v2) == 0)
            {
                throw std::string("Two vectors should not be parallel.");
            }
        }
        else
        {
            throw std::string("Two vectors should be connected.");
        }
    }
    ~Triangle() {}

    double area() const override
    {
        return abs(_v1.cross(&_v2)) / 2;
    }

    double perimeter() const override
    {
        auto isEqual = [=](const Point *a, const Point *b) -> bool
        {
            return *a == *b;
        };

        const Point *p1, *p2;
        if (isEqual(_v1.a(), _v2.a()))
        {
            p1 = _v1.b();
            p2 = _v2.b();
        }
        else if (isEqual(_v1.b(), _v2.b()))
        {
            p1 = _v1.a();
            p2 = _v2.a();
        }
        else if (isEqual(_v1.b(), _v2.a()))
        {
            p1 = _v1.a();
            p2 = _v2.b();
        }
        else if (isEqual(_v1.a(), _v2.b()))
        {
            p1 = _v2.a();
            p2 = _v1.b();
        }
        return _v1.length() + _v2.length() + TwoDimensionalVector(*p1, *p2).length();
    }

    std::string info() const override
    {
        return "Triangle (" + _v1.info() + ", " + _v2.info() + ")";
    }

    Iterator *createIterator(IteratorFactory *factory) override
    {
        return factory->createIterator();
    }

    std::set<Point> getPoints() override
    {
        std::set<Point> points = {
            Point(_v1.a()->x(), _v1.a()->y()),
            Point(_v1.b()->x(), _v1.b()->y()),
            Point(_v2.a()->x(), _v2.a()->y()),
            Point(_v2.b()->x(), _v2.b()->y())};
        return points;
    }

    void accept(ShapeVisitor *visitor) override
    {
        visitor->visitTriangle(this);
    }
};