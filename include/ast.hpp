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
#include "ast/context.hpp"
#include "ast/literals/ast_float_literal.hpp"
#include "ast/literals/ast_int_literal.hpp"
#include "ast/literals/ast_string_literal.hpp"


extern const nodePtr parseAST(std::string filename);

#endif
