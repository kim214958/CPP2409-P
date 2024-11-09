# include <iostream>
#include <string>
using namespace std;

class MCP{
    string UserInput; // 사용자로부터 입력받은 문자열
    int UserChoice; // 유효검사를 완료한 사용자의 선택
    int ComputerChoice; // 컴퓨터의 선택
    int turn; //100이면 사용자의 공격, -100이면 컴퓨터의 공격, 0이면 공격자 미정
    int Winner; // 승자를 표시하는 변수, 사용자가 이기면 1000, 컴퓨터가 이기면 -1000을 반환 0이면 미정
    bool giveScore; // 점수획득 여부를 결정
    bool isBonusUsed; // 보너스가 사용되었는지 확인

    public:
    int getUserInput(); // 사용자로부터 선택을 입력받는 함수
    int getComputerChoice(); // 컴퓨터의 선택을 결정하는 함수
    void showComputerChoice(); // 컴퓨터의 선택을 출력하는 함수
    bool isNumber(string &choice); // 사용자의 입력이 숫자인지 확인하는 함수
    bool isValidNumber(int choice); // 사용자가 입력한 숫자가 유효한 숫자인지 확인하는 함수
    int turnCheck(int UserChoic, int ComputerChoice); // 공격권을 결정하는 함수
    int checkWin(int turn, int UserChoice, int ComputerChoice); // 승자 확인 함수
    int playMCP(); // 실제 게임을 실행시키는 함수
};
