#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define null NULL
#define MAX_STRING 250
#define MAX_LINE 1000
#define INF 99999

typedef long long ll;

typedef char String[MAX_STRING];

//---------------------------------------------GLOBAL VARIABLES-------------------------------------------------------------------------
int V = 0; // VARIABLE TO STORE THE NUMBER OF VERTICES

// avl tree functions in orded to use it as a SET
typedef struct Node *ptr;

typedef struct Node
{

    String cityName; // key
    int indx;        // index of the course in the graph
    ptr left;
    ptr right;
    int height; // Balance information

} Node;

int height(ptr P)
{
    if (P == NULL)
    {
        return -1;
    }
    else
    {
        return P->height;
    }
}

int max(int Lhs, int Rhs)
{
    return Lhs > Rhs ? Lhs : Rhs;
}

ptr singleRotateWithLeft(ptr K2)
{
    ptr K1;

    K1 = K2->left;
    K2->left = K1->right;
    K1->right = K2;

    K2->height = max(height(K2->left), height(K2->right)) + 1;
    K1->height = max(height(K1->left), K2->height) + 1;

    return K1; /* New root */
}

ptr singleRotateWithRight(ptr K1)
{
    ptr K2;

    K2 = K1->right;
    K1->right = K2->left;
    K2->left = K1;

    K1->height = max(height(K1->left), height(K1->right)) + 1;
    K2->height = max(height(K2->right), K1->height) + 1;

    return K2; /* New root */
}

/* This function can be called only if K3 has a left */
/* child and K3's left child has a right child */
/* Do the left-right double rotation */
/* Update heights, then return new root */

ptr doubleRotateWithLeft(ptr K3)
{
    /* Rotate between K1 and K2 */
    K3->left = singleRotateWithRight(K3->left);

    /* Rotate between K3 and K2 */
    return singleRotateWithLeft(K3);
}
/* END */

/* This function can be called only if K1 has a right */
/* child and K1's right child has a left child */
/* Do the right-left double rotation */
/* Update heights, then return new root */

ptr doubleRotateWithRight(ptr K1)
{
    /* Rotate between K3 and K2 */
    K1->right = singleRotateWithLeft(K1->right);

    /* Rotate between K1 and K2 */
    return singleRotateWithRight(K1);
}

ptr insert(Node treeNode, ptr T)
{
    if (T == NULL)
    {
        /* Create and return a one-listNode tree */
        T = malloc(sizeof(Node));
        if (T == NULL)
        {
            printf("Out of space!!!");
        }

        else
        {
            *T = treeNode;
            T->height = 0;
            T->left = T->right = NULL;
        }
    }
    else if (strcmp(treeNode.cityName, T->cityName) < 0)
    {
        T->left = insert(treeNode, T->left);
        if (height(T->left) - height(T->right) == 2)
        {
            if (strcmp(treeNode.cityName, T->left->cityName) < 0)
            {
                T = singleRotateWithLeft(T);
            }
            else
            {
                T = doubleRotateWithLeft(T);
            }
        }
    }
    else if (strcmp(treeNode.cityName, T->cityName) > 0)
    {

        T->right = insert(treeNode, T->right);
        if (height(T->right) - height(T->left) == 2)
        {
            if (strcmp(treeNode.cityName, T->right->cityName) > 0)
            {
                T = singleRotateWithRight(T);
            }
            else
            {
                T = doubleRotateWithRight(T);
            }
        }
    }
    else
    {

        T->height = max(height(T->left), height(T->right)) + 1;
        return T;
    }
    /* Else cityName is in the tree already; we'll do nothing */

    T->height = max(height(T->left), height(T->right)) + 1;
    return T;
}
int getIndex(String cityName, ptr T)
{
    if (T == NULL)
    {
        return -1;
    }

    if (strcmp(cityName, T->cityName) < 0)
    {
        return getIndex(cityName, T->left);
    }
    else if (strcmp(cityName, T->cityName) > 0)
    {
        return getIndex(cityName, T->right);
    }
    else
    {
        return T->indx;
    }
}

ptr SET = null;

int cnt = 0;

int getVsize(ptr t, String CITITIES)
{

    int dummy = 0;
    if (t != NULL)
    {
        dummy = getVsize(t->left, CITITIES);
        t->indx = cnt;
        strcat(CITITIES, t->cityName);
        strcat(CITITIES, "\t");

        cnt++;

        V++;
        dummy = getVsize(t->right, CITITIES);
    }
    //    printf("\n");
    return V;
}

void line();

void welcome();

void menu();

void reset();

void art();

void readV();

void assignToGraph(int Graph[V][V]); // assigns the values to the graph

void dijkstra(int Graph[V][V], int src, String allCities, int dist[V], bool visited[V], int parent[V], String cityArray[V]);

void displayRoute(int parent[], int dist[], String strSrc, String strDest,
                  String cityArray[V]); // display the route from source to destination

//---------------------------------------------DRIVER FUNCTION -------------------------------------------------------------------------

int main()
{

    readV();
    int tmpV = 0;
    String allCities = "";
    int dummy = getVsize(SET, allCities);
    String cityArray[V];

    int dist[V];
    bool visited[V];
    int parent[V];

    int Graph[V][V]; // Graph[i][j] = x is the edge from i to j
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            Graph[i][j] = INF;
        }
    }

    welcome();
    int selection;
    String srcCity;
    String destCity;
    int srcIndx;

    bool selected = false;
    bool selected2 = false;
    while (true)
    {
        menu();
        printf("CITIES TO TRAVERSE : \n");
        printf("%s\n", allCities);
        scanf("%d", &selection);

        selected = true;

        assignToGraph(Graph);
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                if (i == j)
                {
                    Graph[i][j] = 0; // no edge between same city
                }
            }
        }

        if (selection == 1)
        {
            selected2 = true;

            if (!selected)
            {
                printf("Please load graph first\n");
                continue;
            }
            printf("PLEASE ENTER SOURCE CITY\n");
            scanf("%s", srcCity);
            srcIndx = getIndex(srcCity, SET); // gets the index of the city in the tree

            if (srcIndx == -1)
            {

                printf("\nSOURCE CITY NOT FOUND\n");
                reset();
                continue;
            }
            //            printf("%s\n", allCities);
            printf("shortest paths from %s to : \n", srcCity);
            //            printf("all in main %s\n", allCities); WHAT IS LEFT AT THE END IS AKKA

            dijkstra(Graph, srcIndx, allCities, dist, visited, parent,
                     cityArray); // dijkstra algorithm to find the shortest path from source to destination city
        }

        else if (selection == 2)
        {
            if (!selected2)
            {
                printf("Please choose source destination f first\n");
                continue;
            }

            if (!selected)
            {
                printf("Please load graph first\n");
                continue;
            }

            printf("PLEASE ENTER DESTINATION CITY\n");
            scanf("%s", destCity);
            int destIndx = getIndex(destCity, SET);
            if (destIndx == -1)
            {

                printf("\nDESTINATION CITY NOT FOUND\n");
                reset();
                continue;
            }
            displayRoute(parent, dist, srcCity, destCity, cityArray);
        }

        else if (selection == 3)
        { // note: we auto save to the file each time in 3rd selection number 4 just exits the program
            // do stuff

            art();
            break;
        }

        else
        {

            printf("Invalid Selection\n");
            reset();
            continue;
        }
    }
}

void reset()
{
    printf("\033[0m");
}

void line()
{
    printf("================================================================\n");
    reset();
}

void welcome()
{

    printf("                 _                              \n"
           "                | |                             \n"
           " __      __ ___ | |  ___  ___   _ __ ___    ___ \n"
           " \\ \\ /\\ / // _ \\| | / __|/ _ \\ | '_ ` _ \\  / _ \\\n"
           "  \\ V  V /|  __/| || (__| (_) || | | | | ||  __/\n"
           "   \\_/\\_/  \\___||_| \\___|\\___/ |_| |_| |_| \\___|\n"
           "                                                \n"
           "                                                \n");

    reset();
}

void menu()
{
    line();

    printf(
        "1. Enter source city:\n"
        "2. Enter destination city:\n"
        "3. Exit:\n");
    reset();
    line();
}

void art()
{
    printf("THANK YOU COME AGAIN  !!!!\n");
}

void readV()
{

    FILE *in = fopen("cities.txt", "r");
    if (in == NULL)
    {

        printf("Error opening file\n");
        reset();
        exit(1);
    }

    String city1;
    String city2;
    String cost;

    while (fscanf(in, "%s%s%s", city1, city2, cost) != EOF)
    {
        ptr tmpNode1 = malloc(sizeof(Node));
        strcpy(tmpNode1->cityName, city1);

        ptr tmpNode2 = malloc(sizeof(Node));
        strcpy(tmpNode2->cityName, city2);

        SET = insert(*tmpNode1, SET);
        SET = insert(*tmpNode2, SET);
    }

    fclose(in);
}

void assignToGraph(int Graph[V][V])
{
    FILE *in = fopen("cities.txt", "r");
    String city1, city2;
    String strCost;

    char *num;

    while (fscanf(in, "%s%s%s", city1, city2, strCost) != EOF)
    {

        num = strtok(strCost, "[Kk][Mm]"); // capital K or k for kilometers and M or m for miters
        int cost = atoi(num);

        //        printf("cost : %d\n", cost);

        Graph[getIndex(city1, SET)][getIndex(city2, SET)] = cost;
        Graph[getIndex(city2, SET)][getIndex(city1, SET)] = cost;
    }

    fclose(in);
}

void dijkstra(int Graph[V][V], int src, String allCities, int dist[V], bool visited[V], int parent[V], String cityArray[])
{
    int i, j;
    int min;
    int next;

    for (i = 0; i <
                V;
         i++)
    { // initialize the distance array and visited array to infinity and false respectively for all vertices
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;    // source node is always 0 distance from itself
    parent[src] = -1; // parent of source is set to -1 since source is the parent of itself

    for (i = 0; i < V - 1; i++)
    { // run for V-1 times since we have already visited source node once in the beginning

        // iterates over Dist array to find the minimum distance vertex available so far
        min = INF;
        for (j = 0; j <
                    V;
             j++)
        { // run for all vertices to find the minimum distance vertex from the set of unvisited vertices and mark it as visited
            if (visited[j] == false && dist[j] <= min)
            {
                min = dist[j];
                next = j; // next is the vertex with minimum distance from the set of unvisited vertices
            }
        }

        visited[next] = true; // the minimum distance vertex is marked as visited

        for (j = 0; j < V; j++)
        {
            // update the distance array by comparing the distance of the vertex from the set of unvisited vertices with the distance of the vertex from the set of visited vertices
            // comparing edges from the next vertex to all of its edges
            // j represents the  index of the edges to 'next' in the Graph
            if (visited[j] == false && Graph[next][j] && dist[next] != INF && dist[next] + Graph[next][j] < dist[j])
            {
                parent[j] = next;
                dist[j] = dist[next] + Graph[next][j];
            }

        } // update the distance of all the vertices adjacent to the minimum distance vertex from the set of unvisited vertices
    }

    int z = 0;

    //    printf("tst all cit  %s\n", allCities);

    char *tmp = null;
    //    printf("tmp %s\n", tmp);

    //    printf("all %s\n", allCities);

    tmp = strtok(allCities, "\t"); // split the string by tabs
    while (tmp != NULL)
    {
        //        printf("BOOOO2%s\n", tmp);

        printf("%s:", tmp);
        printf("\t%d Km", dist[z]);
        printf("\n");
        strcpy(cityArray[z], tmp);
        tmp = strtok(NULL, "\t");
        z++;
    }
    printf("\n");
    strcpy(allCities, ""); // clear the string

    for (int k = 0; k < V; ++k)
    {
        strcat(allCities,
               cityArray[k]);    // concatenate the cities to the string again cuz it changes when we split it by tabs
        strcat(allCities, "\t"); // add a tab after each city
    }
}

void displayRoute(int *parent, int *dist, String srcCity, String destCity, String cityArray[])
{
    // display the route from source to destination city using the parent array and distance array from dijkstra algorithm

    FILE *out = fopen("shortest_path.txt", "a"); // append to the file
    if (out == null)
    {

        printf("COULDN'T OPEN THE OUTPUT FILE\n"); // if the file couldn't be opened print an error message and exit the program
        reset();
    }

    int parentVertix = parent[getIndex(destCity, SET)]; // get the parent of the destination city from the parent array and set it to parentVertix variable (the parent of the destination city)
                                                        //    printf("parent vert = %d\n",parentVertix);
    printf("%s", destCity);
    fprintf(out, "%s", destCity);

    int d1;
    d1 = getIndex(destCity, SET);
    int total = 0;
    while (parentVertix !=
           -1)
    { // while the parent of the destination city is not -1 ( the destination city is not the source city)
        total += abs(dist[d1] - dist[parentVertix]);

        printf("  (%dKm)<-  %s ", abs(dist[d1] - dist[parentVertix]), cityArray[parentVertix]); //
        fprintf(out, "  (%dKm)<-  %s ", abs(dist[d1] - dist[parentVertix]), cityArray[parentVertix]);

        d1 = parentVertix;
        parentVertix = parent[parentVertix]; // get the parent of the parent city and set it to parentVertix variable (the parent of the parent city)
    }
    printf("\n");

    printf("total destination : %dKm \n", total);

    fprintf(out, "\t| (total destination : %dKm) \n", total);
    fclose(out);
}
