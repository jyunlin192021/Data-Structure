//linked list之應用
#include<iostream>
using namespace std;
class Node{
	private:
		int coef; //係數 
		int exp;  //次方 
		Node *next;
	public:
		Node(){
			next=NULL;
		}
		friend class Poly;
};
class Poly{
	private:
			Node *first;
	public:
		Poly(){
			first=NULL;
		}
		bool isEmpty(){								//判斷linked list內是否為空 
			if(first==NULL){
				return true;
			}
			else
				return false;
		}
		void Delete(int c){							//刪除Linked list內係數為c的node,此題用來刪除係數為0的node 
			Node *current=first;
			Node *previous=NULL;
			while(current!=NULL&&current->coef!=c){
				previous=current;
				current=current->next;
			}
			if(first==current){
				first=current->next;
				delete current;
				current=NULL;
			}
			if(current!=first&&current!=0){
				previous->next=current->next;
				delete current;
				current=NULL;
			}		
		}
		void AddNode(int c,int e){					//加入新的node,並將相同次方的項相加,且按照降冪排列 
			Node *newNode=new Node;
			Node *current=first;
			Node *previous=NULL;
			newNode->coef=c;
			newNode->exp=e;
			while(current!=NULL&&current->exp>e){
				previous=current;
				current=current->next;
			}
			if(first==NULL){		
				first=newNode;
				newNode->next=NULL;
				delete current;
				current=NULL;
			}
			else if(first==current&&current->exp<e){
				newNode->next=current;
				first=newNode;
			}
			else if(current==NULL){
				previous->next=newNode;
				newNode->next=NULL;
				delete current;
				current=NULL;
			}
			else if(current->exp==newNode->exp){
				current->coef+=c;
				Delete(0);
			}
			else{	
				newNode->next=current;
				previous->next=newNode;
			}	
		}
		void Print(){										//印出結果 
			Node *current=new Node;
			int k=0;
			current=first;
			if(first==NULL)
				cout << "0 0"<<endl;
			while(current!=NULL){
				cout << current->coef << " "<<current->exp;
				current=current->next;
				cout <<endl;
			}
		//	cout <<endl;
		} 
		Poly operator + (const Poly& b){					//operator '+'
			Poly c;
			Node *temp1=new Node;
			Node *temp2=new Node;
			temp1=first;
			temp2=b.first;
			while(temp1!=NULL){
				c.AddNode(temp1->coef,temp1->exp);	
				temp1=temp1->next; 
			} 
			while(temp2!=NULL){
				c.AddNode(temp2->coef,temp2->exp);
				temp2=temp2->next; 
			} 
					return c;
		}
		Poly operator *(const Poly& b){						//	//operator '*'
			Poly c;
			Node *temp1=new Node;
			Node *temp2=new Node;
			temp1=first;
			temp2=b.first;
			while(temp2!=NULL){
				while(temp1!=NULL){
					c.AddNode((temp1->coef)*(temp2->coef),(temp1->exp)+(temp2->exp));
					temp1=temp1->next;
				}
				temp2=temp2->next;
				temp1=first;
			} 
			return c;
		}
}; 

int main(){
	Poly A[100],B[100],C[100],D[100];
	int P,Q,c,e,num=0;
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	while(1){
		cin >> P;
		for(int i=0;i<P;i++){
			cin >> c >> e;
			A[num].AddNode(c,e);
		}
		cin >> Q;
		for(int i=0;i<Q;i++){
			cin >> c >> e;
			B[num].AddNode(c,e);
		}
		if(P==0&&Q==0)
			break;
		C[num]=A[num]+B[num];
		D[num]=A[num]*B[num];
		cout << "Case " << num+1 << ":\n";
		cout << "ADD\n"; 
		C[num].Print();
		cout << "MULTIPLY\n";
		D[num].Print();
		num++;
	}
}






