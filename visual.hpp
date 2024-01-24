#ifndef VISUAL_HPP
#define VISUAL_HPP

#include <GLUT/glut.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include <nlohmann/json.hpp>

#include "user.hpp"
#include "shapeDrawer.hpp"
#include "data.hpp"

using namespace std;
using json = nlohmann::json;

class Visual {
    private:
        Visual();
        static Visual* displayer;
        User* user1;
        ShapeDrawer drawer;
        Data* zones;
        string greenIndex;
        GLFWwindow* window;
        vector <double> clicked_coords;

    public:
        static Visual* getInstance();
        void display();
        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void mouseCallback(GLFWwindow* window, int button, int action, int mods);
        int showVisuals();
        int waitForClicks(int number);
        void keyCallbackImpl(GLFWwindow* window, int key, int scancode, int action, int mods);
        void setUser(User* user);
        void setData(Data* data);
        void setGreenId(string id);
        void expectCoordinates(int number_of_coordinates);
        void setClick(double value);
    };

#endif