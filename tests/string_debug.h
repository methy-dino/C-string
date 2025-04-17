/*header automatically generated by autoHead*/
#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#define FORCE_BREAK 2
typedef struct string {
	char* string;
	size_t length;
	size_t maxCapacity;
} String;
int growStr(String* str, size_t inc);
int growStrClean(String* str, size_t inc);
/* creates an empty (length 0, string[0] == '\0') string with allocSize */
String* emptyStr(size_t allocSize);
/* converts a null terminated char* to a String */
String* ptrToStr(char* ptr);
/* creates a String using a char* with rawStrLen, USING THE POINTER PROVIDED BEWARE.*/
String* initStr(char* rawStr, size_t rawStrLen);
/* builds a String with spare capacity from the char* with length*/ 
String* buildStr(char* pointer, size_t length);
/* appends only part of a pointer, determined by start and end, does not stop at null terminators.*/
void appendSubPtr(String* str, char* ptr, size_t start, size_t end);
int prependSubPtr(String* str, char* ptr, size_t start, size_t end);
int appendChar(String* str, char ch);
int appendNoLen(String* str, char* ptr, size_t max);
int appendPtr(String* str, char* ptr, size_t ptrLen);
int prependPtr(String* str, char* ptr, size_t ptrLen);
void appendHeapPtr(String* str, char* ptr, size_t ptrLen);
int appendStr(String* str, String* toAppend);
String* concatStr(String* str, String* toAppend);
void toUpperCase(String* str);
void toLowerCase(String* str);
/* start inclusive, end exclusive, returns string built with exact capacity.
*/
String* subStr(String* str, size_t start, size_t end);
/* start is inclusive, end is exclusive, as by default.
 * not to be confused with removeStr(String*, String*)
 * as a safe guard, ints are converted to % str->length 
 */
void removeSubStr(String* str, size_t start, size_t end);
void removeCharAt(String* str, size_t index);
void removeChar(String* str, char character);
void removeStr(String* str, String* subStr);
void removeFirstStr(String* str, String* subStr);
void removeLastStr(String* str, String* subStr);
size_t indexOfChar(String* str, char character, size_t startIndex);
size_t lastIndexOfChar(String* str, char character, size_t endOffset);
size_t indexOfStr(String* str, String* subStr, size_t startIndex);
size_t lastIndexOfStr(String* str, String* subStr, size_t endOffset);
void replaceChar(String* str, char target, char sub);
void replaceStr(String* str, String* target, String* sub);
void replaceFirstStr(String* str, String* target, String* sub);
void replaceLastStr(String* str, String* target, String* sub);
char insertStr(String* str, String* str2, size_t index);
char insertChar(String* str, char ch, size_t index);
/* returns 1 if the strings are equal, otherwise returns 0.
 * does not compare after String.length, it may contain trash data after that.
 * trash data is non-zeroed and unsanitized.
 */
int strEqual(String* str1, String* str2);
size_t evaluateStr(String* str);
long long strCompare(String* str1, String* str2);
/* clones a string, will not clone content after String.length (Incase you are storing data there) */
String* cloneStr(String* str);
size_t hashStr(void* str);
String* joinStr(String** strings, size_t len, String* separator);
/* splits the String* str by String* divisor, writing the quantity of strings after the split to int* len. */
String* splitByStr(String* str, String* divisor, size_t* len);
/* reduces the String* str's memory allocation by reduction. */
void reduceStr(String* str, size_t reduction);
/* sets the String* str's memory allocation to be exact with it's current contents*/
void trimEnd(String* str);
/* it is a void* to easier integration to libs with need of free functions.
 * frees the String* str memory */
void discardStr(void* str);
/* verbosity indicates what should be printed: 
 * 0 prints the string's contents before str->length, using default string printing.
 * 1 prints the string's address, and it's capacity/filled portion.
 * 2 will also print control characters by it's escape code, wrapped in ' (i.e '\n' instead of a new line), using a custom printer, and print the char* address.
 * 3 will print characters after str->length, up to str->maxCapacity*/
void debugPrintStr(String* str, int verbosity);
