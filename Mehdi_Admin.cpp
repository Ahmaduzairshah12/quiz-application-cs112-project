#include<iostream>
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
   
     // Overloading the << operator to print a Student object
        friend ostream& operator<<(ostream& os, const Student& student) {
               
			    os << "Name: " << student.name << endl;
                os << "Password: " << student.password << endl;
                os << "Email: " << student.email << endl;
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
 } //SIGN IN ends

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

  }//ADD Student ends

  void display_students(){
    for(auto& student:students){
		cout<<student<<" "<<endl;
	}
  }

}; //class Admin ends



}//Namspace Admin ends

int main(){
Admin::admin a;
a.SignIn();
a.addstudent();
a.display_students();
a.addstudent();
a.display_students();
}
