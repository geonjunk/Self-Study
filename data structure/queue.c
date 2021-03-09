#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_QUEUE_SIZE 5 

typedef struct Customer{
	int id;
	int service_time;
	int arrival_time;
}Customer;
typedef struct Queue{
	int front;//�Ǿ� 
	int rear;//�ǵ� 
	Customer data[MAX_QUEUE_SIZE];
}Queue;
void init_queue(Queue*q){
	q->front=q->rear=0;//��ĭ ����ΰ� ����, -1�� �����ϸ� �������, ��ȭ���� ���� �Ұ��� 
}
int is_empty(Queue*q){
	return (q->front==q->rear);
}
int is_full(Queue*q){
    return (((q->rear+1)%MAX_QUEUE_SIZE)==q->front);
}
void enqueue(Queue*q,Customer c){
	if(is_full(q)){
		fprintf(stderr,"queue is full");
		exit(1);
	}else {
		q->rear=(q->rear+1)%MAX_QUEUE_SIZE;
	    q->data[q->rear]=c;
   }
}
Customer dequeue(Queue*q){
	if(is_empty(q)){
		fprintf(stderr,"queue is empty");
		exit(1);
	}else {
		q->front=(q->front+1)%MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}


int main() {
	int clock;
	Queue q[2];
	init_queue(q);
	init_queue(q+1);
	int total_customers=0;
	int total_wait_time=0;
	int service_time[2]={0,0};
	
	Customer service_customer[2];

	srand((unsigned) time(NULL));//rand�Լ� �Ź� �ٸ��� �ϱ����� �Լ� 
	int r;
	for(clock=0;clock<60;clock++){
		printf("����ð�=%d\n",clock);
		r=rand()%10;
		Customer c;
		if(r<3){//����ٿ� �� 		
			c.id=total_customers++;
			c.arrival_time=clock;
			c.service_time=rand()%3+1;
			enqueue(q,c);
			printf("1�� â�� �� %d�� %d�п� ���ɴϴ�. ����ó���ð�= %d��\n",c.id,c.arrival_time,c.service_time);
		}else if(r>6){
			c.id=total_customers++;
			c.arrival_time=clock;
			c.service_time=rand()%3+1;
			enqueue(q+1,c);
			printf("2�� â�� �� %d�� %d�п� ���ɴϴ�. ����ó���ð�= %d��\n",c.id,c.arrival_time,c.service_time);
		
		}
		if(service_time[0]==0){
			if(!is_empty(q)){
			service_customer[0]=dequeue(q);
			service_time[0]=service_customer[0].service_time;
			printf("1�� â�� �� %d�� %d�п� ������ �����մϴ�. ���ð��� %d���̾����ϴ�.\n",service_customer[0].id,clock,clock-(service_customer[0].arrival_time));
			total_wait_time+=(clock-(service_customer[0].arrival_time));
		}
		}else{
			printf("1�� â�� �� %d ����ó�����Դϴ�.\n",service_customer[0].id);
			service_time[0]--;
		} 
		
		if(service_time[1]==0){
			if(!is_empty(q+1)){
			service_customer[1]=dequeue(q+1);
			service_time[1]=service_customer[1].service_time;
			printf("2�� â�� �� %d�� %d�п� ������ �����մϴ�. ���ð��� %d���̾����ϴ�.\n",service_customer[1].id,clock,clock-(service_customer[1].arrival_time));
			total_wait_time+=(clock-(service_customer[1].arrival_time));
		}
		}else{
			printf("2�� â�� �� %d ����ó�����Դϴ�.\n",service_customer[1].id);
			service_time[1]--;
		}
	
		    
	
		
	}
	printf("�� ���ð� : %d\n",(total_wait_time));
	printf("��� ���ð� : %d\n",(total_wait_time)/total_customers);
	return 0;
}



