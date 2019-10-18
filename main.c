#include "list.h"
#include "matrix.h"

int main()
{
	//testiranje liste
	list list1;
	CreateList(&list1);/*
	AddElement(&list1, "pera");
	AddElement(&list1, "mika");
	AddElement(&list1, "djoka");
	PrintList(&list1);
	list_element* element=CreateElement("pera");
	RemoveElement(&list1, element);
	PrintList(&list1);
	DestroyList(&list1);
	PrintList(&list1);*/
	//testiranje matrice
	AddElement(&list1, "tip");
	AddElement(&list1, "top");
	matrix_elem* matrix=(matrix_elem*)malloc(sizeof(SOLUTION_MAX_SIZE*SOLUTION_MAX_SIZE));
	FillMatrix(matrix);
	PrintMatrix(matrix);
	SolveMatrix(matrix, &list1);
	PrintMatrix(matrix);
	return 0;
}
