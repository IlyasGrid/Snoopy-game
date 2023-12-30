#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "../utils/asciart.h"

#define COLONNE 21
#define LIGNE 10
#define PLAYER 'S'
#define OBSTACLE 'X'
#define COIN 'o'
#define BORDER 0x0DB
#define EMPTY ' '
#define BALL '#'

typedef struct
{
    int x;
    int y;
} Cordonee;

typedef struct
{
    Cordonee position;
    int lifes;
} Player;

typedef struct
{
    Cordonee position;
    Cordonee direction;
} Ball;

extern Player player;
extern Ball ball;
extern clock_t startTime;
extern int gameOver, nbrCoins, timer, score;
extern char matrix[LIGNE + 2][COLONNE + 2];

void setup();
void drawGame();
void updatePlayer();
void updateBall();
void checkCoins(int x, int y);
void setConsoleColor(int colorCode);
void saveScore(int score);
void collision();
void addObstacle(int x, int y);

#endif
