//code1 demonstrate constructor overloading  

/*
#include <iostream>  
using namespace std;  
class Person {  
private:  
    int age;  
public:  
    Person(){  
    age = 20; }  
 Person(int a){   
    age = a;  }  
int getAge( ) { 
return age;  
  }  
};  
int main()  
{  
    Person person1, person2(45);  
    cout<< "Person1 Age = " << person1.getAge() <<endl;  
    cout<< "Person2 Age = " << person2.getAge() <<endl;  
}
*/

//code2 demonstrate constructor overloading  
/*
#include <iostream>
using namespace std; 
class Room {
   private:
    double length;
    double breadth;
   public:
    Room() {
        length = 6.9;
        breadth = 4.2;
    }
    Room(double l, double b) {
        length = l;
        breadth = b;
    }
    Room(double len) {
        length = len;
        breadth = 7.2;
    }
    double calculateArea() {
        return length * breadth;
    }
};
int main() {
    Room room1, room2(8.2, 6.6), room3(8.2);

    cout << "When no argument is passed: " << endl;
    cout << "Area of room = " << room1.calculateArea() << endl;

    cout << "\nWhen (8.2, 6.6) is passed." << endl;
    cout << "Area of room = " << room2.calculateArea() << endl;

    cout << "\nWhen breadth is fixed to 7.2 and (8.2) is passed:" << endl;
    cout << "Area of room = " << room3.calculateArea() << endl;
}
*/

//code 3 Constructor overloading
/*
#include <iostream>
using namespace std;
class construct
{ 
public:
    float area; 
    construct()
    {
         area = 0;// defualt constructor
    }
    construct(int a, int b)
    {
        area = a * b; // paramiterize constructor
    }
    void disp()
    {
        cout<< area<< endl;
    }
};
 
int main()
{   construct o;
    construct o2( 10, 20);
     
    o.disp();
    o2.disp();
    return 1;
}

*/

//code 4 Constructor and Destructor Example

/*
#include <iostream>  
using namespace std;  
class Employee  
 {  
   public:  
        Employee()    
        {    
            cout<<"Constructor Invoked"<<endl;    
        }    
        ~Employee()    
        {    
            cout<<"Destructor Invoked"<<endl;    
        }  
};  
int main(void)   
{  
    Employee e1; 
    Employee e2; 
    return 0;  
}  

*/

//code 5 Pointer
/*
#include <iostream>  
using namespace std;  
class Employee {  
   public:  
       int id;   
       string name;
       float salary;  
       Employee(int id, string name, float salary)    
        {    
             this->id = id;    
            this->name = name;    
            this->salary = salary;   
        }    
       void display()    
        {    
            cout<<id<<"  "<<name<<"  "<<salary<<endl;    
        }    
};  
int main(void) {  
    Employee e1 =Employee(101, "Sonoo", 890000);   
    Employee e2=Employee(102, "Nakul", 59000); 
    e1.display();    
    e2.display();    
    return 0;  
}  
*/

//code 6 static field 

#include <iostream>  
using namespace std;  
class Account {  
   public:  
       int accno; 
       string name; 
       static float rateOfInterest;   
       Account(int accno, string name)   
        {    
            this->accno = accno;    
            this->name = name;    
        }     
       void display()    
        {    
            cout<<accno<<" "<<name<<" "<< rateOfInterest<<endl;   
        }    
};  
float Account::rateOfInterest = 6.5;  
int main(void) {  
    Account a1 =Account(201, "Sanjay"); 
    Account a2=Account(202, "Nakul");
    a1.display();    
    a2.display();    
    return 0;  
}  

//code 7 static field,Counting Objects
/*
#include <iostream>  
using namespace std;  
class Account {  
   public:  
       int accno;      
       string name;   
       static int count;     
       Account(int accno, string name)   
        {   
            this->accno = accno;    
            this->name = name;    
            count++;  
        }    
       void display()    
        {    
            cout<<accno<<" "<<name<<endl;   
        }    
};  
int Account::count=0;  
int main(void) {  
    Account a1 =Account(201, "Sanjay"); 
    Account a2=Account(202, "Nakul");   
     Account a3=Account(203, "Ranjana");  
    a1.display();    
    a2.display();    
    a3.display();    
    cout<<"Total Objects are: "<<Account::count;  
    return 0;  
}  
*/

