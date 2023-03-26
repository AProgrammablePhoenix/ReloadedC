#pragma once

class Node {
public:
    Node(int line);
    int getline() const;
    virtual void accept(class Visitor& v) = 0;
    virtual void delete_mem() { };
private:
    int line;
};