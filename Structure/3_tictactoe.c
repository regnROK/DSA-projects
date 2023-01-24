#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 9

typedef struct mat
{   char arr[max];
    char mark1;
    char mark2;

}mt;
 mt s;
void green () {
  printf("\033[0;32m");
}
void yellow () {
  printf("\033[0;33m");
}
//---------------------Draw tic tac toe board--------------------------
void draw_board(void)
{
    printf("\t 1 | 2 | 3 ");
    printf(" \t %c | %c | %c \n", s.arr[0], s.arr[1], s.arr[2]);
    printf(" \t---|---|--- ");
    printf(" \t---|---|---\n");
    printf("\t 4 | 5 | 6 ");
    printf(" \t %c | %c | %c \n", s.arr[3], s.arr[4], s.arr[5]);
    printf(" \t---|---|---");
    printf(" \t---|---|---\n");
    printf("\t 7 | 8 | 9 ");
    printf(" \t %c | %c | %c \n", s.arr[6], s.arr[7], s.arr[8]);
}
//---------------------Chack for winner--------------------------
int check_win()
{
    int i, c=0;

    for (i = 0; i <= 6; i += 3)
        if (s.arr[i] == s.arr[i + 1] && s.arr[i] == s.arr[i + 2] && s.arr[i] != ' ')
            return 1;
    for (i = 0; i < 3; i++)
        if (s.arr[i] == s.arr[i + 3] && s.arr[i] == s.arr[i + 6] && s.arr[i] != ' ')
            return 1;
    if (s.arr[0] == s.arr[4] && s.arr[0] == s.arr[8] && s.arr[0] != ' ')
        return 1;
    else if (s.arr[2] == s.arr[4] && s.arr[2] == s.arr[6] && s.arr[2] != ' ')
        return 1;
    for (i = 0; i < 9; i++)
    {
        if (s.arr[i] != ' ')
            c++;
    }
    if (c == 9)
    {
        return 0;
    }
    return -1;
}
//---------------------Player 1's move--------------------------
void get_player1_move()
{
    int t;
    green();
    printf("Enter position of player 1's move: ");
    scanf("%d", &t);
    if (1 <= t && t <= 9)
    {
        if ((s.arr[t - 1] != s.mark1) && (s.arr[t - 1] != s.mark2))
            s.arr[t - 1] = s.mark1;
        else
        {
            printf("Invalid move, try again.\n");
            get_player1_move();
        }
    }
    else
    {
        printf("Invalid move, try again.\n");
        get_player1_move();
    }
}
//---------------------Player 2's move--------------------------

void get_player2_move()
{   yellow();
    int t;
    printf("Enter position of player 2's move: ");
    scanf("%d", &t);
    if (1 <= t && t <= 9)
    {
        if ((s.arr[t - 1] != s.mark1) && (s.arr[t - 1] != s.mark2))
            s.arr[t - 1] = s.mark2;
        else
        {
            printf("Invalid move, try again.\n");
            get_player2_move();
        }
    }
    else
    {
        printf("Invalid move, try again.\n");
        get_player2_move();
    }
}

int main()
{
    s.mark1 = 'x';
    s.mark2 = '0';
    int j;
    int choice;
    int i = 1;
    int k;
    
    system("color FC");
    do
    {       for (i = 0; i < 9; i++)
            s.arr[i] = ' ';
        
        printf("\n-:  Welcome to TIC TAC TOE game  :-\n");
        printf("\n\n\tPlayer 1 ='x'");
        printf("\n\tPlayer 2 ='0'");

        printf("\n\n\n=> Start the Game :)\n");
        draw_board();
        do
        {
            get_player1_move();
            system("color FC");
            draw_board();
            j = check_win();
            if (j == 0)
            {
                printf("\n=> Match is draw !! <=\n");
                break;
            }
            if (j == 1)
            {
                printf("\n=> Player 1 is winner !!! <=\n");
                break;
            }
            get_player2_move();
            system("color FC");
            draw_board();
            j = check_win();
            if (j == 1)
            {
                printf("\n=> Player 2 is winner !!! <=\n");
                break;
            }

        } while (j = -1);
        while(1){
            printf("\n\nIF YOU WANT TO PLAY AGAIN ENTER '1' OR FOR QUITE THE GAME ENTER '0' : ");
            scanf("%d", &k);
            if(k==1 || k==0){
                break;
            }
            else{
                printf(" Invalid Option, Enter Again");
            }
        }
    } while (k == 1);
    return 0;
}
