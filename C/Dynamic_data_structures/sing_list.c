#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* Create(int data) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->next = NULL;
}
void show_lst(Node *lst) {
	while (lst != NULL) {
		printf("%d\t%#lu\n", lst->data, lst);
		lst = lst->next;
	}
	printf("------\n");
}
void add_end(Node *lst, int data) {
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->next = NULL;
	tmp->data = data;
	Node* p = lst;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = tmp;
}
Node* add_start(Node* lst, int data) {
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->next = lst;
	return tmp;
}
Node* reverse(Node* lst) {
	Node* save_branch = NULL;
	Node* tmp = NULL;

	while (lst != NULL) {
		save_brabch = lst->next;
		lst->next = tmp;
		tmp = lst;
		lst = save_branch;
	}
	return tmp;
}
void main() {
	Node *lst = Create(0);
	add_end(lst, 1);
	add_end(lst, 2);
	add_end(lst, 3);
	add_end(lst, 4);
	add_end(lst, 5);
	add_end(lst, 6);
	add_end(lst, 7);
	add_end(lst, 8);
	add_end(lst, 9);
	lst = add_start(lst, -1);
	show_lst(lst);
	lst = reverse(lst);
	show_lst(lst);
}
