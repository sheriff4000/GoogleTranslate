f:
addiu   $sp,$sp,-8
sw      $31,4($sp)
sw      $fp,0($sp)
move    $fp,$sp
jal     g
nop
move    $sp,$fp
lw      $31,4($sp)
lw      $fp, 0($sp)
addiu   $sp,$sp,8
j       $31
nop

