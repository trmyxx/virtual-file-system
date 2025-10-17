#include <iostream>
#include "FileSystem.h"

int main()
{
    FileSystem* fs = FileSystem::getInstance();
    Directory* root = new Directory("root");
    fs->AddDirectory(nullptr, root);
    File file1("file1.txt", 10);
    root->add(file1);

    return 0;
}