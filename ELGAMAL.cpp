#include<iostream>
#include<string>
#include<math.h>
#include<bits/stdc++.h>
#include <cstdlib>
using namespace std;

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
		//cout << X <<"\t " << B <<"\t" << Y << endl;
	
	}
	while(B < 0){
		B = B + k;
	}
	cout <<" " << B << endl;
	return B;
	
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

		//cout << x <<"\t " << temp_a << "\t " << d << endl;
	}
	cout << A <<" ^ " << X << " mod " << n <<": " << d;
	return d;
}


int main(){
	int x,p,a ,a_pha,k;
	
	int b_ta;
	
	cout <<"Nhap ban ro x: ";
	cin >> x;
	cout <<"Nhap a: ";
	cin >> a;
	cout <<"Nhap p: ";
	cin >> p;
	cout <<"Nhap a_pha: ";
	cin >> a_pha;
	cout <<"Nhap k: ";
	cin >> k;
	
	b_ta = BPvaN(a_pha,a,p);
	
	cout <<"\nKhoa cong khai: "<< p <<", " << a_pha <<", " << b_ta << endl;
	cout <<"Khoa bi mat: " << a;
	
	int y1,y2;
	int temp;
	y1 = BPvaN(a_pha,k,p);
	temp = BPvaN(b_ta,k,p);
	y2 = (x * temp) % p;
	
	cout <<"\nLap ma ta dc y1 = " << y1 <<" , y2 = " << y2;
	
	int dk1 = BPvaN(y1,a,p);
	cout <<"  y1 ^ a = " << dk1<< endl;

	int dk2 = Euclid(p,dk1);
	cout <<" abc: " << dk2 << endl;
	cout <<endl;
	int dk =  (y2* dk2) % p;
	cout <<"\nGiai ma ta dc: " << dk;
}
