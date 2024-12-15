#include "Check_Input.h"

// 사용자의 입력이 숫자인지 확인하는 함수
bool CheckInput::IsNumber(string &choice)
{ // 정수인지 확인 (소숫점 존재 여부 확인)
    if (choice.find('.') != string::npos)
    {
        cout << "입력한 값이 정수가 아닙니다. 다시 입력하세요." << endl;
        return false;
    }

    // 문자열이 비었는지 확인
    if (choice.empty())
    {
        cout << "입력한 값이 비어 있습니다. 다시 입력하세요." << endl;
        return false;
    }

    // 모든 문자가 숫자인지 확인 (첫 번째 문자는 음수 기호 '-' 가능)
    for (size_t i = 0; i < choice.size(); ++i)
    {
        if (i == 0 && choice[i] == '-')
        {
            continue; // 첫 번째 문자가 '-'이면 음수로 간주하고 계속 진행
        }

        if (!isdigit(choice[i]))
        {
            cout << "입력한 값이 숫자가 아닙니다. 다시 입력하세요." << endl;
            return false;
        }
    }
    try
    { // stoi 예외처리를 위한 try-catch
        // 사용자의 String 입력을 int로 캐스팅한 값을 저장
        int int_choice1 = std::stoi(choice);
    }
    catch (const std::out_of_range &e)
    { // 너무 큰 숫자를 입력했을 때
        cout << "입력한 숫자가 너무 큽니다. 다시 입력하세요." << endl;
        return false; // false를 반환
    }
    return true; // 문자가 전부 숫자면 true를 반환
}

// 사용자의 입력 2개가 숫자인지 확인하는 함수
bool CheckInput::IsNumber(string &choice1, string &choice2)
{
    if (IsNumber(choice1) && IsNumber(choice2))
        return true;
    else
        return false;
}

bool CheckInput::IsAlphabet(char choice)
{ // 사용자의 입력이 알파벳인지 확인하는 함수
    // 입력이 알파벳이면 true를 반환
    if (isalpha(choice))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CheckInput::IsValidNumber(int choice)
{ // 사용자의 입력이 유효한 숫자인지 확인하는 함수
    // 사용자가 1,2,3 중 하나를 입력했으면 true를, 아니면 false를 반환
    return choice == 1 || choice == 2 || choice == 3;
}

// 음수, 양수를 판단하는 함수
bool CheckInput::IsNegativeNumber(int number)
{
    if (number < 0)
    {
        cout << "입력한 숫자가 음수입니다." << endl;
        return false;
    }

    else
        return true;
}