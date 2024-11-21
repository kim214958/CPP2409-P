#ifndef HM_H
#define HM_H

#include <iostream>
#include <fstream> // 파일 입력 스트림 라이브러리
#include <vector>
#include <string>
#include <ctime>
#include "Check_input.h"
using namespace std;

class HM : public CheckInput
{
public:
    vector<string> words; // 텍스트파일에서 읽어온 단어들의 집합
    string *answer; // 정답
    string *hidden_answer; // 숨겨진 정답
    int subject_num; // 선택한 주제의 번호
    string subject; // 퀴즈 주제
    int chance; // 단어를 추측할 수 있는 기회
    bool is_bonus_used; // 보너스가 사용되었는지 확인하는 변수
    bool give_score;    // 점수 부여 여부를 결정하는 함수

    void LoadWords(vector<string> &wordList, string fileName); // 텍스트 파일의 단어를 벡터에 담는 함수
    void SelectQuiz(int subject); // 주제, 단어를 선택하는 함수
    void SetAnswer(vector<string> &wordList); // 단어를 추출한 벡터로부터 랜덤한 단어를 선택하는 함수
    void ShowCharacter(); // 현재 내가 맞춘 문자를 보여주는 함수
    void CheckAnswer(); // 단어의 문자를 추측하는 함수
    int PlayHM(); // hangman을 플레이하는 함수
    int SelectSub(); // 주제를 선택하는 함수
    bool IsWin(); // 승리 여부를 확인하는 함수
};

#endif