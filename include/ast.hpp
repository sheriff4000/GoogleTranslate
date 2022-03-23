#ifndef ast_hpp
#define ast_hpp


#include <string>
#include <iostream>
#include <map>
#include <fstream>

//other AST stuff
#include "ast/ast_node.hpp"

#include "ast/literals/ast_float.hpp"
#include "ast/literals/ast_int.hpp"
#include "ast/literals/ast_string.hpp"

#include "ast/ast_type.hpp"
#include "ast/ast_ident.hpp"
#include "ast/context.hpp"
#include "ast/functions/ast_def_function.hpp"
#include "ast/ast_statement_list.hpp"

#include "node_vector_parser.hpp"




extern node *parseAST(std::string filename);

#endif