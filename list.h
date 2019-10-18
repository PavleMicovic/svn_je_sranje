#ifndef LIST_H_
#define LIST_H_
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define SOLUTION_MAX_SIZE 3

typedef struct list_element list_element;

typedef struct list_element{
	char solution[SOLUTION_MAX_SIZE];
	list_element* next;
} list_element;

typedef struct list{
	list_element* head;
} list;

void CreateList(list* list);
void AddElement(list* list, char* solution);
void RemoveElement(list* list, list_element* element);
void DestroyList(list* list);
void PrintList(list* list);
list_element* CreateElement(char* solution);
#endif
