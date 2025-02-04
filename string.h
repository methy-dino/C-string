#pragma once
typedef struct string{
	char* string;
	int length;
	int maxCapacity;
}String;
void growStr(String* str, int inc);
String* initString(char* pointer, int length);
String* appendArr(String* str, char[]chars, int arrL);
String* appendPtr(String* str, char* ptr, int ptrLen);
String* appendHeapPtr(String* str, char* ptr, int ptrLen);
String* appendStr(String* str, String* toAppend);
String* appendHeapStr(String* str, String* toAppend);
void removeCharAt(String* str,int index);
void removeChar(String* str, char character);
