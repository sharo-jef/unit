//Q[ΜbygͺΦΎY
// fixed by Yuya Nakamura
// added #ifndef~#endif

#ifndef GAMECLEAR
#define GAMECLEAR

void gameClear(){
    win = true;
    // ΘΊΜAuthor ΊGΖ
    score = getScore();
    saveScore();
    updateScores();
    setState(D_CLEAR);
    setCursor(0);
}

#endif