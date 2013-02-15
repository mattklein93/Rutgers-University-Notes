#February 7, 2013
***
## File I/O (Continued)
```
#include <stdio.h>
fprintf(stderr, "fmt string", …);
```
-	Used for warnings, errors, usage messages, etc.

```
size_t fread(void * ptr, size_t size, size_t nobo, file *);
size_t fwrite(const void * ptr, size_t size, size_t nobo, file *);
```
-	`fread` takes an input buffer pointer, element size, and the number of objects. It reads a chunk of memory.
-	`fwrite` writes that chunk of memory

```
int getc(file *);
int fgetc(file *);
```
-	Give back a single character, -1 at the end of file. If it is not -1, cast it to a `char` to get the character. It consistently gets the next character in the file. Raw, low level, gets bytes. More freedom because it can get binary data.

```
char * gets(file *s);
char * fgets(char *s, int n, file *);
```
-	Reads into a string, until end of file, or new line (discarded, automatically gives a `\0` or `null` character). If the buffer is not large enough, it keeps reading.
-	`fgets` is better as it reads a max of `n-1` (the -1 comes from the new line) characters or until a new line is reached. `fgets` first char pointer is where the data goes. `s` is then returned, but the end of file returns `NULL`.
-	Still need to use `fclose`, unlike with `stdin` and `stdout` these are not opened so need to close. (If we close them, bad things will happen).

```
void rewind(file *);
	//Or fseek(file *, OL ,seekset);
long ftell(file *);
```
-	`ftell` gives the current offset in the file.
***
## C Preprocessor
```
#include <stdio.h>
#include "myheader.h"
```
-	`#include` is a directive, which means take that file and go get it. If we just use brackets it finds the c file. The double quotes say look in my files, then look in the C files.

### Macros
```
#define SOME_ID
#define ASIZE 100
#define MAX(A,B) ((A) > (B) ? (A) : (B))
```
-	By convention, all define's should be in caps.
-	Easier to use, such as changing the size or something without breaking our program. Puts all sizes to one lace.
-	The third kind of macro, the `MAX` macro, will send all parameters and send `((A) > (B) ? (A) : (B))` as the output
##### 	For Example
	```
	int x,y,z;
	y = 3;
	z = 5;
	x = MAX(y,z);
	x = MAX(y++, ++z);
	```
	-	`x = MAX(y++, ++z);` must be expanded to x = ((y++) > (++z) ? (y++) : (++z))`
		-	However this is a problem, because we are using our arguments more than once.
>	It's just text substitution, however if we do something like this we may getting uninteded behaviors.

###### More Trouble
```
#define SQUARE(x) (x)*(x);
y = SQUARE(z+1);
y = (z+1)*(z+1);
```
-	Paranthesis are required, or we can get side effects. However, even with paranthesis there can be issues with things like `y++` and `++z`.

### Conditional Compilation
```
#if EXPRESSION
	//If true, run
#elif EXPRESSION
	//Might have this
#else
	//Or run this
#endif
```
-	Can create a lot of trouble. The compiler makes the decisions during compile time.
-	No need to use curly braces to execute multiple lines. Also possible to nest these expressions.

```
#ifdef some #define
#endif
#ifndef some #define
#endif
```
-	If a macro is defined, then it executes some specific code. Same if not if not defined. If defined is `#ifdef` and if not defined is `#ifndef`
##### Examples
```
#if SYSTEM == SYSV
#include "SYSV.h"
#elif SYSTEM == BSD
#include "BSD.h"
#elif SYSTEM == MSDOS
#include "MSDOS.h"
#else
#include "DEFAULT.h"
#endif
```
-	This can change code compiled per operating system.

```
#ifdef DEBUG
	printf("got to line %d file %s\n", __LINE__,__FILE__);
#endif
```
-	`gcc -DDEBUG mysource.c` defines the macro.
-	`gcc -DASIZE = 200 mysource.c`
-	To use more than one, include as many `-D` as required.

### Takeaways
-	Can use other preprocessor's in these.
***
## Makefiles
-	The beauty is I have all my information in it, and to make it of any complexity, I can use the simple command `make`.
-	The first part is the **macros**. They identify something else.
-	It builds only what needs to be rebuilt.
-	**Follow all with a colon :**
-	Whenever we use a macro, use `$(name)`.
-	`make clean` is encouraged. Make it the last one, and it does the command underneath it.
##### Makefile Commands

```
Makefile
makefile
s.Makefile
s.makefile

make -f prog1.mak
make -i	
make -n
```
-	`make -n` shows what will run, but does **not** execute them.