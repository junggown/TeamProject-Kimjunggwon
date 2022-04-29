#include "Walker.h"
#include <random>
#include "InputHandler.h"

Walker::Walker(int x, int y) 
{
    loc.setX(x);
    loc.setX(y);
    loc = Vector2D(x,y);
    Maxspd = 4;
    r = 16; 
    Maxfrc = 0.25;
    radian = 0;
}

void Walker::seek(Vector2D* target){
  force = target - loc;
  force.normalize();
  force *= Maxspd;
  force -= vel;
  force.limit(Maxspd);
  applyForce(force);
}

void Walker::applyForce(Vector2D& force){
  acc += force;
}

  Vector2D& Walker::rotate(float rx, float ry, float rd)
{
  tmp = new Vector2D(0,0);
  tmp->setX(cos(radian) * rx - sin(radian) * ry);
  tmp->setY(sin(radian) * rx - cos(radian) * ry);

  return *tmp;
}

void Walker::update() 
{
  radian = atan2(vel.getY(), vel.getX());
  tm1 = rotate(-r, -r/2, radian);
  tm2 = rotate(-4, r/2, radian);
  tm3 = rotate(r, 0, radian);
  vel += acc;
  vel.limit(Maxspd);
  loc += vel;
  acc *= 0;

  target = TheInputHandler::Instance()->getMousePosition();

  walker->seek(target);
}
void Walker::show(SDL_Renderer* renderer)
{
  filledTrigonColor(renderer, tm1.getX() + loc.getX(), tm1.getY() + loc.getY(), tm2.getX() + loc.getX(), tm2.getY() + loc.getY() , tm3.getX() + loc.getX(), tm3.getY() + loc.getY(), 0xFFFFFFFF);
}

void Walker::draw(SDL_Renderer* renderer)
{
 filledCircleColor(renderer, target->getX(), target->getY(), 16, 0xFF0000FF); 
}


//최대한 할려고 했는데 여기서 잘 모르겠습니다..