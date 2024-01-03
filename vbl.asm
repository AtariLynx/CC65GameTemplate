.interruptor _vbl
.export _framecount
.export _seconds
.export _minutes

_framecount:
	.byte   $00
_seconds:
	.byte   $05
_minutes:
	.byte   $14

.proc   _vbl: near

.segment "CODE"
	lda $FD81
	and #$04
	beq done

	inc _framecount
	lda _framecount
	cmp #60
	bne done
	
	dec _seconds
	stz _framecount
	lda _seconds
	bpl done
	
	lda #59
	sta _seconds
	dec _minutes

done:
	clc
	rts
	
.endproc