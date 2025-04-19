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

int main() {
    unique_ptr<Vehicle> car = VehicleFactory::createVehicle("Car");
    unique_ptr<Vehicle> bike = VehicleFactory::createVehicle("Bike");
    unique_ptr<Vehicle> truck = VehicleFactory::createVehicle("Truck");

    if (car) car->drive();
    if (bike) bike->drive();
    if (truck) truck->drive();

    return 0;
}
