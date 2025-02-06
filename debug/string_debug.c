#include <stdlib.h>
#include <stdio.h>
typedef struct string{
	char* string;
	int length;
	int maxCapacity;
}String;
void growStr(String* str, int inc){
	printf("growing string from %d to %d \n",str->length, inc);
	int newL = inc + str->maxCapacity;
	char* nStr = (char*)malloc(newL);
	for (int i = 0; i < str->length; i++){
		nStr[i] = str->string[i];
	}
	free(str->string);
	str->string = nStr;
	str->string[str->length] = '\0';
}
String* emptyStr(int allocSize){
	String* string  = (String*)malloc(sizeof(struct string));
	string->maxCapacity = allocSize;
	string->length = 0;
	string->string = (char*)malloc(string->maxCapacity);
	return string;
}
/* I don't know why someone would want to initialize like this.
 * It is here anyways.
*/
String* charArrToStr(char arr[], int length){
	String* string  = (String*)malloc(sizeof(struct string));
	string->maxCapacity = length*1.5+1;
	string->length = length;
	string->string = (char*)malloc(string->maxCapacity);
	for (int i = 0; i < length; i++){
		string->string[i] = arr[i];
	}
	string->string[string->length] = '\0';
	return string;
}

String* initStr(char* rawStr, int rawStrLen){
	String* string  = (String*)malloc(sizeof(struct string));
	string->maxCapacity = rawStrLen;
	string->length = rawStrLen;
	string->string = rawStr;
	return string;
}

String* buildStr(char* pointer, int length){
		String* string  = (String*)malloc(sizeof(struct string));
		string->maxCapacity = length*1.5+1;
		string->length = length;
		string->string = (char*)malloc(string->maxCapacity);
	for (int i = 0; i < length; i++){
		string->string[i] = pointer[i];
	}
	string->string[string->length] = '\0';
	return string;
}
void appendArr(String* str, char chars[], int arrL){
	if (str->maxCapacity < str->length + arrL){
		growStr(str, (str->length+1) / 2);
	}
	for (int i = 0; i < arrL; i++){
		str->string[str->length] = chars[i];
		str->length++;
	}
	str->string[str->length] = '\0';
}

void appendPtr(String* str, char* ptr, int ptrLen){
	if (str->maxCapacity < str->length + ptrLen){
		 growStr(str, ptrLen * 1.5);
	}
	for (int i = 0; i < ptrLen; i++){	
		str->string[str->length] = ptr[i];
		str->length++;
	}
	str->string[str->length] = '\0';
}
void appendHeapPtr(String* str, char* ptr, int ptrLen){
	if (str->maxCapacity < str->length + ptrLen){
		 growStr(str, ptrLen * 1.5);
	}
	for (int i = 0; i < ptrLen; i++){
		if (str->length == str->maxCapacity){
			growStr(str, (str->length+1) / 2);   
		}
		str->string[str->length] = ptr[i];
		str->length++;
	}
	str->string[str->length] = '\0';
	free(ptr);
}

void appendStr(String* str, String* toAppend){
	// avoid unnecessary grow checks
	if (str->maxCapacity < str->length + toAppend->length){
	 growStr(str, toAppend->length * 1.5);
	}
	for (int i = 0; i < toAppend->length; i++){
		str->string[str->length] = toAppend->string[i];
		str->length++;
	}
	str->string[str->length] = '\0';	
}

String* concatStr(String* str, String* toAppend){
	if (str->maxCapacity < str->length + toAppend->length){
	 growStr(str, toAppend->length * 1.5);
	}
	for (int i = 0; i < toAppend->length; i++){
		str->string[str->length] = toAppend->string[i];
		str->length++;
	}
	str->string[str->length] = '\0';
	free(toAppend->string);
	free(toAppend);
	return str;	
}
/* start inclusive, end exclusive, returns string built with exact capacity.
*/
String* subStr(String* str, int start, int end){
	start = str->length % start;
	end = str->length % end;
	String* ret = malloc(sizeof(String));
	ret->string = (char*) malloc(sizeof(char) * (start-end));
	for (int i = 0; i < end-start; i++){
		ret->string[i] = str->string[i+start];
	}
	return subStr;
}
/* start is inclusive, end is exclusive, as by default.
 * not to be confused with removeStr(String*, String*)
 * as a safe guard, ints are converted to % str->length 
 */
void removeSubStr(String* str, int start, int end){
	start = str->length % start;
	end = str->length % end;
    str->length -= end-start;
	for (int i = start; i < str->length; i++){
		str->string[i] = str->string[i+end-start];
	}
}

void removeCharAt(String* str,int index){
	for (int i = index + 1; i < str->length; i++){
		str->string[i-1] = str->string[i];
	}
	str->length--;
}

void removeChar(String* str, char character){
	int removed = 0;
	for (int i = 0; i < str->length-removed; i++){
		while (str->string[i+removed] == character){
			removed++;
		}
		str->string[i] = str->string[i+removed];
	}
	str->length -= removed;
	str->string[str->length] = '\0';
}

void removeStr(String* str, String* subStr){
	int j = 0;
	int removed = 0;
	for (int i = 0; i < str->length; i++){
		j = 0;
		while (str->string[i+j] == subStr->string[j]){	
			j++;
			if (subStr->string[j+1] == '\0'){
				i += j+1;
				removed+= subStr->length;
			}
		}
		str->string[i-removed] = str->string[i]; 	
	}
	str->length-=removed;
	str->string[str->length] = '\0';
}

int indexOfChar(String* str, char character, int startIndex){
	int start = (str->length + startIndex) % str->length;
	while (start < str->length){
		if (str->string[start] == character){
			return start;
		}
		start++;
	}
	return -1;
}

int lastIndexOfChar(String* str, char character, int endOffset){
	int start = (str->length + endOffset - 1) % str->length;
	while (start > -1){
		if (str->string[start] == character){
			return start;
		}
		start--;
	}
	return -1;
}

int indexOfStr(String* str, String* subStr, int startIndex){
	int start = (str->length + startIndex) % str->length;
	int i = 0;
	while (start < str->length){
/* must be done in this way, for cases like ("abaabaac", "abaac")
* since the string start can be messed up by an check advancing after it
*  It's possible to check if the start is seen, but it has barely any benefit*/
		while (str->string[start+i] == subStr->string[i]){
			i++;
			if (i+1 == subStr->length){
				return start;
			}
		}
		i = 0;
		start++;
	}
	return -1;
}

int LastindexOfStr(String* str, String* subStr, int endOffset){
	int start = (str->length + endOffset - 1) % str->length;
	int i = subStr->length;
	while (start > 0){
		while (str->string[start-i] == subStr->string[subStr->length - i]){
			i--;
			if (i == 1){
				return start-subStr->length;
			}	
		}
		start--;
		i = subStr->length;
	}
	return -1;
}
void replaceChar(String* str, char target, char sub){
	for (int i = 0; i < str->length; i++){
		if (str->string[i] == target){
			str->string[i] = sub;
		}
	}
}
void replaceSubStr(String* str, String* target, String* sub){
	int added = 0;
	int j = 0;
	printf("%d \n", target->length);
	for (int i = 0; i < str->length - target->length; i++){
		j = 0;
		while (str->string[i+j] == target->string[j]){
			j++;
			if (j == target->length){
				if (str->maxCapacity < str->length + sub->length - target->length){
					// allocate extra space for less reallocs (heap slow!1!1!1)
					growStr(str, (sub->length - target->length)*2);
				}
				printf("before change: %s \n", str->string);
				str->length += sub->length - target->length;
				str->string[str->length] = '\0';	
				// has to be backwards since we are moving chars further.
				for (int k = str->length-1; k > i+sub->length-1; k--){
					str->string[k] = str->string[k - sub->length + target->length];
				}
				printf("in-between: %s \n", str->string);
				for (int k = 0; k < sub->length; k++){
					str->string[i+k] = sub->string[k];
				}
				printf("after: %s \n",str->string);
				i += sub->length - target->length;
				
			}
		}
	}
	str->string[str->length] = '\0';
}
void discardStr(String* str){
	free(str->string);
	free(str);
}
