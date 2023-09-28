.data
	a: .word 15
	b: .word 10
	c: .word 7
	d: .word 2
	e: .word 18
	f: .word -3
	# z: .word
	string: .asciiz "Il risultato vale: "
	
.text
	lw $a0, a
	lw $a1, b
	lw $a2, c
	lw $a3, d
	lw $s0, e
	lw $s1, f
	
	# ho più di 4 parametri da passare alla funzione,
	# carico i restanti sullo stack e sposto lo stack pointer
	addi $sp, $sp, -8 # alloco il frame per passare gli argomenti
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	
	jal do_match
	
	addi $sp, $sp, 8 # dealloco il frame occupato per passare gli argomenti
	move $t0, $s0 # mi salvo il valore di ritorno perchè per stampare $v0 viene sovrascritto
	
	#la, $a0, string # carico l'indirizzo della stringa
	#li $v0, 4 # stampa di stringa
	#syscall
	
do_match:
	# preservo $s0 e $s1
	addi $sp, $sp, -12 #sposto sp perchè sto mettendo 3 robe sullo stack
	sw $fp, 8($sp)
	sw $s0, 4($sp)
	sw $s1, 0($sp)
	addi, $fp, $sp, 8
	
	# prelevo i parametri dallo stack
	lw $s0, 8($fp)
	lw $s1, 4($fp)
	
	# primo conto
	add $s2, $a0, $a1
	
	# secondo conto
	sub $t2, $a2, $a3
	add $s2, $s2, $t2
	
	# terzo conto
	add $t2, $t0, $t1
	add $s2, $s2, $t3
	
	# quarto conto
	sub $t2, $a0, $a2
	
	# preparo il valore di ritorno (conto totale) 
	sub $v0, $s2, $t2

	lw $s1, 0($sp)	
	lw $s0, 4($sp)
	lw $fp, 8($sp)

	addi $sp, $sp, 12 # ripristino $sp
	jr $ra # return
	