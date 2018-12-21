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
		jl near mensaje_1
		; Si el indice es mayor de lo permitido, error en tiempo de ejecucion
		cmp eax, 7
		jg near mensaje_1
		mov dword edx, _main_A1
		lea eax, [edx + eax * 4]
		push dword eax
		push dword 2
		push dword 2
		; carga el valor del indice en eax
		pop dword eax 
		; Si el indice es menor que 0, error en tiempo de ejecucion
		cmp eax,0
		jl near mensaje_1
		; Si el indice es mayor de lo permitido, error en tiempo de ejecucion
		cmp eax, 7
		jg near mensaje_1
		mov dword edx, _main_A2
		lea eax, [edx + eax * 4]
		push dword eax
		push dword 8
		push dword 5
		; carga el valor del indice en eax
		pop dword eax 
		; Si el indice es menor que 0, error en tiempo de ejecucion
		cmp eax,0
		jl near mensaje_1
		; Si el indice es mayor de lo permitido, error en tiempo de ejecucion
		cmp eax, 7
		jg near mensaje_1
		mov dword edx, _main_A1
		lea eax, [edx + eax * 4]
		push dword eax

		; Escritura
		pop eax
		push dword [eax]
		call print_int
		call print_endofline
		add esp, 4

jmp near fin

error_1: push dword mensaje_1
	  call print_string
	  add esp, 4
	  jmp near fin

error_2: push dword mensaje_2
         call print_string
         add esp, 4
         jmp near fin

fin:
mov dword esp, [__esp]
ret
