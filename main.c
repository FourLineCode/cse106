#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

//Sets Cursor Co-ordinate in Console
COORD coordinate = {0, 0};
void setxy(int x, int y)
{
    coordinate.X = x;
    coordinate.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

//Generates a Random Directed Graph of Input Size
void generateArray(int size)
{
	system("cls");
	
	//Declaring 2D Matrix using Dynamic Allocation
	int **a;
	a = (int**) malloc(sizeof(int*) * size);
	for(int i=0; i<size; i++){
		a[i] = (int*) malloc(sizeof(int*) * size);
	}

	long start = clock();
	//Generating Graph
	long start1 = clock();
	srand(time(NULL));
	for(int i=0; i<size;i++){
		for(int j=0; j<size; j++){
			a[i][j] = rand() % 2;
		}
	}
	long end1 = clock();

	//Calculating Degree
	long start2 = clock();
	int in = 0, out = 0;
	for(int i=0; i<size;i++){
		for(int j=0; j<size; j++){
			if(a[j][i] == 1){
				in++;
			}
			if(a[i][j] == 1){
				out++;
			}
		}
	}
	long end2 = clock();

	long end = clock();

	//Printing Results
	setxy(10, 2);
	printf("Generated a Directed graph of %d vertices.\n", size);
	setxy(10, 3);
	printf("Generating time: %.0lf nanoseconds\n", ((double)(end1-start1)/CLOCKS_PER_SEC) * 1000000000);
	
	setxy(10, 5);
	printf("In Degree: %d\n", in);
	setxy(10, 6);
	printf("Out Degree: %d\n", out);
	setxy(10, 8);
	if(in == out){
		puts("Number of In-Degrees and Out-Degrees are Equal!");
	} else {
		puts("Number of In-Degrees and Out-Degrees are Not Equal!");
	}
	setxy(10, 10);
	printf("Computational time: %.0lf nanoseconds\n", ((double)(end2-start2)/CLOCKS_PER_SEC) * 1000000000);

	setxy(10, 12);
	printf("Full Execution time: %.0lf nanoseconds\n", ((double)(end-start)/CLOCKS_PER_SEC) * 1000000000);
	setxy(10, 13);
	printf("Press any key to continue ..");
	getch();
}

int main()
{
	begin:
	system("cls");
	//Initial program menu
	setxy(10, 2);
	puts("This program can generate a random Directed graph represented by Adjacency Matrix");
	setxy(10, 3);
	puts("Choose an option to generate a Directed graph - ");
	setxy(10, 5);
	puts("1. Generate a graph with 1000 vertices.");
	setxy(10, 7);
	puts("2. Generate a graph with 2000 vertices.");
	setxy(10, 9);
	puts("3. Generate a graph with 3000 vertices.");
	setxy(10, 11);
	puts("4. Generate a graph with 4000 vertices.");
	setxy(10, 13);
	puts("5. Generate a graph with 5000 vertices.");
	setxy(10, 15);
	puts("6. Generate a graph with specific vertices.");
	setxy(10, 17);
	puts("7. Exit.");

	setxy(10, 19);
	printf("Your choice > ");
	char res = getche();

	switch(res)
	{
		case '1':
		{
			generateArray(1000);
			goto begin;
			break;
		}
		case '2':
		{
			generateArray(2000);
			goto begin;
			break;
		}
		case '3':
		{
			generateArray(3000);
			goto begin;
			break;
		}
		case '4':
		{
			generateArray(4000);
			goto begin;
			break;
		}
		case '5':
		{
			generateArray(5000);
			goto begin;
			break;
		}
		case '6':
		{
			system("cls");
			setxy(10, 2);
			printf("Enter number of vertices: ");
			int num;
			scanf("%d", &num);
			generateArray(num);
			goto begin;
			break;
		}
		case '7':
		{
			system("cls");
			setxy(10, 2);
			puts("Program exited successfully!");
			puts("");
			return 0;
			break;
		}
		default:
		{
			system("cls");
			setxy(10, 2);
			puts("Invalid Response!");
			setxy(10, 4);
			printf("Press any key to continue ..");
			getch();
			goto begin;
			break;
		}
	}

	return 0;
}