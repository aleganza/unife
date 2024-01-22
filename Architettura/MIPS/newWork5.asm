.data
	a: .word 6
	b: .word 8
	c: .word 190
	bingoString: .asciiz "bingo"
	noString: .asciiz "no!!!"

.text
	lw $s0, a
	lw $s1, b
	lw $s2, c
	
	beq $s0, 1, orTrue
	beq $s0, 2, orTrue
	beq $s0, 4, orTrue
	beq $s0, 6, orTrue
	j no
	
orTrue:
	bne $s1, 8, andFalse
	bne $s2, 10, andFalse
	
	li $v0, 4
	la $a0, bingoString
	syscall
	
	j exit
	
andFalse:
	li $v0, 4
	la $a0, noString
	syscall
	
exit:
	li $v0, 10
	syscall
