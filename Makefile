CXX	:= clang++
CXX_FLAGS	:= -std=gnu++11 -ggdb

BIN	:= bin
SRC	:= src

EXECUTABLE_T := testcards
EXECUTABLE := game

all: $(BIN)/$(EXECUTABLE)
test: $(BIN)/$(EXECUTABLE_T)

runtest: clean test
$(BIN)/$(EXECUTABLE_T): $(SRC)/*.c*
	$(CXX) $(CXX_FLAGS) $^ -o $@ -D _CARDGAME_DEV=1
	$@

clean:
	-rm $(BIN)/*