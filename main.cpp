#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std;

//DataBase of the Student and Subject

namespace DataBase{
   
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

struct Subjects{

  string subject_name;
  char answers[10];
 
};
 
  void function();

}

vector<DataBase::Student> students;
vector<DataBase::Subjects> t;

void DataBase::function(){

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

//ADMIN

namespace Admin{

class admin{

private:
string admin_name;
string admin_password;

public:



admin(){
        admin_name="Mehdi";
        admin_password="2004";
 }

            bool SignIn(){

            string ad,pass;
            cout<<"\nEnter the name:"<<endl;
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
         DataBase::Student newStudent[numstudents];
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

void displaySubjects();
void add_subject();

}; //class Admin Ends...

}//Namspace Admin ends

//-----------------------------------------------------------------------------------------------------------------------------------//



void Admin::admin::displaySubjects() {
    cout << "List of Subjects:" << endl;
    for (const auto& subject : t) {
        cout << subject.subject_name << endl;
    }
}

void Admin::admin::add_subject() {
    
    string subject_name;
    string input;
   
    do {

        cout << "Enter subject name: ";
        getline(cin, subject_name);

        DataBase::Subjects new_subject;
        new_subject.subject_name = subject_name;

        vector<pair<string, string>> questions_and_options(10);

        cout << "Enter questions and options (a, b, c, d) for the quiz:" << endl;
     
        for (int i = 0; i < 10; ++i) {
            cout << "Question " << i + 1 << ": ";
            getline(cin, questions_and_options[i].first);
            cout << "Enter options (a, b, c, d) for Question " << i + 1 << ":" << endl;
            cout << "Option a: ";
            getline(cin, questions_and_options[i].second);
            cout << "Option b: ";
            getline(cin, questions_and_options[i].second);
            cout << "Option c: ";
            getline(cin, questions_and_options[i].second);
            cout << "Option d: ";
            getline(cin, questions_and_options[i].second);
            cout << "Enter answer (a, b, c, d) for Question " << i + 1 << ": ";
            cin >> new_subject.answers[i];
            cin.ignore(); // Ignore newline character
        }

        // Add the new subject to the subjects vector
        t.push_back(new_subject);

        // Create a new file for the subject and write the questions into it
        ofstream file(subject_name + ".txt");
        if (file.is_open()) {
            for (int i = 0; i < 10; ++i) {
                file << "Question " << i + 1 << ": " << questions_and_options[i].first << endl;
                file << "Options: " << endl;
                file << "a) " << questions_and_options[i].second << endl;
                file << "b) " << questions_and_options[i].second << endl;
                file << "c) " << questions_and_options[i].second << endl;
                file << "d) " << questions_and_options[i].second << endl;
                file << "Answer: " << new_subject.answers[i] << endl;
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


//--------------------------------------------------------------------------------------------------------------------------------------//

namespace Student {

    class Student  {

    private :
        string name ;
               

    public:
            void takeQuiz(int number ,const string& subject, const string& answersFileName) {
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
                    if (choice == t[number].answers[i]) {
                        score++;
                    } 
                    ++i;
                }
                ++line;
            }

            file.close();
            ofstream files(name+".txt",ios::app);
            
            if(files.is_open()){
              
              files<<name<<endl;
              files<<subject<<endl;
              files<<score<<"/10"<<endl;
            
            }
            files.close();

        }

        void viewQuizHistory(){
           ifstream read(name+".txt");
           string store;
          while(getline(read,store)){
            cout<<store<<endl;
          }
          read.close();
        }

       bool login(const string& username, const string& password){
    for(auto & student : students){
        if(student.name == username && student.password == password){
            name = username; // Set the name of the student upon successful login
            return true;
        }
    }
    return false;
}
    };
}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


int main() {
   
    DataBase::function();
    bool admin_check;
    Admin::admin ad;
    
    bool check=true;
    bool a=true;
    bool s=true;
    Student::Student student;

do{
       int choice;
cout<<"\n\n\t\t\t\t---------- WELCOME to THE QUIZ SYSTEM !   -----------\n"<<endl;
       cout<<"\t\t\t\t\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
       cout<<"\t\t\t\t\t|                               |"<<endl;
       cout<<"\t\t\t\t\t|                               |"<<endl;
       cout<<"\t\t\t\t\t|  1:  LOGIN as ADMIN           |"<<endl; 
       cout<<"\t\t\t\t\t|  2:  LOGIN as STUDENT:        |"<<endl;
       cout<<"\t\t\t\t\t|  3:  EXIT                     |"<<endl;
       cout<<"\t\t\t\t\t|                               |"<<endl;
       cout<<"\t\t\t\t\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|"<<endl;
       cout<<"\n\t\t\t\t\tENTER YOUR CHOICE:";
                         cin >> choice;
                        
   cin.ignore();
  
    if (choice == 1) 
    {   
        admin_check=ad.SignIn();
       
        if (admin_check == true) {
            system("CLS"); 
            cout << "\nWELCOME ADMIN!" <<endl;
            cout<<"\n\t\t\t CHOOSE ANY OPTION :"<<endl<<endl;
       do{    
           int option;
       cout<<"\t\t\t\t\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
       cout<<"\t\t\t\t\t|                               |"<<endl;
       cout<<"\t\t\t\t\t|   1. ADD STUDENTS             |"<<endl; 
       cout<<"\t\t\t\t\t|   2. REMOVE STUDENTS          |"<<endl;
       cout<<"\t\t\t\t\t|   3. DISPLAY STUDENTS         |"<<endl;
       cout<<"\t\t\t\t\t|   4. ADD SUBJECTS             |"<<endl;
       cout<<"\t\t\t\t\t|   5. DISPLAY SUBJECT          |"<<endl;
       cout<<"\t\t\t\t\t|   6. EXIT                     |"<<endl;
       cout<<"\t\t\t\t\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|"<<endl;
       cout<<"\n\n\t\t\t\t\tENTER YOUR CHOICE:";
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
                    ad.displaySubjects();
                    break;
                case 6:
                     a=false;
                     system("CLS");
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
            int number;
           string subject;
       cout<<"\t\t\t\t\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
       cout<<"\t\t\t\t\t|  Choose an option:            |"<<endl;
       cout<<"\t\t\t\t\t|   1. Take a quiz              |"<<endl; 
       cout<<"\t\t\t\t\t|   2. View quiz history        |"<<endl;
       cout<<"\t\t\t\t\t|   3. Exit                     |"<<endl;
       cout<<"\t\t\t\t\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|"<<endl;
       cout<<"\t\t\t\t\t Enter your choice:";
                                 cin >> option;
          
            cin.ignore();
            switch (option) {

                case 1:
                   int number;
                   cout<<"\nFollowing are available Subjects"<<endl;
                   ad.displaySubjects();
                   cout << "Enter subject number : ";
                cin>>number;
                cin.ignore();
                --number;
                   subject=t[number].subject_name;
                    student.takeQuiz(number,subject,subject + ".txt");
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
   
   else if(choice==3){
   
    system("CLS");
     cout<<"\n\n\t\t\t\t         SUCCESSFULLY EXITED QUIZ SYSTEM........"<<endl;
    cout<<"\n\n";
    check=false;
   
   }

    }while(check);

}
