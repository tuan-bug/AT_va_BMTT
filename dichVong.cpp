#include<iostream>
#include <string.h>

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

// hàm mã hóa
string funtionEncode(string BangChuCai, string input, int k){
	string Output = "";
	int number;
	for(int i = 0; i < input.length();i++){
		number = searchNumber(BangChuCai,input[i]);
		//cout <<"NB: " << number << endl;
		int temp = (number + k) % 26;
		//cout << "\n abc:  " << temp <<", " << number;
		Output += BangChuCai[temp];
	}
	
	return Output;
}

// hàm giai mã
string funtionDecryption(string BangChuCai, string input, int k){
	string Output;
	int number;
	for(int i = 0; i < input.length();i++){
		number = (searchNumber(BangChuCai,input[i]) - k) % 26;
		//cout << "\n a: " << number;
		if(number < 0){
			number += 26;
		}
		//cout << "\n acv: " << number;
		Output += BangChuCai[number];
	}
	return Output;
}

string khoangtrang(string x){
	string result;
	for(int i = 0; i < x.length(); i++){
      if (x[i] == '\r' || x[i] == '\n' || x[i] == ' ' ){
        continue;
      }
      result += x[i];
	
	}
	return result;
}

int main(){
	string BangChuCai = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	string input;
	int k;
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
				cin.ignore();
				cout <<"Nhap vao chuoi can giai ma: ";
				getline(cin,input);
				input = khoangtrang(input);
//				StringSpace(input);
				do{
					cout <<"Nhap vao khoa k: ";
					cin >> k;
					if( k < 0 || k >25){
						cout <<"\nKhoa nhap vao k hop le. Moi nhap lai";
					}	
				}while(k < 0 || k >25);
				
				//cout <<"Chuoi " << Upper_Input(input);
				cout <<"\nSau khi ma hoa: " << funtionEncode(BangChuCai,Upper_Input(input),k);
				break;
			case 2:
				cin.ignore();
				cout <<"Nhap vao chuoi can giai ma: ";
				getline(cin,input);
				input = khoangtrang(input);
				do{
					cout <<"Nhap vao khoa k: ";
					cin >> k;	
					if( k < 0 || k >25){
						cout <<"\nKhoa nhap vao k hop le. Moi nhap lai";
					}
				}while(k < 0 || k >25);
				//cout <<"Chuoi " << Upper_Input(input);
				cout <<"\nSau khi giai ma: " << funtionDecryption(BangChuCai,Upper_Input(input),k);
				break;
		}
	}
	
	
	
}
