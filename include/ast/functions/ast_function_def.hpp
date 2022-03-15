#include<iostream>
#include <vector>
#include <string>

class function_def : public node
{
    //WHEN YOU MAKE THIS OBECT YOU NEED TO PUT ITS POINTER INTO CONTEXT
    //DURING PARSING PERHAPS
    //we have inherited branches, wbout arguments
    // 
private:
    std::vector<nodePtr> args;
    std::string name;
    //std::vector<nodePtr> statements;
public:
    
    function_def(std::vector<nodePtr> _args)
    {
        args = _args; //I think it copies instead of reference
    }
    function_def() //overloading
    {
        args = {}; 
    }
    void add_statement(nodePtr statement)
    {
        branches.push_back(statement);
    }

    void gen_mips(std::ostream &dst, context &Context) const override
    {
        int argSize = args.size();//multiply by 4 or 8 or something

        //PROLOGUE
        dst << name << ":" << std::endl;
        dst << "addiu   $sp,$sp,-8" << std::endl;
        dst << "sw      $fp,4($sp)" << std::endl;
        dst << "move    $fp,$sp" << std::endl;

        //DO SOME STUFF IN THE MIDDLE INNIT
        // for (int i = 0; i < branches.size(); i++)
        // {
        //     branches->gen_mips;
        // }

        //EPILOGUE
        dst << "move    $sp,$fp" << std::endl;
        dst << "lw      $fp,4($sp)" << std::endl;
        dst << "addiu   $sp,$sp,8" << std::endl;
        dst << "j       $31" << std::endl;
        dst << "nop" << std::endl;

        //assign values to each argument?
        //use context to retrieve baindings, in future could use it for scope, but tbh i don't know if we'll get to that, 
        //i.e. just assume everything happens in one function

        
    }

    //visualise
    // void visualise()const override {
    //     std::cout << "function definition" << std::endl;
    //     for(int i = 0; i < args.size()){
    //         args[i]->visualise();
    //     }
    // }

    virtual ~function_def();
    



};