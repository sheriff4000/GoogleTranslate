f:
addiu   $sp,$sp,-7
sw      $31,3($sp)
sw      $fp,-1($sp)
move    $fp,$sp
jal     g()
nop
move    $sp,$fp
lw      $31,3($sp)
lw      $fp, -1($sp)
addiu   $sp,$sp,7
j       $31
nop

