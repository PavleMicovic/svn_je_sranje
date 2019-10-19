#include "matrix.h"
void strcat_c (char *str, char c)
  {
<<<<<<< HEAD
    for (;*str;str++);
=======
    for (;*str;str++); // note the terminating semicolon here.
>>>>>>> 25d7ca1ec269e8e25b513f2ace9479c0ad89af4d
    *str++ = c;
    *str++ = 0;
  }
void FillMatrix(matrix_elem* matrix)
{
<<<<<<< HEAD
    int_fast8_t i;
    /*matrix->elem='t';
    (matrix+1)->elem='a';
    (matrix+2)->elem='h';
    (matrix+3)->elem='p';
    (matrix+4)->elem='e';
    (matrix+5)->elem='r';
    (matrix+6)->elem='s';
    (matrix+7)->elem='t';
    (matrix+8)->elem='p';*/

    matrix->elem='C';
    (matrix+1)->elem='T';
	(matrix+2)->elem='A';
	(matrix+3)->elem='R';
	(matrix+4)->elem='D';
	(matrix+5)->elem='A';
	(matrix+6)->elem='V';
	(matrix+7)->elem='K';

	(matrix+8)->elem='V';
	(matrix+9)->elem='I';
	(matrix+10)->elem='S';
	(matrix+11)->elem='R';
	(matrix+12)->elem='O';
	(matrix+13)->elem='S';
	(matrix+14)->elem='A';
	(matrix+15)->elem='M';

	(matrix+16)->elem='E';
	(matrix+17)->elem='I';
	(matrix+18)->elem='R';
	(matrix+19)->elem='R';
	(matrix+20)->elem='E';
	(matrix+21)->elem='T';
	(matrix+22)->elem='K';
	(matrix+23)->elem='I';

	(matrix+24)->elem='P';
	(matrix+25)->elem='N';
	(matrix+26)->elem='K';
	(matrix+27)->elem='I';
	(matrix+28)->elem='P';
	(matrix+29)->elem='J';
	(matrix+30)->elem='U';
	(matrix+31)->elem='E';

	(matrix+32)->elem='D';
	(matrix+33)->elem='R';
	(matrix+34)->elem='I';
	(matrix+35)->elem='I';
	(matrix+36)->elem='L';
	(matrix+37)->elem='S';
	(matrix+38)->elem='M';
	(matrix+39)->elem='A';

	(matrix+40)->elem='I';
	(matrix+41)->elem='E';
	(matrix+42)->elem='E';
	(matrix+43)->elem='G';
	(matrix+44)->elem='Z';
	(matrix+45)->elem='I';
	(matrix+46)->elem='K';
	(matrix+47)->elem='S';

	(matrix+48)->elem='J';
	(matrix+49)->elem='C';
	(matrix+50)->elem='A';
	(matrix+51)->elem='M';
	(matrix+52)->elem='M';
	(matrix+53)->elem='E';
	(matrix+54)->elem='C';
	(matrix+55)->elem='I';

	(matrix+56)->elem='O';
	(matrix+57)->elem='V';
	(matrix+58)->elem='O';
	(matrix+59)->elem='L';
	(matrix+60)->elem='S';
	(matrix+61)->elem='A';
	(matrix+62)->elem='J';
	(matrix+63)->elem='A';
	for(i=0;i<SOLUTION_MAX_SIZE*SOLUTION_MAX_SIZE;i++)
        (matrix+i)->bold=false;
=======
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
>>>>>>> 25d7ca1ec269e8e25b513f2ace9479c0ad89af4d
}
void PrintMatrix(matrix_elem* matrix)
{
	uint_fast8_t i;
	for(i=0;i<SOLUTION_MAX_SIZE*SOLUTION_MAX_SIZE;i++)
		{
<<<<<<< HEAD
			if((matrix+((i/SOLUTION_MAX_SIZE)*SOLUTION_MAX_SIZE+i%SOLUTION_MAX_SIZE))->bold==true)
			{
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 2);
                printf("%c\t", matrix[(i/SOLUTION_MAX_SIZE)*SOLUTION_MAX_SIZE+i%SOLUTION_MAX_SIZE].elem);
                SetConsoleTextAttribute(hConsole, 7);
            }
			else
				printf("%c\t", matrix[(i/SOLUTION_MAX_SIZE)*SOLUTION_MAX_SIZE+i%SOLUTION_MAX_SIZE].elem);
			if(i%SOLUTION_MAX_SIZE==SOLUTION_MAX_SIZE-1)
=======
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
>>>>>>> 25d7ca1ec269e8e25b513f2ace9479c0ad89af4d
			{
				printf("\n");
			}
		}
	printf("\n");
}

void SolveMatrix(matrix_elem* matrix, list* list)
{
<<<<<<< HEAD
    int_fast8_t i;
    int_fast8_t j;
    int_fast8_t k;
    int_fast8_t len;
    int_fast8_t m;
    list_element* current=list->head;
	char buff[SOLUTION_MAX_SIZE+1];
	char buff_reverse[SOLUTION_MAX_SIZE+1];
	buff[0]='\0';
	buff_reverse[0]='\0';
	//direction 1/4 right and left
    for (i=0;i<SOLUTION_MAX_SIZE;i++)
    {
        for (j=0;j<SOLUTION_MAX_SIZE;j++)
        {
            current=list->head;
            strcat_c(buff, matrix[i*SOLUTION_MAX_SIZE+j].elem);
            if(j==SOLUTION_MAX_SIZE-1)
            {
                for (k=0;k<SOLUTION_MAX_SIZE;k++)
                    buff_reverse[k]=buff[SOLUTION_MAX_SIZE-k-1];
                buff_reverse[k]='\0';
                while ((strstr(buff, current->solution)==NULL) && strstr(buff_reverse, current->solution)==NULL)
                {
                    if(current->next==NULL)
                        break;
                    current=current->next;
                }
                if (strstr(buff, current->solution)!=NULL)
                {
                    len=strlen(current->solution)-1;
                    for(k=0;k<len;k++)
                        matrix[i*SOLUTION_MAX_SIZE+j-k].bold=true;
                }
                if (strstr(buff_reverse, current->solution)!=NULL)
                {
                    len=strlen(current->solution);
                    for(k=0;k<len;k++)
                        matrix[i*SOLUTION_MAX_SIZE+j-k].bold=true;
                }
                buff[0]='\0';
                buff_reverse[0]='\0';
            }
        }
    }
	//direction 2/4 diagonal top left to bottom right and bottom right to top left
	for (i=0;i<SOLUTION_MAX_SIZE;i++)
        for(j=0;j<SOLUTION_MAX_SIZE;j++)
    {
        k=i;
        len=j;
        buff[0]='\0';
        buff_reverse[0]='\0';
        while (k!=SOLUTION_MAX_SIZE && len!=SOLUTION_MAX_SIZE)
        {
            strcat_c(buff, matrix[k*SOLUTION_MAX_SIZE+len].elem);
            k++;
            len++;
        }
        for (m=0;m<SOLUTION_MAX_SIZE;m++)
        {
            buff_reverse[m]=buff[SOLUTION_MAX_SIZE-m-1];
        }
        buff_reverse[m]='\0';
        current=list->head;
        while ((strstr(buff, current->solution)==NULL) && strstr(buff_reverse, current->solution)==NULL)
        {
            if(current->next==NULL)
                break;
            current=current->next;
        }
        if (strstr(buff, current->solution)!=NULL)
        {
            for(m=0;m<strlen(current->solution)+1;m++)
                matrix[k*SOLUTION_MAX_SIZE+len-m*SOLUTION_MAX_SIZE-m].bold=true;
        }
        if (strstr(buff_reverse, current->solution)!=NULL)
        {
            for(m=0;m<strlen(current->solution)+1;m++)
                matrix[k*SOLUTION_MAX_SIZE+len-m*SOLUTION_MAX_SIZE-m].bold=true;
        }
        buff[0]='\0';
        buff_reverse[0]='\0';
    }
=======
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

>>>>>>> 25d7ca1ec269e8e25b513f2ace9479c0ad89af4d
}
