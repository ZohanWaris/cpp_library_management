#include <iostream>
#include <vector>
using namespace std;
vector<int>rollNoVec;
vector<string>nameVec;
vector<string>reservedVec;
vector<int>reservingStdVec;
string lib[]={"English","Math","Physics","Chemistry","Computer"};
int size= sizeof(lib)/sizeof(lib[0]);
void regFun(){
	string n; int rn;
	cout<<"Enter Student RollNO: ";
	cin>>rn;
	cout<<"Enter Student Name: ";
	cin>>n;
	rollNoVec.push_back(rn);
	nameVec.push_back(n);
	cout<<"You are Registerd Successfuly"<<endl;	
}

void resFun(){
	int rn;string book;
	cout<<"Enter Your RollNo: ";
	cin>>rn;
	
	bool Rfound=false;
	bool Bfound=false;
	
	for(int i=0;i<rollNoVec.size();i++){
		if(rn==rollNoVec[i]){
			Rfound=true;
			cout<<"Enter Book Name: ";
			cin>>book;
			for(int j=0;j<size; j++){
			
			 if(book==lib[j]){
				Bfound=true;
				reservedVec.push_back(book);
				reservingStdVec.push_back(rn);
				cout<<"Book is reserved Successfuly for "<<
				rn<<endl;
				
			}
	}
			
			break;
		}
	}
	if(!Rfound){
		cout<<"RollNo is not Registered!"<<endl;
		cout<<" "<<endl;
	}
	if(!Bfound){
		cout<<"Invalid Book Name"<<endl;
		cout<<" "<<endl;
	}
}

void listFun(){
	cout<<"List of Returnable Books"<<endl;
	cout<<"************************"<<endl;
	for(int i=0;i<reservedVec.size();i++){
		cout<<"Book: "<<reservedVec[i]<<" reserved by: "<<
		reservingStdVec[i]<<endl;
		cout<<" "<<endl;
	}
}

void returnFun(){
	int rn; string book;
	cout<<"Enter RollNo: ";
	cin>>rn;
	cout<<"Ente Book Name: ";
	cin>>book;
	bool Found=false;
	for(int i=0;reservedVec.size();i++){
	 if(rn==reservingStdVec[i] && book==reservedVec[i]){
	 	Found=true;
	 	reservedVec.erase(reservedVec.begin()+i);
	 	reservingStdVec.erase(reservingStdVec.begin()+i);
	 	cout<<"Book Returned to Library"<<endl;
	 	break;
	 	
	 }
	}
	if(!Found){
		cout<<"Invalid RollNo or Book Name"<<endl;
	}
	
}

int main(){
	while(true){
		cout<<"Library Management System"<<endl;
		cout<<"========================="<<endl;
		cout<<"0.List Returnable Books."<<endl;
		cout<<"1.Register Student."<<endl;
		cout<<"2.Reserve a Book."<<endl;
		cout<<"3.Return a Book."<<endl;
		cout<<"4.Exit."<<endl;
		cout<<"Enter Your Choice: ";
		int choice;
		cin>>choice;
		
		if(choice==0){
			//ruturnable list
			system("cls");
			listFun();
			cout<<" "<<endl;
		}
		
		else if(choice==1){
			//register std
			system("cls");
			regFun();
			cout<<" "<<endl;
		}
		else if(choice==2){
			//reserve a book
			system("cls");
			resFun();
			cout<<" "<<endl;
		}
		else if(choice==3){
			//return book
			system("cls");
			returnFun();
			cout<<" "<<endl;
		}
		else if(choice==4){
			//exit from prog
			system("cls");
			cout<<"Best of Luck!";
			cout<<" "<<endl;
			break;
		}
		else{
			system("cls");
			cout<<"Invalid Input!";
			cout<<" "<<endl;
		}
	}
}
