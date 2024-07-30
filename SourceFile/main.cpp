//Makefile : make build
//Commandline : g++ Main.cpp -o Main.exe -IE:/Dev_Game/Game/HeaderFile -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
#include <Data.hpp>
#include "Setup.cpp"
#include "Object.cpp"

int main(int argc, char *argv[]){
    Open();
    SetGame();
    SetMap();
    SetPlayer();
    while(game.Get_Status()){
        timer.Up_Count(); 
        timer.Set_Firt_Time(SDL_GetTicks());

        game.Handle_Input();
        game.Load_Frame();

        timer.Set_Last_Time(SDL_GetTicks());
        timer.Delay_Frame();

        if(timer.Get_Count() >= 10){
            fps.Set_Value((int)(1000/(SDL_GetTicks() - timer.Get_Firt_Time())));
            fps.ValueFromText();
            timer.Reset_Count();
            player.Set_Stand(!player.Get_Stand());
        }
    }
    Close();
    return 0;
}