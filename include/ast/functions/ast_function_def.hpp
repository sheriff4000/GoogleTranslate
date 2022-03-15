#include<iostream>
#include <vector>
#include <string>

class function_def : public node
{
    //WHEN YOU MAKE THIS OBECT YOU NEED TO PUT ITS POINTER INTO CONTEXT
    //DURING PARSING PERHAPS
    //we have inherited branches, wbout arguments
private:
    std::vector<nodePtr> args;
    std::string name;
public:
    function_def(std::vector<nodePtr> _args)
    {
        args = _args; //I think it copies instead of reference
    }
    function_def() //overloading
    {
        args = {}; 
    }

    void gen_mips()
    {
        //assign values to each argument?
        //how to retrieve bindings

        //need to evaluate every branch
        
    }

    //visualise
    void visualise() {
        std::cout << "function definition" << std::endl;
        for(int i = 0; i < args.length()){
            args[i].visualise();
        }
    } const override;

    virtual ~function_def();
    



};