segment .data
mensaje_1 db "Indice fuera de rango", 0
mensaje_2 db "Division por cero", 0

segment .bss
__esp resd 1
_main_y resd 1
_main_resultado resd 1
_main_x resd 1

segment .text
global main
extern print_int, print_boolean, print_string, print_blank, print_endofline, scan_int, scan_boolean

; PROCEDIMIENTO PRINCIPAL
main:
mov dword [__esp], esp

		; Lectura
		push dword _main_x
		call scan_int
		add esp, 4

		; Lectura
		push dword _main_y
		call scan_int
		add esp, 4
		push dword _main_x
		push dword _main_y

		; Exponencial
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
		mov dword ebx, [ebx]
		mov dword ecx, eax
		cmp ebx, 0
		je __es_uno_0
		jmp __no_es_uno_0
		__es_uno_0:
		mov eax, 1
		jmp __fin_exp_0
		__no_es_uno_0:
		cmp ebx, 1
		je __elevado_a_uno_0
		imul dword ecx
		dec ebx
		jmp __no_es_uno_0
		__elevado_a_uno_0:
		jmp __fin_exp_0
		__fin_exp_0:
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


		; Lectura
		push dword _main_x
		call scan_int
		add esp, 4

		; Lectura
		push dword _main_y
		call scan_int
		add esp, 4
		push dword _main_x
		push dword _main_y

		; Exponencial
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
		mov dword ebx, [ebx]
		mov dword ecx, eax
		cmp ebx, 0
		je __es_uno_1
		jmp __no_es_uno_1
		__es_uno_1:
		mov eax, 1
		jmp __fin_exp_1
		__no_es_uno_1:
		cmp ebx, 1
		je __elevado_a_uno_1
		imul dword ecx
		dec ebx
		jmp __no_es_uno_1
		__elevado_a_uno_1:
		jmp __fin_exp_1
		__fin_exp_1:
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
