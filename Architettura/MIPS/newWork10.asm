.data

.text
	li $t0, 3
	li $t1, 2
	
	li $s0, 0 # i
	iLoopStart:
	beq $s0, $t0, iLoopEnd
	
	li $s1, 0 # j
	jLoopStart:
	beq $s1, $t1, jLoopEnd
	
	li $s2, 0 # k
	kLoopStart:
	beq $s2, $t1, kLoopEnd
	
	li $v0, 1
	move $a0, $s2
	syscall
	
	add $s2, $s2, 1
	j kLoopStart
	kLoopEnd:
	
	add $s1, $s1, 1
	j jLoopStart
	jLoopEnd:
	
	add $s0, $s0, 1
	j iLoopStart
	iLoopEnd: