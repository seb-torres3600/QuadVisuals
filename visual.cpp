#include "visual.hpp"

Visual* Visual :: displayer = NULL;

Visual ::Visual() {
};

Visual* Visual :: getInstance() {
    if (displayer == NULL){
        displayer = new Visual();
    }
    return displayer;
}

void Visual :: setUser(User* _user){
    this->user1 = _user;
}

void Visual :: setData(Data* _zones){
    this->zones = _zones;
}

void Visual :: setGreenId(string _id){
    this->greenIndex = _id;
}

void Visual :: display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    json data = zones->getData();
    for(auto& object: data){
        string shape_name = object.at("shape");
        string object_id = object.at("id");
        vector <float> coordinates = object.at("coordinates");
        if(object_id == greenIndex){
            drawer.drawShape(shape_name, coordinates, true);
        }
        else{
            drawer.drawShape(shape_name, coordinates, false);
        }
    }

    user1->drawUser(0.01f, 200);
    glFlush();
}

void Visual :: keyCallbackImpl(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        user1->moveUser(key);
    }
}

void Visual::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Visual* visualInstance = reinterpret_cast<Visual*>(glfwGetWindowUserPointer(window));
    if (visualInstance) {
        visualInstance->keyCallbackImpl(window, key, scancode, action, mods);
    }
}

void Visual :: mouseCallback(GLFWwindow* window, int button, int action, int mods)
{
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) 
    {
       double xpos, ypos;
       int max_x, max_y;
       //getting cursor position
       glfwGetCursorPos(window, &xpos, &ypos);
       glfwGetWindowSize(window, &max_x, &max_y);

       double adj_x, adj_y;
       adj_x = (xpos - double(max_x/2))/double(max_x/2);
       adj_y = (double(max_y/2) - ypos)/double(max_y/2);
       Visual* visualInstance = Visual :: getInstance();
       visualInstance->clicked_coords.push_back(adj_x);
       visualInstance->clicked_coords.push_back(adj_y);
    }
}

int Visual :: waitForClicks(int number){

    string shape;
    int expected_clicks;

    switch(number){
        case 1:
            expected_clicks = 6;
            shape = "triangle";
            break;
        case 2:
            expected_clicks = 4;
            shape = "circle";
            break;
        case 3:
            expected_clicks = 4;
            shape = "rectangle";
            break;
        default:
            expected_clicks = 0;
            return -1;
    }
    cout << "Expecting " << expected_clicks/2 << " clicks" << endl;

    if (!glfwInit()) {
        return -1;
    }
    while(int(clicked_coords.size()) != expected_clicks){
        glfwSetMouseButtonCallback(window, mouseCallback);
    }
    if(shape == "circle"){
        vector<double> tmp;
        double x_tmp = clicked_coords.at(0);
        double y_tmp = clicked_coords.at(1);
        double rad_x = clicked_coords.at(2);
        double rad_y = clicked_coords.at(3);

        double deltaX = rad_x - x_tmp;
        double deltaY = rad_y - y_tmp;
        double radius = sqrt(deltaX * deltaX + deltaY * deltaY);
        tmp.push_back(clicked_coords.at(0));
        tmp.push_back(clicked_coords.at(1));
        tmp.push_back(radius);
        tmp.push_back(200.0);
        clicked_coords = tmp;
    }
    zones->writeData(shape, clicked_coords);
    clicked_coords.clear();
    return 0;
}


int Visual :: showVisuals(){
    if (!glfwInit()) {
        return -1;
    }

    window = glfwCreateWindow(800, 800, "Move Circle with Arrow Keys", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwSetWindowUserPointer(window, displayer);   
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keyCallback);

    glClearColor(1.0, 1.0, 1.0, 1.0);

    while (!glfwWindowShouldClose(window)) {
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}