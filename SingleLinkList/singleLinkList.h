#include <stdbool.h>

typedef char string[50];

typedef struct Node{
	void* data;
	struct Node *next;
}Node;

typedef struct List{
	Node* header;
	int length;
}List;

List* createList();
bool insertNode(List* list , int index , void* data);
bool deleteNode(List* list , int index);
