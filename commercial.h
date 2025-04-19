#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Dallas.h"
#include "main.h"

// Helper function to determine if a cell is adjacent to a powerline
bool isAdjacentToPowerline(std::vector<std::vector<Dallas>>& region, int x, int y);

// Function to count adjacent cells with a specified population or more
int countAdjacentOfPopulation(std::vector<std::vector<Dallas>>& region, int x, int y, int population);

// Main processing function for a commercial zone locality
Dallas commercialProcess(Dallas& city, std::vector<std::vector<Dallas>>& region, int x, int y);

#endif
