#include "Box.h"
#include <malloc.h> 
#include <stdlib.h>

#define BAD_DATA -1
struct Box_ {
    unsigned depth;
    unsigned height;
    unsigned width;
};


// invisible from 
Box* createBox(unsigned a, unsigned b, unsigned c) {
	Box* tmp = (Box*)malloc(sizeof(Box));
	tmp->depth = a;
	tmp->height = b;
	tmp->width = c;
	return tmp;
}
void setHeight(Box* this_, unsigned height) {
    if (checkHeight(height)) {
        this_->height = height;
    } else {
        exit(BAD_DATA);
    }
}
void setWidth(Box* this_, unsigned width) {
    if (checkWidth(width)) {
        this_->width = width;
    } else {
        exit(BAD_DATA);
    }
}
void setDepth(Box* this_, unsigned depth) {
    if (checkDepth(depth)) {
        this_->depth = depth;
    } else {
        exit(BAD_DATA);
    }
}

unsigned getHeight(Box* this_) {
    return this_->height;
}
unsigned getWidth(Box* this_) {
    return this_->width;
}
unsigned getDepth(Box* this_) {
    return this_->depth;
}
unsigned getVolume(Box* this_) {
    return this_->depth * this_->height * this_->width;
}

int checkDepth(unsigned depth) {
    return (depth < MAX_DEPTH);
}
int checkHeight(unsigned height) {
    return (height < MAX_HEIGHT);
}
int checkWidth(unsigned width) {
    return (width < MAX_WIDTH);
}
