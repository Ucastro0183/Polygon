#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include <math.h>

typedef struct point_t{
    double x;
    double y;

    point_t() : x(0), y(0) {};
    point_t(double x, double y) : x(x), y(y) {};

    double dist(point_t p) {
        return sqrt(pow(x-p.x,2)+pow(y-p.y,2));
    };
} Point;

class Polygon
{
    public:
        Polygon();
        Polygon(const std::vector<Point>);
        ~Polygon();


        double getArea();
        double getPerimeter();

        std::vector<Point> getCoordinates();
        void addCoordinate(double, double);

    private:
        std::vector<Point>* coordinates;
};

#endif // POLYGON_H
