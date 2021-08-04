#include"libOne.h"
#include"createTriangle.h"
#include"VEHICLE.h"
#include"TARGET.h"
void gmain() {
    window(1000, 1000);
    VEHICLE vehicle;
    vehicle.setShapeId(createTriangle());
    vehicle.setScale(30);
    vehicle.setPos(400, 400);
    vehicle.setMaxSpeed(4);
    vehicle.setMaxForce(0.25);
    TARGET target;
    target.setScale(60);
    target.setPos(width / 2, height / 2);
    target.setColor(0, 200, 0);
    TARGET monster;
    monster.setScale(60);
    monster.setColor(255, 0, 0);
    while (notQuit) {
        clear();
        monster.setPos(mouseX, mouseY);

        vehicle.arrive(target.pos());
        vehicle.flee(monster.pos());
        
        vehicle.update();
        target.draw();
        monster.draw();
        vehicle.draw();
    }
}
