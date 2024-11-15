#include "Mukchippa.h"
#include "Bonus.h"
#include "tictactoe.h"
#include "Hangman.h"

// 게임을 확인하는 메인(임시)
int main(){
    MCP mcpGame; // 묵찌빠 객체
    Bonus gameBonus; // 보너스 객체
    TTT tictactoeGame; // 틱택토 객체

    cout<<"초기 점수 : "<<gameBonus.getScore()<<endl;
    cout<<"초기 보너스 : "<<gameBonus.getBonus()<<endl;
    gameBonus.setScore(gameBonus.getScore()+400); // 점수 설정
    gameBonus.setBonus(gameBonus.getScore()); // 남은 보너스 갱신
    cout<<"설정된 점수 : "<<gameBonus.getScore()<<endl;
    cout<<"설정된 보너스 : "<<gameBonus.getBonus()<<endl;
    
    mcpGame.playMCP(); // 묵찌빠 실행
 
    tictactoeGame.playTTT(); // 틱택토 실행

    cout<<"최종 점수 : "<<gameBonus.getScore()<<endl;
    cout<<"최종 남은 보너스 : "<<gameBonus.getBonus()<<endl;
    cout<<"사용된 보너스 : "<<gameBonus.getUsedBonus()<<endl;

}