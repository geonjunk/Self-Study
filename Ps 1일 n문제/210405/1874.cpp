#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int n;
stack<int>s;
queue<char>q;
int arr[100000];
int main() {
	cin >> n;
	for (int i =0; i <n; i++) {
		cin >> arr[i];
	}
	s.push(1);
	q.push('+');
	//ó������ ������ �־��ֱ�
	int idx = 0;
	int num = 2;
	while (idx != n) {//s.empty() x������ ���쵵 ���� �� ����
		if (!s.empty() && s.top() > arr[idx]) {
			cout << "NO" << "\n";
			return 0;
		}
		while (num <=arr[idx]) {//s.top() ��� num ���(���� ���� ���� ����)
			s.push(num++);
			q.push('+');
		}
		if (!s.empty() && s.top() == arr[idx]) {//���⼭ while���� idx �ʰ� ����
			idx++;
			s.pop();
			q.push('-');
		}
	
	
	}
	while (!q.empty()) {
		cout << q.front() << "\n";
		q.pop();
	}

	return 0;
}

//���� ���� ����