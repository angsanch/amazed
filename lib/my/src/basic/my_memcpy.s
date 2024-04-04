	.file	"my_memcpy.c"
# GNU C17 (Ubuntu 11.4.0-1ubuntu1~22.04) version 11.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 11.4.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.24-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection
	.text
	.globl	my_memcpy
	.type	my_memcpy, @function
my_memcpy:
.LFB6:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)	# dest, dest
	movq	%rsi, -48(%rbp)	# src, src
	movq	%rdx, -56(%rbp)	# n, n
# my_memcpy.c:12:     size_t i = 0;
	movq	$0, -24(%rbp)	#, i
# my_memcpy.c:13:     char *destchr = dest;
	movq	-40(%rbp), %rax	# dest, tmp87
	movq	%rax, -16(%rbp)	# tmp87, destchr
# my_memcpy.c:14:     const char *srcchr = src;
	movq	-48(%rbp), %rax	# src, tmp88
	movq	%rax, -8(%rbp)	# tmp88, srcchr
# my_memcpy.c:16:     if (dest == NULL && src == NULL)
	cmpq	$0, -40(%rbp)	#, dest
	jne	.L4	#,
# my_memcpy.c:16:     if (dest == NULL && src == NULL)
	cmpq	$0, -48(%rbp)	#, src
	jne	.L4	#,
# my_memcpy.c:17:         return (NULL);
	movl	$0, %eax	#, _5
	jmp	.L3	#
.L5:
# my_memcpy.c:19:         destchr[i] = srcchr[i];
	movq	-8(%rbp), %rdx	# srcchr, tmp89
	movq	-24(%rbp), %rax	# i, tmp90
	addq	%rdx, %rax	# tmp89, _1
# my_memcpy.c:19:         destchr[i] = srcchr[i];
	movq	-16(%rbp), %rcx	# destchr, tmp91
	movq	-24(%rbp), %rdx	# i, tmp92
	addq	%rcx, %rdx	# tmp91, _2
# my_memcpy.c:19:         destchr[i] = srcchr[i];
	movzbl	(%rax), %eax	# *_1, _3
# my_memcpy.c:19:         destchr[i] = srcchr[i];
	movb	%al, (%rdx)	# _3, *_2
# my_memcpy.c:20:         i ++;
	addq	$1, -24(%rbp)	#, i
.L4:
# my_memcpy.c:18:     while (i < n){
	movq	-24(%rbp), %rax	# i, tmp93
	cmpq	-56(%rbp), %rax	# n, tmp93
	jb	.L5	#,
# my_memcpy.c:22:     return (dest);
	movq	-40(%rbp), %rax	# dest, _5
.L3:
# my_memcpy.c:23: }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE6:
	.size	my_memcpy, .-my_memcpy
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
