#include <stdio.h>
#include <stdlib.h>
#include "levels/levels.h"

void tutoriallevel();
void levels();

int main()
{

    char choice = ' ';
    do
    {
        system("Cls");
        snoopy();
        printf("Menu:\n");
        printf("\t tutoriel                  1\n");
        printf("\t Nouveau jeu               2\n");
        printf("\t voir le table du score    3\n");
        printf("\t Quitter                   Q\n");

        choice = getch();

    } while (choice != 'q' && choice != 'Q' && choice != '1' && choice != '2' && choice != '3');

    switch (choice)
    {
    case '1':
        // tutoriallevel();
        tutorial();
        break;
    case '2':
        levels();
        break;
    case '3':
        printf("table du score\n");
        displayScoreTable();
        printf("\n entrez un cle pour revient au menu\n");
        getchar();
        main();
        break;
    case 'q':
        auRevoir();
        break;
    }

    return 0;
}

void tutoriallevel()
{
    char again;
    do
    {
        tutorial();
        system("cls");
        printf("\n play again ? (Y/N)");

        scanf("%c", &again);
    } while (again != 'N' || again != 'n' || again == 'Y' || again == 'y');

    system("cls");
    printf("\n start level 1 (Y/N)");
    scanf("%c", again);
    if (again == 'Y')
        levels();
    else
    {
        system("cls");
        printf("\n get back to the main menu (Y/N)");
        scanf("%c", again);
        if (again == 'Y')
            levels();
    }
}

void levels()
{
    system("cls");
    level1();
    system("cls");
    level2();
    saveScore();
}