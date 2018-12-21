segment .data
mensaje_1 db "Indice fuera de rango", 0
mensaje_2 db "Division por cero", 0

segment .bss
__esp resd 1
_main_x2 resd 1
_main_x1 resd 1

segment .text
global main
extern print_int, print_boolean, print_string, print_blank, print_endofline, scan_int, scan_boolean
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
pop eax
cmp eax, 0
je near fin_then1
	push dword 1
pop dword eax
mov dword esp, ebp
pop dword ebp
ret
jmp near fin_ifelse1
fin_then1:
	push dword 0
pop dword eax
mov dword esp, ebp
pop dword ebp
ret
fin_ifelse1:

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
push dword [_main_x1]
push dword [_main_x2]
call _main_igual@1@1
add esp, 4*2
push dword eax

; Escritura
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
