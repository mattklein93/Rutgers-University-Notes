#February 21, 2013
***
##*ASS*-embly
### Why?
-	Machine interface: where software meets hardware.
-	To understand how the hardware works, we have to understand the interface that it exports.
***


### IA32
-	Many different assemblers, they are processor-specific. We focus on **IA32**.
***

### Assembly Programmer's View
-	We can see the ALU, Control Logic, PC (instruction pointer), Registers (inside CPU, no memory access overhead. Small, expensive, fastest.), Condition Codes in the **CPU**.
-	Communicate addresses to CPU from Memory, and we can read/write, and move data.

#### Example 1
-	Go to address `03`, and read what is there.
-	Send to CPU.

#### Example 2	
-	Go to address `04`, and write what's in CPU.
***
	
### Basic CPU Function
-	Arithmetic: +,-,*,/
-	Logic: bre, jmp

	1.	Fetch[PC++]
	2.	Decode
	3.	Execute
	4.	Repeat
***
	
### Assembly Characteristics
-	Barely data types.
-	Integer data of 1,2, or 4 bytes.
	-	Data values, and addresses (numbers)
-	Floating point data of 4,8,or 10.
-	No type checking. No constraints or protection against misinterpretation of data.

##### 	Primitive Operations
-	Perform arithmetic function on register or memory data.
-	Can transfer data between memory and registers
	-	Load daa from memory into register
	-	Store register data into memory

-	Transfer controls (jumps and branches)
***

### X86 Characteristics
-	Variable length instrunctions: 1-15 bytes
-	Can address memory directly in most instructions
-	Uses little-endian format

>	Our machine instructions have 2,1, or 0 operands. Some instructions have implicit operands, and can get acted on if we do not explicitly state it.

***

### Instruction Format
-	Usually `opcode		operands`

#### Opcode
-	Short mnemonic for instruction's purpose such as `movb, addl` etc. Comma seperated.

#### Operands
-	Immediate, register, or memory
-	Number of operands command-dependant
***

### Registers
```
32bit		16bit	8bit
--------|---------|--------
%eax		%ax		%ah	%al
%ebx		%bx		%bh	%bl
%ecx		%cx		%ch	%cl
%edx		%dx		%dh	%dl
%ebp		%bp					Frame pointer registers
%esp		%sp					Stack pointer registers
%eip		%ip					Instruction pointer register, changes by itself.
%esi		%si					along with %edi are for segment addressing
```
-	The low half and the 16bit registers occupy **the same space**
-	The 8bit `h` occupy the high 8bits of thr 16bit registers.
-	All are distinct in memory.
-	64bit registers start with `r` for, example `%rax%` and the 32bit registers occupy the lower half of the 64bit registers space.

#### Memory Display

```
------------------------ %eax
				-------- %ax
				----	 %ah
					----  %al
```
-	`%ebp` is the most recent always. `%esp` points to the top of the stack always. `%eip` contains address of the next instruction to execute.

***

### Stacks on Stacks on Stacks
-	Pushes and pops individual values.
-	From the stack I can build a call stack, whic hare the values needed for a particular function invocation.
	-	The call stack contains **call frames** or **activation records**
-	Intel stacks grow to **lower** addresses.
-	`%esp` points to the top of the stack always.
-	There's a push and a pop instruction, when we push and pop it takes two steps.

##### Push
1.	Decrement `%esp` by 4.	
2.	Copy what we are trying to push to the `%esp` register.

##### Pop
1.	Copy `%esp` value to where it's going
2.	Increment `%esp` by 4.
***

### Instructions
-	Can be made in text editor, each assembly instruction is *one* machine instructions.
-	The general form is indented by 1 tab each:`mnemonic operands`.

#### MOV Instruction
```
movb		Move Byte (8 bits)
movw		Move Word (16 bits)
movl		Move Double Word (16 bits)
movq		Move Quad Word (64 bits)
```
-	We can apply `b|w|l|q` to many instructions, as these refer to size.
-	`MOV` Instructions have two operands: `mov	S, D`, move source to destination. Can only move things of the same size.

```
movsbw		Move from 8bit to 16
movsbl		Move from 8bit to 32
movsbq		Move from 8bit to64
movswl		Move from 16bit to 32
movswq		Move from 16bit to 64
movslq		Move from 32bit to 64
```
-	Use the **s** to sign extend from source to destination.


```
movzbw		Move from 8bit to 16
movzbl		Move from 8bit to 32
movzbq		Move from 8bit to64
movzwl		Move from 16bit to 32
movzwq		Move from 16bit to 64
movzlq		Move from 32bit to 64
```
-	The **z** is a zero extend.

##### Example
```
movb	$0x43,%bh				//Move 43 to the BH register (byte)
movw	%ax,%bx					//Moving 16bits of one register into another register
movl	$0x007FFFFF,(%ecx)		//Move the hex address to what is in the ecx register
movsbl	%ah,%ebx				//Moving a byte to a long, grab what's in ah register to the ebx register
```

##### MOV-ability
```
r	r		Register->Register
r	m		Register->Memory
m	r		Memory->Register
i	r		Immediate(literal)->Register
i	m		Immediate(literal)->Memory
```
-	To do memory to memory, do memory to register then register to memory.
***

### Data Types
-	Byte: 8 bits
-	Word: 16 bits
-	Double Word: 32 bits
-	Quad Word: 64bits
***

### Operand Form
#### Immediate Addressing
-	Operand is `immediate`. We do this by putting a `$` and what we want after it. For example: `movl	$0x4040, %eax`. 

#### Direct Addressing
-	Address of operand is found immediately after the instruction. It is aso known as absolute address. For example: `movl $eax, 0x0000f`

#### Register Specifcation
-	Place percent sign in front, such as `%eax`. For example:: `movl	$eax, $ebx`.

#### Indirect Mode Addressing
-	Content of operand is an address. Designated as parantehsis around operand. Offset can be specified as immediate mode.
###### Example
-	`movl	(%ebp), %eax` - Copy value from memory location whose address is in ebp into eax.
-	`movl	-4(%ebp), %eax` - Copy value from memory location who is -4 away from ebp into eax.
-	`imm(%eax)` - `imm` is immediate displacement number. The address is `%eax + imm` which can be 1, 2, or 4 bytes depending on the value.

#### Indexed Mode Addressing
-	Adds conents of two registers to get address of operand. For example `movl	(%eab, %esi), %eax`. This does address = eab + esi into eax. Along with `movl 8(%eab, %esi), %eax` which takes the value at 8+eab+esi itno eax.
-	Useful with arrays, if you need to walk through the elements of an array. Use one register to hold base address, one ot hold index. Such as implementing the C array access in a for loop.
-	`(, %eax,4)` is with scaling factor. Take the eax register, multiply that by a scaling factor, as 1, 2, 4 or 8.
-	`imm(, %eax,4)` is scale with the `imm`, indirectly. add `imm` at the end.
-	`(%ebx, %eax,4)` scale indirect with an index register. Multiply by the scaler and then add the contents to get the address.
***

### Assignment 2 Info
-	Any positive number can be represented as the sum of various powers of two.