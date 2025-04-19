#include "commercial.h" // Include the header file for commercial functions
#include "analysis.h"   // Include the header file for analysis functions

// Function to handle commercial development in a city within a region
// based on specific conditions regarding population, proximity to power lines, and other factors.
Dallas commercialProcess(Dallas& city, std::vector<std::vector<Dallas>>& region, int x, int y) {
    Dallas updatedCity = city; // Create a copy of the city for modifications

    // If the city currently has no population
    if (city.getPopulation() == 0) {
        // Check if the city is near a powerline and potentially other conditions (commented out)
        if (isAdjacentToPowerline(region, x, y) /* && city.getWorkers() >= 1 && city.getGoods() >= 1 */) {
            updatedCity.updatePopulation(); // Increase population if conditions are met
            // Potential future conditions for assigning workers and goods
            /* updatedCity.assignWorker();
            updatedCity.assignGoods(); */
            return updatedCity; // Return the modified city
        }
        return updatedCity; // Return the unchanged city if conditions are not satisfied
    }
    // Check for a specific case where the city has no population but is adjacent to at least two populated areas
    else if (city.getPopulation() == 0 && countAdjacentOfPopulation(region, x, y, 1) >= 2 /* && city.getWorkers() >= 1 && city.getGoods() >= 1 */) {
        updatedCity.updatePopulation(); // Increase population if conditions are met
        // Potential future conditions for assigning workers and goods
        /* updatedCity.assignWorker();
        updatedCity.assignGoods(); */
        return updatedCity; // Return the modified city
    }
    // Check for cities with a population of 1 that are adjacent to at least four areas with a population of 2
    else if (city.getPopulation() == 1 && countAdjacentOfPopulation(region, x, y, 2) >= 4 /* && city.getWorkers() >= 1 && city.getGoods() >= 1 */) {
        updatedCity.updatePopulation(); // Increase population if conditions are met
        // Potential future conditions for assigning workers and goods
        /* updatedCity.assignWorker();
        updatedCity.assignGoods(); */
        return updatedCity; // Return the modified city
    }

    return updatedCity; // Return the city, potentially unchanged if no conditions were satisfied
}
