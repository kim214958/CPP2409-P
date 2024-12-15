#include <ctime>
#include "tictactoe.h"
#include "Bonus.h"
using namespace std;

void TTT::SetInstruction()
{
	cout << "틱텍토(빙고) 게임을 실행합니다." << endl;
	cout << "플레이어와 컴퓨터가 번갈아가면서 돌을 둡니다." << endl;
	cout << "먼저 돌 3개로 한 줄(대각선 포함)을 완성하면 승리합니다." << endl;
	cout << "보너스를 사용하면 첫 차례에 돌을 한 번 더 둘 수 있습니다." << endl;
}; // 게임 설명 오버라이딩

void TTT::ClearMap()
{ // 틱텍토의 보드판을 초기화하는 함수
	// 벡터의 1D, 2D 크기를 NUM_CELL로 설정하면서 초기화
	map = vector<vector<char>>(NUM_CELL, vector<char>(NUM_CELL));
	for (int i = 0; i < NUM_CELL; i++)
	{
		for (int j = 0; j < NUM_CELL; j++)
		{
			map[i][j] = ' '; // 각 위치를 빈 칸(' ')으로 초기화
		}
	}
}

void TTT::SetCurrentPlayer()
{ // 현재 플레이어의 돌을 설정하는 함수 (플레이어는 2명)
	switch (turn_check % 2)
	{ // 현재 턴에 따라 다음 플레이어의 차례(돌)이 결정됨
	case 0:
		current_player = 'X'; // 유저의 돌
		break;
	case 1:
		current_player = 'O'; // 컴퓨터의 돌
		break;
	}
}

int TTT::IsValid(int x, int y)
{ // 입력한 좌표가 유효한 좌표인지 확인하는 함수
	if (x >= NUM_CELL || y >= NUM_CELL)
	{ // 좌표 범위를 벗어날때 -100을 반환
		return -100;
	}
	else if (map[x][y] != ' ')
	{ // 입력한 좌표에 돌이 놓여있으면 -200 반환
		return -200;
	}
	else
		return 0; // 유효한 좌표면 0을 반환
}

void TTT::GetUserInput()
{ // 사용자로부터 돌을 둘 좌표를 받는 함수
	while (true)
	{
		cout << "유저 (" << current_player << ")의 차례입니다. -> ";
		cout << "(x, y) 좌표를 입력하세요 (띄어쓰기로 구분): ";
		cin >> user_input >> user_input2;

		// 입력받은 문자열이 숫자인지 확인
		if (!IsNumber(user_input, user_input2))
		{
			continue; // 숫자가 아니면 처음으로 돌아감 (다시 입력받음)
		}

		// 유효성 검사를 마치면 int로 캐스팅
		x = stoi(user_input);
		y = stoi(user_input2);

		if (!IsNegativeNumber(x) || !IsNegativeNumber(y))
		{
			continue; // 숫자가 음수이면 처음으로 돌아감
		}

		// 입력받은 숫자가 유효한 숫자인지 확인
		// -100을 반환하면 보드판을 벗어나는 숫자, -200을 반환하면 이미 돌이 있는 보드칸
		// 유효하지 않은 숫자를 입력시 처음으로 돌아감 (다시 입력받음)
		if (IsValid(x, y) == -100)
		{
			cout << x << "," << y << ": x와 y둘중 하나가 칸을 벗어납니다. " << endl;
			continue;
		}
		if (IsValid(x, y) == -200)
		{ // 좌표범위의 입력값이 중복될때
			cout << x << "," << y << ": 이미 돌이 차있습니다. " << endl;
			continue;
		}
		if (IsValid(x, y) == 0)
		{
			// 유효성을 검사를 통과한 좌표에 유저의 돌을 두고 보드판 출력
			map[x][y] = current_player;
			break; // 성공적으로 돌을 두면 루프 종료
		}
	}
}

void TTT::GetComputerInput()
{ // 컴퓨터의 선택을 결정하는 함수
	cout << "컴퓨터 (" << current_player << ")의 차례입니다. " << endl;
	while (1)
	{ // 유효한 숫자를 결정하기위한 루프
		// 컴퓨터의 입력은 0~NUM_CELL-1까지 즉 좌표 범위 안의 숫자만 랜덤으로 생성한다.
		int comx = (rand() % NUM_CELL);
		int comy = (rand() % NUM_CELL);
		// 유효한 좌표의 숫자를 선택하면 해당 좌표에 컴퓨터의 돌을 둔다.
		if (IsValid(comx, comy) == 0)
		{
			map[comx][comy] = current_player;
			break; // 성공적으로 돌을 두면 루프 종료
		}
	}
}

void TTT::PrintMap()
{ // 틱텍토 보드판을 출력하는 함수
	for (int i = 0; i < NUM_CELL; i++)
	{
		for (int i = 0; i < NUM_CELL - 1; i++)
		{
			cout << "---|";
		}
		cout << "---" << endl;
		for (int j = 0; j < NUM_CELL; j++)
		{
			cout << map[i][j];
			if (j == NUM_CELL - 1)
			{
				break;
			}
			cout << "  |";
		}
		cout << endl;
	}
	for (int i = 0; i < NUM_CELL - 1; i++)
	{
		cout << "---|";
	}
	cout << "---" << endl;
}

bool TTT::CheckWin()
{ // 승자를 확인하는 함수
	// 가로,세로 빙고를 확인하는 부분
	for (int i = 0; i < NUM_CELL; i++)
	{
		bool rowWin = true, columnWin = true; // 가로빙고, 세로빙고 선언
		for (int j = 0; j < NUM_CELL; j++)
		{
			if (map[i][j] != current_player)
				rowWin = false; // 만약 가로줄에 놓여진 돌 중 플레이어의 것이 아닌 돌이나 빈칸이 있으면 가로빙고 = false
			if (map[j][i] != current_player)
				columnWin = false; // 만약 세로줄에 놓여진 돌 중 플레이어의 것이 아닌 돌이나 빈칸이 있으면 세로빙고 = false
		}
		if (rowWin == true)
		{
			cout << "가로에 모두 돌이 놓였습니다!" << endl;
			return true; // 가로 빙고이면 가로빙고임을 알리고 true를 반환
		}
		if (columnWin == true)
		{
			cout << "세로에 모두 돌이 놓였습니다!" << endl;
			return true; // 세로 빙고이면 세로빙고임을 알리고 true를 반환
		}
	}
	// (대각선 왼쪽 위 -> 오른쪽 아래) 빙고 확인
	for (int i = 0; i < NUM_CELL; i++)
	{
		if (map[i][i] != current_player)
		{ // 만약 대각선에 놓여진 돌 중 플레이어의 것이 아닌 돌이나 빈칸이 있으면 대각선 빙고 = false
			break;
		}
		if (i == NUM_CELL - 1)
		{ // 모든 대각선을 확인했을 때 플레이어 것이 아닌 돌이나 빈칸이 없으면 (= 모두 플레이어의 돌이면)
			cout << "왼쪽 위 -> 오른쪽 아래 대각선에 모두 돌이 놓였습니다!" << endl;
			return true; // 대각선 빙고임을 알리고 true를 반환
		}
	}
	// (대각선 오른쪽 위 -> 왼쪽 아래) 빙고 확인
	for (int i = 0; i < NUM_CELL; i++)
	{
		if (map[i][NUM_CELL - 1 - i] != current_player)
		{ // 만약 대각선에 놓여진 돌 중 플레이어의 것이 아닌 돌이나 빈칸이 있으면 대각선 빙고 = false
			break;
		}
		if (i == NUM_CELL - 1)
		{ // 모든 대각선을 확인했을 때 플레이어 것이 아닌 돌이나 빈칸이 없으면 (= 모두 플레이어의 돌이면)
			cout << "오른쪽 위 -> 왼쪽 아래 대각선에 모두 돌이 놓였습니다!" << endl;
			return true; // 대각선 빙고임을 알리고 true를 반환
		}
	}
	return false; // 승리조건을 만족하지 못하면 false를 반환
}

bool TTT::CheckFullMap()
{ // 틱텍토 보드가 다 찼는지 확인하는 함수
	// 빈칸을 세는 변수
	int checked = 0;
	for (int i = 0; i < NUM_CELL; i++)
	{
		for (int j = 0; j < NUM_CELL; j++)
		{
			if (map[i][j] == ' ')
			{
				checked++; // 틱텍토 보드칸에 빈칸이 있으면 checked를 증가
			}
		}
	}

	// 빈칸이 없으면 true를 반환
	if (checked == 0)
	{
		return true;
	}
	// 빈칸이 있으면 false를 반환
	return false;
}

// 틱텍토 게임을 실행하는 함수
int TTT::PlayTTT()
{
	// 게임을 진행하는 데 필요한 변수 초기화
	turn_check = 0;		  // 누구 차례인지 체크하기 위한 변수
	current_player = ' '; // 현재 플레이어의 돌을 나타내는 변수
	x, y = 0;			  // 사용자의 입력 초기화

	srand(time(0));						  // 컴퓨터의 무작위 선택을 위한 난수 생성
	ClearMap();							  // 보드판 초기화
	Bonus ttt_bonus;					  // 보너스 시스템을 위한 보너스 객체
	is_bonus_used = ttt_bonus.useBonus(); // 보너스 사용여부를 확인
										  // 게임 플레이를 위한 반복문
	while (true)
	{
		SetCurrentPlayer(); // 현재 플레이어의 돌을 설정 (처음은 유저의 차례이다.)

		if (current_player == 'X')
		{
			GetUserInput(); // 유저의 차례이면 유저로부터 x,y 좌표를 입력받음 & 보드판에 돌을 놓음
			PrintMap();		// 보드판 출력
		}
		else if (current_player == 'O')
		{
			GetComputerInput(); // 컴퓨터의 차례이면 컴퓨터의 선택을 설정 & 보드판에 돌을 놓음
			PrintMap();			// 보드판 출력
		}

		// 보너스가 사용되었으면 처음으로 돌아감 (= 아직 turn이 넘어가지 않았으므로 플레이어가 돌을 한번 더 둔다.)
		if (is_bonus_used == true)
		{
			is_bonus_used = false; // 보너스가 중복으로 사용됨을 막기위해 false를 대입
			continue;
		}
		// 승자 여부를 확인
		if (CheckWin())
		{ // 승자가 결정되었으면 (각 플레이어의 턴에는 현재 플레이어의 승리 여부만 결정된다.)
			if (current_player == 'X')
			{
				cout << "플레이어 (" << current_player << ")의 승리입니다!" << endl;
				give_score = true; // 점수 부여 여부를 true로
				break;			   // 루프문 종료
			}
			else if (current_player == 'O')
			{
				cout << "컴퓨터 (" << current_player << ")의 승리입니다..." << endl;
				give_score = false; // 점수 부여 여부를 false로
				break;				// 루프문 종료
			}
		}
		// 보드판이 다 찼으면 게임을 종료한다.
		if (CheckFullMap() == true)
		{
			cout << "모든 칸이 다 찼습니다.  종료합니다. " << endl;
			give_score = false; // 점수 부여 여부를 false로
			break;				// 루프문 종료
		}

		// 승자가 결정되지 않거나 보드판에 빈칸이 남았다면
		turn_check++; // 턴을 넘김
	}

	// 점수 부여 여부가 true이면 (승리했다면)
	if (give_score == true)
	{
		ttt_bonus.setScore(ttt_bonus.getScore() + 100); // 점수 +100, 누적점수 갱신
		ttt_bonus.setBonus(ttt_bonus.getScore());		// 남은 보너스 갱신
	}

	return 0; // 틱텍토 프로그램 종료
}