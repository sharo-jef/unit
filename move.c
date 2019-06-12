//FāVSó
//wķĖÚŪ

// fixed by Yuya Nakamura
// added #ifndef~#endif
// fixed indent
// added if (moved...

#ifndef MOVE
#define MOVE

void move (int inputDirection)
{
    int direction = getRoom()->direction;
    bool moved = false;
    if (inputDirection & direction)
    {
        if (strcmp(getRoom()->eventName, "pickUpText") == 0 && textBooks[player.pos[0] / 2])
        {
            pickUpText();
        }
        switch (inputDirection)
        {
        case 1:
            player.pos[1]++; //E
            break;

        case 2:
            player.pos[0]++; //ã
            break;

        case 4:
            player.pos[1]--; //ķ
            break;
        }
        moved = true;
    }
    if (moved)
    {
        // GJEgĩ―Đŧč
        if (checkEncount())
        {
            setState(D_BATTLE);
            setCursor(0);
        }
    }
}

#endif