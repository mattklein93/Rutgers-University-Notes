#February 19, 2013
***
-	Practice site - [leetcode](www.leetcode.com). The practice problems are good for help with internship.
###### 	Number of times screen was off - 3

### Continue Problem Set 1
#### Problem 3
```
int x = 42;		//Address is 100
int y = 13;		//Address is 104
int *p;			//Address is 108
int **p2;		//Address is 112
/*1*/
p = &y;
p2 = &p;
/*2*/
*p2 = &x;
**p2 = 11;
/*3*/
*p = 12;
/*4*/
```

variable	| Loc 1 | Loc 2 | Loc 3 |	Loc 4
-----|------|-------|------
x	|	42	|	42	| 	11	|	12
y	|	13	|	13	|	13	|	13
p	|	Nothing	|	104	|	100	|	1 00
p2	|	Nothing	|	108	|	108	|	108

#### Problem 4
```
int * foo (int x) {
	int a[2];
	a[0] = x;
	a[1] = x+1;
	return a;
}

…
int *p1 = foo(2);
int *p2 = foo(3);
```
-	`p1[0]` - `2`
-	`p1[1]` - `3`
-	`p2[0]` - `3`
-	`p1[1]` - `4`
	>	This is wrong because in memory `ESP` from function call will always point to the top, new stacks will be created. 
	
### Second Project Info
##### How to Convert a Number to it's Complement
-	Given a number, `23`, how to convert to binary:
	-	$$$2^0 2^1 2^2 2^3 2^4 …$$$ pick largest, but not over the number. That is our total size, so here will be $$$10000$$$. Continue to go down, changing where the 1 is based on the exponent. See [here](http://www.wikihow.com/Convert-from-Binary-to-Decimal).
-	Converting [One's Complement](http://en.wikipedia.org/wiki/Ones'_complement) to `-23` is to:
	1. Convert each bit
	2. Add one	
	3. $$$11101001$$$
-	What about going back to `23`?
	-	This does not account for overflow where max is $$$2^{31}-1$$$. The minimum is $$$(-2^{31}-1)-1$$$