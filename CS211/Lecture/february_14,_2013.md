#February 14, 2013
***
## Integer Arithmetic
-	Why focus on integer and computer arithmetic?
	-	Finite number of bits (only a specific level of precision), number representaiton (two's complement), develop algorithms easy to implement in hardware.
	
### Unsigned Addition and Subtraction
##### Two's Complement
-	$$$5+6=11$$$ where $$$5 = 0101, 6 = 0110, 11 = 1011$$$
-	Can subtract and add negative numbers and it still works
-	Adding two n bits numbers may result in an n+1 bit number, no space to hold extra bit means modulo.
-	**Overflow** - occurs when the result cannot fit within the size limit of the data type. When executing C programs, overflows are **not** signaled as errors. Rather, we must figure it out ourself.
-	Suppose numbers are stored as 4 bits 2's complement, What is the 2's complement number produced by $$$(1011) + (1110) = 11001$$$
-	Addition is binary addition, ignore carry out.
-	Subtraction is invert subtrahend and add.
###### 	Why does it work?
-	Adding two positive numbers (and two negatives): obvious.
-	Adding positive and negative number? $$$2+(-1)=1$$$
-	Pos number > neg number
	-	Will wrap around $$$\to$$$ 0 MSB
-	Neg number > pos number
	-	Will not wrap around $$$\to$$$ 1 MSB

### Unsigned Multiply
-	How can we compute n x m? $$\sum_{i=1}^m n$$
	-	However this is not very efficient. It depends on magnitudes of the numbers involved.
-	Left shifts and right shifts, displayed as `<<` and `>>` respectively.
	-	`x << 1 = 2*x`
	-	A logical left shift will pad the left bit(s) with 0.
	-	An arithmetic left shift preserves sign.

```
 1011
x 101
------
  1011	(multiplicand x 1) shift left 0
 0000	(multiplicand x 0) shift left 1
10111	(miltiplicand x 0) shift left 2
```
###### Agorithm
1.	Result (product) = 0
2.	If Least Significant Bit of multipler = 1, add multiplicand to result else add 0 to result
3.	Shift multiplicant left by 1 bit (fill LSB with 0)
4.	Shift multipler right by 1 but (fill MSB with 0)
5.	If multipler > 0 , go to 1
6.	Stop
	Because of this, we only need to know how to add and shift in order to multiply.

#### 	Overflow
-	The result of multiplying two n-bits long numbers can be up to 2n-bits long.
-	What do we do with the extra bits? Discard n most signifnicant bits and do modulo, or some processors leave results in two registers so programmer can have the entire result if desired.

### Sign Extension

Signed Integer | 4 bit representation | 8 bit representation | 16 bit representation
----------|------------------|-----------------|------------
+1			|	0001			|	00000001	| 00000000000000001
-1		|		1111		|		11111111	| 11111111111111111

### Unsigned Division
-	How can we compute n/m?
	-	Count how many times we can subtract n from n until the remainder r is less than m
	-	Call this count q $$ n/m = q + r$$
###### 	Code
```
xpos = (x > 0);
ypos = (y > 0);
x = abs(x);
y = abs(y);
quot = 0;
while (x >= 0) {
	quot++;
	x -=y;
}
if (xpos && !ypos || !xpos && ypos)
	return -quotient+1;
else
	return quotient-1;
```

### What the Fuck about Floating Point?
-	**Decimal Scientific Notation** - some magnitude times some power of ten.
	-	$$$1 = 10^0$$$
	-	$$$3000 = 3x10^3$$$
	-	$$$412 = 4.12x10^2$$$
	-	$$$0.001 = 1x10^{-3}$$$
	-	$$$1/3 = 3.3333… x10^{-1}$$$
		-	**Normalizaiton** - magnitude for some number is always 1 or greater and less than 10 *except for 0*.
-	**Inary Floating Point** - Instead of powers of 10, do powers of 2. Some binary number multiplied by 2 to some power.
	-	$$$1 = 2^0$$$
	-	$$$2 = 2^1$$$
	-	$$$4 = 2^2$$$
	-	$$$3 = 11 x 2^0$$$
	-	$$$5 = 101 x 2^0$$$
	-	$$$3 = 1.1 x 2^1$$$
	-	$$$5 = 1.01 x 2^2$$$
		-	Last two occur because every digit passed the point is $$$1/2^x$$$
		-	**Normalized** - First number to the right of the point is always 1, except for 0.
	-	$$$1/4 = 1 x 2^{-2}$$$
	-	$$$1/3 = 1.01010101… x 2^{-1}$$$
	-	$$$1/5 = 1.10011001100… x 2^{-3}$$$
###### Storage

1	|	8	|23
-----|------|
Sign | Exponent| Mantissa

-	$$$1 = 2^0$$$
	-	Sign = 0
	-	Exponent = 0
	-	Mantissa = 1
-	For example, $$$1.0$$$. In hex: `3F800000`. In binary: `0011111110000000000000000001`. Signed bit is first, with the exponent being the next 8. Taking the `0111111` is `7F` in hex.

###### Decompose
```
sign = fpnumber.cpart[3] >> 7;
exponent = (fpnumber.cpart[3] << 1 | fpnumber.cpart[2] >> 7) & 0xff;
mantissa = (fpnumber.lpart & 0x007ffffff);	//Turning off all the high bits
```
###### Compose
```
fpnumber.lpart = 0;
fpnumber.lpart |= (sign && 1) << 31;	//Put sign in bit
fpnumber.cpart[3] |= (exponent >> 1) & 0xff;	//Little endian exponent building
fpnumber.cpart[2] |= (exponent << 7) & 0xff;
mantissa = (mantissa << 24) & 0x007fffff;	//Mask out sign bit, exponent and high bit of mantissa
```

-	**Bitwise or** - $$$0101\ 1001 = 1101$$$.
-	**Bitwise and** - $$$0101\ 1001 = 0001$$$. Turns off bits in other operator.
-	**XOR** - $$$0101\ 1001 = 1100$$$.

###### Takeaways
-	For any non zero there is a hidden bit.
-	Biased exponent - value stored is offset

Exponent we Want | IEEE Representation
---------------|----------------
0				|	127 or 7F
1				|	128 or 80
127				|	254 or $$$2^{127}$$$ or FE
-1				|	126 or 7E
-2				|	125 or 7D
-126			|	1 or $$$2^{-126}$$$ or 01

-	Range is -126 to 127. 0 (`00`) is reserved for real 0, and 255 (`FF`) is for infinity.