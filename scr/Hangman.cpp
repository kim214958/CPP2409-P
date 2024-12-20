#include "Hangman.h"

void HM::SetInstruction()
{
    cout << "단어 맞추기 게임을 실행합니다." << endl;
    cout << "주제를 선택하면 주제에 맞는 무작위 단어를 물어봅니다." << endl;
    cout << "단어에 들어가는 알파벳을 맞추면 해당 알파벳이 표시됩니다." << endl;
    cout << "알파벳을 못 맞추면 기회가 1 줄어듭니다." << endl;
    cout << "기본으로 제공하는 기회는 10번이고, 보너스를 사용하면 13번 제공합니다." << endl;
}; // 게임 설명 오버라이딩

// 텍스트 파일의 단어를 벡터에 담는 함수
void HM::LoadWords(vector<string> &word_list, string file_name)
{
    ifstream file(file_name); // 파일을 읽어옴
    string word;              // 텍스트에 담긴 단어들
    if (file.is_open())       // 파일을 읽는 동안
    {
        while (getline(file, word)) // 파일에 담겨있는 단어들에 대해서
        {
            word_list.push_back(word); // 원본 벡터에 단어 추가
        }
        file.close(); // 파일 읽기 종료
    }
}

// 단어를 추출한 벡터로부터 랜덤한 단어를 선택하는 함수
void HM::SetAnswer(vector<string> &word_list)
{
    answer = new string(word_list[rand() % word_list.size()]); // 정답이 vector 내의 무작위 단어로 선택된다.
    hidden_answer = new string(answer->length(), '_');         // 정답 string의 길이와 같은 숨겨진 답을 생성한다.
}

// 현재 내가 맞춘 문자를 보여주는 함수
void HM::ShowCharacter()
{
    for (char &a : *hidden_answer) // 숨겨진 답의 각 문자에 대해서
    {
        cout << a; // 문자를 출력한다.
    }
    cout << endl;
}

// 단어의 문자를 추측하는 함수
void HM::CheckAnswer()
{
    char guess;        // 추측한 단어의 문자
    bool find = false; // 추측한 문자의 존재 여부 (초기화)
    while (true)
    {
        ShowCharacter(); // 지금까지 맞춘 문자들을 표시

        string input; // 사용자의 입력 (string)
        cout << "알파벳을 입력하세요. (남은 기회: " << chance << "번) : ";
        cin >> input;

        if (input.length() != 1) // 문자를 하나 이상 입력했을 때 다시 입력받음
        {
            cout << "하나의 문자만 입력하세요" << endl;
            continue;
        }

        guess = input[0]; // 추측한 문자 (char)

        if (!IsAlphabet(guess)) // 문자가 알파벳이 아니면 다시 입력받음
        {
            cout << "잘못된 입력입니다!" << endl;
            continue;
        }

        guess = tolower(guess); // 대문자를 소문자로 변환 (문자의 일관성 확보)

        for (int i = 0; i < answer->length(); i++) // 정답의 문자열에 대해서
        {
            if ((*answer)[i] == guess) // 정답의 문자열 중 추측한 문자가 존재하면
            {
                (*hidden_answer)[i] = guess; // 숨겨진 정답에 추측한 문자를 표시
                find = true;                 // 추측한 문자가 존재함
            }
        }

        if (!find) // 추측한 문자가 틀렸으면
        {
            cout << "틀렸습니다." << endl;
            --chance; // 기회를 1 차감
        }

        cout << endl; // 줄바꿈

        return;
    }
}

// 승리 여부를 확인하는 함수
bool HM::CheckWin()
{
    for (char i : *hidden_answer) // 숨겨진 정답의 문자에 대해서
    {
        if (i == '_') // 숨겨진 문자('_')가 있으면 승리 X
        {
            return false;
        }
    }
    return true; // 숨겨진 문자('_')가 없으면, 즉 정답의 문자를 모두 맞추면 승리
}

// 사용자로부터 주제를 입력받는 함수
int HM::GetUserInput()
{
    while (true)
    {
        cout << "주제를 선택하세요 (1. 동물, 2. 과일, 3. 나라)" << endl;
        cin >> user_input; // 사용자로부터 입력을 받음(string)

        if (!IsNumber(user_input)) // 입력받은 값이 숫자가 아니면 다시 입력받음
        {
            continue;
        }

        if (!IsValidNumber(stoi(user_input))) // 입력받은 값이 1,2,3인지 확인
        {
            cout << "유효하지 않은 숫자입니다." << endl;
            continue;
        }

        return stoi(user_input); // 입력받은 값을 int형으로 반환
    }
}
// 주제, 단어를 결정하는 함수
void HM::SelectQuiz(int subject_num)
{
    switch (subject_num) // 사용자의 선택에 따라서 주제, 단어가 선택됨
    {
    case 1:
    {
        LoadWords(word_list, "animals.txt"); // 동물 텍스트파일 읽음
        SetAnswer(word_list);                // 랜덤 동물 단어 선택
        break;
    }
    case 2:
    {
        LoadWords(word_list, "fruits.txt"); // 과일 텍스트파일 읽음
        SetAnswer(word_list);               // 랜덤 과일 단어 선택
        break;
    }
    case 3:
    {
        LoadWords(word_list, "countries.txt"); // 나라 텍스트파일 읽음
        SetAnswer(word_list);                  // 랜덤 나라 단어 선택
        break;
    }
    }
}

// hangman을 플레이하는 함수
int HM::PlayHM()
{
    // 보너스 객체 생성 & 보너스 사용여부 확인
    Bonus hm_bonus;
    is_bonus_used = hm_bonus.UseBonus();

    // 정답, 숨겨진 정답 초기화
    answer = nullptr;
    hidden_answer = nullptr;

    chance = 10;                  // 기회는 10번 설정
    srand(time(0));               // 컴퓨터의 무작위 선택을 위한 난수 생성
    subject_num = GetUserInput(); // 사용자로부터 주제를 입력 받음
    SelectQuiz(subject_num);      // 주제에 맞는 랜덤 단어 선택

    if (is_bonus_used == true)
    {
        chance = 13; // 보너스 사용시 기회를 13번으로 바꿈
    }

    // 기회가 1 이상이면
    while (chance > 0)
    {
        CheckAnswer(); // 단어 추측 함수 호출

        if (CheckWin()) // 기화가 1 이상이고, 단어 추측에 성공하면
        {
            cout << "정답 " << *answer << "을(를) 맞췄습니다!" << endl;
            give_score = true; // 점수 부여
            break;
        }
    }

    // 기회를 다 소진했으면
    if (chance == 0)
    {
        cout << "기회를 모두 사용했습니다. 정답은 " << *answer << "입니다." << endl;
        give_score = false; // 점수 부여 X
    }

    // 승리시 점수 부여
    if (give_score == true)
    {
        hm_bonus.SetScore(hm_bonus.GetScore() + 100); // 점수 +100, 누적점수 갱신
        hm_bonus.SetBonus(hm_bonus.GetScore());       // 남은 보너스 갱신
    }

    // 포인터 초기화
    delete answer;
    delete hidden_answer;
    answer = nullptr;
    hidden_answer = nullptr;

    return 0;
}
