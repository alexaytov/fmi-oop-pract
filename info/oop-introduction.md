# Въведение в обектно-ориентираното програмиране с C++

Обектно-ориентираното програмиране (ООП) представлява съвременна парадигма в разработката на софтуер, която се базира на концепцията за обекти – структури, съдържащи данни и функционалност. Тази лекция ще ви запознае с основните принципи на ООП в контекста на езика C++ и ще разгледа ключови концепции като класове, конструктори, деструктори и типове кастване.

## Основни принципи на обектно-ориентираното програмиране

Обектно-ориентираното програмиране се явява наследник на процедурното програмиране, при което програмата представлява съвкупност от процедури, които се извикват една друга. ООП предлага по-гъвкав и модулен подход за структуриране на кода[^1].

### 🔑 Основни принципи:

#### 1. Енкапсулация (Encapsulation)

Енкапсулацията позволява групиране на данни и методи в една логическа единица (клас) и контролиране на достъпа до тях. Всеки обект си има свои собствени променливи и методи, като вътрешното състояние е защитено от външна модификация[^6].

```cpp
// Example of encapsulation
class BankAccount {
private:
    double balance; // Private data, not accessible directly
public:
    void deposit(double amount) { balance += amount; } // Public interface
    double getBalance() { return balance; } // Controlled access to private data
};
```


#### 2. Наследяване (Inheritance)

Наследяването позволява създаването на нови класове (наследници) на базата на съществуващи класове (родители). Наследникът получава всички данни и методи на родителя си, като може да ги разшири или модифицира[^6].

```cpp
// Example of inheritance
class Animal {
public:
    void breathe() { /* breathing implementation */ }
};

class Dog : public Animal { // Dog inherits from Animal
public:
    void bark() { /* barking implementation */ }
    // Dog inherits the breathe() method from Animal
};
```


#### 3. Полиморфизъм (Polymorphism)

Полиморфизмът позволява различни обекти от една йерархия да реагират по различен начин на един и същи метод. Това се постига чрез виртуални функции и override[^6].

```cpp
// Example of polymorphism
class Shape {
public:
    virtual void draw() { /* default drawing implementation */ }
};

class Circle : public Shape {
public:
    void draw() override { /* circle-specific drawing */ }
};

class Rectangle : public Shape {
public:
    void draw() override { /* rectangle-specific drawing */ }
};
```


#### 4. Абстракция (Abstraction)

Абстракцията е процесът на скриване на ненужни подробности от потребителя. Тя позволява да се работи с опростени модели на сложни обекти и системи[^1].

```cpp
// Example of abstraction
class DatabaseConnection {
private:
    // Complex internal implementation details are hidden
    void authenticate() { /* ... */ }
    void establishConnection() { /* ... */ }
    
public:
    // Simple interface for users
    bool connect(string username, string password) {
        // Internally calls complex methods
        authenticate();
        return establishConnection();
    }
};
```


## Потребителски дефинирани типове в C++

В C++ има три основни механизма за създаване на потребителски дефинирани типове: struct, class и union. Всеки от тях има различна употреба и характеристики.

### 🧩 struct, class и union

#### struct (структура)

Структурата е съвкупност от полета (данни), които могат да бъдат различни типове. Тя е наследена от езика C, но в C++ е разширена с възможности за методи и контрол на достъпа[^7].

```cpp
// Example of a struct
struct Point {
    int x;    // Public by default
    int y;    // Public by default
    
    void reset() {
        x = 0;
        y = 0;
    }
};
```


#### class (клас)

Класът е структура, която по подразбиране има частен (private) достъп до членовете си. Той е основният механизъм за имплементация на обектно-ориентирано програмиране в C++[^2].

```cpp
// Example of a class
class Person {
private:    // Private by default
    string name;
    int age;
    
public:
    Person(string n, int a) : name(n), age(a) {}
    
    void introduce() {
        cout << "My name is " << name << " and I am " << age << " years old." << endl;
    }
};
```


#### union (обединение)

Обединението е специален тип, при който всички членове споделят едно и също място в паметта. То може да съдържа само една стойност в даден момент от време[^7].

```cpp
// Example of a union
union Variant {
    int intValue;
    float floatValue;
    char charValue;
    // Only one of these values can be active at a time
    // All share the same memory location
};
```


### ⚖️ Основни разлики между struct и class

Основната разлика между struct и class в C++ е в подразбиращия се контрол на достъпа:

- В struct всички членове са public по подразбиране
- В class всички членове са private по подразбиране[^2]

Освен това, има стилистична разлика - структурите обикновено се използват за прости групирания на данни (Plain Old Data - POD), докато класовете се използват когато е необходима по-сложна логика и контрол на достъпа[^2].

## Класове - основни понятия

### 🏗️ Конструктори

Конструкторът е специален член-функция на класа, която се извиква автоматично при създаване на обект. Той има същото име като класа и няма тип на връщане[^3][^8].

```cpp
class Rectangle {
private:
    int width, height;
    
public:
    // Default constructor
    Rectangle() {
        width = 0;
        height = 0;
    }
    
    // Parameterized constructor
    Rectangle(int w, int h) {
        width = w;
        height = h;
    }
    
    // Copy constructor
    Rectangle(const Rectangle &r) {
        width = r.width;
        height = r.height;
    }
};
```


#### Видове конструктори:

1. **Конструктор по подразбиране (Default Constructor)** - няма параметри или всички параметри имат стойности по подразбиране
2. **Параметризиран конструктор (Parameterized Constructor)** - приема аргументи
3. **Копиращ конструктор (Copy Constructor)** - създава обект, копирайки стойностите от друг обект от същия клас

### 💀 Деструктори

Деструкторът е специална член-функция, която се извиква автоматично, когато обектът се унищожава. Името му е същото като името на класа, но с префикс тилда (~). Деструкторът няма параметри и няма тип на връщане[^3][^8].

```cpp
class ResourceManager {
private:
    int* data;
    
public:
    ResourceManager() {
        data = new int[^100]; // Allocate memory
        cout << "Constructor called, resource allocated" << endl;
    }
    
    ~ResourceManager() {
        delete[] data; // Free memory
        cout << "Destructor called, resource deallocated" << endl;
    }
};
```


### 👁️ Видимост и контрол на достъпа

C++ предлага три нива на видимост:

1. **public** - членовете са достъпни от всякакъв код
2. **protected** - членовете са достъпни само от методи на самия клас и неговите наследници
3. **private** - членовете са достъпни само от методи на самия клас[^1]
```cpp
class Example {
private:
    int privateVar;    // Accessible only within the class
    
protected:
    int protectedVar;  // Accessible within class and derived classes
    
public:
    int publicVar;     // Accessible from anywhere
    
    void accessAllVars() {
        // All variables are accessible here
        privateVar = 1;
        protectedVar = 2;
        publicVar = 3;
    }
};
```


## Подробности за конструктори и деструктори

### 🔄 Кога се извикват конструкторите и деструкторите?

- **Конструктори** се извикват при:
    - Създаване на обект
    - Създаване на динамичен обект с new
    - Създаване на временен обект
- **Деструктори** се извикват при:
    - Излизане от обхвата, в който е дефиниран обектът
    - Изрично унищожаване на динамичен обект с delete
    - Край на програмата (за глобални обекти)

Деструкторите се извикват в обратен ред на създаването на обектите[^8].

### ⚙️ Дефолтни конструктори и деструктори

Компилаторът генерира дефолтни конструктори и деструктори в следните случаи:

- **Дефолтен конструктор** - създава се автоматично, ако в класа няма дефиниран нито един конструктор. Той инициализира примитивните типове с неопределени стойности, а обектите - чрез техните дефолтни конструктори.
- **Дефолтен деструктор** - създава се автоматично, ако в класа няма дефиниран деструктор. Той извиква деструкторите на член-обектите, но не освобождава динамично заделена памет.

```cpp
// Example with default constructor and destructor
class SimpleClass {
    int x;              // Will have undefined value
    std::string name;   // Will be initialized with default constructor of std::string
};  // Compiler will generate both default constructor and destructor
```


## Типове кастване в C++

C++ предлага няколко механизма за преобразуване на типове, всеки със своята специфична употреба.

### 🔄 const_cast и static_cast

#### const_cast

`const_cast` се използва за премахване (или добавяне) на квалификатора const от променлива[^4]. Този тип кастване трябва да се използва внимателно, тъй като може да доведе до недефинирано поведение.

```cpp
// Example of const_cast
void printValue(int* ptr) {
    cout << "Value: " << *ptr << endl;
}

void example() {
    const int value = 10;
    // const int* cannot be passed to int*
    // printValue(&value); // This would cause compilation error
    
    // Remove constness using const_cast
    printValue(const_cast<int*>(&value));
}
```


#### static_cast

`static_cast` се използва за преобразуване между свързани типове, като числови типове или указатели в йерархията на наследяване[^4]. Това е най-често използваното и безопасно кастване.

```cpp
// Example of static_cast
void example() {
    // Convert between numeric types
    double pi = 3.14159;
    int intPi = static_cast<int>(pi); // Convert double to int
    
    // Cast within class hierarchy
    Base* basePtr = new Derived();
    Derived* derivedPtr = static_cast<Derived*>(basePtr); // Safe if basePtr points to Derived
}
```


### ⚠️ Кога поведението на кастванията е недефинирано?

- **const_cast** - когато се използва за модифициране на константна стойност. Например:

```cpp
// Undefined behavior!
const int x = 10;
int* ptr = const_cast<int*>(&x);
*ptr = 20; // Modifying a const object - undefined behavior!
```

- **static_cast** - когато се кастира указател към базов клас към указател към производен клас, и указателят не сочи към обект от производния клас:

```cpp
// Undefined behavior!
Base* basePtr = new Base(); // Points to Base object only
Derived* derivedPtr = static_cast<Derived*>(basePtr); // Dangerous downcast
derivedPtr->derivedMethod(); // Undefined behavior!
```


## Често срещани грешки и добри практики

### 🚨 Често срещани грешки

1. **Неинициализирани данни**

Конструкторите трябва да инициализират всички член-данни, за да се избегнат неопределени стойности[^5].

```cpp
// BAD:
class A {
public:
    A() {} // Does not initialize 'm_i'
    int getI() const { return m_i; }
private:
    int m_i; // Uninitialized!
};
```

2. **Скриване на имена (Name-Hiding)**

Обявяване на променлива със същото име като променлива от външен обхват може да доведе до неочаквани грешки[^5].

```cpp
// BAD:
void foo() {
    int i = 15;
    int myArray[^20];
    
    for (int i = 0; i < 10; ++i) {
        myArray[i] = 0;
    }
    
    // Here, i is still 15, not 10!
    myArray[i-1] = 1; // Out of bounds!
}
```

3. **Неправилно управление на ресурси**

Неосвобождаване на ресурси в деструктора може да доведе до изтичане на памет.

```cpp
// BAD:
class ResourceHandler {
    int* data;
public:
    ResourceHandler() { data = new int[^100]; }
    // Missing destructor! Memory leak!
};
```

4. **Неправилно кастване**

Използването на C-style кастване вместо по-безопасните C++ кастове може да доведе до трудно откриваеми грешки[^4].

```cpp
// BAD:
Base* basePtr = new Base();
Derived* derivedPtr = (Derived*)basePtr; // C-style cast - dangerous!
```


### ✅ Добри практики

1. **Използвайте списъци за инициализация в конструкторите**

```cpp
// GOOD:
class Person {
    string name;
    int age;
public:
    // Initialize members in initialization list
    Person(string n, int a) : name(n), age(a) {}
};
```

2. **Прилагайте правилото на трите/петте**

Ако класът има собствен деструктор, копиращ конструктор или оператор за присвояване, вероятно трябва да дефинирате и останалите.

```cpp
// GOOD:
class ResourceOwner {
    int* data;
public:
    ResourceOwner() : data(new int[^10]) {}
    ~ResourceOwner() { delete[] data; }
    ResourceOwner(const ResourceOwner& other) : data(new int[^10]) {
        // Copy data from other
    }
    ResourceOwner& operator=(const ResourceOwner& other) {
        if (this != &other) {
            delete[] data;
            data = new int[^10];
            // Copy data from other
        }
        return *this;
    }
};
```

3. **Използвайте подходящия тип кастване**

Вместо C-style кастване, използвайте по-безопасните C++ кастове:

```cpp
// GOOD:
double d = 3.14;
int i = static_cast<int>(d);

const int x = 10;
// Only use const_cast when absolutely necessary
int* ptr = const_cast<int*>(&x); // Be careful!
```

4. **Следвайте принципа RAII (Resource Acquisition Is Initialization)**

Придобивайте ресурси в конструктора и ги освобождавайте в деструктора.

```cpp
// GOOD:
class FileHandler {
    FILE* file;
public:
    FileHandler(const char* filename) {
        file = fopen(filename, "r");
    }
    ~FileHandler() {
        if (file) fclose(file);
    }
};
```


## Заключение

Обектно-ориентираното програмиране предлага мощен инструментариум за създаване на гъвкав, модулен и преизползваем код. Разбирането на основните концепции като енкапсулация, наследяване и полиморфизъм, както и правилното използване на механизмите на C++ като конструктори, деструктори и кастване, е ключово за успешното програмиране с този език.

Това въведение обхваща само основите на ООП с C++. Преминавайки към по-сложни теми, ще се запознаете с шаблони, изключения, стандартна библиотека и много други функционалности, които превръщат C++ в един от най-мощните и гъвкави езици за програмиране.

<div style="text-align: center">⁂</div>

[^1]: https://softuni.bg/blog/fundamentals-of-object-oriented-programming

[^2]: https://www.reddit.com/r/cpp_questions/comments/gxrskj/what_is_the_difference_between_a_struct_and_a/

[^3]: https://www.codementor.io/@supernerdd7/constructor-and-destructor-in-c-1r8kkogm6j

[^4]: https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used

[^5]: https://www.perforce.com/blog/qac/7-common-errors-c-cpp-programming

[^6]: http://fmi.wikidot.com/sdp1

[^7]: https://www.ibm.com/docs/de/zos/2.4.0?topic=types-structures-unions

[^8]: https://uomustansiriyah.edu.iq/media/lectures/9/9_2020_03_25!11_41_14_PM.pdf

[^9]: https://docs.oracle.com/cd/E19205-01/819-5267/bkahi/index.html

[^10]: https://www.pro5.ai/blog/10-common-c-coding-mistakes-and-how-to-avoid-them

[^11]: https://introprogramming.info/intro-csharp-book/read-online/glava11-sazdavane-i-izpolzvane-na-obekti/

[^12]: https://stackoverflow.com/questions/4003087/whats-the-major-difference-between-union-and-struct-in-c

[^13]: https://jwlss.pw/course_notes/algoritmi/11_6.1 - Constructor Destructor and Abstract Classes - 1x.pdf

[^14]: https://omkaracharekar.hashnode.dev/a-guide-to-c-casting-staticcast-reinterpretcast-dynamiccast-and-constcast

[^15]: https://learn.microsoft.com/en-us/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-170

[^16]: https://codegym.cc/bg/groups/posts/bg.155.principi-na-oop

[^17]: https://learn.microsoft.com/en-us/cpp/cpp/classes-and-structs-cpp?view=msvc-170

[^18]: https://www.youtube.com/watch?v=sNiiJ16dLz0

[^19]: https://www.luisllamas.es/en/cpp-static-dynamic-const-cast/

[^20]: https://softwareengineering.stackexchange.com/questions/430984/what-are-the-best-practices-when-implementing-c-error-handling

