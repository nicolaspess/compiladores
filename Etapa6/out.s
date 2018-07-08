	.section	.rodata

.string0_label:
	.string "\n"

.LC0:
	.string	"%d"

##VARDEC
	.globl	a
	.data
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	1
##VARDEC
	.globl	b
	.data
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	0
##VARDEC
	.globl	x
	.data
	.align 4
	.type	x, @object
	.size	x, 4
x:
	.long	3
##VARDEC
	.globl	n
	.data
	.align 4
	.type	n, @object
	.size	n, 4
n:
	.long	4
##BEGFUN
	.text
	.globl	teste
	.type	teste, @function

teste:
	pushl	%ebp
	movl	%esp, %ebp

##ADD
	movl x, %edx
	movl n, %eax
	addl %edx, %eax

##ASSIGN
	movl %eax, b
movl b, %eax

	popl	%ebp
	ret

##BEGFUN
	.text
	.globl	main
	.type	main, @function

main:
	pushl	%ebp
	movl	%esp, %ebp

##ARG FUNCALL
	movl	$0, (%esp)

##ARG FUNCALL
	movl	$0, 4(%esp)

##FUNCALL
	movl $0, %eax
	call teste

##ASSIGN
	movl %eax, a

## PRINT
	andl	$-16, %esp
	subl	$16, %esp
	movl	a, %edx
	movl	$.LC0, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	 call printf

## PRINT
	movl $.string0_label, %eax
	movl %eax, (%esp)
	call printf

	leave
	ret
