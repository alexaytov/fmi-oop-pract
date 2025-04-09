# Канонична форма на клас

## Задача 1: Клас за символен низ с канонично представяне (ОСНОВНА, ВАЖНА !!!):
Даден е следният клас, представляващ символен низ:
```cpp
class String {

    public:
        // Конструктор:
        String( const char * = nullptr );
        // Деструктор:
        ~String();
        // Копи-конструктор:
        String( const String& );
        // Оператор за присвояване:
        String& operator=( const String& );
        // Метод за конкатениране на низ към текущия:
        String& Concatenate( const String& );
        // Връща стойността на низа като масив от символи:
        const char* GetValue() const;
        // Връща дължината на низа:
        size_t GetLength() const;

    private:
        // Поле, представляващо указател, сочещ динамичния масив от символи,
        // в който се съдържа низа:
        char *str;
};
```

* Реализирайте класа, като поддържате информация за низа в динамичен масив от символи, към който сочи полето str. За правилно боравене с динамичната памет, използвайте каноничното представяне на класа (двата вида конструктора, десткруктора и операторът за присвояване);
* Напишете програма, която създава обект от тип `String`, след което инициализира втори обект от същия тип използвайки първия, както и трети обект, който първо се инициализира с конструктор по подразбиране, извежда се стойността му на екрана (чрез метод `.GetValue()`), а след това му се присвоява стойността на първия обект. Накрая изведете стойносттите и на трите обкета на екрана;
* Създайте динамичен масив от тип `String` с около 4 елемента, като зададете на всеки един от елементите на масива уникална стойност. Конкатенирайте всеки един от елементите на масива и запишете получения резултат в първия елемент след което го изведете на екрана. Не забравяйте накрая да освободите динамичната памет, след като тя вече няма да се използва.

!!! ВНИМАНИЕ - задачата е основна в курса по ООП и всеки, който желае да го завърши трябва да може да я реализира!

---

## Задача 2: Член-данни - обекти, ред на изпълнение:

Разгледайте следната програма. Опитайте да си обясните резултата от изпълнението и. Следете внимателно последователността на изпълнение на конструктурите, деструктурите, операторите за присвояване:

```cpp
#include <iostream>

using namespace std;

class Person {

    public:
        Person( string = "" );
        Person( const Person & );
        ~Person();
        Person & operator=( const Person & );

    private:
        string name;
};

class Couple {

    public:
        Couple( string = "", string = "" );
        Couple( const Couple & );
        ~Couple();
        Couple & operator=( const Couple & );

    private:
        Person person1, person2;
};

int main() {

    Couple couple1;
    Couple couple2 = couple1;
    couple2 = couple1;
    return 0;
}

Person::Person( string name ) {

    cout << "Person - Regular\n";
    this->name = name;
}

Person::Person( const Person &other ) {

    cout << "Person - Copy\n";
    this->name = other.name;
}

Person::~Person() {

    cout << "Person - Destructor\n";
}

Person & Person::operator=( const Person &other ) {

    cout << "Person - operator =\n";
    this->name = other.name;
    return *this;
}

Couple::Couple( string name1, string name2 ):
    person1( name1 )
{
    cout << "Couple - Regular\n";
    this->person2 = Person( name2 );
}

Couple::Couple( const Couple &other ) : person1( other.person1 ) {

    cout << "Couple - Copy\n";
    this->person2 = other.person2;
}

Couple::~Couple() {

    cout << "Couple - Destructor\n";
}

Couple & Couple::operator=( const Couple &other ) {

    cout << "Couple - operator =\n";
    this->person1 = other.person1;
    this->person2 = other.person2;
    return *this;
}
```
