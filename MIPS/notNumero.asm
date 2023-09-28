.data
	numero: .word 69
		
.text
	lw $a0, numero
	
	jal notNumero
	
	move $a0, $v0
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall
	
notNumero:
	sub, $v0, $zero, $a0
	jr $ra