	.import __BANK0BLOCKSIZE__
	.import __STARTOFDIRECTORY__
	.import __MAIN_START__
.ifdef release
	.import __LOADER_SIZE__
	.import __TITLE_START__
	.import __TITLE_SIZE__ 
.endif
	.export _MAIN_FILENR : absolute
	.import __STARTUP_LOAD__
	.import __STARTUP_SIZE__ 
	.import __LOWCODE_SIZE__
	.import __ONCE_SIZE__ 
	.import __CODE_SIZE__
	.import __DATA_SIZE__ 
	.import __RODATA_SIZE__

	.export _GAME_FILENR : absolute
	.import __GAME_CODE_LOAD__ 
	.import __GAME_CODE_SIZE__
	.import __GAME_DATA_SIZE__
	.import __GAME_RODATA_SIZE__

	.segment "DIRECTORY"

.macro entry old_off, old_len, new_off, new_block, new_len, new_size, new_addr
new_off=old_off+old_len
new_block=new_off/__BANK0BLOCKSIZE__
new_len=new_size
	.byte	<new_block
	.word	(new_off & (__BANK0BLOCKSIZE__ - 1))
	.byte	$88
	.word	new_addr
	.word	new_len
.endmacro

__DIRECTORY_START__: 
 
.ifdef release

; Entry 0 - Title sprite (mandatory)
_TITLE_FILENR=0
entry __LOADER_SIZE__, __DIRECTORY_END__-__DIRECTORY_START__, off0, block0, len0, __TITLE_SIZE__, __TITLE_START__

; Entry 1 - First executable (mandatory)  
_MAIN_FILENR=_TITLE_FILENR+1
entry off0, len0, mainoff, mainblock, mainlen, __STARTUP_SIZE__+__ONCE_SIZE__+__CODE_SIZE__+__DATA_SIZE__+__RODATA_SIZE__+__LOWCODE_SIZE__, __MAIN_START__

.endif

.ifdef debug 

_MAIN_FILENR=0 
entry __STARTOFDIRECTORY__+(__DIRECTORY_END__-__DIRECTORY_START__), 0, mainoff, mainblock, mainlen, __STARTUP_SIZE__+__ONCE_SIZE__+__CODE_SIZE__+__RODATA_SIZE__+__DATA_SIZE__+__LOWCODE_SIZE__, __STARTUP_LOAD__

.endif 

_GAME_FILENR=_MAIN_FILENR+1
entry mainoff, mainlen, gameoff, gameblock, gamelen, __GAME_CODE_SIZE__+__GAME_RODATA_SIZE__+__GAME_DATA_SIZE__, __GAME_CODE_LOAD__

__DIRECTORY_END__:
