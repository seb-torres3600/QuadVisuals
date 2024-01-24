#include "user.hpp"

User* User:: tracker = NULL;

User:: User(){
    xCoordinate = 0.0f;
    yCoordinate = 0.0f;
    moveSpeed = 0.02f;
}

User* User:: getInstance(){
    if (tracker == NULL){
        tracker = new User();
    }
    return tracker;
}

Coordinates User :: getCoordinates(){
    Coordinates currentPosition;
    currentPosition.xCoor = xCoordinate;
    currentPosition.yCoor = yCoordinate;
    return currentPosition;
}

void User ::moveUser(int key) {
    switch (key) {
        case GLFW_KEY_LEFT:
            xCoordinate -= moveSpeed;
            break;
        case GLFW_KEY_RIGHT:
            xCoordinate += moveSpeed;
            break;
        case GLFW_KEY_UP:
            yCoordinate += moveSpeed;
            break;
        case GLFW_KEY_DOWN:
            yCoordinate -= moveSpeed;
            break;
    }
}

void User :: drawUser(float radius, int numSegments) {
    glBegin(GL_TRIANGLE_FAN); // Use GL_TRIANGLE_FAN to fill the circle
    glColor3f(0.0, 0.0, 0.0); // Set circle color (black)
    glVertex2f(xCoordinate, yCoordinate); // Center of the circle

    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * M_PI * float(i) / float(numSegments);
        float x = xCoordinate + radius * cos(theta);
        float y = yCoordinate + radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

