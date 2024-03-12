#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int T;
typedef struct Stack_tag {
	T data[20];
	size_t size;
} Stack_t;

void push(Stack_t* stack, const T value) {
	if ( stack->size >= 20 ) {
		exit(-1);
	}

	stack->data[stack->size] = value;
	stack->size++;
}

T peek(const Stack_t* stack) {
	if (stack->size <= 0) {
		exit(-1);
	}
	return stack->data[stack->size - 1];
}

T pop(Stack_t* stack) {
	if (stack->size == 0) {
		exit(-1);
	}
	stack->size--;
	return stack->data[stack->size];
}
void printStackValue(const T value) {
	printf("%d\n", value);
}

void printStack(const Stack_t* stack, void (*printStackValue)(const T)) {
	int i;
	for (int i = 0; i < stack->size; i++) {
		printf("%d ", i);
		printStackValue(stack->data[i]);
	}
	printf("\n");
	if (stack->size != 0) {
		printStackValue(stack->data[i]);
	}
}

void main() {
	Stack_t* a = (Stack_t*)malloc(sizeof(Stack_t));
	a->size = 0;

	push(a, 6);
	push(a, 5);
	push(a, 4);
	push(a, 3);

	printStack(a, printStackValue);
	int tmp = pop(a);
	printf("%d\n", tmp);
	printStack(a, printStackValue);

	//printf("%d\n", peek(a));
}
