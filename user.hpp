#ifndef USER_HPP
#define USER_HPP

#include <GLUT/glut.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

using namespace std;

struct Coordinates {
    float xCoor;
    float yCoor;
};

class User {
    private:
        float xCoordinate;
        float yCoordinate;
        float moveSpeed;
        static User* tracker;
        User();

    public:
        Coordinates getCoordinates();
        static User* getInstance();
        void setCoordinates(float moveX, float moveY);
        void moveUser(int key);
        void drawUser(float radius, int numSegments);
};

#endif // USER_HPP