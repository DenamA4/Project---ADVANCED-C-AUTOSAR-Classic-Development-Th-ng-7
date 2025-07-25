#include "../include/can_frame.h"

void packDoorStatus(Door* doors, CANFrame_t* frame)    // doors là con trỏ đến mảng 4 struct kiểu Door
{
    for(int i = 0; i < 4; i++)
    {
        frame->bytes[i] = (doors + i)->statusUnion.byte;
    }
}

void unpackDoorStatus(CANFrame_t* frame, Door* doors)   // doors là con trỏ đến mảng 4 struct kiểu Door
{
    for(int i = 0; i < 4; i++)
    {
        if(frame->bytes[i] & 1)
        {
            (doors + i)->open(doors + i);
        } else
        {
            (doors + i)->close(doors + i);
        }

        if(frame->bytes[i] & (1 << 1))
        {
            (doors + i)->lock(doors + i);
        } else 
        {
            (doors + i)->unlock(doors + i);
        }

        if(frame->bytes[i] & (1 << 2))
        {
            (doors + i)->openWin(doors + i);
        } else 
        {
            (doors + i)->closeWin(doors + i);
        }
    }
}