#include <iostream>
#include <memory>
using namespace std;

// Base class
class Vehicle {
public:
    virtual void drive() = 0;
    virtual ~Vehicle() = default;
};

// Concrete classes
class Car : public Vehicle {
public:
    void drive() override {
        cout << "Driving a Car!" << endl;
    }
};

class Bike : public Vehicle {
public:
    void drive() override {
        cout << "Riding a Bike!" << endl;
    }
};

class Truck : public Vehicle {
public:
    void drive() override {
        cout << "Driving a Truck!" << endl;
    }
};

// Factory class
class VehicleFactory {
public:
    static unique_ptr<Vehicle> createVehicle(const string& type) {
        if (type == "Car") return make_unique<Car>();
        if (type == "Bike") return make_unique<Bike>();
        if (type == "Truck") return make_unique<Truck>();
        return nullptr;
    }
};



