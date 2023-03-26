#include "node.hpp"

Node::Node(int line) : line(line) {}

int Node::getline() const {
    return this->line;
}