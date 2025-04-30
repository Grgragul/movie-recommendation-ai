#include <stdio.h> 
#include <string.h> 
#define MOVIE_COUNT 4 
typedef struct {     char title[50];     int action;     int comedy;     int drama;     int sci_fi; 
    float score; // Similarity score 
} Movie; typedef struct {     int action;     int comedy;     int drama;     int sci_fi; 
} UserProfile; 
 
void computeScores(Movie movies[], UserProfile user) {     for (int i = 0; i < MOVIE_COUNT; i++) {         movies[i].score = (movies[i].action * user.action) + 
                          (movies[i].comedy * user.comedy) + 
                          (movies[i].drama * user.drama) + 
                          (movies[i].sci_fi * user.sci_fi); 
    } 
} 
 
void sortMovies(Movie movies[]) {     for (int i = 0; i < MOVIE_COUNT - 1; i++) {         for (int j = i + 1; j < MOVIE_COUNT; j++) {             if (movies[j].score > movies[i].score) {                 Movie temp = movies[i];                 movies[i] = movies[j];                 movies[j] = temp; 
            } 
        } 
    } 
} int main() { 
    Movie movies[MOVIE_COUNT] = { 
        {"The Matrix", 1, 0, 0, 1}, 
        {"The Notebook", 0, 0, 1, 0}, 
        {"Interstellar", 1, 0, 1, 1}, 
        {"Superbad", 0, 1, 0, 0} 
    }; 
UserProfile user = {1, 0, 0, 1};      computeScores(movies, user);     sortMovies(movies);     printf("Recommended Movies:\n");     for (int i = 0; i < MOVIE_COUNT; i++) { 
        printf("%s (Score: %.1f)\n", movies[i].title, movies[i].score); 
    }     return 0;
}
