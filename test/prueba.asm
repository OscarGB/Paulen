segment .data
mensaje_1 db "Indice fuera de rango", 0
mensaje_2 db "Division por cero", 0

segment .bss
__esp resd 1
_x2 resd 1
_y2 resd 1
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
	push dword 3
push dword _x1
