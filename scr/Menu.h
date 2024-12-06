#ifndef Menu_H
#define Menu_H

#include "Mukchippa.h"
#include "tictactoe.h"
#include "Hangman.h"
#include "SortNumber.h"
#include "Bonus.h"
#include "Check_Input.h"

class Menu : public CheckInput
{
private:
    int choice;

public:
    void SetInstruction() override;
    bool IsValidNumber(int choice) override; // 사용자의 입력이 유효한 숫자인지 확인하는 함수
    void GetInstruction();
    void ShowScore();
    void SelectGame();
    bool PlayRandom();
    void PlayGame();
};

#endif