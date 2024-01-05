.include "lynx.inc"
.interruptor _com
.export _receivecount

_receivecount:
	.byte   $00

.proc   _com: near

.segment "CODE"
	lda $FD81
	and #$10
	beq done

	inc _receivecount
	lda $FD8D
	lda	#$10
	sta	$FD80 

done:
	clc
	rts
	
.endproc
