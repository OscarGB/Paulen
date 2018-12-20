segment .data
mensaje_1 db "Indice fuera de rango", 0
mensaje_2 db "Division por cero", 0

segment .bss
__esp resd 1
_main_x2 resd 1
_main_y1 resd 1
_main_x1 resd 1

segment .text
global main
extern print_int, print_boolean, print_string, print_blank, print_endofline, scan_int, scan_boolean

; PROCEDIMIENTO PRINCIPAL
main:
mov dword [__esp], esp

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
push dword _main_x1
push dword _main_x2

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
pop eax
cmp eax, 0
je near fin_then1
push dword _main_y1
pop eax
mov eax, [eax]
cmp eax, 0
je near fin_then2
	push dword 110

	; Escritura
	call print_int
	call print_endofline
	add esp, 4

jmp near fin_ifelse2
fin_then2:
	push dword 111

	; Escritura
	call print_int
	call print_endofline
	add esp, 4

fin_ifelse2:
jmp near fin_ifelse1
fin_then1:
push dword _main_y1
pop eax
mov eax, [eax]
cmp eax, 0
je near fin_then3
	push dword 10

	; Escritura
	call print_int
	call print_endofline
	add esp, 4

jmp near fin_ifelse3
fin_then3:
	push dword 11

	; Escritura
	call print_int
	call print_endofline
	add esp, 4

fin_ifelse3:
fin_ifelse1:
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
