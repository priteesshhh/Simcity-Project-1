#include "init.h"
#include "main.h"
#include "Residential.h"
#include "commercial.h"
#include "industrial.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

string ParseConfigLine(string configLine) {
    bool hit = false;
    int hitAt = 0;
    string str = "";
    for (size_t i = 0; i < configLine.size(); i++) {
        if (configLine.at(i) == ':') {
            hit = true;
            hitAt = i;
            break;
        }
    }
    if (hit) {
        str = configLine.substr(hitAt + 1, configLine.size());
    } else {
        str = "-1";
    }
    return str;
}

void ParseRegionLine(string &regionLine, vector<Dallas> &row) {
    for (size_t i = 0; i < regionLine.length(); i++) {
        if (regionLine[i] == ',') {
            continue;
        } else {
            Dallas new_city;
            new_city.setType(regionLine[i]);
            row.push_back(new_city);
        }
    }
}

void ParseConfigFile(string configFileName, string &regionFileName, int &timeLimit, int &refreshRate) {
    ifstream configStream;
    string configLine = "";

    configStream.open(configFileName);
    if (configStream.is_open()) {
        cout << configFileName << " opened successfully.\n";
    } else {
        cout << configFileName << " failed to open. Exiting with error code -1\n";
        exit(-1);
    }

    int i = 0;
    stringstream ss;
    string tempString;
    while (!configStream.eof()) {
        getline(configStream, configLine);
        i++;
        if (i == 1) {
            regionFileName = ParseConfigLine(configLine);
        } else if (i == 2) {
            tempString = ParseConfigLine(configLine);
            ss << tempString;
            ss >> timeLimit;
            ss.clear();
        } else if (i == 3) {
            tempString = ParseConfigLine(configLine);
            ss << tempString;
            ss >> refreshRate;
            ss.clear();
        }
    }
    configStream.close();
}

void ParseRegionFile(vector<vector<Dallas> > &Region, string regionFileName) {
    ifstream regionStream;
    regionStream.open(regionFileName);
    if (regionStream.is_open()) {
        cout << regionFileName << " opened successfully.\n";
    } else {
        cout << regionFileName << " failed to open. Exiting with error code -1\n";
        exit(-1);
    }

    string regionLine;
    while (getline(regionStream, regionLine)) {
        vector<Dallas> row;
        ParseRegionLine(regionLine, row);
        Region.push_back(row);
    }
    regionStream.close();
}



int GetTotalPollution(vector<vector<Dallas>>& Region) {
    int totalPollution = 0;
    for (auto& row : Region) {
        for (auto& city : row) {
            totalPollution += city.getPollution();
        }
    }
    return totalPollution;
}


void Initialize(vector<vector<Dallas> > &Region, int &timeLimit, int &refreshRate, vector<vector<int> > &mapKey) {
    string regionFileName = "";
    string configFileName = "";
    cout << endl << "Enter filename of configuration file: ";
    cin >> configFileName;

    ParseConfigFile(configFileName, regionFileName, timeLimit, refreshRate);
    ParseRegionFile(Region, regionFileName);

    cout << "Time Limit: " << timeLimit << endl;
    cout << "Refresh Rate: " << refreshRate << endl;
    cout << "Available Workers: " << 0 << endl;  // Start with 0 as per the example
    cout << "Available Goods: " << 0 << endl;    // Start with 0 as per the example

    int rows = Region.size();
    int cols = Region[0].size();
    mapKey.resize(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char type = Region[i][j].getType();
            if (type == 'R') mapKey[i][j] = 1;
            else if (type == 'I') mapKey[i][j] = 2;
            else if (type == 'C') mapKey[i][j] = 3;
        }
    }
}



    void Simulation(vector<vector<int>> mapKey, vector<vector<Dallas>>& Region, int& availableWorkers, int& availableGoods) {
    for (size_t i = 0; i < mapKey.size(); ++i) {
        for (size_t j = 0; j < mapKey[i].size(); ++j) {
            if (mapKey[i][j] == 1) {  // Residential zone
                Region[i][j] = residentialProcess(Region[i][j], Region, i, j);
                //availableWorkers += Region[i][j].getPopulation() > 0 ? 1 : 0;
                availableWorkers += Region[i][j].getPopulation();

            } 
            else if (mapKey[i][j] == 2) {  // Industrial zone
                Region[i][j] = industrialProcess(Region[i][j], Region, i, j);
                calculatePollution(Region, i, j); // <-- Add this line
                availableGoods += Region[i][j].getPopulation() > 0 ? 1 : 0;
            } 
            else if (mapKey[i][j] == 3) {  // Commercial zone
                Region[i][j] = commercialProcess(Region[i][j], Region, i, j);
                if (availableWorkers > 0 && availableGoods > 0) {
                    availableWorkers -= 1;
                    availableGoods -= 1;
                }
            }
        }
    }



    // Updated lines for output:
    std::cout << "Available Workers: " << availableWorkers << std::endl;
    std::cout << "Available Goods: " << availableGoods << std::endl;
    std::cout << "Press 'A' to advance the sim." << std::endl;
    std::cout << "Press 'X' to exit the sim." << std::endl;
    std::cout << "Press 'Q' to edit config file." << std::endl;
}
