f:
addiu   $sp,$sp,-8
sw      $fp,4($sp)
move    $fp,$sp
jal g()
nop
move    $sp,$fp
lw      $fp,4($sp)
addiu   $sp,$sp,8
j       $31
nop
