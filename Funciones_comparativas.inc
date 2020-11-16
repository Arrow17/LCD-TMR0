    ;Se presenta en la sguiente funcion el comportamiento de una XORWF
     sobre una variable llamada AUX, comparando con una serie de valores
     0x06, 0x07. Es un claro ejemplo de un Switch(case) en ASM.
    CASE1  
    MOVF  AUX,W
    XORWF 0x06,0   ;USO XORWF PARA HACER UNA OPERACION XOR SOBRE AUX Y W
    BTFSC STATUS,2 ; EL RESULTADO DEL XOR SE GUARDA EN Z QUE ES EL BIT 2 DE STATUS
    GOTO  ACTION1  
    GOTO  CASE2 
   
    CASE2  
    MOVF  AUX,W
    XORWF 0x07,0   ;USO XORWF PARA HACER UNA OPERACION XOR SOBRE AUX Y W
    BTFSC STATUS,2 ; EL RESULTADO DEL XOR SE GUARDA EN Z QUE ES EL BIT 2 DE STATUS
    GOTO  ACTION2
    GOTO  BUCLE3
     


    ;Se presenta la función equivalente.
    MOVLW   0x0A
	  SUBWF   AUX,w
	  BTFSS   STATUS,C
	  GOTO    AUX_ES_MENOR_A_0x0A
	  BTFSS   STATUS,Z
	  GOTO    AUX_ES_MAYOR_A_0x0A
	  GOTO    AUX_ES_IGUAL_A_0x0A
	       	       
	       
	       















