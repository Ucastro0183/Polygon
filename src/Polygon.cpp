#include "Polygon.h"
using namespace std;

Polygon::Polygon()
{
    this->coordinates = new vector<Point>();
}

Polygon::Polygon(const vector<Point> c) {
    this->coordinates = new vector<Point>;
    for (auto it: c) {
        this->coordinates->push_back(it);
    }
}

Polygon::~Polygon()
{
    delete coordinates;
}

double Polygon::getArea() {
    double area=0;

    if (coordinates->size()==0) return 0;

    Point last = coordinates->back();

    for (Point it: *coordinates) {
        area += (it.x*last.y)-(it.y*last.x);
        last = it;
    }
    return area/2;
};

double Polygon::getPerimeter() {
    double perimeter=0;

    if (coordinates->size()==0) return 0;

    Point last = coordinates->back();

    for (Point it: *coordinates) {
        perimeter += last.dist(it);
        last=it;
    }
    return perimeter;
};

vector<Point> Polygon::getCoordinates(){
    return *coordinates;
}

void Polygon::addCoordinate(double x, double y){
    coordinates->push_back(Point(x,y));
}

