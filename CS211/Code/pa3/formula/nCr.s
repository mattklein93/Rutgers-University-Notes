.globl _nCr
_nCr:
Leh_func_begin1:
	pushq	%rbp
Ltmp0:
	movq	%rsp, %rbp
Ltmp1:
	subq	$32, %rsp
Ltmp2:
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	xorb	%cl, %cl
	movl	%eax, %edi
	movb	%cl, %al
	callq	_factorial
	movl	%eax, %ecx
	movl	%ecx, -20(%rbp)
	movl	-4(%rbp), %ecx
	movl	-8(%rbp), %edx
	subl	%edx, %ecx
	movl	%ecx, -24(%rbp)
	movl	-8(%rbp), %ecx
	xorb	%dl, %dl
	movl	%ecx, %edi
	movb	%dl, %al
	callq	_factorial
	movl	%eax, %ecx
	movl	-24(%rbp), %edx
	xorb	%sil, %sil
	movl	%edx, %edi
	movb	%sil, %al
	movl	%ecx, -32(%rbp)
	callq	_factorial
	movl	%eax, %ecx
	movl	-32(%rbp), %esi
	imull	%ecx, %esi
	movl	%esi, -28(%rbp)
	movl	-20(%rbp), %ecx
	movl	-28(%rbp), %esi
	movl	%ecx, %eax
	cltd
	idivl	%esi
	movl	%eax, %ecx
	movl	%ecx, -16(%rbp)
	movl	%ecx, -12(%rbp)
	movl	-12(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	ret

.globl _factorial
_factorial:
Leh_func_begin2:
	pushq	%rbp
Ltmp3:
	movq	%rsp, %rbp
Ltmp4:
	movl	%edi, -4(%rbp)
	movl	$1, -16(%rbp)
	movl	$1, -20(%rbp)
	jmp	LBB2_2
LBB2_1:
	movl	-16(%rbp), %eax
	movl	-20(%rbp), %ecx
	imull	%ecx, %eax
	movl	%eax, -16(%rbp)
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
LBB2_2:
	movl	-20(%rbp), %eax
	movl	-4(%rbp), %ecx
	cmpl	%ecx, %eax
	jle	LBB2_1
	movl	-16(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	popq	%rbp
	ret
