#ifndef MCP_H
#define MCP_H

#include "Check_Input.h"
#include "Bonus.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class MCP : public CheckInput
{
public:
    int user_choice;     // 유효검사를 완료한 사용자의 선택
    int computer_choice; // 컴퓨터의 선택
    int turn;            // 100이면 사용자의 공격, -100이면 컴퓨터의 공격, 0이면 공격자 미정
    int winner;          // 승자를 표시하는 변수, 사용자가 이기면 1000, 컴퓨터가 이기면 -1000을 반환 0이면 미정

    void SetInstruction() override;                               // 게임 설명 오버라이딩
    int GetUserInput();                                           // 사용자로부터 선택을 입력받는 함수
    int GetComputerChoice();                                      // 컴퓨터의 선택을 결정하는 함수
    void ShowComputerChoice();                                    // 컴퓨터의 선택을 출력하는 함수
    int TurnCheck(int user_choic, int computer_choice);           // 공격권을 결정하는 함수
    int CheckWin(int turn, int user_choice, int computer_choice); // 승자 확인 함수
    int PlayMCP();                                                // 실제 게임을 실행시키는 함수
};

#endif