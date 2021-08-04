#pragma once
#include"VECTOR2.h"
class VEHICLE
{
    int ShapeId=0;
    float Angle=0;
    float Scale=1;
    VECTOR2 Pos;
    VECTOR2 Vel;
    VECTOR2 Acc;
    float MaxSpeed;
    float MaxForce;
public:
    const VECTOR2& pos() { return Pos; }
    void setPos(float x, float y) { Pos.x = x; Pos.y = y; }
    void setMaxSpeed(float maxSpeed) { MaxSpeed = maxSpeed; }
    void setMaxForce(float maxForce) { MaxForce = maxForce; }
    void setShapeId(int shapeId) { ShapeId = shapeId; }
    void setScale(float scale) { Scale = scale; }
    void seek(const VECTOR2& target);
    void flee(const VECTOR2& target);
    void arrive(const VECTOR2& target);
    void applyForce(const VECTOR2& force);
    void update();
    void draw();
};

