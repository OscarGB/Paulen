segment .data
mensaje_1 db "Indice fuera de rango", 0
mensaje_2 db "Division por cero", 0
mensaje_prueba db "Me caguen tu padre", 0

segment .bss
__esp resd 1
_c1 resd 1
_c2 resd 1
_d1 resd 1
_m resd 1
_Vobjs resd 1
_vector_int resd 4
_c3 resd 1

segment .text
global main
extern print_int, print_boolean, print_string, print_blank, print_endofline, scan_int, scan_boolean
	extern  _msA1, _msA2,  _msB1, _msB2, _msC1, _msC2, _msD1, _msD2, _BmsA1, _CmsA1, _CmsA2, _no_defined_method, _mnsA1, _mnsB1, _mnsC1, _mnsD1, _set_offsets, _create_ms_table, _offset_msA1, _offset_msA2, _offset_msB1, _offset_msB2, _offset_msC1, _offset_msC2, _offset_msD1,     _offset_msD2, _offset_aiA1, _offset_aiA2, _offset_aiB1, _offset_aiB2, _offset_aiC1, _offset_aiC2, _offset_aiD1, _offset_aiD2, _msA, _msB, _msC, _msD, _acA1, _acB1, _acC1, _acD1
	extern malloc, free
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
_main_factorial@o2:
	push ebp
	mov ebp, esp
	sub esp, 4*2
		push 28
		call malloc
		add esp, 4
		push eax
		mov dword [eax], _msC
lea eax, [ebp-4*2]
push dword eax
		pop eax
		pop ebx
		mov [eax], ebx

	; Guarda el operando 9999 en la pila
	push dword 9999
lea eax, [ebp-4*2]
push dword eax
		pop eax
		mov dword ebx, [_offset_aiC2]
		lea eax, [eax+ebx]
		push eax
		pop eax
		pop ebx
		mov [eax], ebx
lea eax, [ebp-4*2]
push dword eax
		pop eax
		mov dword ebx, [_offset_aiC2]
		lea eax, [eax+ebx]
		push eax

; Escritura
pop eax
push dword [eax]
call print_int
call print_endofline
add esp, 4


	; Guarda el operando 111111 en la pila
	push dword 111111
lea eax, [ebp-4*2]
push dword eax
		pop eax
		mov dword ebx, [_offset_aiC2]
		lea eax, [eax+ebx]
		push eax
		pop eax
		pop ebx
		mov [eax], ebx
lea eax, [ebp-4*2]
push dword eax
		pop eax
		mov dword ebx, [_offset_aiC2]
		lea eax, [eax+ebx]
		push eax

; Escritura
pop eax
push dword [eax]
call print_int
call print_endofline
add esp, 4


	; Guarda el operando 100 en la pila
	push dword 100
lea eax, [ebp-4*1]
push dword eax
		pop eax
		pop ebx
		mov [eax], ebx
lea eax, [ebp-4*1]
push dword eax

; Escritura
pop eax
push dword [eax]
call print_int
call print_endofline
add esp, 4


	; Guarda el operando 333 en la pila
	push dword 333
lea eax, [ebp+4+4*1]
push dword eax
		pop eax
		mov dword ebx, [_offset_aiC2]
		lea eax, [eax+ebx]
		push eax
		pop eax
		pop ebx
		mov [eax], ebx
lea eax, [ebp+4+4*1]
push dword eax
		pop eax
		mov dword ebx, [_offset_aiC2]
		lea eax, [eax+ebx]
		push eax

; Escritura
pop eax
push dword [eax]
call print_int
call print_endofline
add esp, 4

lea eax, [ebp-4*2]
push dword eax
pop dword eax
mov eax, [eax]
mov dword esp, ebp
pop dword ebp
ret

; PROCEDIMIENTO PRINCIPAL
main:
mov dword [__esp], esp
	call _create_ms_table
		push 28
		call malloc
		add esp, 4
		push eax
		mov dword [eax], _msC

	; Guarda el operando c1 en la pila
	push dword _c1
		pop eax
		pop ebx
		mov [eax], ebx

	; Guarda el operando 99 en la pila
	push dword 99

	; Guarda el operando c1 en la pila
	push dword _c1
		pop eax
		mov dword ebx, [_offset_aiC2]
		lea eax, [eax+ebx]
		push eax
		pop eax
		pop ebx
		mov [eax], ebx

	; Guarda el operando c1 en la pila
	push dword _c1
		pop eax
		mov dword ebx, [_offset_aiC2]
		lea eax, [eax+ebx]
		push eax

; Escritura
pop eax
push dword [eax]
call print_int
call print_endofline
add esp, 4


	; Guarda el operando c1 en la pila
	push dword _c1
		pop eax
		mov eax, [eax]
		mov eax, [eax]
		mov dword ebx, [_offset_msA1]
		lea eax, [eax+ebx]
		mov eax, [eax]
		call eax

	; Guarda el operando c1 en la pila
	push dword _c1
pop dword eax
mov eax, [eax]
push dword eax
call _main_factorial@o2
add esp, 4*1
push dword eax

	; Asignacion de a pila a c2
	pop dword eax
	mov dword [_c2], eax

	; Guarda el operando c1 en la pila
	push dword _c1
		pop eax
		push dword [eax]
		call free
		add esp, 4

	; Guarda el operando c2 en la pila
	push dword _c2
		pop eax
		mov dword ebx, [_offset_aiC2]
		lea eax, [eax+ebx]
		push eax

; Escritura
pop eax
push dword [eax]
call print_int
call print_endofline
add esp, 4

		push 36
		call malloc
		add esp, 4
		push eax
		mov dword [eax], _msD

	; Guarda el operando d1 en la pila
	push dword _d1
		pop eax
		pop ebx
		mov [eax], ebx
		push 28
		call malloc
		add esp, 4
		push eax
		mov dword [eax], _msC

	; Guarda el operando d1 en la pila
	push dword _d1
		pop eax
		mov dword ebx, [_offset_aiD2]
		lea eax, [eax+ebx]
		push eax
		pop eax
		pop ebx
		mov [eax], ebx

	; Guarda el operando d1 en la pila
	push dword _d1
		pop eax
		mov dword ebx, [_offset_aiD2]
		lea eax, [eax+ebx]
		push eax

	; Guarda el operando c1 en la pila
	push dword _c1
		pop eax
		pop ebx
		mov ebx, [ebx]
		mov [eax], ebx

	; Guarda el operando 99 en la pila
	push dword 99

	; Guarda el operando c1 en la pila
	push dword _c1
		pop eax
		mov dword ebx, [_offset_aiC2]
		lea eax, [eax+ebx]
		push eax
		pop eax
		pop ebx
		mov [eax], ebx

	; Guarda el operando 20 en la pila
	push dword 20

	; Guarda el operando m en la pila
	push dword _m
		pop eax
		pop ebx
		mov [eax], ebx

	; Guarda el operando m en la pila
	push dword _m

	; Guarda el operando 0 en la pila
	push dword 0

	; Comparacion de mayor
	pop dword ebx
	pop dword eax
	mov eax, dword [eax]
	cmp eax, ebx
	jg __mayor_1
	push dword 0
	jmp __fin_mayor_1
	__mayor_1:
		push dword 1
	__fin_mayor_1:
; Comprobamos la condicion: if (1) para ver que es algo asimilable a una variable
pop eax
cmp eax, 0
; En caso de que no se cumpla la condicion nos vamos al else
je __else_1
;Nos metemos en el caso del then (1) ya que se cumple la condicion

	; Guarda el operando 0 en la pila
	push dword 0

; Escritura
call print_int
call print_endofline
add esp, 4


	; Guarda el operando m en la pila
	push dword _m

	; Guarda el operando 2 en la pila
	push dword 2

	; Comparacion de mayor
	pop dword ebx
	pop dword eax
	mov eax, dword [eax]
	cmp eax, ebx
	jg __mayor_2
	push dword 0
	jmp __fin_mayor_2
	__mayor_2:
		push dword 1
	__fin_mayor_2:

	; Guarda el operando 22 en la pila
	push dword 22

; Escritura
call print_int
call print_endofline
add esp, 4

; Estamos en la parte del final del else (2) del ifthen_else
__endifthen_else_2:
inicio_while3:

	; Guarda el operando m en la pila
	push dword _m

	; Guarda el operando 0 en la pila
	push dword 0

	; Comparacion de mayor o igual
	pop dword ebx
	pop dword eax
	mov eax, dword [eax]
	cmp eax, ebx
	jge __mayor_o_igual_3
	push dword 0
	jmp __fin_mayor_o_igual_3
	__mayor_o_igual_3:
		push dword 1
	__fin_mayor_o_igual_3:
pop eax
cmp eax, 0
je near fin_while3

	; Guarda el operando m en la pila
	push dword _m

; Escritura
pop eax
push dword [eax]
call print_int
call print_endofline
add esp, 4


	; Guarda el operando m en la pila
	push dword _m

	; Guarda el operando 1 en la pila
	push dword 1

	; Resta
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	sub eax, ebx
	push dword eax

	; Guarda el operando m en la pila
	push dword _m
		pop eax
		pop ebx
		mov [eax], ebx
jmp near inicio_while3
fin_while3:
; Estamos en la parte del final del then (1) del ifthen_else
jmp __endifthen_else_1
__else_1:

	; Guarda el operando 1 en la pila
	push dword 1

; Escritura
call print_int
call print_endofline
add esp, 4


	; Guarda el operando m en la pila
	push dword _m

	; Guarda el operando -11 en la pila
	push dword -11

	; Comparacion de menor
	pop dword ebx
	pop dword eax
	mov eax, dword [eax]
	cmp eax, ebx
	jl __menor_4
	push dword 0
	jmp __fin_menor_4
	__menor_4:
		push dword 1
	__fin_menor_4:

	; Guarda el operando -11 en la pila
	push dword -11

; Escritura
call print_int
call print_endofline
add esp, 4

; Estamos en la parte del final del else (4) del ifthen_else
__endifthen_else_4:
; Estamos en la parte del final del else (1) del ifthen_else
__endifthen_else_1:

	; Guarda el operando 0 en la pila
	push dword 0

	; Guarda el operando m en la pila
	push dword _m
		pop eax
		pop ebx
		mov [eax], ebx
inicio_while5:

	; Guarda el operando m en la pila
	push dword _m

	; Guarda el operando 3 en la pila
	push dword 3

	; Comparacion de menor o igual
	pop dword ebx
	pop dword eax
	mov eax, dword [eax]
	cmp eax, ebx
	jle __menor_o_igual_5
	push dword 0
	jmp __fin_menor_o_igual_5
	__menor_o_igual_5:
		push dword 1
	__fin_menor_o_igual_5:
pop eax
cmp eax, 0
je near fin_while5

	; Guarda el operando m en la pila
	push dword _m

	; Guarda el operando 10 en la pila
	push dword 10

	; Multiplicacion
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	imul dword ebx
	push dword eax

	; Guarda el operando m en la pila
	push dword _m
; carga el valor del indice en eax
pop dword eax 
mov dword eax , [eax]
; Si el indice es menor que 0, error en tiempo de ejecucion
cmp eax,0
jl near mensaje_1
; Si el indice es mayor de lo permitido, error en tiempo de ejecucion
cmp eax, 3
jg near mensaje_1
mov dword edx, _vector_int
lea eax, [edx + eax * 4]
push dword eax
		pop eax
		pop ebx
		mov [eax], ebx

	; Guarda el operando m en la pila
	push dword _m
; carga el valor del indice en eax
pop dword eax 
mov dword eax , [eax]
; Si el indice es menor que 0, error en tiempo de ejecucion
cmp eax,0
jl near mensaje_1
; Si el indice es mayor de lo permitido, error en tiempo de ejecucion
cmp eax, 3
jg near mensaje_1
mov dword edx, _vector_int
lea eax, [edx + eax * 4]
push dword eax

; Escritura
pop eax
push dword [eax]
call print_int
call print_endofline
add esp, 4


	; Guarda el operando m en la pila
	push dword _m

	; Guarda el operando 1 en la pila
	push dword 1

	; Suma
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	add eax, ebx
	push dword eax

	; Guarda el operando m en la pila
	push dword _m
		pop eax
		pop ebx
		mov [eax], ebx
jmp near inicio_while5
fin_while5:

	; Guarda el operando 2 en la pila
	push dword 2
; carga el valor del indice en eax
pop dword eax 
; Si el indice es menor que 0, error en tiempo de ejecucion
cmp eax,0
jl near mensaje_1
; Si el indice es mayor de lo permitido, error en tiempo de ejecucion
cmp eax, 3
jg near mensaje_1
mov dword edx, _vector_int
lea eax, [edx + eax * 4]
push dword eax

	; Guarda el operando m en la pila
	push dword _m
		pop eax
		pop ebx
		mov ebx, [ebx]
		mov [eax], ebx

	; Guarda el operando m en la pila
	push dword _m

; Escritura
pop eax
push dword [eax]
call print_int
call print_endofline
add esp, 4


	; Guarda el operando 999999999 en la pila
	push dword 999999999

; Escritura
call print_int
call print_endofline
add esp, 4

		push 20
		call malloc
		add esp, 4
		push eax
		mov dword [eax], _msB

	; Guarda el operando 0 en la pila
	push dword 0
; carga el valor del indice en eax
pop dword eax 
; Si el indice es menor que 0, error en tiempo de ejecucion
cmp eax,0
jl near mensaje_1
; Si el indice es mayor de lo permitido, error en tiempo de ejecucion
cmp eax, 2
jg near mensaje_1
mov dword edx, _Vobjs
lea eax, [edx + eax * 4]
push dword eax
		pop eax
		pop ebx
		mov [eax], ebx
		push 28
		call malloc
		add esp, 4
		push eax
		mov dword [eax], _msC

	; Guarda el operando 1 en la pila
	push dword 1
; carga el valor del indice en eax
pop dword eax 
; Si el indice es menor que 0, error en tiempo de ejecucion
cmp eax,0
jl near mensaje_1
; Si el indice es mayor de lo permitido, error en tiempo de ejecucion
cmp eax, 2
jg near mensaje_1
mov dword edx, _Vobjs
lea eax, [edx + eax * 4]
push dword eax
		pop eax
		pop ebx
		mov [eax], ebx
		push 36
		call malloc
		add esp, 4
		push eax
		mov dword [eax], _msD

	; Guarda el operando 2 en la pila
	push dword 2
; carga el valor del indice en eax
pop dword eax 
; Si el indice es menor que 0, error en tiempo de ejecucion
cmp eax,0
jl near mensaje_1
; Si el indice es mayor de lo permitido, error en tiempo de ejecucion
cmp eax, 2
jg near mensaje_1
mov dword edx, _Vobjs
lea eax, [edx + eax * 4]
push dword eax
		pop eax
		pop ebx
		mov [eax], ebx

	; Guarda el operando 0 en la pila
	push dword 0

	; Guarda el operando m en la pila
	push dword _m
		pop eax
		pop ebx
		mov [eax], ebx
inicio_while6:

	; Guarda el operando m en la pila
	push dword _m

	; Guarda el operando 2 en la pila
	push dword 2

	; Comparacion de menor o igual
	pop dword ebx
	pop dword eax
	mov eax, dword [eax]
	cmp eax, ebx
	jle __menor_o_igual_6
	push dword 0
	jmp __fin_menor_o_igual_6
	__menor_o_igual_6:
		push dword 1
	__fin_menor_o_igual_6:
pop eax
cmp eax, 0
je near fin_while6

	; Guarda el operando m en la pila
	push dword _m

; Escritura
pop eax
push dword [eax]
call print_int
call print_endofline
add esp, 4


	; Guarda el operando m en la pila
	push dword _m
; carga el valor del indice en eax
pop dword eax 
mov dword eax , [eax]
; Si el indice es menor que 0, error en tiempo de ejecucion
cmp eax,0
jl near mensaje_1
; Si el indice es mayor de lo permitido, error en tiempo de ejecucion
cmp eax, 2
jg near mensaje_1
mov dword edx, _Vobjs
lea eax, [edx + eax * 4]
push dword eax
		pop eax
		mov eax, [eax]
		mov eax, [eax]
		mov dword ebx, [_offset_msA1]
		lea eax, [eax+ebx]
		mov eax, [eax]
		call eax

	; Guarda el operando m en la pila
	push dword _m
; carga el valor del indice en eax
pop dword eax 
mov dword eax , [eax]
; Si el indice es menor que 0, error en tiempo de ejecucion
cmp eax,0
jl near mensaje_1
; Si el indice es mayor de lo permitido, error en tiempo de ejecucion
cmp eax, 2
jg near mensaje_1
mov dword edx, _Vobjs
lea eax, [edx + eax * 4]
push dword eax
		pop eax
		mov eax, [eax]
		mov eax, [eax]
		mov dword ebx, [_offset_msA2]
		lea eax, [eax+ebx]
		mov eax, [eax]
		call eax
push dword mensaje_prueba
call print_string
call print_endofline
add esp,4		

	; Guarda el operando m en la pila
	push dword _m

	; Guarda el operando 1 en la pila
	push dword 1

	; Suma
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	add eax, ebx
	push dword eax

	; Guarda el operando m en la pila
	push dword _m
		pop eax
		pop ebx
		mov [eax], ebx
jmp near inicio_while6
fin_while6:

	; Guarda el operando 0 en la pila
	push dword 0

	; Guarda el operando m en la pila
	push dword _m
		pop eax
		pop ebx
		mov [eax], ebx
inicio_while7:

	; Guarda el operando m en la pila
	push dword _m

	; Guarda el operando 2 en la pila
	push dword 2

	; Comparacion de menor o igual
	pop dword ebx
	pop dword eax
	mov eax, dword [eax]
	cmp eax, ebx
	jle __menor_o_igual_7
	push dword 0
	jmp __fin_menor_o_igual_7
	__menor_o_igual_7:
		push dword 1
	__fin_menor_o_igual_7:
pop eax
cmp eax, 0
je near fin_while7

	; Guarda el operando m en la pila
	push dword _m

; Escritura
pop eax
push dword [eax]
call print_int
call print_endofline
add esp, 4


	; Guarda el operando m en la pila
	push dword _m
; carga el valor del indice en eax
pop dword eax 
mov dword eax , [eax]
; Si el indice es menor que 0, error en tiempo de ejecucion
cmp eax,0
jl near mensaje_1
; Si el indice es mayor de lo permitido, error en tiempo de ejecucion
cmp eax, 2
jg near mensaje_1
mov dword edx, _Vobjs
lea eax, [edx + eax * 4]
push dword eax
		pop eax
		push dword [eax]
		call free
		add esp, 4

	; Guarda el operando m en la pila
	push dword _m

	; Guarda el operando 1 en la pila
	push dword 1

	; Suma
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	add eax, ebx
	push dword eax

	; Guarda el operando m en la pila
	push dword _m
		pop eax
		pop ebx
		mov [eax], ebx
jmp near inicio_while7
fin_while7:

	; Guarda el operando c2 en la pila
	push dword _c2
		pop eax
		mov dword ebx, [_offset_aiC2]
		lea eax, [eax+ebx]
		push eax

; Escritura
pop eax
push dword [eax]
call print_int
call print_endofline
add esp, 4


	; Guarda el operando c2 en la pila
	push dword _c2

	; Guarda el operando 2 en la pila
	push dword 2
; carga el valor del indice en eax
pop dword eax 
; Si el indice es menor que 0, error en tiempo de ejecucion
cmp eax,0
jl near mensaje_1
; Si el indice es mayor de lo permitido, error en tiempo de ejecucion
cmp eax, 2
jg near mensaje_1
mov dword edx, _Vobjs
lea eax, [edx + eax * 4]
push dword eax
		pop eax
		pop ebx
		mov ebx, [ebx]
		mov [eax], ebx
		push 28
		call malloc
		add esp, 4
		push eax
		mov dword [eax], _msC

	; Guarda el operando c3 en la pila
	push dword _c3
		pop eax
		pop ebx
		mov [eax], ebx

	; Guarda el operando 2 en la pila
	push dword 2
; carga el valor del indice en eax
pop dword eax 
; Si el indice es menor que 0, error en tiempo de ejecucion
cmp eax,0
jl near mensaje_1
; Si el indice es mayor de lo permitido, error en tiempo de ejecucion
cmp eax, 2
jg near mensaje_1
mov dword edx, _Vobjs
lea eax, [edx + eax * 4]
push dword eax
		pop eax
		mov dword ebx, [_offset_aiC2]
		lea eax, [eax+ebx]
		push eax

	; Guarda el operando c3 en la pila
	push dword _c3
		pop eax
		mov dword ebx, [_offset_aiC2]
		lea eax, [eax+ebx]
		push eax
		pop eax
		pop ebx
		mov ebx, [ebx]
		mov [eax], ebx

	; Guarda el operando c3 en la pila
	push dword _c3
		pop eax
		mov dword ebx, [_offset_aiC2]
		lea eax, [eax+ebx]
		push eax

; Escritura
pop eax
push dword [eax]
call print_int
call print_endofline
add esp, 4


	; Guarda el operando c3 en la pila
	push dword _c3
		pop eax
		push dword [eax]
		call free
		add esp, 4

	; Guarda el operando c2 en la pila
	push dword _c2
		pop eax
		push dword [eax]
		call free
		add esp, 4

	; Guarda el operando d1 en la pila
	push dword _d1
		pop eax
		mov dword ebx, [_offset_aiD2]
		lea eax, [eax+ebx]
		push eax
		pop eax
		push dword [eax]
		call free
		add esp, 4

	; Guarda el operando d1 en la pila
	push dword _d1
		pop eax
		push dword [eax]
		call free
		add esp, 4

	;FINAL DEL PROGRAMA
	jmp near _fin
	__error_division:
		push mensaje_1
		jmp near __salida_mensaje_error
	__salida_mensaje_error:
		call print_string
		call print_endofline
	_fin:
		mov dword esp, [__esp]
	ret
