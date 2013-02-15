# February 12, 2013
***
## Data Representation
-	Computers manipulate stored information. Stored in 8 bit bytes. Everything is in bytes.
-	Decimal number system is natural for humans, because we have 5 fingers each hand.

Display Form	|	Meaning
-----|----
`0b`	|	binary
`0x`	|	hex
`0o`	|	octal

### Number Systems
-	Compromises a set of numbers, operations, and the rules. We need to assign values to numbers. Numbers are written as $$$d_n…d_2d_1d_0$$$. Each digit is in [0-9].
-	Value of a number is computed by $$$\sum_{i=0}^n d_ix2^i$$$
-	Binary representation is used in computers (easy to represent by switches)
#### Hexadecimal Numbers
-	Base 16. Contains 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F. First 10 symbols are the same, with A = 10, B = 11, C = 12, D = 13, E = 14, F = 15.
-	Written as $$$\sum_{i=0}^n d_ix16^i$$$
#### Octal Numbers
-	Base 8. Is [0-7]. Numbers still written as $$$d_n…d_2d_1d_0$$$ and represented as $$$\sum_{i=0}^n ix8^i$$$
### Hex to Binary
-	Represented by 4 binary digits. 0x2A8C = 0b0010101010001100
### Octal to binary
-	Convert each to 3 bits, then string it to together.
> 	Real programmers use hex, octal is too awkward.
### Binary to Hex
-	Do reverse, grab each set as 4 digits and change to each to hex. Go right to left.
### Decimal to Binary
-	What's the largest p,q, r… such that
	-	$$$2 = 2^p + r_1$$$, where $$$r_1 < 2^p$$$
	-	$$$n - 2^p = 2^q + r_2$$$, where $$$r_2 < 2^q$$$
	-	$$$n - (2^p + 2^q) = 2^r + r_3$$$ where $$$r_3 < 2^r$$$
### 	Fractions
-	Represented as $$$2^52^42^32^22^12^0.2^{-1}2^{-2}2^{-3}…$$$ or each has $$$1/2^i$$$ for each ith slot.
#### Data Sizes
-	Only pointers are different on 64bit machines with 8 byte pointers, instead of 4 byte pointers.
#### Big Endian vs Little Endian
-	The question posed is, is it `A0BC0012` or `1200BCA0`
	-	**Big Endian** - most significant byte first (biggest value), with decreasing numeric significance as address increases
		-	For example : `0x01020304` with most signifcant being `01`. Motorola, IBM, SPARC use this.
	-	**Little Endian** - least significant byte first (smallest value), with increasing numeric significance as address increases
		-	For example : `0x01020304` with the least significant being `04`. Intel, VAX, Z80 use this.
-	How to determine value when have a binary number spread across multiple bytes.
-	It matters because it interprets machine code and values, and one computer sending data to another, so we must convert before.
-	Neither is inherently superior.

### Representing Integers
-	Signed quanitites can be negative.
-	An unsigned integer in bits: $$$0…2^n-1$$$. How do we represent negative numbers? We use **signed maginitude**. One bit (left most) is for a sign with the rest being the number.
	-	$$$10000_{10} = 00002710$$$
	-	$$$-10000_{10} = 80002710$$$
-	range of $$$-2^{n-1}…2^{n-1}$$$
-	Both 0 and -0 are able to be displayed, this is a complication of signed values.
-	Lowest 8bit byte is $$$-2^7 = -128$$$
-	Highest is $$$2^7-1 = 127$$$
-	Lowest 16bit byte is $$$-2^{16} = -32767$$$
-	Highest is $$$2^{16}-1 = 32767$$$
-	Lowest 32bit byte is $$$-2^{32} = -2147483648$$$
-	Highest is $$$2^{32}-1 = 2147483647$$$
#### One's Complement
-	Flip the bits
	-	$$$10000_{10} = 00002710$$$
	-	$$$-10000_{10} = FFFFD8EF$$$
#### Two's Complement
-	All zero's and positives are represented the same way. $$$00002710$$$
-	Get a negative by: flip the bits, then add one. 
-	Advantages
	-	All (math functions like additon subtraction and multiplcation) are identical for positve and negative numbers.
	-	Simplified because we have only one zero
-	Range is $$$-d_{n-1} 2^{n-1} + \sum_{i=0}^{n-2} d_i 2^i$$$
#### Example One
-	Flipped - $$$FFFFD8EF$$$
-	Add 1 - $$$FFFFD8F0$$$

#### Example Two
-	Original $$$00000000$$$
-	Flipped $$$FFFFFFFF$$$
-	Add One $$$00000000$$$

#### Examples
-	$$$1 = 0x2^{31} +1 = 000000001$$$
-	$$$-1 = -1x2^{31} + 2^{31}-1$$$
	
-	$$$1000_{10}=0000003E8$$$ 
-	$$$0x2^{31}+1000_{10}=1000$$$
	
-	$$$-1000_{10} = FFFFFF218 = -1 x 2^{31} + 2147482651 = -100000$$$

### ASCII
-	A character is stored as 1 byte, originally only used 128 values (7 bits). Digits are all together consecutively.

```
//ASCII to Integer
int atoi(char * s) {
	int value, mult;
	if (*s == '-') {
		mult = 1;
		++s;
	}
	else if (*s == '+') {
		mult = 1;
		++s;
	}
	else
		mult = 1;
		
	value = 0;
	while (isdigit(*s)) {
		value = 10*value + (*s -);
		++s;
	}
	return mult*value;
}
```
-	This program converts each each integer to ascii.

### Unicode and UTF-8
-	Characters for other languages, standard that defines more than 107,000 characters across 90 scripts.
-	Most common is UTF-8.
	-	Variable length encoding of Unicode: 1-4 bytes for each character.
	-	1-byte form is reserved for conversation to ASCII
	
### Floating Point and Numbers
-	Integers typically written in ordinary decimal form, but can also be written in scientific notation.
	-	Single precision - 32 bits
	-	Double precision - 64 bits
	-	Extended precision - 80 bits
-	A float in C is a 32 bit single precision. his is the float type.
-	A double in C is 64 bits double precision.
-	Some representations are `NaN` or not a number.
##### Example
-	$$$12.375 to 1100.001 from 12 + 1/4 + 1/8$$$
	-	Shifted down to $$$1.100011x2^3$$$
	-	From $$$127+3=130$$$
#### Extended Precision
-	80 bits used to represent a real number.
-	1 sign bit, 15 bit exponent, 64 bit mantissa. 20 decimal digits of accuracy. Not supported in C.