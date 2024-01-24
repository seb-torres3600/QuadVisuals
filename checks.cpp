#include "checks.hpp"

Checks :: Checks(string approachToCheck, Data* _data){
    this->approach = approachToCheck;
    this->data = _data;
    this->userX = 0.0;
    this->userY = 0.0;
}


string Checks :: runCheck(float xCoor, float yCoor){
    this->userX = xCoor;
    this->userY = yCoor;
    
    if(approach == "naive"){
        for(auto& object: data->getData()){
            string shape_name = object.at("shape");
            string object_id = object.at("id");
            vector <float> coordinates = object.at("coordinates");
            if (naiveCheck(shape_name, coordinates)){
                return object_id;
            }
        }
    }
    return "";
}

bool Checks :: naiveCheck(string shape, vector <float> coords){
    Naive test;
    std::map<std::string, std::function<bool()>> naiveMap;
    naiveMap["rectangle"] = [this, &test, coords]() -> bool { return test.naiveRectangle(userX, userY, coords); };
    naiveMap["triangle"] = [this, &test, coords]() -> bool { return test.naiveTriangle(userX, userY, coords); };
    naiveMap["circle"] = [this, &test, coords]() -> bool { return test.naiveCircle(userX, userY, coords); };
    return naiveMap[shape]();
}

bool Checks :: quadCheck(string shape){
    Quad test;
    std::map<std::string, std::function<bool()>> quadMap;
    quadMap["rectangle"] = [&test]() -> bool { return test.quadRectangle(); };
    quadMap["triangle"] = [&test]() -> bool { return test.quadTriangle(); };
    quadMap["circle"] = [&test]() -> bool { return test.quadCircle(); };
    return quadMap[shape]();
}