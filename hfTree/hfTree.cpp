#include "hfTree.h"

hfTree::hfTree(const char *x,const int *w,int size)
{
    const int MAX_INT=32767;
    int min_first,min_second;//保存最小和次小的权重
    int x_first,x_second;//保存最小和次小的下标
    length=2*size;//整个hfTree的规模是2*size-1，0的位置不保存数据，size~2*size-1保存待编码的数，开始就直接将待编码的数保存好
    elem=new Node[length];
    for(int i=size;i<length;++i)
    {
        elem[i].data=x[i-size];
        elem[i].weight=w[i-size];
        elem[i].left=0;
        elem[i].right=0;
        elem[i].parent=0;//待编码数据的parent为0，后面再合并树寻找最小和次小树的时候，只在parent为0的Node中寻找
    }

    //合并树
    for(int i=size-1;i>0;--i)
    {
        min_first=min_second=MAX_INT;
        x_first=x_second=0;
        for(int j=i+1;j<length;++j)//寻找i+1~2*size-1的最小和次小的权重和1对应的下标
        {
            if(elem[j].parent==0)//只在parent=0中寻找，因为这些才没有被合并过
            {
                if(elem[j].weight<min_first)//比最小还小
                {
                    min_second=min_first;
                    x_second=x_first;
                    min_first=elem[j].weight;
                    x_first=j;

                }
                else if(elem[j].weight<min_second)
                {
                    min_second=elem[j].weight;
                    x_second=j;
                }
            }
        }
        //已经找出了权重最小和次小的权重值和对应的下标，然后可以合并树
        elem[x_first].parent=elem[x_second].parent=i;
        elem[i].weight=min_first+min_second;
        elem[i].parent=0;
        elem[i].left=x_first;
        elem[i].right=x_second;

    }
    elem[0].parent=0;// 首元素的parent为0，可以方便后面hfCode生成
    getCode();//获取hfCode


}

//获取hf编码，为父节点的左子树，则编码为0，为父节点的右子树，编码则为1
void hfTree::getCode()
{
    int size=length/2;
    hf_code=new hfCode[size];

    for(int i=size;i<length;++i)//追踪每个data
    {
        hf_code[i-size].data=elem[i].data;
        hf_code[i-size].code="";
        int p=elem[i].parent;//int p=i/2;！！！！！！这里并不是按照完全二叉树的规则存储的，i的父节点下标不是i/2
        int s=i;//跟踪i
        while(p)
            {
                if(elem[p].left==s)//表示这个数是父节点的做节点
                    hf_code[i-size].code='0'+hf_code[i-size].code;
                else
                    hf_code[i-size].code='1'+hf_code[i-size].code;
                s=p;
                p=elem[p].parent;
            }
    }

}

void hfTree::printHfCode()
{
    cout<<"hfCode:"<<endl;
    for(int i=0;i<length/2;++i)
        cout<<"data="<<hf_code[i].data<<" hfcode="<<hf_code[i].code<<endl;

}
