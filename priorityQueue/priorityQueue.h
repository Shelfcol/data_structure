#ifndef PRIOITYQUEUE_H
#define PRIOITYQUEUE_H

#include<iostream>
using namespace std;

//����һ����С��
class priorityQueue
{
private:
    int maxSize;//��������ֵ����ֵ
    int *array;//���������
    int currentSize;//�������ڵ�����
    void doubleSpace();
    void buildHeap();
    void percolate(int hole);//���¹��˵ĺ���
    void printQueue();//������ʾ��Ԫ��
public:
    priorityQueue(int capacity=100)//���������Ƚ�һ���ն�
    {
        array=new int [capacity+1];
        maxSize=capacity;
        int currentSize=0;
        array[0]=-10000;
    }

    priorityQueue(int data[],int size);//ͨ������һ������������һ����

    ~priorityQueue()
    {
        delete [] array;
    }

    bool isEmpty() const{ return currentSize==0;}
    void enQueue(int x);//���
    int deQueue();//����
    int getHead(){return array[1];}


};
#endif // PRIOITYQUEUE_H
