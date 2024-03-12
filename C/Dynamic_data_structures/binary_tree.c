#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>


typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} Node;

Node* init(int data) {
	Node* obj = (Node*)malloc(sizeof(Node));
	obj->data = data;
	obj->left = NULL;
	obj->right = NULL;
	return obj;
}

void add_el(Node* obj, int data) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;
	
	Node* ptr = obj;
	while(1) {
		if (ptr->data < tmp->data) {
			if (ptr->right == NULL) {
				ptr->right = tmp;
				return;
			} else {
				ptr = ptr->right;
			}
		} else if (ptr->data > tmp->data) {
			if (ptr->left == NULL) {
				ptr->left = tmp;
				return;
			} else {
				ptr = ptr->left;
			}
		} else {
			return;
		}
	}
}
void show_pr(Node* obj) {
	if (obj != NULL) {
		printf("%d\n", obj->data);
		show_pr(obj->right);
		show_pr(obj->left);
	}
}
void show_left(Node* obj) {
	if (obj != NULL) {
		show_left(obj->left);
		printf("%d\n", obj->data);
		show_left(obj->right);
	}
}
void show_right(Node* obj) {
	if (obj != NULL) {
		show_right(obj->right);
		printf("%d\n", obj->data);
		show_right(obj->left);
	} 
}
void find_element(Node* obj, int data) {
	int count = 0;
	while (obj != NULL) {
		if (obj->data > data) {
			obj = obj->left;
		} else if (obj->data < data) {
			obj = obj->right;
		} else { 
			printf("count: %d.\tWe have number %d \n", count, data);
			return;
		}
		count++;
	}
	printf("count: %d.\tWe don't have number %d \n", count, data);
}
void remove_element(Node* obj, int data) {
	Node* tmp;
	while (obj != NULL) {
		if (obj->data > data) {
			obj = obj->left;
		} else if (obj->data < data) {
			obj = obj->right;
		} else { 
			Node* l = obj->left;
			Node* r = obj->right;
			free(obj);
			if (l->data > r->data) {
				obj = l->;
			} else {
				obj = r->data;
			}
		}
	}
	printf("We don't have number %d\n");
	
}
void main() {
	Node* obj;
	//srand(time(NULL));

	obj = init(111);
	int arr[10] = {132, 5, -43, 53, 67, -333, 55, 32, -73, 12};
	for (unsigned i=1;i<10;i++) {
		add_el(obj, arr[i]);
	}
	//printf("\n\nright\n");
	//ishow_right(obj);
	//printf("\n\nleft\n");
	//show_left(obj);
	printf("\n\nshow_pr\n");
	show_pr(obj);
	printf("|------|\n");
	find_element(obj, 8);
	find_element(obj, 13);
	printf("|------|\n\n");
	remove_element(obj, 5);
	show_right(obj);
}
