#include "priorityQueue.h"
//����һ����С��

//���
//���ַŵ���β����Ҫ�ж�maxSize����������Ȼ�����������ĸ������Ƚϣ�������ȸ���С�������³����������ĸ��׵ĸ��ױȽϣ��������forѭ��
//�ŵ����ڵ�holeλ��
void priorityQueue::enQueue(int x)
{
    if(currentSize==maxSize) doubleSpace();
    int hole=(++currentSize);//���Ƚ����ַŵ���β��Ȼ�����������ĸ��ױȽϴ�С
    for(;x<array[hole/2];hole/=2)//��Ϊ���ڱ�array[0]Ϊ��С������array[1]�����ֲ����ܱ����ĸ���С���������ǲ���Ҫ�ж�hole>=1�����Լ��ٴ���
        array[hole]=array[hole/2];//���������ֱȸ���С����Ӧ�ðѸ���������
    array[hole]=x;
}

//����һ����С��
//���Ƚ����е����ݷŵ�������
//Ȼ���ٴ������ж��ӵĽڵ㿪ʼ��percolate
void priorityQueue::priorityQueue(int data[],int size)
{
    array=new int [size+10];
    for(int i=0;i<size;++i)
        array[i+1]=data[i];
    currentSize=size;
    for(int i=currentSize/2;i>0;--i)
        percolate(i);

}

//����
//�����׵�����ȡ������Ȼ�󽫶�β�����ַŵ����ף�Ȼ������������¹���
int priorityQueue::deQueue()
{
    int item=array[1];
    array[1]=array[currentSize];
    currentSize--;
    percolate(1);
    return item;
}

//���¹���
//��hole��ʼ�����ҳ����Ķ�������С�ģ����hole����ֵ����С���ӻ�����ô�ͽ�hole����ֵ����������С���ӣ�ֱ��û�ж��ӣ����߱�������С���ӻ�С
//������forѭ����Ȼ���ʱ��holeֵΪ��ʼ��hole����ֵ
void priorityQueue::percolate(int hole)
{
    int child;
    int item=array[hole];//����ʼ��ֵ��������
    for(;2*hole <currentSize+1;hole=child)
    {
        child=2*hole;
        //�ҳ������е���Сֵ
        if(child!=currentSize&&array[child]>array[child+1])//���Ҷ��ӣ������Ҷ��ӱ������С
            ++child;
        if(array[child]<item)//item����С�Ķ��ӻ�С������С�Ķ����ϸ�һ��λ�ã�Ȼ��hole�䵽��С���ӵ�λ��
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
