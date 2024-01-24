#include "shapeDrawer.hpp"


void ShapeDrawer :: drawRectangle(vector<float> coords, bool g) {

    float x1 = coords[0];
    float x2 = coords[1]; 
    float y1 = coords[2];
    float y2 = coords[3];

    glBegin(GL_QUADS);
    if(g){
        glColor3f(0.0f, 1.0f, 0.0f);
    }
    else{
        glColor3f(1.0, 0.0, 0.0); // Set color to red
    }
    glVertex2f(x1, y1); // Bottom-left corner
    glVertex2f(x2, y1); // Bottom-right corner
    glVertex2f(x2, y2); // Top-right corner
    glVertex2f(x1, y2); // Top-left corner
    glEnd();
}

void ShapeDrawer :: drawTriangle(vector <float> coords, bool g) {
    float x1 = coords[0];
    float y1 = coords[1]; 
    float x2 = coords[2];
    float y2 = coords[3];
    float x3 = coords[4];
    float y3 = coords[5];

    glBegin(GL_TRIANGLES);
    if(g){
        glColor3f(0.0f, 1.0f, 0.0f);
    }
    else{
        glColor3f(1.0, 0.0, 0.0); // Set color to red
    } // Set color to red
    glVertex2f(x1, y1);       // Vertex 1
    glVertex2f(x2, y2);       // Vertex 2
    glVertex2f(x3, y3);       // Vertex 3
    glEnd();
}

void ShapeDrawer :: drawCircle(vector <float> coords, bool g) {
    float centerX = coords[0];
    float centerY = coords[1];
    float radius = coords[2];
    float numSegments = coords[3];

    glBegin(GL_TRIANGLE_FAN);
    if(g){
        glColor3f(0.0f, 1.0f, 0.0f);
    }
    else{
        glColor3f(1.0, 0.0, 0.0); // Set color to red
    }

    for (int i = 0; i <= numSegments; ++i) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + centerX, y + centerY);
    }

    glEnd();
}

void ShapeDrawer :: drawShape(string shape, vector<float> values, bool green = false){
    std::map<std::string, std::function<void(const std::vector<float>&, bool)>> shapeMap;
    shapeMap["rectangle"] = [this](const std::vector<float>& v, bool g) { drawRectangle(v, g); };
    shapeMap["circle"] = [this](const std::vector<float>& v, bool g) { drawCircle(v, g); };
    shapeMap["triangle"] = [this](const std::vector<float>& v, bool g) { drawTriangle(v, g); };
    shapeMap[shape](values, green);
}