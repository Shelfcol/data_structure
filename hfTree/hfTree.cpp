#include "hfTree.h"

hfTree::hfTree(const char *x,const int *w,int size)
{
    const int MAX_INT=32767;
    int min_first,min_second;//������С�ʹ�С��Ȩ��
    int x_first,x_second;//������С�ʹ�С���±�
    length=2*size;//����hfTree�Ĺ�ģ��2*size-1��0��λ�ò��������ݣ�size~2*size-1����������������ʼ��ֱ�ӽ���������������
    elem=new Node[length];
    for(int i=size;i<length;++i)
    {
        elem[i].data=x[i-size];
        elem[i].weight=w[i-size];
        elem[i].left=0;
        elem[i].right=0;
        elem[i].parent=0;//���������ݵ�parentΪ0�������ٺϲ���Ѱ����С�ʹ�С����ʱ��ֻ��parentΪ0��Node��Ѱ��
    }

    //�ϲ���
    for(int i=size-1;i>0;--i)
    {
        min_first=min_second=MAX_INT;
        x_first=x_second=0;
        for(int j=i+1;j<length;++j)//Ѱ��i+1~2*size-1����С�ʹ�С��Ȩ�غ�1��Ӧ���±�
        {
            if(elem[j].parent==0)//ֻ��parent=0��Ѱ�ң���Ϊ��Щ��û�б��ϲ���
            {
                if(elem[j].weight<min_first)//����С��С
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
        //�Ѿ��ҳ���Ȩ����С�ʹ�С��Ȩ��ֵ�Ͷ�Ӧ���±꣬Ȼ����Ժϲ���
        elem[x_first].parent=elem[x_second].parent=i;
        elem[i].weight=min_first+min_second;
        elem[i].parent=0;
        elem[i].left=x_first;
        elem[i].right=x_second;

    }
    elem[0].parent=0;// ��Ԫ�ص�parentΪ0�����Է������hfCode����
    getCode();//��ȡhfCode


}

//��ȡhf���룬Ϊ���ڵ���������������Ϊ0��Ϊ���ڵ����������������Ϊ1
void hfTree::getCode()
{
    int size=length/2;
    hf_code=new hfCode[size];

    for(int i=size;i<length;++i)//׷��ÿ��data
    {
        hf_code[i-size].data=elem[i].data;
        hf_code[i-size].code="";
        int p=elem[i].parent;//int p=i/2;���������������ﲢ���ǰ�����ȫ�������Ĺ���洢�ģ�i�ĸ��ڵ��±겻��i/2
        int s=i;//����i
        while(p)
            {
                if(elem[p].left==s)//��ʾ������Ǹ��ڵ�����ڵ�
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
