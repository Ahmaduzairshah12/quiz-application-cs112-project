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
 }

}; //class Admin ends


}//Namspace Admin ends

int main(){
Admin::admin a;
a.SignIn();
}
