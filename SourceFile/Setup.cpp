#include<Data.hpp>

void Open(){
    SDL_Init((SDL_INIT_EVERYTHING));
    TTF_Init();
}

void SetMap(){
    rectBackgroud.h = Window_Height;
    rectBackgroud.w = Window_Width;
    rectBackgroud.x = 0;
    rectBackgroud.y = 0;

    backgroud.Set_Surface(IMG_Load("E:/Dev_Game/Game/Map/Map1/backgroud.jpg"));
    backgroud.Set_Rect(rectBackgroud);
}

void SetPlayer(){
    player.Set_Status(LIVE);
    player.Set_Run(false);
    player.Set_Jump(false);
    player.Set_Direction(RIGHT);

    rectPlayer[0].h = Player_Height;    
    rectPlayer[0].w = Player_Width;
    rectPlayer[0].x = 0;
    rectPlayer[0].y = 0;

    rectPlayer[1].h = Player_Height;    
    rectPlayer[1].w = Player_Width;
    rectPlayer[1].x = 65;
    rectPlayer[1].y = 0;

    rectPlayer_run[0].h = Player_Height;
    rectPlayer_run[0].w = Player_Width;
    rectPlayer_run[0].x = 0;
    rectPlayer_run[0].y = 65;

    rectPlayer_run[1].h = Player_Height;
    rectPlayer_run[1].w = Player_Width;
    rectPlayer_run[1].x = 65;
    rectPlayer_run[1].y = 65;

    rectPlayer_run[2].h = Player_Height;
    rectPlayer_run[2].w = Player_Width;
    rectPlayer_run[2].x = 129;
    rectPlayer_run[2].y = 69;

    rectPlayer_run[3].h = Player_Height;
    rectPlayer_run[3].w = Player_Width;
    rectPlayer_run[3].x = 197;
    rectPlayer_run[3].y = 69;

    rectPlayer_jump[0].h = Player_Height;
    rectPlayer_jump[0].w = Player_Width;
    rectPlayer_jump[0].x = 0;
    rectPlayer_jump[0].y = 129;

    rectPlayer_jump[1].h = Player_Height;
    rectPlayer_jump[1].w = Player_Width;
    rectPlayer_jump[1].x = 0;
    rectPlayer_jump[1].y = 193;

    rectRenderer.h = Player_Height;
    rectRenderer.w = Player_Width;
    rectRenderer.x = 50;
    rectRenderer.y = 100;
    
    rectTemp = rectPlayer[0];
    player.Set_Surface(IMG_Load("E:/Dev_Game/Game/Player/Player.png"));
    player.Set_Rect(rectTemp);
    //player.Set_Color_Key(g_ColorKeyR, g_ColorKeyG, g_ColorKeyB);
}

bool Create_Window(){
    window = SDL_CreateWindow("Game",
                                Window_PositionX,
                                Window_PositionY,
                                Window_Width,
                                Window_Height,
                                SDL_WINDOW_SHOWN);
    if(window == nullptr)
        return false;
    return true;
}

bool Create_Renderer(){
    renderer = SDL_CreateRenderer(window,
                                    -1,
                                    SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr)
        return false;
    return true;
}

void SetGame(){
    timer.Set_FPS(60);
    game.Set_Status(RUN);
    game.Set_Ground(390);
    game.Set_Gravity(5);
    fps.Set_Value(0);
    fps.ValueFromText();
    fps.Set_Color(255, 255, 255, 255);
    if(Create_Window() && Create_Renderer())
        std::cout << "Game ready" << std::endl;
}


void Close(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}
