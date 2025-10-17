# Virtual File System (VFS)

This project simulates a file system with the ability to create, rename, and delete files and directories.

## Class Structure
- **File**: Represents a file.
- **Directory**: Represents a directory that can contain files.
- **FileSystem**: Manages the entire file system.

## How to Use

1. Initialize the file system via `FileSystem::getInstance()`.
2. Create directories and files, then add them to the system.
3. Use the provided methods to add or remove files from directories.

Example:
```cpp
FileSystem* fs = FileSystem::getInstance();
Directory* root = new Directory("root");
fs->AddDirectory(nullptr, root);
File file1("file1.txt", 10);
root->add(file1);
