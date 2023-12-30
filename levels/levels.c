#include "levels.h"

void level1()
{

    addObstacle(2, 5);
    addObstacle(2, 6);
    addObstacle(7, 5);
    addObstacle(10, 6);

    setup();
    label = "level 1";

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
    if (win == TRUE)
    {
        system("cls");
        congratulation();
        printf("\n\nYou've completed Level 1. with %d points\n", score);
        Sleep(3000);
    }
    else
    {
        char try;
        system("cls");
        printf("\ntry again  (Y/N)\n");
        scanf("%c", &try);
        if (try == 'Y' || try == 'y')
        {
            system("cls");
            Sleep(3000);
            level1();
        }
        else
        {
            system("cls");
            main();
        }
    }
}

void level2()
{

    setup();
    label = "level 2";

    // Ajout des  obstacles
    addObstacle(5, 5);
    addObstacle(5, 6);
    addObstacle(10, 5);
    addObstacle(10, 6);
    // addObstacle(15, 3);

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

    if (win == TRUE)
    {
        system("cls");
        congratulation();
        printf("\n\nYou've completed Level 2. with %d points\n", score);
        Sleep(3000);
    }
    else
    {
        char try;
        system("cls");
        printf("\ntry again  (Y/N)\n");
        scanf("%c", &try);
        if (try == 'Y' || try == 'y')
        {

            system("cls");
            Sleep(3000);
            level2();
        }
        else
        {

            system("cls");
            printf("save your previous score ? ( y/N) \n");
            scanf("%c", &try);
            if (try == 'Y' || try == 'y')
                saveScore();
            main();
        }
    }
}

void tutorial()
{

    setup();
    label = "tutorial";
    while (!gameOver)
    {

        _kbhit();
        drawGame();
        updateBall();
        Sleep(1000 / 30);
        updatePlayer();
    }

    system("cls");
    if (win == TRUE)
    {
        system("cls");
        congratulation();
        printf("\n\nYou've completed the Tutorial. ");
        Sleep(3000);
    }

    char try;
    fflush(stdin);

    system("cls");
    printf("\nPlay again  (Y/N)\n");
    scanf("%c", &try);
    if (try == 'Y' || try == 'y')
    {

        system("cls");
        Sleep(3000);
        tutorial();
    }
    else
    {

        system("cls");
        main();
    }
}
