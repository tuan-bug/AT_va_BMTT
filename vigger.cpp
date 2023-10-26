#include <iostream>
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

string khoangtrang(string x){
	string result;
	for(int i = 0; i < x.length(); i++){
      if (x[i] == '\r' || x[i] == '\n' || x[i] == ' ') {
        continue;
      }
      result += x[i];
	
	}
	return result;
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

// ham giai ma
string encryption(string BangChuCai,string input, string k) {
    string output;
    for (int i = 0, j = 0; i < input.length(); ++i) {
        char c = input[i];
        int temp = (searchNumber(BangChuCai, c) + searchNumber(BangChuCai, k[j]) ) % 26 ;
        
        
        output += BangChuCai[temp]; 
        j = (j + 1) % k.length();
    }
    return output;
   }
   
// ham phá mã
string decryption(string BangChuCai,string input,string k) {
    string output;
    for (int i = 0, j = 0; i < input.length(); ++i) {
        char c = input[i];
        	int temp = (searchNumber(BangChuCai, c) - searchNumber(BangChuCai, k[j]) ) % 26 ;
        	if(temp < 0){
        	temp += 26;
			}
			cout <<"abc : " << temp << endl;
        	output += BangChuCai[temp]; 
        	j = (j + 1) % k.length();
    }
    return output;
}

int main() {
	string BangChuCai = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	string k;
    string input ;
    cout <<"Nhap vao chuoi can ma hoa: ";
    getline(cin,input);
    input = khoangtrang(input);
    cout <<"Nhap vao khoa k: ";
    cin >> k;
    input = Upper_Input(input);
    k = Upper_Input(k);
    cout <<"CHuoi thanh hoa: " << input << endl;
    string encrypt = encryption(BangChuCai,input,k);
    string decrypt = decryption(BangChuCai,encrypt,k);
    
    cout << "Chuoi ki tu can giai ma: "<<input<< endl;
    cout << "Sau khi giai ma: " << encrypt << endl;
    cout << "Pha ma nguoc lai: " << decrypt << endl;
}
