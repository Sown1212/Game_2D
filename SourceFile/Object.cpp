#include<Object.hpp>

Base_Object::Base_Object(){
    base_surface = NULL;
    base_rect = {0, 0, 0, 0};
}

void Base_Object::Set_Surface(SDL_Surface *p_surface){
    this->base_surface = p_surface;
}

void Base_Object::Set_Rect(SDL_Rect rect){
    this->base_rect = rect;
}

SDL_Surface *Base_Object::Get_Surface(){
    return base_surface;
}

SDL_Rect Base_Object::Get_Rect(){
    return base_rect;
}

void Base_Object::Set_Color_Key(int R, int G, int B){
    SDL_SetColorKey(Get_Surface(), SDL_TRUE, SDL_MapRGB(Get_Surface()->format, R, G, B));
}

bool Base_Object::Load_Image(SDL_Rect texture_rect, SDL_Rect render_rect){
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, base_surface);
    if(texture == nullptr)
        return false;
    SDL_RenderCopy(renderer, texture, &texture_rect, &render_rect);
    if(renderer == nullptr)
        return false;
    SDL_DestroyTexture(texture);
    return true;
}

bool Base_Object::Load_ImageEx(SDL_Rect texture_rect, SDL_Rect render_rect, double angle, SDL_Point *center, SDL_RendererFlip flip){
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, base_surface);
    if(texture == nullptr)
        return false;
    SDL_RenderCopyEx(renderer, texture, &texture_rect, &render_rect, angle, center, flip);
    if(renderer == nullptr)
        return false;
    SDL_DestroyTexture(texture);
    return true;
}

Base_Object::~Base_Object(){
    SDL_FreeSurface(base_surface);
    base_surface = NULL;
    base_rect = {0, 0, 0, 0};
}

/// @brief ////////////////////////////////////////////////////////////////////////////////

void Main_Object::Set_Stand(bool stand){
    this->stand = stand;
}
void Main_Object::Set_Status(bool status){
    this->status = status;
}
void Main_Object::Set_Direction(bool direction){
    this->direction = direction;
}
void Main_Object::Set_Run(bool run){
    this->run = run;
}
void Main_Object::Set_Jump(bool jump){
    this->jump = jump;
}
void Main_Object::Set_Chat(bool chat){
    this->chat = chat;
}
bool Main_Object::Get_Stand(){
    return stand;
}
bool Main_Object::Get_Status(){
    return status;
}
bool Main_Object::Get_Direction(){
    return direction;
}
bool Main_Object::Get_Run(){
    return run;
}
bool Main_Object::Get_Jump(){
    return jump;
}
bool Main_Object::Get_Chat(){
    return chat;
}

void Main_Object::Stand(){
    if(player.Get_Stand())
        rectTemp = rectPlayer[0];
    else    
        rectTemp = rectPlayer[1];
}

void Main_Object::Run(){
    if(rectRenderer.y == game.Get_Ground())
        rectTemp = rectPlayer_run[cnt];
    if(cnt >= 3) cnt = 0;
    cnt++;
    if(player.Get_Direction())
        rectRenderer.x+=5;
    else
        rectRenderer.x-=5;
}

void Main_Object::Jump(){
    rectTemp = rectPlayer_jump[0];
    rectRenderer.y -= 10;
    if(rectRenderer.y <= game.Get_Ground() - MAX_JUMP){
        player.Set_Jump(false);
        rectTemp = rectPlayer_jump[1];
    }
}

void Main_Object::Handle_Action(){
    if(player.Get_Status()){
        if(rectRenderer.y < game.Get_Ground())
            rectRenderer.y += game.Get_Gravity();
        if(player.Get_Run())
            player.Run();
        if(player.Get_Jump())
            player.Jump();
        if(player.Get_Jump() == 0 && player.Get_Run() == 0 && rectRenderer.y == game.Get_Ground())
            player.Stand();
    }
}

/// @brief ////////////////////////////////////////////////////////////////////////////////

void Time::Set_FPS(uint8_t fps){
    this->fps = fps;
}
void Time::Set_Firt_Time(uint32_t firt_time){
    this->firt_time = firt_time;
}
void Time::Set_Last_Time(uint32_t last_time){
    this->last_time = last_time;
}
void Time::Delay_Frame(){
    if(last_time - firt_time < 1000/fps)
        SDL_Delay( (1000/fps) - (SDL_GetTicks() - firt_time));
}
uint8_t Time::Get_FPS(){
    return fps;
}
Uint32 Time::Get_Firt_Time(){
    return firt_time;
}
Uint32 Time::Get_Last_Time(){
    return last_time;
}

void Time::Up_Count(){
    count++;
}

void Time::Reset_Count(){
    this->count = 0;
}

uint8_t Time::Get_Count(){
    return count;
}

/// @brief ////////////////////////////////////////////////////////////////////////////////

void Game::Menu(){

}

void Game::Set_Ground(uint16_t ground){
    this->ground = ground;
}

void Game::Set_Gravity(float gravity){
    this->gravity = gravity;
}

void Game::Set_Status(bool play){
    this->play = play;
}

bool Game::Get_Status(){
    return play;
}

uint16_t Game::Get_Ground(){
    return ground;
}

int Game::Get_Gravity(){
    return gravity;
}

void Game::Handle_Input(){
    while( SDL_PollEvent( &event ) ){
        if(event.type == SDL_QUIT){
            game.Set_Status(PAUSE);
            return;
        }
        if(event.type == SDL_KEYDOWN){
            switch (event.key.keysym.sym){
                case SDLK_d:{
                    player.Set_Direction(RIGHT);
                    player.Set_Run(true);
                    rectRenderer.x+=5;
                    break;
                }
                case SDLK_a:{
                    player.Set_Direction(LEFT);
                    player.Set_Run(true);
                    break;
                }
                case SDLK_SPACE:{
                    if(rectRenderer.y == game.Get_Ground())
                        player.Set_Jump(true);
                    break;
                }
                default:{
                break;
                }
            }
        }
        else if(event.type == SDL_KEYUP){
            if(event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_a)
                player.Set_Run(false);
        }
    }
}

void Game::Load_Frame(){
    player.Handle_Action();
    SDL_Rect recta = {0, 450, Window_Width, Window_Height};
    SDL_Rect rectb = {0, 450, Window_Width, Window_Height};
    backgroud.Load_Image(recta, rectb);
    if( player.Get_Direction() )
       player.Load_Image(rectTemp, rectRenderer);
    else
       player.Load_ImageEx(rectTemp, rectRenderer, 360, NULL, SDL_FLIP_HORIZONTAL);    
    fps.Load_Text();
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}

/// @brief ////////////////////////////////////////////////////////////////////////////////
void Font::Set_Text(char text[30]){
    text = text;
}

void Font::Set_Value(int value){
    this->value = value;
}

void Font::Set_Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a){
    this->color = {r, g, b, a};
}

void Font::ValueFromText(){ 
    sprintf(text, "%d", value);
}

void Font::Load_Text(){
    TTF_Font *font = TTF_OpenFont(path, 16);
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect textRect = {750, 10, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &textRect);

    TTF_CloseFont(font);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}