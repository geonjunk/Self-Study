#include<iostream>
using namespace std;

int arr[1001];
int main() {
	int n;
	cin >> n;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2])%10007;
	}
	cout << arr[n] << "\n";
	return 0;
}

// n>=3�϶� ���� ��ȭ�� ����
// n=3�϶��� n=2�϶����� ���� �簢�� �ϳ� �߰��� ����Ǽ� + n=1�϶����� ���� �簢�� 2�� �߰��Ѱ���Ǽ�
//��, arr[n]=arr[n-1]+arr[n-2]