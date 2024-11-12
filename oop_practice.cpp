#include<iostream>
using namespace std;
class Student{
    public:
    int studentid ;
    string studentname ;
    double studentmark ;
Student() {
  studentid = 0 ;
  studentname ="Unknown" ;
  studentmark= 0.00;  
}
Student(int id,string name ,double mark){
   studentid = id ;
  studentname = name  ;
  studentmark = mark; 
}
void display(){
    cout<<"studentid: "<<studentid<<endl;
    cout<<"studentname: "<<studentname<<endl;
    cout<<"studentmark: "<<studentmark<<endl;

}
};
int main(){
    Student Student1;
    Student1.display() ;

    Student Student2(9,"jeny",88.99);
    Student2.display();

return 0;
}
