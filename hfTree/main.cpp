#include <iostream>
#include "hfTree.h"

using namespace std;

int main()
{
    char ch[]={"aeistdn"};
    int w[]={10,15,12,3,4,13,1};

    hfTree tree(ch,w,7);//构造一个tree
    tree.printHfCode();

    return 0;
}
