# include <stdio.h>
# include <stdlib.h>

#define MAXSIZE 10
typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int Lenght;
}SqList;

void InitList(SqList *sq){
    sq->Lenght = 0;
}

int ListInsert(SqList *sq,int i,ElemType e){//插入
    if(i<1 || i>sq->Lenght+1)
        return 0;
    if(sq->Lenght>=MAXSIZE)
        return 0;
    int j;
    for ( j = sq->Lenght; j >= i; j--)
    {
        sq->data[j]=sq->data[j-1];
    }
    sq->data[i-1]=e;
    sq->Lenght++;
    return 1;

}
int ListDelete(SqList *sq,int i,ElemType *e){//删除第i个元素，被删除的元素在e中
    if(i<1 || i>sq->Lenght)
        return 0;
    *e=sq->data[i-1];
    for (int j = i-1; j < sq->Lenght-1; j++)
    {
        sq->data[j] = sq->data[j+1];
    }
    sq->Lenght--;
    return 1;
    
    
}
void ShowList(SqList sq){
    int i=0;
    for ( i = 0; i < sq.Lenght; i++)
    {
        printf("%d\n",sq.data[i]);
    }
    
}

int main(){
    SqList sq;
    InitList(&sq);
    int a;
    int i;
    for ( i= 0; i < 10; i++)
    {
        a = ListInsert(&sq,1,i);
        printf("插入结果%s\n",a? "true":"false");
    }
    int e=0;
    int b = ListDelete(&sq,3,&e);
    printf("删除了%d结果%s\n",e,b? "true":"false");
    
    ShowList(sq);
   return 0; 
}