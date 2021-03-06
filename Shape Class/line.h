#ifndef LINE_H_
#define LINE_H_

#include <QPaintDevice>
#include <QPen>
#include <QPoint>
#include "Shape.h"

const int NUM_LINE_SPECS = 4;

class Line: public Shape
{
public:
    // Default
    Line();

    // CREATE SHAPE_DIMENSIONS ARRAY BEFORE FEEDING INTO CONSTRUCTOR
    Line(int shapeId, std::string shapeType, int numDimensions, dim::specs* shapeDimensions)
          :Shape(shapeId, shapeType, numDimensions, shapeDimensions)
          {}

    ~Line() override {}

    // Return label for this spec index
    std::string getSpec(int specNum) const override {return DimensionLabels[specNum];}

    // Calc perimeter
    dim::perimeter calcPerimeter() const override;
    // Calc area
    dim::area calcArea() const override {return 0;}

    void draw() override;

    void move(const QPoint &shift) override;

    void setPoints();

    std::string print() const override;




private:
    enum class Specifications{X1, Y1, X2, Y2};
    std::string DimensionLabels[NUM_LINE_SPECS]{"x1", "y1","x2", "y2"};
    QPoint point1;
    QPoint point2;
};















#endif /*LINE_H_*/




