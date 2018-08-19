	.section	.rodata
.comm __xXxtempVarxXx123456LABEL1__, 4, 4
.comm __xXxtempVarxXx123456LABEL0__, 4, 4

.string0_label:
	.string "\n"

.LC0:
	.string	"%d"

 ## TAC_VECDEC
	.globl	v
	.data
	.align 4
	.type	v, @object
	.size	v, 40
v:
	.long 1
	.long 2
	.long 3
	.long 4
	.long 5
	.long 6
	.long 7
	.long 8
	.long 9
	.long 10

##VARDEC
	.globl	a
	.data
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	0
##VARDEC
	.globl	b
	.data
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	0
##BEGFUN
	.text
	.globl	main
	.type	main, @function

main:
	pushl	%ebp
	movl	%esp, %ebp

##VEC ASSIGN
	movl $9, v+16

	jmp .__xXxtempVarxXx123456LABEL1__

.__xXxtempVarxXx123456LABEL0__:

##VEC READ
	movl	v+16, %eax

##ASSIGN
	movl %eax, b

## PRINT
	andl	$-16, %esp
	subl	$16, %esp
	movl	b, %edx
	movl	$.LC0, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	 call printf

## PRINT
	movl $.string0_label, %eax
	movl %eax, (%esp)
	call printf

##ADD
	movl a, %edx
	movl $1, %eax
	addl %edx, %eax

##ASSIGN
	movl %eax, a

.__xXxtempVarxXx123456LABEL1__:

##LESS OR EQUAL
	movl a, %edx
	movl $9, %eax
	cmpl %eax, %edx
	jle .__xXxtempVarxXx123456LABEL0__

	leave
	ret
