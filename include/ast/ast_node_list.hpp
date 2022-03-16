#include "ast_node.hpp"

class node_list
{
    private:
        std::vector <nodePtr> list;

    public:
        node_list(std::vector <nodePtr> nodes)
        {
            for (uint32_t i = 0; i < nodes.size(); i++)
            {
                list.push_back(nodes[i]);
                delete nodes[i];
            }
        }
        void append(nodePtr _node)
        {
            list.push_back(_node);
        }
};