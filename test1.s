.globl f
f:
addiu       $sp,$sp,-12
sw       $31,8($sp)
sw      $fp,4($sp)
move        $fp,$sp
li $2,0
move        $sp,$fp
lw      $31,8($sp)
lw      $fp, 4($sp)
addiu       $sp,$sp,12
j       $31
nop

