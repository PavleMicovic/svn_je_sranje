#include "matrix.h"
void strcat_c (char *str, char c)
  {
    for (;*str;str++); // note the terminating semicolon here.
    *str++ = c;
    *str++ = 0;
  }
void FillMatrix(matrix_elem* matrix)
{
	matrix->elem='t';
	matrix->bold=false;
	(matrix+1)->elem='i';
	(matrix+1)->bold=false;
	(matrix+2)->elem='p';
	(matrix+2)->bold=false;
	(matrix+3)->elem='p';
	(matrix+3)->bold=false;
	(matrix+4)->elem='o';
	(matrix+4)->bold=false;
	(matrix+5)->elem='r';
	(matrix+5)->bold=false;
	(matrix+6)->elem='s';
	(matrix+6)->bold=false;
	(matrix+7)->elem='t';
	(matrix+7)->bold=false;
	(matrix+8)->elem='p';
	(matrix+8)->bold=false;
}
void PrintMatrix(matrix_elem* matrix)
{
	int_least8_t i, j;
	for(i=0;i<SOLUTION_MAX_SIZE;i++)
		for(j=0;j<SOLUTION_MAX_SIZE;j++)
		{
			if((matrix+i*SOLUTION_MAX_SIZE+j)->bold==true)
			{
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 2);
                printf("%c\t", matrix[i*SOLUTION_MAX_SIZE+j].elem);
                SetConsoleTextAttribute(hConsole, 7);
            }
			else
				printf("%c\t", matrix[i*SOLUTION_MAX_SIZE+j].elem);
			if(j==SOLUTION_MAX_SIZE-1)
			{
				printf("\n");
			}
		}
	printf("\n");
}

void SolveMatrix(matrix_elem* matrix, list* list)
{
    int_least8_t i;
    int_least8_t j;
    int_least8_t k;
    int_least8_t len;
    list_element* current=list->head;
	char buff[SOLUTION_MAX_SIZE+1];
	buff[0]='\0';
	//direction 1/8 right
    for(i=0;i<SOLUTION_MAX_SIZE;i++)
		for(j=0;j<SOLUTION_MAX_SIZE;j++)
			{
				strcat_c(buff, matrix[i*SOLUTION_MAX_SIZE+j].elem);
				if(j==SOLUTION_MAX_SIZE-1)
				{
					strcat_c(buff, '\0');
					while((strcmp(buff, current->solution)!=0))
					{
						if(current->next==NULL)
							break;
						current=current->next;
					}
					if(strcmp(buff, current->solution)==0)
					{
						len=strlen(current->solution);
						for(k=0;k<len;k++)
							matrix[i*SOLUTION_MAX_SIZE+j-k].bold=true;
					}
					buff[0]='\0';
				}
			}
	//direction 2/8 diagonal top left to bottom right
	/*for(i=0;i<SOLUTION_MAX_SIZE, i++)
        for (j=0;j<SOLUTION_MAX_SIZE;j++)
        {
            int_least8_t k, l;
            if(j-i>0)
            {
                for(k=i;k<)
            }
        }*/

}
