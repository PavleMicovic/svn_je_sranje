#include "matrix.h"
void strcat_c (char *str, char c)
  {
    for (;*str;str++);
    *str++ = c;
    *str++ = 0;
  }
void FillMatrix(matrix_elem* matrix)
{
    int_fast8_t i;
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
}
void PrintMatrix(matrix_elem* matrix, list* list)
{
	uint_fast8_t i;
    uint_fast8_t j;
	list_element* current=list->head;
	char buff[SOLUTION_MAX_SIZE+1];
	for(i=0;i<SOLUTION_MAX_SIZE*SOLUTION_MAX_SIZE;i++)
		{
			if((matrix+((i/SOLUTION_MAX_SIZE)*SOLUTION_MAX_SIZE+i%SOLUTION_MAX_SIZE))->bold==true)
			{
			    /*while(strcmp(buff, current->solution)!=0)
                {
                    if (strlen(buff)<SOLUTION_MAX_SIZE)
                        strcat_c(buff, matrix[(i/SOLUTION_MAX_SIZE)*SOLUTION_MAX_SIZE+i%SOLUTION_MAX_SIZE].elem);
                    else
                    {
                        current=current->next;
                        buff[0]='\0';
                    }
                }*/
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 2);
                //for (j=0;j<strlen(buff);j++)
                //{
                    printf("%c\t", matrix[(i/SOLUTION_MAX_SIZE)*SOLUTION_MAX_SIZE+i%SOLUTION_MAX_SIZE].elem);
                    //i++;
                //}
                SetConsoleTextAttribute(hConsole, 7);
            }
			else
				printf("%c\t", matrix[(i/SOLUTION_MAX_SIZE)*SOLUTION_MAX_SIZE+i%SOLUTION_MAX_SIZE].elem);
			if(i%SOLUTION_MAX_SIZE==SOLUTION_MAX_SIZE-1)
			{
				printf("\n");
			}
		}
	printf("\n");
}

void SolveMatrix(matrix_elem* matrix, list* list)
{
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
                    len=strlen(current->solution);
                    for(k=0;k<len;k++)
                        matrix[i*SOLUTION_MAX_SIZE+j-k].bold=true;
                }
                if (strstr(buff_reverse, current->solution)!=NULL)
                {
                    for (m=j;m>-1;m--)
                        if (matrix[i*SOLUTION_MAX_SIZE+m].elem==current->solution[0] && matrix[i*SOLUTION_MAX_SIZE+m-1].elem==current->solution[1])
                            break;
                    len=strlen(current->solution);
                    for(k=0;k<len;k++)
                        matrix[i*SOLUTION_MAX_SIZE+m-k].bold=true;
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
        for (m=0;m<strlen(buff);m++)
        {
            buff_reverse[m]=buff[strlen(buff)-m-1];
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
    //direction 3/4 up and down
    buff[0]='\0';
    buff_reverse[0]='\0';
    for (j=0;j<SOLUTION_MAX_SIZE;j++)
    {
        for (i=0;i<SOLUTION_MAX_SIZE;i++)
        {
            current=list->head;
            strcat_c(buff, matrix[i*SOLUTION_MAX_SIZE+j].elem);
            if(i==SOLUTION_MAX_SIZE-1)
            {
                for (k=0;k<strlen(buff);k++)
                {
                    buff_reverse[k]=buff[strlen(buff)-k-1];
                }
                buff_reverse[k]='\0';
                while ((strstr(buff, current->solution)==NULL) && strstr(buff_reverse, current->solution)==NULL)
                {
                    if(current->next==NULL)
                        break;
                    current=current->next;
                }
                if (strstr(buff, current->solution)!=NULL)
                {
                    len=strlen(current->solution);
                    for(k=0;k<len;k++)
                        matrix[(i-k)*SOLUTION_MAX_SIZE+j].bold=true;
                }
                if (strstr(buff_reverse, current->solution)!=NULL)
                {
                    for (m=j;m>-1;m--)
                        if (matrix[i*SOLUTION_MAX_SIZE+m].elem==current->solution[0] && matrix[i*SOLUTION_MAX_SIZE+m-1].elem==current->solution[1])
                            break;
                    len=strlen(current->solution);
                    for(k=0;k<len;k++)
                        matrix[(i-k)*SOLUTION_MAX_SIZE+m].bold=true;
                }
                        buff[0]='\0';
                        buff_reverse[0]='\0';
                    }
                }
    }
    //direction 4/4 other diagonal
    for (i=0;i<SOLUTION_MAX_SIZE;i++)
        for(j=0;j<SOLUTION_MAX_SIZE;j++)
    {
        k=i;
        len=j;
        buff[0]='\0';
        buff_reverse[0]='\0';
        while (k!=0 && len!=SOLUTION_MAX_SIZE)
        {
            strcat_c(buff, matrix[k*SOLUTION_MAX_SIZE+len].elem);
            k--;
            len++;
        }
        for (m=0;m<strlen(buff);m++)
        {
            buff_reverse[m]=buff[strlen(buff)-m-1];
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
            for(m=0;m<strlen(current->solution);m++)
                matrix[k*SOLUTION_MAX_SIZE+len+m*SOLUTION_MAX_SIZE+m].bold=true;
        }
        if (strstr(buff_reverse, current->solution)!=NULL)
        {
            for(m=0;m<strlen(current->solution);m++)
                matrix[k*SOLUTION_MAX_SIZE+len+m*SOLUTION_MAX_SIZE+m].bold=true;
        }
        buff[0]='\0';
        buff_reverse[0]='\0';
    }
    printf("Resenje osmosmerke:\t");
    for (i=0;i<SOLUTION_MAX_SIZE;i++)
        for (j=0;j<SOLUTION_MAX_SIZE;j++)
        {
            if (matrix[i*SOLUTION_MAX_SIZE+j].bold==false)
                printf("%c", matrix[i*SOLUTION_MAX_SIZE+j]);
        }
    printf("\n");
}
