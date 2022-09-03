#include <stdio.h>
#include <stdlib.h>
char menu();
void gameBoard(char (*)[3]);
int lenght(char *);
void rePrint(char (*)[3]);
int checkWin(char (*)[3]);
void player(char (*)[3], char *, char *);
int playerInsert(char (*)[3], char, char);
void smart(char (*a)[3], char *);
void smartInsert(char (*a)[3]);
void evil(char (*a)[3], char *);
void evilInsert(char (*a)[3]);
int main()
{
    char x, a[3][3] = {{49, 50, 51}, {52, 53, 54}, {55, 56, 57}};
    char name1[40];
    char name2[40];
    while (1)
    {
        system("cls");
        x = menu();
        fflush(stdin);
        switch (x)
        {
        case '3':
            player(a, name1, name2);
            break;
        case '2':
            evil(a, name1);
            break;
        case '1':
            smart(a, name1);
            break;
        case '4':
            printf("Thanks for playing !\n");
            getchar();
            exit(0);
        default:
            x = 0;
            printf("Invalid input, choose again : ");
            getchar();
            fflush(stdin);
        }
        if (x == 0)
            continue;
        printf("Want to play again (y/n)? ");
        x = getchar();
        fflush(stdin);
        if (x == 'y')
            rePrint(a);
        else
        {
            printf("Thanks for playing ! \n");
            getchar();
            break;
        }
    }
    return 0;
}
char menu()
{
    printf("\n\t\t\t\t\t Welcome To TIC-TAC-TOE Game!\n");
    printf("\n1. Want to play with Smart Computer");
    printf("\n2. Want to play with Evil Computer");
    printf("\n3. Want to play with Player");
    printf("\n4. Exit\n");
    printf("\nEnter your choice : ");
    return getchar();
}
void gameBoard(char (*a)[3])
{
    int i, j;
    printf("\n");
    printf("__|_____|_____|_____|__\n");
    printf("  |     |     |     |  ");
    printf("\n");
    for (i = 0; i < 3; i++)
    {
        printf("  | ");
        for (j = 0; j < 3; j++)
            printf(" %c  | ", a[i][j]);
        printf("\n");
        printf("__|_____|_____|_____|__");
        printf("\n");
        printf("  |     |     |     |  ");
        printf("\n");
    }
}
void player(char (*a)[3], char *b, char *c)
{
    printf("Player 1 name : ");
    fgets(b, 40, stdin);
    b[lenght(b)] = '\0';
    printf("Player 2 name : ");
    fgets(c, 40, stdin);
    c[lenght(c)] = '\0';
    char x, k = 1;
    system("cls");
    while (1)
    {
        printf("Player 1 : X\n");
        printf("Player 2 : O\n\n");
        gameBoard(a);
        x = checkWin(a);
        if (x == 1)
        {
            printf("\n\a%s Won !\n", b);
            return;
        }
        else if (x == 2)
        {
            printf("\n\a%s Won !\n", c);
            return;
        }
        else if (x == 3)
        {
            printf("\n\aGame Drawn !\n");
            return;
        }
        else if (x == -1)
            switch (k % 2)
            {
            case 1:
                printf("\n%s, Enter marking place : ", b);
                x = playerInsert(a, 'X', getchar());
                fflush(stdin);
                while (x != 0)
                {
                    x = playerInsert(a, 'X', getchar());
                    fflush(stdin);
                }
                system("cls");
                break;
            case 0:
                printf("\n%s, Enter marking place : ", c);
                x = playerInsert(a, 'O', getchar());
                fflush(stdin);
                while (x != 0)
                {
                    x = playerInsert(a, 'X', getchar());
                    fflush(stdin);
                }
                system("cls");
                fflush(stdin);
                break;
            }
        k++;
    }
}
void rePrint(char (*a)[3])
{
    int i, j;
    char x = '1';
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            a[i][j] = x++;
}
int playerInsert(char (*a)[3], char b, char c)
{
    char x = '1';
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (x == c)
            {
                if (a[i][j] >= 49 && a[i][j] <= 57)
                {
                    a[i][j] = b;
                    return 0;
                }
                printf("Invalid input, enter again : ");
                getchar();
                fflush(stdin);
                return 1;
            }
            x++;
        }
    }
}
void smart(char (*a)[3], char *b)
{
    printf("Enter Player name : ");
    fgets(b, 40, stdin);
    b[lenght(b)] = '\0';
    system("cls");
    char x;
    while (1)
    {
        printf("Player : X\n");
        printf("Computer : O\n\n");
        gameBoard(a);
        printf("\n\nEnter marking place : ");
        x = playerInsert(a, 'X', getchar());
        fflush(stdin);
        while (x)
        {
            x = playerInsert(a, 'X', getchar());
            fflush(stdin);
        }
        smartInsert(a);
        x = checkWin(a);
        if (x == 1)
        {
            system("cls");
            printf("Player : X\n");
            printf("Computer: O\n\n");
            gameBoard(a);
            printf("\n\aYou Won !\n");
            return;
        }
        else if (x == 2)
        {
            system("cls");
            printf("Player : X\n");
            printf("Computer : O\n\n");
            gameBoard(a);
            printf("\n\aYou Lose !\n");
            return;
        }
        else if (x == 3)
        {
            system("cls");
            printf("Player : X\n");
            printf("Computer : O\n\n");
            gameBoard(a);
            printf("\aGame Drawn !\n");
            return;
        }
        system("cls");
    }
}
void evil(char (*a)[3], char *b)
{
    printf("Enter player name : ");
    fgets(b, 40, stdin);
    b[lenght(b)] = '\0';
    system("cls");
    char x;
    while (1)
    {
        printf("Player : X\n");
        printf("Computer : O\n\n");
        gameBoard(a);
        printf("\n\nEnter marking place : ");
        x = playerInsert(a, 'X', getchar());
        fflush(stdin);
        while (x)
        {
            x = playerInsert(a, 'X', getchar());
            fflush(stdin);
        }
        evilInsert(a);
        x = checkWin(a);
        if (x == 1)
        {
            printf("\n\aYou Won\n");
            return;
        }
        else if (x == 2)
        {
            printf("\n\aYou Lose\n");
            return;
        }
        else if (x == 3)
        {
            printf("\n\aGame Drawn !\n");
            return;
        }
        system("cls");
    }
}
void evilInsert(char (*a)[3])
{
    int i, j, l, k = 0;
    int s = 0, r = 0, flag = 0;
    for (i = 0; i < 3; i++)
    {
        k = 0;
        s = 0;
        for (j = 0; j < 3; j++)
        {
            if (a[i][j] == 'X')
            {
                k++;
            }
            else if (a[i][j] >= 49 && a[i][j] <= 57)
            {
                s++;
                l = j;
            }
        }
        if (k == 2 && s == 1)
        {
            a[i][l] = 'O';
            flag = 1;
        }
    }
    for (i = 0; i < 3; i++)
    {
        k = 0;
        s = 0;
        for (j = 0; j < 3; j++)
        {
            if (a[j][i] == 'X')
            {
                k++;
            }
            else if (a[j][i] >= 49 && a[j][i] <= 57)
            {
                s++;
                r = j;
            }
        }
        if (k == 2 && s == 1)
        {
            a[r][i] = 'O';
            flag = 1;
        }
    }
    s = 0, k = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = i; j <= i; j++)
        {
            if (a[i][j] == 'X')
                k++;
            else if (a[i][j] >= 49 && a[i][j] <= 57)
            {
                s++;
                r = i;
                l = j;
            }
        }
    }
    if (k == 2 && s == 1)
    {
        a[r][l] = 'O';
        flag = 1;
    }
    s = 0, k = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = i; j <= i; j++)
        {
            if (a[i][2 - i] == 'X')
                k++;
            else if (a[i][2 - i] >= 49 && a[i][2 - i] <= 57)
            {
                s++;
                r = i;
                l = 2 - i;
            }
        }
    }
    if (k == 2 && s == 1)
    {
        a[r][l] = 'O';
        flag = 1;
    }
    if (flag == 0)
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (a[i][j] >= 49 && a[i][j] <= 57)
                {
                    a[i][j] = 'O';
                    return;
                }
            }
        }
}
void smartInsert(char (*a)[3])
{
    int i, j, l, k = 0;
    int s = 0, r = 0;
    for (i = 0; i < 3; i++)
    {
        k = 0;
        s = 0;
        for (j = 0; j < 3; j++)
        {
            if (a[i][j] == 'X')
            {
                k++;
            }
            else if (a[i][j] >= 49 && a[i][j] <= 57)
            {
                s++;
                l = j;
            }
        }
        if (k == 2 && s == 1)
        {
            a[i][l] = 'O';
            return;
        }
    }
    for (i = 0; i < 3; i++)
    {
        k = 0;
        s = 0;
        for (j = 0; j < 3; j++)
        {
            if (a[j][i] == 'X')
                k++;
            else if (a[j][i] >= 49 && a[j][i] <= 57)
            {
                s++;
                r = j;
            }
        }
        if (k == 2 && s == 1)
        {
            a[r][i] = 'O';
            return;
        }
    }
    s = 0, k = 0;
    for (i = 0; i < 3; i++)
    {

        for (j = i; j <= i; j++)
        {
            if (a[i][j] == 'X')
                k++;
            else if (a[i][j] >= 49 && a[i][j] <= 57)
            {
                s++;
                r = i;
                l = j;
            }
        }
    }
    if (k == 2 && s == 1)
    {
        a[r][l] = 'O';
        return;
    }
    s = 0, k = 0;
    for (i = 0; i < 3; i++)
    {

        for (j = i; j <= i; j++)
        {
            if (a[i][2 - i] == 'X')
                k++;
            else if (a[i][2 - i] >= 49 && a[i][2 - i] <= 57)
            {
                s++;
                r = i;
                l = 2 - i;
            }
        }
    }
    if (k == 2 && s == 1)
    {
        a[r][l] = 'O';
        return;
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (a[i][j] >= 49 && a[i][j] <= 57)
            {
                a[i][j] = 'O';
                return;
            }
        }
    }
}
int lenght(char *s)
{
    int i = 0;
    while (s[i] != '\0' && s[i] != '\n')
        i++;
    return i;
}
int checkWin(char (*a)[3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        if (a[i][0] == a[i][1] && a[i][1] == a[i][2])
        {
            if (a[i][0] == 'X')
                return 1;
            else if (a[i][0] == 'O')
                return 2;
        }
    }
    for (i = 0; i < 3; i++)
    {
        if (a[0][i] == a[1][i] && a[1][i] == a[2][i])
            if (a[0][i] == 'X')
                return 1;
            else if (a[0][i] == 'O')
                return 2;
    }
    if (a[0][0] == a[1][1] && a[1][1] == a[2][2])
    {
        if (a[0][0] == 'X')
            return 1;
        else if (a[0][0] == 'O')
            return 2;
    }
    if (a[0][2] == a[1][1] && a[1][1] == a[2][0])
    {
        if (a[1][1] == 'X')
            return 1;
        else if (a[1][1] == 'O')
            return 2;
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            if (a[i][j] >= 49 && a[i][j] <= 57)
                return -1;
    }
    return 3;
}