#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include<time.h>

// Fill in the TODO sections as required and DO NOT TOUCH any of the fprintf statements

// Initialize the shift table with the pattern length
void init_table(int* shift_table, int n) {
    for (int i = 0; i < 26; i++) {
        shift_table[i] = n;  // Default shift is the pattern length
    }
}

// Construct the Bad Character Shift table (Horspool's shift table)
void preprocess(int* shift_table, char* pattern) {
    int pattern_len = strlen(pattern);
    for (int i = 0; i < pattern_len - 1; i++) {
        shift_table[pattern[i] - 'a'] = pattern_len - 1 - i;
    }
}

// Function to find occurrences using Horspool’s algorithm
int string_match(int* shift_table, char* pattern, char* text, FILE* output_file) {
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);
    int star_pos = 0;
    int cmp = 0;
    int matches = 0;

    fprintf(output_file, "Occurrences:");
    
    while (star_pos <= text_len - pattern_len) {
        int j = pattern_len - 1;
        
        while (j >= 0 && pattern[j] == text[star_pos + j]) {
            cmp++;
            j--;
        }
        
        if (j < 0) {
            fprintf(output_file, "%d,", star_pos);
            matches++;
            star_pos += shift_table[pattern[pattern_len - 1] - 'a'];  // Shift by last character's shift value
        } else {
            cmp++;
            star_pos += shift_table[text[star_pos + pattern_len - 1] - 'a'];  // Shift by mismatched character
        }
    }

    fprintf(output_file, "\n");
    fprintf(output_file, "Comparisons:%d\n\n", cmp);
    return cmp;
}

void print_table(int* shift_table, FILE* output_file)
{
	fprintf(output_file,"BCST:\n");
	for(int i=0;i<26;i++)
	{
		fprintf(output_file,"%c:%d",(char)(i+97), shift_table[i]);
	}
}

void testcase(FILE* values_file, FILE* input_file, FILE* output_file)
{
	char text[2000];
	char pattern[100];
	fscanf(input_file,"%s",text);
	fscanf(input_file,"%s",pattern);

	int* shift_table=calloc(26,sizeof(int));
	init_table(shift_table,strlen(pattern));
	preprocess(shift_table,pattern);
	print_table(shift_table, output_file);
	clock_t start = clock();
	int cmp = string_match(shift_table,pattern,text,output_file);
	clock_t end = clock();
	int elapse=(int)(((double)(end-start))/CLOCKS_PER_SEC*1000000000); //seconds to nanoseconds
	fprintf(values_file,"%ld,%ld,%d,%d\n",strlen(pattern),strlen(text),cmp,elapse);
}

int main()
{	
	FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("horspool_output.txt", "w");
    FILE *values_file = fopen("horspool_values.txt", "w");

    if (!input_file || !output_file || !values_file) {
        printf("Error opening file!\n");
        return 1;
    }
    int testcases;
	fscanf(input_file,"%d",&testcases);
	int count = 0;
	fprintf(values_file, "patternlen,textlen,cmp,timetaken\n");
	while(count < testcases)
	{
		testcase(values_file, input_file, output_file);
		count += 1;
	}
	fclose(input_file);
	fclose(output_file);
	fclose(values_file);
	return 0;
}
