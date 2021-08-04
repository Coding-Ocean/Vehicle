#pragma once
#include"graphic.h"
#include"VECTOR2.h"
class TARGET
{
    VECTOR2 Pos;
    float Scale;
    COLOR Color;
public:
    void setScale(float scale) { Scale = scale; }
    void setColor(float r, float g, float b) { Color = COLOR(r, g, b); }
    void setPos(float x, float y) { Pos.x = x; Pos.y = y; }
    const VECTOR2& pos() { return Pos; }
    void draw();
};

