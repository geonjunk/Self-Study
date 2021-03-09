#include<stdio.h>
#include<stdlib.h>
#define MAX_LIST_SIZE 100

/*
	* ��ü : n���� element������ ������ ���� �ִ� ����
	* ���� 
		* insert(list,pos,item)::= pos��ġ�� ��Ҹ� �߰���
		* insert_last(list,item)::= �� ���� ��Ҹ� �߰���
		* insert_first(list,item)::= �� ó���� ��Ҹ� �߰���
		* delete(list,pos)::= pos��ġ�� ��Ҹ� ���� 
		* clear(list)::= list�� ��� ��Ҹ� ����
		* get_entry(list,pos)::= pos��ġ�� ��Ҹ� ��ȯ
		* get_length(list)::= ����Ʈ�� ���̸� ����
		* is_empty(list)::= ����Ʈ�� ������� Ȯ�� 
		* is_full(list)::= ����Ʈ�� ��á���� �˻�
		* print_list(list)::= ��� ��� ���
	*/
typedef int element;
typedef struct ArrayListType{
	int size;//��������� (�߰��ϰ� �����Ұ���) 
	element data[MAX_LIST_SIZE];
}ArrayListType;
void init(ArrayListType*list){
	list->size=0;
}
int is_full(ArrayListType*list){
	return (list->size==MAX_LIST_SIZE);
}
int is_empty(ArrayListType*list){
	return (list->size==0);
}
void insert(ArrayListType*list,int pos,element item){
	if(pos<0||pos>list->size){
		return;
	} 
	
	//�߰��� ������ ��� ó�� 
	list->data[pos++]=item;
}

void insert_last(ArrayListType*list,element item){
	if(pos<0||pos>list->size){
		return;
	}
	if(!is_full(list)) list->data[pos++]=item;
} 
void insert_first(ArrayListType*list,element item){
	if(pos<0||pos>list->size){
		return;
	}
	if(!is_full(list)) {
	int i;
	element temp=list[0];
	//shift ���� 
	for(i=1;i<list->size;i++){
	
	
	}
	
	list->data[pos++]=item;
		
	}
}
int main(){
	
	ArrayListType list;
	
	init(&list);
	insert(&list,0,10); print_list(&list);
	
	insert(&list,0,20); print_list(&list);
	insert(&list,0,30); print_list(&list);
	insert_last(&list,40);print_list(&list);
	delete(&list,0); print_list(&list);

	return 0;
}

