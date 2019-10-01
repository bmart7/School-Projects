/******************************************************************************
 Project #9 Support Module
 Name: Brian Martin
 APID: A56350138
 ARM Assembly Language Implementation of functions negate, absolute, add, sub,
 mul, divide, power, and factorial
******************************************************************************/

// Return the negation of parameter passed
	.global	negate

	.text
negate:
	push	{lr}

	rsc	r0, r0, #0	@ Subtract r0 from #0 to get the negation

	pop	{lr}
	bx	lr

// Return the absolute value of parameter passed
	.global	absolute

	.text
absolute:
	push	{r4, lr}

	mov	r4, r0		@ Move parameter to preserve original number
	lsr	r4, r4, #31	@ Shift to most significant bit (sign bit)
	cmp	r4, #0		@ Find out if the number is positive
	beq	done1		@ If positive then its already its absolute value

	rsc	r0, r0, #0	@ Negate if negative

done1:	pop	{r4, lr}
	bx	lr

// Return the sum of parameters #1 and #2 passed
	.global	add

	.text
add:
	push	{lr}

	adds	r0, r0, r1	@ Add registers and update flags
	bvc	done2		@ Branch if no overflow

	mov	r0, #0x80000000	@ Return value to indicate an overflow

done2:	pop	{lr}
	bx	lr

// Return the difference of parameters #1 and
// #2 passed
	.global	sub

	.text
sub:
	push	{lr}

	subs	r0, r0, r1	@ Subtract registers and update flags
	bvc	done3		@ Branch if no overflow

	mov	r0, #0x80000000	@ Return value to indicate an overflow

done3:	pop	{lr}
	bx	lr

// Return the product of parateters #1 and 
// #2 passed
	.global	mul

	.text
mul:
	push	{lr}

	smull	r0, r1, r0, r1	@ Multiply to retrieve 64-bit product
	cmp	r1, r0, asr #31	@ Check for signed overflow using the more significant 32-bits
	beq	done4		@ Branch if there is no overflow

	mov	r0, #0x80000000	@ Return value to indicate overflow

done4:	pop	{lr}
	bx	lr

// Return the quotient of parameters #1 and
// #2 passed
	.global	divide

	.text
divide:
	push	{lr}

	cmp	r0, r1		@ Find if first register is less than the second
	blt	invalid		@ Branch if second register is greater

	sdiv	r0, r0, r1	@ Divide first register by second
	b	done5		@ Branch over invalid

invalid:
	mov	r0, #0x80000000	@ Return value to indicate invalid parameters

done5:	pop	{lr}
	bx	lr

// Return the first parameter to the power of
// the second parameter passed
	.global	power

	.text
power:
	push	{r4, r5, lr}

	cmp	r1, #0		@ Compare second parameter to 0
	blt	invalid2	@ Branch if negative
	beq	zero		@ Branch if zero

	mov	r4, r0		@ Save first parameter to register
	mov	r5, r1		@ Save second parameter as counter

loop:	cmp	r5, #1		@ Compare counter to 1, Branch if equal
	beq	done6

	mov	r1, r4		@ Move parameters for mul
	bl	mul		@ Multiple number by itself for power
	cmp	r0, #0x80000000	@ Check for overflow, branch if found
	beq	done6

	sub	r5, r5, #1	@ Subtract from counter
	b	loop		@ Branch to Loop

invalid2:
	mov	r0, #0x80000000	@ Return value to indicate invalid parameters
	b	done6		@ Branch over zero

zero:
	mov	r0, #1		@ Return 1 if power is 0

done6:	pop	{r4, r5, lr}
	bx	lr

// Return the factorial of the Parameter passed
	.global	factorial

	.text
factorial:
	push	{r4, lr}

	cmp	r0, #0		@ Compare parameter to 0
	blt	invalid3	@ Branch if negative
	beq	done7		@ Branch if 0

	cmp	r0, #1		@ Compare parameter to 1, branch if equal
	beq	done7

	mov	r4, r0		@ Save initial value as counter

loop1:	sub	r4, r4, #1	@ Subtract from counter
	cmp	r4, #1		@ Branch if equal to 1
	beq	done7

	mov	r1, r4		@ Set parameters for mul
	bl	mul		@ Multiply by next factorial value
	cmp	r0, #0x80000000	@ Check for overflow, branch if found
	beq	done7

	b	loop1		@ Loop

invalid3:
	mov	r0, #0x80000000	@ Return value to indicate invalid parameters

done7:	pop	{r4, lr}
	bx	lr


