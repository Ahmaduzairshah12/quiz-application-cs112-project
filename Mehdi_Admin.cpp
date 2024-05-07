1#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;

#include<vector>

namespace Admin{

//ADMIN
class admin{

private:
string admin_name;
string admin_password;

public:

admin(){
	admin_name="Mehdi";
	admin_password="2004";
 
}

struct Student{
	
	string name;
  string password;
	string email;
   
  // Overloading the << operator to print a vector object
	//ostream objects can't be passed by value because they have a private copy constructor
	//  returns an ostream object to  cout.
		   
	friend ostream& operator<<(ostream& os,vector<Student>&st) {
   
    cout<<"\n         STUDENTS INFORMATION \n";
   
    for(int i=0;i<st.size();i++){
     
      cout<<"\nStudent "<<i+1<<"\n"<<endl;
      cout<<"Name:"<<st[i].name<<endl;
      cout<<"Password"<<st[i].password<<endl;
      cout<<"Email"<<st[i].email<<endl;
      
    }
  
    return os;
  
  }
  
};

vector<Student> students;

void SignIn(){

string ad,pass;

cout<<"Enter the name:"<<endl;
getline(cin,ad);

cout<<"Enter the password:"<<endl;
getline(cin,pass);

   if(ad==admin_name && pass==admin_password){
	        cout<<"LOGGED IN"<<endl;
     } 
   else{
	    cout<<"Incorrect Username or Password:"<<endl;
     }
 } //SIGN IN Ends...

   void addstudent(){
 
	 int numstudents;
	 
	 cout<<"Enter number of students you want to add:"<<endl;
	 cin>>numstudents;
	 Student newStudent[numstudents];
	 cin.ignore();

      for(int i=0;i<numstudents;i++){
	   
	   cout<<"Enter the name of Student "<<i+1<<":"<<endl;
	   getline(cin,newStudent[i].name);
	   
	   cout<<"Enter the password of student "<<i+1<<":"<<endl;	
     getline(cin,newStudent[i].password);

	   cout<<"Enter the email of Student "<<i+1<<":"<<endl;
	   getline(cin,newStudent[i].email);

	   students.push_back(newStudent[i]);

	  }

   

  }//ADD Student Ends...


  void removestudents(){
 
   display_students();
    
    int remove;
    cout<<"How many students you want to remove ?:"<<endl;
    cin>>remove;
    cin.ignore();
    int num;
    num=students.size();
    cout<<endl;
    
    do{
      
      int index;
      
      cout<<"\nTELL ME WHICH STUDENT TO REMOVE FROM BELOW LIST:"<<endl;
      display_students(); 
      cout<<"\nStudent:";
      cin>>index;
      cin.ignore();
      
      if(index>num){
        cout<<"No student exist of that number from the list"<<endl;
        break;
      }

      --index;
      for(int i=0;i<num;i++){
        
        if(i==index){
          students.erase(students.begin()+i);
          cout<<"Student "<<i+1<<"is removed successfully"<<endl;
        }
      
      }  
      --num;
      --remove;
    
    }while(remove>0);
  
  }
  
  
  void display_students(){
    cout<<students;
    cout<<"\nTotal number of students are:"<<students.size()<<endl;
  } //Display Student Ends...

struct Subjects{

  string subject_name;
   
  char answers[10];
    
    void function(string file){
    
     cout<<"\nSUBJECT: "<<subject_name<<endl<<endl;
    
     ifstream obj(file);
  
     string store;
     
     char choice;
     int line=1;
     int i=0;
        
        while(getline(obj,store)){
     
          cout<<store<<endl;
    
          if(line%6==0){
            
            cout<<"\n";
            cout<<"Choose a,b,c,d"<<endl;
            cin>>choice;
            cin.ignore();
          
          if(choice==answers[i]){
           
            cout<<"\nCORRECT"<<endl<<endl;    
        }

        else{
           
            cout<<"\nINCORRECT"<<endl<<endl;
        }
        ++i;
        }

    ++line;
   }
 }


};

void function();

}; //class Admin Ends...

}//Namspace Admin ends


vector<Admin::admin::Subjects> t;

void Admin :: admin::function(){

Subjects s1[4];
s1[0].subject_name="C++";

char c[] = "dcbdcadcdd";
char python[]="cdbcadabbd";
char javascript[]="aabadbbaac";
char java[]="bdcbcddcbb";

for(int i=0;i<10;i++){
  s1[0].answers[i]=c[i];
  s1[3].answers[i]=python[i];
  s1[2].answers[i]=javascript[i];
  s1[1].answers[i]=java[i];
}

s1[1].subject_name="JAVA";
s1[2].subject_name="JAVA SCRIPT";
s1[3].subject_name="PYTHON";

for(int i=0;i<4;i++){
t.push_back(s1[i]);
}

}

int main(){
Admin::admin a;
// a.SignIn();
// a.addstudent();
// a.removestudents();

    a.function();
    string name[4]={"C++.txt","JAVA.txt","JAVASCRIPT.txt","PYTHON.txt"};
 
    for(int i=0;i<4;i++){
      t[i].function(name[i]);
    }
   
   
}
