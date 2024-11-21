#include "Check_Input.h"

bool CheckInput::IsNumber(string &choice){ // 사용자의 입력이 숫자인지 확인하는 함수
    // 사용자의 문자열의 문자에 대해서
    for (char c : choice) {
        if (!isdigit(c)) return false; // 문자중 숫자가 아닌게 있으면 false를 반환
    }
    try { // stoi 예외처리를 위한 try-catch
			// 사용자의 String 입력을 int로 캐스팅한 값을 저장
            int int_choice1 = std::stoi(choice);
        }
	catch (const std::out_of_range& e) { // 너무 큰 숫자를 입력했을 때
            cout << "입력한 숫자가 너무 큽니다. 다시 입력하세요." << endl;
			return false; // false를 반환
        }
    return true; // 문자가 전부 숫자면 true를 반환
}

bool CheckInput::IsNumber(string &choice1, string &choice2){ // 사용자의 입력이 숫자인지 확인하는 함수
    try { // stoi 예외처리를 위한 try-catch
			// 사용자의 String 입력을 int로 캐스팅한 값을 저장
            int int_choice1 = std::stoi(choice1);
            int int_choice2 = std::stoi(choice2);
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

bool CheckInput::IsAlphabet(char choice) { // 사용자의 입력이 알파벳인지 확인하는 함수
    if(isalpha(choice)){ // 입력이 알파벳이면 true를 반환    
        return true;         
    }
    else{
        return false;                  
    }
}