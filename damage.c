//吉岡誇太郎
//ダメージ計算
#ifndef DAMAGE
#define DAMAGE
#define NORMAL_ATTACK 0
#define REPORT_ATTACK 1
void damage(int a)
{
    Enemy enemy = enemies[player.pos[0] != 7 ? player.pos[0] : player.pos[1] == 2 ? 7 : 8];
    switch (a)
    {
    case NORMAL_ATTACK:
        tmpAttack *= player.atk;
        break;
    case REPORT_ATTACK:
        tmpAttack *= player.atk + player.intelligence;
        break;
    }
    if (player.skills[0])
    {
        tmpAttack *= 2.5;
    }
    if (enemy.dmgCut)
    {
        tmpAttack /= 2;
    }
}

#endif