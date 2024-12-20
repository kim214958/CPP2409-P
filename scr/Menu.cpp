#include "Menu.h"

void Menu::SetInstruction()
{
    cout << "게임 설명이 설정되지 않았습니다." << endl;
};

bool Menu::IsValidNumber(int choice)
{ // 사용자의 입력이 유효한 숫자인지 확인하는 함수
    // 사용자가 1,2,3,4 중 하나를 입력했으면 true를, 아니면 false를 반환
    return choice == 1 || choice == 2 || choice == 3 || choice == 4;
}

void Menu::GetInstruction()
{
    int num;
    while (true)
    {
        cout << "설명들을 게임을 선택하세요 (1. 묵찌빠, 2. 틱택토, 3. 행맨, 4. 숫자 정렬): ";
        cin >> user_input; // 사용자로부터 입력을 받음(string)
        cout << endl;

        if (!IsNumber(user_input)) // 입력받은 값이 숫자가 아니면 다시 입력받음
        {
            continue;
        }

        if (!IsValidNumber(stoi(user_input))) // 입력받은 값이 1,2,3,4인지 확인
        {
            cout << "유효하지 않은 숫자입니다." << endl;
            continue;
        }

        num = stoi(user_input); // 입력받은 값을 int형으로 반환
        break;
    }
    // 게임들의 부모 객체 생성성
    CheckInput *info;

    switch (num)
    { // 각 게임 객체를 상향 형변환
    case 1:
    {
        info = new MCP();
        break;
    }
    case 2:
    {
        info = new TTT();
        break;
    }
    case 3:
    {
        info = new HM();
        break;
    }
    case 4:
    {
        info = new SN();
        break;
    }
    }

    //형변환한 객체의 SetInstruction()함수를 호출
    info->SetInstruction();
    delete info;
    return;
}

void Menu::ShowScore()
{
    Bonus bonus; // 보너스 객체 생성
    cout << "점수 : " << bonus.GetScore() << endl;
    cout << "남은 보너스 : " << bonus.GetBonus() << endl;
    cout << "사용된 보너스 : " << bonus.GetUsedBonus() << endl;
}

bool Menu::PlayRandom()
{ // 무작위 플레이 여부 확인 함수
    while (true)
    {
        cout << "무작위 게임을 실행하시겠습니까? (y/n): ";
        cin >> user_input;
        cout << endl;

        if (user_input == "y" || user_input == "Y")
        { // 사용자의 입력이 y이면 사용여부 true를 반환
            return true;
        }
        else if (user_input == "n" || user_input == "N")
        { // 사용자의 입력이 n이면 사용여부 false를 반환
            return false;
        }
        else
        { // 사용자의 입력이 y,n이 아니면 루프를 반복하여 입력을 다시 받음
            cout << "잘못된 입력입니다. y 또는 n을 입력해주세요." << endl;
        }
    }
}

void Menu::SelectGame()
{                                 // 플레이할 게임 선택
    bool game_select_flag = true; // 게임 선택 여부 확인
    int num = 0;

    if (PlayRandom()) // 무작위 게임 선택 여부
    {
        num = (rand() % 4) + 1;   // 1~4까지 무작위 숫자 생성
        game_select_flag = false; // 게임 선택 X
    }

    while (game_select_flag)
    {
        cout << "실행할 게임을 선택하세요 (1. 묵찌빠, 2. 틱택토, 3. 행맨, 4. 숫자 정렬): ";
        cin >> user_input; // 사용자로부터 입력을 받음(string)
        cout << endl;

        if (!IsNumber(user_input)) // 입력받은 값이 숫자가 아니면 다시 입력받음
        {
            continue;
        }

        if (!IsValidNumber(stoi(user_input))) // 입력받은 값이 1,2,3,4인지 확인
        {
            cout << "유효하지 않은 숫자입니다." << endl;
            continue;
        }

        num = stoi(user_input); // 입력받은 값을 int형으로 반환
        break;
    }

    switch (num)
    {
    case 1:
    {
        cout << "묵찌빠 게임을 실행합니다." << endl;
        MCP *mcp = new MCP();
        mcp->PlayMCP();
        delete mcp;
        return;
    }
    case 2:
    {
        cout << "틱택토 게임을 실행합니다." << endl;
        TTT *ttt = new TTT();
        ttt->PlayTTT();
        delete ttt;
        return;
    }
    case 3:
    {
        cout << "행맨 게임을 실행합니다." << endl;
        HM *hm = new HM();
        hm->PlayHM();
        delete hm;
        return;
    }
    case 4:
    {
        cout << "숫자 정렬 게임을 실행합니다." << endl;
        SN *sn = new SN();
        sn->PlaySN();
        delete sn;
        return;
    }
    }
}

void Menu::PlayGame()
{
    srand(time(0));
    cout << "미니게임 천국에 온걸 환영합니다." << endl;
    while (true)
    {
        cout << endl;
        cout << "원하는 항목을 선택하세요. (1. 게임 시작 2. 게임 설명 3. 점수 확인 4. 게임 종료) ";
        cin >> user_input;
        cout << endl;
        if (!IsNumber(user_input)) // 입력받은 값이 숫자가 아니면 다시 입력받음
        {
            continue;
        }

        if (!IsValidNumber(stoi(user_input))) // 입력받은 값이 1,2,3인지 확인
        {
            cout << "유효하지 않은 숫자입니다." << endl;
            continue;
        }

        choice = stoi(user_input);

        switch (choice)
        {
        case 1:
        { // 게임 선택
            SelectGame();
            break;
        }
        case 2:
        { // 게임 설명
            GetInstruction();
            break;
        }
        case 3:
        { // 점수, 보너스 확인
            ShowScore();
            break;
        }
        case 4:
        { // 프로그램 종료
            cout << "프로그램을 종료합니다." << endl;
            return;
        }
        }
    }
}