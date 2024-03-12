#ifndef _BOX_H_
#define _BOX_H_

#define MAX_HEIGHT 10000
#define MAX_WIDTH  10000
#define MAX_DEPTH  10000
 
struct Box_;
 
typedef struct Box_ Box;

Box* createBox(unsigned, unsigned, unsigned);
 
void setHeight(Box*, unsigned);
void setDepth(Box*, unsigned);
void setWidth(Box*, unsigned);

unsigned getHeight(Box*);
unsigned getWidth(Box*);
unsigned getDepth(Box*);
unsigned getVolume(Box*);
 
static int checkDepth(unsigned);
static int checkHeight(unsigned);
static int checkWidth(unsigned);
 
#endif
