CC=cc

SRC_DIR=./

SRC_EXT=cpp

INCLUDE_DIR=./

OBJ_DIR=./

CFLAGS=-lstdc++ -std=c++11

WFLAGS=-Wall -Wextra

EXE=Program05

SOURCES := $(wildcard $(SRC_DIR)/*.$(SRC_EXT))
OBJECTS := $(SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/%.o)

all: $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(EXE)

$(OBJECTS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(WFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm $(OBJECTS) $(EXE) -v
