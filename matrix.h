#ifndef MATRIX_H_
#define MATRIX_H_
#include "list.h"
#include <inttypes.h>

typedef struct matrix_elem
{
    char elem;
    bool bold;
} matrix_elem;
void FillMatrix(matrix_elem* matrix);
void PrintMatrix(matrix_elem* matrix);
void SolveMatrix(matrix_elem* matrix, list* list);
#endif
