CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I include

all : bin/c_compiler

src/parser.tab.cpp src/parser.tab.hpp : src/parser.y
	bison -v -d src/parser.y -o src/parser.tab.cpp

src/lexer.yy.cpp : src/lexer.flex src/parser.tab.hpp
	flex -o src/lexer.yy.cpp  src/lexer.flex


#links
bin/c_compiler : src/c_compiler.o src/lexer.yy.o src/parser.tab.o 
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/c_compiler $^
	

clean :
	rm -rf bin/*
	rm -f src/*.tab.cpp
	rm -f src/*.yy.c
	rm -f src/*.yy.cpp
	rm -f src/*.output
	rm -f src/*.tab.hpp
	rm -f src/*.o
	rm -f working_dir/*