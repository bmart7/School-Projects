/********************************************************************
 Project #11
 Name: Brian Martin
 APID: A56350138
********************************************************************/

/***********************************************************************/
/*  Function:  search                                                  */
/*                                                                     */
/*  Purpose:  locate and return a pointer to a player, if the player   */
/*  is present in the table.                                           */
/*                                                                     */
/*  Arguments:                                                         */
/*    pointer to table of players                                      */
/*    jersey number of player to be located                            */
/*    pointer to pointer to player                                     */
/*                                                                     */
/*  Return value:                                                      */
/*    1 (true) if player located, 0 (false) otherwise                  */
/***********************************************************************/

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
	str	r4, [r2]	@ Store address of player struct
	b	finish		@ Branch over fail

fail:	mov	r0, #0		@ Move not found return value
	str	r4, [r2]	@ Store address of insert location

finish:	pop	{r4,r5,lr}
	bx	lr


/***********************************************************************/
/*  Function:  delete                                                  */
/*                                                                     */
/*  Purpose:  delete a player from the table, if the                   */
/*  player is present in the table.                                    */
/*                                                                     */
/*  Arguments:                                                         */
/*    pointer to table of players                                      */
/*    jersey number of player to be deleted                            */
/*                                                                     */
/*  Return value:                                                      */
/*    1 (true) if player deleted, 0 (false) otherwise                  */
/***********************************************************************/

	.global	delete

	.text
delete:
	push	{r4,r5,r6,r7,lr}

	mov	r4, r0		@ Store address of table
	mov	r5, r1		@ Store number to be deleted
	ldr	r2, =point	@ Address of pointer to store player
	bl	search

	cmp	r0, #0		@ Finish if not found in table
	beq	done

	ldr	r6, =point	@ Retrieve address of found player
	ldr	r6, [r6]

	ldr	r3, [r4, #+4]	@ Load address of first player in array
	sub	r7, r6, r3	@ Find offset of found player
	mov	r0, #40		@ Size of player struct
	sdiv	r7, r7, r0	@ Find index of found player
	ldrh	r0, [r4, #+2]	@ Load count of players
	add	r7, r7, #1
	sub	r7, r0, r7	@ Find count of remaining players in array

loop1:
	cmp	r7, #0		@ Branch if no remaining players left in array
	beq	success

	mov	r0, r6		@ Move subsequent players in array to i-1
	add	r1, r0, #40
	mov	r2, #40
	bl	memmove

	sub	r7, r7, #1	@ Increment count of remaining players
	add	r6, r6, #40	@ Increment address to next player
	b	loop1


success:
	mov	r0, #1		@ Move successful return value
	ldrh	r1, [r4, #+2]	@ Load and decrease player count
	sub	r1, r1, #1
	strh	r1, [r4, #+2]	@ Store updated player count

done:
	pop	{r4,r5,r6,r7,lr}
	bx	lr

	.data
point:
	.skip 	4


/***********************************************************************/
/*  Function:  insert                                                  */
/*                                                                     */
/*  Purpose:  insert a player into the table, as long as there is      */
/*  room in the table and the player is not already present.           */ 
/*                                                                     */
/*  Arguments:                                                         */
/*    pointer to table of players                                      */
/*    jersey number of player to be inserted                           */
/*    pointer to name of player                                        */
/*    number of games played                                           */
/*    number of goals scored                                           */
/*    number of assists scored                                         */
/*                                                                     */
/*  Return value:                                                      */
/*    1 (true) if player inserted, 0 (false) otherwise                 */
/***********************************************************************/

	.global	insert

	.text
insert:
	push	{r4,r5,r6,r7,r8,r9,r10,r11,lr}

	ldrh	r4, [r0]	@ Load capacity
	ldrh	r5, [r0, #+2]	@ Load count
	cmp	r4, r5		@ Branch if at capacity
	beq	fail1

	mov	r4, r0		@ Store table
	mov	r5, r1		@ Store jersey number
	mov	r6, r2		@ Store char*
	mov	r7, r3		@ Store games played
	ldr	r8, [sp, #+36]	@ Store goals scored
	ldr	r9, [sp, #+40]	@ Store assists scored

	ldr	r2, =ipoint	@ Address of pointer to store player
	bl	search		@ Search for player in table

	cmp	r0, #1		@ Branch if already exists
	beq	fail1

	ldr	r10, =ipoint	@ Retrieve address of insertion location
	ldr	r10, [r10]

	mov	r0, #40		@ Size of player
	ldr	r1, [r4, #+4]	@ Address of first player
	sub	r11, r10, r1	@ Find offset of insertion location
	sdiv	r11, r11, r0	@ Find index of insertion location
	ldrh	r2, [r4, #+2]	@ Load count
	sub	r11, r2, r11	@ Find remaining number of players

	sub	r2, r2, #1	@ Find address of last player
	mul	r3, r2, r0
	add	r10, r1, r3

loop2:
	cmp	r11, #0		@ Branch if no remaining players
	beq	endloop

	add	r0, r10, #40	@ Move player to i+1
	mov	r1, r10
	mov	r2, #40
	bl	memmove

	sub	r11, r11, #1	@ Increment remaining players
	sub	r10, r10, #40	@ Increment to previous player
	b	loop2

endloop:
	add	r10, r10, #40	@ Set insert location
	strh	r5, [r10]	@ Store jersey number
	strh	r7, [r10, #+28]	@ Store games
	strh	r8, [r10, #+30]	@ Store goals
	strh	r9, [r10, #+32] @ Store assists

	add	r8, r8, r9	@ Calculate Points
	strh	r8, [r10, #+34] @ Store Points

	fmsr	s0, r8		@ Convert points
	fsitos	s1, s0
	fmsr	s0, r7		@ Convert games
	fsitos	s2, s0
	fdivs	s3, s1, s2	@ Calculate points / games
	fsts	s3, [r10, #+36]	@ Store points per game

	mov	r5, #0		@ Offset for char*
	mov	r8, #2		@ Offset for player struct

charloop:
	ldrb	r7, [r6, +r5]	@ Load char
	strb	r7, [r10, +r8]	@ Store char
	cmp	r7, #0		@ Branch if null
	beq	success1
	add	r5, r5, #1	@ Increment offsets
	add	r8, r8, #1
	b	charloop

success1:
	mov	r0, #1		@ Return true
	ldrh	r1, [r4, #+2]	@ Update count
	add	r1, r1, #1
	strh	r1, [r4, #+2]
	b	done1

fail1:
	mov	r0, #0		@ Return false

done1:
	pop	{r4,r5,r6,r7,r8,r9,r10,r11,lr}
	bx	lr

	.data
ipoint:
	.skip 	4

