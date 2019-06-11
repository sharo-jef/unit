#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>

void pickUpText(){}
void goShop(){}
void useItem(){}

#define D_RULE 0
#define D_DUNGEON 1
#define D_BATTLE 2
#define D_ESC_MENU 99

#include "headers.h"

using namespace display;

int main (int argc, const char** argv)
{
    srand(time(NULL));
    initializeVariables();
    initializeDungeon();
    initializeEnemies();
    initializeSettings(argc, argv);
    initializeStudent();
    framerateInitialization();
    for (;;)
    {
        calcFps();
        switch (state)
        {
        case D_RULE:
            displayInformation();
            getch();
            prevState = state;
            state = 1;
            startTime = timeGetTime();
            break;
        case D_DUNGEON:
            setCursor(player.pos[1]);
            if (kbhit())
            {
                inputKey(getch());
            }
            displayInformation();
            break;
        case D_BATTLE:
            displayInformation();
            if (kbhit())
            {
                if (getch() == 0x1b) // DEBUG
                {
                    state = D_DUNGEON;
                }
            }
            break;
        case D_ESC_MENU:
            if (kbhit())
            {
                inputKey(getch());
            }
        }
    }

    forceexit:;
    return 0;
}