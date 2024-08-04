#include<Data.hpp>

void Open(){
    SDL_Init((SDL_INIT_EVERYTHING));
    TTF_Init();
}

void SetMap(){
    rectBackgroud = {0, 0, Window_Width, Window_Height};
    backgroud.Set_Surface(IMG_Load("Map/Map1/backgroud.jpg"));
    backgroud.Set_Rect(rectBackgroud);
}

void SetPlayer(){
    player.Set_Status(LIVE);
    player.Set_Run(false);
    player.Set_Jump(false);
    player.Set_Direction(RIGHT);

    rectPlayer[0] = {0, 0, Player_Width, Player_Height};
    rectPlayer[1] = {65, 0, Player_Width, Player_Height};

    rectPlayer_run[0] = {0, 65, Player_Width, Player_Height};
    rectPlayer_run[1] = {65, 65, Player_Width, Player_Height};
    rectPlayer_run[2] = {129, 69, Player_Width, Player_Height};
    rectPlayer_run[3] = {197, 69, Player_Width, Player_Height};

    rectPlayer_jump[0] = {0, 129, Player_Width, Player_Height};
    rectPlayer_jump[1] = {0, 193, Player_Width, Player_Height};

    rectRenderer = {50, 100, Player_Width, Player_Height};
    
    rectTemp = rectPlayer[0];
    player.Set_Surface(IMG_Load("Player/Player.png"));
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
    timer.Set_FPS(45);
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
