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
public:
string admin_name;
string admin_password;
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
void Admin::admin::add_subject() {
    string subject_name;
    string input;
    int num_questions;

    do {
        cout << "Enter subject name: ";
        getline(cin, subject_name);

        cout << "Enter the number of questions for the quiz: ";
        getline(cin, input);
        num_questions = stoi(input);

        vector<pair<string, char[4]>> questions_and_answers(num_questions);

        cout << "Enter questions and their answers for the quiz:" << endl;
        for (int i = 0; i < num_questions; ++i) {
            cout << "Question " << i + 1 << ": ";
            getline(cin, questions_and_answers[i].first);
            cout << "Enter options (a, b, c, d) for Question " << i + 1 << ":" << endl;
            cout << "Option a: ";
            getline(cin, input);
            questions_and_answers[i].second[0] = input[0];
            cout << "Option b: ";
            getline(cin, input);
            questions_and_answers[i].second[1] = input[0];
            cout << "Option c: ";
            getline(cin, input);
            questions_and_answers[i].second[2] = input[0];
            cout << "Option d: ";
            getline(cin, input);
            questions_and_answers[i].second[3] = input[0];
        }

        // Create a new Subject object
        Subjects new_subject;
        new_subject.subject_name = subject_name;

        for (int i = 0; i < num_questions; ++i) {
            for (int j = 0; j < 4; ++j) {
                new_subject.answers[i * 4 + j] = questions_and_answers[i].second[j];
            }
        }

        // Add the new subject to the subjects vector
        t.push_back(new_subject);

        // Create a new file for the subject and write the questions into it
        ofstream file("quiz_" + subject_name + ".txt");
        if (file.is_open()) {
            for (int i = 0; i < num_questions; ++i) {
                file << "Question " << i + 1 << ": " << questions_and_answers[i].first << endl;
                file << "Options: " << endl;
                file << "a) " << questions_and_answers[i].second[0] << endl;
                file << "b) " << questions_and_answers[i].second[1] << endl;
                file << "c) " << questions_and_answers[i].second[2] << endl;
                file << "d) " << questions_and_answers[i].second[3] << endl;
            }
            file.close();
            cout << "Subject added successfully and questions saved in quiz_" << subject_name << ".txt!" << endl;
        } else {
            cout << "Error: Unable to create file for the subject." << endl;
        }

        cout << "Do you want to add another subject? (yes/no): ";
        getline(cin, input);
    } while (input == "yes" || input == "Yes");
}



int main() {
    Admin::admin ad;
    Student::Student student("John Doe");

   cout << "Welcome to the Quiz System!" <<endl;
   cout << "1 to login as admin "<<endl;
   cout << "2 to login as student: "<<endl;
    int choice;
   cin >> choice;
   cin.ignore();

    if (choice == 1) {
        ad.SignIn();
        if (ad.admin_name == "Mehdi" && ad.admin_password == "2004") {
           cout << "Logged in as admin." <<endl;
            int option;
           cout << "Choose an option:" <<endl;
           cout << "1. Add student" <<endl;
           cout << "2. Remove students" <<endl;
           cout << "3. Display students" <<endl;
           cout << "4. Add subject" <<endl;
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
                default:
                   cout << "Invalid option." <<endl;
            }
        }
    } else if (choice == 2) {
       string username, password;
       cout << "Enter username: ";
       getline(std::cin, username);
       cout << "Enter password: ";
       getline(std::cin, password);

        if (student.login(username, password)) {
           cout << "Logged in as student." <<endl;
            int option;
           string subject;
           cout << "Choose an option:" <<endl;
           cout << "1. Take a quiz" <<endl;
           cout << "2. View quiz history" <<endl;
           cout << "Enter your choice: ";
           cin >> option;
           cin.ignore();
             
            switch (option) {
                case 1:
                   
                   cout << "Enter subject: ";
                   getline(std::cin, subject);
                    student.takeQuiz(subject, "quiz_" + subject + ".txt");
                    break;
                case 2:
                    student.viewQuizHistory();
                    break;
                default:
                   cout << "Invalid option." <<endl;
            }
        } else {
           cout << "Invalid username or password." <<endl;
        }
    }

    return 0;
}
