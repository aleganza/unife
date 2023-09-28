.data
	numero: .word -69
.text
	lw $a0, numero
	
	jal notNumero
	
	move $a0, $v0
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall
	
notNumero:
	nor $v0, $a0, $a0
	add $v0, $v0, 1
	#sub, $v0, $zero, $a0
	jr $ra