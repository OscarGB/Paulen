segment .data
mensaje_1 db "Indice fuera de rango", 0
mensaje_2 db "Division por cero", 0

segment .bss
__esp resd 1
_main_x2 resd 1
_main_z resd 1
_main_y1 resd 1
_main_x1 resd 1

segment .text
global main
extern print_int, print_boolean, print_string, print_blank, print_endofline, scan_int, scan_boolean
_main_doble@1:
		push ebp
		mov ebp, esp
		sub esp, 4*1
		lea eax, [ebp+4+4*1]
		push dword eax
		pop dword eax
		mov dword eax, [eax]
		mov dword [ebp-4*0], eax
		push dword 2
		lea eax, [ebp+4+4*1]
		push dword eax

		; Multiplicacion
		pop dword ebx
		pop dword eax
		imul dword [ebx]
		push dword eax
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
_main_igual@1@1:
		push ebp
		mov ebp, esp
		sub esp, 4*0
		lea eax, [ebp+4+4*2]
		push dword eax
		lea eax, [ebp+4+4*1]
		push dword eax

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
		je __else_1
		;Nos metemos en el caso del then (1) ya que se cumple la condicion
		push dword 1
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
		; Estamos en la parte del final del then (1) del ifthen_else
		jmp __endifthen_else_1
		__else_1:
		push dword 0
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
		; Estamos en la parte del final del else (1) del ifthen_else
		__endifthen_else_1:
_main_imprime@1@1@3:
		push ebp
		mov ebp, esp
		sub esp, 4*0
		lea eax, [ebp+4+4*3]
		push dword eax
		lea eax, [ebp+4+4*2]
		push dword eax

		; Comparacion de igualdad
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
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
		; En caso de que no se cumpla la condicion nos vamos al else
		je __else_3
		;Nos metemos en el caso del then (3) ya que se cumple la condicion
		lea eax, [ebp+4+4*1]
		push dword eax
		; Comprobamos la condicion: if (4) para ver que es algo asimilable a una variable
		pop eax
		mov eax, [eax]
		cmp eax, 0
		; En caso de que no se cumpla la condicion nos vamos al else
		je __else_4
		;Nos metemos en el caso del then (4) ya que se cumple la condicion
		push dword 110

		; Escritura
		call print_int
		call print_endofline
		add esp, 4

		; Estamos en la parte del final del then (4) del ifthen_else
		jmp __endifthen_else_4
		__else_4:
		push dword 111

		; Escritura
		call print_int
		call print_endofline
		add esp, 4

		; Estamos en la parte del final del else (4) del ifthen_else
		__endifthen_else_4:
		; Estamos en la parte del final del then (3) del ifthen_else
		jmp __endifthen_else_3
		__else_3:
		lea eax, [ebp+4+4*1]
		push dword eax
		; Comprobamos la condicion: if (5) para ver que es algo asimilable a una variable
		pop eax
		mov eax, [eax]
		cmp eax, 0
		; En caso de que no se cumpla la condicion nos vamos al else
		je __else_5
		;Nos metemos en el caso del then (5) ya que se cumple la condicion
		push dword 10

		; Escritura
		call print_int
		call print_endofline
		add esp, 4

		; Estamos en la parte del final del then (5) del ifthen_else
		jmp __endifthen_else_5
		__else_5:
		push dword 11

		; Escritura
		call print_int
		call print_endofline
		add esp, 4

		; Estamos en la parte del final del else (5) del ifthen_else
		__endifthen_else_5:
		; Estamos en la parte del final del else (3) del ifthen_else
		__endifthen_else_3:
		push dword 1
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret

; PROCEDIMIENTO PRINCIPAL
main:
mov dword [__esp], esp

		; Lectura
		push dword _main_z
		call scan_int
		add esp, 4
		push dword [_main_z]
		call _main_doble@1
		add esp, 4*1
		push dword eax

		; Escritura
		call print_int
		call print_endofline
		add esp, 4


		; Lectura
		push dword _main_x1
		call scan_int
		add esp, 4

		; Lectura
		push dword _main_x2
		call scan_int
		add esp, 4
		push dword [_main_x1]
		push dword [_main_x2]
		call _main_igual@1@1
		add esp, 4*2
		push dword eax

		; Escritura
		call print_boolean
		call print_endofline
		add esp, 4


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
		push dword [_main_x1]
		push dword [_main_x2]
		push dword [_main_y1]
		call _main_imprime@1@1@3
		add esp, 4*3
		push dword eax

		; Escritura
		call print_boolean
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
