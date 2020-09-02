#ifndef HFTREE_H
#define HFTREE_H

#include <iostream>
#include <string>
using namespace std;

class hfTree
{
private:
    struct Node//����hfTree�Ľṹ�壬����������ݣ��Լ����ڵ㡢�����ӽڵ��λ�ã���Ϊ����洢����Ҫ���û���������������Ϊ˽����
    {
        char data;
        int weight;
        int parent,left,right;
    };

    Node *elem;//����hfTree
    int length;//hfTree�ĳ���,Ϊhfcode���ȵ�����

public:
    struct hfCode
    {
        char data;//�����������
        string code;//��Ӧ��hf����
    };
    hfCode *hf_code;//�������ɵ�hfcode
    hfTree(const char *x,const int *w,int size);//����hfTree��xΪ���������飬wΪ���ݵ�Ȩ�أ�sizeΪ���ݹ�ģ
    void getCode();//hfTree����hf����
    void printHfCode();//��ӡ����
    ~hfTree(){delete [] elem;delete [] hf_code;}
};


#endif // HFTREE_H
