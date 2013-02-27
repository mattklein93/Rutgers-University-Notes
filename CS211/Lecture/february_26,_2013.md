#February 26, 2013
***
## ASS-embly Continued
```
imm(%esp, %eax, 4)	;(imm is displacement, %eax is index register, # is scale by 1,2,4 or 8)
```
-	This address is the `immediate value + %esp + 4*%eax`.
### Auto arrays:
```
	movl	%edx, -48(%rbp,%rax,4)	;Scale by 4 because its the size of an int. 
```
### Formal parameter array element access
```
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	-24(%rbp), %rax
	movl	-4(%rbp),%edx
	movl	%edx, (%rax)
	addl	$1, -4(%rbp)	;Auto scalar variable access
```
-	Paranthesis around register, take the memory from that address. Indirect addressing.
-	Loops are represented by jumps and conditions.
### Accessing a scalar formal parameter
```
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	-24(%rbp), %rax
```
### Struct array element access
```
	movl	%edx, a+8(,%rax,4)	;a is the name for the struct, 8 for double, expression gets to the array
```
### Global struct member access
```
	movabsq $4614256655080292474, %rax
	movq	%rax, xyz+24(%rip)
```
### Global struct member access
```
	movabsq $4614256655080292474, %rax
	movq	%rax, -48(%rip)	;Moves into place, since xyz is previous it is a -48, its a smaller address
```
### Formal parm struct member access
```
	movabsq $4614256655080292474, %rax
	movq	%rax, -16(%rbp)	
```
### Multidimensional array element access, rowmajor
```
	movl	%ecx, array(,%rax,4)
```

## Address Computation Examples
Expression | Computation | Address
-----------|--------------|-------
0x8(%edx)	|	0xf000 + 0x8	|	0xf008
(%edx, %ecx) | 0xf000 + 0x100	|	0xf100
(%edx,%ecx,4) | 0xf000 + f*0x100	| 0xf400
0x80(,%edx,2) | 2*0xf000 + 0x80		| 0x1e080

## Swap the Wop!
```
	movl 12(%eb),%ecx
	movl 8(%ebp), %edx
	movl (%ecx),%eax
	movl (%edx),%ebx
	movl %eax, (%edx)
	movl %ebx, (%ecx)
```

## Address Computing Instruction
-	`leal` or `leaq` - computer addres susing addressing mode without accessing memory
-	`leal` works by taking `src, dest`. `src` is adress mode expression. Set `dest` to address specified by src
-	The 'l' is for 32 bit the 'q' is for 64 bit.
-	For example, `leal 7%edx, %ex, 4), %eax`
	-	`eax = 4*edx + edx + 7 = 5&edx + 7`
```
	leal (%eax), %ebx <=> movl %eax, %ebx
	leal 40(%eax), %ebx
	leal (%eax,%edx),%ebx
	leal 80(%eax,%edx), %ecx
```

## Arithmetic automatic!!
```
	addl src, dest		dest = dest + src
	subl src, dest		dest = dest - src
	imull src,dest		dest = dest * src
	sall src, dest		dest = dest << src (left shift)
	
	sarl src,dest		dest = dest >> src (right shift)
	xorl src,dest		dest = dest ^ src
	andl src,dest		dest = dest & src
	orl src,dest		dest = dest | src
arithmetic	
	inc		[b]		opnd
	dec		[w]		opnd
	neg		[l]		opnd
	not		[q]		opnd
	
binary
	add		[b]		src,dst		dst += src
	sub		[w]		src,dst		dst -= src
	or		[l]		src,dst		dst |= src
	and		[q]		src,dst		dst &= src
	xor				src,dst		dst ^= src
```
***
## Assignment Two
### Floating point to ASS-Key
-	Get a number that is greater than or equal to 1.0 and less than 10. First power is the exponent, all successive tell me where i am going to place my digits.
-	For negative numbers, first check, then turn to positive. At the end place the negative.