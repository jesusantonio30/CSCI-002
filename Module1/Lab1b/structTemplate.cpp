#include <iostream>
#include <string>

template <class T>
struct Person{
   std::string name;
   std::string gender;
   T age;

   Person(std::string argName, std::string argGender, T argAge);

   void printDetails(void); 
   bool isMinor(void);  //returns true if Person is a minor.
};

int main() {

    Person<float> person1("Jesus", "Male", 17), 
                  person2("Maria", "Female", 21),
                  person3("Fatima", "Female", 20.51),
                  person4("Gustavo", "Male", 23.78);
    
    std::cout << '\n';
    
    person1.printDetails();
    std::cout << "Minor: " << (person1.isMinor() ? "Yes" : "No") << std::endl;
    
    std::cout << '\n';

    person2.printDetails();
    std::cout << "Minor: " << (person2.isMinor() ? "Yes" : "No") << std::endl;

    std::cout << '\n';

    person3.printDetails();
    std::cout << "Minor: " << (person3.isMinor() ? "Yes" : "No") << std::endl;
    
    std::cout << '\n';

    person4.printDetails();
    std::cout << "Minor: " << (person4.isMinor() ? "Yes" : "No") << std::endl;

    return 0;
}

template<class T>
Person<T>::Person(std::string argName, std::string argGender, T argAge) {
    name = argName;
    gender = argGender;
    age = argAge;
}

template<class T>
void Person<T>::printDetails(void) {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "Age: " << age << std::endl;
}

template <class T>
bool Person<T>::isMinor(void) {
    return age < 18 ? true : false;
}
