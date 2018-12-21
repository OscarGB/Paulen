segment .data
mensaje_1 db "Indice fuera de rango", 0
mensaje_2 db "Division por cero", 0

segment .bss
__esp resd 1
_main_y resd 1
_main_resultado resd 1
_main_i resd 1
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
		push dword 0

		; Asignacion de pila a main_resultado
		pop dword eax
		mov dword [_main_resultado], eax
		push dword 0

		; Asignacion de pila a main_i
		pop dword eax
		mov dword [_main_i], eax
		inicio_while1:
		push dword _main_i
		push dword _main_y

		; Comparacion de menor
		pop dword ebx
		pop dword eax
		mov eax, dword [eax]
		mov ebx, dword [ebx]
		cmp eax, ebx
		jl __menor_1
		push dword 0
		jmp __fin_menor_1
		__menor_1:
		push dword 1
		__fin_menor_1:
		pop eax
		cmp eax, 0
		je near fin_while1
		push dword _main_resultado
		push dword _main_x

		; Suma
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
		mov dword ebx, [ebx]
		add eax, ebx
		push dword eax

		; Asignacion de pila a main_resultado
		pop dword eax
		mov dword [_main_resultado], eax
		push dword _main_i
		push dword 1

		; Suma
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
		add eax, ebx
		push dword eax

		; Asignacion de pila a main_i
		pop dword eax
		mov dword [_main_i], eax
		jmp near inicio_while1
		fin_while1:
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
