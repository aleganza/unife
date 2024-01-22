.data
	enter: .asciiz "Enter a value to check divisibility with 6\n"
	isDivisibleBy6String: .asciiz "The number is divisible by 6.\n"
	isNotDivisibleBy6String: .asciiz "The number is NOT divisible by 6.\n"
	
.text

	li $v0, 4
	la $a0, enter
	syscall
	
	li $v0, 5
	syscall
	
	move $a0, $v0 # preparo il valore da passare
	jal div_6
	
exit:
	li $v0, 10
	syscall

#-- funzioni --
div_2:
	# $a0 % 2
	li $t0, 2
	div $a0, $t0
	mfhi $v0 # resto in $v0
	
	li $t0, 0
	li $t1, 1
	bne $v0, $t0, return0
	move $v0, $t1
	jr $ra
	
	return0:
	move $v0, $t0
	jr $ra
	
div_6:
	addi $sp, $sp, -4 # push del ritorno (preservo)
	sw $ra, 0($sp)
	
	jal div_2
	
	lw $ra, 0($sp) # pull del ritorno (preservato in precedenza)
	
	# preparazione dei registri $ti per fare gli if
	li $t0, 1
	li $t1, 3
	li $t2, 0
	
	div $a0, $t1
	mfhi $t1 # resto di $a0 % 3 in $t1
	
	bne $v0, $t0, isNotDivisible # if (val di ritorno di div_2 NON è 1) -> non è div
	bne $t1, $t2,  isNotDivisible # if (argomento di div_6 NON è 0) -> non è div
	
	li $v0, 4
	la $a0, isDivisibleBy6String
	syscall
	
	jr $ra
	isNotDivisible:
	
	li $v0, 4
	la $a0, isNotDivisibleBy6String
	syscall
	
	jr $ra
	