# programma che fa il "not" del numero (!numero)
#
# con  -2147483648 non va!
# sub: con segno, se si eccede il range di rappresentazione, se ne accorge e va in overflow,
#	   siccome controlla il bit del segno;
# subu: senza segno, non fa controllo quindi non controlla se si eccede il range di
#		 rappresentazione, dunque fa il calcolo lo stesso, anche se errato.
#
# SOSTANZIALE DIFFERENZA: check sull'overflow (sub lo fa, subu no).

.data
	numero: .word 2147483647
.text
	lw $a0, numero
	
	jal notNumero
	
	move $a0, $v0
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall
	
notNumero:
	sub, $v0, $zero, $a0
	#sub, $v0, $zero, $a0
	jr $ra