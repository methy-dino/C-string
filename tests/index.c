#include "string_debug.h"
#include <assert.h>
#include <stdio.h>
#include <limits.h>
int testIndex(){
	printf("running index tests...\n");
	String* similar = ptrToStr("abcbbbcbbc\0");
	String* simiSub = ptrToStr("bbc\0");
	assert(indexOfStr(similar, simiSub, 0) == 3);
	printf("I T1 passed\n");
	assert(indexOfStr(similar, simiSub, 5) == 7);
	printf("I T2 passed\n");
	assert(lastIndexOfStr(similar, simiSub, 0) == 7);
	printf("I T3 passed\n");
	discardStr(similar);
	discardStr(simiSub);
	similar = ptrToStr("mini shark, giga fish");
	simiSub = ptrToStr("ni");
	unsigned int indSub = indexOfStr(similar, simiSub, 0);
	assert(indSub == 2);
	printf("I T4 passed\n");
	removeCharAt(similar, indSub);
	assert(indexOfStr(similar, simiSub, 0) == UINT_MAX);
	printf("I T5 passed\n");
	discardStr(similar);
	discardStr(simiSub);
	similar = ptrToStr("mamamamamama");
	unsigned int index = 0;
	unsigned int prevInd = 0;
	index = indexOfChar(similar, 'a', prevInd); 
	assert(index == 1);
	prevInd = index;
	printf("I T6 passed\n");
	index = indexOfChar(similar, 'a', prevInd + 1);
	assert(prevInd+2 == index);
	prevInd = index;
	printf("I T7 passed\n");
	index = indexOfChar(similar, 'a', prevInd + 1);
	assert(prevInd+2 == index);
	prevInd = index;
	printf("I T8 passed\n");
	index = indexOfChar(similar, 'a', prevInd + 1);
	assert(prevInd+2 == index);
	prevInd = index;
	printf("I T9 passed\n");
	index = indexOfChar(similar, 'a', prevInd + 1);
	assert(prevInd+2 == index);
	prevInd = index;
	printf("I T10 passed\n");
    debugPrintStr(similar, 3);
	//printf("I T11 passed\n");
    return 0;
}
