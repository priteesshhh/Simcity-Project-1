#include "Residential.h"
#include "main.h"
#include "analysis.h"

Dallas residentialProcess(Dallas& city, std::vector<std::vector<Dallas>>& Region, int x, int y) {
    Dallas updatedCity = city;

    // If the city has no population
    if (city.getPopulation() == 0) {
        // Check if the city is adjacent to a powerline or has at least one adjacent populated city
        if (isAdjacentToPowerline(Region, x, y) || countAdjacentOfPopulation(Region, x, y, 1) >= 1) {
            updatedCity.updatePopulation();
            return updatedCity;
        }
        return updatedCity;    
    } 
    // If the city has a population of 1 and at least two adjacent populated cities
    else if (city.getPopulation() == 1 && countAdjacentOfPopulation(Region, x, y, 1) >= 2) {
        updatedCity.updatePopulation();
        return updatedCity;
    } 
    // If the city has a population of 2 and at least four adjacent cities with a population of 2
    else if (city.getPopulation() == 2 && countAdjacentOfPopulation(Region, x, y, 2) >= 4) {
        updatedCity.updatePopulation();
        return updatedCity;
    } 
    // If the city has a population of 3 and at least six adjacent cities with a population of 3
    else if (city.getPopulation() == 3 && countAdjacentOfPopulation(Region, x, y, 3) >= 6) {
        updatedCity.updatePopulation();
        return updatedCity;
    } 
    // If the city has a population of 4 and at least eight adjacent cities with a population of 4
    else if (city.getPopulation() == 4 && countAdjacentOfPopulation(Region, x, y, 4) >= 8) {
        updatedCity.updatePopulation();
        return updatedCity;
    }

    return updatedCity;
}
