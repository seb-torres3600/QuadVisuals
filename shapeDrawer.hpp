#ifndef SHAPEDRAWER_HPP
#define SHAPEDRAWER_HPP

#include <iostream>
#include <GLUT/glut.h>
#include <GLFW/glfw3.h>
#include <map>
#include <functional>

using namespace std;

class ShapeDrawer {
    private:
        void drawCircle(vector<float> coords, bool g);
        void drawTriangle(vector<float> coords, bool g);
        void drawRectangle(vector<float> coords, bool g);
    public:
        void drawShape(string shape, vector<float> values, bool g);
};

#endif