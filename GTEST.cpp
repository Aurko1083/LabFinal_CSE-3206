#include "gtest/gtest.h"
#include <sstream>
#include <memory>
#include <iostream>
using namespace std;




class Vehicle {
public:
    virtual void drive() = 0;
    virtual ~Vehicle() = default;
};


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

// =================== Google Test Code =====================

// Redirect stdout for testing
class DriveTest : public ::testing::Test {
protected:
    stringstream buffer;
    streambuf* old;

    void SetUp() override {
        old = cout.rdbuf(buffer.rdbuf()); // redirect cout to buffer
    }

    void TearDown() override {
        cout.rdbuf(old); // restore cout
    }

    string getOutput() {
        return buffer.str();
    }
};

TEST_F(DriveTest, CarDriveTest) {
    auto car = VehicleFactory::createVehicle("Car");
    ASSERT_TRUE(car != nullptr);
    car->drive();
    EXPECT_EQ(getOutput(), "Driving a Car!\n");
}

TEST_F(DriveTest, BikeDriveTest) {
    auto bike = VehicleFactory::createVehicle("Bike");
    ASSERT_TRUE(bike != nullptr);
    bike->drive();
    EXPECT_EQ(getOutput(), "Riding a Bike!\n");
}

TEST_F(DriveTest, TruckDriveTest) {
    auto truck = VehicleFactory::createVehicle("Truck");
    ASSERT_TRUE(truck != nullptr);
    truck->drive();
    EXPECT_EQ(getOutput(), "Driving a Truck!\n");
}

TEST(VehicleFactoryTest, InvalidVehicleTest) {
    auto unknown = VehicleFactory::createVehicle("Plane");
    EXPECT_EQ(unknown, nullptr);
}
