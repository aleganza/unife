.data
	enter: .asciiz "Enter a positive integer: "
	
.text
	la $a0, enter
	li $v0, 4
	syscall
	
	li $v0, 5
	syscall 
	move $t0, $v0 # num
	
	li $t1, 1 # count
	li $t2, 0 # somma
	
	loopInizio:
	bgt $t1, $t0, loopFine
	
	add $t2, $t2, $t1
	add $t1, $t1, 1
	j loopInizio

	loopFine:
	
	li $v0, 1
	move $a0, $t2
	syscall
