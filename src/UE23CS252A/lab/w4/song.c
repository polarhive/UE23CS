#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a song node
typedef struct SongNode {
    char title[100];
    int duration;
    struct SongNode *prev;
    struct SongNode *next;
} SongNode;

// Function to add a new song to the playlist
SongNode *addSong(SongNode *playlist, const char *title, int duration) {
    SongNode *newSong = (SongNode *)malloc(sizeof(SongNode));
    strcpy(newSong->title, title);
    newSong->duration = duration;
    newSong->prev = NULL;
    newSong->next = NULL;

    if (playlist == NULL) {
        playlist = newSong;
    } else {
        SongNode *current = playlist;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newSong;
        newSong->prev = current;
    }
    return playlist;
}

// Function to find a song by title
SongNode *findSong(SongNode *playlist, const char *title) {
    SongNode *current = playlist;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to play the enchanted playlist
void playPlaylist(SongNode *startSong, int totalTime) {
    SongNode *current = startSong;
    int forward = 1; // 1 for forward, -1 for backward

    while (totalTime > 0) {
        if (totalTime - current->duration >= 0) {
            printf("%s\n", current->title);
        }
        totalTime -= current->duration;

        if (forward == 1) {
            if (current->next != NULL) {
                current = current->next;
            } else {
                forward = -1; // Reverse direction
                current = current->prev;
            }
        } else {
            if (current->prev != NULL) {
                current = current->prev;
            } else {
                forward = 1; // Reverse direction
                current = current->next;
            }
        }
    }
}

int main() {
    SongNode *playlist = NULL;

    // Add songs to the playlist
    int n;
    scanf("%d", &n);
    getchar(); // Consume the newline character left by scanf

    while (n > 0) {
        char title[100];
        int duration;
        scanf("%s %d", title, &duration);
        playlist = addSong(playlist, title, duration);
        n--;
    }

    // Set total listening time
    int totalTime;
    scanf("%d", &totalTime);
    getchar(); // Consume the newline character left by scanf

    // Select the beginning song
    char songTitle[100];
    scanf("%s", songTitle);

    SongNode *startSong = findSong(playlist, songTitle);
    if (startSong != NULL) {
        playPlaylist(startSong, totalTime);
    } else {
        printf("Starting song not found.\n");
    }

    // Free memory
    SongNode *current = playlist;
    while (current != NULL) {
        SongNode *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
