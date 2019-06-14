#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define D_RULE       0
#define D_DUNGEON    1
#define D_BATTLE     2
#define D_SHOP       3
#define D_ESC_MENU  99

#define STUDENT_POS {0, 2}
#define STUDENT_MAX_HP 10000.f
#define STUDENT_HP 10000.f
#define STUDENT_ATK 100.f
#define STUDENT_INT 0
#define STUDENT_MONEY 1000
#define STUDENT_ITEM {0, 0, 0} // energy, paper, es
#define STUDENT_RECAST {4, 5, 2, 5}
#define STUDENT_SKILLS {0, 0}

int state, prevState;
float tmpAttack;

void setState (int s)
{
    prevState = state;
    state = s;
}

typedef struct Student {
    struct Student* self;
    char name[256];
    int pos[2];
    float maxHp;
    float hp;
    float atk;
    int intelligence;
    int money;
    int item[3];
    int recast[4];
    int skills[2];
} Student;

Student new_Student (const char* name)
{
    Student s = {
        &s,
        "",
        STUDENT_POS,
        STUDENT_MAX_HP,
        STUDENT_HP,
        STUDENT_ATK,
        STUDENT_INT,
        STUDENT_MONEY,
        STUDENT_ITEM,
        STUDENT_RECAST,
        STUDENT_SKILLS
    };
    strcpy(s.name, name);
    return s;
}

typedef struct Enemy
{
    struct Enemy* self; // 自身
    int hp;             // HP
    int maxHp;          // 最大HP
    float stdAtk;       // 基礎攻撃力
    bool charge;        // 溜めの有無
    int dmgCut;         // 半減の残りターン数
    int intelligence;   // もらえる知識量
    int type;           // 中:1, 通常:2, 裏ボス:3か雑魚:0か
    int act;            // 行動ルーチン
    int spact;          // 特殊行動
} Enemy;

Enemy new_Enemy (int hp, int maxHp, float stdAtk, int intelligence, int type, int act, int spact)
{
    Enemy e = {
        &e,
        hp,
        maxHp,
        stdAtk,
        0,
        0,
        intelligence,
        type,
        act,
        spact
    };
    return e;
}

Enemy enemies[9]; 

#define SKILL_F1B 1
#define SKILL_F2B 2
#define SKILL_F3B 3
#define SKILL_F4B 4
#define ROUTINE_F4B 5
#define SKILL_LAST 6
#define ROUTINE_LAST 7
//敵の初期化by吉岡誇太郎
void initializeEnemies(){
    Enemy e[9] = {
        new_Enemy(500,500,500,100,0,0,0),//f1z
        new_Enemy(1000,1000,1000,400,1,0,SKILL_F1B),//f1b
        new_Enemy(2000,2000,500,200,0,0,0),//f2z
        new_Enemy(4500,4500,1000,600,1,0,SKILL_F2B),//f2b
        new_Enemy(4000,4000,800,300,0,0,0),//f3z
        new_Enemy(10000,10000,1000,800,1,0,SKILL_F3B),//f3b
        new_Enemy(10000,10000,1000,450,0,0,0),//f4z
        new_Enemy(15000,15000,1000,1000,2,ROUTINE_F4B,SKILL_F4B),//f4b
        new_Enemy(50000,50000,2000,0,3,ROUTINE_LAST,SKILL_LAST),//last
    };
    memcpy(enemies, e, sizeof(e));
}


typedef struct Cursor {
    int pos;
} Cursor;

Cursor cursor;
Student player;

void addIntelligence(int intelligence){ 
    player.intelligence+=intelligence;
}


bool win;
bool lose;
bool trueClear;

#include "useItem.c"
#include "useSkill.c"
#include "damage.c"
#include "isCritical.c"
#include "battleVictory.c"

void execute ()
{
    switch (state)
    {
    case D_BATTLE:

        break;
    }
}

int main (int argc, const char** argv)
{
    win = false;
    lose = false;
    trueClear = false;
    cursor.pos = 0;
    player = new_Student("TestStudent");
    player.intelligence = 300;
    player.item[0] = 2;
    player.item[1] = 100;
    player.item[2] = 1;
    state = D_BATTLE;
    srand(time(NULL));
    initializeEnemies();
    rand();
    for (;;)
    {
        if (kbhit())
        {
            switch (getch())
            {
            case 'd':
                cursor.pos++;
                break;
            case 'a':
                if (cursor.pos > 0) cursor.pos--;
                break;
            case '.':
                state++;
                break;
            case ',':
                state--;
                break;
            }
        }
        printf("---\n名前: %s\n知識: %d\nCursor: %d\nstate: %d\nHP: %5d, 知識: %4d\nエナジードリンク: %2d本, レポート用紙: %3d枚, 履歴書: %1d枚\n|%s出席 |%sレポート提出 |%sスキル |%sアイテム |\n",
            player.name,
            player.intelligence,
            cursor.pos,
            state,
            (int)player.hp,
            player.intelligence,
            player.item[0],
            player.item[1],
            player.item[2],
            cursor.pos == 0 ? ">" : " ",
            cursor.pos == 1 ? ">" : " ",
            cursor.pos == 2 ? ">" : " ",
            cursor.pos == 3 ? ">" : " "
        );
    }
    return 0;
}