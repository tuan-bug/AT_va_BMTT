#include<iostream>
using namespace std ;
int main(){
	int x;
	int flag = 0;
	int a_nghich;
	cout <<"jhgfdsa";
		cin >> x;
	for(int i = 0; i < 26;i++){
		flag = (x * i) % 26;
		if(flag == 1){
			a_nghich = i;
		}
	}
	cout <<"Kha nghich: " << a_nghich;
}
