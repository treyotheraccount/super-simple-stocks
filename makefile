CC_FILES := $(wildcard src/*.cc)
OBJ_FILES := $(addprefix build/,$(notdir $(CC_FILES:.cc=.o)))
LD_FLAGS := -O -pg -g
CC_FLAGS := -O2 -std=c++11 -Wall

super-simple-stocks: $(OBJ_FILES)
	g++ $(LD_FLAGS) -o bin/$@ $^

build/%.o: src/%.cc
	g++ $(CC_FLAGS) -c -o $@ $<

clean:
	rm -rf build/*
