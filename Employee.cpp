#include<iostream>
using namespace std;
class Employee {
public :
   int employeeID;
   string name ;
   double salary ;

   Employee() {
        employeeID = 0;
        name = "Unknown";
        salary = 0.0;
   }
Employee( int id, string emlopyeename , double emlopyeesalary){
     employeeID = id;
     name = emlopyeename ;
    salary = emlopyeesalary ;
}
void display(){
     cout<<"employeeID:"<<" "<<employeeID<<endl;
    cout<<"name:"<<" "<<name<<endl;
    cout<<"salary:"<<" "<<salary<<endl;
}
};
int main(){
    Employee employee1 ;
    employee1.display();
    
    Employee employee2(2003,"jeny",9999.89);
    employee2.display();

}