;***********************************************************
;* Mikrokopter ?A                                          *
;* based on tgy.inc                                        *
;* http://home.versanet.de/~b-konze/                       *
;* http://home.versanet.de/~b-konze/blc_18a/blc_18a.htm    *
;***********************************************************

.set	F_CPU		= 16000000
.equ	USE_INT0	= 0
.equ	USE_I2C		= 1
.equ	USE_UART	= 1
.equ	USE_ICP		= 1

.equ    DEAD_LOW_NS     = 450	; May work on some boards, but be careful!
.equ    DEAD_HIGH_NS    = 8000

;*********************
; PORT D definitions *
;*********************
;.equ	mux_c		= 7	;i <plus> comparator input (AIN0)
;.equ	c_comp		= 6	;i common comparator input (AIN0)
.equ	AnFET		= 3
.equ	BnFET		= 4
.equ	CnFET		= 5
.equ	txd			= 1	;o

.equ	INIT_PD		= 0
.equ	DIR_PD		= (1<<AnFET)+(1<<BnFET)+(1<<CnFET)

.equ	AnFET_port	= PORTD
.equ	BnFET_port	= PORTD
.equ	CnFET_port	= PORTD

;*********************
; PORT C definitions *
;*********************
;.equ			= 7	; ADC7
;.equ			= 6	; ADC6
.equ	mux_a		= 0	; ADC0 phase input
.equ	mux_b		= 1	; ADC1 phase input
.equ	mux_c		= 2	; ADC2 phase input
;.equ			= 3	; ADC3
;.equ			= 2	; ADC2 (plush has something on here)
;.equ	mux_temperature	= 1	; ADC1 temperature input
;.equ	mux_voltage	= 0	; ADC0 voltage input (10k from Vbat, 1k to gnd, 10.10V -> .918V at ADC0)

.equ	red_led		= 3	; o
.equ	green_led	= 6	; o

;.equ	O_POWER		= 10
;.equ	O_GROUND	= 1

.equ	INIT_PC		= 0
.equ	DIR_PC		= 0

.MACRO RED_on
	sbi	DDRC, red_led
.ENDMACRO
.MACRO RED_off
	cbi	DDRC, red_led
.ENDMACRO
.MACRO GRN_on
	sbi	DDRC, green_led
.ENDMACRO
.MACRO GRN_off
	cbi	DDRC, green_led
.ENDMACRO

;*********************
; PORT B definitions *
;*********************
;.equ			= 7
;.equ			= 6
;.equ			= 5	(sck stk200 interface)
;.equ			= 4	(miso stk200 interface)
;.equ			= 3	(mosi stk200 interface)
.equ	ApFET	= 3	;o
.equ	BpFET	= 2	;o
.equ	CpFET	= 1	;o
.equ	rcp_in	= 0	;i r/c pulse input

.equ	INIT_PB		= 0
.equ	DIR_PB		= (1<<ApFET)+(1<<BpFET)+(1<<CpFET)

.equ	ApFET_port	= PORTB
.equ	BpFET_port	= PORTB
.equ	CpFET_port	= PORTB
