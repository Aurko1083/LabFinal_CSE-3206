
// ======================
// ✅ Adapter Pattern
// ======================
#include <iostream>
using namespace std;

// Old interface
class OldPrinter
{
public:
    void oldPrint(){
        cout << "[OldPrinter] Printing in legacy format... ";
    }
};

// New interface expected
class IPrinter
{
public:
    virtual void print() = 0;
};

// Adapter Class
class PrinterAdapter : public IPrinter
{
    OldPrinter *oldPrinter;

public:
    PrinterAdapter(OldPrinter *p) : oldPrinter(p) {}
    void print() override
    {
        cout << "[Adapter] Converting old print to new...";
        oldPrinter->oldPrint(); // You can add more logic here
    }
};

// ======================
// ✅ Factory Pattern
// ======================
class Shape
{
public:
    virtual void draw() = 0;
};

class Circle : public Shape
{
public:
    void draw() override{
        cout << "[Circle] Drawing Circle with radius 5.";
    }
};

class Square : public Shape
{
public:
    void draw() override{
        cout << "[Square] Drawing Square with side 4.";
    }
};

class ShapeFactory
{
public:
    static Shape *createShape(string type)
    {
        if (type == "circle")
            return new Circle();
        if (type == "square")
            return new Square();
        return nullptr;
    }
};

// ======================
// ✅ Decorator Pattern
// ======================
class Coffee
{
public:
    virtual void cost() = 0;
};

class BasicCoffee : public Coffee
{
public:
    void cost() override{
        cout << "[BasicCoffee] Cost: $5";
    }
};

class CoffeeDecorator : public Coffee
{
protected:
    Coffee *coffee;

public:
    CoffeeDecorator(Coffee *c) : coffee(c) {}
};

class MilkDecorator : public CoffeeDecorator
{
public:
    MilkDecorator(Coffee *c) : CoffeeDecorator(c) {}
    void cost() override
    {
        coffee->cost();
        cout << "[MilkDecorator] + Milk: $1";
    }
};

class SugarDecorator : public CoffeeDecorator
{
public:
    SugarDecorator(Coffee *c) : CoffeeDecorator(c) {}
    void cost() override
    {
        coffee->cost();
        cout << "[SugarDecorator] + Sugar: $0.5";
    }
};

// ======================
// ✅ Abstract Class
// ======================
class Animal
{
public:
    virtual void sound() = 0; // Pure virtual function
};

class Dog : public Animal
{
public:
    void sound() override{
        cout << "[Dog] Woof Woof!";
    }
};

// ======================
// ✅ Abstract Factory Pattern
// ======================
class Button
{
public:
    virtual void draw() = 0;
};

class WindowsButton : public Button
{
public:
    void draw() override{
        cout << "[WindowsButton] Drawing Windows style button";
    }
};

class MacButton : public Button
{
public:
    void draw() override{
        cout << "[MacButton] Drawing Mac style button";
    }
};

class GUIFactory
{
public:
    virtual Button *createButton() = 0;
};

class WindowsFactory : public GUIFactory
{
public:
    Button *createButton() override
    {
        return new WindowsButton();
    }
};

class MacFactory : public GUIFactory
{
public:
    Button *createButton() override
    {
        return new MacButton();
    }
};

// ======================
// ✅ Singleton Pattern
// ======================
class Singleton
{
private:
    static Singleton *instance;
Singleton(){
    cout << "[Singleton] Instance Created.";
} public : static Singleton *getInstance()
    {
        if (instance == nullptr)
            instance = new Singleton();
        return instance;
    }

    void showMessage(){
        cout << "[Singleton] Hello from Singleton!";
    }
};

// Initialize static member
Singleton *Singleton::instance = nullptr;

// ======================
// ✅ Main Function (Demo)
// ======================
int main()
{
    // Adapter Demo
    cout << "\n=== Adapter Demo ===\n";
    OldPrinter old;
    PrinterAdapter adapter(&old);
    adapter.print();

    // Factory Demo
    cout << "\n=== Factory Demo ===\n";
    Shape *shape = ShapeFactory::createShape("circle");
    if (shape)
        shape->draw();
    delete shape;

    // Decorator Demo
    cout << "\n=== Decorator Demo ===\n";
    Coffee *coffee = new SugarDecorator(new MilkDecorator(new BasicCoffee()));
    coffee->cost();
    delete coffee;

    // Abstract Class Demo
    cout << "\n=== Abstract Class Demo ===\n";
    Animal *animal = new Dog();
    animal->sound();
    delete animal;

    // Abstract Factory Demo
    cout << "\n=== Abstract Factory Demo ===\n";
    GUIFactory *factory = new MacFactory(); // Switch to WindowsFactory if needed
    Button *btn = factory->createButton();
    btn->draw();
    delete btn;
    delete factory;

    // Singleton Demo
    cout << "\n=== Singleton Demo ===\n";
    Singleton *s = Singleton::getInstance();
    s->showMessage();

    return 0;
}
