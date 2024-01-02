#include <stdio.h>
#include <stdlib.h>
#include "levels/levels.h"

void showMainMenu();
void tutorialLevel();
void playGame();
void showScoreTable();

int main()
{
    char choice;

    do
    {
        showMainMenu();
        choice = getchar();
        fflush(stdin); // Clear the input buffer

        switch (choice)
        {
        case '1':
            tutorialLevel();
            break;
        case '2':
            playGame();
            break;
        case '3':
            showScoreTable();
            break;
        case '4':
            auRevoir();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            Sleep(900);
        }
    } while (choice != 'q' && choice != 'Q');

    return 0;
}

void showMainMenu()
{
    system("cls");
    snoopy();
    printf("Menu:\n");
    printf("\t tutoriel                  1\n");
    printf("\t Nouveau jeu               2\n");
    printf("\t voir le table du score    3\n");
    printf("\t Quitter                   4\n");
}

void tutorialLevel()
{
    char again;

    do
    {
        tutorial();
        printf("\n Play again? (Y/N): ");
        scanf(" %c", &again);
        fflush(stdin); // Clear the input buffer
    } while (again == 'Y' || again == 'y');

    printf("\n Start level 1? (Y/N): ");
    scanf(" %c", &again);

    if (again == 'Y' || again == 'y')
    {
        playGame();
    }
    else
    {
        printf("\n Get back to the main menu? (Y/N): ");
        scanf(" %c", &again);

        if (again == 'Y' || again == 'y')
        {
            // No need to call levels() here; it's called in playGame()
            main();
        }
    }
}

void playGame()
{
    system("cls");
    level1();
    system("cls");
    char save;
    printf("Save your score ? (y/n)\n");
    scanf("%c", &save);
    if (save == 'y' || save == 'Y')
        saveScore();
    else
        main();
}

void showScoreTable()
{
    char c;

    do
    {
        system("cls");
        printf("Table du score\n");
        displayScoreTable();
        printf("\n Entrez (m) pour revenir au menu\n");
        c = getchar();
    } while (c != 'm');
}
