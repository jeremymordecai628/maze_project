#include "../inc/game.h"

// Global variables
int map[MAP_HEIGHT][MAP_WIDTH];
int player_x = 0;
int player_y = 0;
int e_x = -1;
int e_y = -1;
int path[1000][2];
int step_count = 0;

// Function implementations
void load_map(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening map file");
        exit(EXIT_FAILURE);
    }

    char line[MAP_WIDTH + 2]; // To account for newline and null terminator
    for (int i = 0; i < MAP_HEIGHT; i++) {
        if (fgets(line, sizeof(line), file)) {
            for (int j = 0; j < MAP_WIDTH; j++) {
                if (line[j] == '1' || line[j] == '0') {
                    map[i][j] = line[j] - '0';  // Convert char to int
                }
            }
        }
    }

    fclose(file);
}

void display_map() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (i == player_y && j == player_x) {
                printf("P ");  // Player's position
            } else if (i == e_y && j == e_x) {
                printf("E ");  // Enemy's position
            } else if (map[i][j] == 1) {
                printf("# ");  // Wall
            } else {
                printf(". ");  // Path
            }
        }
        printf("\n");
    }
}

void move_player(char direction) {
    int new_x = player_x;
    int new_y = player_y;

    if (direction == 'w') new_y--;  // Move up
    if (direction == 's') new_y++;  // Move down
    if (direction == 'a') new_x--;  // Move left
    if (direction == 'd') new_x++;  // Move right

    if (new_x >= 0 && new_x < MAP_WIDTH && new_y >= 0 && new_y < MAP_HEIGHT && map[new_y][new_x] == 0) {
        player_x = new_x;
        player_y = new_y;
        path[step_count][0] = player_x;
        path[step_count][1] = player_y;
        step_count++;
    }
}

void move_enemy() {
    if (step_count > 0) {
        e_x = path[step_count - 1][0];
        e_y = path[step_count - 1][1];
        step_count--;  // Move one step back in the path
    }
}

int check_collision() {
    return (player_x == e_x && player_y == e_y);
}

void restart_game() {
    printf("Game Over! Restarting...\n");
    player_x = 0;
    player_y = 0;
    e_x = -1;
    e_y = -1;
    step_count = 0;
    memset(path, 0, sizeof(path));  // Clear the recorded path
    sleep(2);  // Wait for 2 seconds before restarting
}
