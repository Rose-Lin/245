	.text
	.globl	getStrLen
getStrLen:
	pushq	%rbp
	movq %rsp, %rbp
	## TODO: Implement this function
	callq strlen
	popq	%rbp
	retq

	.globl	setStr
setStr:    
	pushq	%rbp
	## TODO: Implement this function
	subq $16, %rsp
	movq %rsp, %rbp
	mov %rdi, (%rbp)
	mov %rsi, 8(%rbp)
	lea (%rsi), %rdi
	callq strlen
	# compare	
	cmp $30, %rax
	jg endsetStr
	callq copyString
	jmp endsetStr

endsetStr:
	add $16, %rsp
	popq	%rbp
	retq

copyString:
	pushq %rbp
	movq %rsp, %rbp	
	push %r12
	push %r13
	push %r14
	push %r15
	movq $0, %r12
	movq $0, %r14
	movq %rax, %r13
	jmp loopstart

loopstart:
	cmp %r12, %r13
	je endCopyString
	jl endCopyString
	movq 24(%rbp), %r15
	add %r12, %r15
	movq 16(%rbp), %rsi
	movq (%r15), %r14
	movq $14, %r15
	movq %r14, (%rsi, %r12, 1)
	add $8, %r12
	jmp loopstart

endCopyString:
	pop %r12
	pop %r13
	pop %r14
	pop %r15
	pop %rbp
	retq

	.global max
max:	
	pushq	%rbp
	## TODO: Implement this function
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	movq %rsi, %r12
	movq $0, %r13
	movq $0, %r14
	imul $8, %r12 #r12 has the space to allocate on the stack
					# cannot change r12
	addq $8, %r12 #to store curmax
	subq %r12, %rsp
	subq $8, %r12
	movq %rsp, %rbp

#move all arr to stack
max_loop:
	cmp %r12, %r13
	je compare
	jg compare
	movq (%rdi, %r13, 1), %rsi
	movq %rsi, 8(%rbp, %r13, 1)
	add $8, %r13
	jmp max_loop

#call cmp in %rdx
compare:
	movq $0, %r13
	movq 8(%rbp, %r13, 1), %r14
	movq (%r14), %rdi
	movq %r14, %r15
	movq %rdi, (%rbp)
	# movq %r14, %rdi

cmp_loop:
	cmp %r12, %r13
	je end_max
	jg end_max
	movq %r15, %rdi
	# movq (%rsp), %rdi    #curmax is always in the first arg
	movq 8(%rbp, %r13, 1), %r14
	movq %r14, %rsi
	callq *%rdx
	cmpl $0, %eax
	jl store_larger
	add $8, %r13
	jmp cmp_loop

store_larger:
	movq %rsi, %r15
	add $8, %r13
	jmp cmp_loop

end_max:
	movq %r15, %rax
	add $8, %r12
	add %r12, %rsp 
	popq %r12
	popq %r13
	popq %r14
	popq %r15 
	popq	%rbp
	retq
