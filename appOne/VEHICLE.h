#pragma once
#include"VECTOR2.h"
class VEHICLE
{
    int ShapeId=0;
    int Img = 0;
    float Angle=0;
    float Scale=1;
    VECTOR2 Pos;
    VECTOR2 Vel;
    VECTOR2 Acc;
    float MaxSpeed=0;
    float MaxForce=0;
    float RadiusArrive=0;
    float RadiusFlee=0;
public:
    void create();
    void setMaxSpeed(float maxSpeed) {
        MaxSpeed = maxSpeed;
    }
    void setMaxForce(float maxForce) {
        MaxForce = maxForce;
    }
    void seek(const VECTOR2& target);
    void flee(const VECTOR2& target);
    void arrive(const VECTOR2& target);
    void applyForce(const VECTOR2& force);
    void update();
    void update(const VECTOR2& target);
    void draw();
    const VECTOR2& pos() { return Pos; }
    const VECTOR2& vel() { return Vel; }
};

