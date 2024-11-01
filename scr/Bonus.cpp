#include "Bonus.h"

int Bonus::score = 0;
int Bonus::bonus = 0;
int Bonus::usedbonus = 0;

void Bonus::setScore(int record){
    score = record;
}

int Bonus::getScore(){
    return score; 
}

void Bonus::setBonus(int record){
    bonus = getScore()/200 - getUsedBonus();
}

int Bonus::getBonus(){
    return bonus;
}

void Bonus::setUsedBonus(int use){
    usedbonus += use;
}

int Bonus::getUsedBonus(){
    return usedbonus;
}

bool Bonus::checkUseBonus(){
    string input;
    while(true){
        if(getBonus() >= 1){
            cout << "보너스를 사용하시겠습니까? 보유한 보너스:" << getBonus() << "개" << endl;
            cout << "사용하시려면 'y'를, 사용하지 않으시려면 'n'을 입력하세요."<<endl;
            cin >> input;
            if (input == "y" || input == "Y") {
                return true;
            } 
            else if (input == "n" || input == "N") {
                return false;
            } 
            else {
                cout << "잘못된 입력입니다. y 또는 n을 입력해주세요."<<endl;
            }
        }
    }
    return false; // 보유한 보너스가 0개이면 false를 반환
}

void Bonus::useBonus(){
    setUsedBonus(1); // 사용된 보너스를 1 증가
    setBonus(getScore()); // 남은 보너스를 갱신
}