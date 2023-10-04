//建造C++的集合類別
#include<iostream>
#include<string.h>
using namespace std;

class TSet{
	public:
		TSet();						
		string get();              //取得字串 
		void set();				   //字母和0,1轉換 
		void display();			   //印出 
		friend istream& operator >>(istream& inputStream,TSet& T);  //輸入 
		friend TSet operator + (TSet &T1,TSet &T2);      //聯集 
		friend TSet operator * (TSet &T1,TSet &T2);      //交集
		friend TSet operator - (TSet &T1,TSet &T2);      //差集 
		friend bool operator >= (TSet &T1,TSet &T2);     //包含 
	private:
		char a[256];
		string str;
}; 

TSet::TSet()                  //初始化 
{
	for(int i=0;i<256;i++)
	{
		a[i]='0';
	}
}


string TSet::get()          
{
	return str;
}


void TSet::set()
{
	
	
	
	for(int i=0;i<256;i++)
	{
		a[i]='0';
	}
	
	
	
//	cout<<endl<<str<<endl;
	for(int i=0 ; i<256 ; i++ )               //256個ascii code碼 
	{
		for( int j=0 ; j<str.size() ; j++ )    
		{
			if( str[j] == i)                 //有此字元為1 
			{
				a[i]='1';
				break;                       //重複字元跳過 
			}else
				a[i]='0';                    //反之為0 
		}
	}
	
	
 
}


void TSet::display()                        //輸出 
{
	
	for( int i=0; i<256 ; i++ )
	{
		char temp = i;
	
		if( a[i] == '1' )
			cout <<temp;
			
	}
}


istream& operator >> ( istream& inputStream, TSet& T )   //class輸入 
{
	
	
	
	getline(inputStream,T.str);
//	return inputStream;
//	inputStream.ignore();
	//T.str=a;
	//inputStream >> T.str;
}


TSet operator + (TSet& T1, TSet& T2)         //聯集( T1 or T2) 
{  
	TSet T3;
	for(int i=0;i<256;i++)
	{
		if( T1.a[i]=='1' || T2.a[i]=='1' )
			T3.a[i]='1';
	}
	
	return T3;
}



TSet operator * (TSet& T1, TSet& T2)         //交集(T1 AND T2) 
{
	TSet T3;
	for(int i=0;i<256;i++)
	{
		if( T1.a[i]=='1' && T2.a[i]=='1' )
			T3.a[i]='1';
	}
	
	return T3;
}

TSet operator - (TSet& T1, TSet& T2)         //差集(T1 AND ~T2) 
{
	TSet T3;
	for(int i=0;i<256;i++)
	{
		if( T1.a[i]=='1' && T2.a[i]=='0' )
			T3.a[i]='1';
	}
	
	return T3;
}

bool operator >= (TSet& T1, TSet& T2)        //包含(T1 AND T2 = T2) 
{
	TSet T3 = T1*T2;
	for(int i=0; i<256 ; i++ )
	{
		if( T3.a[i] != T2.a[i] )
			return false;
	}
	
	return true;
}

int main()
{
	int n = 0;
	cin >> n;
	TSet TA[100],TB[100],TC[100],TD;
	 
	cin.ignore();
	
	for( int i=0 ; i<n ; i++ )
	{
		
		cin >> TA[i];
		cin >> TB[i];
		cin >> TC[i];
		TA[i].set();
		TB[i].set();
		TC[i].set(); 
	}
	
	for( int i=0 ; i<n ; i++ )
	{
		cout<<endl;
		cout<<"Test Case "<< i+1 <<":"<<endl;
		cout<<"A: {";
		TA[i].display();
		cout<<"}"<<endl;
		cout<<"B: {";
		TB[i].display();
		cout<<"}"<<endl;
		TD = TA[i] + TB[i];
		cout<<"A+B: {";
		TD.display();
		cout<<"}"<<endl;
		TD = TA[i] * TB[i];
		cout<<"A*B: {";
		TD.display();
		cout<<"}"<<endl;
		TD = TA[i] - TB[i];
		cout<<"A-B: {";
		TD.display();
		cout<<"}"<<endl;
		TD = TB[i] - TA[i];
		cout<<"B-A: {";
		TD.display();
		cout<<"}"<<endl;
		
		if( TA[i] >= TB[i] )
			cout<<"A contains B"<<endl;
		else
			cout<<"A does not contain B"<<endl;
		
		if( TB[i] >= TA[i] )
			cout<<"B contains A"<<endl;
		else
			cout<<"B does not contain A"<<endl;
		
		if( TA[i] >= TC[i] )
			cout << "'" << TC[i].get() << "'" <<" is in A"<<endl;
		else
			cout << "'" << TC[i].get() << "'" <<" is not in A"<<endl;
		if( TB[i] >= TC[i] )
			cout << "'" << TC[i].get() << "'" <<" is in B"<<endl;
		else
			cout << "'" << TC[i].get() << "'" <<" is not in B"<<endl;
		
		
		
		
	}
	
}
