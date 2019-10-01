/********************************************************************
 Project #10
 Name: Brian Martin
 APID: A56350138
 Searches through a table struct of with an array of of player
 structs for a specific key and returns 1 if found and 0 if not.
 Stores address of player struct in player** parameter if found.

 struct table* - table of players
 unsigned long - key to search (player number)
 struct player** - pointer to an address to store found player
********************************************************************/
	.global	search

	.text
search:
	push	{r4,r5,lr}

	mov	r4, r0		@ Store address of table
	ldrh	r3, [r4, #+2]	@ Get amount of players as counter
	add	r4, r4, #4	@ Get address of player array and load
	ldr	r4, [r4]

loop:	cmp	r3, #0		@ Check counter, Branch if at end and not found
	beq	fail

	ldrh	r5, [r4]	@ Load number (key) of player
	cmp	r1, r5		@ Compare to search key
	blo	fail		@ Branch if less than player number (ordered table)
	beq	found		@ Branch if found

	add	r4, r4, #40	@ Move to next player address
	sub	r3, r3, #1	@ Increment counter
	b	loop

found:	mov	r0, #1		@ Move found return value
	str	r4, [r2]	@ Move address of player struct
	b	finish		@ Branch over fail

fail:	mov	r0, #0		@ Move not found return value

finish:	pop	{r4,r5,lr}
	bx	lr

