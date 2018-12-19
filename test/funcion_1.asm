segment .data
mensaje_1 db "Indice fuera de rango", 0
mensaje_2 db "Division por cero", 0

segment .bss
__esp resd 1
_main_z resd 1

segment .text
global main
extern print_int, print_boolean, print_string, print_blank, print_endofline, scan_int, scan_boolean
_doble@1:
	push ebp
	mov ebp, esp
	sub esp, 4*1
lea eax, [ebp-4*0]
push dword eax
pop dword eax
mov dword eax, [eax]
mov dword [ebp-4*0], eax
	push dword 2
lea eax, [ebp-4*0]
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
