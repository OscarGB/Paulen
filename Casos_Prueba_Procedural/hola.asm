segment .data
mensaje_1 db "Indice fuera de rango", 0
mensaje_2 db "Division por cero", 0

segment .bss
__esp resd 1
_main_resultado resd 1
_main_x resd 1

segment .text
global main
extern print_int, print_boolean, print_string, print_blank, print_endofline, scan_int, scan_boolean
_main_fibonacci@1:
		push ebp
		mov ebp, esp
		sub esp, 4*2
		lea eax, [ebp+4+4*1]
		push dword eax
		push dword 0

		; Comparacion de igualdad
		pop dword eax
		pop dword ebx
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
		; En caso de que no se cumpla la condicion nos vamos al final del ifthen
		je __end_if_1
		; En caso de que se cumpla nos metemos en el caso del then (1) ya que se cumple la condicion
		push dword 0
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
		; Estamos en la parte del final del then (1) del ifthen
		__end_if_1:
		lea eax, [ebp+4+4*1]
		push dword eax
		push dword 1

		; Comparacion de igualdad
		pop dword eax
		pop dword ebx
		cmp eax, [ebx]
		je __igual_2
		push dword 0
		jmp __fin_igual_2
		__igual_2:
		push dword 1
		__fin_igual_2:
		; Comprobamos la condicion: if (3) para ver que es algo asimilable a una variable
		pop eax
		cmp eax, 0
		; En caso de que no se cumpla la condicion nos vamos al final del ifthen
		je __end_if_3
		; En caso de que se cumpla nos metemos en el caso del then (3) ya que se cumple la condicion
		push dword 1
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
		; Estamos en la parte del final del then (3) del ifthen
		__end_if_3:
		lea eax, [ebp+4+4*1]
		push dword eax
		push dword 1

		; Resta
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
		sub eax, ebx
		push dword eax
		call _main_fibonacci@1
		add esp, 4*1
		push dword eax
		pop dword eax
		mov dword [ebp-4*0], eax
		lea eax, [ebp+4+4*0]
		push dword eax
		push dword 2

		; Resta
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
		sub eax, ebx
		push dword eax
		call _main_fibonacci@1
		add esp, 4*1
		push dword eax
		pop dword eax
		mov dword [ebp-4*0], eax
		lea eax, [ebp-4*0]
		push dword eax
		lea eax, [ebp-4*0]
		push dword eax

		; Suma
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
		mov dword ebx, [ebx]
		add eax, ebx
		push dword eax
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret

; PROCEDIMIENTO PRINCIPAL
main:
mov dword [__esp], esp

		; Lectura
		push dword _main_x
		call scan_int
		add esp, 4
		push dword [_main_x]
		call _main_fibonacci@1
		add esp, 4*1
		push dword eax

		; Asignacion de pila a main_resultado
		pop dword eax
		mov dword [_main_resultado], eax
		push dword _main_resultado

		; Escritura
		pop eax
		push dword [eax]
		call print_int
		call print_endofline
		add esp, 4


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
