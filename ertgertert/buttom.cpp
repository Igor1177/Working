#include "TXLib.h"

struct Button
{
   int x;
   int y;
   const char* name;
   string category;

   void draw()
    {
        txSetColor(TX_TRANSPARENT);
        txSetFillColor(TX_GRAY);
        Win32::RoundRect (txDC(), x+5, y+5, x+145, y+35, 30, 30);
        txSetColor(TX_BLACK, 2);
        txSetFillColor(TX_WHITE);
        if (click()) txSetFillColor(RGB(250, 180, 180));
        Win32::RoundRect (txDC(), x, y, x+140, y+30, 30, 30);
        txSetColor(TX_BLACK);
        txSelectFont("Times New Roman", 24);
        txDrawText (x, y, x+140, y+30, name);
    }

    bool click()
    {
        return( txMouseButtons() == 1 &&
                txMouseX() >= x && txMouseX() <= x+140 &&
                txMouseY() >= y && txMouseY() <= y+30);
    }

};
