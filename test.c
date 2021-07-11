# include <stdio.h>
# include <stdlib.h>
/*
���Ա��˳���ʵ��
�ؼ��֣�
Last����ָ�����һ��λ��(�±�);
data������

*/
#define MAXSIZE  10	//����
typedef int ElementType;	//�����int�����������ṹ������
typedef struct LNode *List;	//struct���������ṹ�����ʹ˴���List����Ϊ��ָ�롯���ͣ�typedef������������ṹ��ı�������ΪList

struct LNode{
	ElementType Data[MAXSIZE];
	int Last;	//Lastָ�����һ��Ԫ�ص�λ��
};

struct LNode L;		//LΪLNode���͵Ľṹ��
List PtrL;	//PtrLΪLNode��ָ������

List MakeEmpty()	//˳����ʼ��
{
	List PtrL;
	PtrL = (List)malloc(sizeof(struct LNode));
	PtrL->Last = -1;
	return PtrL;
}

int Find(ElementType X,List PtrL){	//����X��һ�γ��ֵ�λ�ò�����λ�ã��±꣩�����򷵻�-1

	int i=0;
	while(i<=PtrL->Last && PtrL->Data[i]!=X)	//PtrL->Last��PtrLָ��Ľṹ���ȡLast�����ݽ��бȽ�
		i++;
	if(i > PtrL->Last) return -1;
	else return i;
}

void Insert(ElementType X,int i,List PtrL){//����Ԫ��X�ڵ�i��λ�ã�ע�⣺û�е�0��λ��
	int j;
	if(PtrL->Last==MAXSIZE-1){	//�ж��Ƿ�����
		printf("�ռ�����\n");
		return;
	}

	if(i<1 || i > PtrL->Last+2){		//Last+2��ʾ���һ��Ԫ�ص���һ��λ�ã�+3�������м��п�λ
		printf("λ�ò��Ϸ�\n");
		return;
	}

	for(j=PtrL->Last;j>=i-1;j--)
		PtrL->Data[j+1]=PtrL->Data[j];
	PtrL->Data[i-1] = X;
	PtrL->Last++;
	return;
}

void Delete(int i,List PtrL){ //ɾ����i��λ���ϵ����ݡ�ע�⣺û�еڸ�λ��
	int j;
	if(i<1 || i>PtrL->Last+1){
		printf("%d ��λ��û������\n",i);
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
	
	printf("λ��  \t Ԫ��\n");
	for(i=0;i<=PtrL->Last;i++)
		printf("%d \t %d\n",i+1,PtrL->Data[i]);
	int n;

    return 0;
	


	//printf("%d\n",PtrL->Last);
}