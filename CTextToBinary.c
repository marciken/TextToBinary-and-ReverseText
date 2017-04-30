#include <stdio.h>
  #include <string.h>
  #define MAX 256

  int main() {
        int num;
	char convert;
        FILE *fp1, *fp2;
        char ch, src[MAX], tgt[MAX];

        /* open the source file in read mode */	
	fp1 = fopen("/home/maryamhafizahj/Documents/InputText.txt", "r");

	/* error handling */
        if (!fp1) {
                printf("Unable to open the input file!!\n");
                return 0;
        }

        /* write the output file for the user */
        fp2 = fopen("/home/maryamhafizahj/Documents/OutputBinary.bin", "wb");

	/* error handling */
        if (!fp2) {
                printf("Unable to open the output file!!\n");
                return 0;
        }



	/*
         * read data from input file and write
         * the binary form of it in output file
         */
        while (!feof(fp1)) {
                /* reading one byte of data */
                fread(&ch, sizeof(char), 1, fp1);
                /* converting the character to ascii integer value */
                num = ch;
                /* writing 4 byte of data to the output file */
                fwrite(&num, sizeof(int), 1, fp2);

        }

	printf("SUCCESSFULLY DONE!\n");
	
        /* close all opened files */
        fclose(fp1);
        fclose(fp2);
        return 0;
  }
