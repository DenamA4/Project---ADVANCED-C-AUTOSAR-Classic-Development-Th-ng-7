#include "../include/utils.h"
#include <stdio.h>
#include <string.h>


uint8_t checkParity(uint8_t byte)
{
    char i = 0;
    char count = 0;
    while(i < 9)
    {
        if(byte & (1 << i)) count++;
        i++;
    }
    if(count % 2 == 0) return 1;
    else return 0;
}

uint8_t reverseBits(uint8_t byte)
{
    char i = 0;
    char value = 0;
    while(i < 9)
    {
        if (byte & (1 << i)) value &= ~(1 << i);
        else value |= (1 << i);
        i++;
    } 
    return value;
}

void pointerDemo(Door* doors)
{
    printf("=== Advanced Pointer Demo ===\n");

    // Pointer to pointer
    Door** ptrToPtr = &doors;
    printf("ptrToPtr -> doors[0].isOpen = %d\n", (*ptrToPtr)[0].statusUnion.status.isOpen);

    // 2. Void pointer thao tác generic
    void* vptr = (void*)&doors[1];  // generic pointer tới door thứ 2
    Door temp;

    memcpy(&temp, vptr, sizeof(Door));  // sao chép generic nội dung Door
    printf("Generic memcpy door[1] → temp: isLocked = %d\n", temp.statusUnion.status.isLocked);

    // Const pointer
    Door* const constPtr = &doors[2];
    constPtr->statusUnion.status.hasWindow = 1;
    printf("constPtr:   door[2].hasWindow = %d\n", constPtr->statusUnion.status.hasWindow);

    // Pointer to const 
    const Door* ptrToConst = &doors[3];
    printf("ptrToConst:   door[3].isOpen = %d\n", ptrToConst->statusUnion.status.isOpen);
    // ptrToConst->statusUnion.status.isOpen = 1; // lỗi nếu thử gán

    printf("=================================\n");
}

// void* memcpy(void* dest, const void* src, size_t n);