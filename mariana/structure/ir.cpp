/*
 *        (C) COPYRIGHT LeiNao Limited.
 *             ALL RIGHTS RESERVED
 *
 * File       : structure/ir.cpp
 * Authors    : wangliquan@zkln
 * Create Time: 2022-12-28:08:55:41
 * Description:
 * 
 */

#include <structure/ir.h>
#include <core/utils/logging.h>

namespace mariana {

Node::EdgeEnd::EdgeEnd(const Node* node, int index) noexcept : node_(node),
    index_(index) {}

Node::EdgeEnd::EdgeEnd(const Node* node) noexcept : EdgeEnd(node, INT_MAX) {}

Node* Graph::make_node() {
    MCHECK(nodes_.size() < static_cast<unsigned int>(std::numeric_limits<int>::max()));
    std::unique_ptr<Node> new_node(new Node(nodes_.size(), *this));
    Node* node{new_node.get()};
    nodes_.push_back(std::move(new_node));
    ++num_of_nodes_;
    return node;
}

Node& Graph::add_node(const std::string& name, const std::string& op_type) {
    Node* node = make_node();
    node->init(name, op_type);
    return *node;
}

void Scope::init(Graph *graph) {
    node_name_map.clear();
    for (auto it : graph->nodes()) {
        node_name_map.insert({it->name(), it});
    }
}

} // namespace mariana
