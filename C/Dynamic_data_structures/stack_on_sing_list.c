#include <stdio.h>
#include <stdlib.h>

#define STACK_OVERFLOW -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY -102


typedef int T;
typedef struct Node {
	T data;
	struct Node* next;
} Node;

void push(Node** head, T value) {
	Node* tmp = malloc(sizeof(Node));
	if (tmp == NULL) {
		exit(STACK_UNDERFLOW);
	}
	tmp->data = value;
	tmp->next = *head;
	*head = tmp;
}
void showStack(const Node* node) {
	while (node) {
		printf("%d ", node->data);
		node = node->next;
	}
}

void main() {
	Node* lup = NULL;
	push(&lup, 3);
	push(&lup, 4);
	showStack(lup);



}
