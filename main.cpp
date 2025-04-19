#include "main.h"
#include <iostream>
using namespace std;


void Print(int loop_value, vector<vector<Dallas>>& region, int availableWorkers, int availableGoods) {
    cout << "=============================================================\n";
    cout << "                       Dallas Simulation                     \n";
    cout << "=============================================================\n\n";

    cout << "Region Map (Population Status):\n";
    cout << "-------------------------------------------------------------\n";
    for (auto& row : region) {
        for (auto& city : row) {
            cout << (city.getPopulation() == 0 ? string(1, city.getType()) : to_string(city.getPopulation())) << "\t";
        }
        cout << endl;
    }
    cout << "-------------------------------------------------------------\n\n";

    cout << "Simulation Statistics:\n";
    cout << "-------------------------------------------------------------\n";
    cout << "Timestep: " << loop_value << endl;
    cout << "Pollution: " << GetTotalPollution(region) << " units\n";
    cout << "Available Workers: " << availableWorkers << endl;
    cout << "Available Goods: " << availableGoods << endl;
    cout << "-------------------------------------------------------------\n\n";

    cout << "Actions:\n";
    cout << "[A] Advance simulation\n";
    cout << "[X] Exit simulation\n";
    cout << "[Q] Edit configuration\n\n";
    cout << "Enter your choice: ";
}


int main() {
    vector<vector<Dallas> > Region;
    vector<vector<int> > mapKey;
    int timeLimit = 0;
    int refreshRate = 0;
    int availableWorkers = 0; // Starting count for workers
    int availableGoods = 0;   // Starting count for goods

    Initialize(Region, timeLimit, refreshRate, mapKey);

    for (int i = 0; i <= timeLimit; i++) {
        if (i % refreshRate == 0) {
            Print(i, Region, availableWorkers, availableGoods);
        }

        // Prompt the user for input to control simulation
        char userInput;
        cout << "Enter your choice: ";
        cin >> userInput;

        if (userInput == 'X' || userInput == 'x') {
            cout << "Exiting simulation..." << endl;
            break; // Exit the loop and end the program
        }
        else if (userInput == 'A' || userInput == 'a') {
            // Advance the simulation
            Simulation(mapKey, Region, availableWorkers, availableGoods);
        }
        else if (userInput == 'Q' || userInput == 'q') {
            cout << "Editing configuration is not implemented in this example." << endl;
            // Add configuration editing logic if required
        } else {
            cout << "Invalid input. Please enter 'A', 'X', or 'Q'." << endl;
        }
    }
    return 0;
}
