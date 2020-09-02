#include "priorityQueue.h"
//构建一个最小堆

//入堆
//数字放到堆尾（需要判断maxSize够不够），然后依次与他的父亲做比较，如果他比父亲小，则父亲下沉，再与他的父亲的父亲比较，最后跳出for循环
//放到现在的hole位置
void priorityQueue::enQueue(int x)
{
    if(currentSize==maxSize) doubleSpace();
    int hole=(++currentSize);//首先将数字放到堆尾，然后依次与它的父亲比较大小
    for(;x<array[hole/2];hole/=2)//因为有哨兵array[0]为最小，所以array[1]的数字不可能比他的父亲小，所以我们不需要判定hole>=1，可以加速代码
        array[hole]=array[hole/2];//如果这个数字比父亲小，则应该把父亲移下来
    array[hole]=x;
}

//生成一个最小堆
//首先将所有的数据放到堆里面
//然后再从最大的有儿子的节点开始，percolate
void priorityQueue::priorityQueue(int data[],int size)
{
    array=new int [size+10];
    for(int i=0;i<size;++i)
        array[i+1]=data[i];
    currentSize=size;
    for(int i=currentSize/2;i>0;--i)
        percolate(i);

}

//出堆
//将堆首的数字取出来，然后将堆尾的数字放到堆首，然后对整个堆向下过滤
int priorityQueue::deQueue()
{
    int item=array[1];
    array[1]=array[currentSize];
    currentSize--;
    percolate(1);
    return item;
}

//向下过滤
//从hole开始，先找出他的儿子中最小的，如果hole处的值比最小儿子还大，那么就将hole处的值赋给他的最小儿子，直到没有儿子，或者比他的最小儿子还小
//则跳出for循环，然后此时的hole值为初始的hole处的值
void priorityQueue::percolate(int hole)
{
    int child;
    int item=array[hole];//将开始的值保存下来
    for(;2*hole <currentSize+1;hole=child)
    {
        child=2*hole;
        //找出儿子中的最小值
        if(child!=currentSize&&array[child]>array[child+1])//有右儿子，并且右儿子比左儿子小
            ++child;
        if(array[child]<item)//item比最小的儿子还小，则最小的儿子上浮一个位置，然后hole变到最小儿子的位置
            array[hole]=array[child];
    }
    array[hole]=item;

}
void priorityQueue::printQueue()
{
    cout<<"print the heap"<<endl;
    for(int i=1;i<currentSize+1;++i)
        cout<<array[i]<<" ";
    cout<<"heap printing over";
}
void priorityQueue::doubleSpace()
{
    maxSize*=2;
    int *tmp=array;
    array=new int [maxSize];

    for(int i=1;i<currentSize+1;++i)
        array[i]=tmp[i];
    delete [] tmp;
}
