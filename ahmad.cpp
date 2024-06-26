#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<vector>
#include<cstdlib>
using namespace std;

namespace Admin{

//ADMIN

class admin{

private:
string admin_name;
string admin_password;
public:
void add_subject();

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

            bool SignIn(){
           
            string ad,pass;
            cout<<"Enter the name:"<<endl;
            getline(cin,ad);
            cout<<"Enter the password:"<<endl;
            getline(cin,pass);
            if(ad==admin_name && pass==admin_password){
                            cout<<"LOGGED IN"<<endl;
                            return true;
                } 
            else{
                    
                        return false;
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

void Admin::admin::add_subject() {
   
    string subject_name;
    char answers[10];

    cout << "Enter subject name: ";
    getline(cin, subject_name);

    cout << "Enter answers for the quiz (e.g., abcdabcdab): ";
    for (int i = 0; i < 10; ++i) {
        cin >> answers[i];
    }
    cin.ignore(); // Ignore newline character

    // Create a new Subject object
    Subjects new_subject;
    new_subject.subject_name = subject_name;
   
    for (int i = 0; i < 10; ++i) {
        new_subject.answers[i] = answers[i];
    }

    // Add the new subject to the subjects vector
    t.push_back(new_subject);

    cout << "Subject added successfully!" << endl;
}


int main() {
    bool admin_check;
    Admin::admin ad;
    bool check=true;
    bool a=true;
    bool s=true;
    Student::Student student("John Doe");
 
  do{
  
   cout << "Welcome to the Quiz System!" <<endl;
   cout << "1 to login as admin "<<endl;
   cout << "2 to login as student: "<<endl;
    
   int choice;
   cin >> choice;
   cin.ignore();
   
   
   
    if (choice == 1) {
       
        admin_check=ad.SignIn();
        if (admin_check == true) {
            cout << "Welcome Admin!" <<endl;

   do{    
           
         
           int option;
           cout << "Choose an option:" <<endl;
           cout << "1. Add student" <<endl;
           cout << "2. Remove students" <<endl;
           cout << "3. Display students" <<endl;
           cout << "4. Add subject" <<endl;
           cout<<  "5. Exit"<<endl;
           cout << "Enter your choice: ";
           cin >> option;
           cin.ignore();

            switch (option) {
         
                case 1:
                    ad.addstudent();
                    break;
         
                case 2:
                    ad.removestudents();
                    break;
             
                case 3:
                    ad.display_students();
                    break;
             
                case 4:
                    ad.add_subject();
                    break;
                case 5:
                     a=false;
                     break;
                default:
                   cout << "Invalid option." <<endl;
            }
        
    }while(a);
        }
        else{
            cout << "Invalid username or password." <<endl;
        }
    }
     
      
       
       if (choice == 2) {
       do{
       string username, password;
       cout << "Enter username: ";
       getline(cin, username);
       cout << "Enter password: ";
       getline(cin, password);

        if (student.login(username, password)) {
           cout << "Logged in as student." <<endl;
            int option;
           string subject;
           cout << "Choose an option:" <<endl;
           cout << "1. Take a quiz" <<endl;
           cout << "2. View quiz history" <<endl;
           cout<<"  3. Exit"<<endl;
           cout << "Enter your choice: ";
           cin >> option;
           cin.ignore();

            switch (option) {
                
                case 1:
                   cout << "Enter subject: ";
                   getline(cin, subject);
                    student.takeQuiz(subject, "quiz_" + subject + ".txt");
                    break;
                case 2:
                    student.viewQuizHistory();
                    break;
                case 3:
                s=false;
                 break;
                default:
                   cout << "Invalid option." <<endl;
            }
        } else {
           cout << "Invalid username or password." <<endl;
        }
    }while(s); }
    
    
    }while(check);

}
