.data
	inserire: .asciiz "Inserire due numeri interi separandoli mediante CARRIAGE RETURN: \n"
	risultato: .asciiz "Il minimo comune multiplo vale "
	
.text
	li $v0, 4
	la $a0, inserire
	syscall
	
	li $v0, 5
	syscall
	move $a0, $v0 # $s0 = num1
	
	li $v0, 5
	syscall
	move $a1, $v0 # $s1 = num2
	
	jal minimoComuneMultiplo
	
	move $t0, $v0
	
	li $v0, 4
	la $a0, risultato
	syscall
	
	li $v0, 1
	move $a0, $t0
	syscall
	
	li $v0, 10
	syscall
	
minimoComuneMultiplo:
	# preservo l'indirizzo del ritorno al main e i due argomenti della funzione chiamante, perchè chiamando la seconda funzione li perderei
	# push
	addi, $sp, $sp, -12
	sw $ra, 8($sp)
	sw $a0, 4($sp)
	sw $a1, 0($sp)
	
	jal minimoComunDivisore
	
	# pop
	lw $a1, 0($sp)
	lw $a0, 4($sp)
	lw $ra, 8($sp)
	addi, $sp, $sp, 12
	
	# n1 * n2 / massimoComunDivisore(n1, n2)
	mul $t0, $a0, $a1
	div $t0, $v0
	mflo $v0
	jr $ra
	
minimoComunDivisore:
	move $s0, $a0 # a
	move $s1, $a1 # b
	
	while:
	beq $s1, $zero, whileEnd
	
	div $s0, $s1
	mfhi $t1 # resto
	move $s0, $s1 # a = b
	move $s1, $t1 # b = resto
	
	j while
	whileEnd:
	
	move $v0, $s0
	jr $ra
	