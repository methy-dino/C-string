#include <stdlib.h>
#include <stdio.h>
#include "debug/string_debug.h"
//#include "string.h"
int main(){
	char a[36] = "atireiopaunogato,ogatonaomorreu-reuz";
	char b[2] = "to";
	char c[3] = "tos";
	String* str = buildStr(a, 36);
	String* target = buildStr(b,2);
	String* sub = buildStr(c,3);
	replaceLastStr(str, target, sub);
	toUpperCase(str);
	printf("new = %s", str->string);
	//char* b = &a;
	/*	for (long long i = 0; i < 999; i++){
		String* str = buildStr(a,10);
		growStr(str, 10);
		discardStr(str);
	}*/
	//char* sub = (char*)malloc(2);
	//sub[0] = 'l';
	//sub[1] = 'l';
	//String* str2 = initString(sub, 2);
	//printf("%s\n", str->string);
	//removeChar(str, '1');
	//printf("%s\n", str->string);
	//char hello[6] = {'h','e','l','l','o'};
	//appendArr(str,hello,6);
	//printf("%s\n", str->string);
	//removeChar(str, 'l');
	//printf("%s\n", str->string);
	//printf("%d\n", indexOfStr(str, initString(sub,2), 0));
	return 0;
}
