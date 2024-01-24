#ifndef NAIVE_HPP
#define NAIVE_HPP

#include <iostream>
#include <map>
#include <functional>
#include <cmath>

using namespace std;

class Naive {
    public:
        bool naiveCircle(float userX, float userY, vector <float> circleCoords);
        bool naiveTriangle(float userX, float userY, vector <float> triangleCoords);
        bool naiveRectangle(float userX, float userY, vector <float> rectangleCoords);
};

#endif