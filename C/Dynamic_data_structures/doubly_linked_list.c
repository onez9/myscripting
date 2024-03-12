#include <stdio.h>
#include <malloc.h>

// узел ДЛС
typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

//инициализация корневого узла
Node* init(int data) {
	Node* lst = (Node*)malloc(sizeof(Node));
	lst->data = data;
	lst->next = NULL;
	lst->prev = NULL;
	return lst;
}
void addend(int data, Node* lst) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL; // новый элемент будет указывать вправо на NULL
	Node* p = lst;
	while (p->next != NULL) {
		p = p->next;
	}
	temp->prev = p;
	p->next = temp; // последний элемент получит адресс нового элемента
}
Node* addstart(int data, Node* obj) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->prev = NULL;
	temp->next = obj;
	obj->prev = temp;
	return temp;
}
void show_elements(Node* obj) {
	if (obj == NULL) {
		return;
	}
	int count = 0;
	while (obj != NULL) {
		printf("%d)\t%d\n", count, obj->data);
		obj = obj->next;
		count++;
	}
}
void show1(Node* obj) {
	if (obj == NULL) {
		return;
	}
	while (obj->next != NULL) {
		obj = obj->next;
	}
	int count = 0;
	do {
		printf("%d)\t%d\n", count, obj->data);
		obj = obj->prev;
		count++;
	} while (obj != NULL);
}
// 0 and $ не работает
Node* addelement(int data, int position, Node* obj) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;

	Node* p = obj;
	int count = 0;
	// 1 0  1 1 -> 2 1  2 2 x
	while (p->next != NULL && count < position - 1) {
		count++;
		p = p->next;
	}
	temp->next = p->next; // новый элемент принимает указатель на 3 элемент
	
	p->next->prev = temp; // 3 элемент указывает на новый элемент
	
	// мы говорим что temp 
	//присваивается указателю next второго элемента
	p->next = temp; 
	
	temp->prev = p; // новый элемент ссылается на второй
	return obj;
}
size_t get_len(Node* obj) {
	size_t count = 0;
	while (obj != NULL) {
		obj = obj->next;
		count++;
	}
	return count;
}
int get_el(Node* obj, int number) {
	Node *ptr = obj;
	size_t count = 0;
	while (ptr && count != number) {
		ptr = ptr->next;
		count++;
	}
	//if (ptr == obj) return -2;
	return ptr->data;
}
// указатель на объект и индекс
Node* del_el(Node* obj, int number) {
	Node* ptr = obj;
	Node* p;
	int count = 0;
	while (ptr && count != number) {
		p = ptr;
		ptr = ptr->next;
		count++;
	}


	//printf("%#x\n", p->next);
	//printf("%#x\n", ptr->next);
	if (ptr->next == NULL) {
		ptr->prev->next = NULL;
		free(ptr);
		return obj;
	} else if (ptr != obj) {
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		free(ptr);
		return obj;
	} else {
		//printf("3\n");
		return obj->next;
	}
}
void remove_all(Node* obj) {
	if (obj == NULL) {
		return;
	}
	int count = 0;
	while (obj != NULL) {
		Node* p = obj;
		obj = obj->next;
		free(p);
		count++;
	}
	printf("count = %d\n", count);
}
void main() {
	Node* obj;
	obj = init(13);
	addend(12, obj);
	addend(666, obj);
	addend(666666, obj);
	obj = addstart(69, obj);
	//show_elements(obj);
	//printf("------\n");
	//show1(obj);
	//printf("------\n");
	obj = addelement(333, 2, obj);
	obj = addelement(666, 1, obj);
	obj = addelement(666, 4, obj);
	obj = addelement(612, 3, obj);
	//show_elements(obj);
	//printf("get_len(obj) = %u\n", get_len(obj));
	//printf("get_element(obj) = %d\n", get_el(obj, 3));

	//printf("------\n");
	//printf("------\n");
	//obj = del_el(obj, 3);
	//obj = del_el(obj, 4);
	//obj = del_el(obj, 0);
	//show_elements(obj);
	//printf("------\n");

	//obj = del_el(obj, 7);
	

	show_elements(obj);
	printf("----\n");
	show_elements(obj);
	printf("----\n");
	show1(obj);
	printf("----\n");
	remove_all(obj);
	printf("----\n");
	printf("%d\n", get_len(obj));
	printf("----\n");
	show1(obj);
	/*
	printf("------\n");
	show_elements(obj);
	printf("01010\n");
	remove_all(obj);
	printf("01010\n");
	show_elements(obj);
	printf("------\n");
	*/
	printf("%d\n", (13>>1));
	//printf("get_len(obj) = %d\n", get_len(obj));
	//printf("%d\n", (69>>4));
	//printf("%d\n", obj->prev->data);
}
