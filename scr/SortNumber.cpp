#include "SortNumber.h"
#include "Bonus.h"

bool SN::IsValidNumber(int choice) // 부모 클래스의 유효한 숫자 검사 함수를 오버라이딩
{
    return choice == 5 || choice == 6 || choice == 7 || choice == 8 || choice == 9 || choice == 10;
}

void SN::SetInstruction()
{
    cout << "제한시간 내에 숫자를 크기순으로 정렬하는 게임입니다." << endl;
    cout << "맨 처음 문제의 수를 결정합니다." << endl;
    cout << "정한 문제의 수 만큼 무작위 숫자가 제시됩니다." << endl;
    cout << "제한시간 내에 숫자를 크기순으로 정렬하세요. 주어진 시간은 문제*3초 입니다." <<endl;
    cout << "보너스를 사용하면 제한시간이 5초 늘어납니다." <<endl;
} // 게임 설명 오버라이딩

// 문제 벡터의 길이 (문제의 수)를 설정하는 함수
void SN::SetArrayLength(int &array_length)
{
    while (true)
    {
        cout << "문제의 수를 결정하세요 (5개 ~ 10개)" << endl;
        cin >> user_input; // 사용자의 입력 (string)

        if (!IsNumber(user_input)) // 사용자의 입력이 숫자인지 확인
        {
            continue;
        }
        if (!IsValidNumber(stoi(user_input))) // 유효한 숫자인지 확인
        {
            cout << "유효하지 않은 숫자입니다." << endl;
            continue;
        }
        array_length = stoi(user_input); // int로 반환
        break;
    }
}

// 문제 벡터를 설정하는 함수
void SN::MakeRandomNumber(vector<int> &random_numbers)
{
    for (int i = 0; i < array_length; ++i) // 설정한 문제 배열의 길이(문제의 수) 만큼 반복
    {
        int randomNum = (rand() % 201) - 100; // -100부터 100까지의 무작위 정수 생성
        random_numbers.push_back(randomNum);  // 문제 벡터에 추가
    }
}

// 문제 벡터를 출력하는 함수
void SN::ShowRandomNumbers(vector<int> &random_numbers)
{
    for (int number : random_numbers) // 문제 벡터의 원소를 출력
    {
        cout << number << " ";
    }
    // 줄바꿈
    cout << endl
         << endl;
}

// 사용자로부터 입력을 받아 사용자 정답 벡터를 설정하는 함수
void SN::GetUserAnswer(vector<int> &user_answer)
{
    cout << "정답을 입력하세요 (띄어쓰기로 구분) :" << endl;
    while (true)
    {
        string user_input;           // 사용자의 입력 문자열 (유효성 체크 X)
        string temp;                 // 사용자의 입력 문자열에 포함된 단어
        getline(cin, user_input);    // 사용자로부터 한줄을 입력 받음, user_input에 저장
        stringstream ss(user_input); // 사용자의 입력을 stringstream으로 저장
        bool is_valid = true;        // 잘못된 입력을 확인하는 변수

        user_answer.clear();           // 사용자의 정답을 담는 벡터 초기화
        while (getline(ss, temp, ' ')) // ss스트림에서 ' '를 구분하여 문자열 temp를 읽어냄
        {
            // 입력받은 각 숫자에 대해 유효성 검사
            if (IsNumber(temp))
            {
                user_answer.push_back(stoi(temp)); // 숫자이면 사용자 정답 벡터에 추가
            }
            else
            { // 숫자가 아닌 입력을 확인하면 반복문 break
                is_valid = false;
                break;
            }
        }
        if (!is_valid) // 잘못된 입력이 있었다면 루프 재시작
        {
            continue;
        }

        if (user_answer.size() == 0) // 유저가 입력이 공란이면 다시 입력받음
        {
            continue;
        }

        // 유저의 정답 벡터의 길이와 문제 벡터의 길이가 다르면 다시 입력받음
        if (user_answer.size() != random_numbers.size())
        {
            cout << "문제의 갯수와 정답의 갯수가 다릅니다. 다시 입력하세요." << endl;
            continue;
        }

        break; // 모든 유효성 검사를 통과하면 종료
    }
}

// 게임 결과를 확인하는 함수
bool SN::CheckWin(vector<int> &user_answer, vector<int> &random_numbers)
{
    for (int i = 0; i < user_answer.size() - 1; i++)
    {
        if (user_answer[i] != random_numbers[i]) // 사용자의 배열 순서와 정답의 배열 순서가 다르면 패배
        {
            return false;
        }
    }
    return true; // 사용자의 배열 순서와 정답의 배열 순서가 같으면 승리
}

// 배열의 요소를 크기순으로 sorting, merge
void SN::Merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 양쪽으로 나눈 부분 벡터들
    vector<int> left_array(n1), right_array(n2);

    // 부분 벡터 복사
    for (int i = 0; i < n1; i++)
        left_array[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        right_array[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    // 병합부분
    while (i < n1 && j < n2)
    { // 크기순으로 병합
        if (left_array[i] <= right_array[j])
        {
            arr[k++] = left_array[i++];
        }
        else
        {
            arr[k++] = right_array[j++];
        }
    }

    // 남은 요소 추가 (sorting이 되면 왼쪽이 더 작고 오른쪽이 더 크다)
    while (i < n1)
        arr[k++] = left_array[i++];
    while (j < n2)
        arr[k++] = right_array[j++];
}

// Merge Sort 함수: 재귀적으로 배열을 나누고 병합
void SN::MergeSort(vector<int> &random_numbers, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2; // 가운데를 중심으로 나눔

        // 나눈 벡터를 재귀적으로 호출
        MergeSort(random_numbers, left, mid);
        MergeSort(random_numbers, mid + 1, right);

        // 쪼갠 벡터를 크기순으로 sorting & 병합
        Merge(random_numbers, left, mid, right);
    }
}

void SN::PlaySN()
{
    // 보너스 객체 생성 & 보너스 사용 여부 확인
    Bonus sn_bonus;
    is_bonus_used = sn_bonus.useBonus();
    // 보너스를 사용하면 보너스 타임 5초 추가
    int bonus_time = 0;
    if (is_bonus_used)
    {
        bonus_time = 5;
    }

    srand(time(0));                   // 난수 생성성
    array_length = 0;                 // 문제 배열의 길이 초기화
    SetArrayLength(array_length);     // 문재 배열 길이 설정
    MakeRandomNumber(random_numbers); // 배열 길이 만큼 무작위 값을 가진 문제 벡터 생성

    // 3초 후 정답 문제 공개
    for (int i = 3; i > 0; --i)
    {
        cout << i << " 초 후에 문제가 나옵니다!" << endl;
        Sleep(1000);
    };

    cout << endl
         << "주어진 시간은 " << array_length * 3 + bonus_time << "초 입니다." << endl;

    // 설정한 문제 벡터 공개
    ShowRandomNumbers(random_numbers);

    time_t start = time(0);     // 시간 측정 시작
    GetUserAnswer(user_answer); // 사용자로부터 답을 입력받음
    time_t end = time(0);       // 시간 측정 종료

    // 걸린 시간 계산 (초 단위)
    double duration = difftime(end, start);

    // 문제 벡터를 megesort를 통해 크기순으로 재배치
    MergeSort(random_numbers, 0, random_numbers.size() - 1);
    // sorting한 문제 벡터 출력
    ShowRandomNumbers(random_numbers);

    bool is_win = CheckWin(user_answer, random_numbers);
    // 성공 여부 확인
    if (is_win && duration <= array_length * 3 + bonus_time) // 성공
    {
        cout << "정답입니다. " << "걸린 시간: " << duration << endl;
        give_score = true;
    }
    else if (is_win && duration > array_length * 3 + bonus_time) // 정답 but 시간 초과
    {
        cout << "시간이 초과되었습니다. " << "걸린 시간: " << duration << endl;
        give_score = false;
    }
    else // 오답
    {
        cout << "실패했습니다." << "걸린 시간: " << duration << endl;
        give_score = false;
    }

    // 승리시 점수 부여
    if (give_score == true)
    {
        sn_bonus.setScore(sn_bonus.getScore() + 100); // 점수 +100, 누적점수 갱신
        sn_bonus.setBonus(sn_bonus.getScore());       // 남은 보너스 갱신
    }
}