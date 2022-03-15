#ifndef ast_hpp
#define ast_hpp

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>

#include "ast/ast_node.hpp"

#include "ast/ast_declarations.hpp"
#include "ast/functions/ast_function_call.hpp"
#include "ast/functions/ast_function_def.hpp"
//#include "ast/context.hpp"


// struct context {

//     std::map<std::string, int> var_list; //maps variable names to memory address
//     std::map<std::string, std::string> var_type; // maps variables to their types

// }

extern const nodePtr parseAST();

#endif
