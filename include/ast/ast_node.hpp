#ifndef ast_node
#define ast_node

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>


typedef node* nodePtr;

class node
{
    
public:
//public functions to be inherited
    node(std::vector<nodePtr> _branches); //basic constructor
    node();


    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const;
    virtual void generateTypeMIPS(std::ostream &dst, Context &context, int destReg, enum Specifier type) const;



protected:
    std::vector<nodePtr> branches;


    

};

#endif