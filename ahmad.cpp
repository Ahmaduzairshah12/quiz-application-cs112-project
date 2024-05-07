#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<vector>
using namespace std;
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

//-----------------------------------------------------------------------------------------------------------------------------------//
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
//--------------------------------------------------------------------------------------------------------------------------------------//

namespace Student {
   
    class Student : public Admin::admin {
    private :
        string name ;
        vector<pair<string, int>> quizResults; // Pair of (subject, score)
    public:
        Student(string _name) : name(_name) {}
        void takeQuiz(const string& subject, const string& answersFileName) {
            ifstream file(answersFileName);
            if (!file.is_open()) {
                cout << "Error: Unable to open file." << endl;
                return;
            }

            string answers;
            int score = 0;
            char choice;
            
            int line = 1;
            int i = 0;
            string store;
            while (getline(file, store)) {
                cout << store << endl;
                if (line % 6 == 0) {
                    cout<<"\n";
                    cout << "Choose a, b, c, d: ";
                    cin >> choice;
                    cin.ignore();
                    cout<<"\n";
                    if (choice == answers[i]) {
                        score++;
                    } 
                    ++i;
                }
                ++line;
            }

            file.close();
            quizResults.push_back(make_pair(subject, score));

        }

        void viewQuizHistory() {
            cout << "\nQUIZ HISTORY FOR STUDENT: " << name << endl<<endl;
            for (const auto& result : quizResults) {
                cout << "Subject: " << result.first << ", Score: " << result.second << "/10" << endl;
            }
        }
        bool login(const string& username, const string & password){
            for(auto & student : Admin::admin::students){
                if(student.name == username && student.password == password){
                    return true;
                }
            }return false;
        }
    };
}
int main() {
    Admin::admin admin_1;
    int choice;
    while (true) {
        std::cout << "1. Sign in" << std::endl;
        std::cout << "2. Add student" << std::endl;
        std::cout << "3. Remove students" << std::endl;
        std::cout << "4. Display students" << std::endl;
        std::cout << "5. Quiz" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
               // admin_1.signIn();
                break;
            case 2:
                admin_1.addstudent();
                break;
            case 3:
                admin_1.removestudents();
                break;
            case 4:
                admin_1.display_students();
                break;
        
            case 6:
                return 0;
     default:
                std::cout << "Invalid choice selected ." << std::endl;
            break;
        }
    }
    return 0;
}

