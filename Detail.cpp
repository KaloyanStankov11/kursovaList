#include <iostream>
#include <cstdlib>
using namespace std;

class Detail{
private:
    int ID;
    string name;
    string unit;
    double value;
public:

    //Constructor
    Detail(int ID, string name, string unit, double value){
        this->ID = ID;
        this->name = name;
        this->unit = unit;
        this->value = value;
    }

    //Accessors
    int getID(){return ID;}
    string getName(){return this->name;}
    string getUnit(){return this->unit;}
    double getValue(){return this->value;}
};
