# February 6, 2013
***
## Office Hours
-	Declare everything in a header file before it is used
-	Can we use BST with linked list nodes?
	-	Yes. Our efficicency must work reasonably well in quadratic form.
-	With traversing through the linked list with pointers:
	-	Adding it in should be a fixed number of steps, such as a low number of lines. In order to add between, need a pointer to a previous and a next, 
-	What is in the header file?
	-	`Types`, `structs`, `unions`, `enums`, functions declared (unlike `int main()`).
	-	If `struct` is used more than once, put it in header file. Such as using it here and there.
	-	Put functions in a header file, they must be declared or defined, or else you are given warnings. Without prototypes, compiler freaks out and will fuss. Helps prevent errors.
-	Producing wordstat executable is up to you. No need if definitions in a different file, or as long as they 
-	Using `char ** argv`
	-	`argv` points to an array of `char*` (strings). The first address is the name. This is how we can run our program and enter a file.
	-	```
		char *s;
		scanf("%s", s);
		```
		**NOTHING IS MALLOCed in this program**.
-	Max length of words: 80 or so
-	Deallocating memory from a string (rest of the length of a string, chopping up a chunk)
	-	You can only free what you've taken, so don't allocate as much, instead read into a buffer then allocate based off that size.
-	`free` what is `malloc`ed
	-	All the extra spaced is reclaimed by the opearting system, and it goes away.
>	Take all the memory you want, but you better free it
-	Does not matter if `wordstat.c` and `wordstat.h` are called wordstat.
-	Warning with `realloc`:
	-	The pointers may be in different spots, so we must point in the right spot.
	-	If I give pointer to free, I can't use it again. If I pass to realloc, I can't use it again.
	
	```
	p = malloc(100);
	p = realloc(p,200);
	```

```
char *s = "CS211";
char c;
c = s[5];
printf("%s\n", s");
s[5] = '4';	//Won't work
```
>	This is different from an array, such as `char array[] = "CS211"`, as CS211 is placed into the array. In memory, all these strings are put together one after the other. All constants are read only. 

-	How do you modify a pointer?
	-	Modifying what it points to - modify the refrence
***	
## STDERR
-	In C, there is low level I/O. All communication is done using a file descripter, or an integer. No opened files, already has 3. STD input, Out, and Error. Input = 0, Out = 1, Error = 2. A file descripter is **not** a file pointer.

```
FILE *p;
p = fdopen(2, "w");	//Converted to an error to write. Converts a file descripter to a pointer
fprintf(P, "format string", …);
```	
***
## Dealing with Segfaults
-	`printf("GOT TO LINE %d FILE %s\n", __LINE__, __FILE__);` use this to figure out between what lines have crashed or just use a debugger
***	