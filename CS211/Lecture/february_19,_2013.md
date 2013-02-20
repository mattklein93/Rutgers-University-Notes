#February 19, 2013
***
## Shifting and Shitting
### Bit-Ordering
-	Most significant bit (in 32bit word) is 31, while the least is 0. For something with 16bit word the most is 15. **Nothing** to do with byte-ordering (big-endian and little-endian), it is just a convention.

#### Left Shifting
-	In C, operators are `<<` and `<<=`. High-order bits are lost. Shifting left $$$n$$$ bits is the same as multiplying $$$2^n$$$. For example, $$$4$$$ bit shift is $$$2^4$$$.

$$Shift\ N\ Bits = x*2^N$$

- `0000 1000 << 2` is `0010 0000`
- `1000 1001 << 2` is `0010 0100`
-	Shifting any N bit number N results in **zero**.

#### Right Shifting
-	In C operators are `>>` and `>>=`. Same as left shifting, it is some number of bits. Must be positive. Low-order bits are lost. These are diving by $$$2^N$$$.

$$Shift\ N\ Bits = x/2^N$$

-	There are *arithmetic* and *logical* right shifts.
	-	**Logical** - new high bits are zero.
	-	**Arithmetic** - sign preserving.
		- See [wikipedia](http://en.wikipedia.org/wiki/Bitwise_operation#Bit_shifts) for example and more infromation.
		
	- `y = x >> 2` and `y >>= 2`
	
#### Bitwise Operations: And, Or, Exclusive Or, Not
-	Act on all the bits all at the same time.

###### And
-	C Operator is `&`. For a `1`, they both must be `1`.

```
	1100 |				0 |		0 |		1 |		1
&	1010 |	 --->	& 	0 | &	1 | &	0 | &	1
-------- |		   ------ | ----- | ----- | -----
	1000 |				0 |		0 |		0 |		1
```

###### Or
-	C operator is `|`.

```
	1100 |				0 |		0 |		1 |		1
|	1010 |	 --->	| 	0 | |	1 | |	0 | |	1
-------- |		   ------ | ----- | ----- | -----
	1110 |				0 |		1 |		1 |		1
```

###### Exclusive Or (XOR)
-	C operator is `^`. If they are the same, you get 0.

```
	1100 |				0 |		0 |		1 |		1
^	1010 |	 --->	^ 	0 | ^	1 | ^	0 | ^	1
-------- |		   ------ | ----- | ----- | -----
	0110 |				0 |		1 |		1 |		0
```

###### Not
-	C operator is `~`. Flips bits.

```
	1100 |		 --->	0 |		0 |		1 |		1
```

#### Logical Operations: And, Or, Not
-	These are used for comparisons. Unlike in Java, we can capture these results as a `1` or a `0`.
###### And
-	In C, Operator is `&&`, enables **lazy evaluation** if left most is false:
```
if (p != 0 && p->value > 32)
```
###### Or
-	In C, Operator is `||`, enables **lazy evaluation** if left most is true:
```
if (p != 0 && p->value > 32)
```
###### Not
-	In C, Operator is `!`.

- Unlike in Java, we can capture these results as a `1` or a `0`.

```
int k,l,m;
k = l > 5 && m < 6;
k = l && m;
```

-	`A || B = !(!A && !B)` and `A && B = !(!A || !B)`

Operator | Precedence
-------|-------
`!`	|	1
`&&`	|	2
`\|\|`		|	3

#### Masking
>	Capture or manipulate multi-bit values that don't fit on byte boundaries or in some fixed number of bytes.

-	Use masking to get sets of bits. Using a bitwise or, will ensure that certain bits are turned on (Displayed as 1). Using a bitwise and, will ensure that certain bits are turned off (Displayed as 0).
###### For Example
-	32 Bit floating point capture mantissa by doing a mask of `00 7F FF FF`
-	64 Bit floating point capture mantissa by doing a mask of `000F FFFF FFFF FFFF`
###### Specific Bits
-	Set bit N = 1 in X - `X |= (1 << N)`
-	Set bit N = 0 in X - `X &= ~(1 << N)`
	>	I have n-1 bits, a single 1 bit. Now with the & it is turned off
	
-	Toggle Bit N in X - ` X ^= (1 << N)`

#### Using Two's Complement
-	Do X and Y have the same sign?
	-	`(x^y) < 0`

##### Swapping Fixed-Point X and Y
```
x ^= y
y ^= x
x ^= y
```

#### Rotation
```
unsigned int rshift(unisgned int val, unsigned int n) {
	unsigned int intsize = sizeof(int)*8;
	if (n == 0)		//Zero bits is a no-op
		return val;
	else
		return val >> n | val << (intsize-n);
}
```