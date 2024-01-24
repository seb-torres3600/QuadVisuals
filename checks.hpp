#ifndef CHECKS_HPP
#define CHECKS_HPP

#include <iostream>
#include <map>
#include <functional>
#include <nlohmann/json.hpp>

#include "naive.hpp"
#include "quad.hpp"
#include "data.hpp"

using namespace std;
using json = nlohmann::json;

class Checks {
    private:
        string approach;
        Data* data;
        float userX;
        float userY;
        bool naiveCheck(string shape, vector<float> coords);
        bool quadCheck(string shape);
    public:
        string runCheck(float userX, float userY);
        Checks(string approach, Data* _data);
};

#endif