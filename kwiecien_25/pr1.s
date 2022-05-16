	.file	"pr1.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"Przyklad uzycia dyrektyw preprocesora, koniecznie zapoznaj sie z komentarzami w kodzie!"
	.align 8
.LC1:
	.string	"Stala PI jest juz zdefiniowana"
.LC3:
	.string	"Stala PI:%f\n"
	.align 8
.LC4:
	.string	"Zmienilem dok\305\202adno\305\233\304\207 sta\305\202ej PI"
.LC6:
	.string	"Wyswietlam SUMA(2,3)*2: %d\n"
.LC7:
	.string	"Uzywam LEPSZA_SUMA(2,3)*2:%d\n"
	.align 8
.LC8:
	.string	"Uzywam LEPSZY_ILOCZYN(2+3,5):%d\n"
	.align 8
.LC9:
	.string	"Uzywam JESZCZE_LEPSZY_ILOCZYN(2+3,5):%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	.LC2(%rip), %rax
	movq	%rax, %xmm0
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	.LC5(%rip), %rax
	movq	%rax, %xmm0
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	$8, %esi
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$10, %esi
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$17, %esi
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$25, %esi
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC2:
	.long	1374389535
	.long	1074339512
	.align 8
.LC5:
	.long	-266631570
	.long	1074340345
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
