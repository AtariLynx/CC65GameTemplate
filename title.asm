.include "lynx.inc"
.org $2400
.export __TITLE_START__
.export __TITLE_SIZE__

.segment "TITLESCR"

__TITLE_SIZE__ = title_end - __TITLE_START__

__TITLE_START__:

; Handy color palette
; Greens
.byte	$00,$00,$07,$0C,$07,$0A,$05,$0D,$0F,$08,$0E,$05,$02,$0B,$03,$0F
; Blue-reds
.byte	$00,$5F,$BF,$CC,$A8,$0F,$56,$BF,$2F,$50,$50,$3B,$58,$F3,$52,$EF

erase_sprite:
; Handy Sprite
	.byte	BPP_1+TYPE_BACKNONCOLL	; Control 0
	.byte	REHVST+LITERAL		; Control 1
	.byte	$00	; Control 2
	.word   title_sprite	; Next sprite's address
	.word   erase_sprite_data
	.word	0	; HPos
	.word	0	; VPos
	.word	$A000	; HSize
	.word	$6600	; VSize
	.word	$0000	; Stretch
	.word	$0000	; Tilt
	.byte	$00	    ; Palette

title_sprite:
; Handy Sprite
	.byte	BPP_4+TYPE_NONCOLL ; Control 0
	.byte	REHVST ; Control 1
	.byte	$00 ; Control 2
	.word	$0000	; Next Sprite
	.word	title_sprite_data	; ImageData
	.word	0	; HPos
	.word	0	; VPos
	.word	$0100	; HSize
	.word	$0100	; VSize
	.word	$0000	; Stretch
	.word	$0000	; Tilt
	; Palette
	.byte	$01,$23,$45,$67,$89,$AB,$CD,$EF

erase_sprite_data:
; Handy Sprite Image Data
; Bits per Pixel = 1
; Next data is down-right
	.byte	$02,$00
	.byte	$00

title_sprite_data:
	.incbin "title.spr"

title_end: