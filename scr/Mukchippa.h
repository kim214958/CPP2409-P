# include <iostream>
#include <string>
using namespace std;

class MCP{
    string UserInput;
    int UserChoice;
    int ComputerChoice;
    int turn; //100이면 사용자의 공격, -100이면 컴퓨터의 공격, 0이면 공격자 미정
    int Winner; // 사용자가 이기면 1000, 컴퓨터가 이기면 -1000을 반환 0이면 미정
    bool PlayFlag;
    bool giveScore; // 점수획득 여부를 결정
    bool isBonusUsed; // 보너스가 사용되었는지 확인

    public:
    int getUserInput();
    int getComputerChoice();
    bool isNumber(string &choice);
    bool isValidNumber(int choice);
    
    int checkWin(int turn, int UserChoice, int ComputerChoice);
    int playMCP();
    int turnCheck(int UserChoic, int ComputerChoice);
    void showComputerChoice();
};
