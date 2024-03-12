#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int value;
	struct Node *next;
} Spisok;

Spisok *create(int data) {
	// Выделение памяти под корень списка
	Spisok *tmp = (Spisok*)malloc(sizeof(Spisok));
	// Присваиание значения узлу
	tmp->value = data;
	// Присваивание указателю на следующий элемент значения NULL
	tmp->next = NULL;
	return(tmp);
}

Spisok *add_element_start(int data, Spisok *head) {
	// Выделение памяти под узел списка
	Spisok *tmp = (Spisok*)malloc(sizeof(Spisok));
	// Присваиание значения узлу
	tmp->value=data;
	// Присваивание указателю на следующий элемент значения указателя на "head"
	// Первоначальношо списка
	tmp->next = head;
	return(tmp);
}


void add_element_end(int data, Spisok *head) {
	// Выделение памяти под корень списка
	Spisok *tmp = (Spisok*)malloc(sizeof(Spisok));
	// Присвоение значения узлу
	tmp->value = data;
	// Присваивание указателю на следующий элемент значения NULL
	tmp->next = NULL;
	// Присваивание новому указателю указателя head. 
	// Присваивание выполняется для того, чтобы не потерять 
	// указатель на «голову» списка
	Spisok *p = head;
	while (p->next != NULL) 
		p = p->next;
	// Присваивание указателю p -> next значения 
	// указателя tmp (созданный новый узел)
	p->next = tmp;
}

Spisok *add_element_n_position(int data, int n, Spisok *head) {
	// Присваивание новому указателю указателя head.
	// Присваивание выполняется для того, чтобы не потерять
	// указатель на «голову» списка
	Spisok *p = head;
	// счётчик
	int count = 1;
	// поиск позиции n
	while (count < n - 1 && p->next != NULL) {
		p = p->next;
		count++;
	}
	// Выделение памяти под узел списка
	Spisok *tmp = (Spisok*)malloc(sizeof(Spisok));
	// Присвоение значения узлу
	tmp->value = data;
	// Присваивание указателю tmp -> next значения указателя p -> next 
	// (созданный новый узел)
	tmp->next = p->next;
	// Присваивание указателю p -> next значения 
	// указателя tmp (созданный новый узел)
	p->next = tmp;
	return head;
}



Spisok *remove_all(Spisok *head) {
	// Сдвиг указателя head в самый конец первоначального списка
	while (head != NULL) {
		// Присваивание новому указателю head
		Spisok *p = head;
		head = head->next;
		// Освобождение памяти для указателя p
		free(p);
	}
	return NULL;
}
void show_elements(Spisok *head) {
	int count = 0;
	while (head != NULL) {
		Spisok *p = head;
		printf("%d)\t%d\n", count, p->value);
		count++;
		head = head->next;
	}
}

Spisok *remove_element(int data, Spisok *head) {
	// Присваивание новому указателю  tmp указателя head, p - NULL
	Spisok *tmp = head, *p = NULL;
	// Проверка списка на пустоту
	if (head == NULL) {
		return NULL;
	}
	// Если список не пуст, поиск указателя на искомый элемент
	while (tmp && tmp->value != data) {
		p = tmp;
		tmp = tmp->next;
	}
	// Если удаляемый элемент первый
	if (tmp == head) {
		free(head);
		return tmp->next;
	}
	// Если в списке нет искомого элемента, то возвращаем первоначальный список
	if (!tmp) {
		return head;
	}
	// Присваивание новому указателю указателя tmp
	p->next = tmp->next;
	// Освобождение памяти для указателя tmp
	free(tmp);
	return head;
}

// 1 -> 2 -> 3 -> 4 -> 5 -> null
// 5 -> 4 -> 3 -> 2 -> 1 -> null
// o(n)
Spisok* reverse(Spisok* head) {
	Spisok *tmp = head;
	Spisok* save = NULL;
	Spisok* a = NULL;

	while (tmp != NULL) {
		save = tmp->next; // сохраняем адресс на следующий элемент
		tmp->next = a; // tmp->next теперб указываает на "a" затерли адрес 
		a = tmp; // а теперб равно текушт элементу
		tmp = save; // сохраняем ветку без текущего элемента
	}
	return a;
}
void main(){
	Spisok *les = create(0);
	
	add_element_end(1, les);
	add_element_end(2, les);
	add_element_end(3, les);
	add_element_end(4, les);
	add_element_end(5, les);
	add_element_end(6, les);
	add_element_end(7, les);
	add_element_end(8, les);
	add_element_end(9, les);
	
	show_elements(les);
	les = reverse(les);
	show_elements(les);
}
