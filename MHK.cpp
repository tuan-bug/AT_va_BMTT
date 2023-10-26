#include<iostream>
#include<string>
#include<math.h>
#include<bits/stdc++.h>
#include <cstdlib>
using namespace std;

// b^-1 mod a
long long Euclid(long long a, long long b){
	long long x1 = a, x2 = b, b1 = 0, b2 = 1;
	long k = a;
	//int y = 0;
	long long X;
	long long B;
	long long i = 2;
	long long Y = x1 / x2;
	while(x2 != 1){
		X = x1 % x2;
		B = b1 - b2 * Y;
		
		b1 = b2;
		b2 = B;
		x1 = x2;
		x2 = X;
		
		Y = x1 / x2;
		cout << X <<"\t " << B <<"\t" << Y << endl;
	
	}
	while(B < 0){
		B = B + k;
	}
	cout <<"(a,b) = " << B << endl;
	return B;
	
}

void nhapM(int a[], int n){
	
	for(int i = 0; i < n;i++){
		cout <<"a [" << i << "] : ";
		cin >> a[i];
	}
}
int Sum(int a[], int n){
	int S = 0;
	for(int i = 0; i < n;i++){
		S += a[i];
	}
	
	return S;
}

void xuatM(int a[], int n){
	for(int i = 0; i < n;i++){
		cout << a[i] << "\t";
	}
}

long long BPvaN(long long a,long long x, long long n){
	long long d;
	long long temp_a = a;
	long long A = a, X = x;
	
	if(x % 2 == 1)
	{
		d = ( a * 1 ) % n;
	}
	else
	{
		d = 1;
	}
	cout <<"\n d ban dau : " << d << endl;
	while(x != 1)
	{
		x = x / 2;
		temp_a = (temp_a * temp_a ) % n;
		
		if(x % 2 == 1)
		{
			d = ( temp_a * d ) % n;
		}
		else
		{
			d = d;
		}

		cout << x <<"\t " << temp_a << "\t " << d << endl;
	}
	cout << A <<" ^ " << X << " mod " << n <<": " << d;
	return d;
}



int main(){
	int s[30];
	int t[30];
	int n;
	int p,a;
	int sum ;
	cout <<"Nhap n: ";
	cin>> n;
	nhapM(s,n);
	xuatM(s,n);
	sum = Sum(s,n);
	
	do{
		do{
			cout <<"\nNhap vap p: ";
			cin >> p;
			if(p < sum)
				cout <<"\nBan phai nhap p lon hon tong S" << endl;
		}while (p < sum);
	
		do{
			cout <<"\nNhap vao a: ";
			cin >> a;
			if(a > p -1 || a < 1)
				cout <<"\nBan phai nhap a trong khoang 1 den p -1" << endl;
		}while(a > p -1 || a < 1);
	
	}while(__gcd(a,p) != 1);
	
	for(int i = 0; i < n; i++){
		t[i] = ( a * s[i] ) % p;
	}
	
	cout <<"\nKhoa cong khai: ";
	for(int i = 0; i < n; i++){
		cout << t[i] <<"\t";
	}
	cout <<"\nKhoa bi mat: " << a <<" , " << p << endl;
	xuatM(s,n);
	
	int x[30];
	
	for(int i = 0; i < n; i++){
		cout <<"x[" << i << "] : ";
		cin >> x[i];
	}
	
	int tong = 0;
	for(int i = 0; i < n;i++){
		tong += x[i] * t[i];
	}
	cout <<"Ban ma cua no : " << tong << endl;
	
	int a_nghich = Euclid(p,a);
	cout <<"Giai ma: " << (a_nghich * tong) % p;
	
	
	
	
	
	
	
	
}
