#include <iostream>
#include "fstream"
#include "Polygon.h"

/** Main: entry for execution

    This program reads a text file with the content of the coordinates of a polygon.

    Filename: "Coordinates.txt"

    Each x and y coordinate per line, space separated.

    Note: coordinates shall be given clockwise.

    The program will return Perimeter and Area of the Polygon.
*/
int main()
{
    Polygon p;
    double x=0,y=0;

    try {
        std::ifstream file;
        file.open("Coordinates.txt");

        if (!file.is_open())
            throw std::ifstream::failure("File not found");
        while(!file.eof()) {
            file >> x >> y;
            p.addCoordinate(x,y);
        }
        file.close();

    } catch (std::ifstream::failure *e) {
        std::cerr << e->what();
    }



        std::cout << "Perimeter: " << p.getPerimeter() << std::endl;
        std::cout << "Area: " << p.getArea() << std::endl;

        getchar();

    return 0;
}
