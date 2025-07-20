// VEHICLE RENTAL SYSTEM - OOP PROJECT
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ---------------- VEHICLE BASE CLASS ----------------
class Vehicle {
protected:
    string vehicleID;
    string brand;
    string model;
    float rentPerDay;
    bool isAvailable;

public:
    Vehicle() {}
    Vehicle(string id, string b, string m, float rent)
        : vehicleID(id), brand(b), model(m), rentPerDay(rent), isAvailable(true) {}

    virtual void displayInfo() {
        cout << "ID: " << vehicleID << ", Brand: " << brand << ", Model: " << model
             << ", Rent/Day: $" << rentPerDay << ", Available: " << (isAvailable ? "Yes" : "No") << endl;
    }

    virtual float calculateRent(int days) {
        return days * rentPerDay;
    }

    string getID() { return vehicleID; }
    bool getAvailability() { return isAvailable; }
    void setAvailability(bool status) { isAvailable = status; }

    bool operator==(const Vehicle &v) {
        return vehicleID == v.vehicleID;
    }
};

// ---------------- DERIVED CLASSES ----------------
class Car : public Vehicle {
    int doors;
public:
    Car(string id, string b, string m, float rent, int d)
        : Vehicle(id, b, m, rent), doors(d) {}

    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Doors: " << doors << endl;
    }
};

class Bike : public Vehicle {
    bool hasGear;
public:
    Bike(string id, string b, string m, float rent, bool g)
        : Vehicle(id, b, m, rent), hasGear(g) {}

    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Has Gear: " << (hasGear ? "Yes" : "No") << endl;
    }
};

// ---------------- LINKED LIST ----------------
struct Node {
    Vehicle* vehicle;
    Node* next;
};

class VehicleList {
    Node* head;
public:
    VehicleList() { head = nullptr; }

    void addVehicle(Vehicle* v) {
        Node* newNode = new Node{v, head};
        head = newNode;
    }

    void displayAll() {
        Node* temp = head;
        while (temp) {
            temp->vehicle->displayInfo();
            cout << "-----------------------" << endl;
            temp = temp->next;
        }
    }

    Vehicle* searchByID(string id) {
        Node* temp = head;
        while (temp) {
            if (temp->vehicle->getID() == id) return temp->vehicle;
            temp = temp->next;
        }
        return nullptr;
    }

    void removeByID(string id) {
        Node* temp = head;
        Node* prev = nullptr;
        while (temp) {
            if (temp->vehicle->getID() == id) {
                if (prev) prev->next = temp->next;
                else head = temp->next;
                delete temp->vehicle;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    Node* getHead() { return head; } // Needed for file operations
};

// ---------------- FILE HANDLING ----------------
void saveVehiclesToFile(VehicleList &list) {
    ofstream file("vehicles.txt");
    Node* temp = list.getHead();
    while (temp) {
        file << temp->vehicle->getID() << "\n"; // ID only for simplicity
        temp = temp->next;
    }
    file.close();
}

// ---------------- MAIN FLOW ----------------
int main() {
    VehicleList inventory;

    inventory.addVehicle(new Car("C001", "Toyota", "Corolla", 50, 4));
    inventory.addVehicle(new Bike("B001", "Honda", "CBR", 30, true));
    inventory.addVehicle(new Car("C002", "Tesla", "Model 3", 100, 4));

    int choice;
    do {
        cout << "\n--- VEHICLE RENTAL SYSTEM ---\n";
        cout << "1. View Vehicles\n2. Rent Vehicle\n3. Return Vehicle\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            inventory.displayAll();
        }
        else if (choice == 2) {
            string id;
            int days;
            cout << "Enter Vehicle ID to Rent: "; cin >> id;
            Vehicle* v = inventory.searchByID(id);
            if (v && v->getAvailability()) {
                cout << "Enter number of days: "; cin >> days;
                cout << "Total Rent: $" << v->calculateRent(days) << endl;
                v->setAvailability(false);
            } else {
                cout << "Vehicle not available or invalid ID!\n";
            }
        }
        else if (choice == 3) {
            
            string id;
            cout << "Enter Vehicle ID to Return: "; cin >> id;
            Vehicle* v = inventory.searchByID(id);
            if (v && !v->getAvailability()) {
                v->setAvailability(true);
                cout << "Vehicle returned successfully!\n";
            } else {
                cout << "Vehicle not found or not rented.\n";
            }
        }

    } while (choice != 4);

    saveVehiclesToFile(inventory);
    return 0;
}


