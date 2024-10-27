#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int mid;
    char mname[100];
} Movie;

void read_csv(const char *filename, Movie movies[], int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    
    char buffer[128];
    *count = 0;
    fgets(buffer, sizeof(buffer), file); // Skip header
    while (fgets(buffer, sizeof(buffer), file)) {
        sscanf(buffer, "%d,%99[^\n]", &movies[*count].mid, movies[*count].mname);
        (*count)++;
    }

    fclose(file);
}

void write_csv(const char *filename, Movie movies[], int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "mid,mname\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s\n", movies[i].mid, movies[i].mname);
    }

    fclose(file);
}

void bubble_sort(Movie movies[], int count, int (*compare)(Movie, Movie)) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (compare(movies[j], movies[j + 1]) > 0) {
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}

int compare_by_id(Movie a, Movie b) {
    return a.mid - b.mid;
}

int compare_by_name(Movie a, Movie b) {
    return strcmp(a.mname, b.mname);
}

void display_menu() {
    printf("Menu:\n");
    printf("1. Sort by Movie ID\n");
    printf("2. Sort by Movie Name\n");
    printf("3. Exit\n");
    printf("Enter your choice (1-3): ");
}

int main() {
    Movie movies[100];
    int count;
    read_csv("movies.csv", movies, &count);

    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubble_sort(movies, count, compare_by_id);
                write_csv("sorted.csv", movies, count);
                printf("Movies sorted by movie ID\n");
                break;
            case 2:
                bubble_sort(movies, count, compare_by_name);
                write_csv("sorted.csv", movies, count);
                printf("Movies sorted by Name\n");
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
