.include "MPlayDef.s"
.section .rodata

.macro tone_data type, key, length, pan_sweep, wav, attack, decay, sustain, release
    .byte \type, \key, \length, \pan_sweep
    .word \wav
    .byte \attack, \decay, \sustain, \release
.endm

@ ****************************** header ******************************
.align 2
.global this_song
this_song:
    .byte 0x08                      @ trackCount
    .byte 0x00                      @ blockCount
    .byte 0x0A                      @ priority
    .byte 0x94                      @ reverb
    .word this_song_tone            @ tone
    .word this_song_track0          @ tracks 0x085451D0
    .word this_song_track1          @ tracks 0x085454C5
    .word this_song_track2          @ tracks 0x08545661
    .word this_song_track3          @ tracks 0x085458F3
    .word this_song_track4          @ tracks 0x08545B74
    .word this_song_track5          @ tracks 0x08545CE1
    .word this_song_track6          @ tracks 0x08545D9B
    .word this_song_track7          @ tracks 0x08546144

@ ****************************** tracks ******************************
.align 2
this_song_track0:
    .byte KEYSH, 0
    .byte TEMPO, 56
    .byte W48
    .byte TEMPO, 60
    .byte W48
    .byte W72
    .byte VOICE, 51
    .byte W12
    .byte VOL, 46
    .byte W06
    .byte PAN, 40
    .byte W06
    .byte W72
    .byte N04, 76, 92
    .byte W04
    .byte 0x4E
    .byte W04
    .byte 0x50
    .byte W04
    .byte 0x52
    .byte W04
    .byte 0x53
    .byte W04
    .byte 0x55
    .byte W04
    .byte TEMPO, 72
    .byte N06, 87
    .byte W09
    .byte 0x57
    .byte 0x20
    .byte W84
    .byte W03
    .byte W96
    .byte W96
    .byte W96
    .byte W48
    .byte N32, 78, 84
    .byte W36
    .byte N05, 76, 96
    .byte W06
    .byte 0x4B
    .byte 0x5C
    .byte W06
    .byte N23, 73
    .byte W24
    .byte 0x4B
    .byte W24
    .byte 0x4C
    .byte W24
    .byte 0x4E
    .byte W24
    .byte N05, 73, 127
    .byte W06
    .byte 0x49
    .byte 0x3C
    .byte W06
    .byte 0x42
    .byte 0x7F
    .byte W06
    .byte 0x42
    .byte 0x3C
    .byte W06
    .byte 0x49
    .byte 0x7F
    .byte W06
    .byte 0x49
    .byte 0x3C
    .byte W06
    .byte 0x42
    .byte 0x7F
    .byte W06
    .byte 0x42
    .byte 0x3C
    .byte W06
    .byte 0x4B
    .byte 0x7F
    .byte W06
    .byte 0x4B
    .byte 0x3C
    .byte W06
    .byte 0x46
    .byte 0x7F
    .byte W06
    .byte 0x46
    .byte 0x3C
    .byte W06
    .byte 0x4B
    .byte 0x7F
    .byte W06
    .byte 0x4B
    .byte 0x3C
    .byte W06
    .byte 0x46
    .byte 0x7F
    .byte W06
    .byte 0x46
    .byte 0x3C
    .byte W06
    .byte 0x4C
    .byte 0x7F
    .byte W06
    .byte 0x4C
    .byte 0x3C
    .byte W06
    .byte 0x46
    .byte 0x7F
    .byte W06
    .byte 0x46
    .byte 0x3C
    .byte W06
    .byte 0x4C
    .byte 0x7F
    .byte W06
    .byte 0x4C
    .byte 0x3C
    .byte W06
    .byte 0x46
    .byte 0x7F
    .byte W06
    .byte 0x46
    .byte 0x3C
    .byte W06
    .byte 0x3D
    .byte 0x7F
    .byte W06
    .byte 0x42
    .byte W06
    .byte 0x49
    .byte W06
    .byte 0x42
    .byte W06
    .byte 0x49
    .byte W06
    .byte 0x4E
    .byte W06
    .byte N05
    .byte W06
    .byte 0x55
    .byte W06
    .byte 0x50
    .byte W06
    .byte 0x50
    .byte 0x64
    .byte W06
    .byte 0x4B
    .byte 0x7F
    .byte W06
    .byte 0x4B
    .byte 0x64
    .byte W06
    .byte 0x47
    .byte 0x7F
    .byte W06
    .byte 0x47
    .byte 0x64
    .byte W06
    .byte 0x44
    .byte 0x7F
    .byte W06
    .byte 0x44
    .byte 0x64
    .byte W06
    .byte 0x50
    .byte 0x7F
    .byte W06
    .byte 0x50
    .byte 0x64
    .byte W06
    .byte 0x4B
    .byte 0x7F
    .byte W06
    .byte 0x4B
    .byte 0x64
    .byte W06
    .byte 0x47
    .byte 0x7F
    .byte W06
    .byte 0x47
    .byte 0x64
    .byte W06
    .byte 0x44
    .byte 0x7F
    .byte W06
    .byte 0x44
    .byte 0x64
    .byte W06
    .byte 0x50
    .byte 0x7F
    .byte W06
    .byte 0x50
    .byte 0x64
    .byte W06
    .byte 0x4D
    .byte 0x7F
    .byte W06
    .byte 0x4D
    .byte 0x64
    .byte W06
    .byte 0x49
    .byte 0x7F
    .byte W06
    .byte 0x49
    .byte 0x64
    .byte W06
    .byte 0x44
    .byte 0x7F
    .byte W06
    .byte 0x44
    .byte 0x64
    .byte W06
    .byte 0x50
    .byte 0x7F
    .byte W06
    .byte 0x50
    .byte 0x64
    .byte W06
    .byte 0x4D
    .byte 0x7F
    .byte W06
    .byte 0x4D
    .byte 0x64
    .byte W06
    .byte 0x49
    .byte 0x7F
    .byte W06
    .byte 0x49
    .byte 0x64
    .byte W06
    .byte 0x44
    .byte 0x7F
    .byte W06
    .byte 0x44
    .byte 0x64
    .byte W06
    .byte 0x50
    .byte 0x7F
    .byte W06
    .byte 0x50
    .byte 0x64
    .byte W06
    .byte 0x4C
    .byte 0x7F
    .byte W06
    .byte 0x4C
    .byte 0x64
    .byte W06
    .byte 0x47
    .byte 0x7F
    .byte W06
    .byte 0x47
    .byte 0x64
    .byte W06
    .byte 0x44
    .byte 0x7F
    .byte W06
    .byte 0x44
    .byte 0x64
    .byte W06
    .byte 0x50
    .byte 0x7F
    .byte W06
    .byte 0x50
    .byte 0x64
    .byte W06
    .byte 0x4C
    .byte 0x7F
    .byte W06
    .byte 0x4C
    .byte 0x64
    .byte W06
    .byte 0x47
    .byte 0x7F
    .byte W06
    .byte 0x47
    .byte 0x64
    .byte W06
    .byte 0x44
    .byte 0x7F
    .byte W06
    .byte 0x44
    .byte 0x64
    .byte W06
    .byte 0x50
    .byte 0x7F
    .byte W06
    .byte 0x50
    .byte 0x64
    .byte W06
    .byte 0x4C
    .byte 0x7F
    .byte W06
    .byte 0x4C
    .byte 0x64
    .byte W06
    .byte 0x47
    .byte 0x7F
    .byte W06
    .byte 0x47
    .byte 0x64
    .byte W06
    .byte 0x44
    .byte 0x7F
    .byte W06
    .byte 0x44
    .byte 0x64
    .byte W06
    .byte 0x3B
    .byte 0x7F
    .byte W06
    .byte 0x40
    .byte W06
    .byte 0x47
    .byte W06
    .byte 0x40
    .byte W06
    .byte 0x47
    .byte W06
    .byte 0x4C
    .byte W06
    .byte N05
    .byte W06
    .byte 0x53
    .byte W06
    .byte 0x56
    .byte W06
    .byte 0x56
    .byte 0x64
    .byte W06
    .byte 0x53
    .byte 0x7F
    .byte W06
    .byte 0x53
    .byte 0x64
    .byte W06
    .byte 0x4E
    .byte 0x7F
    .byte W06
    .byte 0x4E
    .byte 0x64
    .byte W06
    .byte 0x4A
    .byte 0x7F
    .byte W06
    .byte 0x4A
    .byte 0x64
    .byte W06
    .byte 0x53
    .byte 0x7F
    .byte W06
    .byte 0x53
    .byte 0x64
    .byte W06
    .byte 0x4E
    .byte 0x7F
    .byte W06
    .byte 0x4E
    .byte 0x64
    .byte W06
    .byte 0x4A
    .byte 0x7F
    .byte W06
    .byte 0x4A
    .byte 0x64
    .byte W06
    .byte 0x47
    .byte 0x7F
    .byte W06
    .byte 0x47
    .byte 0x64
    .byte W06
    .byte 0x52
    .byte 0x7F
    .byte W06
    .byte 0x52
    .byte 0x64
    .byte W06
    .byte 0x4F
    .byte 0x7F
    .byte W06
    .byte 0x4F
    .byte 0x64
    .byte W06
    .byte 0x4A
    .byte 0x7F
    .byte W06
    .byte 0x4A
    .byte 0x64
    .byte W06
    .byte 0x46
    .byte 0x7F
    .byte W06
    .byte 0x46
    .byte 0x64
    .byte W06
    .byte 0x52
    .byte 0x7F
    .byte W06
    .byte 0x4D
    .byte W06
    .byte 0x4A
    .byte W06
    .byte 0x46
    .byte W06
    .byte 0x4D
    .byte W06
    .byte 0x46
    .byte W06
    .byte 0x41
    .byte W06
    .byte 0x3E
    .byte W06
    .byte TIE, 61
    .byte W48
    .byte TEMPO, 68
    .byte W48
    .byte W96
    .byte TEMPO, 76
    .byte W02
    .byte EOT
    .byte W92
    .byte W02
    .byte W96
    .byte W96
    .byte W48
    .byte N08, 77, 100
    .byte W08
    .byte 0x4F
    .byte W08
    .byte 0x50
    .byte W08
    .byte 0x52
    .byte W08
    .byte 0x54
    .byte W08
    .byte 0x56
    .byte W08
    .byte TIE, 87, 96
    .byte W02
    .byte VOL, 46
    .byte W01
    .byte 0x2B
    .byte W01
    .byte 0x26
    .byte W01
    .byte 0x21
    .byte W01
    .byte 0x1E
    .byte W01
    .byte 0x19
    .byte W01
    .byte 0x14
    .byte W01
    .byte 0x10
    .byte W02
    .byte 0x10
    .byte W01
    .byte 0x11
    .byte W01
    .byte 0x12
    .byte W01
    .byte 0x12
    .byte W01
    .byte 0x13
    .byte W01
    .byte 0x14
    .byte W01
    .byte 0x14
    .byte W01
    .byte 0x15
    .byte W01
    .byte 0x16
    .byte W01
    .byte 0x16
    .byte W01
    .byte 0x17
    .byte W01
    .byte 0x17
    .byte W01
    .byte 0x18
    .byte W01
    .byte 0x19
    .byte W01
    .byte 0x19
    .byte W01
    .byte 0x1A
    .byte W01
    .byte 0x1A
    .byte W01
    .byte 0x1B
    .byte W01
    .byte 0x1C
    .byte W01
    .byte 0x1C
    .byte W01
    .byte 0x1D
    .byte W01
    .byte 0x1E
    .byte W01
    .byte 0x1E
    .byte W01
    .byte 0x1F
    .byte W01
    .byte 0x20
    .byte W01
    .byte 0x20
    .byte W01
    .byte 0x21
    .byte W01
    .byte 0x22
    .byte W01
    .byte 0x22
    .byte W01
    .byte 0x23
    .byte W01
    .byte 0x24
    .byte W01
    .byte 0x24
    .byte W01
    .byte 0x25
    .byte W01
    .byte 0x26
    .byte W01
    .byte 0x26
    .byte W01
    .byte 0x27
    .byte W01
    .byte 0x27
    .byte W01
    .byte 0x28
    .byte W02
    .byte 0x27
    .byte W02
    .byte 0x27
    .byte W01
    .byte 0x26
    .byte W02
    .byte 0x26
    .byte W01
    .byte 0x26
    .byte W01
    .byte 0x25
    .byte W02
    .byte 0x25
    .byte W01
    .byte 0x24
    .byte W02
    .byte 0x24
    .byte W01
    .byte 0x24
    .byte W02
    .byte 0x23
    .byte W01
    .byte 0x23
    .byte W01
    .byte 0x22
    .byte W02
    .byte 0x22
    .byte W01
    .byte 0x22
    .byte W02
    .byte 0x21
    .byte W01
    .byte 0x21
    .byte W02
    .byte 0x20
    .byte W01
    .byte 0x20
    .byte W01
    .byte 0x20
    .byte W02
    .byte 0x1F
    .byte W01
    .byte 0x1F
    .byte W02
    .byte 0x1E
    .byte W01
    .byte 0x1E
    .byte W02
    .byte 0x1E
    .byte W01
    .byte 0x1D
    .byte W01
    .byte 0x1D
    .byte W02
    .byte 0x1C
    .byte W01
    .byte 0x1C
    .byte W02
    .byte 0x1C
    .byte W01
    .byte 0x1B
    .byte W02
    .byte 0x1B
    .byte W01
    .byte 0x1A
    .byte W01
    .byte 0x1A
    .byte W02
    .byte 0x1A
    .byte W01
    .byte 0x19
    .byte W02
    .byte 0x19
    .byte W01
    .byte 0x18
    .byte W02
    .byte 0x18
    .byte W01
    .byte 0x18
    .byte W01
    .byte 0x17
    .byte W02
    .byte 0x17
    .byte W01
    .byte 0x16
    .byte W02
    .byte 0x16
    .byte W01
    .byte 0x16
    .byte W01
    .byte 0x15
    .byte W02
    .byte 0x15
    .byte W01
    .byte 0x14
    .byte W02
    .byte 0x14
    .byte W01
    .byte 0x14
    .byte W02
    .byte 0x13
    .byte W01
    .byte 0x13
    .byte W01
    .byte 0x12
    .byte W02
    .byte 0x12
    .byte W01
    .byte 0x12
    .byte W02
    .byte 0x11
    .byte W01
    .byte 0x11
    .byte W02
    .byte 0x10
    .byte W01
    .byte 0x10
    .byte W01
    .byte 0x10
    .byte W02
    .byte 0x0F
    .byte W01
    .byte 0x0F
    .byte W02
    .byte 0x0E
    .byte W01
    .byte 0x0E
    .byte W02
    .byte 0x0E
    .byte W01
    .byte 0x0D
    .byte W01
    .byte 0x0D
    .byte W02
    .byte 0x0C
    .byte W01
    .byte 0x0C
    .byte W02
    .byte 0x0C
    .byte W01
    .byte 0x0B
    .byte W02
    .byte 0x0B
    .byte W01
    .byte 0x0A
    .byte W01
    .byte 0x0A
    .byte W02
    .byte 0x0A
    .byte W01
    .byte xIECL
    .byte W02
    .byte xIECL
    .byte W01
    .byte xIECV
    .byte W02
    .byte xIECV
    .byte W01
    .byte xIECV
    .byte W01
    .byte 0x07
    .byte W02
    .byte 0x07
    .byte W01
    .byte 0x06
    .byte W02
    .byte 0x06
    .byte W01
    .byte 0x06
    .byte W01
    .byte 0x05
    .byte W02
    .byte 0x05
    .byte W01
    .byte 0x04
    .byte W02
    .byte 0x04
    .byte W01
    .byte 0x04
    .byte W02
    .byte 0x03
    .byte W01
    .byte 0x03
    .byte W01
    .byte 0x02
    .byte W02
    .byte 0x02
    .byte W01
    .byte 0x02
    .byte W03
    .byte 0x01
    .byte W02
    .byte 0x01
    .byte W01
    .byte 0x00
    .byte W01
    .byte 0x00
    .byte W01
    .byte EOT
    .byte VOL, 0
    .byte FINE

.align 2
this_song_track1:
    .byte KEYSH, 0
    .byte W24
    .byte VOICE, 33
    .byte W24
    .byte VOL, 51
    .byte W24
    .byte PAN, 64
    .byte W24
    .byte W96
    .byte W96
label_this_song_track1_0:
    .byte N09, 44, 127
    .byte W36
    .byte N09
    .byte W36
    .byte N09
    .byte W24
    .byte PEND
label_this_song_track1_1:
    .byte W12
    .byte N09, 44, 127
    .byte W36
    .byte N09
    .byte W24
    .byte N06
    .byte W12
    .byte N06
    .byte W12
    .byte PEND
    .byte PATT
    .word label_this_song_track1_0
    .byte PATT
    .word label_this_song_track1_1
    .byte PATT
    .word label_this_song_track1_0
    .byte PATT
    .word label_this_song_track1_1
    .byte PATT
    .word label_this_song_track1_0
    .byte PATT
    .word label_this_song_track1_0
    .byte PATT
    .word label_this_song_track1_0
    .byte PATT
    .word label_this_song_track1_1
    .byte PATT
    .word label_this_song_track1_0
    .byte PATT
    .word label_this_song_track1_1
    .byte N09, 54, 127
    .byte W36
    .byte N09
    .byte W36
    .byte N09
    .byte W12
    .byte 0x34
    .byte W12
    .byte 0x32
    .byte W36
    .byte N09
    .byte W36
    .byte N12
    .byte W12
    .byte N06, 49
    .byte W06
    .byte 0x32
    .byte W06
    .byte VOICE, 54
    .byte VOL, 51
    .byte PAN, 69
    .byte TIE, 37, 104
    .byte W96
    .byte W92
    .byte W01
    .byte EOT
    .byte W03
    .byte VOICE, 33
    .byte VOL, 51
    .byte PAN, 64
    .byte N12, 48, 127
    .byte W68
    .byte W01
    .byte N06
    .byte W19
    .byte N06
    .byte W08
    .byte N12
    .byte W72
    .byte N12
    .byte W24
    .byte N12
    .byte W48
    .byte N12
    .byte W48
    .byte N12
    .byte W48
    .byte N12
    .byte W24
    .byte N12
    .byte W24
    .byte TIE, 43, 124
    .byte W48
    .byte VOL, 51
    .byte W02
    .byte 0x32
    .byte W01
    .byte 0x32
    .byte W01
    .byte 0x31
    .byte W01
    .byte 0x31
    .byte W01
    .byte 0x30
    .byte W01
    .byte 0x30
    .byte W02
    .byte 0x30
    .byte W01
    .byte 0x2F
    .byte W01
    .byte 0x2F
    .byte W01
    .byte 0x2E
    .byte W01
    .byte 0x2E
    .byte W01
    .byte 0x2E
    .byte W01
    .byte 0x2D
    .byte W01
    .byte 0x2D
    .byte W02
    .byte 0x2C
    .byte W01
    .byte 0x2C
    .byte W01
    .byte 0x2C
    .byte W01
    .byte 0x2B
    .byte W01
    .byte 0x2B
    .byte W01
    .byte 0x2A
    .byte W01
    .byte 0x2A
    .byte W01
    .byte 0x2A
    .byte W02
    .byte 0x29
    .byte W01
    .byte 0x29
    .byte W01
    .byte 0x28
    .byte W01
    .byte 0x28
    .byte W01
    .byte 0x28
    .byte W01
    .byte 0x27
    .byte W01
    .byte 0x27
    .byte W01
    .byte 0x26
    .byte W02
    .byte 0x26
    .byte W01
    .byte 0x26
    .byte W01
    .byte 0x25
    .byte W01
    .byte 0x25
    .byte W01
    .byte 0x24
    .byte W01
    .byte 0x24
    .byte W01
    .byte 0x24
    .byte W01
    .byte 0x23
    .byte W02
    .byte 0x23
    .byte W01
    .byte 0x22
    .byte W01
    .byte 0x22
    .byte W01
    .byte 0x22
    .byte W01
    .byte 0x21
    .byte W01
    .byte 0x21
    .byte W01
    .byte 0x20
    .byte W01
    .byte 0x20
    .byte W02
    .byte 0x20
    .byte W01
    .byte 0x1F
    .byte W01
    .byte 0x1F
    .byte W01
    .byte 0x1E
    .byte W01
    .byte 0x1E
    .byte W01
    .byte 0x1E
    .byte W01
    .byte 0x1D
    .byte W01
    .byte 0x1D
    .byte W02
    .byte 0x1C
    .byte W01
    .byte 0x1C
    .byte W01
    .byte 0x1C
    .byte W01
    .byte 0x1B
    .byte W01
    .byte 0x1B
    .byte W01
    .byte 0x1A
    .byte W01
    .byte 0x1A
    .byte W01
    .byte 0x1A
    .byte W02
    .byte 0x19
    .byte W01
    .byte 0x19
    .byte W01
    .byte 0x18
    .byte W01
    .byte 0x18
    .byte W01
    .byte 0x18
    .byte W01
    .byte 0x17
    .byte W01
    .byte 0x17
    .byte W01
    .byte 0x16
    .byte W02
    .byte 0x16
    .byte W01
    .byte 0x16
    .byte W01
    .byte 0x15
    .byte W01
    .byte 0x15
    .byte W01
    .byte 0x14
    .byte W01
    .byte 0x14
    .byte W01
    .byte 0x14
    .byte W01
    .byte 0x13
    .byte W02
    .byte 0x13
    .byte W01
    .byte 0x12
    .byte W01
    .byte 0x12
    .byte W01
    .byte 0x12
    .byte W01
    .byte 0x11
    .byte W01
    .byte 0x11
    .byte W01
    .byte 0x10
    .byte W01
    .byte 0x10
    .byte W02
    .byte 0x10
    .byte W01
    .byte 0x0F
    .byte W01
    .byte 0x0F
    .byte W01
    .byte 0x0E
    .byte W01
    .byte 0x0E
    .byte W01
    .byte 0x0E
    .byte W01
    .byte 0x0D
    .byte W01
    .byte 0x0D
    .byte W02
    .byte 0x0C
    .byte W01
    .byte 0x0C
    .byte W01
    .byte 0x0C
    .byte W01
    .byte 0x0B
    .byte W01
    .byte 0x0B
    .byte W01
    .byte 0x0A
    .byte W01
    .byte 0x0A
    .byte W01
    .byte 0x0A
    .byte W02
    .byte xIECL
    .byte W01
    .byte xIECL
    .byte W01
    .byte xIECV
    .byte W01
    .byte xIECV
    .byte W01
    .byte xIECV
    .byte W01
    .byte 0x07
    .byte W01
    .byte 0x07
    .byte W01
    .byte 0x06
    .byte W02
    .byte 0x06
    .byte W01
    .byte 0x06
    .byte W01
    .byte 0x05
    .byte W01
    .byte 0x05
    .byte W01
    .byte 0x04
    .byte W01
    .byte 0x04
    .byte W01
    .byte 0x04
    .byte W01
    .byte 0x03
    .byte W02
    .byte 0x03
    .byte W01
    .byte 0x02
    .byte W01
    .byte 0x02
    .byte W01
    .byte 0x02
    .byte W01
    .byte 0x01
    .byte W01
    .byte 0x01
    .byte W01
    .byte 0x00
    .byte W01
    .byte 0x00
    .byte W02
    .byte EOT
    .byte VOL, 0
    .byte FINE

.align 2
this_song_track2:
    .byte KEYSH, 0
    .byte W24
    .byte VOICE, 54
    .byte W24
    .byte VOL, 24
    .byte PAN, 69
    .byte VOL, 27
    .byte TIE, 32, 104
    .byte W01
    .byte VOL, 31
    .byte W01
    .byte 0x22
    .byte W01
    .byte 0x26
    .byte W01
    .byte 0x2A
    .byte W01
    .byte 0x2D
    .byte W01
    .byte 0x33
    .byte W05
    .byte 0x31
    .byte W01
    .byte 0x2C
    .byte W01
    .byte 0x29
    .byte W01
    .byte 0x24
    .byte W01
    .byte 0x1F
    .byte W01
    .byte 0x1C
    .byte W01
    .byte 0x17
    .byte W01
    .byte 0x13
    .byte W05
    .byte 0x14
    .byte W02
    .byte 0x14
    .byte W02
    .byte 0x14
    .byte W02
    .byte 0x15
    .byte W03
    .byte 0x15
    .byte W02
    .byte 0x16
    .byte W02
    .byte 0x16
    .byte W02
    .byte 0x16
    .byte W03
    .byte 0x17
    .byte W02
    .byte 0x17
    .byte W02
    .byte 0x18
    .byte W02
    .byte 0x18
    .byte W01
    .byte W02
    .byte 0x18
    .byte W02
    .byte 0x19
    .byte W02
    .byte 0x19
    .byte W02
    .byte 0x1A
    .byte W03
    .byte 0x1A
    .byte W02
    .byte 0x1A
    .byte W02
    .byte 0x1B
    .byte W02
    .byte 0x1B
    .byte W03
    .byte 0x1C
    .byte W02
    .byte 0x1C
    .byte W02
    .byte 0x1C
    .byte W02
    .byte 0x1D
    .byte W03
    .byte 0x1D
    .byte W02
    .byte 0x1E
    .byte W02
    .byte 0x1E
    .byte W02
    .byte 0x1E
    .byte W03
    .byte 0x1F
    .byte W02
    .byte 0x1F
    .byte W02
    .byte 0x20
    .byte W02
    .byte 0x20
    .byte W03
    .byte 0x20
    .byte W02
    .byte 0x21
    .byte W02
    .byte 0x21
    .byte W02
    .byte 0x22
    .byte W03
    .byte 0x22
    .byte W02
    .byte 0x22
    .byte W02
    .byte 0x23
    .byte W02
    .byte 0x23
    .byte W03
    .byte 0x24
    .byte W02
    .byte 0x24
    .byte W02
    .byte 0x24
    .byte W02
    .byte 0x25
    .byte W03
    .byte 0x25
    .byte W02
    .byte 0x26
    .byte W02
    .byte 0x26
    .byte W02
    .byte 0x26
    .byte W03
    .byte 0x27
    .byte W02
    .byte 0x27
    .byte W02
    .byte 0x28
    .byte W02
    .byte 0x28
    .byte W03
    .byte 0x28
    .byte W02
    .byte 0x29
    .byte W02
    .byte 0x29
    .byte W02
    .byte 0x2A
    .byte W03
    .byte 0x2A
    .byte W02
    .byte 0x2A
    .byte W02
    .byte 0x2B
    .byte W02
    .byte 0x2B
    .byte W03
    .byte 0x2C
    .byte W02
    .byte 0x2C
    .byte W02
    .byte 0x2C
    .byte W02
    .byte 0x2D
    .byte W03
    .byte 0x2D
    .byte W02
    .byte 0x2E
    .byte W02
    .byte 0x2E
    .byte W02
    .byte 0x2E
    .byte W03
    .byte 0x2F
    .byte W02
    .byte 0x2F
    .byte W02
    .byte 0x30
    .byte W02
    .byte 0x30
    .byte W03
    .byte 0x30
    .byte W02
    .byte 0x31
    .byte W02
    .byte 0x31
    .byte W02
    .byte 0x32
    .byte W03
    .byte 0x33
    .byte W44
    .byte W01
    .byte EOT
    .byte W01
    .byte VOICE, 56
    .byte VOL, 40
    .byte PAN, 54
    .byte N24, 56
    .byte W30
    .byte N06
    .byte W06
    .byte 0x3A
    .byte W06
    .byte 0x3B
    .byte W06
    .byte N24, 63
    .byte W24
    .byte W03
    .byte N06, 63, 32
    .byte W09
    .byte 0x44
    .byte 0x68
    .byte W06
    .byte 0x44
    .byte 0x20
    .byte W06
    .byte N44, 66, 104
    .byte W48
    .byte N24, 65
    .byte W24
    .byte N06, 65, 32
    .byte W12
    .byte 0x3D
    .byte 0x68
    .byte W06
    .byte 0x3F
    .byte W06
    .byte N44, 64
    .byte W48
    .byte N60, 59
    .byte W48
    .byte W15
    .byte N06, 59, 32
    .byte W09
    .byte N21, 59, 104
    .byte W24
    .byte 0x3D
    .byte W24
    .byte 0x3F
    .byte W24
    .byte N32, 66
    .byte W36
    .byte N05, 64
    .byte W06
    .byte 0x3F
    .byte W06
    .byte N64, 61
    .byte W48
    .byte W18
    .byte N06, 61, 32
    .byte W06
    .byte N17, 59, 112
    .byte W18
    .byte N06, 59, 32
    .byte W06
    .byte N17, 61, 112
    .byte W18
    .byte N06, 61, 32
    .byte W06
    .byte N17, 63, 120
    .byte W18
    .byte N06, 63, 32
    .byte W06
    .byte N42, 61, 96
    .byte W42
    .byte N06, 61, 32
    .byte W06
    .byte N42, 63, 104
    .byte W42
    .byte N06, 63, 32
    .byte W06
    .byte N42, 64, 112
    .byte W42
    .byte N06, 64, 32
    .byte W06
    .byte N42, 66, 120
    .byte W42
    .byte N06, 66, 32
    .byte W06
    .byte W96
    .byte W96
    .byte W96
    .byte W96
    .byte W96
    .byte W96
    .byte VOICE, 50
    .byte VOL, 18
    .byte PAN, 34
    .byte N05, 49, 96
    .byte W06
    .byte 0x31
    .byte 0x50
    .byte W03
    .byte VOL, 18
    .byte W02
    .byte 0x13
    .byte W01
    .byte 0x14
    .byte N05, 50, 96
    .byte W01
    .byte VOL, 21
    .byte W01
    .byte 0x16
    .byte W01
    .byte 0x16
    .byte W01
    .byte 0x17
    .byte W01
    .byte 0x18
    .byte W01
    .byte 0x18
    .byte N05, 50, 80
    .byte W01
    .byte VOL, 25
    .byte W01
    .byte 0x1A
    .byte W01
    .byte 0x1A
    .byte W01
    .byte 0x1B
    .byte W01
    .byte 0x1C
    .byte W01
    .byte 0x1D
    .byte N05, 49, 96
    .byte W01
    .byte VOL, 30
    .byte W01
    .byte 0x1E
    .byte W01
    .byte 0x1F
    .byte W01
    .byte 0x20
    .byte W01
    .byte 0x20
    .byte W01
    .byte 0x21
    .byte N05, 49, 80
    .byte W01
    .byte VOL, 34
    .byte W01
    .byte 0x22
    .byte W01
    .byte 0x23
    .byte W01
    .byte 0x24
    .byte W01
    .byte 0x25
    .byte W01
    .byte 0x26
    .byte N05, 50, 96
    .byte W01
    .byte VOL, 38
    .byte W01
    .byte 0x27
    .byte W01
    .byte 0x28
    .byte W01
    .byte 0x28
    .byte W01
    .byte 0x29
    .byte W01
    .byte 0x2A
    .byte N05, 50, 80
    .byte W01
    .byte VOL, 42
    .byte W01
    .byte 0x2B
    .byte W01
    .byte 0x2C
    .byte W01
    .byte 0x2D
    .byte W01
    .byte 0x2E
    .byte W01
    .byte 0x2E
    .byte N05, 49, 96
    .byte W01
    .byte VOL, 47
    .byte W01
    .byte 0x30
    .byte W01
    .byte 0x30
    .byte W01
    .byte 0x31
    .byte W01
    .byte 0x32
    .byte W01
    .byte 0x33
    .byte N05, 49, 80
    .byte W06
    .byte 0x32
    .byte 0x60
    .byte W06
    .byte 0x32
    .byte 0x50
    .byte W06
    .byte 0x31
    .byte 0x60
    .byte W06
    .byte 0x31
    .byte 0x50
    .byte W06
    .byte 0x32
    .byte 0x60
    .byte W06
    .byte 0x32
    .byte 0x50
    .byte W06
    .byte 0x31
    .byte 0x60
    .byte W06
    .byte 0x31
    .byte 0x50
    .byte W06
    .byte 0x32
    .byte 0x60
    .byte W06
    .byte 0x32
    .byte 0x50
    .byte W06
    .byte 0x31
    .byte 0x60
    .byte W06
    .byte 0x31
    .byte 0x50
    .byte W06
    .byte 0x32
    .byte 0x60
    .byte W06
    .byte 0x32
    .byte 0x50
    .byte W06
    .byte 0x33
    .byte 0x60
    .byte W06
    .byte 0x33
    .byte 0x50
    .byte W06
    .byte 0x34
    .byte 0x60
    .byte W06
    .byte 0x34
    .byte 0x50
    .byte W06
    .byte 0x32
    .byte 0x60
    .byte W06
    .byte 0x32
    .byte 0x50
    .byte W06
    .byte 0x31
    .byte 0x60
    .byte W06
    .byte 0x31
    .byte 0x50
    .byte W06
    .byte VOICE, 59
    .byte VOL, 36
    .byte PAN, 64
    .byte N23, 55, 88
    .byte N23, 60, 100
    .byte W24
    .byte N06, 55, 88
    .byte N06, 60, 100
    .byte W08
    .byte 0x3A
    .byte 0x58
    .byte N06, 62, 100
    .byte W08
    .byte 0x3C
    .byte 0x58
    .byte N06, 63, 100
    .byte W08
    .byte N24, 63, 88
    .byte N24, 67, 100
    .byte W24
    .byte W03
    .byte N06, 63, 40
    .byte N06, 67
    .byte W13
    .byte 0x43
    .byte 0x58
    .byte N06, 72, 100
    .byte W08
    .byte N44, 65, 88
    .byte N44, 70, 100
    .byte W48
    .byte N24, 63, 88
    .byte N24, 69, 100
    .byte W24
    .byte N06, 63, 40
    .byte N06, 69
    .byte W24
    .byte N68, 61, 84
    .byte N68, 66, 100
    .byte W72
    .byte N06, 62, 76
    .byte N06, 68, 96
    .byte W08
    .byte 0x3D
    .byte 0x44
    .byte N06, 66, 88
    .byte W08
    .byte 0x3E
    .byte 0x48
    .byte N06, 68, 88
    .byte W08
    .byte N42, 62, 80
    .byte N42, 69, 100
    .byte W42
    .byte N06, 62, 40
    .byte N06, 69
    .byte W06
    .byte FINE

.align 2
this_song_track3:
    .byte KEYSH, 0
    .byte W96
    .byte W36
    .byte W03
    .byte VOICE, 61
    .byte W03
    .byte VOL, 46
    .byte W03
    .byte PAN, 81
    .byte W48
    .byte W03
    .byte W96
label_this_song_track3_0:
    .byte N24, 51, 104
    .byte N24, 56
    .byte W30
    .byte N06, 51
    .byte N06, 56
    .byte W06
    .byte 0x36
    .byte N06, 58
    .byte W06
    .byte 0x38
    .byte N06, 59
    .byte W06
    .byte N24
    .byte N24, 63
    .byte W24
    .byte W03
    .byte N06, 63, 32
    .byte W09
    .byte 0x3F
    .byte 0x68
    .byte N06, 68
    .byte W06
    .byte 0x44
    .byte 0x20
    .byte W06
    .byte PEND
label_this_song_track3_1:
    .byte N44, 61, 104
    .byte N44, 66
    .byte W48
    .byte N24, 61
    .byte N24, 65
    .byte W24
    .byte N06, 65, 32
    .byte W12
    .byte 0x38
    .byte 0x68
    .byte N06, 61
    .byte W06
    .byte 0x3A
    .byte N06, 63
    .byte W06
    .byte PEND
label_this_song_track3_2:
    .byte N44, 59, 104
    .byte N44, 64
    .byte W48
    .byte N60, 52
    .byte N60, 59
    .byte W48
    .byte PEND
    .byte W12
    .byte N06, 59, 32
    .byte W12
    .byte N21, 59, 104
    .byte W24
    .byte 0x3D
    .byte W24
    .byte 0x3F
    .byte W24
    .byte N32, 61
    .byte N32, 66
    .byte W36
    .byte N05, 59
    .byte N05, 64
    .byte W06
    .byte 0x39
    .byte N05, 63
    .byte W06
    .byte N64, 56
    .byte N64, 61
    .byte W48
    .byte W18
    .byte N06, 61, 32
    .byte W06
    .byte N17, 54, 112
    .byte N17, 59
    .byte W18
    .byte N06, 59, 32
    .byte W06
    .byte N17, 56, 112
    .byte N17, 61
    .byte W18
    .byte N06, 61, 32
    .byte W06
    .byte N17, 57, 120
    .byte N17, 63
    .byte W18
    .byte N06, 63, 32
    .byte W06
    .byte N36, 58, 88
    .byte N42, 61, 104
    .byte W42
    .byte N06, 61, 32
    .byte W06
    .byte N36, 59, 80
    .byte N42, 63, 96
    .byte W42
    .byte N06, 63, 32
    .byte W06
    .byte N36, 61, 100
    .byte N42, 64, 112
    .byte W42
    .byte N06, 64, 32
    .byte W06
    .byte N36, 63, 108
    .byte N42, 66, 124
    .byte W42
    .byte N06, 66, 32
    .byte W06
    .byte PATT
    .word label_this_song_track3_0
    .byte PATT
    .word label_this_song_track3_1
    .byte PATT
    .word label_this_song_track3_2
    .byte W12
    .byte N06, 59, 32
    .byte W12
    .byte N21, 54, 104
    .byte N21, 58
    .byte W24
    .byte 0x38
    .byte N21, 59
    .byte W24
    .byte 0x3A
    .byte N21, 61
    .byte W24
    .byte N44, 59
    .byte N32, 62
    .byte W36
    .byte N05, 61
    .byte W06
    .byte N06, 62, 84
    .byte W06
    .byte N44, 61, 104
    .byte N48, 64
    .byte W48
    .byte N44, 62
    .byte N32, 65
    .byte W36
    .byte N06, 67, 84
    .byte W06
    .byte 0x41
    .byte 0x5C
    .byte W06
    .byte N36, 62, 104
    .byte N36, 67, 96
    .byte W36
    .byte N04, 65, 84
    .byte W04
    .byte 0x3F
    .byte 0x50
    .byte W04
    .byte 0x3E
    .byte 0x58
    .byte W04
    .byte TIE, 61, 108
    .byte W96
    .byte N92, 57
    .byte W84
    .byte W03
    .byte EOT, 61
    .byte W09
    .byte TIE, 60, 76
    .byte TIE, 67, 96
    .byte W96
    .byte W92
    .byte W03
    .byte EOT, 60
    .byte W01
    .byte N92, 61, 84
    .byte W23
    .byte EOT, 67
    .byte W01
    .byte N06, 67, 32
    .byte W24
    .byte N68, 68, 100
    .byte W48
    .byte N92, 62, 88
    .byte W24
    .byte N06, 68, 32
    .byte W24
    .byte N44, 69, 112
    .byte W48
    .byte TIE, 63, 92
    .byte TIE, 65
    .byte TIE, 70, 104
    .byte W02
    .byte VOL, 46
    .byte W01
    .byte 0x2B
    .byte W01
    .byte 0x28
    .byte W01
    .byte 0x26
    .byte W01
    .byte 0x22
    .byte W01
    .byte 0x1F
    .byte W01
    .byte 0x1C
    .byte W01
    .byte 0x19
    .byte W01
    .byte 0x16
    .byte W01
    .byte 0x13
    .byte W01
    .byte 0x10
    .byte W01
    .byte 0x11
    .byte W01
    .byte 0x11
    .byte W01
    .byte 0x12
    .byte W01
    .byte 0x13
    .byte W01
    .byte 0x13
    .byte W01
    .byte 0x14
    .byte W01
    .byte 0x15
    .byte W01
    .byte 0x15
    .byte W01
    .byte 0x16
    .byte W01
    .byte 0x17
    .byte W01
    .byte 0x17
    .byte W01
    .byte 0x18
    .byte W01
    .byte 0x19
    .byte W01
    .byte 0x19
    .byte W01
    .byte 0x1A
    .byte W01
    .byte 0x1B
    .byte W01
    .byte 0x1B
    .byte W01
    .byte 0x1C
    .byte W01
    .byte 0x1D
    .byte W01
    .byte 0x1D
    .byte W01
    .byte 0x1E
    .byte W01
    .byte 0x1F
    .byte W01
    .byte 0x1F
    .byte W01
    .byte 0x20
    .byte W01
    .byte 0x21
    .byte W01
    .byte 0x21
    .byte W01
    .byte 0x22
    .byte W01
    .byte 0x23
    .byte W01
    .byte 0x23
    .byte W01
    .byte 0x24
    .byte W01
    .byte 0x25
    .byte W01
    .byte 0x25
    .byte W01
    .byte 0x26
    .byte W01
    .byte 0x27
    .byte W01
    .byte 0x27
    .byte W01
    .byte 0x28
    .byte W02
    .byte 0x27
    .byte W02
    .byte 0x27
    .byte W01
    .byte 0x26
    .byte W02
    .byte 0x26
    .byte W01
    .byte 0x26
    .byte W01
    .byte 0x25
    .byte W02
    .byte 0x25
    .byte W01
    .byte 0x24
    .byte W02
    .byte 0x24
    .byte W01
    .byte 0x24
    .byte W02
    .byte 0x23
    .byte W01
    .byte 0x23
    .byte W01
    .byte 0x22
    .byte W02
    .byte 0x22
    .byte W01
    .byte 0x22
    .byte W02
    .byte 0x21
    .byte W01
    .byte 0x21
    .byte W02
    .byte 0x20
    .byte W01
    .byte 0x20
    .byte W01
    .byte 0x20
    .byte W02
    .byte 0x1F
    .byte W01
    .byte 0x1F
    .byte W02
    .byte 0x1E
    .byte W01
    .byte 0x1E
    .byte W02
    .byte 0x1E
    .byte W01
    .byte 0x1D
    .byte W01
    .byte 0x1D
    .byte W02
    .byte 0x1C
    .byte W01
    .byte 0x1C
    .byte W02
    .byte 0x1C
    .byte W01
    .byte 0x1B
    .byte W02
    .byte 0x1B
    .byte W01
    .byte 0x1A
    .byte W01
    .byte 0x1A
    .byte W02
    .byte 0x1A
    .byte W01
    .byte 0x19
    .byte W02
    .byte 0x19
    .byte W01
    .byte 0x18
    .byte W02
    .byte 0x18
    .byte W01
    .byte 0x18
    .byte W01
    .byte 0x17
    .byte W02
    .byte 0x17
    .byte W01
    .byte 0x16
    .byte W02
    .byte 0x16
    .byte W01
    .byte 0x16
    .byte W01
    .byte 0x15
    .byte W02
    .byte 0x15
    .byte W01
    .byte 0x14
    .byte W02
    .byte 0x14
    .byte W01
    .byte 0x14
    .byte W02
    .byte 0x13
    .byte W01
    .byte 0x13
    .byte W01
    .byte 0x12
    .byte W02
    .byte 0x12
    .byte W01
    .byte 0x12
    .byte W02
    .byte 0x11
    .byte W01
    .byte 0x11
    .byte W02
    .byte 0x10
    .byte W01
    .byte 0x10
    .byte W01
    .byte 0x10
    .byte W02
    .byte 0x0F
    .byte W01
    .byte 0x0F
    .byte W02
    .byte 0x0E
    .byte W01
    .byte 0x0E
    .byte W02
    .byte 0x0E
    .byte W01
    .byte 0x0D
    .byte W01
    .byte 0x0D
    .byte W02
    .byte 0x0C
    .byte W01
    .byte 0x0C
    .byte W02
    .byte 0x0C
    .byte W01
    .byte 0x0B
    .byte W02
    .byte 0x0B
    .byte W01
    .byte 0x0A
    .byte W01
    .byte 0x0A
    .byte W02
    .byte 0x0A
    .byte W01
    .byte xIECL
    .byte W02
    .byte xIECL
    .byte W01
    .byte xIECV
    .byte W02
    .byte xIECV
    .byte W01
    .byte xIECV
    .byte W01
    .byte 0x07
    .byte W02
    .byte 0x07
    .byte W01
    .byte 0x06
    .byte W02
    .byte 0x06
    .byte W01
    .byte 0x06
    .byte W01
    .byte 0x05
    .byte W02
    .byte 0x05
    .byte W01
    .byte 0x04
    .byte W02
    .byte 0x04
    .byte W01
    .byte 0x04
    .byte W02
    .byte 0x03
    .byte W01
    .byte 0x03
    .byte W01
    .byte 0x02
    .byte W02
    .byte 0x02
    .byte W01
    .byte 0x02
    .byte W03
    .byte 0x01
    .byte W02
    .byte 0x01
    .byte W01
    .byte 0x00
    .byte W01
    .byte EOT, 63
    .byte 0x41
    .byte 0x46
    .byte VOL, 0
    .byte W01
    .byte 0x00
    .byte FINE

.align 2
this_song_track4:
    .byte KEYSH, 0
    .byte W36
    .byte VOICE, 50
    .byte VOL, 24
    .byte PAN, 34
    .byte W12
    .byte VOL, 27
    .byte TIE, 44, 104
    .byte W01
    .byte VOL, 31
    .byte W01
    .byte 0x22
    .byte W01
    .byte 0x26
    .byte W01
    .byte 0x2A
    .byte W01
    .byte 0x2D
    .byte W01
    .byte 0x33
    .byte W05
    .byte 0x31
    .byte W01
    .byte 0x2C
    .byte W01
    .byte 0x29
    .byte W01
    .byte 0x24
    .byte W01
    .byte 0x1F
    .byte W01
    .byte 0x1C
    .byte W01
    .byte 0x17
    .byte W01
    .byte 0x13
    .byte W05
    .byte 0x14
    .byte W02
    .byte 0x14
    .byte W02
    .byte 0x14
    .byte W02
    .byte 0x15
    .byte W03
    .byte 0x15
    .byte W02
    .byte 0x16
    .byte W02
    .byte 0x16
    .byte W02
    .byte 0x16
    .byte W03
    .byte 0x17
    .byte W02
    .byte 0x17
    .byte W02
    .byte 0x18
    .byte W02
    .byte 0x18
    .byte W01
    .byte W02
    .byte 0x18
    .byte W02
    .byte 0x19
    .byte W02
    .byte 0x19
    .byte W02
    .byte 0x1A
    .byte W03
    .byte 0x1A
    .byte W02
    .byte 0x1A
    .byte W02
    .byte 0x1B
    .byte W02
    .byte 0x1B
    .byte W03
    .byte 0x1C
    .byte W02
    .byte 0x1C
    .byte W02
    .byte 0x1C
    .byte W02
    .byte 0x1D
    .byte W03
    .byte 0x1D
    .byte W02
    .byte 0x1E
    .byte W02
    .byte 0x1E
    .byte W02
    .byte 0x1E
    .byte W03
    .byte 0x1F
    .byte W02
    .byte 0x1F
    .byte W02
    .byte 0x20
    .byte W02
    .byte 0x20
    .byte W03
    .byte 0x20
    .byte W02
    .byte 0x21
    .byte W02
    .byte 0x21
    .byte W02
    .byte 0x22
    .byte W03
    .byte 0x22
    .byte W02
    .byte 0x22
    .byte W02
    .byte 0x23
    .byte W02
    .byte 0x23
    .byte W03
    .byte 0x24
    .byte W02
    .byte 0x24
    .byte W02
    .byte 0x24
    .byte W02
    .byte 0x25
    .byte W03
    .byte 0x25
    .byte W02
    .byte 0x26
    .byte W02
    .byte 0x26
    .byte W02
    .byte 0x26
    .byte W03
    .byte 0x27
    .byte W02
    .byte 0x27
    .byte W02
    .byte 0x28
    .byte W02
    .byte 0x28
    .byte W03
    .byte 0x28
    .byte W02
    .byte 0x29
    .byte W02
    .byte 0x29
    .byte W02
    .byte 0x2A
    .byte W03
    .byte 0x2A
    .byte W02
    .byte 0x2A
    .byte W02
    .byte 0x2B
    .byte W02
    .byte 0x2B
    .byte W03
    .byte 0x2C
    .byte W02
    .byte 0x2C
    .byte W02
    .byte 0x2C
    .byte W02
    .byte 0x2D
    .byte W03
    .byte 0x2D
    .byte W02
    .byte 0x2E
    .byte W02
    .byte 0x2E
    .byte W02
    .byte 0x2E
    .byte W03
    .byte 0x2F
    .byte W02
    .byte 0x2F
    .byte W02
    .byte 0x30
    .byte W02
    .byte 0x30
    .byte W03
    .byte 0x30
    .byte W02
    .byte 0x31
    .byte W02
    .byte 0x31
    .byte W02
    .byte 0x32
    .byte W03
    .byte 0x33
    .byte W44
    .byte W01
    .byte EOT
    .byte W01
    .byte W96
    .byte W96
    .byte W96
    .byte W96
    .byte W96
    .byte W96
    .byte W96
    .byte W96
    .byte W96
    .byte W96
    .byte W96
    .byte W96
    .byte W96
    .byte VOICE, 47
    .byte W24
    .byte VOL, 51
    .byte W24
    .byte PAN, 64
    .byte W24
    .byte N06, 56, 127
    .byte W06
    .byte 0x38
    .byte 0x4C
    .byte W06
    .byte 0x38
    .byte 0x50
    .byte W06
    .byte 0x38
    .byte 0x6C
    .byte W06
    .byte N24, 56, 124
    .byte W72
    .byte N24
    .byte W24
    .byte W48
    .byte N06, 55, 127
    .byte W06
    .byte 0x37
    .byte 0x4C
    .byte W06
    .byte 0x37
    .byte 0x50
    .byte W06
    .byte 0x37
    .byte 0x6C
    .byte W06
    .byte 0x37
    .byte 0x70
    .byte W06
    .byte 0x37
    .byte 0x68
    .byte W06
    .byte 0x37
    .byte 0x70
    .byte W06
    .byte 0x37
    .byte 0x7C
    .byte W06
    .byte N24, 60
    .byte W72
    .byte N08
    .byte W08
    .byte N08
    .byte W08
    .byte N08
    .byte W08
    .byte N24
    .byte W72
    .byte N24
    .byte W24
label_this_song_track4_0:
    .byte N24, 60, 124
    .byte W48
    .byte N24
    .byte W48
    .byte PEND
    .byte PATT
    .word label_this_song_track4_0
    .byte N40, 55, 124
    .byte W40
    .byte N04, 55, 84
    .byte W04
    .byte 0x37
    .byte 0x5C
    .byte W04
    .byte 0x37
    .byte 0x60
    .byte W04
    .byte 0x37
    .byte 0x6C
    .byte W04
    .byte 0x37
    .byte 0x74
    .byte W04
    .byte 0x37
    .byte 0x7C
    .byte W04
    .byte N04
    .byte W04
    .byte 0x37
    .byte 0x78
    .byte W04
    .byte N04
    .byte W04
    .byte 0x37
    .byte 0x74
    .byte W04
    .byte N04
    .byte W04
    .byte 0x37
    .byte 0x6C
    .byte W04
    .byte N04
    .byte W04
    .byte N04
    .byte W04
    .byte 0x37
    .byte 0x68
    .byte W04
    .byte 0x37
    .byte 0x64
    .byte W04
    .byte N04
    .byte W04
    .byte 0x37
    .byte 0x60
    .byte W04
    .byte 0x37
    .byte 0x5C
    .byte W04
    .byte 0x37
    .byte 0x58
    .byte W04
    .byte 0x37
    .byte 0x54
    .byte W04
    .byte 0x37
    .byte 0x50
    .byte W04
    .byte N24, 55, 76
    .byte W24
    .byte FINE

.align 2
this_song_track5:
    .byte KEYSH, 0
    .byte W84
    .byte VOICE, 47
    .byte W12
    .byte W12
    .byte VOL, 51
    .byte W24
    .byte PAN, 64
    .byte W60
    .byte W64
    .byte N04, 56, 100
    .byte W04
    .byte 0x38
    .byte 0x58
    .byte W04
    .byte 0x38
    .byte 0x44
    .byte W04
    .byte 0x38
    .byte 0x50
    .byte W04
    .byte 0x38
    .byte 0x58
    .byte W04
    .byte 0x38
    .byte 0x64
    .byte W04
    .byte 0x38
    .byte 0x6C
    .byte W04
    .byte 0x38
    .byte 0x74
    .byte W04
    .byte W96
    .byte W96
    .byte W96
    .byte W96
    .byte W96
    .byte W96
    .byte W96
    .byte VOICE, 68
    .byte W24
    .byte VOL, 38
    .byte W24
    .byte PAN, 55
    .byte W48
    .byte N24, 68, 104
    .byte W30
    .byte N06
    .byte W06
    .byte 0x46
    .byte W06
    .byte 0x47
    .byte W06
    .byte N36, 75
    .byte W36
    .byte N06, 80
    .byte W06
    .byte 0x50
    .byte 0x20
    .byte W06
    .byte N48, 78, 104
    .byte W48
    .byte N24, 77
    .byte W24
    .byte W03
    .byte N06, 77, 32
    .byte W09
    .byte 0x49
    .byte 0x68
    .byte W06
    .byte 0x4B
    .byte W06
    .byte N48, 76
    .byte W48
    .byte N60, 71
    .byte W48
    .byte W15
    .byte N06, 71, 32
    .byte W09
    .byte N24, 70, 104
    .byte W24
    .byte 0x47
    .byte W24
    .byte 0x49
    .byte W24
    .byte N32, 74, 92
    .byte W36
    .byte N05, 73
    .byte W06
    .byte N06, 74, 68
    .byte W06
    .byte N48, 76, 92
    .byte W48
    .byte N32, 77
    .byte W36
    .byte N06, 76, 68
    .byte W06
    .byte 0x4D
    .byte 0x4C
    .byte W06
    .byte N56, 79, 84
    .byte W36
    .byte W02
    .byte VOL, 37
    .byte W01
    .byte 0x23
    .byte W01
    .byte 0x22
    .byte W01
    .byte 0x20
    .byte W01
    .byte 0x1D
    .byte W01
    .byte 0x1C
    .byte W01
    .byte 0x1A
    .byte W01
    .byte 0x18
    .byte W01
    .byte 0x16
    .byte W01
    .byte 0x14
    .byte W01
    .byte 0x12
    .byte W01
    .byte 0x10
    .byte W01
    .byte 0x0E
    .byte W01
    .byte 0x0C
    .byte W01
    .byte 0x0B
    .byte W01
    .byte xIECL
    .byte W01
    .byte 0x07
    .byte W01
    .byte 0x05
    .byte W01
    .byte 0x03
    .byte W01
    .byte 0x01
    .byte W01
    .byte 0x00
    .byte W84
    .byte W02
    .byte W96
    .byte FINE

.align 2
this_song_track6:
    .byte KEYSH, 0
    .byte W96
    .byte W48
    .byte VOICE, 48
    .byte W24
    .byte VOL, 46
    .byte W24
    .byte PAN, 89
    .byte W72
    .byte N04, 61, 92
    .byte W04
    .byte 0x3F
    .byte W04
    .byte 0x40
    .byte W04
    .byte 0x42
    .byte W04
    .byte 0x44
    .byte W04
    .byte 0x46
    .byte W04
    .byte N06, 63, 88
    .byte W06
    .byte 0x3F
    .byte 0x24
    .byte W06
    .byte 0x3F
    .byte 0x44
    .byte W06
    .byte 0x3F
    .byte 0x24
    .byte W18
    .byte 0x38
    .byte 0x5C
    .byte N06, 63
    .byte W06
    .byte 0x3F
    .byte 0x24
    .byte W06
    .byte 0x38
    .byte 0x48
    .byte N06, 63
    .byte W06
    .byte 0x3F
    .byte 0x24
    .byte W18
    .byte 0x38
    .byte 0x5C
    .byte N06, 63
    .byte W06
    .byte 0x3F
    .byte 0x24
    .byte W06
    .byte 0x38
    .byte 0x48
    .byte N06, 63
    .byte W06
    .byte 0x3F
    .byte 0x24
    .byte W06
label_this_song_track6_0:
    .byte W12
    .byte N06, 56, 92
    .byte N06, 63
    .byte W06
    .byte 0x3F
    .byte 0x24
    .byte W06
    .byte 0x38
    .byte 0x48
    .byte N06, 63
    .byte W06
    .byte 0x3F
    .byte 0x24
    .byte W18
    .byte 0x38
    .byte 0x5C
    .byte N06, 63
    .byte W06
    .byte 0x3F
    .byte 0x24
    .byte W06
    .byte 0x38
    .byte 0x48
    .byte N06, 63
    .byte W06
    .byte 0x3F
    .byte 0x24
    .byte W06
    .byte 0x38
    .byte 0x5C
    .byte N06, 63
    .byte W06
    .byte 0x3F
    .byte 0x24
    .byte W06
    .byte 0x38
    .byte 0x48
    .byte N06, 63
    .byte W06
    .byte 0x3F
    .byte 0x24
    .byte W06
    .byte PEND
label_this_song_track6_1:
    .byte N06, 59, 92
    .byte N06, 64, 88
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W06
    .byte 0x3B
    .byte 0x48
    .byte N06, 64, 68
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W18
    .byte 0x3B
    .byte 0x5C
    .byte N06, 64
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W06
    .byte 0x3B
    .byte 0x48
    .byte N06, 64
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W18
    .byte 0x3B
    .byte 0x5C
    .byte N06, 64
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W06
    .byte 0x3B
    .byte 0x48
    .byte N06, 64
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W06
    .byte PEND
label_this_song_track6_2:
    .byte W12
    .byte N06, 59, 92
    .byte N06, 64
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W06
    .byte 0x3B
    .byte 0x48
    .byte N06, 64
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W18
    .byte 0x3B
    .byte 0x5C
    .byte N06, 64
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W06
    .byte 0x3B
    .byte 0x48
    .byte N06, 64
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W06
    .byte 0x3B
    .byte 0x5C
    .byte N06, 64
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W06
    .byte 0x3B
    .byte 0x48
    .byte N06, 64
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W06
    .byte PEND
    .byte 0x39
    .byte 0x5C
    .byte N06, 64, 88
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W06
    .byte 0x39
    .byte 0x48
    .byte N06, 64, 68
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W18
    .byte 0x39
    .byte 0x5C
    .byte N06, 64
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W06
    .byte 0x39
    .byte 0x48
    .byte N06, 64
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W18
    .byte 0x39
    .byte 0x5C
    .byte N06, 64
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W06
    .byte 0x39
    .byte 0x48
    .byte N06, 64
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W06
    .byte W12
    .byte 0x39
    .byte 0x5C
    .byte N06, 64
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W06
    .byte 0x39
    .byte 0x48
    .byte N06, 64
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W18
    .byte 0x39
    .byte 0x5C
    .byte N06, 64
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W06
    .byte 0x39
    .byte 0x48
    .byte N06, 64
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W06
    .byte 0x39
    .byte 0x5C
    .byte N06, 64
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W06
    .byte 0x39
    .byte 0x48
    .byte N06, 64
    .byte W06
    .byte 0x40
    .byte 0x24
    .byte W06
    .byte 0x36
    .byte 0x4C
    .byte N06, 61, 72
    .byte W12
    .byte 0x36
    .byte 0x38
    .byte N06, 61, 52
    .byte W24
    .byte 0x36
    .byte 0x50
    .byte N06, 61, 76
    .byte W12
    .byte 0x36
    .byte 0x3C
    .byte N06, 61
    .byte W24
    .byte 0x36
    .byte 0x5C
    .byte N06, 61
    .byte W12
    .byte 0x36
    .byte 0x48
    .byte N06, 61
    .byte W12
    .byte W12
    .byte 0x36
    .byte 0x5C
    .byte N06, 61, 104
    .byte W12
    .byte 0x36
    .byte 0x44
    .byte N06, 61, 84
    .byte W24
    .byte 0x36
    .byte 0x64
    .byte N06, 61, 112
    .byte W12
    .byte 0x36
    .byte 0x4C
    .byte N06, 61, 88
    .byte W12
    .byte 0x36
    .byte 0x6C
    .byte N06, 61, 120
    .byte W12
    .byte 0x36
    .byte 0x54
    .byte N06, 61, 96
    .byte W12
    .byte 0x38
    .byte 0x5C
    .byte N06, 63, 88
    .byte W06
    .byte 0x3F
    .byte 0x24
    .byte W06
    .byte 0x38
    .byte 0x48
    .byte N06, 63, 68
    .byte W06
    .byte 0x3F
    .byte 0x24
    .byte W18
    .byte 0x38
    .byte 0x5C
    .byte N06, 63
    .byte W06
    .byte 0x3F
    .byte 0x24
    .byte W06
    .byte 0x38
    .byte 0x48
    .byte N06, 63
    .byte W06
    .byte 0x3F
    .byte 0x24
    .byte W18
    .byte 0x38
    .byte 0x5C
    .byte N06, 63
    .byte W06
    .byte 0x3F
    .byte 0x24
    .byte W06
    .byte 0x38
    .byte 0x48
    .byte N06, 63
    .byte W06
    .byte 0x3F
    .byte 0x24
    .byte W06
    .byte PATT
    .word label_this_song_track6_0
    .byte PATT
    .word label_this_song_track6_1
    .byte PATT
    .word label_this_song_track6_2
    .byte N06, 59, 92
    .byte N06, 66, 88
    .byte W06
    .byte 0x42
    .byte 0x24
    .byte W06
    .byte 0x3B
    .byte 0x48
    .byte N06, 66, 68
    .byte W06
    .byte 0x42
    .byte 0x24
    .byte W18
    .byte 0x3B
    .byte 0x5C
    .byte N06, 66
    .byte W06
    .byte 0x42
    .byte 0x24
    .byte W06
    .byte 0x3B
    .byte 0x48
    .byte N06, 66
    .byte W06
    .byte 0x42
    .byte 0x24
    .byte W18
    .byte 0x3B
    .byte 0x5C
    .byte N06, 66
    .byte W06
    .byte 0x42
    .byte 0x24
    .byte W06
    .byte 0x3B
    .byte 0x48
    .byte N06, 66
    .byte W06
    .byte 0x42
    .byte 0x24
    .byte W06
    .byte W12
    .byte 0x3A
    .byte 0x5C
    .byte N06, 67
    .byte W06
    .byte 0x43
    .byte 0x24
    .byte W06
    .byte 0x3A
    .byte 0x48
    .byte N06, 67
    .byte W06
    .byte 0x43
    .byte 0x24
    .byte W18
    .byte 0x3A
    .byte 0x5C
    .byte N06, 62
    .byte W06
    .byte 0x3E
    .byte 0x24
    .byte W06
    .byte 0x3A
    .byte 0x48
    .byte N06, 62
    .byte W06
    .byte 0x3E
    .byte 0x24
    .byte W06
    .byte 0x3E
    .byte 0x5C
    .byte W06
    .byte 0x3E
    .byte 0x24
    .byte W06
    .byte 0x3E
    .byte 0x48
    .byte W06
    .byte 0x3E
    .byte 0x24
    .byte W06
    .byte W96
    .byte W92
    .byte W03
    .byte VOL, 46
    .byte W01
    .byte 0x33
    .byte N08, 60, 80
    .byte W16
    .byte N08
    .byte W08
    .byte N08
    .byte W16
    .byte N08
    .byte W08
    .byte N08
    .byte W08
    .byte 0x3E
    .byte W08
    .byte 0x3F
    .byte W08
    .byte 0x41
    .byte W08
    .byte 0x3F
    .byte W08
    .byte 0x3E
    .byte W08
    .byte 0x3F
    .byte W16
    .byte N08
    .byte W08
    .byte N08
    .byte W16
    .byte N08
    .byte W08
    .byte N08
    .byte W08
    .byte 0x41
    .byte W08
    .byte 0x43
    .byte W08
    .byte 0x44
    .byte W08
    .byte 0x43
    .byte W08
    .byte 0x41
    .byte W08
    .byte 0x42
    .byte W16
    .byte N08
    .byte W08
    .byte N08
    .byte W16
    .byte N08
    .byte W08
    .byte N08
    .byte W08
    .byte 0x44
    .byte W08
    .byte 0x45
    .byte W08
    .byte 0x47
    .byte W08
    .byte 0x45
    .byte W08
    .byte 0x44
    .byte W08
    .byte 0x45
    .byte W16
    .byte N08
    .byte W08
    .byte N08
    .byte W16
    .byte N08
    .byte W08
    .byte 0x45
    .byte 0x5C
    .byte W08
    .byte 0x46
    .byte W08
    .byte 0x48
    .byte W08
    .byte 0x4A
    .byte W08
    .byte 0x4B
    .byte W08
    .byte 0x4D
    .byte W08
    .byte TIE, 79, 96
    .byte W03
    .byte VOL, 48
    .byte W01
    .byte 0x2D
    .byte W01
    .byte 0x2A
    .byte W01
    .byte 0x27
    .byte W01
    .byte 0x23
    .byte W01
    .byte 0x21
    .byte W01
    .byte 0x1E
    .byte W01
    .byte 0x1A
    .byte W01
    .byte 0x18
    .byte W01
    .byte 0x14
    .byte W01
    .byte 0x10
    .byte W01
    .byte 0x10
    .byte W01
    .byte 0x10
    .byte W01
    .byte 0x11
    .byte W01
    .byte 0x12
    .byte W01
    .byte 0x12
    .byte W01
    .byte 0x13
    .byte W01
    .byte 0x14
    .byte W01
    .byte 0x14
    .byte W01
    .byte 0x15
    .byte W01
    .byte 0x16
    .byte W01
    .byte 0x16
    .byte W01
    .byte 0x17
    .byte W01
    .byte 0x18
    .byte W01
    .byte 0x18
    .byte W01
    .byte 0x19
    .byte W01
    .byte 0x1A
    .byte W01
    .byte 0x1A
    .byte W01
    .byte 0x1B
    .byte W01
    .byte 0x1C
    .byte W01
    .byte 0x1C
    .byte W01
    .byte 0x1D
    .byte W01
    .byte 0x1E
    .byte W01
    .byte 0x1E
    .byte W01
    .byte 0x1F
    .byte W01
    .byte 0x20
    .byte W01
    .byte 0x20
    .byte W01
    .byte 0x21
    .byte W01
    .byte 0x22
    .byte W01
    .byte 0x22
    .byte W01
    .byte 0x23
    .byte W01
    .byte 0x24
    .byte W01
    .byte 0x24
    .byte W01
    .byte 0x25
    .byte W01
    .byte 0x26
    .byte W01
    .byte 0x26
    .byte W01
    .byte 0x26
    .byte W02
    .byte 0x25
    .byte W01
    .byte 0x25
    .byte W02
    .byte 0x24
    .byte W01
    .byte 0x24
    .byte W02
    .byte 0x24
    .byte W01
    .byte 0x23
    .byte W02
    .byte 0x23
    .byte W01
    .byte 0x22
    .byte W02
    .byte 0x22
    .byte W01
    .byte 0x22
    .byte W02
    .byte 0x21
    .byte W01
    .byte 0x21
    .byte W02
    .byte 0x20
    .byte W01
    .byte 0x20
    .byte W02
    .byte 0x20
    .byte W01
    .byte 0x1F
    .byte W02
    .byte 0x1F
    .byte W01
    .byte 0x1E
    .byte W02
    .byte 0x1E
    .byte W01
    .byte 0x1E
    .byte W02
    .byte 0x1D
    .byte W01
    .byte 0x1D
    .byte W02
    .byte 0x1C
    .byte W01
    .byte 0x1C
    .byte W02
    .byte 0x1C
    .byte W01
    .byte 0x1B
    .byte W02
    .byte 0x1B
    .byte W01
    .byte 0x1A
    .byte W02
    .byte 0x1A
    .byte W01
    .byte 0x1A
    .byte W02
    .byte 0x19
    .byte W01
    .byte 0x19
    .byte W02
    .byte 0x18
    .byte W01
    .byte 0x18
    .byte W02
    .byte 0x18
    .byte W01
    .byte 0x17
    .byte W02
    .byte 0x17
    .byte W01
    .byte 0x16
    .byte W02
    .byte 0x16
    .byte W01
    .byte 0x16
    .byte W02
    .byte 0x15
    .byte W01
    .byte 0x15
    .byte W02
    .byte 0x14
    .byte W01
    .byte 0x14
    .byte W02
    .byte 0x14
    .byte W01
    .byte 0x13
    .byte W02
    .byte 0x13
    .byte W01
    .byte 0x12
    .byte W02
    .byte 0x12
    .byte W01
    .byte 0x12
    .byte W02
    .byte 0x11
    .byte W01
    .byte 0x11
    .byte W02
    .byte 0x10
    .byte W01
    .byte 0x10
    .byte W02
    .byte 0x10
    .byte W01
    .byte 0x0F
    .byte W02
    .byte 0x0F
    .byte W01
    .byte 0x0E
    .byte W02
    .byte 0x0E
    .byte W01
    .byte 0x0E
    .byte W02
    .byte 0x0D
    .byte W01
    .byte 0x0D
    .byte W02
    .byte 0x0C
    .byte W01
    .byte 0x0C
    .byte W02
    .byte 0x0C
    .byte W01
    .byte 0x0B
    .byte W02
    .byte 0x0B
    .byte W01
    .byte 0x0A
    .byte W02
    .byte 0x0A
    .byte W01
    .byte 0x0A
    .byte W02
    .byte xIECL
    .byte W01
    .byte xIECL
    .byte W02
    .byte xIECV
    .byte W01
    .byte xIECV
    .byte W02
    .byte xIECV
    .byte W01
    .byte 0x07
    .byte W02
    .byte 0x07
    .byte W01
    .byte 0x06
    .byte W02
    .byte 0x06
    .byte W01
    .byte 0x06
    .byte W02
    .byte 0x05
    .byte W01
    .byte 0x05
    .byte W02
    .byte 0x04
    .byte W01
    .byte 0x04
    .byte W02
    .byte 0x04
    .byte W01
    .byte 0x03
    .byte W02
    .byte 0x03
    .byte W01
    .byte 0x02
    .byte W02
    .byte 0x02
    .byte W01
    .byte 0x02
    .byte W02
    .byte 0x01
    .byte W01
    .byte 0x01
    .byte W02
    .byte 0x00
    .byte W01
    .byte 0x00
    .byte W02
    .byte EOT
    .byte VOL, 0
    .byte FINE

.align 2
this_song_track7:
    .byte KEYSH, 0
    .byte W96
    .byte W06
    .byte VOICE, 126
    .byte W24
    .byte VOL, 40
    .byte W24
    .byte PAN, 64
    .byte W42
    .byte W12
    .byte N84, 52, 104
    .byte W48
    .byte W03
    .byte N32, 39, 127
    .byte W32
    .byte W01
label_this_song_track7_0:
    .byte N36, 49, 127
    .byte W24
    .byte N06, 38, 124
    .byte W12
    .byte 0x26
    .byte 0x7F
    .byte W24
    .byte N06
    .byte W12
    .byte 0x26
    .byte 0x54
    .byte W12
    .byte N06
    .byte W06
    .byte N05
    .byte W06
    .byte PEND
label_this_song_track7_1:
    .byte N06, 38, 127
    .byte W06
    .byte N05, 38, 84
    .byte W06
    .byte N05
    .byte W12
    .byte N06
    .byte W12
    .byte 0x26
    .byte 0x7F
    .byte W24
    .byte 0x26
    .byte 0x54
    .byte W12
    .byte N06
    .byte W06
    .byte N05
    .byte W06
    .byte N12, 39
    .byte W12
    .byte PEND
label_this_song_track7_2:
    .byte N06, 38, 127
    .byte W12
    .byte N05, 38, 84
    .byte W12
    .byte N06
    .byte W12
    .byte 0x26
    .byte 0x7F
    .byte W06
    .byte N05, 38, 84
    .byte W18
    .byte N06
    .byte W06
    .byte N05
    .byte W06
    .byte N06, 38, 127
    .byte W12
    .byte 0x26
    .byte 0x54
    .byte W06
    .byte N05
    .byte W06
    .byte PEND
label_this_song_track7_3:
    .byte N06, 38, 127
    .byte W24
    .byte 0x26
    .byte 0x54
    .byte W12
    .byte N06
    .byte W06
    .byte N05
    .byte W18
    .byte N06, 38, 96
    .byte W12
    .byte N24, 39, 108
    .byte W24
    .byte PEND
    .byte PATT
    .word label_this_song_track7_0
    .byte PATT
    .word label_this_song_track7_1
    .byte N06, 38, 96
    .byte W12
    .byte N05, 38, 72
    .byte W12
    .byte N06, 38, 76
    .byte W12
    .byte 0x26
    .byte 0x60
    .byte W06
    .byte N05, 38, 72
    .byte W18
    .byte N06, 38, 76
    .byte W06
    .byte N05
    .byte W06
    .byte N06, 38, 108
    .byte W12
    .byte 0x26
    .byte 0x5C
    .byte W06
    .byte N05, 38, 104
    .byte W06
    .byte N06, 38, 124
    .byte W24
    .byte N06
    .byte W12
    .byte N06
    .byte W06
    .byte N05, 38, 116
    .byte W18
    .byte N06, 38, 127
    .byte W12
    .byte N24, 39
    .byte W24
    .byte PATT
    .word label_this_song_track7_0
    .byte PATT
    .word label_this_song_track7_1
    .byte PATT
    .word label_this_song_track7_2
    .byte PATT
    .word label_this_song_track7_3
    .byte N06, 38, 127
    .byte W06
    .byte N05, 38, 84
    .byte W06
    .byte N05
    .byte W12
    .byte N06, 38, 124
    .byte W12
    .byte 0x26
    .byte 0x7F
    .byte W24
    .byte N06
    .byte W12
    .byte 0x26
    .byte 0x54
    .byte W12
    .byte N06
    .byte W06
    .byte N05
    .byte W06
    .byte PATT
    .word label_this_song_track7_1
    .byte W96
    .byte W48
    .byte N08, 38, 108
    .byte W16
    .byte N08
    .byte W08
    .byte N23, 39
    .byte W24
    .byte N07, 36
    .byte W48
    .byte 0x30
    .byte 0x7F
    .byte W08
    .byte 0x2D
    .byte W08
    .byte 0x29
    .byte W08
    .byte 0x26
    .byte 0x6C
    .byte W16
    .byte N07
    .byte W08
    .byte N07
    .byte W48
    .byte 0x30
    .byte 0x7F
    .byte W08
    .byte 0x2D
    .byte W08
    .byte 0x29
    .byte W08
    .byte 0x26
    .byte 0x6C
    .byte W08
    .byte N07
    .byte W08
    .byte N07
    .byte W08
    .byte N23, 55
    .byte W24
    .byte N07, 41, 127
    .byte W24
    .byte 0x30
    .byte W24
    .byte 0x29
    .byte W08
    .byte 0x2D
    .byte W08
    .byte 0x29
    .byte W08
    .byte 0x30
    .byte W24
    .byte 0x2D
    .byte W12
    .byte TIE, 52
    .byte W12
    .byte N07, 48
    .byte W08
    .byte 0x2D
    .byte W08
    .byte 0x29
    .byte W08
    .byte 0x26
    .byte 0x6C
    .byte W08
    .byte N07
    .byte W08
    .byte N07
    .byte W08
    .byte W96
    .byte W44
    .byte W01
    .byte EOT, 52
    .byte FINE

@ **************************** voice_group ***************************
.align 4
this_song_tone:
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=0 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=1 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=2 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=3 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=4 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=5 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=6 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=7 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=8 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=9 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=10 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=11 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=12 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=13 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=14 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=15 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=16 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=17 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=18 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=19 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=20 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=21 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=22 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=23 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=24 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=25 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=26 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=27 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=28 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=29 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=30 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=31 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=32 (dummy)
tone_data 0x00, 0x3C, 0x00, 0x00, 0x08227988, 0xFF, 0x00, 0xFF, 0xA5 @ index=33
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=34 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=35 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=36 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=37 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=38 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=39 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=40 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=41 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=42 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=43 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=44 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=45 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=46 (dummy)
tone_data 0x00, 0x3C, 0x00, 0x00, 0x08228C7C, 0xFF, 0x00, 0xFF, 0xCC @ index=47
tone_data 0x00, 0x3C, 0x00, 0x00, 0x0822B4DC, 0xFF, 0x00, 0xFF, 0xA5 @ index=48
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=49 (dummy)
tone_data 0x00, 0x3C, 0x00, 0x00, 0x082367A8, 0xFF, 0x00, 0xFF, 0xBC @ index=50
tone_data 0x00, 0x3C, 0x00, 0x00, 0x0823B5FC, 0xFF, 0x00, 0xFF, 0xA5 @ index=51
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=52 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=53 (dummy)
tone_data 0x00, 0x3C, 0x00, 0x00, 0x08247AE8, 0xFF, 0x00, 0xFF, 0xBC @ index=54
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=55 (dummy)
tone_data 0x00, 0x3C, 0x00, 0x00, 0x0824BBAC, 0xFF, 0x00, 0xFF, 0xA5 @ index=56
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=57 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=58 (dummy)
tone_data 0x00, 0x3C, 0x00, 0x00, 0x08261150, 0xFF, 0x00, 0xFF, 0xA5 @ index=59
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=60 (dummy)
tone_data 0x00, 0x3C, 0x00, 0x00, 0x0826CFD0, 0xFF, 0x00, 0xFF, 0xA5 @ index=61
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=62 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=63 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=64 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=65 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=66 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=67 (dummy)
tone_data 0x00, 0x3C, 0x00, 0x00, 0x0827BBD0, 0x80, 0x00, 0xFF, 0xA5 @ index=68
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=69 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=70 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=71 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=72 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=73 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=74 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=75 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=76 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=77 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=78 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=79 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=80 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=81 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=82 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=83 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=84 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=85 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=86 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=87 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=88 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=89 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=90 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=91 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=92 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=93 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=94 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=95 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=96 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=97 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=98 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=99 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=100 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=101 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=102 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=103 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=104 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=105 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=106 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=107 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=108 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=109 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=110 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=111 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=112 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=113 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=114 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=115 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=116 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=117 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=118 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=119 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=120 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=121 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=122 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=123 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=124 (dummy)
tone_data 0x01, 0x3C, 0x00, 0x00, 0x00000002, 0x00, 0x00, 0x0F, 0x00 @ index=125 (dummy)
tone_data 0x80, 0x00, 0x00, 0x00, 0x08222FB0, 0x00, 0x00, 0x00, 0x00 @ index=126
