#include <string>
#include <memory>
#include "FileNode.h"

void FileNode::addChild(std::shared_ptr<FileNode> child) {
    children.push_back(child);
}

std::shared_ptr<FileNode> dfs(std::shared_ptr<FileNode> root, int neededId) {
    if (root->value->getId() == neededId) return root;
    for (auto& i : root->children) {
        auto result = dfs(i, neededId);
        if (result) return result;
    }
    return nullptr;
}