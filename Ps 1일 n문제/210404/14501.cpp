#include<iostream>
#include<algorithm>
using namespace std;

int plan[16][2];
int dp[16];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> plan[i][0] >> plan[i][1];
	}
	if (plan[n][0] == 1)dp[n] = plan[n][1];
	for (int i = n-1; i > 0; i--) {
		if (i + plan[i][0] -1<= n)
			dp[i] = max(dp[i + 1], dp[i + plan[i][0]] + plan[i][1]);
		else dp[i] = dp[i + 1];
	}
	cout << dp[1] << "\n";
	return 0;
}
//�Ｚ���� sw �����׽�Ʈ ����
//����� ���� ���ٰ� �ǴܵǸ� dfs�� �̿��� ����Ž���� ���� Ȯ���� ��� 
//����ϴ� ����Ǽ� 1) �ش糯 ���x �ϰ� ������ 2) �ش糯 ����ϰ� �ɸ��� ���ϼ���ŭ �Ѿ
// 1. dfs 2. dp top down ��� �̿�!