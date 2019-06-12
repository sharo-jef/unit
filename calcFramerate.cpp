// Author: 中村宥哉
// FPS計算関数の定義
// displayInformation呼び出しの関係で関数名変更 (calcFps -> controlFps)

#ifndef CALCFPS
#define CALCFPS

using namespace display;

void controlFps ()
{
    now = timeGetTime();
    if (now - prevTime >= refreshSpeed)
    {
        cls();
        displayInformation();
        prevTime = now;
        count++;
    }
    if (now - baseTime >= 1000)
    {
        fps = (float)(count * 1000) / (float)(now - baseTime);
        baseTime = now;
        count = 0;
    }
}

#endif