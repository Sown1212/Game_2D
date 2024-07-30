//Makefile : make build
//Commandline : g++ Main.cpp -o Main.exe -IE:/Dev_Game/Game/HeaderFile -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
#include <Data.hpp>
#include "Setup.cpp"
#include "Object.cpp"
int i = 0;

int main(int argc, char *argv[]){
    Open();
    SetGame();
    SetMap();
    SetPlayer();
    const char* gifPath = "E:/Dev_Game/Game/SourceFile/Gid.gif";
    SDL_RWops* rwops = SDL_RWFromFile(gifPath, "rb");
    IMG_Animation* animation = IMG_LoadGIFAnimation_RW(rwops);

    while(game.Get_Status()){
        timer.Up_Count(); 
        timer.Set_Firt_Time(SDL_GetTicks());

        game.Handle_Input();

        SDL_Surface* frame = animation->frames[i];
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, frame);
        if(texture == nullptr)
            std::cout << "null_texture" << std::endl;
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_DestroyTexture(texture);
        i++;
        if(i >= 112)
            i= 0;

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
    IMG_FreeAnimation(animation);
    Close();
    return 0;
}