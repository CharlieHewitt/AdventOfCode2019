#include <string>
#include <vector>

class OrbitTree{
    OrbitNode root;
    bool addNode(OrbitNode newNode, std::string parentId);
    int checksum();
};

class OrbitNode{
    std::string id;
    int depth;
    std::vector<OrbitNode> children;

    OrbitNode(std::string id, int depth)
    int getDepth() { return this.depth; }
    int getId() { return this.depth; }
    int getNumChildren() { return this.children.size(); }
    int addChild(OrbitNode child);
};

// overloading == for easy comparison
bool operator==(const OrbitNode& lhs, const OrbitNode& rhs)
{
    return lhs.id == rhs.id
}

