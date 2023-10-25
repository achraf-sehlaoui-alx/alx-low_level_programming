section 	.text
	global	main
	extern	printf
maim:
	mov	edi, format
	mov	eax, 0
	call	printf

section		.data
	format db 'Hello, Holberton', 0xa, 0
