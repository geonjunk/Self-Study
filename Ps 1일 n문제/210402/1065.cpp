#include<iostream>
using namespace std;
 
int main() {
	int n;
	int count = 0;
	cin >> n;
	if (n < 100) {
		count = n;
	}
	else {
		count += 99;
		int num[3];
		for (int i = 100; i <= n; i++) {
			if (i == 1000)break;
			num[0] = i / 100;
			num[1] = (i%100) / 10;
			num[2] = i % 10;
			if ((num[1] - num[0]) == (num[2]-num[1]))count++;
		}
	}
	cout << count << "\n";
	return 0;
}

//1~2�ڸ����� �׳� �Ѽ�
//�ڸ��� ���ϴ� ��� ex) õ���ڸ� ���Ѵ� (n%10000)/1000