segment .data
mensaje_1 db "Indice fuera de rango", 0
mensaje_2 db "Division por cero", 0

segment .bss
__esp resd 1
_main_z resd 1

segment .text
global main
extern print_int, print_boolean, print_string, print_blank, print_endofline, scan_int, scan_boolean
