#ifndef ast_hpp
#define ast_hpp


#include <string>
#include <iostream>
#include <map>

//other AST stuff
#include "ast/ast_node.hpp"



extern node *parseAST(std::string filename);

#endif