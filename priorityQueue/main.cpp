#include <iostream>
#include "priorityQueue.h"

using namespace std;


int main()
{
    //int data[11]={40,20,60,15,30,25,10,35,45,50,55};//检验创建最小堆的数据
    //int data[10]={1,2,4,5,3,10,23,29,60,7};//这个是书上用来检验deQueue的数据
    int data[9]={2,3,4,5,7,10,23,29,60};//检验enQueue

    priorityQueue priQueue(data,9);
    priQueue.printQueue();

    //int minData=priQueue.deQueue();
    //priQueue.printQueue();

    priQueue.enQueue(1);
    priQueue.printQueue();

    return 0;
}
