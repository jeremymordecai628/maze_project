# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -Werror -Wextra -pedantic

# Libraries
LIBS = -lSDL2

# Source Files
SRCS = 

# Object Files (compiled source files)
OBJS = $(SRCS:.c=.o)

# Executable Name
EXEC = maze_game

# Default Target
all: $(EXEC)

# Link the compiled object files to create the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) $(LIBS)

# Compile each source file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove generated files
clean:
	rm -f $(OBJS) $(EXEC)

# Phony Targets (not actual files)
.PHONY: all clean
