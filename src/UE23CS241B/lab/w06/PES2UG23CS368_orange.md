# DAA: Orange Problem

> Name: Nathan Matthew Paul
> SRN: PES2UG23CS368
> Section: 4F
> Date: 2025-04-07

> [!Question]
> 1. Horspool Algorithm
> Implement the Horspool Algorithm, display the shift table contents and the starting
> indices of all the occurrences of the pattern in the text. Count the total number of
> comparisons involved.
>
> 2. Boyer Moore Algorithm
> Implement the Boyer Moore algorithm, display the good suffix shift table and the bad
> character shift table. Also print the starting indices of all the occurrences of the pattern in
> the text. Count the total number of comparisons involved.
>
> 3. Performance Evaluation
> Measure and compare execution times and number of comparisons for both algorithms
> and plot a graph to visualize their performance. (Hint: gnuplot can be used)
>
> Two graphs to be plotted:
> 4. Text length vs Execution Time for given test case against both algorithms
> 5. Text length vs Number of comparisons for both algorithms

---

 <div style="page-break-after: always;"></div>

# Sample Graphs

## Time plot

![[time_graph_PES2UG23CS368.jpg]]

## Comparison plot

![[comparison_graph_PES2UG23CS368.jpg]]

---

 <div style="page-break-after: always;"></div>

# Code

## Horspool

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void init_table(int* shift_table, int n) {
    for (int i = 0; i < 26; i++)
        shift_table[i] = n;
}

void preprocess(int* shift_table, char* pattern) {
    int len = strlen(pattern);
    for (int i = 0; i < len - 1; i++)
        shift_table[pattern[i] - 'a'] = len - i - 1;
}

int string_match(int* shift_table, char* pattern, char* text, FILE* output_file) {
    int matches = 0, cmp = 0;
    int m = strlen(pattern);
    int n = strlen(text);
    fprintf(output_file, "Occurrences:");
    int i = 0;
    while (i <= n - m) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[i + j]) {
            j--;
            cmp++;
        }
        if (j < 0) {
            fprintf(output_file, "%d,", i);
            matches++;
            i += 1;
        } else {
            cmp++;
            i += shift_table[text[i + m - 1] - 'a'];
        }
    }
    fprintf(output_file, "\nComparisons:%d\n\n", cmp);
    return cmp;
}

void print_table(int* shift_table, FILE* output_file) {
    fprintf(output_file, "BCST:\n");
    for (int i = 0; i < 26; i++) {
        fprintf(output_file, "%c:%d", (char)(i + 97), shift_table[i]);
        if (i < 25) fprintf(output_file, ",");
    }
    fprintf(output_file, "\n");
}

void testcase(FILE* values_file, FILE* input_file, FILE* output_file) {
    char text[2000], pattern[100];
    fscanf(input_file, "%s", text);
    fscanf(input_file, "%s", pattern);

    int* shift_table = calloc(26, sizeof(int));
    init_table(shift_table, strlen(pattern));
    preprocess(shift_table, pattern);
    print_table(shift_table, output_file);

    clock_t start = clock();
    int cmp = string_match(shift_table, pattern, text, output_file);
    clock_t end = clock();

    int elapsed = (int)(((double)(end - start)) / CLOCKS_PER_SEC * 1e9);
    fprintf(values_file, "%ld,%ld,%d,%d\n", strlen(pattern), strlen(text), cmp, elapsed);
    free(shift_table);
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("horspool_output.txt", "w");
    FILE *values_file = fopen("horspool_values.txt", "w");

    if (!input_file || !output_file || !values_file) {
        printf("Error opening file!\n");
        return 1;
    }

    int testcases;
    fscanf(input_file, "%d", &testcases);
    fprintf(values_file, "patternlen,textlen,cmp,timetaken\n");

    for (int i = 0; i < testcases; i++)
        testcase(values_file, input_file, output_file);

    fclose(input_file);
    fclose(output_file);
    fclose(values_file);
    return 0;
}
```

## Boyer Moore

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

// Function to create the Bad Character Shift Table
int* bcst_create(const char* pattern, int pattern_len) {
    int* bcst = (int*)malloc(26 * sizeof(int));
    for (int i = 0; i < 26; i++) {
        bcst[i] = pattern_len;
    }
    for (int i = 0; i < pattern_len - 1; i++) {
        bcst[pattern[i] - 'a'] = pattern_len - i - 1;
    }
    return bcst;
}

// Function to create the Good Suffix Shift Table
int* gsst_create(const char* pattern, int pattern_len) {
    int* gsst = (int*)malloc((pattern_len + 1) * sizeof(int));
    if (gsst == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    for (int x = 1; x <= pattern_len; x++) {
        int r2 = 0;
        char* suffix = (char*)malloc((x + 1) * sizeof(char));
        for (int i = 0; i < x; i++) {
            suffix[x - i - 1] = pattern[pattern_len - i - 1];
        }
        suffix[x] = '\0';

        char mis_char = (pattern_len - x - 1 >= 0) ? pattern[pattern_len - x - 1] : '~';

        char* rev_pattern = (char*)malloc(pattern_len * sizeof(char));
        for (int i = 0; i < pattern_len - 1; i++) {
            rev_pattern[i] = pattern[pattern_len - i - 2];
        }
        rev_pattern[pattern_len - 1] = '\0';

        char* rev_suffix = (char*)malloc((x + 1) * sizeof(char));
        for (int i = 0; i < x; i++) {
            rev_suffix[i] = suffix[x - i - 1];
        }
        rev_suffix[x] = '\0';

        int count = 0;
        while (1) {
            char* pos_ptr = strstr(rev_pattern, rev_suffix);
            if (pos_ptr == NULL) {
                r2 = 1;
                break;
            }
            int pos = pos_ptr - rev_pattern;
            char check_char = (pos + x < pattern_len - 1) ? rev_pattern[pos + x] : '`';
            if (check_char != mis_char) {
                gsst[x] = pos + count + 1;
                break;
            }
            rev_pattern += pos + 1;
            count += pos + 1;
        }

        if (r2) {
            while (1) {
                if (strlen(suffix) == 1) {
                    gsst[x] = pattern_len;
                    break;
                }
                suffix++;
                if (strncmp(pattern, suffix, strlen(suffix)) == 0) {
                    gsst[x] = pattern_len - strlen(suffix);
                    break;
                }
            }
        }
    }
    return gsst;
}

// Boyer-Moore search function
int boyer_moore(const char* text, const char* pattern, int* bcst, int* gsst, FILE* output_file) {
    int comparisons = 0;
    int pattern_len = strlen(pattern);
    int text_len = strlen(text);
    int pos = pattern_len - 1;

    fprintf(output_file, "Occurrences:");
    while (pos < text_len) {
        int match = 0;
        int i;
        for (i = pattern_len - 1; i >= 0; i--) {
            comparisons++;
            if (text[pos - pattern_len + 1 + i] != pattern[i]) {
                break;
            }
        }
        if (i < 0) {
            fprintf(output_file, "%d,", pos - pattern_len + 1);
            pos += gsst[1];
        } else {
            int bc_shift = bcst[text[pos] - 'a'];
            int gs_shift = gsst[pattern_len - i];
            pos += (bc_shift > gs_shift) ? bc_shift : gs_shift;
        }
    }
    fprintf(output_file, "\n");
    return comparisons;
}

void testcase(FILE* values_file, FILE* input_file, FILE* output_file) {
    char text[2000];
    char pattern[500];
    fscanf(input_file, "%s", text);
    fscanf(input_file, "%s", pattern);

    int pattern_len = strlen(pattern);
    int* bcst = bcst_create(pattern, pattern_len);
    fprintf(output_file, "BCST:\n");
    for (int i = 0; i < 26; i++) {
        fprintf(output_file, "%c:%d, ", (char)(i + 'a'), bcst[i]);
    }
    fprintf(output_file, "\n");

    int* gsst = gsst_create(pattern, pattern_len);
    fprintf(output_file, "GSST:\n");
    for (int i = 1; i <= pattern_len; i++) {
        fprintf(output_file, "%d:%d, ", i, gsst[i]);
    }
    fprintf(output_file, "\n");

    clock_t start = clock();
    int comparisons = boyer_moore(text, pattern, bcst, gsst, output_file);
    clock_t end = clock();
    fprintf(output_file, "Comparisons:%d\n\n", comparisons);

    int elapse = (int)(((double)(end - start)) / CLOCKS_PER_SEC * 1000000000);
    fprintf(values_file, "%d,%ld,%d,%d\n", pattern_len, strlen(text), comparisons, elapse);

    free(bcst);
    free(gsst);
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    FILE* output_file = fopen("boyermoore_output.txt", "w");
    FILE* values_file = fopen("boyermoore_values.txt", "w");

    if (!input_file || !output_file || !values_file) {
        printf("Error opening file!\n");
        return 1;
    }

    int testcases;
    fscanf(input_file, "%d", &testcases);
    int count = 0;
    fprintf(values_file, "patternlen,textlen,cmp,timetaken\n");

    while (count < testcases) {
        testcase(values_file, input_file, output_file);
        count += 1;
    }

    fclose(input_file);
    fclose(output_file);
    fclose(values_file);
    return 0;
}
```

---

# Output

## Horspool

```plain
BCST:
a:8,b:15,c:9,d:15,e:1,f:6,g:15,h:2,i:15,j:15,k:15,l:15,m:15,n:7,o:15,p:15,q:15,r:4,s:10,t:3,u:5,v:15,w:15,x:15,y:15,z:15
Occurrences:320,818,
Comparisons:131

BCST:
a:9,b:11,c:8,d:11,e:4,f:10,g:11,h:5,i:2,j:11,k:11,l:11,m:11,n:11,o:11,p:11,q:11,r:3,s:1,t:6,u:11,v:11,w:11,x:11,y:11,z:11
Occurrences:71,569,
Comparisons:135

BCST:
a:10,b:1,c:12,d:18,e:11,f:18,g:18,h:15,i:4,j:18,k:18,l:18,m:5,n:7,o:8,p:18,q:18,r:18,s:18,t:3,u:18,v:18,w:18,x:18,y:2,z:18
Occurrences:268,766,
Comparisons:120

BCST:
a:16,b:19,c:7,d:23,e:9,f:10,g:23,h:23,i:2,j:23,k:23,l:23,m:20,n:8,o:1,p:4,q:23,r:6,s:23,t:3,u:23,v:23,w:23,x:23,y:5,z:23
Occurrences:357,855,
Comparisons:162

BCST:
a:4,b:24,c:24,d:24,e:17,f:8,g:24,h:22,i:2,j:24,k:24,l:11,m:5,n:9,o:1,p:18,q:24,r:6,s:15,t:3,u:24,v:24,w:24,x:24,y:24,z:24
Occurrences:133,631,
Comparisons:192

BCST:
a:12,b:13,c:7,d:10,e:8,f:13,g:13,h:13,i:4,j:13,k:13,l:13,m:13,n:11,o:1,p:13,q:13,r:5,s:9,t:3,u:6,v:13,w:13,x:13,y:2,z:13
Occurrences:7,505,
Comparisons:184

BCST:
a:20,b:23,c:19,d:23,e:10,f:14,g:1,h:23,i:3,j:23,k:18,l:23,m:23,n:2,o:23,p:8,q:23,r:7,s:23,t:4,u:23,v:23,w:23,x:23,y:23,z:23
Occurrences:88,586,
Comparisons:131

BCST:
a:22,b:22,c:7,d:22,e:1,f:20,g:22,h:6,i:4,j:22,k:22,l:22,m:22,n:5,o:11,p:14,q:3,r:16,s:22,t:9,u:2,v:22,w:22,x:22,y:15,z:22
Occurrences:368,866,
Comparisons:131

BCST:
a:3,b:11,c:1,d:11,e:6,f:11,g:11,h:4,i:11,j:11,k:11,l:11,m:11,n:2,o:7,p:11,q:11,r:11,s:11,t:8,u:11,v:11,w:11,x:11,y:11,z:11
Occurrences:264,762,
Comparisons:199

BCST:
a:6,b:20,c:20,d:17,e:2,f:20,g:5,h:20,i:12,j:20,k:20,l:20,m:3,n:1,o:11,p:20,q:20,r:20,s:13,t:20,u:20,v:20,w:20,x:20,y:20,z:20
Occurrences:390,888,
Comparisons:137

BCST:
a:2,b:15,c:11,d:3,e:15,f:15,g:15,h:15,i:7,j:15,k:15,l:8,m:15,n:6,o:4,p:15,q:15,r:13,s:15,t:5,u:12,v:15,w:15,x:15,y:1,z:15
Occurrences:34,532,1030,
Comparisons:164

BCST:
a:1,b:15,c:15,d:15,e:6,f:15,g:15,h:11,i:9,j:15,k:15,l:15,m:15,n:2,o:3,p:7,q:15,r:5,s:4,t:12,u:15,v:15,w:15,x:15,y:15,z:15
Occurrences:131,629,1127,
Comparisons:165

BCST:
a:13,b:13,c:10,d:13,e:11,f:13,g:13,h:1,i:7,j:13,k:13,l:13,m:13,n:3,o:4,p:13,q:13,r:8,s:12,t:2,u:9,v:13,w:13,x:13,y:5,z:13
Occurrences:10,508,1006,
Comparisons:194

BCST:
a:4,b:25,c:15,d:22,e:8,f:25,g:25,h:25,i:2,j:25,k:18,l:25,m:25,n:9,o:1,p:25,q:25,r:7,s:25,t:3,u:25,v:25,w:25,x:25,y:25,z:5
Occurrences:241,739,
Comparisons:209

BCST:
a:5,b:21,c:3,d:6,e:2,f:21,g:21,h:12,i:9,j:21,k:21,l:21,m:21,n:16,o:11,p:21,q:21,r:10,s:1,t:13,u:14,v:21,w:21,x:21,y:21,z:8
Occurrences:110,608,1106,
Comparisons:215

BCST:
a:15,b:15,c:15,d:10,e:1,f:3,g:15,h:15,i:15,j:15,k:15,l:11,m:15,n:15,o:4,p:15,q:15,r:6,s:5,t:2,u:9,v:15,w:14,x:15,y:15,z:15
Occurrences:56,554,1052,
Comparisons:198

BCST:
a:24,b:31,c:4,d:31,e:5,f:19,g:16,h:31,i:2,j:6,k:31,l:31,m:31,n:7,o:1,p:13,q:31,r:12,s:31,t:3,u:31,v:31,w:31,x:31,y:31,z:31
Occurrences:210,708,1206,
Comparisons:222

BCST:
a:20,b:23,c:19,d:23,e:10,f:14,g:1,h:23,i:3,j:23,k:18,l:23,m:23,n:2,o:23,p:8,q:23,r:7,s:23,t:4,u:23,v:23,w:23,x:23,y:23,z:23
Occurrences:88,586,1084,
Comparisons:180

BCST:
a:1,b:15,c:15,d:15,e:6,f:15,g:15,h:11,i:9,j:15,k:15,l:15,m:15,n:2,o:3,p:7,q:15,r:5,s:4,t:12,u:15,v:15,w:15,x:15,y:15,z:15
Occurrences:131,629,1127,
Comparisons:183

BCST:
a:11,b:17,c:17,d:5,e:2,f:17,g:14,h:17,i:13,j:17,k:17,l:6,m:17,n:17,o:8,p:17,q:17,r:1,s:3,t:12,u:4,v:17,w:9,x:17,y:17,z:17
Occurrences:49,547,1045,
Comparisons:209

BCST:
a:3,b:8,c:16,d:15,e:5,f:16,g:16,h:16,i:2,j:16,k:16,l:1,m:4,n:16,o:11,p:12,q:16,r:16,s:10,t:16,u:16,v:16,w:16,x:16,y:16,z:16
Occurrences:296,794,1292,
Comparisons:206

BCST:
a:7,b:7,c:7,d:7,e:2,f:7,g:7,h:3,i:1,j:7,k:7,l:7,m:7,n:5,o:6,p:7,q:7,r:7,s:7,t:4,u:7,v:7,w:7,x:7,y:7,z:7
Occurrences:18,516,1014,
Comparisons:309

BCST:
a:4,b:10,c:2,d:10,e:1,f:10,g:10,h:5,i:10,j:10,k:10,l:10,m:10,n:3,o:8,p:10,q:10,r:10,s:10,t:9,u:10,v:10,w:10,x:10,y:10,z:10
Occurrences:266,764,1262,
Comparisons:275

BCST:
a:9,b:29,c:29,d:12,e:1,f:28,g:15,h:6,i:3,j:29,k:29,l:29,m:29,n:10,o:5,p:22,q:29,r:4,s:29,t:7,u:8,v:29,w:29,x:29,y:29,z:2
Occurrences:96,594,1092,
Comparisons:204

BCST:
a:11,b:17,c:17,d:5,e:2,f:17,g:14,h:17,i:13,j:17,k:17,l:6,m:17,n:17,o:8,p:17,q:17,r:1,s:3,t:12,u:4,v:17,w:9,x:17,y:17,z:17
Occurrences:49,547,1045,
Comparisons:224

BCST:
a:13,b:19,c:19,d:19,e:1,f:19,g:12,h:19,i:19,j:19,k:19,l:19,m:10,n:5,o:18,p:19,q:19,r:2,s:4,t:7,u:3,v:19,w:19,x:19,y:19,z:19
Occurrences:398,896,1394,
Comparisons:208

BCST:
a:11,b:12,c:5,d:12,e:6,f:12,g:12,h:12,i:3,j:12,k:12,l:12,m:12,n:1,o:2,p:10,q:12,r:9,s:12,t:4,u:12,v:12,w:12,x:12,y:12,z:12
Occurrences:420,918,1416,
Comparisons:299

BCST:
a:9,b:11,c:8,d:11,e:4,f:10,g:11,h:5,i:2,j:11,k:11,l:11,m:11,n:11,o:11,p:11,q:11,r:3,s:1,t:6,u:11,v:11,w:11,x:11,y:11,z:11
Occurrences:71,569,1067,1565,
Comparisons:251

BCST:
a:12,b:13,c:7,d:10,e:8,f:13,g:13,h:13,i:4,j:13,k:13,l:13,m:13,n:11,o:1,p:13,q:13,r:5,s:9,t:3,u:6,v:13,w:13,x:13,y:2,z:13
Occurrences:7,505,1003,1501,
Comparisons:317

BCST:
a:4,b:24,c:24,d:24,e:17,f:8,g:24,h:22,i:2,j:24,k:24,l:11,m:5,n:9,o:1,p:18,q:24,r:6,s:15,t:3,u:24,v:24,w:24,x:24,y:24,z:24
Occurrences:133,631,1129,1627,
Comparisons:335
```

## Boyer Moore

```plain
BCST:
a:8, b:15, c:9, d:15, e:1, f:6, g:15, h:2, i:15, j:15, k:15, l:15, m:15, n:7, o:15, p:15, q:15, r:4, s:10, t:3, u:5, v:15, w:15, x:15, y:15, z:15, 
GSST:
1:4, 2:11, 3:15, 4:15, 5:15, 6:15, 7:15, 8:15, 9:15, 10:15, 11:15, 12:15, 13:15, 14:15, 15:15, 
Occurrences:320,818,
Comparisons:133

BCST:
a:9, b:11, c:8, d:11, e:4, f:10, g:11, h:5, i:2, j:11, k:11, l:11, m:11, n:11, o:11, p:11, q:11, r:3, s:1, t:6, u:11, v:11, w:11, x:11, y:11, z:11, 
GSST:
1:11, 2:11, 3:11, 4:11, 5:11, 6:11, 7:11, 8:11, 9:11, 10:11, 11:11, 
Occurrences:
Comparisons:79

BCST:
a:10, b:1, c:12, d:18, e:11, f:18, g:18, h:15, i:4, j:18, k:18, l:18, m:5, n:7, o:8, p:18, q:18, r:18, s:18, t:3, u:18, v:18, w:18, x:18, y:2, z:18, 
GSST:
1:2, 2:18, 3:18, 4:18, 5:18, 6:18, 7:18, 8:18, 9:18, 10:18, 11:18, 12:18, 13:18, 14:18, 15:18, 16:18, 17:18, 18:18, 
Occurrences:268,766,
Comparisons:110

BCST:
a:16, b:19, c:7, d:23, e:9, f:10, g:23, h:23, i:2, j:23, k:23, l:23, m:20, n:8, o:1, p:4, q:23, r:6, s:23, t:3, u:23, v:23, w:23, x:23, y:5, z:23, 
GSST:
1:8, 2:23, 3:23, 4:12, 5:23, 6:23, 7:23, 8:23, 9:23, 10:23, 11:23, 12:23, 13:23, 14:23, 15:23, 16:23, 17:23, 18:23, 19:23, 20:23, 21:23, 22:23, 23:23, 
Occurrences:
Comparisons:78

BCST:
a:4, b:24, c:24, d:24, e:17, f:8, g:24, h:22, i:2, j:24, k:24, l:11, m:5, n:9, o:1, p:18, q:24, r:6, s:15, t:3, u:24, v:24, w:24, x:24, y:24, z:24, 
GSST:
1:9, 2:13, 3:24, 4:24, 5:24, 6:24, 7:24, 8:24, 9:24, 10:24, 11:24, 12:24, 13:24, 14:24, 15:24, 16:24, 17:24, 18:24, 19:24, 20:24, 21:24, 22:24, 23:24, 24:24, 
Occurrences:631,
Comparisons:95

BCST:
a:12, b:13, c:7, d:10, e:8, f:13, g:13, h:13, i:4, j:13, k:13, l:13, m:13, n:11, o:1, p:13, q:13, r:5, s:9, t:3, u:6, v:13, w:13, x:13, y:2, z:13, 
GSST:
1:11, 2:13, 3:13, 4:13, 5:13, 6:13, 7:13, 8:13, 9:13, 10:13, 11:13, 12:13, 13:13, 
Occurrences:
Comparisons:93

BCST:
a:20, b:23, c:19, d:23, e:10, f:14, g:1, h:23, i:3, j:23, k:18, l:23, m:23, n:2, o:23, p:8, q:23, r:7, s:23, t:4, u:23, v:23, w:23, x:23, y:23, z:23, 
GSST:
1:20, 2:23, 3:23, 4:23, 5:23, 6:23, 7:23, 8:23, 9:23, 10:23, 11:23, 12:23, 13:23, 14:23, 15:23, 16:23, 17:23, 18:23, 19:23, 20:23, 21:23, 22:23, 23:23, 
Occurrences:
Comparisons:50

BCST:
a:22, b:22, c:7, d:22, e:1, f:20, g:22, h:6, i:4, j:22, k:22, l:22, m:22, n:5, o:11, p:14, q:3, r:16, s:22, t:9, u:2, v:22, w:22, x:22, y:15, z:22, 
GSST:
1:22, 2:22, 3:22, 4:22, 5:22, 6:22, 7:22, 8:22, 9:22, 10:22, 11:22, 12:22, 13:22, 14:22, 15:22, 16:22, 17:22, 18:22, 19:22, 20:22, 21:22, 22:22, 
Occurrences:
Comparisons:54

BCST:
a:3, b:11, c:1, d:11, e:6, f:11, g:11, h:4, i:11, j:11, k:11, l:11, m:11, n:2, o:7, p:11, q:11, r:11, s:11, t:8, u:11, v:11, w:11, x:11, y:11, z:11, 
GSST:
1:6, 2:11, 3:11, 4:11, 5:11, 6:11, 7:11, 8:11, 9:11, 10:11, 11:11, 
Occurrences:
Comparisons:137

BCST:
a:6, b:20, c:20, d:17, e:2, f:20, g:5, h:20, i:12, j:20, k:20, l:20, m:3, n:1, o:11, p:20, q:20, r:20, s:13, t:20, u:20, v:20, w:20, x:20, y:20, z:20, 
GSST:
1:20, 2:20, 3:20, 4:20, 5:20, 6:20, 7:20, 8:20, 9:20, 10:20, 11:20, 12:20, 13:20, 14:20, 15:20, 16:20, 17:20, 18:20, 19:20, 20:20, 
Occurrences:
Comparisons:62

BCST:
a:2, b:15, c:11, d:3, e:15, f:15, g:15, h:15, i:7, j:15, k:15, l:8, m:15, n:6, o:4, p:15, q:15, r:13, s:15, t:5, u:12, v:15, w:15, x:15, y:1, z:15, 
GSST:
1:15, 2:15, 3:15, 4:15, 5:15, 6:15, 7:15, 8:15, 9:15, 10:15, 11:15, 12:15, 13:15, 14:15, 15:15, 
Occurrences:
Comparisons:79

BCST:
a:1, b:15, c:15, d:15, e:6, f:15, g:15, h:11, i:9, j:15, k:15, l:15, m:15, n:2, o:3, p:7, q:15, r:5, s:4, t:12, u:15, v:15, w:15, x:15, y:15, z:15, 
GSST:
1:15, 2:15, 3:15, 4:15, 5:15, 6:15, 7:15, 8:15, 9:15, 10:15, 11:15, 12:15, 13:15, 14:15, 15:15, 
Occurrences:
Comparisons:79

BCST:
a:13, b:13, c:10, d:13, e:11, f:13, g:13, h:1, i:7, j:13, k:13, l:13, m:13, n:3, o:4, p:13, q:13, r:8, s:12, t:2, u:9, v:13, w:13, x:13, y:5, z:13, 
GSST:
1:11, 2:13, 3:13, 4:13, 5:13, 6:13, 7:13, 8:13, 9:13, 10:13, 11:13, 12:13, 13:13, 
Occurrences:
Comparisons:121

BCST:
a:4, b:25, c:15, d:22, e:8, f:25, g:25, h:25, i:2, j:25, k:18, l:25, m:25, n:9, o:1, p:25, q:25, r:7, s:25, t:3, u:25, v:25, w:25, x:25, y:25, z:5, 
GSST:
1:9, 2:13, 3:25, 4:25, 5:25, 6:25, 7:25, 8:25, 9:25, 10:25, 11:25, 12:25, 13:25, 14:25, 15:25, 16:25, 17:25, 18:25, 19:25, 20:25, 21:25, 22:25, 23:25, 24:25, 25:25, 
Occurrences:241,739,
Comparisons:139

BCST:
a:5, b:21, c:3, d:6, e:2, f:21, g:21, h:12, i:9, j:21, k:21, l:21, m:21, n:16, o:11, p:21, q:21, r:10, s:1, t:13, u:14, v:21, w:21, x:21, y:21, z:8, 
GSST:
1:1, 2:21, 3:21, 4:21, 5:21, 6:21, 7:21, 8:21, 9:21, 10:21, 11:21, 12:21, 13:21, 14:21, 15:21, 16:21, 17:21, 18:21, 19:21, 20:21, 21:21, 
Occurrences:110,608,1106,
Comparisons:166

BCST:
a:15, b:15, c:15, d:10, e:1, f:3, g:15, h:15, i:15, j:15, k:15, l:11, m:15, n:15, o:4, p:15, q:15, r:6, s:5, t:2, u:9, v:15, w:14, x:15, y:15, z:15, 
GSST:
1:15, 2:15, 3:15, 4:15, 5:15, 6:15, 7:15, 8:15, 9:15, 10:15, 11:15, 12:15, 13:15, 14:15, 15:15, 
Occurrences:
Comparisons:96

BCST:
a:24, b:31, c:4, d:31, e:5, f:19, g:16, h:31, i:2, j:6, k:31, l:31, m:31, n:7, o:1, p:13, q:31, r:12, s:31, t:3, u:31, v:31, w:31, x:31, y:31, z:31, 
GSST:
1:7, 2:31, 3:31, 4:20, 5:31, 6:31, 7:31, 8:31, 9:31, 10:31, 11:31, 12:31, 13:31, 14:31, 15:31, 16:31, 17:31, 18:31, 19:31, 20:31, 21:31, 22:31, 23:31, 24:31, 25:31, 26:31, 27:31, 28:31, 29:31, 30:31, 31:31, 
Occurrences:
Comparisons:87

BCST:
a:20, b:23, c:19, d:23, e:10, f:14, g:1, h:23, i:3, j:23, k:18, l:23, m:23, n:2, o:23, p:8, q:23, r:7, s:23, t:4, u:23, v:23, w:23, x:23, y:23, z:23, 
GSST:
1:20, 2:23, 3:23, 4:23, 5:23, 6:23, 7:23, 8:23, 9:23, 10:23, 11:23, 12:23, 13:23, 14:23, 15:23, 16:23, 17:23, 18:23, 19:23, 20:23, 21:23, 22:23, 23:23, 
Occurrences:
Comparisons:67

BCST:
a:1, b:15, c:15, d:15, e:6, f:15, g:15, h:11, i:9, j:15, k:15, l:15, m:15, n:2, o:3, p:7, q:15, r:5, s:4, t:12, u:15, v:15, w:15, x:15, y:15, z:15, 
GSST:
1:15, 2:15, 3:15, 4:15, 5:15, 6:15, 7:15, 8:15, 9:15, 10:15, 11:15, 12:15, 13:15, 14:15, 15:15, 
Occurrences:
Comparisons:92

BCST:
a:11, b:17, c:17, d:5, e:2, f:17, g:14, h:17, i:13, j:17, k:17, l:6, m:17, n:17, o:8, p:17, q:17, r:1, s:3, t:12, u:4, v:17, w:9, x:17, y:17, z:17, 
GSST:
1:3, 2:17, 3:17, 4:17, 5:17, 6:17, 7:17, 8:17, 9:17, 10:17, 11:17, 12:17, 13:17, 14:17, 15:17, 16:17, 17:17, 
Occurrences:
Comparisons:142

BCST:
a:3, b:8, c:16, d:15, e:5, f:16, g:16, h:16, i:2, j:16, k:16, l:1, m:4, n:16, o:11, p:12, q:16, r:16, s:10, t:16, u:16, v:16, w:16, x:16, y:16, z:16, 
GSST:
1:3, 2:16, 3:16, 4:16, 5:16, 6:16, 7:16, 8:16, 9:16, 10:16, 11:16, 12:16, 13:16, 14:16, 15:16, 16:16, 
Occurrences:
Comparisons:125

BCST:
a:7, b:7, c:7, d:7, e:2, f:7, g:7, h:3, i:1, j:7, k:7, l:7, m:7, n:5, o:6, p:7, q:7, r:7, s:7, t:4, u:7, v:7, w:7, x:7, y:7, z:7, 
GSST:
1:5, 2:7, 3:7, 4:7, 5:7, 6:7, 7:7, 
Occurrences:
Comparisons:261

BCST:
a:4, b:10, c:2, d:10, e:1, f:10, g:10, h:5, i:10, j:10, k:10, l:10, m:10, n:3, o:8, p:10, q:10, r:10, s:10, t:9, u:10, v:10, w:10, x:10, y:10, z:10, 
GSST:
1:4, 2:10, 3:10, 4:10, 5:10, 6:10, 7:10, 8:10, 9:10, 10:10, 
Occurrences:
Comparisons:204

BCST:
a:9, b:29, c:29, d:12, e:1, f:28, g:15, h:6, i:3, j:29, k:29, l:29, m:29, n:10, o:5, p:22, q:29, r:4, s:29, t:7, u:8, v:29, w:29, x:29, y:29, z:2, 
GSST:
1:12, 2:29, 3:29, 4:29, 5:29, 6:29, 7:29, 8:29, 9:29, 10:29, 11:29, 12:29, 13:29, 14:29, 15:29, 16:29, 17:29, 18:29, 19:29, 20:29, 21:29, 22:29, 23:29, 24:29, 25:29, 26:29, 27:29, 28:29, 29:29, 
Occurrences:1092,
Comparisons:116

BCST:
a:11, b:17, c:17, d:5, e:2, f:17, g:14, h:17, i:13, j:17, k:17, l:6, m:17, n:17, o:8, p:17, q:17, r:1, s:3, t:12, u:4, v:17, w:9, x:17, y:17, z:17, 
GSST:
1:3, 2:17, 3:17, 4:17, 5:17, 6:17, 7:17, 8:17, 9:17, 10:17, 11:17, 12:17, 13:17, 14:17, 15:17, 16:17, 17:17, 
Occurrences:
Comparisons:158

BCST:
a:13, b:19, c:19, d:19, e:1, f:19, g:12, h:19, i:19, j:19, k:19, l:19, m:10, n:5, o:18, p:19, q:19, r:2, s:4, t:7, u:3, v:19, w:19, x:19, y:19, z:19, 
GSST:
1:4, 2:19, 3:19, 4:19, 5:19, 6:19, 7:19, 8:19, 9:19, 10:19, 11:19, 12:19, 13:19, 14:19, 15:19, 16:19, 17:19, 18:19, 19:19, 
Occurrences:
Comparisons:118

BCST:
a:11, b:12, c:5, d:12, e:6, f:12, g:12, h:12, i:3, j:12, k:12, l:12, m:12, n:1, o:2, p:10, q:12, r:9, s:12, t:4, u:12, v:12, w:12, x:12, y:12, z:12, 
GSST:
1:11, 2:11, 3:11, 4:11, 5:11, 6:11, 7:11, 8:11, 9:11, 10:11, 11:11, 12:11, 
Occurrences:420,918,1416,
Comparisons:180

BCST:
a:9, b:11, c:8, d:11, e:4, f:10, g:11, h:5, i:2, j:11, k:11, l:11, m:11, n:11, o:11, p:11, q:11, r:3, s:1, t:6, u:11, v:11, w:11, x:11, y:11, z:11, 
GSST:
1:11, 2:11, 3:11, 4:11, 5:11, 6:11, 7:11, 8:11, 9:11, 10:11, 11:11, 
Occurrences:1067,
Comparisons:157

BCST:
a:12, b:13, c:7, d:10, e:8, f:13, g:13, h:13, i:4, j:13, k:13, l:13, m:13, n:11, o:1, p:13, q:13, r:5, s:9, t:3, u:6, v:13, w:13, x:13, y:2, z:13, 
GSST:
1:11, 2:13, 3:13, 4:13, 5:13, 6:13, 7:13, 8:13, 9:13, 10:13, 11:13, 12:13, 13:13, 
Occurrences:
Comparisons:158

BCST:
a:4, b:24, c:24, d:24, e:17, f:8, g:24, h:22, i:2, j:24, k:24, l:11, m:5, n:9, o:1, p:18, q:24, r:6, s:15, t:3, u:24, v:24, w:24, x:24, y:24, z:24, 
GSST:
1:9, 2:13, 3:24, 4:24, 5:24, 6:24, 7:24, 8:24, 9:24, 10:24, 11:24, 12:24, 13:24, 14:24, 15:24, 16:24, 17:24, 18:24, 19:24, 20:24, 21:24, 22:24, 23:24, 24:24, 
Occurrences:631,1129,1627,
Comparisons:193
```