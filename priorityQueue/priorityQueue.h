#ifndef PRIOITYQUEUE_H
#define PRIOITYQUEUE_H

#include<iostream>
using namespace std;

//构建一个最小堆
class priorityQueue
{
private:
    int maxSize;//保存堆数字的最大值
    int *array;//保存堆数字
    int currentSize;//保存现在的数量
    void doubleSpace();
    void buildHeap();
    void percolate(int hole);//向下过滤的函数
    void printQueue();//遍历显示堆元素
public:
    priorityQueue(int capacity=100)//根据容易先建一个空堆
    {
        array=new int [capacity+1];
        maxSize=capacity;
        int currentSize=0;
        array[0]=-10000;
    }

    priorityQueue(int data[],int size);//通过传入一个数组来构建一个堆

    ~priorityQueue()
    {
        delete [] array;
    }

    bool isEmpty() const{ return currentSize==0;}
    void enQueue(int x);//入队
    int deQueue();//出堆
    int getHead(){return array[1];}


};
#endif // PRIOITYQUEUE_H
