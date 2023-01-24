#include <stdio.h>
#include <stdlib.h>
#define max_yr 9999
#define min_yr 1800
#define MAX_lux 50
#define MAX_sup 40
#define MAX_del 30

void insert();
void delete ();
void display();
int deluxe[MAX_lux];
int suite[MAX_sup];
int presuite[MAX_del];
int rear = -1;
int front = -1;
void green () {
  printf("\033[0;32m");
}
void yellow () {
  printf("\033[0;33m");
}
int isleap(int y)
{
    if ((y % 4 == 0) && (y % 100 != 0) && (y % 400 == 0))
        return 1;
    else
        return 0;
}
// Function to check the date is valid or not
int datevalid(int d, int m, int y)
{
    if (y < min_yr || y > max_yr)
        return 0;
    if (m < 1 || m > 12)
        return 0;
    if (d < 1 || d > 31)
        return 0;
    // Now we will check date according to month
    if (m == 2)
    {
        if (isleap(y))
        {
            if (d <= 29)
                return 1;
            else
                return 0;
        }
    }
    // April, June, September and November are with 30 days
    if (m == 4 || m == 6 || m == 9 || m == 11)
        if (d <= 30)
            return 1;
        else
            return 0;
    return 1;
}

// Function for the transaction
int transact(int am)
{
    long long bid;
    int pass;
    int cho;
L0:
    yellow();
    printf("How would you like to pay\n");
    printf("1)NetBanking\n");
    printf("2)Credit/Debit Card\n");
    printf("3)UPI\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &cho);

    if (cho == 1)
    {
    L1:
        printf("Enter your Login ID(Login ID should be of 16 digit):");
        scanf("%lld", &bid);
        if (bid > 1e16 || bid < 1e15) // bid should be of 16 numbers
        {
            printf("Error, please try Again!!\n");
            goto L1;
            return 0;
        }
    L2:
        printf("Enter your password(Password should be of 4 digit):");
        scanf("%d", &pass);
        if (pass > 10000 || pass < 1000) // pass should be of 4 numbers
        {
            printf("Error, please try Again!!\n");
            goto L2;
            return 0;
        }
        printf("Rs%d amount debited\n", am);
        printf("SUCCESS!!\n");
    }

    else if (cho == 2)
    {
        long long cardno;
        int expm, expy, cvv;
    L3:
        printf("\nEnter your Card number(Card number should be of 16 digit):");
        scanf("\n%lld", &cardno);
        if (cardno > 1e16 || cardno < 1e15) // cardno should be of 16 numbers
        {
            printf("\nError, please try Again!!\n");
            goto L3;
            return 0;
        }
    L4:
        printf("\nExpiry date(mm yy):");
        scanf("\n%d %d", &expm, &expy);
        if (expm < 01 || expm > 12) // month should be less than 12
        {
            printf("\nError, please try Again!!\n");
            goto L4;
            return 0;
        }
        if (expy < 22 || expy > 99) // year should be less than 99 and greater than 22
        {
            printf("\nError, please try Again!!\n");
            goto L4;
            return 0;
        }
    L5:
        printf("\nCVV(CVV should be of 3 digit):");
        scanf("\n%d", &cvv);
        if (cvv > 1000 || cvv < 100) // cvv should be of 3 numbers
        {
            printf("\nError, please try Again!!\n");
            goto L5;
            return 0;
        }
        printf("\nRs%d amount debited\n", am);
        printf("\nSUCCESS!!\n");
    }

    else if (cho == 3)
    {
        long long uid;
        int upin;
    L6:
        printf("\nUPI ID(UPI ID should be of 12 digit):");
        scanf("\n%lld", &uid);
        if (uid > 1e12 || uid < 1e11) // uid should be of 12 numbers
        {
            printf("\nError\n");
            goto L6;
            return 0;
        }
        printf("\nUPI PIN(UPI PIN should be of 4 digit):");
        scanf("\n%d", &upin);
        if (upin > 10000 || upin < 1000) // upin should be of 4 numbers
        {
            printf("\nError\n");
            goto L6;
            return 0;
        }
        printf("\nRs%d amount debited\n", am);
        printf("\nSUCCESS!!\n");
    }
    else
    {
        printf("\nYou've entered the wrong number!!\n");
        goto L0;
        return 0;
    }
}
// Function for delux room
int delroom()
{
    yellow();
    int dd, dd1, mm, mm1, yy, yy1;
    int frch = 0, frto = 0, nor;

    printf("\nCost : Rs 8500 per night\n");

    printf("\nFROM\n");
    printf("\nDD:");
    scanf("\n%d", &dd);
    printf("\nMM:");
    scanf("\n%d", &mm);
    printf("\nYYYY:");
    scanf("\n%d", &yy);

    printf("\nTO\n");
    printf("\nDD:");
    scanf("\n%d", &dd1);
    printf("\nMM:");
    scanf("\n%d", &mm1);
    printf("\nYYYY:");
    scanf("\n%d", &yy1);

    int nod = dd1 - dd;
    int booid;
    booid = 10001 + (dd * 100) + (mm * 1000);

    if (datevalid(dd, mm, yy))
    {
        printf("\nHow many rooms would you like to book:");
        scanf("\n%d", &nor);

        transact(nod * nor * 8500);
        printf("\nYour Booking  ID is: %d", booid);
    }
    else
    {
        printf("\nDate is invalid\n");
    }
    insert(delroom, MAX_del, booid);
}

// Function for suite room
int suiroom()
{
    yellow();
    int dd, dd1, mm, mm1, yy, yy1;
    int frch = 0, frto = 0, nor;

    printf("\nCost : Rs 13400 per night\n");

    printf("\nFROM\n");
    printf("\nDD:");
    scanf("\n%d", &dd);
    printf("\nMM:");
    scanf("\n%d", &mm);
    printf("\nYYYY:");
    scanf("\n%d", &yy);

    printf("\nTO\n");
    printf("\nDD:");
    scanf("\n%d", &dd1);
    printf("\nMM:");
    scanf("\n%d", &mm1);
    printf("\nYYYY:");
    scanf("\n%d", &yy1);

    int nod = dd1 - dd;
    int booid;

    booid = 50001 + (dd * 100) + (mm * 1000);

    if (datevalid(dd, mm, yy))
    {
        printf("\nHow many rooms would you like to book:");
        scanf("\n%d", &nor);

        transact(nod * nor * 13400);
        printf("\nYour Booking  ID is: %d", booid);
    }
    else
    {
        printf("\nDate is invalid\n");
    }
    insert(delroom, MAX_lux, booid);
}

// Function for premium suite
int susuiroom()
{
    yellow();
    int dd, dd1, mm, mm1, yy, yy1;
    int frch = 0, frto = 0, nor;

    printf("\nCost : Rs 15000 per night\n");

    printf("\nFROM\n");
    printf("\nDD:");
    scanf("\n%d", &dd);
    printf("\nMM:");
    scanf("\n%d", &mm);
    printf("\nYYYY:");
    scanf("\n%d", &yy);

    printf("\nTO\n");
    printf("\nDD:");
    scanf("\n%d", &dd1);
    printf("\nMM:");
    scanf("\n%d", &mm1);
    printf("\nYYYY:");
    scanf("\n%d", &yy1);

    int nod = dd1 - dd;
    int booid;
    booid = 30001 + (dd * 100) + (mm * 1000);

    if (datevalid(dd, mm, yy))
    {
        printf("\nHow many rooms would you like to book:");
        scanf("\n%d", &nor);

        if (nod < 0)
        {
            nod = -nod;
        }

        transact(nod * nor * 15000);
        printf("\nYour Booking  ID is: %d", booid);
    }
    else
    {
        printf("\nDate is invalid\n");
    }
    insert(delroom, MAX_sup, booid);
}
// This function is called for cancellation of room
void cancel()
{
    yellow();
    int i;
    printf("\nEnter your Booking ID:");
    scanf("\n%d", &i);
    if (i > 10000 && i < 30000)
    {
        delete (deluxe);
    }
    else if (i > 30000 && i < 50000)
    {
        delete (suite);
    }
    else if (i > 50000)
    {
        delete (presuite);
    }
}
// function for recreational activities
int recact()
{
    int cho;
    printf("\nThe list of all the recreational activities for a day are");
    printf("\n1)Mountain Trek     1.30hour     Rs300");
    printf("\n2)Archery           1.00hour     Rs450");
    printf("\n3)Heritage Walk     0.45hour     Rs150");
    printf("\nEnter:");
    scanf("%d", &cho);

    if (cho == 1)
    {
        transact(300);
    }
    else if (cho == 2)
    {
        transact(450);
    }
    else if (cho == 3)
    {
        transact(150);
    }
    else
    {
        printf("\nInvalid Input");
    }
}
int main()
{
    green();
    // system("color DF");
    int choice;
    int roomChoice;

    system("cls");
    printf("<Welcome To The Sky Rise>");

    printf("\n\n\n\n The services provided by us are: ");

    printf("\n1.Booking Rooms: ");
    printf("\n2.Cancellation of the rooms");
    printf("\n3.Recreational Activities ");
    printf("\n4.Quit");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);

    // switch case for selection
    switch (choice)
    {
    case (1):
        system("cls");
    I1:
        system("cls");
        printf("\n<==== The Sky Rise====>");
        printf("\n\n\tRoom Booking\n\n\n\n");
        printf("\nDifferent Types Of Rooms Present Are: ");
        printf("\n1.Deluxe");
        printf("\n2.Suite ");
        printf("\n3.Premium Suite");
        printf("\n\nEnter your choice: ");
        scanf("%d", &roomChoice);

        switch (roomChoice)
        {
        case (1):
            delroom();
            break;
        case (2):
            suiroom();
            break;
        case (3):
            susuiroom();
            break;
        default:
            printf("\nPlease Enter a valid input!");
            goto I1;
            break;
        }
        break;
    case (2):
        cancel();
        break;

    case (3):
        recact();
        break;
    case (4):
        exit(1);

    default:
        printf("\nPlease Enter a valid input!");
        break;
    }
    return 0;
}
// enqueue operation
void insert(int *queue_array, int max, int i)
{
    int item;
    if (rear == max - 1)
        printf("Queue Overflow \n");
    else
    {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        queue_array[rear] = i;
    }
}
// dequeue operation
void delete (int *queue_array)
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow \n");
        return;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
}
// display operation
void display(int *queue_array)
{
    int i;
    if (front == -1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}