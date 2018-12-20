segment .data
mensaje_1 db "Indice fuera de rango", 0
mensaje_2 db "Division por cero", 0

segment .bss
__esp resd 1
_main_z resd 1

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
