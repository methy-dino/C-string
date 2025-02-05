#pragma once
typedef struct string{
	char* string;
	int length;
	int maxCapacity;
}String;
void growStr(String* str, int inc);
String* emptyStr(int allocSize);
String* charArrToStr(char arr[], int length);
String* initString(char* pointer, int length);
String* appendArr(String* str, char chars[], int arrL);
String* appendPtr(String* str, char* ptr, int ptrLen);
String* appendHeapPtr(String* str, char* ptr, int ptrLen);
String* appendStr(String* str, String* toAppend);
String* concatStr(String* str, String* toAppend);
void removeCharAt(String* str,int index);
void removeChar(String* str, char character);
void removeSubStr(String* str, String* subStr);
int indexOfChar(String* str, char character, int startIndex);
int lastIndexOfChar(String* str, char character, int endOffset);
int indexOfStr(String* str, String* subStr, int startIndex);
int lastIndexOfStr(String* str, String* subStr, int endOffset);
