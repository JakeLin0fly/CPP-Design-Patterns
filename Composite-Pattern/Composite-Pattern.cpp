//
// Created by JakeLin on 2021/11/18.
//
#include <bits/stdc++.h>
using namespace std;

/**
 * 实现一个文件管理工具，支持对文件夹和文件的创建和删除功能，并且提供 tree 接口显示文件系统结构。
 * 设计类图如下：https://gitee.com/jakel-in/images/raw/master/2021-11/Composite-Pattern-Example.png
 */

// 抽象部件：抽象文件结点
class IFile {
public:
    IFile(string name) : fileName(name) {}
    virtual ~IFile() = default;
    virtual void touch(IFile *file) = 0;
    virtual void remove(IFile *file) = 0;
    virtual void tree(int depth) {
        cout << string(depth * 2, '-') << fileName << endl;
    };
protected:
    string fileName;
};

// 容器部件：文件夹
class Folder : public IFile {
public:
    Folder(string name) : IFile(name) {}
    virtual void touch(IFile *file) {
        childs.insert(file);
        cout << fileName << "childs size = " << childs.size() <<endl;
    }
    virtual void remove(IFile *file) {
        childs.erase(file);
    }
    virtual void tree(int depth) {
        IFile::tree(depth);
        for (IFile *file : childs) {
            file->tree(depth + 1);
        }
    }

private:
    unordered_set<IFile*> childs;
};

// 叶子：文件
class File : public IFile {
public:
    File(string name) : IFile(name) {}
    virtual void touch(IFile *file) {
        cout << "Error! Cannot touch from a file." << endl;
    }
    virtual void remove(IFile *file) {
        cout << "Error! Cannot remove from a file." << endl;
    }
    virtual void tree(int depth) {
        IFile::tree(depth);
    }
};

// 测试
int main() {
    IFile *root = new Folder("root");
    IFile *readme = new File("README.md");
    root->touch(readme);

    IFile *cs = new Folder("Computer_Science");
    root->touch(cs);

    IFile *csapp = new File("CSAPP.pdf");
    IFile *apue = new File("apue.pdf");
    cs->touch(csapp);
    cs->touch(apue);

    cout << "======= tree Computer_Science=========\n";
    cs->tree(1);
    cout << "\n======= tree root=========\n";
    root->tree(1);

    cout << "\n======= remove CSAPP.pdf =========\n";
    cs->remove(csapp);
    root->tree(1);

    return 0;
}