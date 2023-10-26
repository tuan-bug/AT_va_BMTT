#include<stdlib.h>
#include<stdio.h>
typedef int item; //kieu item la kieu nguyen
struct Node
{
     item key; //truong key cua du lieu
     Node *Left, *Right; //con trai va con phai
};
typedef Node *Tree;  //cay
   
Node* makeNode(Node *p, item x) // chen 1 Node vao cay
{
    p = (Node *) malloc(sizeof(Node));
    p->key = x;
    p->Left = p->Right = NULL;
    return p;   // ok
}
 
Node*  CreateTree(Node *p,item x)        // nhap cay
{   
        printf("Node: "); scanf("%d", &x);
        if (x==0)return NULL;
        p=  makeNode(p,x);
        printf("Nhap con trai cua node %d: ",x);
        p->Left=CreateTree(p->Left,x);
        printf("Nhap con phai cua node %d: ",x);
        p->Right=CreateTree(p->Right,x);
    return p;       
}
   
// Duyet theo LNR thu tu giua
void LNR(Tree T)
{
     if(T!=NULL)
     {
      LNR(T->Left);
      printf("%d   ",T->key);//duyet goc
      LNR(T->Right);
     }
}
void NLR(Tree T)//duyet theo thu tu truoc
{
     if(T!=NULL)
     {printf("%d   ",T->key);
      NLR(T->Left);
      NLR(T->Right);
     }
}
void LRN(Tree T)//duyet theo thu tu sau
{
     if(T!=NULL)
     {
      LRN(T->Left);
      LRN(T->Right);
      printf("%d   ",T->key);
     }
}
   
Node* searchKey(Tree T, item x)     // tim nut co key x
{  Tree p;
    if (T->key==x)return T;
    if(T==NULL) return NULL;
    p=searchKey(T->Left,x);
    if(p==NULL)searchKey(T->Right,x);
     
}
Node * leftChild(Tree T){
    if(T!=NULL)return T->Left;
    else return NULL;
} 
Node * rightChild(Tree T){
    if(T!=NULL)return T->Right;
    else return NULL;
}   
int isLeaf(Tree T){
    if(T!=NULL)
        return (T->Left==NULL&&T->Right==NULL);
    else return NULL;
}
int numberNode(Tree T){
     
    if(T==NULL)return 0;
    else return (1+numberNode(leftChild(T))+numberNode(rightChild(T)));
}
int main()
{
    Tree T;
    T=NULL; //Tao cay rong
    Node *p=NULL;item x;
    printf("Nhap 0 de chuyen sang nhap node khac hoac thoat"); 
    T=CreateTree(p,x); //Nhap cay
        printf("Duyet cay theo thu tu giua LNR: \n");
            LNR(T);
            printf("\n");
                 printf("Duyet cay theo thu tu truoc NLR: \n");
             NLR(T);
             printf("\n");
 
            printf("Duyet cay theo thu tu sau LRN: \n");
            LRN(T);
            printf("\n");
//    Node *P;
//    
//    printf("Nhap vao key can tim: ");
//    scanf("%d", &x);
//    P = searchKey(T, x);
//    if (P != NULL) printf("Tim thay key %d\n", P->key);
//    else printf("Key %d khong co trong cay\n", x);
//  
//    if (delKey(T, x)) printf("Xoa thanh cong\n");
//    else printf("Khong tim thay key %d can xoan", x);
//    printf("Duyet cay theo thu tu giua: \n");
//    LNR(T);
//    printf("\n");
//}while(chon!=4);
    return 0;
}
