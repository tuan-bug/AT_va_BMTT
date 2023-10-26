#include<iostream>
#include<string>
using namespace std;
struct tree {
    int info;
    tree *Left, *Right;
};
tree* root;
class Binary_tree {
public:
    Binary_tree();
    void insert1(int);
    tree* insert2(tree*, tree*);
    void Delete(int);
    void pretrav(tree*);
    void intrav(tree*);
    void posttrav(tree*);
    int maxTree(tree*);
    int countLeaf(tree*);
};

Binary_tree::Binary_tree()
{
    root = NULL;
}
tree* Binary_tree::insert2(tree* temp, tree* newnode)
{
    if (temp == NULL) {
        temp = newnode;
    }
    else if (temp->info < newnode->info) {
        insert2(temp->Right, newnode);
        if (temp->Right == NULL)
            temp->Right = newnode;
    }
    else {
        insert2(temp->Left, newnode);
        if (temp->Left == NULL)
            temp->Left = newnode;
    }
    return temp;
}
int Binary_tree::countLeaf(tree* T = root)
{   
	if(T==NULL)
 		return 0;
    else
       if(T->Left==NULL && T->Right==NULL)
			return 1;
       else
	    	return countLeaf(T->Left)+countLeaf(T->Right);
}

int Binary_tree::maxTree(tree *T = root){
	if (T==NULL) 
        return 0;
    else
    {
         /* compute the depth of each subtree */
          int lDepth = maxTree(T->Left);
          int rDepth = maxTree(T->Right);
 
          /* use the larger one */
          if (lDepth > rDepth) 
                return(lDepth+1);
          else 
               return(rDepth+1);
   }
}
void Binary_tree::insert1(int n)
{
    tree *temp = root, *newnode;
    newnode = new tree;
    newnode->Left = NULL;
    newnode->Right = NULL;
    newnode->info = n;
    root = insert2(temp, newnode);
}
void Binary_tree::pretrav(tree* t = root)
{
    if (root == NULL) {
        cout << "Nothing to display";
    }
    else if (t != NULL) {
        cout << t->info << " ";
        pretrav(t->Left);
        pretrav(t->Right);
    }
}
void Binary_tree::intrav(tree* t = root)
{
    if (root == NULL) {
        cout << "Nothing to display";
    }
    else if (t != NULL) {
        intrav(t->Left);
        cout << t->info << " ";
        intrav(t->Right);
    }
}
void Binary_tree::posttrav(tree* t = root)
{
    if (root == NULL) {
        cout << "Nothing to display";
    }
    else if (t != NULL) {
        posttrav(t->Left);
        posttrav(t->Right);
        cout << t->info << " ";
    }
}
void Binary_tree::Delete(int key)
{
    tree *temp = root, *parent = root, *marker;
    if (temp == NULL)
        cout << "The tree is empty" << endl;
    else {
        while (temp != NULL && temp->info != key) {
            parent = temp;
            if (temp->info < key) {
                temp = temp->Right;
            }
            else {
                temp = temp->Left;
            }
        }
    }
    marker = temp;
    if (temp == NULL)
        cout << "No node present";
    else if (temp == root) {
        if (temp->Right == NULL && temp->Left == NULL) {
            root = NULL;
        }
        else if (temp->Left == NULL) {
            root = temp->Right;
        }
        else if (temp->Right == NULL) {
            root = temp->Left;
        }
        else {
            tree* temp1;
            temp1 = temp->Right;
            while (temp1->Left != NULL) {
                temp = temp1;
                temp1 = temp1->Left;
            }
            if (temp1 != temp->Right) {
                temp->Left = temp1->Right;
                temp1->Right = root->Right;
            }
            temp1->Left = root->Left;
            root = temp1;
        }
    }
    else {
        if (temp->Right == NULL && temp->Left == NULL) {
            if (parent->Right == temp)
                parent->Right = NULL;
            else
                parent->Left = NULL;
        }
        else if (temp->Left == NULL) {
            if (parent->Right == temp)
                parent->Right = temp->Right;
            else
                parent->Left = temp->Right;
        }
        else if (temp->Right == NULL) {
            if (parent->Right == temp)
                parent->Right = temp->Left;
            else
                parent->Left = temp->Left;
        }
        else {
            tree* temp1;
            parent = temp;
            temp1 = temp->Right;
            while (temp1->Left != NULL) {
                parent = temp1;
                temp1 = temp1->Left;
            }
            if (temp1 != temp->Right) {
                temp->Left = temp1->Right;
                temp1->Right = parent->Right;
            }
            temp1->Left = parent->Left;
            parent = temp1;
        }
    }
    delete marker;
}
int main()
{	int countNode;
    Binary_tree bt;
    int choice, n, key;
    while (1) {
        cout << "\n\t1. Insert\n\t2. Delete\n\t3. Preorder Traversal\n\t4. Preorder Treversal\n\t5. Postorder Traversal \n\t6. Lenght Tree \n\t7. Count Leaf \n\t8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Nh?p vao so luong Node: " ;
            cin >> countNode;
            for(int i = 0; i < countNode ;i++){
            	cout <<"Nhap node thu : " << i + 1 << " :";
            	 cin >> n;
            	bt.insert1(n);
			}
           
            break;
        case 2:
            cout << "Enter element to delete: ";
            cin >> key;
            bt.Delete(key);
            break;
        case 3:
            cout << endl;
            bt.pretrav();
            break;
        case 4:
            cout << endl;
            bt.intrav();
            break;
        case 5:
            cout << endl;
            bt.posttrav();
            break;
        case 6:
            cout << endl;
            cout <<"Do cao cua cay: " << bt.maxTree();
            break;
        case 7:
            cout << endl;
            cout <<"So la cua cay: " << bt.countLeaf();
            break;
        
        case 8:
            exit(0);
        }
    }
    return 0;
}
