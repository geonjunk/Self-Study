#include<iostream>
using namespace std;


long long dp[91][2];//������ Ʋ��  
int main(){
	int n;
	cin>>n;
	dp[1][1]=1;
	
	for(int i=2;i<=n;i++){	
		dp[i][0]=dp[i-1][0]+dp[i-1][1];
		dp[i][1]=dp[i-1][0];
	}
	cout<<dp[n][0]+dp[n][1]<<"\n";
	
	return 0;
}

long long dp[91];
int main(){
	int n;
	cin>>n;
	dp[1]=dp[2]=1;
	for(int i=3;i<=n;i++){
		dp[i]=dp[i-2]+dp[i-1];
	}
	cout<<dp[n]<<"\n";
}

//1. �ڸ����� �������� idx�� �ϴ� 2���� �迭�� �̿��� Ǯ��
//2. ���������� 0�̸� �ٰ��� + 1�̸� �� ���ڸ��� ������0 -> �Ǻ���ġ �̿밡�� 
//int�� �ƴ϶� long �迭��
// 
