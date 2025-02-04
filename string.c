#include <stdlib.c>
typedef struct string{
	char* string;
	int length;
	int maxCapacity;
}String;
String* initString(char* pointer, int length){
	struct string* string = malloc(sizeof(struct string));
	string->maxCapacity = length * 1.5;
	string->length = length;
	string->string = malloc(string->maxCapacity);
	for (int i = 0; i < sizeof(pointer); i++){
		string[i] = pointer[i];
	}
	return string;
}
String* appendArr(String* str, char[]chars, int arrL){
	for (int i = 0; i < arrL; i++){
		if (str->length == str->maxCapacity){
			growStr(str, (str->length+1) / 2);  
		}
		str->string[str->length] = chars[i];
		str->length++;
	}
}
String* appendPtr(String* str, char* ptr, int ptrLen){
	for (int i = 0; i < ptrLen; i++){
		if (str->length == str->maxCapacity){
			growStr(str, (str->length+1) / 2);
		}
		str->string[str->length] = ptr[i];
		str->length++;
	}
	return str;
}
String* appendHeapPtr(String* str, char* ptr, int ptrLen){
	for (int i = 0; i < ptrLen; i++){
		if (str->length == str->maxCapacity){
			growStr(str, (str->length+1) / 2);   
		}
		str->string[str->length] = ptr[i];
		str->length++;
	}
	free(ptr);
	return str;
}
String* appendStr(String* str, struct string* toAppend){
	for (int i = 0; i < toAppend.length; i++){
		if (str->length == str->maxCapacity){
			growStr(str, (str->length+1) / 2);  
		}
		str->string[str->length] = toAppend->string[i];
		str->length++;
	}
	return str;	
}	
void growStr(String* str, int inc){
	int newL = inc + str->maxCapacity;
	char* nStr = malloc(newL);
	for (int i = 0; i < str->len; i++){
		nStr[i] = str->string[i];
	}
}
