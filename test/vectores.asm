segment .data
mensaje_1 db "Indice fuera de rango", 0
mensaje_2 db "Division por cero", 0

segment .bss
__esp resd 1
_main_A1 resd 1
_main_A2 resd 1

segment .text
global main
extern print_int, print_boolean, print_string, print_blank, print_endofline, scan_int, scan_boolean

; PROCEDIMIENTO PRINCIPAL
main:
mov dword [__esp], esp
		push dword 5
		; carga el valor del indice en eax
		pop dword eax 
		; Si el indice es menor que 0, error en tiempo de ejecucion
		cmp eax,0
		jl near __error_rango
		; Si el indice es mayor de lo permitido, error en tiempo de ejecucion
		cmp eax, 7
		jg near __error_rango
		mov dword edx, _main_A1
		lea eax, [edx + eax * 4]
		push dword eax
		push dword 2
		; Cargar en eax la parte derecha de la asignacion
		pop dword eax
		; Cargar en edx la parte izquierda de la asignacion
		pop dword edx
		; Hacer la asignacion efectiva
		mov dword [edx], eax
		push dword 2
		; carga el valor del indice en eax
		pop dword eax 
		; Si el indice es menor que 0, error en tiempo de ejecucion
		cmp eax,0
		jl near __error_rango
		; Si el indice es mayor de lo permitido, error en tiempo de ejecucion
		cmp eax, 7
		jg near __error_rango
		mov dword edx, _main_A2
		lea eax, [edx + eax * 4]
		push dword eax
		push dword 8
		; Cargar en eax la parte derecha de la asignacion
		pop dword eax
		; Cargar en edx la parte izquierda de la asignacion
		pop dword edx
		; Hacer la asignacion efectiva
		mov dword [edx], eax
		push dword 5
		; carga el valor del indice en eax
		pop dword eax 
		; Si el indice es menor que 0, error en tiempo de ejecucion
		cmp eax,0
		jl near __error_rango
		; Si el indice es mayor de lo permitido, error en tiempo de ejecucion
		cmp eax, 7
		jg near __error_rango
		mov dword edx, _main_A1
		lea eax, [edx + eax * 4]
		push dword eax
		push dword 2
		; carga el valor del indice en eax
		pop dword eax 
		; Si el indice es menor que 0, error en tiempo de ejecucion
		cmp eax,0
		jl near __error_rango
		; Si el indice es mayor de lo permitido, error en tiempo de ejecucion
		cmp eax, 7
		jg near __error_rango
		mov dword edx, _main_A2
		lea eax, [edx + eax * 4]
		push dword eax

		; Suma
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
		mov dword ebx, [ebx]
		add eax, ebx
		push dword eax

		; Escritura
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
