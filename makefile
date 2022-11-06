.PHONY: dirs clean 

CXXFLAGS = -Wfatal-errors
SRC = $(shell ls src/*.h src/**/*.h)
TEST = $(shell ls test/*.h test/**/*.h)
OBJ = obj/bfs_iterator_factory.o obj/dfs_iterator_factory.o

all: dirs bin/ut_all

bin/ut_all: test/ut_main.cpp $(OBJ) $(TEST) $(SRC)
	g++ -o $@ $< $(OBJ) -lgtest -lpthread -std=c++17 $(CXXFLAGS)

obj/%.o: src/iterator/factory/%.cpp
	g++ -o $@ -c $< -std=c++17 $(CXXFLAGS)

test: all
	bin/ut_all

dirs:
	mkdir -p bin obj

clean:
	rm -f bin/* obj/*
