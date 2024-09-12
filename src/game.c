#include "../inc/game.h"

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

int map[MAP_HEIGHT][MAP_WIDTH];
int player_x = 0;  // Player's initial X position
int player_y = 0;  // Player's initial Y position
int e_x = -1;      // Enemy ("e") initial position (off-screen)
int e_y = -1;      // Enemy ("e") initial position (off-screen)
int path[1000][2]; // Array to store the player's path (maximum of 1000 steps)
int step_count = 0; // Number of steps the player has taken

// Function to load the map
void load_map(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening map file");
        exit(EXIT_FAILURE);
    }

    char line[MAP_WIDTH + 2];  // To account for newline and null terminator
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

// Function to display the map with the player's current position
void display_map() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (i == player_y && j == player_x) {
                printf("P ");  // Player's position
            }else if (i == e_y && j == e_x)
            {
                printf("E"); //enemy player
            }
            
             else if (map[i][j] == 1) {
                printf("# ");  // Wall
            } else {
                printf(".");  // Path
            }
        }
        printf("\n");
    }
}

// Function to handle player movement
void move_player(char direction) {
    int new_x = player_x;
    int new_y = player_y;

    if (direction == 'w') new_y--;  // Move up
    if (direction == 's') new_y++;  // Move down
    if (direction == 'a') new_x--;  // Move left
    if (direction == 'd') new_x++;  // Move right

    // Check for collision with walls
    if (new_x >= 0 && new_x < MAP_WIDTH && new_y >= 0 && new_y < MAP_HEIGHT && map[new_y][new_x] == 0) {
        player_x = new_x;
        player_y = new_y;


        // Record the player's path
        path[step_count][0] = player_x;
        path[step_count][1] = player_y;
        step_count++;
    }
}

// Function to move the enemy ("e") along the player's path
void move_enemy() {
    if (step_count > 0) {
        e_x = path[step_count - 1][0];
        e_y = path[step_count - 1][1];
        step_count--;  // Move one step back in the path
    }
}

// Function to check for collision between player and enemy
int check_collision() {
    return (player_x == e_x && player_y == e_y);
}

// Function to restart the game
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

// Main game loop
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_map(argv[1]);

    // Start timer for enemy appearance
    time_t start_time = time(NULL);

    // Game loop
    char input;
    while (1) {
        system("clear");  // Clear the screen (use "cls" on Windows)
        display_map();

        // Check if 3 minutes have passed
        if (difftime(time(NULL), start_time) >= 180 && e_x == -1 && e_y == -1) {
            e_x = player_x;
            e_y = player_y;  // Spawn enemy at the player's starting position
        }
        // Move the enemy along the player's path if they have started moving
        if (e_x != -1 && e_y != -1) {
            move_enemy();
        }

        // Check for collision
        if (check_collision()) {
            restart_game();
            continue;  // Skip the rest of the loop and restart the game
        }

        // Check for win condition (e.g., reaching bottom-right corner)
        if (player_x == MAP_WIDTH - 1 && player_y == MAP_HEIGHT - 1) {
            printf("You win!\n");
            break;
        }

        // Get player input
        printf("Move (w/a/s/d): ");
        input = getchar();
        getchar();  // Consume newline

        // Move player based on input
        move_player(input);
    }

    return 0;
}