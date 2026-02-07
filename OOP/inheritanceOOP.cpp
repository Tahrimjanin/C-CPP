




/*3) Single Level Inheritance Example: Inheriting Methods
#include <iostream>
using namespace std;
class Animal {
     public:
     void eat() {
     cout<<"Eating..."<<endl;
     }
};
class Dog: public Animal {
     public:
     void bark(){
     cout<<"Barking...";
     }
 };
int main(void) {
   Dog d1;
     d1.eat();
     d1.bark();
     return 0;
} */

/*4) Single Level Inheritance Example: Inheriting Methods
#include <iostream>
using namespace std;

class A {
    int a = 4;
    int b = 5;
public:
    int mul() {
        int c = a * b;
        return c;
    }
};

class B : private A { 
public:
    void display() {
        int result = mul(); 
        cout << "Multiplication of a and b is: " << result << endl; 
    }
};

int main() {
     B b; 
     b.display(); 
     return 0;
}
*/

/*5) C++ program to explain multiple inheritance
#include <iostream>
using namespace std;
class Vehicle {
public:
    Vehicle() {
        cout << "This is a Vehicle\n";
    }
};
class FourWheeler {
public:
    FourWheeler() {
        cout << "This is a Four Wheeler Vehicle\n";
    }
};
class Car : public Vehicle, public FourWheeler {
};
int main() {
    Car obj;
    return 0;
}
*/

/*6) C++ program to explain multiple inheritance
#include <iostream>
using namespace std;

class A {
protected:
    int a;
public:
    void get_a(int n) {
        a = n;
    }
};

class B {
protected:
    int b;
public:
    void get_b(int n) {
        b = n;
    }
};

class C : public A, public B {
public:
    void display() {
        cout << "The value of a is: " << a << endl;
        cout << "The value of b is: " << b << endl;
        cout << "Addition of a and b is: " << a + b << endl;
    }
};

int main() {
    C c;
    c.get_a(10);
    c.get_b(20);
    c.display();
    return 0;
}
 */

/*7) Multilevel Inheritance
#include <iostream>
using namespace std;
class Animal {
public:
void eat() {
cout<<"Eating..."<<endl;
}
};
class Dog: public Animal
{
public:
void bark(){
cout<<"Barking..."<<endl;
}
};
class BabyDog: public Dog
{
public:
void weep() {
cout<<"Weeping...";
}
};
int main(void) {
BabyDog d1;
d1.eat();
d1.bark();
d1.weep();
return 0;
} */

/* 8) C++ program to implement Multilevel Inheritance
#include <iostream>
using namespace std;
class Vehicle {
public:
    Vehicle() { 
        cout << "This is a Vehicle\n"; 
    }
};
class fourWheeler : public Vehicle { 
public:
    fourWheeler() {
        cout << "Objects with 4 wheels are vehicles\n";
    }
};
class Car : public fourWheeler { 
public:
    Car() { 
        cout << "Car has 4 Wheels\n"; 
    }
};
int main() {
    Car obj;
    return 0;
} */


#include <iostream>
using namespace std;

// Base class
class Vehicle {
public:
    Vehicle() {
        cout << "This is a Vehicle\n";
    }
};

class Car : public Vehicle {
public:
    Car() {
        cout << "This is a Car\n";
    }
};

class Bus : public Vehicle {
public:
    Bus() {
        cout << "This is a Bus\n";
    }
};

int main() {
    Car obj1;
    Bus obj2;
    return 0;
}









/*10) Hierarchical Inheritance
#include <iostream>
using namespace std;

class Shape {
public:
    int a, b;
    
    void get_data(int n, int m) {
        a = n;
        b = m;
    }
};

class Rectangle : public Shape { // Inheriting Shape class
public:
    int rect_area() {
        return a * b;
    }
};

class Triangle : public Shape { // Inheriting Shape class
public:
    float triangle_area() {
        return 0.5 * a * b;
    }
};

int main() {
    Rectangle r;
    Triangle t;
    int length, breadth, base, height;

    cout << "Enter the length and breadth of a rectangle: " << endl;
    cin >> length >> breadth;
    r.get_data(length, breadth);
    int m = r.rect_area();
    cout << "Area of the rectangle is: " << m << endl;

    cout << "Enter the base and height of the triangle: " << endl;
    cin >> base >> height;
    t.get_data(base, height);
    float n = t.triangle_area();
    cout << "Area of the triangle is: " << n << endl;

    return 0;
}*/

/*11) hybrid inheritance 
#include <iostream>
using namespace std;
class Vehicle {
public:
    Vehicle() { 
        cout << "This is a Vehicle\n"; 
    }
};
class Fare {
public:
    Fare() { 
        cout << "Fare of Vehicle\n"; 
    }
};
class Car : public Vehicle {
public:
    Car() {
        cout << "This is a Car\n";
    }
};
class Bus : public Vehicle, public Fare {
public:
    Bus() {
        cout << "This is a Bus\n";
    }
};
int main() {
    Bus obj2;
    return 0;
} */
/*11) hybrid inheritance 
#include <iostream>
using namespace std;

class A {
protected:
    int a;
public:
    void get_a() {
        cout << "Enter the value of 'a': ";
        cin >> a;
    }
};

class B : public A {
protected:
    int b;
public:
    void get_b() {
        cout << "Enter the value of 'b': ";
        cin >> b;
    }
};

class C {
protected:
    int c;
public:
    void get_c() {
        cout << "Enter the value of 'c': ";
        cin >> c;
    }
};

class D : public B, public C {
public:
    void mul() {
        get_a();
        get_b();
        get_c();
        cout << "Multiplication of a, b, and c is: " << a * b * c << endl;
    }
};

int main() {
    D d;
    d.mul();
    return 0;
}
*/
/*12) hybrid inheritance
#include <iostream>
using namespace std;
class ClassA {
public:
    int a;
};
class ClassB : public ClassA {
public:
    int b;
};
class ClassC : public ClassA {
public:
    int c;
};
class ClassD : public ClassB, public ClassC {
public:
    int d;
};
int main() {
    ClassD obj;
    obj.ClassB::a = 10;   
    obj.ClassC::a = 100; 

    obj.b = 20;
    obj.c = 30;
    obj.d = 40;

    cout << "a from ClassB: " << obj.ClassB::a;
    cout << "\na from ClassC: " << obj.ClassC::a;
    cout << "\nb: " << obj.b;
    cout << "\nc: " << obj.c;
    cout << "\nd: " << obj.d << '\n';

    return 0;
}


*/
/*13
#include <iostream>
using namespace std;

class ClassA {
public:
    int a;
};
class ClassB : virtual public ClassA {
public:
    int b;
};
class ClassC : virtual public ClassA {
public:
    int c;
};
class ClassD : public ClassB, public ClassC {
public:
    int d;
};
int main() {
    ClassD obj;
    obj.a = 10; 
    obj.b = 20;
    obj.c = 30;
    obj.d = 40;
    cout << "a: " << obj.a;
    cout << "\nb: " << obj.b;
    cout << "\nc: " << obj.c;
    cout << "\nd: " << obj.d << '\n';
    return 0;
}
*/