#February 28, 2013
***
## Assignment Grades
-	10 days for questions on grade, sooner the better. After 10 days, that window closes.
***
## Assignment 2
-	C ints are a mistake. Use C ints if you want, if you use some other representation, that is extra credit. Using C ints will not work for multiplication, only your arbitrary representation.
-	Using `printf` can not use `%d %g %e` only '%s %c'.
***
## Fuck me in the ASS-embly (Part 3)
### Shift Instructions
```
	sal	[b]	src,dst		Left Shift Arithmetic Sign Preserved
	shl	[w]	src,dst		Left Shift Logical Gives 0's at LSB
	sar	[l]	src,dst		Right Shift Arithmetic Sign Preserved
	shr	[q]	src,dst		Right Shift Logical Gives 0's at MSB
```
-	Binary operators, take two operands. `dst` can be memory or a register. `src` is an immediate or `%cl`. `dst` is shifted. `src` is how much.

### Rotation Instructions
```
	ROL	[b]	src,dst		MSB->LSB
	ROR	[w]	src,dst		LSB->MSB
	RCL	[l]	src,dst		MSB->CF->LSB	(Left rotate through carry, treated as extra bit)
	RCR	[q]	src,dst		LSB->CF->MSB	(Right rotate through carry, treated as extra bit)
```
-	`dst` can be register or memory, `src` can be immediate or register. `dst` is rotated. `src` is how much.

### Takeaways
-	If I add two n bit numbers, the sum is not more than n+1 bits.
-	The product of any two n bit numbers, will require not more than 2n bits.
-	If N bits is unsigned: $$$0...2^n-1$$$
$$2^n-1 * 2^n-1 = -2^n+1 +(2^n)^2-2^n = 2^{2n}-2^{n+1}+1$$
-	Largest possible product is $$$2^{2n}-2^{n+1}+1$$$
-	If N bits is signed: $$$-2^{n-1}…2^{n-1}-1$$$
$$2^{n-1}-1*2^{n-1}-1 = -2^{n-1}+1 + (2^{n-1})^2-2^{n-1} = 2^{2n-2}-2^n+1$$

### Multiplication
```
		Unsigned
	mul [b]	One operand (Register or memory, **not** immediate)
		[w]
		[q]
		[l]
```
```
	mulb	%ax := %al&*opnd8
	mulw	%dx:%ax := %ax*opnd16		Register pair: ax gets the low half, dx gets high half. They are implicit.
	mull	%edx:%eax := %eax*opnd32
	mulq	%rdx:%rax := %rax*opnd64
```
-	Register pairs are implicit, we do **not** code them.

#### Signed Multiplication
```
		Signed
	imul [b]	One operand (Register or memory, **not** immediate)
		 [w]
		 [q]
		 [l]
```
```
	imulb	%ax := %al&*opnd8
	imulw	%dx:%ax := %ax*opnd16		Register pair: ax gets the low half, dx gets high half. They are implicit.
	imull	%edx:%eax := %eax*opnd32
	imulq	%rdx:%rax := %rax*opnd64
```

### More Multiplication (Signed)
### 16Bit
```
	imul	mem,reg16			reg16 *= mem
			reg16_s,reg16_d		reg16_d *= reg16_s
			imm8,reg16			reg16 *= imm8
			imm16,reg16			reg16 *= imm16
```

### 32Bit
```
	imul	mem,reg32			reg32 *= mem
			reg16,reg32			
			reg32_s,reg32_d		reg32_d *= reg32_s
			imm8,reg32			
			imm16,reg32			
			imm32,reg32			
```
### 64Bit
```
	imul	mem,reg64			reg64 *= mem
			reg16,reg64			reg64 *= reg16
			reg32,reg64			reg64 *= reg32
			reg64_s,reg64_d		reg32_d *= reg32_s
			imm8,reg64					
			imm16,reg64			
			imm32,reg64						
```

### Division
```
	Unsigned One Operand
	div	[b]	opnd			divb %al := %ax/opnd; %ah := %ax mod opnd
		[w]					divw %ax := %dx:%ax/opnd; %dx = %dx:%ax
		[l]					divl %eax := %edx:%eax/opnd; %edx := %ex:%eax mod opnd
		[q]					divq
```
-	opnd is memory or reg. Not IMMED.
```
	Signed One Operand
	idiv	[b]	opnd			idivb %al := %ax/opnd; %ah := %ax mod opnd
			[w]					idivw %ax := %dx:%ax/opnd; %dx = %dx:%ax
			[l]					idivl %eax := %edx:%eax/opnd; %edx := %ex:%eax mod opnd
			[q]					idivq
```
>	Dividing by zero is bad. Your programm will stop running.