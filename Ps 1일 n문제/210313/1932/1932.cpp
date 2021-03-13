#include<iostream>
#include<algorithm>
using namespace std;
/*
	int tri[125251];
	int dp[125251] = { 0, };//���� index�� ������ �����ϴ� ���� �ִ밪
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= (n*(n+1)/2); i++) {	
		cin >> tri[i];
	}
	dp[1] = tri[1];
	for (int i = 1; i <n; i++) {
		for (int j = i * (i - 1) / 2 + 1; j <= i * (i + 1) / 2; j++) {
			dp[j + i] = max(dp[j + i], dp[j]+tri[j+i]);
			dp[j + i+1] = max(dp[j + i+1], dp[j] + tri[j + i+1]);
		}
	}
	int max = 0;
	for (int i = n * (n - 1) / 2 + 1; i <= n * (n + 1) / 2; i++) {
		if (max < dp[i]) max = dp[i];
	}
	cout << max << "\n";

	return 0;
}
*/
/*
int tri[501][501];//�� ���°
int dp[501][501] = { 0, };
int main() {

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}
	dp[1][1] = tri[1][1];
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + tri[i + 1][j]);
			dp[i + 1][j+1] = max(dp[i + 1][j+1], dp[i][j] + tri[i +1][j+1]);
		}

	}
	int max =  dp[n][1];
		for (int j = 1; j <= n; j++) {
			if (max < dp[n][j]) max = dp[n][j];
		}
		cout << max << "\n";
}
*/
int tri[501][501];//�� ���°
int dp[501][501] = { 0, };
int main() {

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}
	dp[1][1] = tri[1][1];
	for (int i = 2; i <=n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) dp[i][j] = dp[i - 1][j]+tri[i][j];
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
			}
		}

	}
	int max = dp[n][1];
	for (int j = 2; j <= n; j++) {
		if (max < dp[n][j]) max = dp[n][j];
	}
	cout << max << "\n";
}
//lis�� ����� dp ���縦 ������ �����ϴ� ���� �ִ�
// 1. 1���� �迭�� -> 2. 2�����迭�� �� �� ���� -> 3. �ݺ��� ����
// ����ġ�� ū �迭�� �����Ҵ� �ʹ�Ŀ�� �ȵ� �� �����Ƿ� ���� �����̳� �����Ҵ�(heap)������