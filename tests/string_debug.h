#pragma once
#define FORCE_BREAK 2
typedef struct string{
	char* string;
	unsigned int length;
	unsigned int maxCapacity;
}String;
void growStr(String* str, unsigned int inc);
void growStrClean(String* str, unsigned int inc);
String* emptyStr(unsigned int allocSize);
String* ptrToStr(char* ptr);
String* charArrToStr(char arr[], unsigned int length);
String* initStr(char* rawStr, unsigned int rawStrLen);
String* buildStr(char* pointer, unsigned int length);
void appendArr(String* str, char chars[], unsigned int arrL);
void appendSubPtr(String* str, char* ptr, int start, int end);
unsigned int appendNoLen(String* str, char* ptr, unsigned int max);
void appendPtr(String* str, char* ptr, unsigned int ptrLen);
void appendHeapPtr(String* str, char* ptr, unsigned int ptrLen);
void appendStr(String* str, String* toAppend);
String* concatStr(String* str, String* toAppend);
void removeCharAt(String* str, unsigned int index);
void removeChar(String* str, char character);
String* subStr(String* str, unsigned int start, unsigned int end);
void removeSubStr(String* str, unsigned int start, unsigned int end);
void removeStr(String* str, String* subStr);
void removeFirstStr(String* str, String* target, String* sub);
void removeLastStr(String* str, String* target, String* sub);
unsigned int indexOfChar(String* str, char character, unsigned int startIndex);
unsigned int lastIndexOfChar(String* str, char character, unsigned int endOffset);
unsigned int indexOfStr(String* str, String* subStr, unsigned int startIndex);
unsigned int lastIndexOfStr(String* str, String* subStr, unsigned int endOffset);
void replaceStr(String* str, String* target, String* sub);
void replaceFirstStr(String* str, String* target, String* sub);
void replaceLastStr(String* str, String* target, String* sub);
unsigned int strEqual(String* str1, String* str2);
unsigned long long evaluateStr(String* str);
long long strCompare(String* str1, String* str2);
void toUpperCase(String* str);
void toLowerCase(String* str);
String* cloneStr(String* str);
unsigned long long hashStr(void* str);
String* joinStr(String** strings, unsigned int len, String* separator);
void reduceStr(String* str, unsigned int reduction);
void trimEnd(String* str);
String* splitByStr(String* str, String* divisor, unsigned int* len);
void discardStr(String* str);
void debugPrintStr(String* str, int verbosity);

