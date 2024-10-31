# include <iostream>
#include <string>
using namespace std;

class MCP{
    int UserChoice;
    int ComputerChoice;
    int turn; //100이면 사용자의 차례, -100이면 컴퓨터의 차례


    public:
    int getUserChoice();
    int getComputerChoice();
    bool checkWin();
};
