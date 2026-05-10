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




