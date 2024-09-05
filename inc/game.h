#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <SDL2/SDL.h>

// Screen dimensions
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Map dimensions
#define MAP_WIDTH 10
#define MAP_HEIGHT 10

// Function declarations
void initGame();
void loadAssets();
void handleInput();
void updateGame();
void renderGame();
void cleanup();

// Map structure
extern int map[MAP_HEIGHT][MAP_WIDTH];

#endif /* GAME_H */