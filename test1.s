main:
addiu   $sp,$sp,-8
sw      $fp,4($sp)
move    $fp,$sp
li $2,7
sw $2,8($fp)
move    $sp,$fp
lw      $fp,4($sp)
addiu   $sp,$sp,8
j       $31
nop
