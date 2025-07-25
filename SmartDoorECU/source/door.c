#include "../include/door.h"

void openDoor(Door* d)
{
    d->statusUnion.status.isOpen = 1;
}

void closeDoor(Door* d)
{
    d->statusUnion.status.isOpen = 0;
}

void lockDoor(Door* d)
{
    d->statusUnion.status.isLocked = 1;
}

void unlockDoor(Door* d)
{
    d->statusUnion.status.isLocked = 0;
}

void openWindow(Door* d)
{
    d->statusUnion.status.hasWindow = 1;
}

void closeWindow(Door* d)
{
    d->statusUnion.status.hasWindow = 0;
}

void Door_Init(Door* d, ActuatorFunc open, ActuatorFunc close, ActuatorFunc lock, ActuatorFunc unlock, ActuatorFunc openWin, ActuatorFunc closeWin)
{
    d->statusUnion.status.isOpen = 0;        // Mặc định ban đầu cửa đóng
    d->statusUnion.status.isLocked = 0;      // ................ mở khóa
    d->statusUnion.status.hasWindow = 0;     // ................ cửa kính đóng
    d->open = open;
    d->close = close;
    d->lock = lock;
    d->unlock = unlock;
    d->openWin = openWin;
    d->closeWin = closeWin;
}