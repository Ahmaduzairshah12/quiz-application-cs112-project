#include<iostream>
#include<cstdlib>
#include<ctime>

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

  int addstudent(){
 
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

    return numstudents;

  }//ADD Student Ends...


  void removestudents(int stud,Admin::admin a){
 
   a.display_students();
   cout<<"\nTotal students"<<stud<<endl;
   int index;
   cout<<"\nEnter the student you wish to remove:"<<endl;
   cin.ignore();
  }
  
  
  void display_students(){
    cout<<students;
  } //Display Student Ends...


  


}; //class Admin Ends...



}//Namspace Admin ends

int main(){
Admin::admin a;
a.SignIn();
int total_students=a.addstudent();
a.removestudents(total_students,a);
a.display_students();

}
