/********************************************************************
 Project #8 -- ARM Control Constructs
 Name: Brian Martin
 APID: A56350138
 Read one character from the standard input stream, classify it,
 and write it to the standart output stream.
********************************************************************/
	.global	main

	.text
main:
	push	{lr}

	mov	r4, #0		@ initialize character count
	mov	r5, #0		@ initialize newline count
	mov	r6, #0		@ initialize whitespace count
	mov	r7, #0		@ initialize octal count
	mov	r8, #0		@ initialize decimal count
	mov	r9, #0		@ initialize hexadecimal count
	mov	r10, #0		@ initialize letter count

loop:	bl	getchar		@ reads one character from standard input stream

//if character is -1 indicating end of file
//branch out of loop
if0:	cmp	r0, #-1
	beq	end

//increment total character count
//if character is not end of file character
	add	r4, #1		@ increments character count

//if character is equal to newline character
//increment newline and whitespace count
if1:	cmp	r0, #0x0a	@ compare character to newline character
	bne	if2		@ branch if not equal

then1:	add	r5, #1		@ increment newline count
	add	r6, #1		@ increment whitespace count
	b	iter		@ iterate if found

//if character is equal to tab character
//increment whitespace count
if2:	cmp	r0, #0x09	@ compare character to tab character
	bne	if3		@ branch if not equal

then2:	add	r6, #1		@ increment whitespace count
	b	iter		@ iterate if found

//if character is equal to space character
//increament whitespace count
if3:	cmp	r0, #0x20	@ compare character to space character
	bne	if4		@ branch if not equal

then3:	add	r6, #1		@ increment whitespace count
	b	iter		@ iterate if found

//if character is in the set 0-7
//increment octal, decimal, and hex count
if4:	cmp	r0, #0x30	@ compare character to '0'
	blt	iter		@ iterate if less than, no lower characters relevant
	cmp	r0, #0x37	@ compare character to '7'
	bgt	if5		@ branch if greater than

then4:	add	r7, #1		@ increment octal count
	add	r8, #1		@ increment decimal count
	add	r9, #1		@ increment hexidecimal count
	b	iter		@ iterate if found

//if character is in the set 8-9
//increment decimal and hex count
if5:	cmp	r0, #0x38	@ compare character to '8'
	blt	iter		@ iterate if less than, no lower characters relevant
	cmp	r0, #0x39	@ compare character to '9'
	bgt	if6		@ branch if greater than

then5:	add	r8, #1		@ increment decimal count
	add	r9, #1		@ increment hexidecimal count
	b	iter		@ iterate if found

//if character is in the set A-F
//increment hex and letter count
if6:	cmp	r0, #0x41	@ compare character to 'A'
	blt	iter		@ iterate if less than, no lower characters relevant
	cmp	r0, #0x46	@ compare character to 'F'
	bgt	if7		@ branch if greater than

then6:	add	r9, #1		@ increment hexidecimal count
	add	r10, #1		@ increment letter count
	b	iter		@ iterate if found

//if character is in the set G-Z
//increment letter count
if7:	cmp	r0, #0x47	@ compare character to 'G'
	blt	iter		@ iterate if less than, no lower characters relevant
	cmp	r0, #0x5a	@ compare character to 'Z'
	bgt	if8		@ branch if greater than

then7:	add	r10, #1		@ increment letter count
	b	iter		@ iterate if found

//if character is in the set a-f
//increment hex and letter count
if8:	cmp	r0, #0x61	@ compare character to 'a'
	blt	iter		@ iterate if less than, no lower characters relevant
	cmp	r0, #0x66	@ compare character to 'f'
	bgt	if9		@ branch if greater than

then8:	add	r9, #1		@ increment hexidecimal count
	add	r10, #1		@ increment letter count
	b	iter		@ iterate if found

//if character is in the set g-z
//increment letter count
if9:	cmp	r0, #0x67	@ compare character to 'g'
	blt	iter		@ iterate if less than, no lower characters relevant
	cmp	r0, #0x7a	@ compare character to 'z'
	bgt	iter		@ iterate if greater than, no more characters relevant

then9:	add	r10, #1		@ increment letter count

iter:	bl	putchar		@ write character to standard output
	b	loop		@ loop if found, no other ifs

end:	ldr	r0, =fmt1	@ first arg -- formatted string for total count
	mov	r1, r4		@ second arg -- total character count
	bl	printf		@ display total character count

	ldr	r0, =fmt2	@ first arg -- formatted string for newline count
	mov	r1, r5		@ second arg -- newline character count
	bl	printf		@ display newline character count

	ldr	r0, =fmt3	@ first arg -- formatted string for whitespace count
	mov	r1, r6		@ second arg -- total whitespace count
	bl	printf		@ display whitespace character count

	ldr	r0, =fmt4	@ first arg -- formatted string for octal count
	mov	r1, r7		@ second arg -- total octal count
	bl	printf		@ display octal digit count

	ldr	r0, =fmt5	@ first arg -- formatted string for decimal count
	mov	r1, r8		@ second arg -- total decimal count
	bl	printf		@ display decimal digit count

	ldr	r0, =fmt6	@ first arg -- formatted string for hexidecimal count
	mov	r1, r9		@ second arg -- total hexidecimal count
	bl	printf		@ display hexidecimal digit count

	ldr	r0, =fmt7	@ first arg -- formatted string for letter count
	mov	r1, r10		@ second arg -- total letter count
	bl	printf		@ display letter count

	pop	{lr}
	bx	lr

	.data
fmt1:
	.asciz	"\nThis stream has %d total characters\n"
fmt2:
	.asciz	"\nThis stream has %d newline characters\n"
fmt3:
	.asciz	"\nThis stream has %d whitespace characters\n"
fmt4:
	.asciz	"\nThis stream has %d octal digits\n"
fmt5:
	.asciz	"\nThis stream has %d decimal digits\n"
fmt6:
	.asciz	"\nThis stream has %d hexidecimal digits\n"
fmt7:
	.asciz	"\nThis stream has %d letters\n"









