#include "naive.hpp"

bool Naive :: naiveCircle(float userX, float userY, vector <float> circleCoords){
    float centerX = circleCoords[0];
    float centerY = circleCoords[1];
    float radius = circleCoords[2];
    float distance = sqrt(pow(userX - centerX, 2) + pow(userY - centerY, 2));
    if(distance <= radius){
        return true;
    }
    return false;
}

bool Naive::naiveTriangle(float userX, float userY, vector<float> triangleCoords) {
    // Extract triangle coordinates
    float x1 = triangleCoords[0];
    float y1 = triangleCoords[1];
    float x2 = triangleCoords[2];
    float y2 = triangleCoords[3];
    float x3 = triangleCoords[4];
    float y3 = triangleCoords[5];

    // Calculate barycentric coordinates
    float denominator = ((y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3));
    float alpha = ((y2 - y3) * (userX - x3) + (x3 - x2) * (userY - y3)) / denominator;
    float beta = ((y3 - y1) * (userX - x3) + (x1 - x3) * (userY - y3)) / denominator;
    float gamma = 1.0f - alpha - beta;

    // Check if the point is inside the triangle
    return alpha >= 0.0f && beta >= 0.0f && gamma >= 0.0f;
}

bool Naive :: naiveRectangle(float userX, float userY, vector <float> rectangleCoords){
    float upperY = max(rectangleCoords[2], rectangleCoords[3]);
    float lowerY = min(rectangleCoords[2], rectangleCoords[3]);
    float rightX = max(rectangleCoords[0], rectangleCoords[1]);
    float leftX = min(rectangleCoords[0], rectangleCoords[1]);
        
    if(lowerY <= userY && userY <= upperY && leftX <= userX && userX <= rightX){
        return true;
    }
    return false;
}