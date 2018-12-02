CXX ?= g++

# path #
SRC_PATH = src
BUILD_PATH = build
BIN_PATH = $(BUILD_PATH)/bin

# executable # 
BIN_NAME = orderBook

# extensions #
SRC_EXT = cpp

CXXFLAGS = $(COMPILE_FLAGS)

SOURCES = $(shell find $(SRC_PATH) -name '*.$(SRC_EXT)' | sort -k 1nr | cut -f2-)
# Set the object file names, with the source directory stripped
# from the path, and the build path prepended in its place
OBJECTS = $(SOURCES:$(SRC_PATH)/%.$(SRC_EXT)=$(BUILD_PATH)/%.o)

# flags #
COMPILE_FLAGS = -std=c++14 -Wall -Wextra -g
INCLUDES = -I include/ -I /usr/local/include
LIBS =

all: $(BIN_PATH)/$(BIN_NAME)
	@echo "Making symlink: $(BIN_NAME) -> $<"
	@$(RM) $(BIN_NAME)
	@ln -s $(BIN_PATH)/$(BIN_NAME) $(BIN_NAME)

clean:
	@echo "Deleting $(BIN_NAME) symlink"
	@$(RM) $(BIN_NAME)
	@echo "Deleting directories"
	@$(RM) -r $(BUILD_PATH)
	@$(RM) -r $(BIN_PATH)

.PHONY: dirs
dirs:
	@echo "Creating directories"
	@mkdir -p $(dir $(OBJECTS))
	@mkdir -p $(BIN_PATH)

# Creation of the executable
$(BIN_PATH)/$(BIN_NAME): dirs $(OBJECTS)
	@echo "Linking: $@"
	$(CXX) $(OBJECTS) -o $@

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.$(SRC_EXT)
	@echo "Compiling: $< -> $@"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@