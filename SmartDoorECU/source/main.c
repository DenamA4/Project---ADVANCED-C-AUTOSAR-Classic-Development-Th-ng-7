#include "../include/door.h"
#include "../include/can_frame.h"
#include "../include/utils.h"
#include <stdio.h>


int main()
{
    Door doors[4];
    CANFrame_t frame;

    // Khoi tao actuator cho moi cua
    for (int i = 0; i < 4; i++) {
        Door_Init(&doors[i], openDoor, closeDoor, lockDoor, unlockDoor, openWindow, closeWindow);
    }

    int choice;
    while (1)
    {
        printf("\n========= SMART DOOR ECU MENU =========\n");
        printf("1. Xem trang thai tat ca cua\n");
        printf("2. Dieu khien actuator cua\n");
        printf("3. Packing trang thai vao frame\n");
        printf("4. Unpacking trang thai tu frame\n");
        printf("5. Kiem tra parity va dao bit\n");
        printf("6. Thao tac advanced pointer\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                for (int i = 0; i < 4; i++) {
                    printf("Door %d: Open=%d, Locked=%d, Window=%d, Byte=0x%02X\n", i,
                           doors[i].statusUnion.status.isOpen,
                           doors[i].statusUnion.status.isLocked,
                           doors[i].statusUnion.status.hasWindow,
                           doors[i].statusUnion.byte);
                }
                break;

            case 2: {
                int doorIdx, action;
                printf("Chon cua (0-3): ");
                scanf("%d", &doorIdx);
                printf("1: Open, 2: Close, 3: Lock, 4: Unlock, 5: OpenWindow, 6: CloseWindow\n");
                printf("Chon hanh dong: ");
                scanf("%d", &action);
                switch (action) {
                    case 1: doors[doorIdx].open(&doors[doorIdx]); break;
                    case 2: doors[doorIdx].close(&doors[doorIdx]); break;
                    case 3: doors[doorIdx].lock(&doors[doorIdx]); break;
                    case 4: doors[doorIdx].unlock(&doors[doorIdx]); break;
                    case 5: doors[doorIdx].openWin(&doors[doorIdx]); break;
                    case 6: doors[doorIdx].closeWin(&doors[doorIdx]); break;
                    default: printf("Hanh dong khong hop le!\n"); break;
                }
                break;
            }

            case 3:
                packDoorStatus(doors, &frame);
                printf("Packed CAN Frame: ");
                for (int i = 0; i < 8; i++)
                    printf("0x%02X ", frame.bytes[i]);
                printf("\n");
                break;

            case 4:
                unpackDoorStatus(&frame, doors);
                printf("Da unpack lai trang thai tu frame:\n");
                for (int i = 0; i < 4; i++) {
                    printf("Door %d: Open=%d, Locked=%d, Window=%d, Byte=0x%02X\n", i,
                           doors[i].statusUnion.status.isOpen,
                           doors[i].statusUnion.status.isLocked,
                           doors[i].statusUnion.status.hasWindow,
                           doors[i].statusUnion.byte);
                }
                break;


            case 5: {
                uint8_t byte;
                printf("Nhap byte (0-255): ");
                scanf("%hhu", &byte);
                printf("Parity: %s\n", checkParity(byte) ? "Even" : "Odd");
                printf("Reversed Bits: 0x%02X\n", reverseBits(byte));
                break;
            }

            case 6:
                pointerDemo(doors);
                break;

            case 0:
                return 0;

            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    }

    return 0;
}

