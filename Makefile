CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I include

all : bin/c_compiler

src/maths_parser.tab.cpp src/maths_parser.tab.hpp : src/compiler_parser.y
	bison -v -d src/compiler_parser.y -o src/compiler_parser.tab.cpp

src/compiler_lexer.yy.cpp : src/compiler_lexer.flex src/compiler_parser.tab.hpp
	flex -o src/compiler_lexer.yy.cpp  src/compiler_lexer.flex

	
bin/c_compiler : src/c_compiler.o src/compiler_parser.tab.o src/compiler_lexer.yy.o src/compiler_parser.tab.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/eval_expr $^


clean :
	rm src/*.o
	rm bin/*
	rm src/*.tab.cpp
	rm src/*.yy.cpp