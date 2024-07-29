#pragma once

#ifndef _BASE_OBJECT_HPP_
#define _BASE_OBJECT_HPP_

#include<Data.hpp>

class Base_Object{
    private:
        SDL_Surface *base_surface;
        SDL_Rect base_rect;
    public:
        Base_Object();
        void Set_Surface(SDL_Surface *p_surface);
        void Set_Rect(SDL_Rect rect);
        SDL_Surface *Get_Surface();
        SDL_Rect Get_Rect();
        void Set_Color_Key(int R, int G, int B);
        bool Load_Image(SDL_Rect texture_rect, SDL_Rect render_rect);
        bool Load_ImageEx(SDL_Rect texture_rect, SDL_Rect render_rect, double angle, SDL_Point *center, SDL_RendererFlip flip);
        ~Base_Object();
};

class Font : public Base_Object{
    private:
        int value;
        char text[30];
        SDL_Color color;
    public:
        void Set_Value(int value);
        void Set_Text(char text[30]);
        void Set_Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
        int Get_Value();
        SDL_Color Get_Color();
        void ValueFromText();
        void Load_Text();
};

class Time : public Base_Object{
    private:
        uint8_t count;
        uint8_t fps;
        Uint32 firt_time;
        Uint32 last_time;
    public:
        void Up_Count();
        void Reset_Count();
        void Delay_Frame();
        void Set_FPS(uint8_t fps);
        void Set_Firt_Time(uint32_t firt_time);
        void Set_Last_Time(uint32_t last_time);
        uint8_t Get_Count();
        uint8_t Get_FPS();
        Uint32 Get_Firt_Time();
        Uint32 Get_Last_Time();
};

class Game : public Base_Object{
    private:
        bool play;
        uint16_t ground;
        int gravity;
    public:
        void Menu();
        void Handle_Input();
        void Set_Status(bool play);
        void Set_Ground(uint16_t ground);
        void Set_Gravity(float gravity);
        bool Get_Status();
        uint16_t Get_Ground();
        int Get_Gravity();
        void Load_Frame();
};

class NPC : public Base_Object{
    private:
    public:
        

};

class Main_Object : public Base_Object{
    private:
        bool status;
        bool stand;
        bool direction;
        bool run;
        bool jump;
        bool chat;
        bool figh;
        uint8_t level;
    public:
        void Set_Stand(bool stand);
        void Set_Status(bool status);
        void Set_Direction(bool direction);
        void Set_Run(bool run);
        void Set_Jump(bool jump);
        void Set_Chat(bool chat);
        bool Get_Stand();
        bool Get_Status();
        bool Get_Direction();
        bool Get_Run();
        bool Get_Jump();
        bool Get_Chat();
        void Stand();
        void Run();
        void Jump();
        void Chat();
        void Handle_Action();
};

#endif // _BASE_OBJECT_HPP_
