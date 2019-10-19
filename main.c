#include "matrix.h"

int main()
{
	list list1;
	CreateList(&list1);
	AddElement(&list1, "tip");
	AddElement(&list1, "top");
	matrix_elem* matrix=(matrix_elem*)malloc(sizeof(SOLUTION_MAX_SIZE*SOLUTION_MAX_SIZE));
	FillMatrix(matrix);
	PrintMatrix(matrix);
	SolveMatrix(matrix, &list1);
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
    return 0;
}
