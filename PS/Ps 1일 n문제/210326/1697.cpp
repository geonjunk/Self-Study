#include<iostream>
#include<queue>
using namespace std;


int visited[100001];
int main(){
	int n,k;
	queue<int>q;
	cin>>n>>k;
	int count=0;
	int size;
	q.push(n);
	visited[n]=1;
	while(!visited[k]&&!q.empty()){
		size=q.size();
		for(int i=0;i<size;i++){
		n=q.front();
		q.pop();
		if(0<=n-1&&visited[n-1]==0){
		q.push(n-1);
		visited[n-1]=1;	
		} 
		if(n+1<=100000&&visited[n+1]==0){
		q.push(n+1);	
		visited[n+1]=1;
		} 
		if(2*n<=100000&&visited[2*n]==0){
		q.push(2*n);
		visited[2*n]=1;	
		} 
		}
		count++;
	}
		cout<<count<<"\n";

	return 0;
}//������޵� bfs�� ���� -> DP�� �����ϸ� BFS �����غ��� 
// �ݺ����� ����? -> ������ �ѹ����� �ƴѰ�쿡�� BFS? 
// �׻� ������ ��ŷ -> ť�� �� ������ �ּ�ȭ 
