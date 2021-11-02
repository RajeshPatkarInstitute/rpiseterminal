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
enum Attribute
{
    reset = '0',
    bright = '1',
    dim = '2',
    underscore = '4',
    blink = '5',
    reverse = '7',
    hidden = '8'
};

void clearScreen();
void clearToLineEnd();
void clearToLineStart();
void clearLine();
void clearToScreenStart();
void ClearToScreenEnd();
void teleportTo(int x, int y);
void foregroundColor(Color foreground);
void backgroundColor(Color background);
void saveCursorLocation();
void restoreCursorLocation();
void showCharacter(char ch);
void hideCharacter();
void showCharacterInPlace(char ch);
void hideCharacterInPlace(char ch);
void showCursor();
void hideCursor();
int readKey(void);
int readKeyInPlace(void);
void setAttribute(Attribute ch);
void wait(unsigned int secs);
void teleportUp();
void teleportDown();
void teleportBack();
void teleportAhead();
