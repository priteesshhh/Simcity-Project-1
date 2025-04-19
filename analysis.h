#ifndef ANALYSIS_H // Prevents multiple inclusions of this header
#define ANALYSIS_H

#include "main.h"
#include "init.h"
#include "Dallas.h" // Include the Dallas class definition
#include <vector>

// Checks if a city at coordinates (x, y) is adjacent to a power line
bool isAdjacentToPowerline(std::vector<std::vector<Dallas>>& region, int x, int y);

// Counts adjacent cities with a population greater than or equal to a specified value
int countAdjacentOfPopulation(std::vector<std::vector<Dallas>>& region, int x, int y, int population);

#endif // ANALYSIS_H 

/* In analysis.h
#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <vector>
#include "Dallas.h" // Ensure this is correct

bool isAdjacentToPowerline(std::vector<std::vector<Dallas>>& Region, int x, int y);
int countAdjacentOfPopulation(std::vector<std::vector<Dallas>>& Region, int x, int y, int population);

#endif. */

