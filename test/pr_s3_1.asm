segment .data
mensaje_1 db "Indice fuera de rango", 0
mensaje_2 db "Division por cero", 0

segment .bss
__esp resd 1
_x2 resd 1
_y1 resd 1
_x1 resd 1

segment .text
global main
extern print_int, print_boolean, print_string, print_blank, print_endofline, scan_int, scan_boolean

; PROCEDIMIENTO PRINCIPAL
main:
mov dword [__esp], esp

	; Lectura
	push dword _x1
	call scan_int
	add esp, 4

	; Lectura
	push dword _x2
	call scan_int
	add esp, 4
push dword _x1
push dword _x2

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

push dword _x1
push dword _x2

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
; Cargamos en el registro eax la parte derecha de la asignacion
pop dword eax
; Efectuamos la asignacion
mov dword [_y1], eax
push dword _y1

; Escritura
pop eax
push dword [eax]
call print_boolean
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
