//binary tree之應用 
#include<iostream>
using namespace std;
class BST;
class TreeNode{
private:
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    int num;
public:
    TreeNode():left(0),right(0),parent(0),num(0){};
    TreeNode(int a):left(0),right(0),parent(0),num(a){};
    int getnum(){
		return num;
	}
    friend class BST;   
};
class BST{
private:
    TreeNode *root;
public:
    BST():root(0){};    
    TreeNode* leftmost(TreeNode *current){									//leftmost
    while (current->left != NULL){
        current = current->left;
    }
    return current;
	}
    TreeNode* InorderSuccessor(TreeNode *current){							//seccesor 
    if (current->right != NULL){
        return leftmost(current->right);
    }

    TreeNode *successor = current->parent;   
    while (successor != NULL && current == successor->right) {
        current = successor;
        successor = successor->parent;
    }
    return successor;
	}
    TreeNode* Search(int N){ 												//查詢是否有N 
    	TreeNode *current = root;               
   		 while (current != NULL && N != current->num) {  					//1.沒找到2.找到跳出迴圈 
       		if (N < current->num)                  
            	current = current->left;  		
        	else 
            	current = current->right;  
        }
		return current;
	}
    void Insert(int N){														 
    	TreeNode *x = 0;   													
		TreeNode *y = 0;     												
    	TreeNode *insert_node = new TreeNode(N);   
		x = root;
    	while (x != NULL) {                      
        	y = x;                        
      	 	if (insert_node->num < x->num) 						//判斷放左右 
            	x = x->left;
       	 	else if(insert_node->num > x->num )
            	x = x->right;
            else{												//若有一樣Delete 
            	Delete(N);
            	return;
			}
    	}                                                    		        
    	insert_node->parent = y;          
    	if (y == NULL){
        	root = insert_node;
        }
    	else if (insert_node->num < y->num){
        	y->left = insert_node;
        }
    	else if (insert_node->num > y->num)
        	y->right = insert_node;
        
	}
    void Delete(int N){               										//Delete N; 
		TreeNode *delete_node = Search(N);    
    	TreeNode *y = NULL;              
    	TreeNode *x = NULL;   
    if (delete_node->left == NULL || delete_node->right == NULL)
        y = delete_node;
    else
        y = InorderSuccessor(delete_node);        
		                       				                                 
    if (y->left != NULL)
        x = y->left;                  
    else
        x = y->right;
    

    if (x != NULL){                        
   		x->parent = y->parent;           
    }
   
    if (y->parent == NULL)              
        this->root = x;
    else if (y == y->parent->left)   
        y->parent->left = x;           
    else                                  
        y->parent->right = x;          
   
    if (y != delete_node)                 
        delete_node->num = y->num;          
    
    delete y;                               
    y = 0;
}

void output()								//output結果 
{
    //print node
    TreeNode *current = leftmost(root);
    cout << "node:  ";
    while ( current != NULL )
    {
        cout << current->num << " ";
        current = InorderSuccessor(current);
    }
    cout << "\n";
    current = leftmost(root);
    cout << "left:  ";
    while ( current != NULL )
    {
        if( current->left == NULL )
            cout << "0 ";
        else
            cout << current->left->num << " ";
        current = InorderSuccessor(current); 
    }
    cout <<endl<< "right: ";
    current = leftmost(root);
    while ( current != NULL )
    {
        if( current->right == NULL )
            cout << "0 ";
        else
            cout << current->right->num << " ";
        current = InorderSuccessor(current); 
    }
    cout << "\n";
}
}; 
int main(){
	int N;
	while(cin>>N){
		BST bst;
		if( N == -1 )
            break;
        bst.Insert(N);
		while(cin>>N){
				if(N==-1)
				break;
			bst.Insert(N); 
		}
		bst.output();
	}
}
