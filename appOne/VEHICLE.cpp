#include"graphic.h"
#include"mathUtil.h"
#include "VEHICLE.h"

void VEHICLE::seek(const VECTOR2& target) 
{
    VECTOR2 desired = target - Pos;
    desired.setMag(MaxSpeed);
    VECTOR2 steer = desired - Vel;
    steer.limmit(MaxForce);
    applyForce(steer);
}

void VEHICLE::flee(const VECTOR2& target)
{
    VECTOR2 desired = target - Pos;
    if (desired.mag() < 200) {
        desired.setMag(MaxSpeed);
        VECTOR2 steer = desired - Vel;
        steer.limmit(MaxForce*2);
        applyForce(-steer);
    }
}

void VEHICLE::arrive(const VECTOR2& target) {
    auto desired = target - Pos;
    auto distance = desired.mag();
    auto radiusSlowDown = 100.0f;
    if (distance < radiusSlowDown) {
        auto speed = map(distance, 0, radiusSlowDown, 0, MaxSpeed);
        desired.setMag(speed);
    }
    else {
        desired.setMag(MaxSpeed);
    }

    auto steer = desired - Vel;
    steer.limmit(MaxForce);
    applyForce(steer);

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

void VEHICLE::draw()
{
    fill(255);
    Angle = atan2(Vel.x,-Vel.y);
    shape(ShapeId, Pos.x, Pos.y, Angle, Scale);
}
