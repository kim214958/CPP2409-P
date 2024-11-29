#ifndef TTT_H
#define TTT_H

#include <iostream>
#include <string>
#include <vector>
#include "Check_Input.h"
using namespace std;

class TTT : public CheckInput
{
    const int NUM_CELL = 3;   // 보드판의 가로 세로 길이 3칸으로 고정
    char current_player;      // 현재 플레이어의 돌을 나타내는 변수
    int turn_check;           // 누구 차례인지 체크하기 위한 변수
    int x, y;                 // 유효성 검사를 통과한 사용자의 입력 좌표
    vector<vector<char>> map; // 틱텍토 보드판

public:
    void ClearMap();           // 틱텍토의 보드판을 초기화하는 함수
    void SetCurrentPlayer();   // 현재 플레이어의 돌을 설정하는 함수
    void PrintMap();           // 틱텍토 보드판을 출력하는 함수
    int IsValid(int x, int y); // 입력한 좌표가 유효한 좌표인지 확인하는 함수
    void GetUserInput();       // 사용자로부터 돌을 둘 좌표를 받는 함수
    void GetComputerInput();   // 컴퓨터의 선택을 결정하는 함수
    bool CheckWin();           // 승자를 확인하는 함수
    bool CheckFullMap();       // 틱텍토 보드가 다 찼는지 확인하는 함수
    int PlayTTT();             // 틱텍토 게임을 실행하는 함수
};

#endif