#include "base.h"

void setup()
{

    // pour cacher le curseur
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

    gameOver = FALSE;
    nbrCoins = 4;
    startTime = clock();

    player.position.x = COLONNE / 2 + 1;
    player.position.y = LIGNE / 2 + 1;

    ball.position.x = COLONNE - 2;
    ball.position.y = LIGNE - 2;

    ball.direction.x = -1;
    ball.direction.y = -1;

    for (int i = 0; i < LIGNE + 2; i++)
    {
        for (int j = 0; j < COLONNE + 2; j++)
        {
            if (i == 0 || i == LIGNE + 1 || j == 0 || j == COLONNE + 1)
            {
                matrix[i][j] = BORDER;
            }
            else
            {
                matrix[i][j] = EMPTY;
            }
        }
    }

    matrix[player.position.y][player.position.x] = PLAYER;
    matrix[ball.position.y][ball.position.x] = BALL;

    matrix[1][1] = COIN;
    matrix[1][21] = COIN;
    matrix[10][1] = COIN;
    matrix[10][21] = COIN;
}

// function pour dessiner l matrice du bordure
void drawGame()
{
    system("cls");

    for (int i = 0; i < LIGNE + 2; i++)
    {
        for (int j = 0; j < COLONNE + 2; j++)
        {
            if (matrix[i][j] == PLAYER)
            {
                setConsoleColor(10); // Green color for the player
            }
            else if (matrix[i][j] == BALL)
            {
                setConsoleColor(12); // Red color for the birds
            }
            else if (matrix[i][j] == COIN)
            {
                setConsoleColor(6); // Red color for the birds
            }
            else
            {
                setConsoleColor(7); // Default color for other characters
            }
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n%d coin(s) reamining ", nbrCoins);
    printf("\nIn %d s ", timer);
}

void updatePlayer()
{

    // Clear the player's current position
    matrix[player.position.y][player.position.x] = EMPTY;

    if (GetAsyncKeyState('A') & 0x8000)
    {
        if (player.position.x > 1)
        {
            player.position.x--;
        }
    }
    if (GetAsyncKeyState('D') & 0x8000)
    {
        if (player.position.x < COLONNE)
        {
            player.position.x++;
        }
    }
    if (GetAsyncKeyState('W') & 0x8000)
    {
        if (player.position.y > 1)
        {
            player.position.y--;
        }
    }
    if (GetAsyncKeyState('S') & 0x8000)
    {
        if (player.position.y < LIGNE)
        {
            player.position.y++;
        }
    }

    // cheking if the player next position contain a coin
    checkCoins(player.position.y, player.position.x);
    collision();

    matrix[player.position.y][player.position.x] = PLAYER;
}

// fonction pour verifier les coins
void checkCoins(int x, int y)
{
    if (matrix[x][y] == COIN)
    {
        nbrCoins--;
    }
    if (nbrCoins == 0)
    {
        gameOver = TRUE;
        score += timer * 1000;

        congratulation();
        printf("\nyour score was %d\n", score);
        char save;
        printf("save score and quit ?? (Y/N)\n");
        scanf("%c", &save);
        if (save == 'Y' || save == 'y')
        {
            saveScore(score);
            return;
        }
    }
}

// fonction pour le deplacement de la balle
void updateBall()
{
    matrix[ball.position.y][ball.position.x] = EMPTY;

    int newX = ball.position.x + ball.direction.x;
    int newY = ball.position.y + ball.direction.y;

    // verifier si il y a  une collision avec les murs
    if (newX >= COLONNE || newX <= 1)
    {
        ball.direction.x = -ball.direction.x;
    }
    if (newY >= LIGNE || newY <= 1)
    {
        ball.direction.y = -ball.direction.y;
    }

    // verifier si il y a une collision avec obstacles ou bien coin
    if (matrix[newY][newX] == OBSTACLE || matrix[newY][newX] == COIN)
    {
        // changer la direction de la ball
        ball.direction.y = -ball.direction.y;
        ball.direction.x = -ball.direction.x;

        // deplacer la balle a la derniere position
        newX = ball.position.x;
        newY = ball.position.y;
    }

    // // Check for collisions with the player
    // if (matrix[newY][newX] == PLAYER)
    // {
    //     printf("Ball hit the player!\n");
    //     exit(0);
    // }

    // mise a jour de la position de la balle
    ball.position.x = newX;
    ball.position.y = newY;

    matrix[ball.position.y][ball.position.x] = BALL;
}

// fonction pour verifier si la balle touche le player
void collision()
{
    if (player.position.x == ball.position.x && player.position.y == ball.position.y)
    {
        printf("\nGame Over! You were hit by the ball!\n");
        gameOver = 1;
    }
}

// fonction pour ajouter les obstacles
void addObstacle(int x, int y)
{

    if (x >= 1 && x <= COLONNE && y >= 1 && y <= LIGNE)
    {
        matrix[y][x] = OBSTACLE;
    }
    else
    {
        fprintf(stderr, "Error: Coordinates out of bounds for adding obstacle.\n");
    }
}

// fonction pour sauvgarder le score dans le fichier
void saveScore(int score)
{
    FILE *file = fopen("../../scoretable/ScoreTable.txt", "a");

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return;
    }

    char username[50];
    printf("Enter your username: ");
    scanf("%s", username);

    fprintf(file, "Username: %s Score: %d\n", username, score);

    fclose(file);
}

// styling
void setConsoleColor(int colorCode)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, colorCode);
}

//
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}