// option 11
#include <iostream>
#include <cmath>

using namespace std;

class GeometricFigure {
protected:
    double dimension{};
public:
    virtual double calculateArea() = 0;

    void setDimension(double size) {
        this->dimension = size;
    }
};

class Trapeze : public GeometricFigure {
public:
    double calculateArea() override {
        return dimension * dimension;
    }
};

class Triangle : public GeometricFigure {
public:
    double calculateArea() override {
        return dimension * dimension / 2;
    }
};

class EquilateralTriangle : public Triangle {
public:
    double calculateArea() override {
        return (cbrt(3) / 4) * pow(dimension, 2);
    }
};

int main() {
    Trapeze trapeze;
    Triangle triangle;
    EquilateralTriangle equilateralTriangle;

    trapeze.setDimension(18);
    triangle.setDimension(20);
    equilateralTriangle.setDimension(22);

    cout << "Area of trapeze: " << trapeze.calculateArea() << "\n";
    cout << "Area of triangle: " << triangle.calculateArea() << "\n";
    cout << "Area of equilateral triangle: " << equilateralTriangle.calculateArea() << "\n";
}