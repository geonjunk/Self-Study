#include<iostream>
using namespace std;

int dp[101][10];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=9;i++){//0���� �����ϴ� �� ���� 
		dp[1][i]=1;
	}
	for(int i=2;i<=n;i++){
		dp[i][0]=dp[i-1][1];
		for(int j=1;j<9;j++){
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%1000000000;
		}
		dp[i][9]=dp[i-1][8];
	}
	int total=0;
	for(int i=0;i<=9;i++){
		total=(total+dp[n][i])%1000000000;
	}
	cout<<total<<"\n";
	return 0;
} 
//��ܼ�
// �������� ���� 
// �ڸ���, ������ �� 
