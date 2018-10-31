#include "Vehicle.h"

int main()
{
    Vehicle V;
    V.getInfo();
    V.printInfo();
    
    V.operate(1000);
    V.sell((char*)"RichGuy");
    V.printInfo();
    return 0;
}

Vehicle::Vehicle(int d, int c, int w, int win, int p) {
    this->setDoors(d);
    this->setChairs(c);
    this->setWheels(w);
    this->setWindows(win);
    this->setMotorPower(p);
    this->setOpCntr(0);
}

Vehicle::Vehicle() {} //default constructor


bool Vehicle::setOwner(char* o)
{
    bool isAlpha = false;
    //loop over the whole name to check if each character is alphabetical or a space
    for (int i = 0; i < strlen(o) ; ++i) {
        if (isalpha(o[i]) || o[i] == ' ') isAlpha = true; //more about the built-in function islapha() here >> http://www.cplusplus.com/reference/cctype/isalpha/
        else return false; //if any of the characters isn't alpha , it doesn't continue
    }
    //reaching this point means that all chars are alphabitical, time to store
    for (int i = 0; i < strlen(o) ; ++i) this->owner[i] = o[i];
    return true;
} 


bool Vehicle::setDoors (int d)
{
    if ( d >= 0 ) this->doors = d;
    else return false;
    return true; // the function returns true if it doesn't go into the else, which means it passed the verfication i.e. valid input
}


bool Vehicle::setChairs (int c)
{
    if ( c >= 0 ) this->chairs = c;
    else return false;
    return true;
}


bool Vehicle::setWheels (int w)
{
    if ( w >= 0 ) this->wheels = w;
    else return false;
    return true; // the function returns true if it doesn't go into the else, which means it passed the verfication i.e. valid input
}


bool Vehicle::setWindows (int win)
{
    if ( win >= 0 ) this->windows = win;
    else return false;
    return true; // the function returns true if it doesn't go into the else, which means it passed the verfication i.e. valid input

}


bool Vehicle::setOpCntr (int cnt)
{
    if ( cnt >= 0 ) this->opCntr = cnt;
    else return false;
    return true; // the function returns true if it doesn't go into the else, which means it passed the verfication i.e. valid input
    
}


bool Vehicle::setMotorPower (int p)
{
    if ( p >= 0 ) this->motorPower = p;
    else return false;
    return true; // the function returns true if it doesn't go into the else, which means it passed the verfication i.e. valid input

}

char* Vehicle::getOwner()
{
    return this->owner;
}


int Vehicle::getDoors()
{
    return this->doors;
}


int Vehicle::getChairs()
{
    return this->chairs;
}


int Vehicle::getWheels()
{
    return this->wheels;
}


int Vehicle::getWindows()
{
    return this->windows;
}


int Vehicle::getOpCntr()
{
    return this->opCntr;
}


float Vehicle::getMotorPower()
{
    return this->motorPower;
}


bool Vehicle::operate(int km)
{
    if ( km >= 0 ) {
        int currentOpCntr = this->getOpCntr();
        this->setOpCntr(currentOpCntr + km); //Add the km to the past value of the counter
    }
    else return false;
    return true;
}


bool Vehicle::sell(char* buyer)
{
    this->setOwner(buyer);    
}

void Vehicle::printInfo()
{
    cout << "Vehicle owned by : " << this->getOwner() << "\n";
    cout << "Doors : " << this->getDoors() << "\t Chairs : " << this->getChairs() << "\n";
    cout << "Wheels : " << this->getWheels() << "\t Windows : " << this->getWindows() << "\n";
    cout << "Motor Power (in watt) : " << this->getMotorPower() << " opertating for : " << this->getOpCntr() << " km\n";
}

bool Vehicle::getInfo()
{
    cout << "Please Enter initial values for the vehicle varibles\n";
    bool success; //I'll use this variable to ask the user continually tell a valid input is given
    char strVar[20]; int intVar; float floatVar; //I'll use these to take input from the user
    do {
        cout << "Please enter Owners's name (max 20 chars) >>> ";
        cin >> strVar;
        success = setOwner(strVar);
        cout << "\n";
    } while (!success);

    do {
        cout << "Please enter No. of Doors >>> ";
        cin >> intVar;
        success = setDoors(intVar);
    } while (!success);

    do {
        cout << "Please enter No. of Chairs >>> ";
        cin >> intVar;
        success = setChairs(intVar);
        cout << "\n";
    } while (!success);

    do {
        cout << "Please enter No. of Wheels >>> ";
        cin >> intVar;
        success = setWheels(intVar);
        cout << "\n";
    } while (!success);

    do {
        cout << "Please enter No. of Windows >>> ";
        cin >> intVar;
        success = setWindows(intVar);
        cout << "\n";
    } while (!success);

    do {
        cout << "Please enter Motor Power >>> ";
        cin >> floatVar;
        success = setMotorPower(floatVar);
        cout << "\n";
    } while (!success);
    
    /////////////////////IMPORTANT COMMENT///////////////////////
    //This is a very repetitive way to solve such a problem.
    //This is called WET (Write Everything Twice) code, it's the opposite od DRY (Don't Repeat Yourself) code.
    //Try to implement a better getInfo() fn. using DRY code
    //Use Git to make a pull request if you reached a better solution
    //Good Luck !
}
