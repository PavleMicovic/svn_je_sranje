#ifndef LIST_H_
#define LIST_H_
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <stdio.h>
#include <windows.h>

#define SOLUTION_MAX_SIZE 8
#define BOLDGREEN   "\033[1m\033[32m"
=======
#include <stdio.h>
#include <windows.h>

#define SOLUTION_MAX_SIZE 3
#define BOLDGREEN   "\033[1m\033[32m"
>>>>>>> 25d7ca1ec269e8e25b513f2ace9479c0ad89af4d
#define RESET   "\033[0m"

typedef struct list_element{
	char solution[SOLUTION_MAX_SIZE];
	struct list_element* next;
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
