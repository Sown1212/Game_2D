#pragma once

#ifndef _DATA_BASE_HPP_
#define _DATA_BASE_HPP_

#include<iostream>
#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include"Object.hpp"

#define Window_Width 800
#define Window_Height 500
#define Window_PositionX 550
#define Window_PositionY 100

#define Player_Width 64
#define Player_Height 64
#define Player_PositionX  20
#define Player_PositionY 390

#define ColorKeyR 255
#define ColorKeyG 255
#define ColorKeyB 255

#define LIVE 1
#define DEAD 0
#define RIGHT 1
#define LEFT 0

#define RUN 1
#define PAUSE 0

#define MAX_JUMP 100
uint8_t SPEED = 3;
int cnt = 0;
int f = 0;

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;
const char *path = "Font/Arial.ttf";
SDL_Event event;

Base_Object backgroud;
Main_Object player;
Time timer;
Game game;
Font fps;

SDL_Rect rectBackgroud;
SDL_Rect rectTemp;
SDL_Rect rectRenderer;

SDL_Rect rectPlayer[2];
SDL_Rect rectPlayer_run[4];
SDL_Rect rectPlayer_jump[2];

#endif // _DATA_BASE_HPP_