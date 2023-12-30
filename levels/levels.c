#include "levels.h"

void level1()
{

    setup();

    while (!gameOver)
    {
        clock_t currentTime = clock();
        double elapsedTime = ((double)(currentTime - startTime)) / CLOCKS_PER_SEC;
        // Update timer
        timer = 60 - (int)elapsedTime;
        if (timer < 0)
            gameOver = !gameOver;

                _kbhit();
        drawGame();
        updateBall();
        updatePlayer();
        Sleep(1000 / 30);
    }
}

void level2()
{

    setup();

    // Ajout des  obstacles
    addObstacle(5, 5);
    addObstacle(10, 8);
    addObstacle(15, 3);

    while (!gameOver)
    {
        clock_t currentTime = clock();
        double elapsedTime = ((double)(currentTime - startTime)) / CLOCKS_PER_SEC;
        timer = 60 - (int)elapsedTime;
        if (timer < 0)
            gameOver = !gameOver;

        _kbhit();
        drawGame();
        updateBall();
        updatePlayer();
        Sleep(1000 / 30);
    }
}

void tutorial()
{

    setup();

    while (!gameOver)
    {

        _kbhit();
        drawGame();        
        updateBall();
        Sleep(1000/30); 
        updatePlayer();
    }

}


