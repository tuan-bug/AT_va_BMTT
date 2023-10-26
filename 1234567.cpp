#include <bits/stdc++.h>
using namespace std;
 
class Matrix{
    private:
        int n;
        int m;
        int A[100][100];
    public:
        Matrix(){};
        Matrix(int n, int m, int A[][100]){
            this->n = n;
            this->m = m;
            for(int i = 0;i<n;i++){
                for(int j = 0; j<m; j++){
                    this->A[i][j] = A[i][j];
                }
            }
        }
         
         
        void nhap(){
            cout<<"Nhap n (So hang): ";
			 cin>>n;
            cout<<"Nhap m (So cot): ";
			 cin>>m;
            cout<<"\n\nNhap ma tran\n";
            for(int i = 0;i<n;i++){
                for(int j = 0; j<m; j++){
                    cout<<"A["<<i<<"]["<<j<<"] = ";
                    cin>>this->A[i][j];
                }
            }
        }
        void nhapMT_Vuong(){
            cout<<"Nhap n (So hang, So cot): ";
			cin>>n;
            
            cout<<"\n\nNhap ma tran\n";
            for(int i = 0;i<n;i++){
                for(int j = 0; j<n; j++){
                    cout<<"A["<<i<<"]["<<j<<"] = ";
                    cin>>this->A[i][j];
                }
            }
        }
         
        void xuat(){
            for(int i = 0;i<n;i++){
                for(int j = 0; j<m; j++){
                    cout<<this->A[i][j]<<"  ";
                }
                cout<<"\n";
            }
        }
         
        Matrix cong(Matrix b){
            Matrix c;
            for(int i = 0;i<this->n;i++){
                for(int j = 0;j<this->m;j++){
                     c.A[i][j] = this->A[i][j] + b.A[i][j];
                }
            }
            return c;
        }
         
        bool sameSize(Matrix b){
            if(this->n == b.getN() && this->m == b.getM()) return true;
            return false;
        }
         
        bool checkCanMultiply(Matrix b){
            return this->m == b.getN() ? true:false;
        }
        Matrix nhan(Matrix b){
            Matrix c;   
            for(int i=0;i<this->n;i++) 
                for(int j=0;j<b.m;j++) {
                 int tt=0;
                   for(int k=0;k<this->m;k++)
                       {
                          tt = tt + (this->A[i][k] * b.A[k][j]); //Công th?c tính C[i][j]
                        }
                    c.A[i][j] = tt;
            }
        }
         
        void setN(int n){
            this->n = n;
        }
        void setM(int m){
            this->m = m;
        }
        void setElementMattrix(int value, int i, int j){
            this->A[i][j] = value;
        }
         
        int getN(){
            return this->n;
        }
        int getM(){
            return this->m;
        }
        int getElementMattrix(int i, int j){
            return this->A[i][j];
        }
};

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
 
int main(){
	string BangChuCai = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    Matrix K;
    string input;
    
    
    
    cout<<"\n\n--------------NHAP MA TRAN K-----------\n";
    K.nhapMT_Vuong();
   
    cout<<"\n\n--------------XUAT MA TRAN A-----------\n";
    K.xuat();
    cout <<"\n------------- NHAP VAO INPUT ---------------\n";
	getline(cin,input);
	int n = K.getN();
	int len = input.length();
	int soMT;
	if(len % n == 0){
		soMT = len / n;
	}
	else {
		soMT = len / n + 1;
	}
	
	int A[] = new int[len];
	for(int i = 0; i < len;i++){
		char c = input[i];
		A[i]
	}
     
//    cout<<"\n\n--------------CONG 2 MA TRAN-----------\n";
//    Matrix tong;
//    if(A.sameSize(B) ==  true){
//        tong = A.cong(B);
//        tong.xuat();
//    }else{
//        cout<<"\n=>Khong the cong 2 ma tran khong cung kich thuoc";
//    }
//     
//     
//    cout<<"\n\n--------------TICH 2 MA TRAN-----------\n";
//    Matrix tich;
//    if(A.sameSize(B) ==  true){
//        tich = A.nhan(B);
//        tich.xuat();
//    }else   {
//        cout<<"\n=>Khong the cong 2 ma tran khong cung kich thuoc";
//    }
}
