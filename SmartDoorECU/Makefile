# Trình biên dịch GCC trên Windows (đặc biệt là bản MinGW, TDM-GCC, hoặc MSYS2) không hỗ trợ tốt Unicode trong đường dẫn, đặc biệt là:
# Dấu tiếng Việt: Tài liệu, Bài tập, Cửa, v.v.
# Khoảng trắng: "My Documents", "Bài 1 __ Smart..."

# Compiler and flags
CC = gcc
CFLAGS = -I./include -Wall -Wextra -g

# Directories
SRC_DIR = source
OBJ_DIR = build
BIN_DIR = bin
INC_DIR = include

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
TARGET = $(BIN_DIR)/smart_door_ecu.exe

# Default rule
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $@

# Compiling each .c into build/*.o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean: remove build/ and bin/
clean:
	@powershell -Command "Remove-Item -Recurse -Force -ErrorAction SilentlyContinue $(OBJ_DIR), $(BIN_DIR)"

# Run the program
run: all
	./$(TARGET)

# Phony
.PHONY: all clean run



































# # Compiler and flags
# CC = gcc
# CFLAGS = -I./include -Wall -Wextra -g

# # Directories
# SRC_DIR = source
# INC_DIR = include

# # Files
# SRCS = $(wildcard $(SRC_DIR)/*.c)
# OBJS = $(patsubst %.c,%.o,$(SRCS))
# TARGET = $(SRC_DIR)/smart_door_ecu.exe

# # Default rule
# all: $(TARGET)

# # Linking
# $(TARGET): $(OBJS)
# 	$(CC) $(OBJS) -o $@

# # Compiling
# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Clean build files (Windows)
# clean:
# 	@powershell -Command "Remove-Item -Force -ErrorAction SilentlyContinue $(SRC_DIR)\*.o, $(SRC_DIR)\*.exe, $(INC_DIR)\*.o, $(INC_DIR)\*.exe"

# # Run
# run: all
# 	$(TARGET)

# # Phony targets
# .PHONY: all clean run




