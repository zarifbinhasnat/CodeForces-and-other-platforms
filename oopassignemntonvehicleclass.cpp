#include <iostream>
#include <string>
using namespace std;

// Base class for Vehicle
class Vehicle {
protected:
    string licensePlate;
    string manufacturer;
    double carriageSizeLimit; // in kg

public:
    Vehicle(const string& licensePlate, const string& manufacturer, double carriageSizeLimit)
        : licensePlate(licensePlate), manufacturer(manufacturer), carriageSizeLimit(carriageSizeLimit) {}
    Vehicle(){
        licensePlate = "";
        manufacturer = "";
        carriageSizeLimit = 0;
    }
    virtual void maintenance() = 0;
    virtual ~Vehicle() {}
};

class GasolineVehicle : public Vehicle {
protected:
    double fuelTankCapacity; // in liters
    string fuelType; // e.g., petrol, octane

public:
    GasolineVehicle(const string& licensePlate, const string& manufacturer, double carriageSizeLimit,
                    double fuelTankCapacity, const string& fuelType)
        : Vehicle(licensePlate, manufacturer, carriageSizeLimit),
          fuelTankCapacity(fuelTankCapacity), fuelType(fuelType) {}
    GasolineVehicle(){fuelTankCapacity = 0;fuelType = "petrol";}
   virtual void maintenance()=0;
};

// Electric Vehicle (derived class)
class ElectricVehicle : public Vehicle {
protected:
    double batteryCapacity; // in KWh
    int chargingTime; // in minutes

public:
    ElectricVehicle(const string& licensePlate, const string& manufacturer, double carriageSizeLimit,
                    double batteryCapacity, int chargingTime)
        : Vehicle(licensePlate, manufacturer, carriageSizeLimit),
          batteryCapacity(batteryCapacity), chargingTime(chargingTime) {}
    ElectricVehicle(){batteryCapacity = 0; chargingTime = 0;}
         void maintenance() {
            cout<<"ElectricVehicle - maintenance"<<endl;
         };
         ~ElectricVehicle() {}

};

// Hybrid Vehicle (derived class)
class HybridVehicle : public GasolineVehicle, public ElectricVehicle {
private:
    double energyRegenerationEfficiency;

public:
    HybridVehicle(const string& licensePlate, const string& manufacturer, double carriageSizeLimit,
                  double fuelTankCapacity, const string& fuelType, double batteryCapacity, int chargingTime,
                  double energyRegenerationEfficiency)
        : GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType),
          ElectricVehicle(licensePlate, manufacturer, carriageSizeLimit, batteryCapacity, chargingTime),
          energyRegenerationEfficiency(energyRegenerationEfficiency) {}
    HybridVehicle(){}
    void maintenance(){
        cout<<"HybridVehicle - maintenance"<<endl;
    }

};


// Motorcycle (derived from GasolineVehicle)
class Motorcycle : public GasolineVehicle {
public:
    Motorcycle(const string& licensePlate, const string& manufacturer, double carriageSizeLimit,
               double fuelTankCapacity, const string& fuelType)
        : GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType) {}
    Motorcycle(){}
    void maintenance(){
        cout<<"Motorcycle - maintenance"<<endl;
    }
};

// Car (derived from GasolineVehicle)
class Car : public GasolineVehicle {
private:
    int passengerCapacity;

public:
    Car(const string& licensePlate, const string& manufacturer, double carriageSizeLimit, double fuelTankCapacity,
        const string& fuelType, int passengerCapacity)
        : GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType),
          passengerCapacity(passengerCapacity) {}

    Car(){}
    void maintenance(){
        cout<<"Car - maintenance"<<endl;
    }
      virtual ~Car() {}
};

// Truck (derived from GasolineVehicle)
class Truck : public GasolineVehicle {
private:
    double cargoCapacity;

public:
    Truck(const string& licensePlate, const string& manufacturer, double carriageSizeLimit, double fuelTankCapacity,
          const string& fuelType, double cargoCapacity)
        : GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType),
          cargoCapacity(cargoCapacity) {}

    Truck(){}
    void maintenance(){
        cout<<"Truck - maintenance"<<endl;
    }
};

// Employee Base Class
class Employee {
protected:
    string name;
    int id;

public:
    Employee(const string& name, int id) : name(name), id(id) {}
    Employee(){}
    void introduce(){cout<<name<<endl;};
};

// Manager (derived from Employee)
class Manager : public Employee {
public:
    Manager(const string& name, int id) : Employee(name, id) {}
    Manager(){}

    void introduce(){
        cout << "Mr. " << name << endl;
    }
};

// Driver (derived from Employee)
class Driver : public Employee {
public:
    Driver(const string& name, int id) : Employee(name, id) {}
    Driver(){}
};

// Branch class containing vehicles and employees
class Branch {
private:
    Motorcycle motorcycles[10];
    Car cars[10];
    Truck trucks[10];
    ElectricVehicle electricVehicles[10];
    HybridVehicle hybridVehicles[10];
    Manager managers[10];
    Driver drivers[10];

public:
    Branch() {

    }

    //You don't need to write this function for written exam
    void check(){
        motorcycles[0].maintenance();
        cars[0].maintenance();
        trucks[0].maintenance();
        electricVehicles[0].maintenance();
        hybridVehicles[0].maintenance();
        introduceEmployees();
    }
    // Method to introduce all employees
    void introduceEmployees() {
        cout << "Managers:" << endl;
        for (int i=0;i<10;i++) {
            managers[i].introduce();
        }

        cout << "Drivers:" << endl;
        for (int i=0;i<30;i++) {
            drivers[i].introduce();
        }
    }
    void addvehicle(const Vehicle* v){
        
    }
    void maintenance_all_vehicles(){
        for(int i=0;i<10;i++){
            motorcycles[i].maintenance();
            cars[i].maintenance();
            trucks[i].maintenance();
            electricVehicles[i].maintenance();
            hybridVehicles[i].maintenance();
        }
    }
};

int main()
{
    
    Branch dhaka;
    dhaka.check();
}
