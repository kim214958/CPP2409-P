#include "Mukchippa.h"
#include "Bonus.h"


int main(){
    MCP mcpGame;
    Bonus a;
    a.setScore(300);
    a.setBonus(a.getScore());
    cout<<a.getScore()<<endl;
    cout<<a.getBonus()<<endl;
    a.setScore(a.getScore()+200);
    a.setBonus(a.getScore());
    cout<<a.getScore()<<endl;
    cout<<a.getBonus()<<endl;
    mcpGame.playMCP();
    cout<<a.getScore()<<endl;
    cout<<a.getBonus()<<endl;
    cout<<a.getUsedBonus()<<endl;
    
}