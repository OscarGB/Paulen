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
_main_suma@1@1:
		push ebp
		mov ebp, esp
		sub esp, 4*0
		lea eax, [ebp+4+4*2]
		push dword eax
		lea eax, [ebp+4+4*1]
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
		push dword 1

		; Asignacion de pila a main_x
		pop dword eax
		mov dword [_main_x], eax
		push dword 3

		; Asignacion de pila a main_y
		pop dword eax
		mov dword [_main_y], eax
		push dword [_main_x]
		push dword [_main_y]
		call _main_suma@1@1
		add esp, 4*2
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

		push dword [_main_x]
		push dword 1
		call _main_suma@1@1
		add esp, 4*2
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

		push dword 10
		push dword [_main_y]
		call _main_suma@1@1
		add esp, 4*2
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

		push dword 3
		push dword 5
		call _main_suma@1@1
		add esp, 4*2
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
