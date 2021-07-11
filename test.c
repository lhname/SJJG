# include <stdio.h>
# include <stdlib.h>
/*
线性表的顺序表实现
关键字：
Last用于指向最后一个位置(下标);
data数据域。

*/
#define MAXSIZE  10	//容量
typedef int ElementType;	//这里的int决定了整个结构的类型
typedef struct LNode *List;	//struct用来声明结构体类型此处对List声明为‘指针’类型，typedef用来声明这个结构体的别名可以为List

struct LNode{
	ElementType Data[MAXSIZE];
	int Last;	//Last指向最后一个元素的位置
};

struct LNode L;		//L为LNode类型的结构体
List PtrL;	//PtrL为LNode的指针类型

List MakeEmpty()	//顺序表初始化
{
	List PtrL;
	PtrL = (List)malloc(sizeof(struct LNode));
	PtrL->Last = -1;
	return PtrL;
}

int Find(ElementType X,List PtrL){	//查找X第一次出现的位置并返回位置（下标），否则返回-1

	int i=0;
	while(i<=PtrL->Last && PtrL->Data[i]!=X)	//PtrL->Last，PtrL指向的结构体抽取Last的数据进行比较
		i++;
	if(i > PtrL->Last) return -1;
	else return i;
}

void Insert(ElementType X,int i,List PtrL){//插入元素X在第i个位置，注意：没有第0个位置
	int j;
	if(PtrL->Last==MAXSIZE-1){	//判断是否已满
		printf("空间已满\n");
		return;
	}

	if(i<1 || i > PtrL->Last+2){		//Last+2表示最后一个元素的下一个位置，+3则会造成中间有空位
		printf("位置不合法\n");
		return;
	}

	for(j=PtrL->Last;j>=i-1;j--)
		PtrL->Data[j+1]=PtrL->Data[j];
	PtrL->Data[i-1] = X;
	PtrL->Last++;
	return;
}

void Delete(int i,List PtrL){ //删除第i个位置上的数据。注意：没有第个位置
	int j;
	if(i<1 || i>PtrL->Last+1){
		printf("%d 该位置没有数据\n",i);
		return;
	}
	for(j=i-1;j<=PtrL->Last;j++)
		PtrL->Data[j] = PtrL->Data[j+1];
	PtrL->Last--;
	
	return;
}
void Print(List PtrL){

}

int main(){
	PtrL = MakeEmpty();
	Insert(12,1,PtrL);
	Insert(122,2,PtrL);
	Insert(1123,3,PtrL);
	int i;
	
	printf("位置  \t 元素\n");
	for(i=0;i<=PtrL->Last;i++)
		printf("%d \t %d\n",i+1,PtrL->Data[i]);
	int n;

    return 0;
	


	//printf("%d\n",PtrL->Last);
}