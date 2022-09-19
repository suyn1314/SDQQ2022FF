#pragma once

class Shape
{
public:
    //Area With Polymorphism Should Be Correct
    virtual double area() const = 0;
    //Perimeter With Polymorphism Should Be Correct
    virtual double perimeter() const = 0;
    virtual std::string info() const = 0;
    virtual ~Shape() {}
};
