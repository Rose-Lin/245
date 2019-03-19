##
## Lab 2 -- Basic Assembly Programming
##[[[[0#]]]]
## 
## This lab will introduce you assembly programming by having you 
## write two functions: max(int x, int y, int z), and max(int *x,
## int siz). The first calculates the maximum integer of a set of 
## three integers. The second calculates the maximum integer in 
## an array of a certain size.
## 
## Assumptions:
## - You may assume that the integers are only ever nonnegative
## - Return arguments in %eax,%rax
## - There are a set of temporary registers you may use. These 
## are specified in comments.
##
## Compile with:
##     clang++ tests/public_test0.cpp lab2.s	
##
## [[[[1#]]]]
##
	
#[[[[0#]]]]
## Honor pledge (please write your name.)
## 
## I **Rose Lin** have completed this code myself, without
## unauthorized assistance, and have followed the academic honor code.
##
## Edit the code below to complete your solution.
##
#[[[[1#]]]]

## Function max(int x, int y, int z)	
	.text
	.globl	max
max:
	pushq	%rbp
	movq	%rsp, %rbp
	## Save temporary registers
	pushq   %r8
	pushq   %r9
	pushq   %r10
	pushq   %r11
	pushq   %r12
	## TODO: Your code here
	## Register layout:
	##   - %rdi <- First argument (x)
	##   - %rsi <- Second argument (y)
	##   - %rdx <- Third argument (z)
	## 
	## I have also saved a few temporary registers
	## that you may use without worrying:
	##  r8, r9, r10, r11, and r12
	## 
	## However, you may not touch other registers
	## without breaking the way the code works.
	movq	%rdi,	%r8	
	movq	%rsi,  	%r9
	movq 	%rdx,	%r10
_todo:
	## Start your code to compute the max of %rdi, 
	## %rsi, and %rdx here. You will likely need to 
	## add some more labels. If in doubt, please refer 
	## to the notes.
	## IMPORTANT: you MUST leave the return value in 
	## the %rax register.
	cmp 	%r8,	%r9
	jg	_check9_10
	jmp _check8_10

_check8_10:
	cmp 	%r8, 	%r10
	jl _return_8
	movq 	%r10, 	%rax
	jmp _end
_check9_10:
	cmp 	%r9,	%r10
	jl _return_9
	movq 	%r10, 	%rax
	jmp _end
_return_9:
	movq 	%r9, 	%rax
	jmp _end
_return_8:
	movq 	%r8, 	%rax
	jmp _end


_end:
	## You can jump to here to return from the function
	## Pop each of the saved registers and return
	popq    %r12
	popq    %r11
	popq    %r10
	popq    %r9
	popq    %r8
	popq	%rbp
	retq
	
## Function max_arr(int *x, unsigned int size)	
	.globl	max_arr
max_arr:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq   %rdx
	movq    $0, %rax # Set %rax to 0
	## Push a bunch of stuff so you can use these as temporary registers
	pushq   %rbx
	pushq   %r8
	pushq   %r9
	pushq   %r10
	pushq   %r11
	pushq   %r12
	## Arguments:
	##  %rdi <- first argument: pointer to base of array
	##  %rsi <- second argument: size of array
	##
	## ASSUME: 
	##  - %rsi is >= 1
	##  - %rdi points at an array of integers whose size is %rsi
	##
	## TEMPORARY REGISTERS
	##  - You may use %r8-12 as temporary registers
	## 
	## Note that you cannot access the lower 32 bits of %r8-12.
	## However, you can use them to "save" %rax,%rbx,%rcx,
	## and %rdx temporarily so that you can use %eax, %ebx,
	## %ecx, and %edx. To do this, you would
	##     movq %rax, %r8
	##     ... Use %eax ...
	##     movq %r8, %rax <-- Also reloads %eax
	##
	## IMPORTANT:
	## The array at %rdi is an array of integers. On the 
	## test server, an integer will be 4 bytes long. This 
	## means that to fetch the `i`th index of the array, 
	## you would write:
	##     	movl	(%rdi,%r8,4), %ebx
	## 
	## Which would move *(%rdi + %r8 * 4) into the %ebx
	## register. Recall from lecture that %edx is the
	## lower 4 bytes of %rax. Because you are working 
	## with a 32-bit datatype (int), you will have to use 
	## the 32-bit registers to manipulate that data
	## 
	## Sketch of a solution: loop over the array,
	## incrementing %r8 each time until it reaches %rsi.
	## Meanwhile, keep the biggest value seen so far in 
	## %eax (you'll have to use %eax rather than %rax 
	## as integers are 32 bits). Each time you load in the 
	## "current" value, keep that in %ebx.
_todo_arr:	
	## Implement your solution here. Leave the result
	## (biggest integer in the array) in %eax. To move
	## between %eax and %ebx, use:
	##     movl %ebx, %eax
	## To compare %ebx and %eax, use:
	##     cmpl %ebx, %eax
	movq 	$0,	%r8 #indexing
	movl 	(%rdi, %r8, 4),	%eax  #curmax
_loop:
	cmp 	%r8, %rsi
	je 	_end_loop
	cmpl 	(%rdi,%r8,4),	%eax
	jl _change_max
	addq	$1,	%r8
	jmp _loop

_change_max:
	movl 	(%rdi,%r8,4),	%eax
	addq	$1,	%r8
	jmp _loop
	
_end_loop:
	jmp _end_arr

_end_arr:
	## Jump here to return from the function
	popq   %r12
	popq   %r11
	popq   %r10
	popq   %r9
	popq   %r8
	popq   %rbx
	popq   %rdx
	popq   %rbp
	retq
