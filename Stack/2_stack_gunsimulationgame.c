#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 20

struct Stack
{   int top;     // number of bullets in stack
    int health;  // health of enemy
    int a[MAX];  // array of magzine //1 if bullet present // 0 if no bullet
    int magsize; // magzine size of the gun
};
typedef struct Stack stack;
stack s;
// ---------------------FUNCTIONS-------------------------
void push(int);
void pop();
void choice();
int peek();
void pistol();
void rifal();
void sniper();
void green () {
  printf("\033[0;32m");
}
//-----------------------MAIN----------------------------------
int main()
{
    
    green();
    system("color 4F");
    printf("\n");
    printf("SHOOTING STIMULATION GAME");
    printf("\n");
    choice();
    return 0;
}

//-----------------------STACK OPERATIONS----------------------------------
void push(int x) // relodes bullet in magzine
{
    if (s.top >= (s.magsize - 1))
    {
        printf("Magazine is already full,can't add more ammo!\n");
    }
    else
    {
        for (int i = 0; i < x; i++)
        {
            s.a[++s.top] = 1;
        }
        printf("%d Bullet loading into magazine....\n loaded\n", s.top + 1);
    }
}
void pop() // removes bullet whne shooted
{
    if (s.top < 0)
    {
        printf("Magazine is empty, can't shoot!");
    }
    else
    {
        s.a[s.top--];
    }
}
int peek() // check if magzine is empty or not
{
    if (s.top < 0)
    {
        printf("Magazine is empty\n");
        return 0;
    }
    else
    {
        int x = s.a[s.top];
        return x;
    }
}
//---------------------// enter choice of gun //------------------------------------
void choice() 
{   for (int i = 0; i < 20; i++)
    {
        s.a[i] == 0;
    }
    s.top = -1;
    s.health = 100;
    char p;
    printf("Press '1' if you want to try pistol! \n");
    printf("Press '2' if you want to try sniper!\n");
    printf("Press '3' if you want to try rifal!\n");
    printf("Press '4' if you want to exit the game!\n");
    printf("Enter your choice = ");
    scanf(" %c", &p);
    if (p == '1')
    {
        pistol();
    }
    else if (p == '3')
    {
        rifal();
    }
    else if (p == '2')
    {
        sniper();
    }
    else if (p == '4')
    {
        exit(0);
    }
    else
    {
        printf("Invalid choice!! enter again\n");
        choice();
    }
}
void pistol() // pistol is choosen to shoot
{
    while (1)
    {
        char p;
        s.magsize = 6;
        printf("\n");
        printf("\n");
        int S = peek();
        printf("Press '1' if you want to reload whole magazine!\n");
        printf("Press '2' if you want to add 1 ammo in magazine!\n");
        printf("Press '3' if you want to shoot!\n");
        printf("Enter '4' to change weapon\n");
        scanf(" %c", &p);
        if (p == '1')
        {
            if (S < s.magsize)
            {
                push(s.magsize - S); // push the remaining bullets into the magzine.
            }
            else
            {
                printf("Magazine is already full,can't add more ammo!\n");
            }
        }
        else if (p == '2')
        {
            int S = peek();
            if (S < s.magsize - 1)
            {
                push(1); // push 1 bullet into the magzine
            }
            else
            {
                printf("Magazine is already full,can't add more ammo!\n");
            }
        }
        else if (p == '3')
        {
            if (s.health > 0)
            {
                if (s.top > -1)
                {
                    printf("Bullet fired !!\n");
                    pop(); // bullet shooted
                    s.health = s.health - 10;
                    printf("Enemy health remaining = %d\n", s.health);// health of enemy remaining
                    if (s.health == 0)
                    {
                        printf("Enemy killed !! ,no need to shoot further\n");
                    } 
                }
                else
                {
                    printf("Magazine is empty, can't shoot!\n");
                }
            }
            else
            {
                printf("Enemy killed !! ,no need to shoot further\n");
                exit(0);
            }
        }
        else if (p == '4')
        {
            choice(); // change gun
        }
        else
        {
            printf("Invalid choice! enter again");
            pistol();
        }
    }
}
void rifal() // rifal is choosen to shoot
{
    while (1)
    {
        char p;
        s.magsize = 20;
        printf("\n");
        int S = peek();
        printf("Press 1 if you want to reload whole magazine!\n");
        printf("Press 2 if you want to add 1 round in magazine!\n");
        printf("Press 3 if you want to shoot 1 round!\n");
        printf("Enter 4 to change weapon\n");
        scanf(" %c", &p);
        if (p == '1')
        {
            if (S < s.magsize)
            {
                push(s.magsize - S);
            }
        }
        else if (p == '2')
        {
            int S = peek();
            if (S < s.magsize - 1)
            {
                push(1);
            }
            else
            {
                printf("Magazine is already full,can't add more ammo!\n");
            }
        }
        else if (p == '3')
        {
            if (s.health > 0)
            {
                if (s.top > -1)
                {
                    printf("Bullet fired !!\n");
                    pop();
                    s.health = s.health - 30;
                    if (s.health > 0)
                    {
                        printf("Enemy health remaining = %d", s.health);
                    }
                    else
                    {
                        printf("Enemy health remaining = 0\n");
                        printf("Enemy killed !! ,no need to shoot further\n");
                        exit(0);
                    }
                }
                else
                {
                    printf("Magazine is empty, can't shoot!\n");
                }
            }
            else
            {
                printf("Enemy killed !! ,no need to shoot further\n");
                exit(0);
            }
        }
        else if (p == '4')
        {
            choice();
        }
        else
        {   printf("Invalid choice! enter again");
            rifal();
        }
    }
}

void sniper() // sniper is choosen to shoot
{
    while (1)
    {
        char p;
        s.magsize = 2;
        printf("\n");
        int S = peek();
        printf("Press 1 if you want to reload whole magazine!\n");
        printf("Press 2 if you want to add 1 ammo in magazine!\n");
        printf("Press 3 if you want to shoot!\n");
        printf("Enter 4 to change gun\n");
        scanf(" %c", &p);
        if (p == '1')
        {
            if (S < s.magsize)
            {
                push(s.magsize - S);
            }
            else
            {
                printf("Magazine is already full,can't add more ammo!\n");
            }
        }
        else if (p == '2')
        {
            int S = peek();
            if (S < s.magsize)
            {
                push(1);
            }
            else
            {
                printf("Magazine is already full,can't add more ammo!\n");
            }
        }
        else if (p == '3')
        {

            if (s.top == 0)
            {
                printf("Magazine is empty, can't shoot!\n");
            }
            else
            {
                printf("Head Shot!!!\nEnemy Has Been Finished!!,no need to shoot further\n");
                exit(0);
            }
        }
        else if (p == '4')
        {
            choice();
        }
        else
        {
            printf("Invalid choice! enter again");
            sniper();
        }
    }
}
