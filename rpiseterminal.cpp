#include<stdio.h>
#include "rpic.h"
#include <time.h>

void clearScreen()
{
    putchar(27);
    putchar('[');
    putchar('2');
    putchar('J');
    teleportTo(1, 1);
}

void clearToLineEnd()
{
    putchar(27);
    putchar('[');
    putchar('K');
}

void clearToLineStart()
{
    putchar(27);
    putchar('[');
    putchar('1');
    putchar('K');
}

void clearLine()
{
    putchar(27);
    putchar('[');
    putchar('2');
    putchar('K');
}


void clearToScreenStart()
{
    putchar(27);
    putchar('[');
    putchar('1');
    putchar('J');
}

void clearToScreenEnd()
{
    putchar(27);
    putchar('[');
    putchar('J');
}

void teleportTo(int x, int y)
{
    char xstr[3] = {'0', '0', '\0'};
    char ystr[3] = {'0', '0', '\0'};
    sprintf(xstr, "%d", x);
    sprintf(ystr, "%d", y);
    putchar(27);
    putchar('[');
    int i = 0;
    for (; i < 3 && ystr[i] != '\0'; i++)
    {
        putchar(ystr[i]);
    }
    putchar(';');
    i = 0;
    for (; i < 3 && xstr[i] != '\0'; i++)
    {
        putchar(xstr[i]);
    }
    putchar('H');
    fflush(stdout);
}

void foregroundColor(Color foreground)
{
    char es[5] = {27, '[', '3', (char)foreground, 'm'};
    for (int i = 0; i < 5; i++)
        putchar(es[i]);
}

void backgroundColor(Color background)
{
    putchar(27);
    putchar('[');
    putchar('4');
    putchar(background);
    putchar('m');
    char es[5] = {27, '[', '4', (char)background, 'm'};
    for (int i = 0; i < 5; i++)
        putchar(es[i]);
}

void saveCursorLocation()
{
    putchar(27);
    putchar('[');
    putchar('s');
}

void restoreCursorLocation()
{
    putchar(27);
    putchar('[');
    putchar('u');
}

void showCharacter(char ch)
{
    putchar(ch);
    fflush(stdout);
}

void hideCharacter(char ch)
{
    putchar(' ');
    fflush(stdout);
}

void showCharacterInPlace(char ch){
    saveCursorLocation();
    putchar(ch);
    restoreCursorLocation();
    fflush(stdout);
}

void hideCharacterInPlace(){
    saveCursorLocation();
    putchar(' ');
    restoreCursorLocation();
    fflush(stdout);
}

void showCursor()
{
    char es[6] = {27, '[', '?', '2', '5', 'h'};
    for (int i = 0; i <= 5; i++)
        putchar(es[i]);
}

void hideCursor()
{
    char es[6] = {27, '[', '?', '2', '5', 'l'};
    for (int i = 0; i <= 5; i++)
        putchar(es[i]);
}

int readKey(void)
{
    char ch = getchar();
    while ((getchar()) != '\n');
    return ch;
}

int readKeyInPlace(void)
{
    saveCursorLocation();
    char ch = getchar();
    while ((getchar()) != '\n');
    restoreCursorLocation();
    return ch;
}

void setAttribute(Attribute ch)
{
    putchar(27);
    putchar('[');
    putchar(ch);
    putchar('m');
}

void wait(unsigned int secs)
{
    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime);
}

void teleportUp()
{
    putchar(27);
    putchar('[');
    putchar('A');
}

void teleportDown()
{
    putchar(27);
    putchar('[');
    putchar('B');
}

void teleportHome()
{
    putchar(27);
    putchar('[');
    putchar('H');
}

void teleportBack()
{
    putchar(27);
    putchar('[');
    putchar('D');
}

void teleportAhead()
{
    putchar(27);
    putchar('[');
    putchar('C');
}
