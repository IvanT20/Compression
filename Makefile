CC := g++
CXX_FLAGS := -std=c++17 -Wall -Wextra -pedantic

SRC_DIR := src

TARGET := compressor

.PHONY: all

all: $(TARGET)

$(TARGET):  $(SRC_DIR)/main.cpp $(SRC_DIR)/parser.cpp $(SRC_DIR)/parser.hpp \
			$(SRC_DIR)/huffmanTree.cpp $(SRC_DIR)/huffmanTree.hpp $(SRC_DIR)/compressor.cpp $(SRC_DIR)/compressor.hpp \
			$(SRC_DIR)/decompressor.cpp $(SRC_DIR)/decompressor.hpp
	$(CC) $(CXX_FLAGS) $(SRC_DIR)/main.cpp $(SRC_DIR)/parser.cpp $(SRC_DIR)/huffmanTree.cpp $(SRC_DIR)/compressor.cpp $(SRC_DIR)/decompressor.cpp -o $(TARGET)