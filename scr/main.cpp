#include "Mukchippa.h"
#include "Bonus.h"
#include "tictactoe.h"

// 게임을 확인하는 메인(임시)
int main(){
    MCP mcpGame;
    Bonus a;
    TTT tictactoeGame;
    a.setScore(0);
    a.setBonus(a.getScore());
    cout<<a.getScore()<<endl;
    cout<<a.getBonus()<<endl;
    a.setScore(a.getScore()+200);
    a.setBonus(a.getScore());
    cout<<a.getScore()<<endl;
    cout<<a.getBonus()<<endl;
    
   // mcpGame.playMCP();
 
    tictactoeGame.playTTT();

    cout<<a.getScore()<<endl;
    cout<<a.getBonus()<<endl;
    cout<<a.getUsedBonus()<<endl;
    
}