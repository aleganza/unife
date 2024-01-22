.data
	a: .word 15
	b: .word 10
	c: .word 7
	d: .word 2
	e: .word 18
	f: .word -3
	z: .word
	string: .asciiz "Il risultato vale: "
	
.text
	#calcoli
	lui $t0, 0x1001
	lw $t1, 0($t0) #a
	lw $t2, 4($t0) #b
	
	add $s0, $t1, $t2 #primo conto
	
	lw $t1, 8($t0) #c
	lw $t2, 12($t0) #d
	
	sub $s1, $t1, $t2# secondo conto
	add $s0, $s0, $s1 
	
	lw $t1, 16($t0) #e
	lw $t2, 20($t0) #f
	
	add $s1, $t1, $t2 #terzo conto
	add	$s0, $s0, $s1
	
	lw $t1, 0($t0) #a
	lw $t2, 8($t0) #c
	
	sub $s1, $t1, $t2
	sub $s0, $s0, $s1
	
	#stampa stringa (errore)
	la $a0, string
	addi $v0, $zero, 4
	syscall
	
	#stampa valore
	sw $s0, 24($t0) #risultato finale in z
	
	la $s0, z
	lw $a0, 0($s0)
	addi $v0, $zero, 1
	syscall
	