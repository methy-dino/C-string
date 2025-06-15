#include "string_debug.h"
#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
int testIndex(){
	String* simiSub;
	String* similar;
	size_t indSub;
	size_t index;
	size_t prevInd;
	printf("running index tests...\n");
	similar = ptrToStr("abcbbbcbbc");
	simiSub = ptrToStr("bbc");
	assert(indexOfStr(similar, simiSub, 0) == 4);
	printf("I T1 passed\n");
	assert(indexOfStr(similar, simiSub, 5) == 7);
	printf("I T2 passed\n");
	assert(lastIndexOfStr(similar, simiSub, 0) == 7);
	printf("I T3 passed\n");
	discardStr(similar);
	discardStr(simiSub);
	similar = ptrToStr("mini shark, giga fish");
	simiSub = ptrToStr("ni");
	indSub = indexOfStr(similar, simiSub, 0);
	assert(indSub == 2);
	printf("I T4 passed\n");
	removeCharAt(similar, indSub);
	assert(indexOfStr(similar, simiSub, 0) == 0xffffffffffffffff);
	printf("I T5 passed\n");
	discardStr(similar);
	discardStr(simiSub);
	similar = ptrToStr("mamamamamama");
	index = 0;
	prevInd = 0;
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
	String* str;
	String* target;
	String* sub;
	String* silly; 
	str = ptrToStr("I read books every once in a while \n today I read Little Prince");
	target = ptrToStr("read");
	sub = ptrToStr("burn");
	replaceFirstStr(str, target, sub);
	printf("\"%s\"", str->string);
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
	insertChar(str, 'e', 3);
	assert(strcmp(str->string, "I beurn baaks every ance in a while \n taday I burned Little Prince") == 0);
	printf("R T4 passed\n");
	silly = ptrToStr("silly");
	insertStr(str, silly, 3);
	printf("\"%s\"\n", str->string);
	assert(strcmp(str->string, "I bsillyeurn baaks every ance in a while \n taday I burned Little Prince") == 0);
	trimEnd(str);
	assert(strcmp(str->string, "I bsillyeurn baaks every ance in a while \n taday I burned Little Prince") == 0);
	printf("R T4 passed\n");
	return 0;
}
int removeTest(){
	String* bloated;
	String* clean_up; 
	bloated = ptrToStr("hello everyone, I am the String itself");
	debugPrintStr(bloated, 3);
	clean_up = ptrToStr("the ");
	removeStr(bloated, clean_up);
	printf("\"%s\"\n", bloated->string);
	assert(strcmp(bloated->string, "hello everyone, I am String itself") == 0);
	printf("REMOVE T1 passed\n");
	clean_up->length = 0;
	appendNoLen(clean_up, " itself", 64);
	printf("\"%s\"\n", clean_up->string);
	removeStr(bloated, clean_up);
	printf("\"%s\"\n", bloated->string);
	assert(strcmp(bloated->string, "hello everyone, I am String") == 0);
	printf("REMOVE T2 passed\n");
	clean_up->length = 0;
	appendNoLen(clean_up, " everyone", 64);
	removeStr(bloated, clean_up);
	assert(strcmp(bloated->string, "hello, I am String") == 0);
	printf("REMOVE T3 passed\n");
	removeCharAt(bloated, 0);
	printf("\"%s\"\n", bloated->string);
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
	String* test;
	String* test2;
	String* divisor;
	String* split_test;
	String* split_test2;
	size_t split_len;
	size_t i;
	test = ptrToStr("thisthatthisthatthisthatthisthatthisthat");
	divisor = ptrToStr("that");
	split_len = 0;
	i = 0;
	split_test = splitByStr(test, divisor, &split_len);
	assert(split_len == 5);
	for (i = 0; i < split_len; i++){ 
		assert(strcmp(split_test[i].string, "this") == 0);    
	}
	printf("S T1 passed\n");
	test2 = ptrToStr("badthatgoodthatwrongthatrightthat");
	split_len = 0;
	split_test2 = splitByStr(test2, divisor, &split_len);
	assert(split_len == 4);
	assert(strcmp(split_test2[0].string, "bad") == 0);
	assert(strcmp(split_test2[1].string, "good") == 0);
	assert(strcmp(split_test2[2].string, "wrong") == 0);
	assert(strcmp(split_test2[3].string, "right") == 0);
	printf("S T2 passed\n");
	return 0;
}
int prependTests(){
	String* test;
	test = ptrToStr("men");
	prependPtr(test, "two ", 4);
	assert(strcmp(test->string, "two men") == 0);
	printf("Prep T1 passed\n");
	prependSubPtr(test, "TTwenty-", 1, 8);
	assert(strcmp(test->string, "Twenty-two men") == 0);
	printf("Prep T2 passed\n");
	return 0; 
}
int allocTests(){
	String* str;
	str = emptyStr(0xffffffffffffffff);
	assert(str == NULL);
	printf("Allocation T1 passed\n");
	return 0;
}
