enum Color
{
    black = '0',
    red = '1',
    green = '2',
    yellow = '3',
    blue = '4',
    magenta = '5',
    cyan = '6',
    white = '7'
};

void clearScreen();
void teleportTo(int x, int y);
void foregroundColor(Color foreground);
void backgroundColor(Color background);
void saveCursorLocation();
void restoreCursorLocation();
