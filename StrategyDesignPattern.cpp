#include <iostream>
using namespace std;


class DriveS {
    public:
    virtual void onDrive() = 0;
    virtual ~DriveS() = default;
};

class NormalDrive : public DriveS {
    public:
    void onDrive() {
        cout<<"Normal Drive"<<endl;
    }
};

class SpeedDrive : public DriveS {
    public:
    void onDrive() {
        cout<<"Speed Drive"<<endl;
    }
};

class Vehicle {
    protected:
    DriveS* driverS;
    public:
    Vehicle(DriveS* driver) : driverS(driver) {};
    void onDrive() {
        driverS->onDrive();
    }
    virtual ~Vehicle() {
        delete driverS;
    }
};

class SportCar : public Vehicle {
    public:
    SportCar() : Vehicle(new SpeedDrive()) {};
};


class NormalCar : public Vehicle {
    public:
    NormalCar() : Vehicle(new NormalDrive()) {};
};

int main() {
    
    Vehicle* sports = new SportCar();
    Vehicle* normal = new NormalCar();
    sports->onDrive();
    normal->onDrive();
    return 0;
}