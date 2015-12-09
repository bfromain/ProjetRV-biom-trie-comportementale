
#include "fonction2.h"

using namespace std;

void sleepcp(int milliseconds) // cross-platform sleep function
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_end){}
}

clock_t timepress (char c)
{
    int i;
    int i2;
    clock_t temps = clock();
    short s;

    i = c;
    if (i>90){i-=32;}

    s=GetKeyState(i);
    i2 = s&0x80;


    while (i2 > 0)
    {
        s=GetKeyState(i);
        i2 = s&0x80;
    }

    temps = clock() - temps;

    return temps;
}
