#include <string>
#include <memory>
#include "FileSystem.h"

FileSystem* FileSystem::getInstance() {
    static FileSystem instance;
    return &instance;
}

FileSystem::FileSystem(const FileSystem&) = delete;
FileSystem& FileSystem::operator= (const FileSystem&) = delete;

void FileSystem::AddDirectory(Directory* father, std::string name) {
    auto newDir = std::make_shared<Directory>(name);
    auto newNode = std::make_shared<FileNode>(*newDir);
    if (!root) {
        root = newNode;
        return;
    }
    auto parent = dfs(root, father->getId());
    if (parent) {
        parent->addChild(newNode);
    }
}

void FileSystem::AddDirectory(Directory* father, Directory* child) {
    if (!root) {
        root = std::make_shared<FileNode>(*child);
        return;
    }
    auto parent = dfs(root, father->getId());
    if (parent) {
        parent->addChild(std::make_shared<FileNode>(*child));
    }
}