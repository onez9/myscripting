#include <stdio.h>
#include <malloc.h>
#include "Box.h"
 
void main() {
    Box *box = createBox(10, 20, 35);
	//int p = checkDepth(3);
    printf("volume = %d\n", getVolume(box));
    setWidth(box, 22);
    printf("volume = %d\n", getVolume(box));
    free(box);
}
