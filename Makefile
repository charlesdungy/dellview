CXX       := g++
TARGET    := dellview
SFML_DIR  := /opt/homebrew/Cellar/sfml/2.6.1

CXX_FLAGS := -std=c++17 -O3 -Wall -Wextra -Wunreachable-code
INCLUDES  := -I./src -I$(SFML_DIR)/include
LDFLAGS   := -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -L$(SFML_DIR)/lib -O3

TGTDIR    := bin
SRCDIR    := src
OBJDIR    := obj
SRC_FILES := $(shell find $(SRCDIR) -type f -name *.cpp)
OBJ_FILES := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SRC_FILES:.cpp=.o))

#
# Build steps.
#
BUILDALL += make_dirs
BUILDALL += what_are_we_building
BUILDALL += $(TARGET)
all : $(BUILDALL)

what_are_we_building :
	$(info *********************************)
	$(foreach OBJ, $(OBJ_FILES), $(info $(\t) $(OBJ)))
	$(info *********************************)
	$(foreach SRC, $(SRC_FILES), $(info $(\t) $(SRC)))
	$(info *********************************)

make_dirs :
	$(info Attempting to make $(OBJDIR) directory. $(shell mkdir -p $(OBJDIR)))
	$(info Attempting to make $(TGTDIR) directory. $(shell mkdir -p $(TGTDIR)))

# Link the OBJ_FILES to the TARGET.
$(TARGET) : $(OBJ_FILES)
	$(CXX) $(LDFLAGS) -o ./$(TGTDIR)/$(TARGET) $^

# Build the OBJ_FILES.
$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) -c $(CXX_FLAGS) $(INCLUDES) -o $@ $<

#
# Run steps.
#
run: $(TARGET)
	cd $(TGTDIR) && ./$(TARGET) && cd ..

#
# Clean steps.
#
.PHONY : clean
clean:
	rm -rf ./bin ./obj
