#include <GLUT/glut.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <nlohmann/json.hpp>
#include <typeinfo>
#include <thread>
#include <chrono>
#include <mutex>
#include <getopt.h>

#include "user.hpp"
#include "shapeDrawer.hpp"
#include "visual.hpp"
#include "checks.hpp"
#include "data.hpp"

User* user1 = User :: getInstance();
Visual* visuals = Visual :: getInstance();
Data* zones = Data :: getInstance();

vector<vector <float>> rectangles;
string green_id;
mutex printMutex;

void threadFunction1(){
    Checks* checker = new Checks("naive", zones);
    while(1){
        Coordinates coord = user1->getCoordinates();
        green_id = checker->runCheck(coord.xCoor, coord.yCoor);
        visuals->setGreenId(green_id);
    }
}

void threadFunction2(){
    visuals->setUser(user1);
    visuals->setData(zones);
    visuals->showVisuals();   
}

void threadFunction4(){
    while(1){
        cout << "What kind of shape would you like to draw?" << endl;
        cout << "1) Triangle" << endl;
        cout << "2) Circle" << endl;
        cout << "3) Rectangle" << endl;
        cout << "Shape: ";
        int choice;
        cin >> choice;
        cout << endl;
        visuals->waitForClicks(choice);
    }
}

int main(int argc, char** argv) {
    string file = "coordinates.json";
    zones->setData(file);

    std::thread t1(threadFunction1);
    //std::thread t2(threadFunction2);
    std::thread t4(threadFunction4);
    threadFunction2();

    // Wait for both threads to finish
    t1.join();
    //t2.join();
    t4.join();
}
