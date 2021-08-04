#include "graphic.h"
#include "input.h"
#include "TARGET.h"

void TARGET::draw()
{
    fill(Color);
    circle(Pos.x, Pos.y, Scale);
}
