.data
	X: .word 1 2 3 4 5
	Y: .word 1 2 3 4 55
	print: .asciiz "\nViene "	
	space: .asciiz " "
	
.text
	la $a0, X
	la $a1, Y
	li $a2, 5
	
	jal correlationCoefficient
	
	move $s0, $v0 # salvo il parametro di ritorno
	
	li $v0, 4
	la $a0, print
	syscall
	
	li $v0, 1
	move $a0, $s0
	syscall
	
	li $v0, 10
	syscall
# end main
	
correlationCoefficient:
	# preservo i registri
	# push
	addi $sp, $sp, -12
	sw $s0, 8($sp)
	sw $s1, 4($sp)
	sw $s2, 0($sp)

	li $s0, 0 # sum_X
	li $s1, 0 # sum_Y
	li $s2, 0 # sum_XY
	move $t0, $zero
	# $a2 = n
	
	for:
	bge $t0, $a2, endFor
	
	lw $t2, 0($a0) # valore di X[i]
	lw $t3, 0($a1) # valore di Y[i]
	
	add $s0, $s0, $t2 # aggiorno sum_X
	add $s1, $s1, $t3 # aggiorno sum_Y
	mul $t4, $t2, $t3
	add $s2, $s2, $t4 # aggiorno sum_XY
	
	addi $a0, $a0, 4 # setto X[i]
	addi $a1, $a1, 4 # setto Y[i]
	
	addi $t0, $t0, 1 # scorro
	
	j for
	endFor:
	
	
	# print section
	li $v0, 1
	move $a0, $s0
	syscall
	
	li $v0, 4
	la $a0, space
	syscall
	
	li $v0, 1
	move $a0, $s1
	syscall
	
	li $v0, 4
	la $a0, space
	syscall
	
	li $v0, 1
	move $a0, $s2
	syscall
	
	li $v0, 4
	la $a0, space
	syscall
	
	mul $t0, $a2, $s2
	mul $t1, $s0, $s1
	sub $v0, $t0, $t1
	
	# pop
	lw $s2, 0($sp)
	lw $s1, 4($sp)
	lw $s0, 8($sp)
	addi $sp, $sp, 12
	
	jr $ra
