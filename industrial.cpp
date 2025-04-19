#include "analysis.h"
#include "industrial.h"

void generateAndDistributeGoods(std::vector<std::vector<Dallas>>& Region, int x, int y, const std::vector<std::vector<int>>& mapKey) {
    
}

void calculatePollution(std::vector<std::vector<Dallas>>& Region, int x, int y) {
    int population = Region[x][y].getPopulation();

    if (population > 0) {
        int pollution = population;

        int directions[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

        for (int i = 0; i < 8; i++) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];

            if (newY >= 0 && newY < Region.size() && newX >= 0 && newX < Region[0].size()) {
                Region[newY][newX].setPollution(Region[newY][newX].getPollution() + pollution - 1);
            }
        }
    }
}




// Function to manage the generation and distribution of goods from industrial areas
void generateAndDistributeGoods(std::vector<std::vector<Dallas>>& Region, int x, int y, std::vector<std::vector<int>> mapKey) {
    int industrialPopulation = Region[y][x].getPopulation();

    if (industrialPopulation > 0) {
        int goodsProduced = industrialPopulation;

        // Define directions for adjacent cells
        int directions[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

        for (int i = 0; i < 8; i++) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];

            // Check bounds before accessing the region
            if (newY >= 0 && newY < Region.size() && newX >= 0 && newX < Region[0].size()) {
                // Check if the adjacent cell is a commercial zone
                if (mapKey[newY][newX] == 3) {
                    // Distribute goods to the commercial cell
                    Region[newY][newX].assignGoods();
                    goodsProduced--;

                    // Stop distributing goods if all have been allocated
                    if (goodsProduced <= 0) {
                        break;
                    }
                }
            }
        }
    }
}

// Main processing function for industrial zones
Dallas industrialProcess(Dallas& city, std::vector<std::vector<Dallas>>& Region, int x, int y) {
    Dallas updatedCity = city;

    if (city.getPopulation() == 0) {
        if (isAdjacentToPowerline(Region, x, y) /*&& available workers >= 2*/) {
            updatedCity.updatePopulation();
            // Assign available workers to this cell and adjust total
            // Set population value of updated city equal to goods
            return updatedCity;
        } else if (countAdjacentOfPopulation(Region, x, y, 1) >= 1 /*&& available workers >= 2*/) {
            updatedCity.updatePopulation();
            // Assign available workers to this cell and adjust total
            return updatedCity;
        }
        return updatedCity;
    } else if (city.getPopulation() == 1 && countAdjacentOfPopulation(Region, x, y, 1) >= 2 /*&& available workers >= 2*/) {
        updatedCity.updatePopulation();
        // Assign available workers to this cell and adjust total
        return updatedCity;
    } else if (city.getPopulation() == 2 && countAdjacentOfPopulation(Region, x, y, 2) >= 4 /*available workers >= 2*/) {
        updatedCity.updatePopulation();
        // Assign available workers to this cell and adjust total
        return updatedCity;
    }

    return updatedCity;
}
