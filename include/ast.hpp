#ifndef ast_hpp
#define ast_hpp


#include <string>
#include <iostream>
#include <map>
#include <fstream>

//other AST stuff
#include "ast/ast_node.hpp"
#include "ast/ast_root.hpp"
#include "ast/context.hpp"

#include "ast/literals/ast_float.hpp"
#include "ast/literals/ast_int.hpp"
#include "ast/literals/ast_string.hpp"
#include "ast/literals/ast_char.hpp"
#include "ast/ast_sizeof.hpp"

#include "ast/ast_type.hpp"
#include "ast/ast_ident.hpp"

#include "ast/functions/ast_def_function.hpp"
#include "ast/ast_statement_list.hpp"


#include "ast/ast_assign.hpp"
#include "ast/ast_return.hpp"
#include "ast/functions/ast_function_call.hpp"

#include "ast/ast_declarator.hpp"
#include "ast/ast_init_declarator.hpp"
#include "ast/ast_function_declarator.hpp"
#include "ast/ast_declaration.hpp"

#include "ast/ast_add_op.hpp"
#include "ast/ops/ast_sub_op.hpp"

#include "node_vector_parser.hpp"




extern node *parseAST(std::string filename);
extern context Context;

#endif