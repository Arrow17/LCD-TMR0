


;ESTA LIBRERIA FUNCIONA UNICAMENTE CON ESTE VALOR DE OSCCON.

;   MOVLW 0x62     
;   MOVWF OSCCON 

    
#DEFINE RS PORTA,0
#DEFINE E  PORTA,1
    
LCD_INIT MACRO x ;Se inicializa LCD
 
if x==0
 
endif

if x==1
TMR0N 0x01,0x3C,0xB0
LCD_CMD b'00000001' ;Limpia pantalla, cursor en 0x00
LCD_CMD b'00111000' ;4 Bits, 2 Líneas, 5x7 Puntos
LCD_CMD b'00001100' ;Display ON, Cursor OFF
LCD_CMD b'00000110' ;Movimiento del cursor a la derecha
LCD_CMD b'10000011' ;Coloca cursor en (1,3)
endif  

if x==0
CLRF PORTB
CLRF PORTB
endif  
    
ENDM    
    
    
LCD_DAT MACRO DATE ;Subrutina para cargar datos

BSF RS
MOVLW DATE
MOVWF PORTB ;Despliega valor
BSF E
TMR0N 0x03,0xFF,0x06 ;DELAY A 2MS
BCF E
ENDM

LCD_CMD MACRO COMANDO ;Subrutina para cargar comandos
BCF RS
MOVLW COMANDO
MOVWF PORTB ;Despliega valor
BSF E
TMR0N 0x03,0xFF,0x06 ;DELAY A 2MS
BCF E
ENDM

	     
	     	     
LCD_GOTO MACRO X,Y
 
  if Y==1
      MOVLW X
      MOVWF X
      BCF RS
      MOVLW 0X80
      ADDWF X,0
      MOVWF PORTB
      BSF E
      TMR0N 0x03,0xFF,0x06 ;DELAY A 2MS
      BCF E
 endif
 
 if Y==2
      MOVLW X
      MOVWF X
      BCF RS
      MOVLW 0XC0
      ADDWF X,0
      MOVWF PORTB
      BSF E
      TMR0N 0x03,0xFF,0x06 ;DELAY A 2MS
      BCF E
 endif
 
 ENDM
 

    








