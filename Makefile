CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I include

all : bin/c_compiler

src/parser.tab.cpp src/parser.tab.hpp : src/parser.y
	bison -v -d src/parser.y -o src/parser.tab.cpp

src/lexer.yy.cpp : src/lexer.flex
	flex -o src/lexer.yy.cpp  src/lexer.flex

bin/c_compiler : src/c_compiler.cpp src/lexer.yy.cpp src/parser.tab.cpp
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/c_compiler $^
	

clean :
	rm bin/*
	rm src/*.tab.cpp
	rm src/*.yy.cpp
	rm src/*.o