#pragma once
#include <iostream>
#include<cstring>
using namespace std;

class Vehicle {
    char owner[20]; //string of max char length 20, the owner's name
    int doors, chairs, wheels, windows, opCntr = 0 ; // opCntr standsd for OperationCounter
    float motorPower;
public:
    //constructor
    Vehicle(int d, int c, int w, int win, int p);
    Vehicle();
    
    //Setters
    bool setOwner(char* o); //char* is the equivalent of string, but it's standard. more on cstrings >> https://www.geeksforgeeks.org/strings-in-c-2/
    bool setDoors (int d);
    bool setChairs (int c);
    bool setWheels (int w);
    bool setWindows (int win);
    bool setOpCntr (int opCntr);
    bool setMotorPower (int p);

    //Getters
    char* getOwner();
    int getDoors();
    int getChairs();
    int getWheels();
    int getWindows();
    int getOpCntr();
    float getMotorPower();

    //functionality
    bool operate(int km);
    bool sell(char* buyer);
    void printInfo();
    bool getInfo();
};