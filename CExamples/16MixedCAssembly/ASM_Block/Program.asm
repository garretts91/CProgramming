; Listing generated by Microsoft (R) Optimizing Compiler Version 19.27.29111.0 

	TITLE	C:\Code\CSCI247\Code\C_Examples\11MixedCAssembly\ASM_Block\Program.c
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB LIBCMT
INCLUDELIB OLDNAMES

PUBLIC	___local_stdio_printf_options
PUBLIC	__vfprintf_l
PUBLIC	_printf
PUBLIC	_add
PUBLIC	_main
EXTRN	___acrt_iob_func:PROC
EXTRN	_getchar:PROC
EXTRN	___stdio_common_vfprintf:PROC
_DATA	SEGMENT
COMM	?_OptionsStorage@?1??__local_stdio_printf_options@@9@9:QWORD							; `__local_stdio_printf_options'::`2'::_OptionsStorage
_DATA	ENDS
_DATA	SEGMENT
$SG9189	DB	'The sum is %d', 0aH, 00H
_DATA	ENDS
; Function compile flags: /Odtp
_TEXT	SEGMENT
_x$ = -16						; size = 4
_y$ = -12						; size = 4
_sum$ = -8						; size = 4
_c$ = -1						; size = 1
_main	PROC
; File C:\Code\CSCI247\Code\C_Examples\11MixedCAssembly\ASM_Block\Program.c
; Line 18
	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H
; Line 19
	mov	DWORD PTR _x$[ebp], 1
; Line 20
	mov	DWORD PTR _y$[ebp], 2
; Line 21
	mov	DWORD PTR _sum$[ebp], 0
; Line 23
	mov	eax, DWORD PTR _y$[ebp]
	push	eax
	mov	ecx, DWORD PTR _x$[ebp]
	push	ecx
	call	_add
	add	esp, 8
	mov	DWORD PTR _sum$[ebp], eax
; Line 25
	mov	edx, DWORD PTR _sum$[ebp]
	push	edx
	push	OFFSET $SG9189
	call	_printf
	add	esp, 8
; Line 27
	call	_getchar
	mov	BYTE PTR _c$[ebp], al
; Line 29
	xor	eax, eax
; Line 30
	mov	esp, ebp
	pop	ebp
	ret	0
_main	ENDP
_TEXT	ENDS
; Function compile flags: /Odtp
_TEXT	SEGMENT
_c$ = -4						; size = 4
_a$ = 8							; size = 4
_b$ = 12						; size = 4
_add	PROC
; File C:\Code\CSCI247\Code\C_Examples\11MixedCAssembly\ASM_Block\Program.c
; Line 4
	push	ebp
	mov	ebp, esp
	push	ecx
; Line 5
	mov	DWORD PTR _c$[ebp], 0
; Line 9
	mov	eax, DWORD PTR _a$[ebp]
; Line 10
	add	eax, DWORD PTR _b$[ebp]
; Line 11
	mov	DWORD PTR _c$[ebp], eax
; Line 14
	mov	eax, DWORD PTR _c$[ebp]
; Line 15
	mov	esp, ebp
	pop	ebp
	ret	0
_add	ENDP
_TEXT	ENDS
; Function compile flags: /Odtp
;	COMDAT _printf
_TEXT	SEGMENT
__Result$ = -8						; size = 4
__ArgList$ = -4						; size = 4
__Format$ = 8						; size = 4
_printf	PROC						; COMDAT
; File C:\Program Files (x86)\Windows Kits\10\include\10.0.18362.0\ucrt\stdio.h
; Line 954
	push	ebp
	mov	ebp, esp
	sub	esp, 8
; Line 957
	lea	eax, DWORD PTR __Format$[ebp+4]
	mov	DWORD PTR __ArgList$[ebp], eax
; Line 958
	mov	ecx, DWORD PTR __ArgList$[ebp]
	push	ecx
	push	0
	mov	edx, DWORD PTR __Format$[ebp]
	push	edx
	push	1
	call	___acrt_iob_func
	add	esp, 4
	push	eax
	call	__vfprintf_l
	add	esp, 16					; 00000010H
	mov	DWORD PTR __Result$[ebp], eax
; Line 959
	mov	DWORD PTR __ArgList$[ebp], 0
; Line 960
	mov	eax, DWORD PTR __Result$[ebp]
; Line 961
	mov	esp, ebp
	pop	ebp
	ret	0
_printf	ENDP
_TEXT	ENDS
; Function compile flags: /Odtp
;	COMDAT __vfprintf_l
_TEXT	SEGMENT
__Stream$ = 8						; size = 4
__Format$ = 12						; size = 4
__Locale$ = 16						; size = 4
__ArgList$ = 20						; size = 4
__vfprintf_l PROC					; COMDAT
; File C:\Program Files (x86)\Windows Kits\10\include\10.0.18362.0\ucrt\stdio.h
; Line 642
	push	ebp
	mov	ebp, esp
; Line 643
	mov	eax, DWORD PTR __ArgList$[ebp]
	push	eax
	mov	ecx, DWORD PTR __Locale$[ebp]
	push	ecx
	mov	edx, DWORD PTR __Format$[ebp]
	push	edx
	mov	eax, DWORD PTR __Stream$[ebp]
	push	eax
	call	___local_stdio_printf_options
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	mov	edx, DWORD PTR [eax]
	push	edx
	call	___stdio_common_vfprintf
	add	esp, 24					; 00000018H
; Line 644
	pop	ebp
	ret	0
__vfprintf_l ENDP
_TEXT	ENDS
; Function compile flags: /Odtp
;	COMDAT ___local_stdio_printf_options
_TEXT	SEGMENT
___local_stdio_printf_options PROC			; COMDAT
; File C:\Program Files (x86)\Windows Kits\10\include\10.0.18362.0\ucrt\corecrt_stdio_config.h
; Line 86
	push	ebp
	mov	ebp, esp
; Line 88
	mov	eax, OFFSET ?_OptionsStorage@?1??__local_stdio_printf_options@@9@9 ; `__local_stdio_printf_options'::`2'::_OptionsStorage
; Line 89
	pop	ebp
	ret	0
___local_stdio_printf_options ENDP
_TEXT	ENDS
END
