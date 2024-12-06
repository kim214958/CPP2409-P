#ifndef SN_H
#define SN_H

#include <iostream>
#include <vector>
#include <ctime>
#define NOMINMAX            // Windows.h에서 min/max 매크로 비활성화
#define WIN32_LEAN_AND_MEAN // Windows.h에서 불필요한 기능 제외
#include <Windows.h>        // sleep 사용을 위해
#include <sstream>
#include "Check_input.h"
#include "Menu.h"

class SN : public CheckInput
{
public:
    void SetInstruction() override; // 게임 설명 오버라이딩
    int array_length;               // 문제 배열의 길이
    vector<int> random_numbers;
    vector<int> user_answer;
    bool IsValidNumber(int choice) override;                              // CheckInput 클래스의 IsValidNumber 함수 오버라이드
    void SetArrayLength(int &array_length);                               // 문제 벡터의 길이 (문제의 수)를 설정하는 함수
    void MakeRandomNumber(vector<int> &random_numbers);                   // 문제 벡터를 설정하는 함수
    void ShowRandomNumbers(vector<int> &random_numbers);                  // 문제 벡터를 출력하는 함수
    void GetUserAnswer(vector<int> &user_answer);                         // 사용자로부터 입력을 받아 사용자 정답 벡터를 설정하는 함수
    bool CheckWin(vector<int> &user_answer, vector<int> &random_numbers); // 게임 결과를 확인하는 함수
    void Merge(vector<int> &arr, int left, int mid, int right);           // 배열의 요소를 크기순으로 sorting, merge
    void MergeSort(vector<int> &arr, int left, int right);                // mergesort 함수
    void PlaySN();
};

#endif