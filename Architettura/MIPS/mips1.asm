.data
	# .eqv non è un istruzione, è una direttiva all'assemblatore
	
	a: .word 5
	
.text
	
	la $s0, a # load address -> metto  in s0 l'indirizzo di a
	lw $a0, 0($s0) # load word -> metto in a0 il valore all'indirizzo situato in s0 + o offset
	addi $v0, $zero, 1 # 1 -> print integer, stampo 5
	syscall
	
	# riscrivibile con pseudo istruzioni:
	
	lw $a0, a
	addi $v0, $zero, 1 
	syscall
	
	addi, $v0, $zero, 10 # 10 -> terminate execution
	syscall
	