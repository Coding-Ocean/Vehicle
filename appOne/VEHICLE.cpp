#include"graphic.h"
#include"mathUtil.h"
#include"createTriangle.h"
#include "VEHICLE.h"
void VEHICLE::create() 
{
    ShapeId = createTriangle();
    Img = loadImage("assets\\osu.png");
    Scale = 30;
    Pos = VECTOR2(width/2-100, height/2-100);
    MaxSpeed = 4;
    MaxForce = 0.25f;
    RadiusArrive = 100;
    RadiusFlee = 200;
    Vel = VECTOR2(1, -1);
    //Vel *= 3;
}

void VEHICLE::seek(const VECTOR2& target) 
{
    VECTOR2 desired = target - Pos;
    desired.setMag(MaxSpeed);
    VECTOR2 steer = desired - Vel;
    steer.limmit(MaxForce);
    applyForce(desired);
}

void VEHICLE::arrive(const VECTOR2& target) {
    auto desired = target - Pos;
    //ターゲットに近づいたらスピードダウン
    auto distance = desired.mag();
    if (distance < RadiusArrive) {
        auto speed = map(distance, 0, RadiusArrive, 0, MaxSpeed);
        desired.setMag(speed);
    }
    else {
        desired.setMag(MaxSpeed);
    }

    auto steer = desired - Vel;
    steer.limmit(MaxForce);
    applyForce(steer);

}

void VEHICLE::flee(const VECTOR2& target)
{
    VECTOR2 desired = target - Pos;
    if (desired.mag() < RadiusFlee) {
        desired.setMag(MaxSpeed);
        VECTOR2 steer = desired - Vel;
        steer.limmit(MaxForce);
        applyForce(-steer);
    }
}

void VEHICLE::applyForce(const VECTOR2& force)
{
    Acc += force;
}

void VEHICLE::update()
{
    Vel += Acc;
    if (Vel.mag() > MaxSpeed)Vel = Vel.normalize() * MaxSpeed;
    Pos += Vel;
    Acc = VECTOR2(0, 0);
}
void VEHICLE::update(const VECTOR2& target) {
    Acc = target - Pos;
    Acc.setMag(1);
    Vel += Acc;
    //Vel.limmit(1);
    Pos += Vel;
}


void VEHICLE::draw()
{
    fill(255);
    Angle = atan2(Vel.x,-Vel.y);
    shape(ShapeId, Pos.x, Pos.y, Angle, Scale);
    rectMode(CENTER);
    image(Img, Pos.x, Pos.y, Angle);
}
