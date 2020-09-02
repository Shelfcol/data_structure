#ifndef HFTREE_H
#define HFTREE_H

#include <iostream>
#include <string>
using namespace std;

class hfTree
{
private:
    struct Node//保存hfTree的结构体，里面包含数据，以及父节点、左右子节点的位置，因为这个存储不需要给用户看到，所以设置为私有类
    {
        char data;
        int weight;
        int parent,left,right;
    };

    Node *elem;//保存hfTree
    int length;//hfTree的长度,为hfcode长度的两倍

public:
    struct hfCode
    {
        char data;//待编码的数据
        string code;//对应的hf编码
    };
    hfCode *hf_code;//保存生成的hfcode
    hfTree(const char *x,const int *w,int size);//构造hfTree，x为待编码数组，w为数据的权重，size为数据规模
    void getCode();//hfTree生成hf编码
    void printHfCode();//打印编码
    ~hfTree(){delete [] elem;delete [] hf_code;}
};


#endif // HFTREE_H
