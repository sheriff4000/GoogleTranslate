#ifndef ast_node_list_hpp
#define ast_node_list_hpp
#include "ast/ast_node.hpp"

class node_list
{
    private:
        std::vector <node_ptr> list;

    public:
        node_list(std::vector <node_ptr> nodes)
        {
            for (uint32_t i = 0; i < nodes.size(); i++)
            {
                list.push_back(nodes[i]);
                delete nodes[i];
            }
        }
        void append(node_ptr _node)
        {
            list.push_back(_node);
        }
};
#endif