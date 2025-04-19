#include "analysis.h"

// Function to check if a given cell (x, y) in the Region grid is adjacent to a power line.
bool isAdjacentToPowerline(std::vector<std::vector<Dallas> >& Region, int x, int y) {
    // Defines the relative coordinates for all eight directions from a cell
    int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
	bool isAdjacent = false; // Initially assume no adjacency to a powerline

    // Loop through all adjacent cells based on defined directions
	for (int i = 0; i < 8; i++) {
        // Calculate the coordinates of the adjacent cell
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        // Check if the adjacent cell is within the bounds of the Region grid
		if ((newY < Region.size() && newY >= 0) && (newX >= 0 && newX < Region.size())) {
            // Check if the adjacent cell contains a power line
			if (Region[newX][newY].isPowerline()) {
				isAdjacent = true; // Mark as adjacent if a powerline is found
			}
		}
    }
	return isAdjacent; // Return whether an adjacent powerline was found
}

// Function to count the number of adjacent cells to a given cell (x, y) in the Region grid that have a population equal to or greater than a specified amount.
int countAdjacentOfPopulation(std::vector<std::vector<Dallas> >& Region, int x, int y, int population) {
    int count = 0; // Initialize count of adjacent cells meeting the population requirement

    // Defines the relative coordinates for all eight directions from a cell
    int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    // Loop through all adjacent cells based on defined directions
    for (int i = 0; i < 8; i++) {
        // Calculate the coordinates of the adjacent cell
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        // Check if the adjacent cell is within the bounds of the Region grid and meets the population requirement
        if (newY >= 0 && newY < Region.size() && newX >= 0 && newX < Region[0].size() && Region[newY][newX].getPopulation() >= population) {
            count++; // Increment count for each adjacent cell meeting the criteria
        }
    }
    return count; // Return the total count
}
