#include "Bonus.h"

int Bonus::score = 0;
int Bonus::bonus = 0;
int Bonus::usedbonus = 0;

void Bonus::setScore(int record){ // 점수를 설정
    score = record;
}

int Bonus::getScore(){ // 점수를 반환
    return score; 
}

void Bonus::setBonus(int record){ // 남은 보너스를 설정
    bonus = getScore()/200 - getUsedBonus(); // 남은 보너스 = 점수/200 - 사용한 보너스의 수
}

int Bonus::getBonus(){  // 남은 보너스를 반환
    return bonus;
}

void Bonus::setUsedBonus(int use){  // 사용한 보너스의 수를 더하는 함수
    usedbonus += use;   // 매개변수의 값만큼 사용한 보너스의 수를 더함
}

int Bonus::getUsedBonus(){  // 사용한 보너스를 반환
    return usedbonus;
}

bool Bonus::checkUseBonus(){    // 보너스 사용여부를 확인하는 함수
    string input; // 사용자의 입력
    while(true){
        if(getBonus() >= 1){ // 남은 보너스가 1 이상이면
            cout << "보너스를 사용하시겠습니까? 보유한 보너스:" << getBonus() << "개" << endl;
            cout << "사용하시려면 'y'를, 사용하지 않으시려면 'n'을 입력하세요."<<endl;
            cin >> input;
            if (input == "y" || input == "Y") { // 사용자의 입력이 y이면 사용여부 true를 반환
                return true;
            } 
            else if (input == "n" || input == "N") { // 사용자의 입력이 n이면 사용여부 false를 반환
                return false;
            } 
            else { // 사용자의 입력이 y,n이 아니면 루프를 반복하여 입력을 다시 받음
                cout << "잘못된 입력입니다. y 또는 n을 입력해주세요."<<endl;
            }
        }
        else
            return false; // 남은 보너스가 0개이면 false를 반환
    }
}

void Bonus::useBonus(){ // 보너스를 사용하는 함수
    setUsedBonus(1); // 사용된 보너스를 1 증가
    setBonus(getScore()); // 남은 보너스를 갱신
}