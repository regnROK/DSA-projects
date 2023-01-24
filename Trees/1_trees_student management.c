// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// create node:
struct Node
{
	int id;
	char fn[20];
	char ln[20];
	char zc[5];
	double s;
	struct Node *left;
	struct Node *right;
};

FILE *fptr;
int records;
void printMenu();
struct Node *insert(struct Node *root, int id, char fn[20], char ln[20], double s, char zc[5]);
struct Node *getNewNode(int id, char fn[20], char ln[20], double s, char zc[5]);
void printDB(struct Node *root);
void searchZip(struct Node *root, char zc[20]);
void searchRange(struct Node *root, double min, double max);
double findMedian(struct Node *root);
void sortScores(double *s, int n);
void aboveMedian(struct Node *root, double med);
int count;
int aboveMed = 0;
double medVal;
double *scores;
int main()
{
	int iRec, id, i, choice;
	double minScore, maxScore;
	char fn[20];
	char ln[20];
	char zc[5];
	double s, medVal;
	struct Node *root = NULL;
	fptr = fopen("data.txt", "w");
	if (fptr == NULL)
	{
		printf("file is empty");
		return 0;
	}
	printf("WELCOME TO THE STUDENT RECORD MANAGER 100 V 1.0! \n");
	printf("Please indicate the number of student records you want to enter (min 1): \n");
	scanf("%d", &iRec);
	if (iRec < 1)
	{
		printf("You must enter atleast one ... terminating. \n");
		return 0;
	}

	printf("Please enter the values for each student (id(1000-11000) firstName lastName score zipcode) pressing enter after each: \n");

	for (i = 0; i < iRec; i++)
	{

		// add record

		printf("%d > \n", i + 1);
		fprintf(fptr, "\nSTUDENT INDEX NO.:%d", i + 1);

		printf("Enter student id(1000-11000) = ");
		scanf("%d", &id);
		fprintf(fptr, "\nid:%d\n", id);

		printf("Enter first name = ");
		scanf("%s", &fn);
		fprintf(fptr, "first name:%s\n", fn);

		printf("Enter last name = ");
		scanf("%s", &ln);
		fprintf(fptr, "last name:%s\n", ln);

		printf("Enter the score student achieved in previous year = ");
		scanf("%lf", &s);
		fprintf(fptr, "score:%lf\n", s);

		printf("Enter zipcode = ");
		scanf("%s", &zc);
		fprintf(fptr, "zipcode:%s\n", zc);

		root = insert(root, id, fn, ln, s, zc);
	}

	do
	{

		printMenu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printDB(root);
			break;
		case 2:

			iRec++;
			printf("Please enter the values for the student (id(1000-11000) firstName lastName score zipcode) pressing enter after each: \n");
			printf("%d > \n", i + 1);
			fprintf(fptr, "\nSTUDENT INDEX NO.:%d\n", i + 1);
			i++;

			printf("Enter student id(1000-11000) = ");
			scanf("%d", &id);
			fprintf(fptr, "id:%d\n", id);

			printf("Enter first name = ");
			scanf("%s", &fn);
			fprintf(fptr, "first name:%s\n", fn);

			printf("Enter last name = ");
			scanf("%s", &ln);
			fprintf(fptr, "last name:%s\n", ln);

			printf("Enter the score student achieved in previous year = ");
			scanf("%lf", &s);
			fprintf(fptr, "score:%lf\n", s);

			printf("Enter zipcode = ");
			scanf("%s", &zc);
			fprintf(fptr, "zipcode:%s\n", zc);

			root = insert(root, id, fn, ln, s, zc);
			break;
		case 3:
			printf("Please enter the zip code you would like to search for: \n");
			scanf("%s", &zc);
			searchZip(root, zc);
			break;
		case 4:
			printf("Please enter the score range you would like to search from(min max): \n");
			scanf("%lf %lf", &minScore, &maxScore);
			searchRange(root, minScore, maxScore);
			break;
		case 5:
			medVal = findMedian(root);
			aboveMedian(root, medVal);
			printf(" > MEDIAN SCORE: %0.3lf\n > STUDENTS ABOVE: %d\n", medVal, iRec);
			count = 0;
			break;
		case 0:
			return 0;
		}
	}
	while (1);
	// fclose(fptr);
	return 0;
	// search
	/*
	int num;
	scanf("%d",&num);
	if(search(root,))
	*/
}

// Print user menu

void printMenu()
{
	printf("\n\tMain Menu\t\n"
		   "============================\n"
		   " > Print records (press 1) \n"
		   " > Add a new record (press 2) \n"
		   " > Search by zip code (press 3)\n"
		   " > Search by score range (press 4) \n"
		   " > Find median score (press 5) \n"
		   " > Exit the program (press 0)\n"
		   "============================\n"
		   "Please select an option: ");
}

struct Node *insert(struct Node *root, int id, char fn[20], char ln[20], double s, char zc[5])
{
	if (root == NULL)
	{
		root = getNewNode(id, fn, ln, s, zc);
	}

	else if (id <= root->id)
	{
		// tree is not empty
		root->left = insert(root->left, id, fn, ln, s, zc);
		// will go back through, root will be null then will get a new node and put it in
	}

	else
	{    // means data > root->data
		// tree is not empty
		root->right = insert(root->right, id, fn, ln, s, zc);
	}

	return root;
}

struct Node *getNewNode(int id, char fn[20], char ln[20], double s, char zc[5])
{

	// Create root node using malloc and a temp variable
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->id = id;
	strcpy(temp->fn, fn);
	strcpy(temp->ln, ln);
	temp->s = s;
	strcpy(temp->zc, zc);
	temp->left = temp->right = NULL;
	records++;

	return temp;
}

void printDB(struct Node *root)
{

	if (root)
	{
		printf("> %d      || %s %s           || %0.2lf       || %s        \n", root->id, root->fn, root->ln, root->s, root->zc);
		printDB(root->left);
		printDB(root->right);
	}
}

void searchZip(struct Node *root, char zc[20])
{
	// first check if it is empty
	if (root == NULL)
	{
		// empty list
	}

	else
	{
		if (strcmp(root->zc, zc) == 0)
		{
			// value found
			printf("> %d      || %s %s           || %0.2lf       || %s        \n", root->id, root->fn, root->ln, root->s, root->zc);
		}
		else
		{
			printf("\nenter valid zipcode\n");
		}

		if (zc < root->zc)
		{
			// left
			searchZip(root->left, zc);
		}

		else
		{
			searchZip(root->right, zc);
		}
	}
}

void searchRange(struct Node *root, double min, double max)
{

	if (root)
	{

		if (root->s <= max && root->s >= min)
		{
			printf("> %d      || %s %s           || %0.2lf       || %s        \n", root->id, root->fn, root->ln, root->s, root->zc);
			searchRange(root->left, min, max);
			searchRange(root->right, min, max);
		}
		else
		{
			printf("this range is invalid\n");
		}
	}
}

double findMedian(struct Node *root)
{

	if (count == 0)
	scores = malloc(records);

	// create dynamic array

	if (root)
	{

		scores[count] = root->s;
		count++;
		findMedian(root->left);
		findMedian(root->right);
		sortScores(scores, records);
		medVal = records / 2;
		medVal = scores[(int)medVal];
		return medVal;
	}
}

// Recursive bubble sort for score

void sortScores(double *s, int n)
{
	int i;
	double tempF;
	if (n == 1)

		return;

	for (i = 0; i < n - 1; i++)
	{

		if (s[i + 1] > s[i])
		{
			tempF = *(s + i + 1);
		    *(s + i + 1) = *(s + i);
			*(s + i) = tempF;
		}
	}
	sortScores(s, n - 1);
}
void aboveMedian(struct Node *root, double med)
{
	if (root)
	{
		if (root->s > med)
		aboveMed++;
		aboveMedian(root->left, med);
		aboveMedian(root->right, med);
	}
}