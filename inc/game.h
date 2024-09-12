#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <SDL2/SDL.h>

// Screen dimensions
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#include <stdio.h>
#include <stdlib.h>

#define MAP_WIDTH 10   // Set map dimensions here
#define MAP_HEIGHT 10

extern int map[MAP_HEIGHT][MAP_WIDTH];  // Declare the map array

void load_map(const char *filename);    // Function to load map from file
void display_map();                     // Function to display the map
void move_player(char direction);       // Function to handle player movement

// Map structure
extern int map[MAP_HEIGHT][MAP_WIDTH];

#endif /* GAME_H */