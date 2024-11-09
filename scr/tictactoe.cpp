#include <ctime>
#include "tictactoe.h"
#include "Bonus.h"
using namespace std;

void TTT::clearMap(){ // 틱텍토의 보드판을 초기화하는 함수
	map = vector<vector<char>>(numCell, vector<char>(numCell)); // 벡터의 1D, 2D 크기를 nuCell로 설정하면서 초기화
    for (int i = 0; i < numCell; i++) {
        for (int j = 0; j < numCell; j++) {
            map[i][j] = ' '; // 각 위치를 빈 칸(' ')으로 초기화
        }
    }
}

void TTT::setCurrentPlayer(){ // 현재 플레이어의 돌을 설정하는 함수
	switch (turnCheck % numUser) { // 현재 턴에 따라 다음 플레이어의 차례(돌)이 결정됨
		case 0:
			currentPlayer = 'X'; // 유저의 돌
			break;
		case 1:			
			currentPlayer = 'O'; // 컴퓨터의 돌
			break;
		}
		
}

bool TTT::isNumber(string a, string b){ // 사용자의 입력이 숫자인지 확인하는 함수
    try { // stoi 예외처리를 위한 try-catch
			// 사용자의 String 입력을 int로 캐스팅한 값을 저장
            x = std::stoi(a);
            y = std::stoi(b);
        }
	catch (const std::invalid_argument& e) { // 숫자가 아닌 값을 입력했을 때 
            cout << "입력한 값이 숫자가 아닙니다. 다시 입력하세요." << endl;
			return false; // false를 반환
        }
	catch (const std::out_of_range& e) { // 너무 큰 숫자를 입력했을 때
            cout << "입력한 숫자가 너무 큽니다. 다시 입력하세요." << endl;
			return false; // false를 반환
        }
		return true; // 유효한 숫자면 true를 반환
}

int TTT::isValid(int x, int y, int numCell){ // 입력한 좌표가 유효한 좌표인지 확인하는 함수
  	if (x >= numCell || y >= numCell) { // 좌표 범위를 벗어날때 -100을 반환
        return -100;
	}
	else if (map[x][y] != ' ') { // 입력한 좌표에 돌이 놓여있으면 -200 반환
		return -200;
	}
	else
		return 0; // 유효한 좌표면 0을 반환
}

void TTT::setComputerChoice(){ // 컴퓨터의 선택을 결정하는 함수
	while(1){ // 유효한 숫자를 결정하기위한 루프
		// 컴퓨터의 입력은 0~numCell-1까지 즉 좌표 범위 안의 숫자만 랜덤으로 생성한다.
		comx = (rand() % numCell);
		comy = (rand() % numCell);
		if (isValid(comx,comy,numCell)==0) { // 유효한 숫자를 선택하면
			map[comx][comy] = currentPlayer; // 틱텍토 보드에 컴퓨터의 돌을 둔다.
			break; // 성공적으로 돌을 두면 루프 종료
		}
	}
}

void TTT::printMap(){ // 틱텍토 보드판을 출력하는 함수
	for (int i = 0; i <numCell; i++){
            for(int i = 0; i<numCell-1; i++){
                cout << "---|";
                }
            cout << "---" << endl;
            for (int j =0; j < numCell; j++){
                cout << map[i][j];
                if(j == numCell-1){
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        for(int i = 0; i<numCell-1; i++){
                cout << "---|";
                }
            cout << "---" << endl;
}

bool TTT::checkWin(){ // 승자를 확인하는 함수
	// 가로,세로 빙고를 확인하는 부분
	for (int i = 0; i < numCell; i++) {
		bool rowWin = true, columnWin = true; //가로빙고, 세로빙고 선언
        for (int j = 0; j < numCell; j++) {
            if (map[i][j] != currentPlayer) rowWin = false; //만약 가로줄에 놓여진 돌 중 플레이어의 것이 아닌 돌이나 빈칸이 있으면 가로빙고 = false
            if (map[j][i] != currentPlayer) columnWin = false; //만약 세로줄에 놓여진 돌 중 플레이어의 것이 아닌 돌이나 빈칸이 있으면 세로빙고 = false
        }
		if(rowWin == true){
			cout << "가로에 모두 돌이 놓였습니다!" << endl;
			return true;	//가로 빙고이면 가로빙고임을 알리고 true를 반환
		}
		if(columnWin == true){
			cout << "세로에 모두 돌이 놓였습니다!" << endl;
			return true;	//세로 빙고이면 세로빙고임을 알리고 true를 반환
		}
	}	
	// (대각선 왼쪽 위 -> 오른쪽 아래) 빙고 확인
    for(int i =0; i<numCell; i++){
        if(map[i][i] != currentPlayer){ // 만약 대각선에 놓여진 돌 중 플레이어의 것이 아닌 돌이나 빈칸이 있으면 대각선 빙고 = false
			break;
        }
        if(i == numCell-1){ //모든 대각선을 확인했을 때 플레이어 것이 아닌 돌이나 빈칸이 없으면 (= 모두 플레이어의 돌이면)
			cout << "왼쪽 위 -> 오른쪽 아래 대각선에 모두 돌이 놓였습니다!" << endl;
            return true; // 대각선 빙고임을 알리고 true를 반환
        }
    }
    // (대각선 오른쪽 위 -> 왼쪽 아래) 빙고 확인
    for(int i = 0; i < numCell; i++) {
        if(map[i][numCell - 1 - i] != currentPlayer) { // 만약 대각선에 놓여진 돌 중 플레이어의 것이 아닌 돌이나 빈칸이 있으면 대각선 빙고 = false
            break;
        }
        if(i == numCell - 1) { //모든 대각선을 확인했을 때 플레이어 것이 아닌 돌이나 빈칸이 없으면 (= 모두 플레이어의 돌이면)
			cout << "오른쪽 위 -> 왼쪽 아래 대각선에 모두 돌이 놓였습니다!" << endl;
            return true; // 대각선 빙고임을 알리고 true를 반환
        }
    }
	return false; // 승리조건을 만족하지 못하면 false를 반환
}

bool TTT::checkFullMap(){ // 틱텍토 보드가 다 찼는지 확인하는 함수
	int checked = 0; // 빈칸을 세는 변수
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			if (map[i][j] == ' ') {
					checked++; // 틱텍토 보드칸에 빈칸이 있으면 checked를 증가
			}
		}
	}
	if (checked == 0) { // 빈칸이 없으면 true를 반환
		return true;
	}
	return false; // 빈칸이 있으면 false를 반환
}

// 틱텍토 게임을 실행하는 함수
int TTT::playTTT(){
	// 게임을 진행하는 데 필요한 변수 초기화
	numCell = 3; // 보드판의 가로 세로 길이
	turnCheck = 0; // 누구 차례인지 체크하기 위한 변수
	numUser = 2; // 게임에 참가한 유저의 수
	currentPlayer = ' '; // 현재 플레이어의 돌을 나타내는 변수
	x, y = 0; // 사용자로부터 받아낸 x좌표, y좌표
	isWin = false; // 우승자를 확인하는 변수

	srand(time(0)); // 컴퓨터의 무작위 선택을 위한 난수 생성 
	clearMap(); // 보드판 초기화
	Bonus TTTbonus; // 보너스 시스템을 위한 보너스 객체
    isBonusUsed = TTTbonus.checkUseBonus(); // 보너스 사용여부를 확인
	
	// 보너스를 사용여부가 true이면 보너스를 사용하는 함수를 호출
    if(isBonusUsed == true){
        TTTbonus.useBonus();
    }
    // 게임 플레이를 위한 반복문      
	while(true){
		setCurrentPlayer(); // 현재 플레이어의 돌을 설정 (처음은 유저의 차례이다.)
		
		if(currentPlayer == 'X'){ // 유저의 차례이이면
			// 유저로부터 x,y 좌표를 입력받는다.
			cout << "유저 ("<< currentPlayer <<")의 차례입니다. -> ";
			cout << "(x, y) 좌표를 입력하세요: ";
			cin >> userx >> usery;
			// 입력받은 문자열이 숫자인지 확인
			if(!isNumber(userx, usery)){
				continue; // 숫자가 아니면 처음으로 돌아감 (다시 입력받음)
			}
			// 입력받은 숫자가 유효한 숫자인지 확인
			// -100을 반환하면 보드판을 벗어나는 숫자, -200을 반환하면 이미 돌이 있는 보드칸
			// 유효하지 않은 숫자를 입력시 처음으로 돌아감 (다시 입력받음)
			if(isValid(x,y,numCell)==-100){
            	cout << x << "," << y << ": x와 y둘중 하나가 칸을 벗어납니다. " << endl;
            	continue;
        	}
			if (isValid(x,y,numCell)==-200) {// 좌표범위의 입력값이 중복될때
				cout << x << "," << y << ": 이미 돌이 차있습니다. " << endl;
				continue;
			}
			// 유효성을 검사를 통과한 좌표에 유저의 돌을 두고 보드판 출력
			map[x][y] = currentPlayer;
			printMap();
		}
		else if(currentPlayer == 'O'){ // 컴퓨터의 차례이면
			cout << "컴퓨터 ("<< currentPlayer <<")의 차례입니다. " <<endl;
			setComputerChoice(); // 컴퓨터의 선택을 설정 & 보드판에 돌을 놓음
			printMap(); // 보드판 출력
		}
		// 보너스가 사용되었으면 처음으로 돌아감 (= 아직 turn이 넘어가지 않았으므로 플레이어가 돌을 한번 더 둔다.)
		if(isBonusUsed == true){
			isBonusUsed = false; // 보너스가 중복으로 사용됨을 막기위해 false를 대입
        	continue;
   		}
		// 승자 여부를 확인하고 isWin 변수에 담는다.
		isWin = checkWin();
		if (isWin == true) { // 승자가 결정되었으면 (각 플레이어의 턴에는 현재 플레이어의 승리 여부만 결정된다.)
			if(currentPlayer == 'X'){
				cout << "플레이어 ("<< currentPlayer <<")의 승리입니다!"<<endl;
				giveScore = true; // 점수 부여 여부를 true로
				break; // 루프문 종료
			}
			else if(currentPlayer == 'O'){
				cout << "컴퓨터 ("<< currentPlayer <<")의 승리입니다..."<<endl;
				giveScore = false; // 점수 부여 여부를 false로
				break; // 루프문 종료
			}
		}
		// 보드판이 다 찼으면 게임을 종료한다.
		if(checkFullMap() == true){
			cout << "모든 칸이 다 찼습니다.  종료합니다. " << endl;
			giveScore = false; // 점수 부여 여부를 false로
			break; // 루프문 종료
		}

		// 승자가 결정되지 않거나 보드판에 빈칸이 남았다면
		turnCheck++; // 턴을 넘김

	}

	// 점수 부여 여부가 true이면 (승리했다면)
	if(giveScore == true){
        TTTbonus.setScore(TTTbonus.getScore()+100); // 점수 +100, 누적점수 갱신
        TTTbonus.setBonus(TTTbonus.getScore()); // 남은 보너스 갱신
    }

	return 0; // 틱텍토 프로그램 종료
}