#ifndef TTT_H
#define TTT_H

#include <iostream>
#include <string>
#include <vector>
#include "Check_Input.h"
using namespace std;

class TTT : public CheckInput
{
    const int NUM_CELL = 3;              // 보드판의 가로 세로 길이 3칸으로 고정
    int turn_check;            // 누구 차례인지 체크하기 위한 변수
    int num_user;              // 게임에 참가한 유저수
    string userx, usery;      // 사용자가 입력한 x, y값
    int x, y;                 // 유효성 검사를 통과한 x,y 입력값
    int comx, comy;           // 컴퓨터가 선택한 x, y값
    char current_player;       // 현재 플레이어의 돌을 나타내는 변수
    bool is_win;               // 우승자를 확인하는 변수
    bool is_bonus_used;         // 보너스가 사용되었는지 확인하는 변수
    bool give_score;           // 점수 부여 여부를 결정하는 함수
    vector<vector<char>> map; // 틱텍토 보드판

public:
    int IsValid(int x, int y); // 입력한 좌표가 유효한 좌표인지 확인하는 함수
    bool CheckWin();                        // 승자를 확인하는 함수
    int PlayTTT();                          // 틱텍토 게임을 실행하는 함수
    void ClearMap();                        // 틱텍토의 보드판을 초기화하는 함수
    void SetCurrentPlayer();                // 현재 플레이어의 돌을 설정하는 함수
    void PrintMap();                        // 틱텍토 보드판을 출력하는 함수
    bool CheckFullMap();                    // 틱텍토 보드가 다 찼는지 확인하는 함수
    void SetComputerChoice();               // 컴퓨터의 선택을 결정하는 함수
};

#endif