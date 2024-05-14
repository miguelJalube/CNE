CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
SRC_DIR = src
BUILD_DIR = build
EXEC = main

all: $(EXEC)

$(EXEC): $(BUILD_DIR)/main.o
    $(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c | $(BUILD_DIR)
    $(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
    mkdir -p $(BUILD_DIR)

clean:
    rm -rf $(BUILD_DIR)

.PHONY: all clean
