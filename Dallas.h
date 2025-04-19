

#ifndef DALLAS_H
#define DALLAS_H

#include <vector>
using namespace std;

class Dallas {
public:
    Dallas(char T = '\0', int P = 0);

    void setType(char t);
    void setPollution(int p);
    char getType() const;
    int getPollution() const;
    int getWorkers() const;
    int getGoods() const;
    int getPopulation() const;
    void updatePopulation();
    bool isPowerline() const;
    void assignWorker();
    void assignGoods();

    // Static method to calculate total pollution
    static int getTotalPollution(const vector<vector<Dallas>>& region);

private:
    char type = '\0';
    int pollution = 0;
    int workers = 0;
    int goods = 0;
    int population = 0;
    bool hasWorker = false;
    bool hasGood = false;
};

#endif
