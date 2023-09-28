.data
	a: .word 
	inserisci: .asciiz "inserisci un numero: "
	stringaPari: .asciiz "il numero e' pari"
	stringaDispari: .asciiz "il numero e' dispari"
	
.text
	#printf
	la $a0, inserisci
	li $v0, 4
	syscall
	
	#scanf int
	li $v0, 5
	syscall
	
	move $a0, $v0
	jal paridispari
	#sposto il return nel registro $t0
	move $t0, $v0
	
	#if (numero == 0) salto
	beq $t0, $zero, pari
	
	la $a0, stringaDispari
	li $v0, 4
	syscall
	
	j exit
	
pari:
	la $a0, stringaPari
	li $v0, 4
	syscall
	
exit:
	li $v0, 10
	syscall
	
	#-- funzioni --
paridispari:
	andi $v0, $a0, 0x0001
	
	jr $ra