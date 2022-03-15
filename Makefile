CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I include

all : bin/c_compiler

src/bare_parser.tab.cpp src/bare_parser.tab.hpp : src/bare_parser.y
	bison -v -d src/bare_parser.y -o src/bare_parser.tab.cpp

src/compiler_lexer.yy.cpp : src/compiler_lexer.flex src/compiler_parser.tab.hpp
	flex -o src/compiler_lexer.yy.cpp  src/compiler_lexer.flex

	
bin/c_compiler : src/c_compiler.o src/compiler_parser.tab.o src/compiler_lexer.yy.o src/compiler_parser.tab.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/c_compiler $^


clean :
	rm src/*.o
	rm bin/*
	rm src/*.tab.cpp
	rm src/*.yy.cpp