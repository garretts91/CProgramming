; Listing generated by Microsoft (R) Optimizing Compiler Version 19.27.29111.0 

	TITLE	C:\Code\CSCI247\Code\C_Examples\02ReadWriteGlobalVariables\Program.c
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB LIBCMT
INCLUDELIB OLDNAMES

PUBLIC	_x
PUBLIC	_y
PUBLIC	_sum
_BSS	SEGMENT
_sum	DD	01H DUP (?)
_BSS	ENDS
_DATA	SEGMENT
_x	DD	01H
_y	DD	02H
_DATA	ENDS
PUBLIC	_main
; Function compile flags: /Odtp
_TEXT	SEGMENT
_main	PROC
; File C:\Code\CSCI247\Code\C_Examples\02ReadWriteGlobalVariables\Program.c
; Line 6
	push	ebp
	mov	ebp, esp
; Line 7
	mov	eax, DWORD PTR _x
	add	eax, DWORD PTR _y
	mov	DWORD PTR _sum, eax
; Line 9
	mov	eax, DWORD PTR _sum
; Line 10
	pop	ebp
	ret	0
_main	ENDP
_TEXT	ENDS
END
