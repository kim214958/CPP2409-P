#include "Mukchippa.h"
#include "Bonus.h"
#include <ctime>

bool MCP::isNumber(string &choice){
    for (char c : choice) {
        if (!isdigit(c)) return false;
    }
    return true;
}
bool MCP::isValidNumber(int choice){
    return choice == 1 || choice == 2 || choice == 3;
}

int MCP::getUserInput() {
    while (true) {
        cout << "묵,찌,빠 중 원하는 손동작의 번호를 입력하세요 (1: 묵, 2: 찌, 3: 빠): ";
        cin >> UserInput;

        // 숫자 여부 확인
        if (!isNumber(UserInput)) {
            cout << "잘못된 입력입니다. 숫자를 입력하세요.\n";
            continue;
        }

        // 유효한 숫자인지 확인
        UserChoice = stoi(UserInput);
        if (!isValidNumber(UserChoice)) {
            cout << "잘못된 입력입니다. 1, 2, 3 중 하나를 입력하세요.\n";
            continue;
        }

        return UserChoice; // 유효한 입력이 확인된 경우 반환
    }
}

int MCP::getComputerChoice(){
    return (rand() % 3 + 1);
}

void MCP::showComputerChoice(){
    switch(ComputerChoice){
        case(1): cout<<endl<<"컴퓨터가 묵을 냈습니다."<<endl<<endl; break;
        case(2): cout<<endl<<"컴퓨터가 찌를 냈습니다."<<endl<<endl; break;
        case(3): cout<<endl<<"컴퓨터가 빠를 냈습니다."<<endl<<endl; break;
    }
}

int MCP::turnCheck(int UserChoice, int ComputerChoice){
    if(ComputerChoice == UserChoice){
        return 0;}

    if((UserChoice == 1&& ComputerChoice == 2) || (UserChoice == 2&& ComputerChoice == 3) || (UserChoice == 3&& ComputerChoice == 1)){
        return 100;
    }
    if((ComputerChoice == 1&& UserChoice == 2) || (ComputerChoice == 2&& UserChoice == 3) || (ComputerChoice == 3&& UserChoice == 1)){
        return -100;
    }
    
    return 0; // 예외값
}

int MCP::checkWin(int turn, int UserChoice, int ComputerChoice){
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

int MCP::playMCP(){
    Bonus mcpbonus;
    srand(time(0));
    PlayFlag = true;
    bool bonusflag = true;
    while(PlayFlag){
        if(bonusflag){
            isBonusUsed = mcpbonus.checkUseBonus();
            if(isBonusUsed == true){
                    mcpbonus.useBonus();
            }
            bonusflag = false; // 루프 중 한 번만 보너스 사용을 체크
        }
        UserChoice = getUserInput();
        ComputerChoice = getComputerChoice();
        showComputerChoice();

        turn = turnCheck(UserChoice, ComputerChoice);

        if(turn == 0){
            continue;
        }

        while (true) {
            UserChoice = getUserInput();
            ComputerChoice = getComputerChoice();
            showComputerChoice();
            Winner = checkWin(turn, UserChoice, ComputerChoice);

            if (Winner == 1000) {
                cout << "승자는 플레이어입니다!" << endl;
                PlayFlag = false;
                giveScore = true;
                break;
            } else if (Winner == -1000) {
                if(isBonusUsed == true){
                    cout<<"패배 방어권을 사용합니다. 컴퓨터의 공격을 다시 막으세요."<< endl;
                    isBonusUsed = false; // 패배 방어권 재사용을 막음
                    continue;
                }
                cout << "승자는 컴퓨터입니다.." << endl;
                PlayFlag = false;
                giveScore = false;
                break;
            }
            // 승자가 결정되지 않은 경우 공격권을 재설정
            turn = turnCheck(UserChoice, ComputerChoice);
        }
    }
    // testing bonus
    if(giveScore == true){
        mcpbonus.setScore(mcpbonus.getScore()+100); // 누적점수 갱신
        mcpbonus.setBonus(mcpbonus.getScore()); // 남은 보너스 갱신
    }
    
    return 0;
}
