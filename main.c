#include "matrix.h"

int main()
{
	list list1;
	CreateList(&list1);
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
	matrix_elem* matrix=(matrix_elem*)malloc(sizeof(SOLUTION_MAX_SIZE*SOLUTION_MAX_SIZE));
	FillMatrix(matrix);
	PrintMatrix(matrix, &list1);
	SolveMatrix(matrix, &list1);
	PrintMatrix(matrix, &list1);
    return 0;
}
