segment .data
mensaje_1 db "Indice fuera de rango", 0
mensaje_2 db "Division por cero", 0

segment .bss
__esp resd 1
_main_y resd 1
_main_x resd 1

segment .text
global main
extern print_int, print_boolean, print_string, print_blank, print_endofline, scan_int, scan_boolean
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
		; En caso de que no se cumpla la condicion nos vamos al else
		je __else_1
		;Nos metemos en el caso del then (1) ya que se cumple la condicion
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
		; En caso de que no se cumpla la condicion nos vamos al else
		je __else_3
		;Nos metemos en el caso del then (3) ya que se cumple la condicion
		push dword 1
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
		; Estamos en la parte del final del then (3) del ifthen_else
		jmp __endifthen_else_3
		__else_3:
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
		; En caso de que no se cumpla la condicion nos vamos al else
		je __else_5
		;Nos metemos en el caso del then (5) ya que se cumple la condicion
		push dword 0
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
		; Estamos en la parte del final del then (5) del ifthen_else
		jmp __endifthen_else_5
		__else_5:
		push dword 2
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
		; Estamos en la parte del final del else (5) del ifthen_else
		__endifthen_else_5:
		; Estamos en la parte del final del else (3) del ifthen_else
		__endifthen_else_3:
		; Estamos en la parte del final del then (1) del ifthen_else
		jmp __endifthen_else_1
		__else_1:
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
		; En caso de que no se cumpla la condicion nos vamos al else
		je __else_7
		;Nos metemos en el caso del then (7) ya que se cumple la condicion
		push dword 0
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
		; Estamos en la parte del final del then (7) del ifthen_else
		jmp __endifthen_else_7
		__else_7:
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
		; En caso de que no se cumpla la condicion nos vamos al else
		je __else_9
		;Nos metemos en el caso del then (9) ya que se cumple la condicion
		push dword 4
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
		; Estamos en la parte del final del then (9) del ifthen_else
		jmp __endifthen_else_9
		__else_9:
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
		; En caso de que no se cumpla la condicion nos vamos al else
		je __else_11
		;Nos metemos en el caso del then (11) ya que se cumple la condicion
		push dword 0
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
		; Estamos en la parte del final del then (11) del ifthen_else
		jmp __endifthen_else_11
		__else_11:
		push dword 3
		pop dword eax
		mov dword esp, ebp
		pop dword ebp
		ret
		; Estamos en la parte del final del else (11) del ifthen_else
		__endifthen_else_11:
		; Estamos en la parte del final del else (9) del ifthen_else
		__endifthen_else_9:
		; Estamos en la parte del final del else (7) del ifthen_else
		__endifthen_else_7:
		; Estamos en la parte del final del else (1) del ifthen_else
		__endifthen_else_1:

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
push dword [_main_x]
push dword [_main_y]
		call _main_ubica@1@1
		add esp, 4*2
		push dword eax

		; Escritura
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
