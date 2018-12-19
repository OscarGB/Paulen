	global _mc1, _mb1, _ma1, _no_defined_method, _mnsb1, _set_offsets, _create_ms_table, _offset_ma1, _offset_mb1, _offset_mc1, _offset_bib1, _offset_aia1, _offset_aia2, _CC, _BB, _AA, _bbb1, _bbb2, _bbb3, _a1, _sa1, 

segment .data
		msg_error_indice_vector     db "Indice de vector fuera de rango", 0
		msg_asignacion     db "Asignacion", 0
		__auxfloat dd 0.0
		__auxint dd 0.0

;METODOS SOBREESCRIBIBLES OFFSET
		_offset_ma1, dd 0
		_offset_mb1, dd 4
		_offset_mc1, dd 8

;ATRIBUTOS INSTANCIA OFFSET
		_offset_bib1 dd 4
		_offset_aia1 dd 8
		_offset_aia2 dd 12


segment .bss
		__esp resd 3
;CLASS CC
		_CC resd 3
;CLASS BB
		_BB resd 2
;CLASS AA
		_AA resd 1


;;;;;FALTA SACAR LAS CLASES INSTANCIADAS;;;;;;


;ATRIBUTOS DE CLASE

		_offset_bbb1 resd 1 
		_offset_bbb2 resd 1 
		_offset_bbb3 resd 1 
		_offset_a1 resd 1 
		_offset_sa1 resd 1 


segment .text
		;global main


		extern malloc, free
		extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
		extern print_endofline, print_blank, print_string
		extern alfa_malloc, alfa_free, ld_float

_create_ms_table:
		mov dword [_CC], _no_defined_method
		mov dword [_CC+4], _no_defined_method
		mov dword [_CC+8], _no_defined_method
		mov dword [_BB], _no_defined_method
		mov dword [_BB+4], _no_defined_method
		mov dword [_AA], _no_defined_method
