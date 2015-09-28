main:
move $t0 $sp
addiu $sp $sp -12
foo:
li $a0  2
sw $a0 4($t0)
lw $a0 4($t0)
li $v0, 1 
syscall 
callfoo:
jr $ra
