# January 31, 2013
---
## String Functions from string.h
-	All string functions believe it is a sequence of chars terminated by a null 	sequence

### String Copy
 
```
char * strcpy(char *s1, const char *s2);			//Second into first
char * strncpy(char *s1, const char *s2, int n);	//Copies at most n bytes
```
-	Both most point to something valid in memory, or segfault occurs
- - -
### String Concat

```
char * strcat (char *s1, const char *s2);
char * strncat (char *s1, const char *s2, int n);
```
- These concatinate the second char set to the first
--  -
### String Compare

```
int strcmp (const char *s1, const char *s2);
int strncmp (const char *s1, const char *s2, int n);
```
-	If 0, the two strings are equal.
-	If > 0 then the second is larger
-	If < 0 then the first is larger
	-	Larger means lexicographic ordering
-	strncmp compares up to n characters
-	These are case **sensitive**, stricmp and strincmp are **case-insensitive**
##### Examples
*	"A" < "B"
*	"AB" < "B"
*	"ABC" > "AB
*	"ABC" < "AC"

---
### String Length
```
int strlen(const char *s);
```
-	The string length **does not** count the null character at the end