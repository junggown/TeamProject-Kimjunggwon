#pragma once

#include "usr/include/SDL2/SDL.h"
#include "usr/include/SDL2/SDL2_gfxPrimitives.h"
#include "Vector2D.h"

class Walker 
{
    int Maxspd;
    int r;    
    float Maxfrc;
    float radian;
    Vector2D vel = Vector2D(0,0);
    Vector2D acc = Vector2D(0,0);
    Vector2D loc = Vector2D(0,0);
    Vector2D force = Vector2D(0,0);
    Vector2D tm1 = Vector2D(0,0);
    Vector2D tm2 = Vector2D(0,0);
    Vector2D tm3 = Vector2D(0,0);
    Vector2D* target;
    Vector2D* walker;
    Vector2D* tmp;


public:
  Walker(int x, int y);
  void seek(Vector2D* target);
  void applyForce(Vector2D& force);
  void show(SDL_Renderer* renderer);
  Vector2D& rotate(float rx, float ry, float rd);
  void draw(SDL_Renderer* renderer);
  void update();
};