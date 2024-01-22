.data
	enter: .asciiz "Enter your guess: "
	right: .asciiz "RIGHT!\n"
	magicNumber: .asciiz " is the magic number."
	wrong: .asciiz "wrong..."
	tooHigh: .asciiz "too high."
	tooLow: .asciiz "too low."

.text
	li $s0, 1325 # magic value
	li $s1, 0 # guess value
	
	li $t0, 0 # i
	li $t1, 10 # valore finale della i
	
	loopInizio:
	beq $t0, $t1, loopFine
	beq $s0, $s1, loopFine
	
	# printf
	la $a0, enter
	li $v0, 4
	syscall
	
	# scanf
	li $v0, 5
	syscall 
	move $s1, $v0 # store guess value
	
	bne $s1, $s0, wrongGuess
	# if...
	la $a0, right #stampo right
	li $v0, 4
	syscall
	
	li $v0, 1 # stampo il valore di guess
	move $a0, $s0
	syscall
	
	la $a0, magicNumber # stampo la stringa associata
	li $v0, 4
	syscall
	
	j rightGuess
	
	wrongGuess:
	# else...
	la $a0, wrong
	li $v0, 4
	syscall
	
	#high or low
	bgt $s1, $s0, high
	
	la $a0, tooLow # stampo che è too low
	li $v0, 4
	syscall
	
	j rightGuess
	high:
	
	la $a0, tooHigh # stampo che è too high
	li $v0, 4
	syscall
	
	rightGuess:
	# i++ e ripeto il ciclo
	add $t0, $t0, 1
	j loopInizio
	
	loopFine:
	