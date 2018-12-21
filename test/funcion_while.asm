segment .data
mensaje_1 db "Indice fuera de rango", 0
mensaje_2 db "Division por cero", 0

segment .bss
__esp resd 1
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
		inicio_while1:
		push dword _main_x1
		push dword 4

		; Comparacion de menor o igual
		pop dword ebx
		pop dword eax
		mov eax, dword [eax]
		cmp eax, ebx
		jle __menor_o_igual_1
		push dword 0
		jmp __fin_menor_o_igual_1
		__menor_o_igual_1:
		push dword 1
		__fin_menor_o_igual_1:
		pop eax
		cmp eax, 0
		je near fin_while1
		push dword 2
		push dword _main_x1

		; Multiplicacion
		pop dword ebx
		pop dword eax
		imul dword [ebx]
		push dword eax

		; Escritura
		call print_int
		call print_endofline
		add esp, 4

		push dword _main_x1
		push dword 1

		; Suma
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
		add eax, ebx
		push dword eax

		; Asignacion de pila a main_x1
		pop dword eax
		mov dword [_main_x1], eax
		push dword _main_x1
		push dword 5

		; Comparacion de igualdad
		pop dword eax
		pop dword ebx
		cmp eax, [ebx]
		je __igual_1
		push dword 0
		jmp __fin_igual_1
		__igual_1:
		push dword 1
		__fin_igual_1:
		; Comprobamos la condicion: if (2) para ver que es algo asimilable a una variable
		pop eax
		cmp eax, 0
		; En caso de que no se cumpla la condicion nos vamos al final del ifthen
		je __end_if_2
		; En caso de que se cumpla nos metemos en el caso del then (2) ya que se cumple la condicion
		push dword 1

		; Escritura
		call print_boolean
		call print_endofline
		add esp, 4

		; Estamos en la parte del final del then (2) del ifthen_else
		jmp __end_ifthen_2
		__end_if_2:
		push dword 0

		; Escritura
		call print_boolean
		call print_endofline
		add esp, 4

		; Estamos en la parte del final del else (2) del ifthen_else
		__end_ifthen_2:
		jmp near inicio_while1
		fin_while1:

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
