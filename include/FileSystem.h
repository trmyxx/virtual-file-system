#pragma once
#include <memory>
#include <string>
#include "Directory.h"
#include "FileNode.h"


class FileSystem {
private:
    std::shared_ptr<FileNode> root;
    FileSystem() {}
public:
    static FileSystem* getInstance();
    FileSystem(const FileSystem&) = delete;
    FileSystem& operator= (const FileSystem&) = delete;
    void AddDirectory(Directory* father, std::string name);
    void FileSystem::AddDirectory(Directory* father, Directory* child);
};