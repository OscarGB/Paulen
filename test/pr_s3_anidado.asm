segment .data
mensaje_1 db "Indice fuera de rango", 0
mensaje_2 db "Division por cero", 0

segment .bss
__esp resd 1
_main_x2 resd 1
_main_y1 resd 1
_main_x1 resd 1

segment .text
global main
extern print_int, print_boolean, print_string, print_blank, print_endofline, scan_int, scan_boolean

; PROCEDIMIENTO PRINCIPAL
main:
mov dword [__esp], esp

		; Lectura
		push dword _main_x1
		call scan_int
		add esp, 4

		; Lectura
		push dword _main_x2
		call scan_int
		add esp, 4

		; Lectura
		push dword _main_y1
		call scan_boolean
		add esp, 4
		push dword _main_x1
		push dword _main_x2

		; Comparacion de igualdad
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
		cmp eax, [ebx]
		je __igual_0
		push dword 0
		jmp __fin_igual_0
		__igual_0:
		push dword 1
		__fin_igual_0:
		; Comprobamos la condicion: if (1) para ver que es algo asimilable a una variable
		pop eax
		cmp eax, 0
		; En caso de que no se cumpla la condicion nos vamos al else
		je __end_if_1
		;Nos metemos en el caso del then (1) ya que se cumple la condicion
		push dword _main_y1
		; Comprobamos la condicion: if (2) para ver que es algo asimilable a una variable
		pop eax
		mov eax, [eax]
		cmp eax, 0
		; En caso de que no se cumpla la condicion nos vamos al else
		je __end_if_2
		;Nos metemos en el caso del then (2) ya que se cumple la condicion
		push dword 110

		; Escritura
		call print_int
		call print_endofline
		add esp, 4

		; Estamos en la parte del final del then (2) del ifthen_else
		jmp __end_if_2
		__else_2:
		push dword 111

		; Escritura
		call print_int
		call print_endofline
		add esp, 4

		; Estamos en la parte del final del else (2) del ifthen_else
		__end_if_2:
		; Estamos en la parte del final del then (1) del ifthen_else
		jmp __end_if_1
		__else_1:
		push dword _main_y1
		; Comprobamos la condicion: if (3) para ver que es algo asimilable a una variable
		pop eax
		mov eax, [eax]
		cmp eax, 0
		; En caso de que no se cumpla la condicion nos vamos al else
		je __end_if_3
		;Nos metemos en el caso del then (3) ya que se cumple la condicion
		push dword 10

		; Escritura
		call print_int
		call print_endofline
		add esp, 4

		; Estamos en la parte del final del then (3) del ifthen_else
		jmp __end_if_3
		__else_3:
		push dword 11

		; Escritura
		call print_int
		call print_endofline
		add esp, 4

		; Estamos en la parte del final del else (3) del ifthen_else
		__end_if_3:
		; Estamos en la parte del final del else (1) del ifthen_else
		__end_if_1:

		;FINAL DEL PROGRAMA
		jmp near _fin
__error_division:
		push mensaje_2
		jmp near __salida_mensaje_error
__error_rango:
		push mensaje_1
		jmp near __salida_mensaje_error
__salida_mensaje_error:
		call print_string
		call print_endofline
		_fin:
		mov dword esp, [__esp]
		ret
