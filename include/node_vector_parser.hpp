#ifndef node_vector_parser
#define node_vector_parser

#include <vector>
#include "ast/ast_node.hpp"

typedef std::vector<node_ptr> node_vector;
typedef node_vector *node_vector_ptr;


inline node_vector_ptr new_vector(node_ptr node)
{
    //we want to make a new vector (dynamically) and return its pointer after adding the passed node
    node_vector_ptr out = new node_vector;
    out->push_back(node);
    return out;
}


#endif