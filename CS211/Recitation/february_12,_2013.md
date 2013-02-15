#February 12, 2013
***
## Debugging and GDB
###### Example Program
```
#include <stdio.h>
#include "a.h"			//Should be in same directory. If it is upper, use "../a.h"
//#include "/home/etc"	Absolute path starts with /

int fun() {
	int i = 0, result = 0;
	for (; i < 10; i++)
		result += i;
}

void main() {
	int ret = fun();
}
```
-	First way is to use `printf(…)` statements.
-	Second way is to use `gdb`.
-	Compile using `gcc -g file` and then run `gdb file`.
	-	Set a **breakpoint**, or a stop sign. Use command `b 3`, or `b "line"` The address given back is the address of that line.
	-	Can set multiple breakpoints, using the same command.
	-	Run using `run` or `r`.
	-	To print a variable, using `p "var"`.
	-	Use `next`, `n`, `step`, to continue. `step` can move into a function such as `strlen()` and `next` can not. `c` runs until the next breakpoint.
***	
## Pointers in Functions

## Arrays and Pointers

## Passing an Array to a Function

```
void fun(char *array) {
	printf("%s\n", array)
}

void main() {
	char array[] = {'1', '2', '3', '4', \0};
	char *array1 = "1234";				//These are the same, both have size 5
	fun(array);
}
```
-	Can pass a pointer to the function (best), or the array itself, `void fun (char array[])` or even the size, `void fun (char array[5])`.
###### Two Dimensional Array

```
void fun(char (*array)[3]) {	//Or array[]2][3]
	int i, j;
	//loop
		//loop
}

void main() {
	char array[2][3] = {{'1', '2','s'},{'3', '4','d'}};
	char *array1 = "1234";				//These are the same, both have size 5
	fun(array);
}
```