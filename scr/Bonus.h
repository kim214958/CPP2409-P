#ifndef Bonus_H
#define Bonus_H

#include <iostream>
#include <string>
using namespace std;

class Bonus
{
private: // 점수 관련 변수의 접근 제어를 위한 private
    // Bonus 객체를 사용하는 모든 객체에서 스코어, 보너스, 사용한 보너스를 공유하기 위한 static
    // static이 없으면 값이 공유되지 않는다.
    static int score;     // 점수
    static int bonus;     // 보너스
    static int used_bonus; // 사용된 보너스
public:
    // 캡슐화한 score, bonus, usedbonus의 getter, setter
    int GetScore();
    int GetBonus();
    int GetUsedBonus();

    void SetScore(int record);
    void SetBonus(int record);
    void SetUsedBonus(int use);
    bool CheckUseBonus(); // 보너스 사용여부를 물어보는 함수
    bool UseBonus();      // 보너스 사용을 결정하는 함수
};

#endif