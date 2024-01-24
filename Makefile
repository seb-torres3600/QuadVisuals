# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++20 -Wall -Wextra -I /opt/homebrew/include/nlohmann

# Source files
SRCS = *.cpp

# Header files
INCS = *.hpp

# Output binary
OUT = main

# GLFW library and OpenGL framework for macOS
LIBS = -lglfw -framework OpenGL -Wno-deprecated-declarations

all: $(OUT)

$(OUT): $(SRCS) $(INCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(OUT) $(LIBS)

clean:
	rm -f $(OUT)

