#ifndef INIT_H
#define INIT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "Dallas.h" 

using namespace std;

string ParseConfigLine(string configLine);
void ParseRegionLine(string &regionLine, vector<Dallas> &row);
void ParseConfigFile(string configFileName, string &regionFileName, int &timeLimit, int &refreshRate);
void ParseRegionFile(vector<vector<Dallas> > &Region, string regionFileName);
int GetTotalPollution(vector<vector<Dallas> > &Region);
void Initialize(vector<vector<Dallas> > &Region, int &timeLimit, int &refreshRate, vector<vector<int> > &mapKey);

// Update this line to include availableWorkers and availableGoods by reference
void Simulation(vector<vector<int> > mapKey, vector<vector<Dallas> > &Region, int &availableWorkers, int &availableGoods);

#endif
