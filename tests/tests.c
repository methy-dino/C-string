#include "string_debug.h"
#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
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
	size_t indSub = indexOfStr(similar, simiSub, 0);
	assert(indSub == 2);
	printf("I T4 passed\n");
	removeCharAt(similar, indSub);
	assert(indexOfStr(similar, simiSub, 0) == 0xffffffffffffffff);
	printf("I T5 passed\n");
	discardStr(similar);
	discardStr(simiSub);
	similar = ptrToStr("mamamamamama");
	size_t index = 0;
	size_t prevInd = 0;
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
	appendNoLen(similar, "testtesttesttest", 64);
    debugPrintStr(similar, 3);
    discardStr(similar);
    printf("I T11 passed\n");
    return 0;
}
int replaceTest(){
    String* str = ptrToStr("I read books every once in a while \n today I read Little Prince");
    String* target = ptrToStr("read");
    String* sub = ptrToStr("burn");
    replaceFirstStr(str, target, sub);
    assert(strcmp(str->string, "I burn books every once in a while \n today I read Little Prince") == 0);
    printf("R T1 passed\n");
    appendPtr(sub, "ed", 2);
    replaceLastStr(str, target, sub);
    assert(strcmp(str->string, "I burn books every once in a while \n today I burned Little Prince") == 0);
    printf("R T2 passed\n");
    debugPrintStr(str, 3);
		sub->length = 1;
		sub->string[1] = '\0';
		sub->string[0] = 'a';
		target->length = 1;
		target->string[1] = '\0';
		target->string[0] = 'o';
		replaceStr(str, target, sub);
		assert(strcmp(str->string, "I burn baaks every ance in a while \n taday I burned Little Prince") == 0);
		printf("R T3 passed\n");
		return 0;
}
int removeTest(){
	String* bloated = ptrToStr("hello everyone, I am the String itself");
	debugPrintStr(bloated, 3);
	String* clean_up = ptrToStr("the ");
	removeStr(bloated, clean_up);
	assert(strcmp(bloated->string, "hello everyone, I am String itself") == 0);
	printf("REMOVE T1 passed\n");
	clean_up->length = 0;
	appendNoLen(clean_up, " itself", 64);
	removeStr(bloated, clean_up);
	assert(strcmp(bloated->string, "hello everyone, I am String") == 0);
	printf("REMOVE T2 passed\n");
	clean_up->length = 0;
	appendNoLen(clean_up, " everyone", 64);
	removeStr(bloated, clean_up);
	assert(strcmp(bloated->string, "hello, I am String") == 0);
	printf("REMOVE T3 passed\n");
	removeCharAt(bloated, 0);
	assert(strcmp(bloated->string, "ello, I am String") == 0);
	printf("REMOVE T4 passed\n");
	removeSubStr(bloated, 0, 5);
debugPrintStr(bloated, 3);
	assert(strcmp(bloated->string, " I am String") == 0);
	printf("REMOVE T5 passed\n");
	debugPrintStr(bloated, 3);
	return 0;
}
int splitTest(){
    String* test = ptrToStr("thisthatthisthatthisthatthisthatthisthat");
    String* divisor = ptrToStr("that");
    size_t split_len = 0;
    String* split_test = splitByStr(test, divisor, &split_len);
    assert(split_len == 5);
		size_t i = 0;
    for (i = 0; i < split_len; i++){ 
        assert(strcmp(split_test[i].string, "this") == 0);    
    }
    printf("S T1 passed\n");
    String* test2 = ptrToStr("badthatgoodthatwrongthatrightthat");
    split_len = 0;
    String* split_test2 = splitByStr(test2, divisor, &split_len);
    assert(split_len == 4);
    assert(strcmp(split_test2[0].string, "bad") == 0);
    assert(strcmp(split_test2[1].string, "good") == 0);
    assert(strcmp(split_test2[2].string, "wrong") == 0);
    assert(strcmp(split_test2[3].string, "right") == 0);
    printf("S T2 passed\n");
}
int prependTests(){
    String* test = ptrToStr("men");
    prependPtr(test, "two ", 4);
		assert(strcmp(test->string, "two men") == 0);
    printf("Prep T1 passed\n");
    prependSubPtr(test, "TTwenty-", 1, 8);
    assert(strcmp(test->string, "Twenty-two men") == 0);
    printf("Prep T2 passed\n");
}
int allocTests(){
	String* str = emptyStr(0xffffffffffffffff);
	assert(str == NULL);
	printf("Allocation T1 passed\n");
	return 0;
}
