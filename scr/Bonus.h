#include <iostream>
#include <string>
using namespace std;

class Bonus{
    private:
    static int score;
    static int bonus;
    static int usedbonus;
    public:
    int getScore();
    int getBonus();
    int getUsedBonus();
    bool checkUseBonus();
    void setScore(int record);
    void setBonus(int record);
    void setUsedBonus(int use);
    void useBonus();
};