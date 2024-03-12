#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int value;
	struct Node* next;
} Node;

void add_element_end(int value, Node* lis) {
	// узел который будет добавляться в конец
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = NULL;

	Node* p = lis;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = tmp;
}
Node* add_element_start(int value1, Node* lis) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value1;
	//printf("%d\n", tmp->value);
	tmp->next = lis;
	return(tmp);
}
void show_elements(Node* lis) {
	int count = 0;
	while (lis != NULL) {
		Node* p = lis;
		lis = lis->next;
		printf("%d) %d\n", count, p->value);
		count++;
	}
}
Node* add_element_n_position(int value, Node* lis, int position) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	
	Node* p = lis;
	int count = 0;
	// p - 2 and count 1
	while ((p->next) != NULL && count < position - 1) {
		p = p->next; // p - 11
		count++;     // count 11
	}


	tmp->next = p->next; // новый элемент указывает на 12 - тую ноду
	p->next = tmp;  // 12 - тая нода указывает на новый элемент
	return lis;
}
Node* remove_element(int nmber, Node* lis) {
	Node* tmp = lis;
	Node* p = NULL;
	if (lis == NULL) {
		return NULL;
	}
	while (tmp && tmp->value != nmber) {
		p = tmp; 
		tmp = tmp->next;
	}
	
	if (tmp == lis) {
		return tmp->next;
	}
	
	if (!tmp) {
		return lis;
	}

	p->next = tmp->next;
	
	free(tmp);
	return lis;
}
void free_list(Node* lis) {
	while (lis != NULL) {
		Node* ptr = lis;
		lis = lis->next;
		free(ptr);
	}
}
void main() {
	Node* lis = (Node*)malloc(sizeof(Node));
	lis->value = 777;
	lis->next = NULL;
	//printf("%#x\n", lis->next);
	lis = add_element_start(13, lis);
	
	add_element_end(1, lis);
	add_element_end(2, lis);
	
	lis = add_element_start(13, lis);
	
	add_element_end(3, lis);
	add_element_end(4, lis);
	add_element_end(5, lis);
	add_element_end(6, lis);
	add_element_end(7, lis);
	add_element_end(8, lis);
	add_element_end(9, lis);
	
	//lis = add_element_start(13, lis);
	//lis = add_element_start(13, lis);
	
	lis = add_element_start(13, lis);
	lis = add_element_n_position(666, lis, 12);
	lis = add_element_n_position(666, lis, 6);
	lis = remove_element(13, lis);
	lis = remove_element(13, lis);
	lis = remove_element(13, lis);
	lis = remove_element(13, lis);
	lis = remove_element(13, lis);
	for (int i=0;i<666;i++){
		add_element_end(666, lis);
	}
	free_list(lis);
	show_elements(lis);
}
