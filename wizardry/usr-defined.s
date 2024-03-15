.macro fun value, name
    .global \name
    .type \name, function
    .set \name, \value
.endm

.macro dat value, name
    .global \name
    .type \name, object
    .set \name, \value
.endm

fun __divsi3, __aeabi_idiv
fun __modsi3, __aeabi_idivmod
fun __udivsi3, __aeabi_uidiv
fun __umodsi3, __aeabi_uidivmod

dat 0x02000000, gAnims
dat 0x03000000, gRNSeeds
dat 0x02020188, gGenericBuffer
