#February 5, 2013
***
## I/O in stdio.h
-	There is no official checking of the types of the arguments and the format specifiers

```
#include <stdio.h>

int printf (const char *, …);	//We can take any number of arguments by the …'s. Returns length

```
##### Formatting ([ ]'s means optional parameters)
-	**Character** - ```%[-][width]c``` - Displays a character with the specific width
	*	```%c```	-	Not justified
	*	```%3c```	-	Right justificed
	*	```%-3c```	-	Left justified

-	**String** -  ```%[-][width][.precision]s``` - Prints a string 
	-	Precision is the number of characters to print
-	**Integers** - ```%[-][+ or _ (_ is a blank)][width][l]d``` - Prints an integer
	-	l means treat as *long*
	-	The + is *positive only*
		*	% d 43
		*	%+d+43
###### 	Alternate Ways to Displays Intgers
	-	```%[-][#][width][l]u``` - unsigned (0 or greater)
		-	%u 777626577
	-	```%[-][#][width][l]O``` - Octal numbers
		-	%O 5626321721
	-	```%[-][#][width][l]o``` - Octal
		-	%#o 05626321721
	-	```%[-][#][width][l]X``` - Hex numbers
		-	%x	2E59A3D1
	-	```%[-][#][width][l]x``` - Octal
		-	%#x 0x2E59A3D1
		-	The # sign is for a 0 a O/o or a X/x in front
-	**Floating point** - All are passed as *doubles*
	-	```%[-][+ or _][#][width][.precision] f``` - no exponent
	-	```%[-][+ or _][#][width][.precision] e``` - exponent
	-	```%[-][+ or _][#][width][.precision] E``` - exponent
	-	```%[-][+ or _][#][width][.precision] g``` - auto
	-	```%[-][+ or _][#][width][.precision] G``` - Auto

###### Special \ Keys
-	```\n``` - New line to next line
-	```\r``` - Goes to new line but starts at the previous line
-	```\0 digits``` - Octal
-	```\X digits``` - Hex

###### Examples
```
int i = 42;
char str[] = "hello";
char * ps = " i am fine";
float e = 2.218;
printf ("str is %s, i is %d, e is %g\n", str, i, e);
```


### Warnings
>	To use %s, we must point to a null terminated string. Without doing this, we will get a segfault. Nobody checks if I specifiy multiple format items and use the wrong amount. This must be checked by ourselves.


### File Output
```
int fprintf(file *, const char *, …);	//Returns length
int sprintf(char *, const char *, …);	//Returns length
```
-	```fprintf``` - writes to a file
-	```sprintf``` - Attaches the rest of the characters the first character
	-	Sprintf does **not** automatically allocate memor


### File input
```
int scanf(const char * fmt, …);		//Returns the number matched
```
-	```%c[width]c```	- Characters
-	```%[width]s```	-	Strings, reads up to white space
-	**Integers**
	-	l or h for a long
	-	```%[width][l or h]d``` - signed
	-	```%[width][l or h]u``` - unsigned
	-	```%[width][l or h]o``` - octal
	-	```%[width][l or h]x``` - hex
-	**FLoating point**
	-	```%[width][l]f``` - 
	-	```%[width][l]e``` - Exponent
	-	```%[width][l]g``` - No exponent
-	**Scanset**
	-	```%[*][width]scanset```
		-	**Example**
			-	Must use  the [ ] in declaration
			-	Things that are not format items can be placed in the scanset
			-	```%[abcd]```
			-	```%[a-z]```
			-	```%[a-f0-9]```
			-	```%[`n]\n```[^1] - the ` means **not**, this example is everything that is not the new line

	###### Example
	```
	while (scanf("%d", &someint) > 0)
	```
	-	Expects an integer, goes until one is not found
	

```
int fscanf(file *, const char *fmt, …);
int sscanf(const char *, const char *fmt …);
```

>	For sscanf, read as command line. sscanf lets use read a string and put it into a number


###### 	For example
	
	
	int main (int argc, char** argv) { 
	int i;
	for (i = 0; i < argc; i++) {
		if (sscanf(argv[i], "%d", &x) > 0)
			printf("argv[%d] is %d\n", i, x);
		else
			printf("program only wants numbers numbskull.");
	}
-	This can only read numbers

### Opening and Reading Files
-	Five basic file operations: open, close, read, write, and move (seeking)
-	Opening is us asking the operating system to open it.
-	When we are reading or writing, this will maintain where we currently are. Reading more than once remembers were we left off

>	A sharp scaple in the hands in a surgeon is good. In Java, sharp things are dangerous. The responsibility is for you.

```
#include <stdio.h>
file * fopen( const char * name, const char * type);
```
-	We can pass file name, file path, and relative file path
	-	###### 	For example	
	-	`"input.txt"` - Simple file name in current directory
	-	`"../otherdir/input.txt"` - Relative path name, from where I currently am. This one in particular states go up one directory, then to otherdir, then input.txt
	-	`"/users/bkr/cs211/prog1/input.txt"` - Full path, or *absolute* path. Does not matter where I am.

Mode	|	Explanation
--------|--------
r		|	Read at beginning
rb		|	Read a binary file
w		|	Write (Creates if not existence)
wb		|	Write a binary file
a		|	Open for output, but appends to end
ab		|	Open a binary for output, creates if it doesn't exist
--------|-----------
r+		|	Read and write
r+b		|	Read and write a binary
rb+		|	Read and write a binary
w+		|	Truncate or create
w+b		|	Truncate or create a binary
wb+		|	Truncate or create a binary
a+		|	Open at end, or create a new
a+b		|	Open at end of a binary
ab+		|	Open at end of a binary

>	I am Morbius because Brian Russell is a common name. They finally made me pick one. Forbidden Planet 1956, a character is named Morbius so I went with that name. He is the father of the daughter.	

##### Moving around

```
int fseek(file *, long offset, int whence);
```
-	`whence` can be `seekset`, `seekcur`, `seekend`
	-	`seekset` is from the beginning, only positive
	-	`seekcur` is where I currently am. Forward is positive, backwards is negative.
	-	`seekend` is from the end, and is always a negative nummber
	
##### Closing a File
```
int fclose(file *);
```
-	Close it when done. **Important for correctness** due to buffered I/O operations, but it is not written. 
-	`fclose` actually saves the file


[^1]: Morbius's favorite