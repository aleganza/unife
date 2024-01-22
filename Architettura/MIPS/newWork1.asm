.data
	x: .word 41
	succeed: .asciiz "You succeed!"
	
.text
	lw $s0, x
	addi $s0, $s0, 1
	
	bne $s0, 42, exit
	
	li $v0, 4
	la $a0, succeed
	syscall
	
exit:
	li $v0, 10
	syscall