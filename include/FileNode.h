#pragma once
#include <memory>
#include <vector>
#include "Directory.h"

struct FileNode {
    std::shared_ptr<Directory> value;
    std::vector<std::shared_ptr<FileNode>> children;

    FileNode(Directory& val) : value(std::make_shared<Directory>(val)) {}

    void addChild(std::shared_ptr<FileNode> child);
};

std::shared_ptr<FileNode> dfs(std::shared_ptr<FileNode> root, int neededId);