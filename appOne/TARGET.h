#pragma once
#include"graphic.h"
#include"VECTOR2.h"
class COLLISION_RECT {
    float OffsetTop=0;
    float OffsetLeft=0;
    float OffsetRight=0;
    float OffsetBottom=0;
    VECTOR2& Pos;
public:
    void setPosRef(const VECTOR2& pos) { Pos = pos; }
    float top() { return Pos.y + OffsetTop; }
    float bottom() { return Pos.y + OffsetBottom; }
    float left() { return Pos.x + OffsetLeft; }
    float right() { return Pos.x + OffsetRight; }
};
class TARGET
{
    int Img;
    VECTOR2 Pos;
    float Angle=0;
    float Scale=1;
    COLOR Color;
public:
    TARGET(int img) { Img = img; }
    void setScale(float scale) { Scale = scale; }
    void setColor(float r, float g, float b, float a=255) { Color = COLOR(r, g, b, a); }
    void setPos(float x, float y) { Pos.x = x; Pos.y = y; }
    const VECTOR2& pos() { return Pos; }
    void update(const VECTOR2& pos) {
        VECTOR2 vec = pos - Pos;
        Angle = atan2(vec.x, -vec.y);
    }
    void draw() {
        rectMode(CENTER);
        fill(Color);
        stroke(255);
        //circle(Pos.x, Pos.y, Scale);
        image(Img, Pos.x, Pos.y, Angle);
    }
};

