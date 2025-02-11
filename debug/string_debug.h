#pragma once
typedef struct string{
	char* string;
	int length;
	int maxCapacity;
}String;
void growStr(String* str, int inc);
String* emptyStr(int allocSize);
String* charArrToStr(char arr[], int length);
String* initStr(char* rawStr, int rawStrLen);
String* buildStr(char* pointer, int length);
void appendArr(String* str, char chars[], int arrL);
void appendPtr(String* str, char* ptr, int ptrLen);
void appendHeapPtr(String* str, char* ptr, int ptrLen);
void appendStr(String* str, String* toAppend);
String* concatStr(String* str, String* toAppend);
void removeCharAt(String* str,int index);
void removeChar(String* str, char character);
String* subStr(String* str, int start, int end);
void removeSubStr(String* str, int start, int end);
void removeStr(String* str, String* subStr);
void removeFirstStr(String* str, String* target, String* sub);
void removeLastStr(String* str, String* target, String* sub);
int indexOfChar(String* str, char character, int startIndex);
int lastIndexOfChar(String* str, char character, int endOffset);
int indexOfStr(String* str, String* subStr, int startIndex);
int lastIndexOfStr(String* str, String* subStr, int endOffset);
void replaceStr(String* str, String* target, String* sub);
void replaceFirstStr(String* str, String* target, String* sub);
void replaceLastStr(String* str, String* target, String* sub);
int strEqual(String* str1, String* str2);
unsigned long long evaluateStr(String* str);
long long strCompare(String* str1, String* str2);
void toUpperCase(String* str);
void toLowerCase(String* str);
String* cloneStr(String* str);
unsigned long long hashStr(void* str);
void discardStr(String* str);
