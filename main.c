/**
 * Program to duplicate a spcific line a specific no. of times
 * */

#include <stdio.h>
#include "duplct_line.h"

#define LB printf("\n")

int	main(void)
{
	/* Local Declarations */
	int	dup_line_num;
	int	dup_count;
	int	success;
	FILE*	sp_src;
	FILE*	sp_tgt;

	/* Intro */
	LB; printf("This program duplicates a line number as specified");

	/* Read user inputs */
	LB; printf("Please enter the line number to duplicate: ");
	scanf("%d", &dup_line_num);
	LB; printf("Please enter the number of times to duplicate: ");
	scanf("%d", &dup_count);

	/* Open files */
	if ((sp_src = fopen("src.txt", "r")) == NULL)
	{
		LB; printf("ERROR 1: Failed to open 'src.txt' for reading");
		LB; LB;
		return -1;
	}

	if ((sp_tgt = fopen("tgt.txt", "w")) == NULL)
	{
		LB; printf("ERROR 1: Failed to open 'tgt.txt' for writing");
		LB; LB;
		return -1;
	}

	/* Duplicate lines */
	success = duplct_line(dup_line_num, dup_count, sp_src, sp_tgt);

	/* Close files */
	if (fclose(sp_src) == EOF)
	{
		LB; LB;
		return -2;
	}

	if (fclose(sp_tgt) == EOF)
	{
		LB; printf("ERROR 2: Failed to close 'tgt.txt' after writing");
		LB; LB;
		return -2;
	}

	/* Exit Program */
	LB; LB;
	return 0;
}

