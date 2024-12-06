#ifndef CHECK_INPUT_H
#define CHECK_INPUT_H

#include <iostream>
#include <string>
using namespace std;

class CheckInput // 사용자의 입력과 관련된 필드들
{
public:
    string user_input; // 사용자로부터 입력받은 문자열
    string user_input2;
    bool is_bonus_used; // 보너스 사용 여부
    bool give_score;    // 점수획득 여부를 결정
    bool IsNumber(string &choice); // 사용자의 입력이 숫자인지 확인하는 함수
    bool IsNumber(string &choice1, string &choice2); // 사용자의 입력 2개가 숫자인지 확인하는 함수
    bool IsAlphabet(char choice); // 사용자의 입력이 알파벳인지 확인하는 함수
    virtual bool IsValidNumber(int choice); // 사용자의 입력이 유효한 숫자인지 확인하는 함수
    virtual void SetInstruction() = 0;
};

#endif