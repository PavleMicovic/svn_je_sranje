#include "matrix.h"

void FillMatrix(char* matrix, list*list)
{
	int_least8_t i, j;
	char tmp='a';
	for(i=0;i<SOLUTION_MAX_SIZE;i++)
		for(j=0;j<SOLUTION_MAX_SIZE;j++)
		{
			matrix[i*SOLUTION_MAX_SIZE+j]=tmp;
			tmp++;
		}
}
void PrintMatrix(char* matrix)
{
	int_least8_t i, j;
	for(i=0;i<SOLUTION_MAX_SIZE;i++)
		for(j=0;j<SOLUTION_MAX_SIZE;j++)
		{
			printf("%c\t", matrix[i*SOLUTION_MAX_SIZE+j]);
			if(j==SOLUTION_MAX_SIZE-1)
			{
				printf("\n");
			}
		}
}
