#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student
{
	int author_id;
	char author_name[30];
    char book_title[30];
	int ISBN_no;
    char publisher[30];
    int year;
	struct student *link;
}node;
node *header=NULL;
node *get_node()
{
	return((node *)malloc(sizeof(node)));
}
//=================insertion======================
void insert()
{
	int author_id,ISBN_no,year;
	char author_name[30],book_title[30],publisher[30];
	node *p;
	printf("Enter Author ID:");
    scanf(" %d",&author_id);
    printf("Author Name");
    scanf(" %s",&author_name);
    printf("Book Title");
    scanf(" %s",&book_title);
    printf("ISBN_no");
    scanf(" %d",&ISBN_no);
    printf("Publisher");
    scanf(" %s",&publisher);
    printf("Year");
	scanf(" %d",&year);
	p=get_node();
	p->author_id=author_id;
	p->ISBN_no=ISBN_no;
	p->year=year;
	strcpy(p->author_name,author_name);
	strcpy(p->book_title,book_title);
	strcpy(p->publisher,publisher);
	p->link=NULL;
	if(header==NULL)
		header=p;
	else
	{
		p->link=header;
		header=p;
	}
}
//=================deletion======================
void del()
{
	node *temp;
	if(header==NULL)
	{
		printf("Empty List\n");
		return;
	}
	else
	{
		temp=header;
		header=header->link;
		printf("The following record is deleted : %d %s %d\n",temp->author_id,temp->author_name,temp->book_title,temp->ISBN_no,temp->publisher,temp->year);
		free(temp);
	}
}
//=================display======================
void display()
{
	node *temp;
	printf("ID        Name         Book Title       ISBN_no        publisher        year\n");
	for(temp=header;temp!=NULL;temp=temp->link)
	printf("%-9d %-12s %-16s %-14d %-16s %d\n",temp->author_id,temp->author_name,temp->book_title,temp->ISBN_no,temp->publisher,temp->year);
}
//=================search======================
void search()
{
	int author_id;
	node *temp;
	printf("Enter the ID of author to be searched : ");
	scanf("%d",&author_id);
	for(temp=header;temp!=NULL;temp=temp->link)
	{
		if(author_id==temp->author_id)
		{
			printf("ID        Name         Book Title       ISBN_no        publisher        year\n");
			printf("%-9d %-12s %-16s %-14d %-16s %d\n",temp->author_id,temp->author_name,temp->book_title,temp->ISBN_no,temp->publisher,temp->year);
			return;
		}
	}
	printf("Author Record Not Found !!!\n");
}
//=================menu======================
void menu()
{
	int choice;
		
		printf("\nChoose :\n1 - Insert Author Record\n2 - Delete Author Record\n3 - Search Author Record\n4 - Display Author Records\nPress any other key to EXIT !\n");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1 : insert();break;
		case 2 : del();break;
		case 3 : search();break;
		case 4 : display();break;
		default : exit(0);break;
		}
}
//=================main function======================
int main()
{
	for(;;) 
	{
		menu();
	}
	return 0;
}

