//Q[ΜskbygͺΦΎY
// fixed by Yuya Nakamura
// added #ifndef~#endif

#ifndef GAMEOVER
#define GAMEOVER

void gameOver () {
    lose = true;
    // ΘΊΜAuthor ΊGΖ
    score = getScore();
    saveScore();
    updateScores();
    setState(D_GAMEOVER);
}

#endif