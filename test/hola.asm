segment .data
mensaje_1 db "Indice fuera de rango", 0
mensaje_2 db "Division por cero", 0

segment .bss
__esp resd 1
_main_i resd 1
_main_a resd 1
_main_res resd 1
_main_b resd 1
_main_c resd 1
_main_A1 resd 8
_main_A2 resd 8
_main_x resd 1
_main_y resd 1
_main_z resd 1
_main_resultado resd 1

segment .text
global main
extern print_int, print_boolean, print_string, print_blank, print_endofline, scan_int, scan_boolean
extern malloc, free
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
_main_ubica@1@1:
		push ebp
		mov ebp, esp
		sub esp, 4*0
		lea eax, [ebp+4+4*2]
		push dword eax
		push dword 0

		; Comparacion de mayor
		pop dword ebx
		pop dword eax
		mov eax, dword [eax]
		cmp eax, ebx
		jg __mayor_0
		push dword 0
		jmp __fin_mayor_0
		__mayor_0:
		push dword 1
		__fin_mayor_0:
		; Comprobamos la condicion: if (1) para ver que es algo asimilable a una variable
		pop eax
		cmp eax, 0
		; En caso de que no se cumpla la condicion nos vamos al final del ifthen
		je __end_if_1
		; En caso de que se cumpla nos metemos en el caso del then (1) ya que se cumple la condicion
		lea eax, [ebp+4+4*1]
		push dword eax
		push dword 0

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
		; Estamos en la parte del final del then (3) del ifthen_else
		jmp __end_ifthen_3
		__end_if_3:
		lea eax, [ebp+4+4*1]
		push dword eax
		push dword 0

		; Comparacion de igualdad
		pop dword eax
		pop dword ebx
		cmp eax, [ebx]
		je __igual_4
		push dword 0
		jmp __fin_igual_4
		__igual_4:
		push dword 1
		__fin_igual_4:
		; Comprobamos la condicion: if (5) para ver que es algo asimilable a una variable
		pop eax
		cmp eax, 0
		; En caso de que no se cumpla la condicion nos vamos al final del ifthen
		je __end_if_5
		; En caso de que se cumpla nos metemos en el caso del then (5) ya que se cumple la condicion
		push dword 0
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
		; Estamos en la parte del final del then (5) del ifthen_else
		jmp __end_ifthen_5
		__end_if_5:
		push dword 2
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
		; Estamos en la parte del final del else (5) del ifthen_else
		__end_ifthen_5:
		; Estamos en la parte del final del else (3) del ifthen_else
		__end_ifthen_3:
		; Estamos en la parte del final del then (1) del ifthen_else
		jmp __end_ifthen_1
		__end_if_1:
		lea eax, [ebp+4+4*2]
		push dword eax
		push dword 0

		; Comparacion de igualdad
		pop dword eax
		pop dword ebx
		cmp eax, [ebx]
		je __igual_6
		push dword 0
		jmp __fin_igual_6
		__igual_6:
		push dword 1
		__fin_igual_6:
		; Comprobamos la condicion: if (7) para ver que es algo asimilable a una variable
		pop eax
		cmp eax, 0
		; En caso de que no se cumpla la condicion nos vamos al final del ifthen
		je __end_if_7
		; En caso de que se cumpla nos metemos en el caso del then (7) ya que se cumple la condicion
		push dword 0
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
		; Estamos en la parte del final del then (7) del ifthen_else
		jmp __end_ifthen_7
		__end_if_7:
		lea eax, [ebp+4+4*1]
		push dword eax
		push dword 0

		; Comparacion de mayor
		pop dword ebx
		pop dword eax
		mov eax, dword [eax]
		cmp eax, ebx
		jg __mayor_8
		push dword 0
		jmp __fin_mayor_8
		__mayor_8:
		push dword 1
		__fin_mayor_8:
		; Comprobamos la condicion: if (9) para ver que es algo asimilable a una variable
		pop eax
		cmp eax, 0
		; En caso de que no se cumpla la condicion nos vamos al final del ifthen
		je __end_if_9
		; En caso de que se cumpla nos metemos en el caso del then (9) ya que se cumple la condicion
		push dword 4
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
		; Estamos en la parte del final del then (9) del ifthen_else
		jmp __end_ifthen_9
		__end_if_9:
		lea eax, [ebp+4+4*1]
		push dword eax
		push dword 0

		; Comparacion de igualdad
		pop dword eax
		pop dword ebx
		cmp eax, [ebx]
		je __igual_10
		push dword 0
		jmp __fin_igual_10
		__igual_10:
		push dword 1
		__fin_igual_10:
		; Comprobamos la condicion: if (11) para ver que es algo asimilable a una variable
		pop eax
		cmp eax, 0
		; En caso de que no se cumpla la condicion nos vamos al final del ifthen
		je __end_if_11
		; En caso de que se cumpla nos metemos en el caso del then (11) ya que se cumple la condicion
		push dword 0
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
		; Estamos en la parte del final del then (11) del ifthen_else
		jmp __end_ifthen_11
		__end_if_11:
		push dword 3
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
		; Estamos en la parte del final del else (11) del ifthen_else
		__end_ifthen_11:
		; Estamos en la parte del final del else (9) del ifthen_else
		__end_ifthen_9:
		; Estamos en la parte del final del else (7) del ifthen_else
		__end_ifthen_7:
		; Estamos en la parte del final del else (1) del ifthen_else
		__end_ifthen_1:
_main_cuadrado@1:
		push ebp
		mov ebp, esp
		sub esp, 4*0
		lea eax, [ebp+4+4*1]
		push dword eax
		lea eax, [ebp+4+4*1]
		push dword eax

		; Multiplicacion
		pop dword ebx
		pop dword eax
		mov eax, [eax]
		imul dword [ebx]
		push dword eax
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
_main_factorial@1:
		push ebp
		mov ebp, esp
		sub esp, 4*0
		lea eax, [ebp+4+4*1]
		push dword eax
		push dword 1

		; Comparacion de igualdad
		pop dword eax
		pop dword ebx
		cmp eax, [ebx]
		je __igual_12
		push dword 0
		jmp __fin_igual_12
		__igual_12:
		push dword 1
		__fin_igual_12:
		; Comprobamos la condicion: if (13) para ver que es algo asimilable a una variable
		pop eax
		cmp eax, 0
		; En caso de que no se cumpla la condicion nos vamos al final del ifthen
		je __end_if_13
		; En caso de que se cumpla nos metemos en el caso del then (13) ya que se cumple la condicion
		push dword 1
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
		; Estamos en la parte del final del then (13) del ifthen_else
		jmp __end_ifthen_13
		__end_if_13:
		lea eax, [ebp+4+4*1]
		push dword eax
		lea eax, [ebp+4+4*1]
		push dword eax
		push dword 1

		; Resta
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
		sub eax, ebx
		push dword eax
		call _main_factorial@1
		add esp, 4*1
		push dword eax

		; Multiplicacion
		pop dword ebx
		pop dword eax
		mov eax, [eax]
		imul dword ebx
		push dword eax
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
		; Estamos en la parte del final del else (13) del ifthen_else
		__end_ifthen_13:

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

		; Lectura
		push dword _main_z
		call scan_int
		add esp, 4
		push dword _main_x
		push dword _main_y

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

		push dword _main_x
		push dword _main_y

		; Resta
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
		sub eax, [ebx]
		push dword eax

		; Escritura
		call print_int
		call print_endofline
		add esp, 4

		push dword _main_x
		push dword _main_y

		; Multiplicacion
		pop dword ebx
		pop dword eax
		mov eax, [eax]
		imul dword [ebx]
		push dword eax

		; Escritura
		call print_int
		call print_endofline
		add esp, 4

		push dword _main_x
		push dword _main_y

		; Division
		pop dword ebx
		pop dword eax
		mov eax, dword [eax]
		mov ebx, dword [ebx]
		cmp ebx, 0
		je __error_division
		cdq
		idiv ebx
		push dword eax

		; Escritura
		call print_int
		call print_endofline
		add esp, 4

		push dword _main_x

		; Cambio de signo
		pop dword eax
		mov dword eax, [eax]
		neg dword eax
		push dword eax

		; Escritura
		call print_int
		call print_endofline
		add esp, 4

		push dword _main_x
		push dword _main_y
		push dword _main_z

		; Multiplicacion
		pop dword ebx
		pop dword eax
		mov eax, [eax]
		imul dword [ebx]
		push dword eax

		; Suma
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
		add eax, ebx
		push dword eax

		; Escritura
		call print_int
		call print_endofline
		add esp, 4

		push dword _main_x
		push dword _main_y

		; Suma
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
		mov dword ebx, [ebx]
		add eax, ebx
		push dword eax
		push dword _main_z

		; Multiplicacion
		pop dword ebx
		pop dword eax
		imul dword [ebx]
		push dword eax

		; Escritura
		call print_int
		call print_endofline
		add esp, 4

		push dword 1

		; Asignacion de pila a main_a
		pop dword eax
		mov dword [_main_a], eax
		push dword 0

		; Asignacion de pila a main_b
		pop dword eax
		mov dword [_main_b], eax
		push dword 0

		; Asignacion de pila a main_c
		pop dword eax
		mov dword [_main_c], eax
		push dword _main_a
		push dword _main_b

		; Conjuncion logica
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
		and eax, [ebx]
		push dword eax

		; Asignacion de pila a main_resultado
		pop dword eax
		mov dword [_main_resultado], eax
		push dword _main_resultado

		; Escritura
		pop eax
		push dword [eax]
		call print_boolean
		call print_endofline
		add esp, 4

		push dword _main_a
		push dword _main_b

		; Disyuncion logica
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
		or eax, [ebx]
		push dword eax

		; Asignacion de pila a main_resultado
		pop dword eax
		mov dword [_main_resultado], eax
		push dword _main_resultado

		; Escritura
		pop eax
		push dword [eax]
		call print_boolean
		call print_endofline
		add esp, 4

		push dword _main_a

		; Negacion logica
		pop eax
		cmp dword [eax], 0
		je __uno_14
		push dword 0
		jmp __fin_no_14
		__uno_14:
		push dword 1
		__fin_no_14:

		; Asignacion de pila a main_resultado
		pop dword eax
		mov dword [_main_resultado], eax
		push dword _main_resultado

		; Escritura
		pop eax
		push dword [eax]
		call print_boolean
		call print_endofline
		add esp, 4

		push dword _main_a
		push dword _main_b
		push dword _main_c

		; Conjuncion logica
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
		and eax, [ebx]
		push dword eax

		; Disyuncion logica
		pop dword eax
		pop dword ebx
		or eax, [ebx]
		push dword eax

		; Asignacion de pila a main_resultado
		pop dword eax
		mov dword [_main_resultado], eax
		push dword _main_resultado

		; Escritura
		pop eax
		push dword [eax]
		call print_boolean
		call print_endofline
		add esp, 4

		push dword _main_a
		push dword _main_b

		; Conjuncion logica
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
		and eax, [ebx]
		push dword eax
		push dword _main_c

		; Disyuncion logica
		pop dword ebx
		pop dword eax
		or eax, [ebx]
		push dword eax

		; Asignacion de pila a main_resultado
		pop dword eax
		mov dword [_main_resultado], eax
		push dword _main_resultado

		; Escritura
		pop eax
		push dword [eax]
		call print_boolean
		call print_endofline
		add esp, 4

		push dword _main_a

		; Negacion logica
		pop eax
		cmp dword [eax], 0
		je __uno_15
		push dword 0
		jmp __fin_no_15
		__uno_15:
		push dword 1
		__fin_no_15:
		push dword _main_b

		; Conjuncion logica
		pop dword ebx
		pop dword eax
		and eax, [ebx]
		push dword eax

		; Asignacion de pila a main_resultado
		pop dword eax
		mov dword [_main_resultado], eax
		push dword _main_resultado

		; Escritura
		pop eax
		push dword [eax]
		call print_boolean
		call print_endofline
		add esp, 4

		push dword _main_a
		push dword _main_b

		; Conjuncion logica
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
		and eax, [ebx]
		push dword eax

		; Negacion logica
		pop eax
		cmp dword eax, 0
		je __uno_16
		push dword 0
		jmp __fin_no_16
		__uno_16:
		push dword 1
		__fin_no_16:

		; Asignacion de pila a main_resultado
		pop dword eax
		mov dword [_main_resultado], eax
		push dword _main_resultado

		; Escritura
		pop eax
		push dword [eax]
		call print_boolean
		call print_endofline
		add esp, 4

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
		push dword 2

		; Multiplicacion
		pop dword ebx
		pop dword eax
		mov eax, [eax]
		imul dword ebx
		push dword eax

		; Suma
		pop dword ebx
		pop dword eax
		mov dword eax, [eax]
		add eax, ebx
		push dword eax

		; Escritura
		call print_int
		call print_endofline
		add esp, 4

		push dword 2

		; Cambio de signo
		pop dword eax
		neg dword eax
		push dword eax
		push dword 3
		call _main_ubica@1@1
		add esp, 4*2
		push dword eax

		; Asignacion de pila a main_z
		pop dword eax
		mov dword [_main_z], eax
		push dword _main_z
		push dword 4

		; Comparacion de igualdad
		pop dword eax
		pop dword ebx
		cmp eax, [ebx]
		je __igual_17
		push dword 0
		jmp __fin_igual_17
		__igual_17:
		push dword 1
		__fin_igual_17:
		; Comprobamos la condicion: if (18) para ver que es algo asimilable a una variable
		pop eax
		cmp eax, 0
		; En caso de que no se cumpla la condicion nos vamos al final del ifthen
		je __end_if_18
		; En caso de que se cumpla nos metemos en el caso del then (18) ya que se cumple la condicion
		push dword 1

		; Escritura
		call print_boolean
		call print_endofline
		add esp, 4

		; Estamos en la parte del final del then (18) del ifthen
		__end_if_18:
		push dword _main_z

		; Escritura
		pop eax
		push dword [eax]
		call print_int
		call print_endofline
		add esp, 4

		push dword [_main_z]
		call _main_cuadrado@1
		add esp, 4*1
		push dword eax

		; Asignacion de pila a main_x
		pop dword eax
		mov dword [_main_x], eax
		push dword _main_x

		; Escritura
		pop eax
		push dword [eax]
		call print_int
		call print_endofline
		add esp, 4

		push dword [_main_z]
		call _main_factorial@1
		add esp, 4*1
		push dword eax

		; Asignacion de pila a main_x
		pop dword eax
		mov dword [_main_x], eax
		push dword _main_x

		; Escritura
		pop eax
		push dword [eax]
		call print_int
		call print_endofline
		add esp, 4

		push dword 2
		call _main_factorial@1
		add esp, 4*1
		push dword eax

		; Asignacion de pila a main_x
		pop dword eax
		mov dword [_main_x], eax
		push dword _main_x

		; Escritura
		pop eax
		push dword [eax]
		call print_int
		call print_endofline
		add esp, 4

		push dword 0

		; Asignacion de pila a main_i
		pop dword eax
		mov dword [_main_i], eax
		inicio_while1:
		push dword _main_i
		push dword 8

		; Comparacion de menor
		pop dword ebx
		pop dword eax
		mov eax, dword [eax]
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
		push dword _main_i
		; carga el valor del indice en eax
		pop dword eax 
		mov dword eax , [eax]
		; Si el indice es menor que 0, error en tiempo de ejecucion
		cmp eax,0
		jl near __error_rango
		; Si el indice es mayor de lo permitido, error en tiempo de ejecucion
		cmp eax, 7
		jg near __error_rango
		mov dword edx, _main_A1
		lea eax, [edx + eax * 4]
		push dword eax
		push dword _main_i
		; Cargar en eax la parte derecha de la asignacion
		pop dword eax
		mov dword eax, [eax]
		; Cargar en edx la parte izquierda de la asignacion
		pop dword edx
		; Hacer la asignacion efectiva
		mov dword [edx], eax
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
		push dword 0

		; Asignacion de pila a main_i
		pop dword eax
		mov dword [_main_i], eax
		inicio_while2:
		push dword _main_i
		push dword 8

		; Comparacion de menor
		pop dword ebx
		pop dword eax
		mov eax, dword [eax]
		cmp eax, ebx
		jl __menor_2
		push dword 0
		jmp __fin_menor_2
		__menor_2:
		push dword 1
		__fin_menor_2:
		pop eax
		cmp eax, 0
		je near fin_while2
		push dword _main_i
		; carga el valor del indice en eax
		pop dword eax 
		mov dword eax , [eax]
		; Si el indice es menor que 0, error en tiempo de ejecucion
		cmp eax,0
		jl near __error_rango
		; Si el indice es mayor de lo permitido, error en tiempo de ejecucion
		cmp eax, 7
		jg near __error_rango
		mov dword edx, _main_A1
		lea eax, [edx + eax * 4]
		push dword eax

		; Escritura
		pop eax
		push dword [eax]
		call print_int
		call print_endofline
		add esp, 4

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
		jmp near inicio_while2
		fin_while2:
		push dword [_main_i]
		call _main_cuadrado@1
		add esp, 4*1
		push dword eax
		push dword 2

		; Multiplicacion
		pop dword ebx
		pop dword eax
		imul dword ebx
		push dword eax

		; Asignacion de pila a main_res
		pop dword eax
		mov dword [_main_res], eax
		push dword _main_res

		; Escritura
		pop eax
		push dword [eax]
		call print_int
		call print_endofline
		add esp, 4

		push dword 4

		; Asignacion de pila a main_x
		pop dword eax
		mov dword [_main_x], eax
		push dword _main_res
		push dword 4
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

		; Division
		pop dword ebx
		pop dword eax
		mov eax, dword [eax]
		mov ebx, dword [ebx]
		cmp ebx, 0
		je __error_division
		cdq
		idiv ebx
		push dword eax
		push dword 4
		push dword _main_x

		; Multiplicacion
		pop dword ebx
		pop dword eax
		imul dword [ebx]
		push dword eax

		; Division
		pop dword ebx
		pop dword eax
		cmp ebx, 0
		je __error_division
		cdq
		idiv ebx
		push dword eax
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

		; Asignacion de pila a main_x
		pop dword eax
		mov dword eax, [eax]
		mov dword [_main_x], eax
		push dword _main_x

		; Escritura
		pop eax
		push dword [eax]
		call print_int
		call print_endofline
		add esp, 4

		push dword 5

		; Asignacion de pila a main_A1
		pop dword eax
		mov dword [_main_A1], eax
		push dword 0
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

		; Escritura
		pop eax
		push dword [eax]
		call print_int
		call print_endofline
		add esp, 4

		push dword 0
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
