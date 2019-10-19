#include "matrix.h"

int main()
{
	list list1;
	CreateList(&list1);
<<<<<<< HEAD
	AddElement(&list1, "AUTOR");
	AddElement(&list1, "ENIGMA");
	AddElement(&list1, "JEZIK");
	AddElement(&list1, "KVADRAT");
	AddElement(&list1, "OSAM");
	AddElement(&list1, "REC");
	AddElement(&list1, "SLOVO");
	AddElement(&list1, "SMER");
	AddElement(&list1, "SMJER");
	AddElement(&list1, "SRPSKI");
	AddElement(&list1, "CIRILICA");
//	AddElement(&list1, "hat");
//	AddElement(&list1, "pet");
=======
	AddElement(&list1, "tip");
	AddElement(&list1, "top");
>>>>>>> 25d7ca1ec269e8e25b513f2ace9479c0ad89af4d
	matrix_elem* matrix=(matrix_elem*)malloc(sizeof(SOLUTION_MAX_SIZE*SOLUTION_MAX_SIZE));
	FillMatrix(matrix);
	PrintMatrix(matrix);
	SolveMatrix(matrix, &list1);
<<<<<<< HEAD
	PrintMatrix(matrix);
=======
	PrintMatrix(matrix);
	int niz[25];
	int i;
	for (i=0;i<25;i++)
        niz[i]=i;
    for (i=0;i<9;i++)
    {
        if(i%3==0)
            printf("\n");
        printf("%d\t", niz[i/3+1+i%3]);
    }
>>>>>>> 25d7ca1ec269e8e25b513f2ace9479c0ad89af4d
    return 0;
}
