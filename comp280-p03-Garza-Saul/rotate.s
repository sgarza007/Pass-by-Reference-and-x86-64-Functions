# Author: Saul Garza
# Email: sgarza@sandiego.edu

.text	# indicates that what follows is code, not data
.globl rotate  # declare global name called "rotate"

rotate:
	# The following lines set up the stack
	# Do NOT modify them.
	pushq	%rbp                
	movq	%rsp, %rbp

	# ADD YOUR CODE IN HERE.

	pushq %rax #these 3 push's save original value
	pushq %rbx
	pushq %r10
	movq (%rdi), %rax #these 3 mov's act as temps for each value
	movq (%rsi), %rbx
	movq (%rdx), %r10
	movq %rax, (%rsi)#I point each param to its corresponding value and pop temp to restore it
	popq %rax
	movq %rbx, (%rdx)
	popq %rbx
	movq %r10, (%rdi)
	popq %r10
	
	# Do NOT modify anything below here
	popq	%rbp
	retq
