

#include <iostream>
#include <vector>
#include "Dallas.h"

using namespace std;

// Constructor
Dallas::Dallas(char T, int P) {
    this->type = T;
    this->pollution = P;
}

// Setter for the city type
void Dallas::setType(char t) {
    this->type = t;
}

// Setter for pollution level
void Dallas::setPollution(int p) {
    this->pollution = p > 0 ? p : 0; // Ensure pollution is non-negative
}

// Getter for city type
char Dallas::getType() const {
    if (type != 'E') {
        return type;
    } else {
        return ' ';
    }
}

// Getter for pollution level
int Dallas::getPollution() const {
    return pollution;
}

// Getter for the number of workers
int Dallas::getWorkers() const {
    return workers;
}

// Getter for the number of goods
int Dallas::getGoods() const {
    return goods;
}

// Getter for population
int Dallas::getPopulation() const {
    return population;
}

// Method to update population
void Dallas::updatePopulation() {
    population++;
}

// Method to check if there's a powerline in the city
bool Dallas::isPowerline() const {
    return (type == 'T' || type == '#');
}

// Method to assign a worker to the city
void Dallas::assignWorker() {
    hasWorker = true;
    workers--;
}

// Method to assign goods to the city
void Dallas::assignGoods() {
    hasGood = true;
    goods--;
}

// Static method to calculate the total pollution for a grid of Dallas objects
int Dallas::getTotalPollution(const vector<vector<Dallas>>& region) {
    int totalPollution = 0;

    for (const auto& row : region) {
        for (const auto& city : row) {
            totalPollution += city.getPollution();
        }
    }

    return totalPollution;
}
