#include<iostream>
using namespace std;

int main() {
	int t, n,pre;
	cin >> t;
	long dp[101] = { 0, };
	dp[1] = dp[2]=dp[3]=1;
	dp[4] = 2;
	pre = 4;
	while (t > 0) {
		cin >> n;
		if (n > pre) {
			for (int i = pre+1; i <= n; i++) {
				dp[i] = dp[i - 1] + dp[i - 5];
			}
			pre = n;
		}
		cout << dp[n] << "\n";
		t--;
	}

	return 0;
}
// �ʰ� �Ǵܹ� : ������ �� �Է� �غ���
// Ƚ�� ���̴� �� -> ���� �� ����س���