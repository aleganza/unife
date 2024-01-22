.data
	a: .word 1 2 3 4 5
	b: .word 6 7 8 9 10 11
	c: .word
	space: .asciiz " "
	
.text
	li $s0, 5
	li $s1, 6
	add $s2, $s0, $s1 # lunghezza c
	li $t0, 4
	
	la $s3, b # indirizzo c
	mul $t1, $s1, $t0
	
	add $s3, $s3, $t1
	
	#li $v0, 1
	#move $a0, $s3
	#syscall
	
	la $t0, a
	la $t1, b
	# $s3 ho indirizzo c
	
	aWhile:
	beq $s0, $zero, aWhileEnd
	
	lw $t3, 0($t0) # dentro $t3 ho il valore dell'array a
	sw $t3, 0($s3)
	
	addi $t0, $t0, 4 # i++ per a
	addi $s3, $s3, 4 # i++ per c
	
	addi $s0, $s0, -1
	j aWhile
	aWhileEnd:
	
	bWhile:
	beq $s1, $zero, bWhileEnd
	
	lw $t3, 0($t1) # dentro $t3 ho il valore dell'array b
	sw $t3, 0($s3)
	
	addi $t1, $t1, 4 # i++ per b
	addi $s3, $s3, 4 # i++ per c

	addi $s1, $s1, -1
	j bWhile
	bWhileEnd:
	
	la $t0, c
	
	print:
	beq $s2, $zero, printEnd
	
	li $v0, 1
	lw $a0, 0($t0)
	syscall
	
	li $v0, 4
	la $a0, space
	syscall
	
	addi $t0, $t0, 4
	
	addi $s2, $s2, -1
	j print
	printEnd:
	