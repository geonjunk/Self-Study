#include<iostream>
#include<math.h>
using namespace std;

int count;
int n,row,col;
void search_z(int len,int rs,int cs){
 	int gap=len/2;
	if(row==rs&&col==cs){
			return;
	}
	if(rs<=row&&row<rs+gap){
	if(cs<=col&&col<cs+gap){
			search_z(n-1,rs,cs);
		}else{
			count+=((gap)*(gap));
			search_z(n-1,rs,cs+gap);
		}	
		}else{
		if(cs<=col&&col<cs+gap){
			count+=(gap*gap*2);
			search_z(n-1,rs+gap,cs);
		}else{
			count+=(gap*gap*3);
			search_z(n-1,rs+gap,cs+gap);
		}
		}
	
				
}//��� 1 

//���� -> ����� ���� pow ����ϴ� �������̱� ���� pow ��ü�� ���ڷ� ����
//-> if�� ���� �� �ְ�  -> ������� Ž���ϸ鼭 Ž����ġ �߰��ϸ� ��� 


void search(int len,int r,int c){
	if(r==row&&c==col){
		cout<<count<<"\n";
		return;
	}
	if(r<=row&&row<r+len&&c<=col&&col<c+len){
		search(len/2,r,c);
		search(len/2,r,c+len/2);
		search(len/2,r+len/2,c);
		search(len/2,r+len/2,c+len/2);
	}else count+=(len*len);
	
}

int main(){
	cin>>n>>row>>col;
	search(1<<n,0,0);//1�� 2^n�� 	 
	return 0;
}
//ó���� arr�̿��Ϸ� ���� -> �ð��ʰ� 
//�������� ��Ģ ã�� ��� �Լ� ����
//����Լ� ����ȭ 
