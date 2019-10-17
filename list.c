#include "list.h"

void CreateList(list* list)
{
	list->head=NULL;
}
list_element* CreateElement(char* solution)
{
	list_element* element=(list_element*)malloc(sizeof(list_element));
	strcpy(element->solution, solution);
	element->next=NULL;
	return element;
}
void AddElement(list* list, char* solution)
{
	list_element* element=CreateElement(solution);
	list_element* current;
	if(list->head==NULL)
	{
		list->head=element;
	}
	else
	{
		current=list->head;
		while(current->next!=NULL)
			current=current->next;
		current->next=element;
	}
}
void RemoveElement(list* list, list_element* element)
{
	list_element* current;

	if(list->head==NULL)
	{
		printf("List is empty\n");
		exit(1);
	}
	if(strcmp(list->head->solution, element->solution)==0)
	{
		list->head=list->head->next;
		free(element);
	}
	else{
		current=list->head;
		while(strcmp(current->solution, element->solution)!=0)
			current=current->next;
		current->next=element->next;
		free(element);
	}

}
void DestroyList(list* list)
{
	list_element* current=list->head;
	list_element* next;
	while(current!=NULL)
	{
		next=current->next;
		free(current);
		current=next;
	}
	list->head=NULL;
}

void PrintList(list* list)
{
	if(list->head==NULL)
	{
		printf("Lista je prazna");
		exit(1);
	}
	list_element* current=list->head;
	printf("Stampanje resenja:\n");
	while(current!=NULL)
	{
		printf("%s\t", current->solution);
		current=current->next;
	}
	printf("\n");
}


