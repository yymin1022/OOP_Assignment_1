CC = g++
CXXFLAGS = -Wall -O2

OBJ_DIR = ./obj
SRC_DIR = ./src
OUT_DIR = ./out

INCLUDE = -Iinclude/
TARGET = StudentManage

SRCS = $(notdir $(wildcard $(SRC_DIR)/*.cpp))
OBJS = $(patsubst %.o,$(OBJ_DIR)/%.o,$(SRCS:.cpp=.o))

all: $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir ./obj 2> /dev/null || true
	mkdir ./out 2> /dev/null || true
	$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(OUT_DIR)/$(TARGET)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR)
