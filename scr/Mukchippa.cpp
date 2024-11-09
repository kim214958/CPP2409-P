#include "Mukchippa.h"
#include "Bonus.h"
#include <ctime>

bool MCP::isNumber(string &choice){ // 사용자의 입력이 숫자인지 확인하는 함수
    // 사용자의 문자열의 문자에 대해서
    for (char c : choice) {
        if (!isdigit(c)) return false; // 문자중 숫자가 아닌게 있으면 false를 반환
    }
    return true; // 문자가 전부 숫자면 true를 반환
}

bool MCP::isValidNumber(int choice){ // 사용자의 입력이 유효한 숫자인지 확인하는 함수
    // 사용자가 1,2,3 중 하나를 입력했으면 true를, 아니면 false를 반환
    return choice == 1 || choice == 2 || choice == 3;
}

int MCP::getUserInput() { // 사용자로부터 입력을 받는 합수
    while (true) {
        cout << "묵,찌,빠 중 원하는 손동작의 번호를 입력하세요 (1: 묵, 2: 찌, 3: 빠): ";
        cin >> UserInput;
        // 사용자가 숫자를 입력했는지 확인
        if (!isNumber(UserInput)) {
            cout << "잘못된 입력입니다. 숫자를 입력하세요." << endl;
            continue;
        }
        // 입력한 유효한 숫자인지 확인
        UserChoice = stoi(UserInput); // UserInput은 String이므로 Int로 캐스팅 해야한다.
        if (!isValidNumber(UserChoice)) {
            cout << "잘못된 입력입니다. 1, 2, 3 중 하나를 입력하세요." <<endl;
            continue;
        }
        return UserChoice; // 유효검사를 통과한 선택을 반납
    }
}

int MCP::getComputerChoice(){ // 컴퓨터의 선택을 결정하는 함수
    return (rand() % 3 + 1); // 컴퓨터는 1,2,3중 무작위로 하나를 선택한다.
}

void MCP::showComputerChoice(){ // 컴퓨터의 선택을 보여주는 함수
    switch(ComputerChoice){ // 컴퓨터의 선택을 출력함
        case(1): cout<<endl<<"컴퓨터가 묵을 냈습니다."<<endl<<endl; break;
        case(2): cout<<endl<<"컴퓨터가 찌를 냈습니다."<<endl<<endl; break;
        case(3): cout<<endl<<"컴퓨터가 빠를 냈습니다."<<endl<<endl; break;
    }
}

int MCP::checkWin(int turn, int UserChoice, int ComputerChoice){ // 승자가 결정되었는지 확인하는 함수
    // 유저가 이기면 1000을 반환
    if(turn==100 && (UserChoice == ComputerChoice)){
        return 1000;
    }
    // 컴퓨터가 승리하면 -1000을 반환
    if(turn==-100 && (UserChoice == ComputerChoice)){
        return -1000;
    }
    // 승자가 결정되지 않으면 0을 반환
    return 0;
}

int MCP::turnCheck(int UserChoice, int ComputerChoice){ // 공격권을 선택하는 함수
    // 비기면 0을 반환
    if(ComputerChoice == UserChoice){
        return 0;}
    // 플레이어가 첫번째 가위바위보를 이기면 플레이어가 공격권 획득(100을 반환)
    if((UserChoice == 1&& ComputerChoice == 2) || (UserChoice == 2&& ComputerChoice == 3) || (UserChoice == 3&& ComputerChoice == 1)){
        return 100;
    }
    // 컴퓨터가 첫번째 가위바위보를 이기면 컴퓨터가 공격권 획득(-100을 반환)
    if((ComputerChoice == 1&& UserChoice == 2) || (ComputerChoice == 2&& UserChoice == 3) || (ComputerChoice == 3&& UserChoice == 1)){
        return -100;
    }
    
    return 0; // 예외값
}

// 묵찌빠 게임을 실행하는 함수
int MCP::playMCP(){
    srand(time(0)); // 컴퓨터의 무작위 선택을 위한 난수 생성 
    Bonus mcpbonus; // 보너스 시스템을 위한 보너스 객체
    isBonusUsed = mcpbonus.checkUseBonus(); // 보너스 사용여부를 확인

    // 보너스를 사용여부가 true이면 보너스를 사용하는 함수를 호출
    if(isBonusUsed == true){
            mcpbonus.useBonus();
    }
    // 게임 플레이를 위한 반복문
    while (true) {
        UserChoice = getUserInput(); // 사용자의 선택
        ComputerChoice = getComputerChoice(); // 컴퓨터의 선택
        showComputerChoice(); // 컴퓨터의 선택을 출력
        Winner = checkWin(turn, UserChoice, ComputerChoice); // 승자를 확인하는 함수 호출

        if (Winner == 1000) { // 유저가 승리
            cout << "승자는 플레이어입니다!" << endl;
            giveScore = true; // 승리시 점수 획득
            break;
        } 
        else if (Winner == -1000) { // 컴퓨터가 승리
            // 보너스 사용여부가 true 이면
            if(isBonusUsed == true){
                cout<<"패배 방어권을 사용합니다. 컴퓨터의 공격을 다시 막으세요."<< endl;
                isBonusUsed = false; // 패배 방어권 재사용을 막기 위해 if문의 조건을 false로 변경
                continue; // 패배하지 않고 다시 방어할 기회를 제공
            }
            // 보너스를 사용하지 않거나, 패배 방어권 사용 후 다시 패배할 경우 컴퓨터의 승리    
            cout << "승자는 컴퓨터입니다.." << endl;
            giveScore = false; // 패배시 점수 획득 불가
            break; // 게임 플레이 반복문 탈출
        }
        // 승자가 결정되지 않은 경우 공격권을 재설정
        turn = turnCheck(UserChoice, ComputerChoice);
    }
    // 점수 계산
    if(giveScore == true){ // 승리시 점수 획득
        mcpbonus.setScore(mcpbonus.getScore()+100); // 점수 +100, 누적점수 갱신
        mcpbonus.setBonus(mcpbonus.getScore()); // 남은 보너스 갱신
    }
    
    return 0; // 묵찌빠 프로그램 종료
}
