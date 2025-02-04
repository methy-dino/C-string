#include <stdlib.c>
struct string{
	char* string;
	int length;
	int maxCapacity;
}
struct string* initString(char* pointer, int length){
	struct string* string = malloc(sizeof(struct string));
	string->maxCapacity = length * 1.5;
	string->length = length;
	string->string = malloc(string->maxCapacity);
	for (int i = 0; i < sizeof(pointer); i++){
		string[i] = pointer[i];
	}
	return string;
}
struct string* appendArr(struct string* string, char[]chars, int arrL){
	for (int i = 0; i < arrL; i++){
		if (string->length == string->maxCapacity){
			growStr(string, (string->length+1) / 2)   
		}
}
