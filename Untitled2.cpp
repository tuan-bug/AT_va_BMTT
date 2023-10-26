#include <iostream>
#include <string.h>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int searchNumber(string BangChuCai, char x){
	int t;
	for(int i = 0; i < BangChuCai.length();i++){
		if(BangChuCai[i] == x){
			t = i;
			break;
		}
	}
	return t;
}

string Upper_Input(string input){
	string temp;
	for(int i = 0; i < input.length();i++){
		if(input[i] >= 'a' && input[i] <= 'z'){
			input[i] -= 32;
		}
		
	}
	return input;
}
// ham ma hoa
string funtionEncode(string BangChuCai, string input, int a, int b){
	string Output = "";
	int number;
	for(int i = 0; i < input.length();i++){
		number = searchNumber(BangChuCai,input[i]);
		int temp = (a*number + b) % 26;
		//cout << "\n abc:  " << temp <<", " << number;
		Output += BangChuCai[temp];
	}
	
	return Output;
}

// hàm giai mã
string funtionDecryption(string BangChuCai, string input, int a, int b){
	
	int flag = 0;
	int a_nghich;
	for(int i = 0; i < 26;i++){
		flag = (a * i) % 26;
		if(flag == 1){
			a_nghich = i;
		}
	}
	cout <<"Kha nghich: " << a_nghich;
	string Output = "";
	int number;
	for(int i = 0; i < input.length();i++){
		number = searchNumber(BangChuCai,input[i]);
		int temp = a_nghich * (number - b) % 26;
		if(temp < 0){
			temp = temp + 26;
		}
		//cout << "\n abc:  " << temp <<", " << number;
		Output += BangChuCai[temp];
	}
	
	return Output;
	
}
int main(){
	string BangChuCai = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string input;
	int a,b;
	int luachon;
	while(luachon != 3){
		cout <<"\n---- NHAP VAO LUA CHON CUA BAN ---\n";
		cout <<"1. Ma hoa \n";
		cout <<"2. Giai ma \n";
		cout <<"3. Exit \n";
		do{
			cout <<"Nhap vao lua chon: ";
			cin >> luachon;
		}while( luachon < 1 || luachon > 3);
		
		
		switch(luachon){
			case 1:
				cout <<"Nhap vao chuoi can ma hoa: ";
				cin >> input;
				input = Upper_Input(input);
				do{
					cout <<"\nNhap khoa k(a,b) : ";
					cout <<"\nNhap a: ";
					cin >> a;
					cout <<"\nNhap b: ";
					cin >> b;
					cout <<"UCLN: " <<__gcd(a,b);
				}while(__gcd(a,26) != 1);
				cout <<"\nSau khi ma hoa: " << funtionEncode(BangChuCai,input,a,b);
				
				break;
			case 2:
				cout <<"Nhap vao chuoi can ma hoa: ";
				cin >> input;
				input = Upper_Input(input);
				do{
					cout <<"\nNhap khoa k(a,b) : ";
					cout <<"\nNhap a: ";
					cin >> a;
					cout <<"\nNhap b: ";
					cin >> b;
					cout <<"UCLN: " <<__gcd(a,b);
				}while(__gcd(a,26) != 1);
				cout <<"\nSau khi giai ma: " << funtionDecryption(BangChuCai,input,a,b);
				break;
		}
	}
	
	
	
}
