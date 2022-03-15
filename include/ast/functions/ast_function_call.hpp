#ifndef ast_function_call
#define ast_function_call

#include "ast/ast_node.hpp"

class function_call : public node {
private: 
    nodePtr def; //points to the definition object, perhaps we could use the prexisting branches variable inherited from node class.
    std::vector<nodePtr> args;
public :
    function_call(nodePtr _def, std::vector<nodePtr> _args)
    {
        def = _def;
        args = _args;
    }

    void gen_mips()
    {
        //we access the function definition and pass it the args we have for this specfic call?
        
        def->gen_mips(args);
        //so all the making a new stack frame, frame pointers, return pointers etc. is written in the function_def class function gen_mips
    }

};




#endif
