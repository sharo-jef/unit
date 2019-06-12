// Author: 中村宥哉
// 設定初期化関数の定義

#ifndef INITSETTINGS
#define INITSETTINGS

void initializeSettings (int argc, const char** argv)
{
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-fps") == 0)
        {
            showFps = true;
        }
        if (strcmp(argv[i], "-lfps") == 0)
        {
            refreshSpeed = 100;
        }
        if (strcmp(argv[i], "-vlfps") == 0)
        {
            refreshSpeed = 500;
        }
    }
}

#endif