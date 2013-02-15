# February 5, 2013
***
## Makefile
-	Script to run several commands
-	Compiles all files together, no need to type the gcc commands over and over
-	Composed of three parts, macro, rules, and deletion
-	[How to make](http://www.opussoftware.com/tutorial/TutMakefile.htm)

###### File1 Example

```
#include <stdio.h>

void print();

void main() {
	print();
}
```

###### File2 example

```
#include <stdio.h>
#include "print.h"

void print() {
	printf("%d: Hello CS211!\n", CS211");
}
```

###### Header file

```
#define CS211
```

### Creating the Makefile
-	Enter vim to create a ```makefile``` named ```makefile```

```
COMPILER = gcc
CCFLAGS = -ansi -pedantic -Wall

all: file1

file1: print.o file1.o
	$(COMPILER) $(CCFLAGS) -o file1 print.o file1.o
print.o: print.c
	$(COMPILER) $(CCFLAGS) -c print.c
file1.o: file1.c
	$(COMPILER) $(CCFLAGS) -c file1.c
```
### Running the makefile
-	In order to run, just type ```make``` in terminal
***

## Pointers
-	**Pointer** - a variable which contains the address in memory of another variable
-	A pointer (1) to another pointer (2) will point to the second's address
-	For example, at slot ```0019``` pointer to ```0015``` pointing to ```0001``` will produce ```0019```'s memory of ```0015```, and ```0015``` will point to ```004```
>	Every pointer will need 4 bytes because 4bytes is 32bits.

```
int x = 1, y = 2;
int *ip;
ip = &x;	//Get the address of x (Uses the & sign)
y = *ip;	//Gives ip's value to y (Uses the * sign) **Dereferences**
```
###### Pointer Exercise
>	Assume the address of c is 6940, of d is 9772, of e is 2224. What is the output of the following code?

```
char c = 'T', d = 'S';
char *p1 = &c;
char *p2 = &d;
char *p3;
p3 = &d;
printf("%c\n", *p3);	//character 'T'
p3 = p1;
printf("%c\n", *p3);	//'T'. Outputs the value at this address
printf("%d\n", p3);		//
*p1 = *p2,
printf("%c\n", *p1);	//6940
printf("%c\n", p1);		//6940
```
>	Char pointers only have **one** byte per character. One pointer accounts for 4 bytes. Originally p1 is pointing to 6940, p2 is pointing to 9772, and p3 is also pointing to 9772. After p3 = p1, p3 becomes 6940. Doing *p1 = *p2, character c becomes 'S'.

##### Pointer Mistakes
>	Using a pointer as a function allows for easy mistakes.

-	The best example is the swap function. This is becuase it passes a **copy** of the values, not the actual values. 

```
void swap (int va, int vb) {
	int temp = va;
	va = vb;
	vb = temp;
}

void main() {
	int va = 9, vb = 8;
	printf("%d, %d\n", va, vb);
	swap (va, vb);
	printf("%d, %d\n", va, vb);
}
```
###### Proper Swap
```
void swap (int *va, int *vb) {
	int temp = *va;
	*va = *vb;
	*vb = temp;
}

void main() {
	int va = 9, vb = 8;
	printf("%d, %d\n", va, vb);
	swap (&va, &vb);				//Need to pass address
	printf("%d, %d\n", va, vb);
}

/*
void main() {
	int t = 9;
	int *va = *t;
	int vb = 8;
	printf("%d, %d\n", va, vb);
	swap (&va, &vb);				//Need to pass address
	printf("%d, %d\n", va, vb);
}
*/
```
***
## File I/O
-	Use the [fgets](http://www.cplusplus.com/reference/cstdio/fgets/) ```char * fgets (char * str, int num, FILE * stream);```
-	Where ```str``` is the input, the ```num``` is the size, the ```stream``` is the output stream

###### Inside input.txt
```
CS211 hello world!
cs222 world hello!
```
###### Code Example

```
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1000

void main() {
	FILE *input;		//File pointer
	char buffer[BUFFER_SIZE];	//Max size. The name of the array is the address of the array
	input = fopen("input.txt", "r");	//Open file, second parameter is mode
	if (input != NULL) {…}
	while (fgets(buffer, sizeof(buffer)/sizeof(char), input)) {
		
		printf("%s", buffer);
	}
}
```