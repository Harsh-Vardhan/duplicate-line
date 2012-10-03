/**
 * This function duplicates the specified line number, a specified number of 
 * times while copying a file to another
 * */

#define LB printf("\n")

int	duplct_line(int	dup_line_num, int dup_count, FILE* sp_src, FILE* sp_tgt)
{
	/* Local Declarations */
	int	curr_line_num;
	int	copy_count;
	char	ch;
	FILE*	sp_tmp;

	/* Initialize current line number */
	curr_line_num = 1;

	/* Read source file character by character */
	while ((ch = fgetc(sp_src)) != EOF)
	{
		/* if you read a NEWLINE character increment current line number */
		if (ch == '\n')
			curr_line_num++;

		/* if curr_line is the same as the line to be duplicated */
		if (curr_line_num == dup_line_num)
		{
			/* open a temp file 'line.txt' */
			if ((sp_tmp = fopen("line.txt", "w")) == NULL)
			{
				LB; printf("ERROR 1: Failed to open 'line.txt' for writing");
				LB; LB;
				return -1;
			}

			/* write curr_line to that file */
			do
			{
				fputc(ch, sp_tmp);
				ch = fgetc(sp_src);
			} while (ch != '\n' && ch != EOF);

			/* put back NEWLINE or EOF for the parent loop to process */
			ungetc(ch, sp_src);

			/* close the temp file 'line.txt' */
			if (fclose(sp_tmp) == EOF)
			{
				LB; printf("ERROR 2: Failed to close 'line.txt' after writing");
				LB; LB;
				return -2;
			}

			/* copy the line stored in temp file to the target file as many times specified */
			copy_count = 0;
			do
			{
				/* open 'line.txt' in read mode */
				if ((sp_tmp = fopen("line.txt", "r")) == NULL)
				{
					LB; printf("ERROR 1: Failed to open 'line.txt' for reading");
					LB; LB;
					return -1;
				}

				/* copy it to 'tgt.txt' */
				while ((ch = fgetc(sp_tmp)) != EOF)
					fputc(ch, sp_tgt);

				/* close 'line.txt' */
				if (fclose(sp_tmp) == EOF)
				{
					LB; printf("ERROR 2: Failed to close 'line.txt' after reading");
					LB; LB;
					return -2;
				}

				/* increment counter for copying */
				copy_count++;

			} while (copy_count < dup_count);

		}		
		
		/* else write character read to 'tgt.txt' */
		else
			fputc(ch, sp_tgt);

	}

	/* Exit function */
	return 0;
}

