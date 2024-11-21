#include "Mukchippa.h"
#include "Bonus.h"
#include "tictactoe.h"
#include "Hangman.h"

// 게임을 확인하는 메인(임시)
int main(){
    MCP mcp_game; // 묵찌빠 객체
    Bonus game_bonus; // 보너스 객체
    TTT tictactoe_game; // 틱택토 객체
    HM hangman_game; // 행맨 객체

    cout<<"초기 점수 : "<<game_bonus.getScore()<<endl;
    cout<<"초기 보너스 : "<<game_bonus.getBonus()<<endl;
    game_bonus.setScore(game_bonus.getScore()+400); // 점수 설정
    game_bonus.setBonus(game_bonus.getScore()); // 남은 보너스 갱신
    cout<<"설정된 점수 : "<<game_bonus.getScore()<<endl;
    cout<<"설정된 보너스 : "<<game_bonus.getBonus()<<endl;
    
   // mcp_game.playMCP(); // 묵찌빠 실행
 

    //hangman_game.PlayHM();
    tictactoe_game.PlayTTT(); // 틱택토 실행

    cout<<"최종 점수 : "<<game_bonus.getScore()<<endl;
    cout<<"최종 남은 보너스 : "<<game_bonus.getBonus()<<endl;
    cout<<"사용된 보너스 : "<<game_bonus.getUsedBonus()<<endl;

}