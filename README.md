###### C-String, yet another dynamic string library.

##### the String type overview.

#### it's variables
String.string, it is pretty self explanatory, it's a char* that contains the null terminated string used and read by operations. \
String.length, this uint is supposed to point to the index of the first null terminator of the String, (IT IS NOT UPDATED OUTSIDE OF FUNCTIONS).\
String.maxCapacity, it's the quantity of allocated bytes in String.string, the default methods will grow the String if it is full.\
