	global _CC_mc1@1@3, _BB_mb1@1@3, _AA_ma1@1@3, _no_defined_method, _BB_mnsb1@1@3, _set_offsets, _create_ms_table, _offset_ma1@1@3, _offset_mb1@1@3, _offset_mc1@1@3, _offset_BB_bib1, _offset_AA_aia1, _offset_AA_aia2, _CC, _BB, _AA, _BB_bbb1, _BB_bbb2, _BB_bbb3, _AA_sa1, _AA_a1, 

segment .data
		msg_error_indice_vector     db "Indice de vector fuera de rango", 0
		msg_asignacion     db "Asignacion", 0
		__auxfloat dd 0.0
		__auxint dd 0.0

;METODOS SOBREESCRIBIBLES OFFSET
		_offset_ma1@1@3, dd 0
		_offset_mb1@1@3, dd 4
		_offset_mc1@1@3, dd 8

;ATRIBUTOS INSTANCIA OFFSET
		_offset_BB_bib1 dd 4
		_offset_AA_aia1 dd 8
		_offset_AA_aia2 dd 12


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

		_offset_BB_bbb1 resd 1 
		_offset_BB_bbb2 resd 1 
		_offset_BB_bbb3 resd 1 
		_offset_AA_sa1 resd 1 
		_offset_AA_a1 resd 1 


segment .text
		;global main


_create_ms_table:
		mov dword [_CC], _AA_ma1@1@3
		mov dword [_CC+4], _no_defined_method
		mov dword [_CC+8], _CC_mc1@1@3
		mov dword [_BB], _no_defined_method
		mov dword [_BB+4], _BB_mb1@1@3
		mov dword [_AA], _AA_ma1@1@3
