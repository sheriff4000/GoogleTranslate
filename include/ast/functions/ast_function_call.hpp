#ifndef ast_function_call
#define ast_function_call

#include "ast/ast_node.hpp"

class function_call : public node {
    public :
        function_call(nodePtr id, std::vector<nodePtr> params);
        function_call(nodePtr id);

        virtual ~function_call();

}




#endif
