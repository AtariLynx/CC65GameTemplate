;
; Karri Kaksonen, 2017
;
; This header contains data for emulators like Handy and Mednafen
;
	.import	__BANK0BLOCKSIZE__
	.export	__LNXHDR__: absolute = 1

; ------------------------------------------------------------------------
; LNX header
	.segment "LNXHDR"
	.byte	'L','Y','N','X'		; magic
	.word	__BANK0BLOCKSIZE__	; bank 0 page size
	.word	0					; bank 1 page size
	.word	1					; version number
	.asciiz	"Atari Lynx Game                "	; 32 bytes cart name
	.asciiz	"               "	; 16 bytes manufacturer
	.byte	0					; rotation 1=left
								; rotation 2=right
	.byte	0					; AUDIN not used
	.byte   $41					; 93C46 support 16-bit
	.byte	0,0,0				; spare