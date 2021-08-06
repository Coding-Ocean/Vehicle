#define _ARRIVE
#ifdef _ARRIVE
#include"libOne.h"
#include"VEHICLE.h"
#include"TARGET.h"
void gmain() {
    window(1920, 1080, full);
    hideCursor();
    VEHICLE vehicle;
    TARGET target(loadImage("assets\\mesu.png"));
    vehicle.create();
    target.setScale(120);
    target.setPos(width/2, 801);
    target.setColor(0, 200, 0, 0);
    while (notQuit) {
        clear(200, 255, 200);
        target.setPos(mouseX, mouseY);
        vehicle.update(target.pos());

        target.draw();
        vehicle.draw();
    }
}
#endif
#ifdef _FLEE
#include"libOne.h"
#include"VEHICLE.h"
#include"TARGET.h"
void gmain() {
    window(1920, 1080, full);
    hideCursor();
    VEHICLE vehicle;
    TARGET target(loadImage("assets\\mesu.png"));
    TARGET monster(loadImage("assets\\karasu.png"));
    vehicle.create();
    target.setScale(120);
    target.setPos(width / 2, height / 2);
    target.setColor(0, 200, 0,0);
    monster.setScale(400);
    monster.setColor(255, 0, 0,0);
    while (notQuit) {
        clear(200,255,200);

        monster.setPos(mouseX, mouseY);

        vehicle.setMaxSpeed(4);
        vehicle.setMaxForce(0.25f);
        vehicle.arrive(target.pos());
        vehicle.setMaxSpeed(4);
        vehicle.setMaxForce(0.4f);
        vehicle.flee(monster.pos());
        
        vehicle.update();
        monster.update(vehicle.pos());
        target.draw();
        monster.draw();
        vehicle.draw();
    }
}
#endif