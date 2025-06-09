#include <iostream>
#include <cstring>

// Абстрактен базов клас Animal
class Animal {
public:
    // Канонична четворка:
    Animal(const char *name, unsigned age);
    Animal(const Animal &other);
    // Виртуален деструктор - необходим е за правилно освобождаване на паметта
    // при полиморфно изтриване на обекти чрез указател към базовия клас
    virtual ~Animal();
    Animal& operator=(const Animal &other);

    void SetName(const char *name);
    void SetAge(unsigned age);
    const char* GetName() const;
    unsigned GetAge() const;

    // Чисто виртуална функция за извеждане на информацията за животното
    virtual void PrintInformation() const = 0;
    // Чисто виртуална функция за извеждане на звука, който издава животното
    virtual void PrintRoar() const = 0;

private:
    char *name = nullptr;
    unsigned age = 0;
};

// Клас Dog наследява Animal
class Dog : public Animal {
public:
    Dog(const char *name, unsigned age, const char *favoriteToyName);
    Dog(const Dog &other);
    ~Dog();
    Dog& operator=(const Dog &other);

    void SetFavoriteToyName(const char *toyName);
    const char* GetFavoriteToyName() const;

    // Реализация на виртуалните функции от базовия клас
    void PrintInformation() const override;
    void PrintRoar() const override;

private:
    char *favoriteToyName = nullptr;
};

// Клас Cat наследява Animal
class Cat : public Animal {
public:
    Cat(const char *name, unsigned age, bool isAggressive);
    Cat(const Cat &other);
    ~Cat();
    Cat& operator=(const Cat &other);

    void SetIsAggressive(bool aggressive);
    bool GetIsAggressive() const;

    // Реализация на виртуалните функции от базовия клас
    void PrintInformation() const override;
    void PrintRoar() const override;

private:
    bool isAggressive = false;
};

// Клас Eagle наследява Animal
class Eagle : public Animal {
public:
    Eagle(const char *name, unsigned age, double wingSpan);
    Eagle(const Eagle &other);
    ~Eagle();
    Eagle& operator=(const Eagle &other);

    void SetWingSpan(double span);
    double GetWingSpan() const;

    // Реализация на виртуалните функции от базовия клас
    void PrintInformation() const override;
    void PrintRoar() const override;

private:
    double wingSpan = 0.0;
};

// ========== РЕАЛИЗАЦИЯ НА КЛАСА ANIMAL ==========

// Конструктор с параметри
Animal::Animal(const char *name, unsigned age) : age(age) {
    // Алокираме памет за името и го копираме
    if (name != nullptr) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
}

// Копиращ конструктор
Animal::Animal(const Animal &other) : age(other.age) {
    // Дълбоко копиране на namnet
    if (other.name != nullptr) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }
}

// Деструктор
Animal::~Animal() {
    delete[] name;
}

// Оператор за присвояване
Animal& Animal::operator=(const Animal &other) {
    if (this != &other) {  // Проверка за самоприсвояване
        // Освобождаваме старата памет
        delete[] name;
        name = nullptr;

        // Копираме новите данни
        age = other.age;
        if (other.name != nullptr) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
    }
    return *this;
}

// Сетър за име
void Animal::SetName(const char *name) {
    delete[] this->name;  // Освобождаваме старата памет
    this->name = nullptr;

    if (name != nullptr) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
}

// Сетър за възраст
void Animal::SetAge(unsigned age) {
    this->age = age;
}

// Гетър за име
const char* Animal::GetName() const {
    return name;
}

// Гетър за възраст
unsigned Animal::GetAge() const {
    return age;
}

// ========== РЕАЛИЗАЦИЯ НА КЛАСА DOG ==========

// Конструктор с параметри
Dog::Dog(const char *name, unsigned age, const char *favoriteToyName)
    : Animal(name, age) {
    // Алокираме памет за любимата играчка
    if (favoriteToyName != nullptr) {
        this->favoriteToyName = new char[strlen(favoriteToyName) + 1];
        strcpy(this->favoriteToyName, favoriteToyName);
    }
}

// Копиращ конструктор
Dog::Dog(const Dog &other) : Animal(other) {
    // Дълбоко копиране на името на играчката
    if (other.favoriteToyName != nullptr) {
        this->favoriteToyName = new char[strlen(other.favoriteToyName) + 1];
        strcpy(this->favoriteToyName, other.favoriteToyName);
    }
}

// Деструктор
Dog::~Dog() {
    delete[] favoriteToyName;
}

// Оператор за присвояване
Dog& Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);  // Извикваме базовия оператор

        delete[] favoriteToyName;
        favoriteToyName = nullptr;

        if (other.favoriteToyName != nullptr) {
            favoriteToyName = new char[strlen(other.favoriteToyName) + 1];
            strcpy(favoriteToyName, other.favoriteToyName);
        }
    }
    return *this;
}

// Сетър за любима играчка
void Dog::SetFavoriteToyName(const char *toyName) {
    delete[] favoriteToyName;
    favoriteToyName = nullptr;

    if (toyName != nullptr) {
        favoriteToyName = new char[strlen(toyName) + 1];
        strcpy(favoriteToyName, toyName);
    }
}

// Гетър за любима играчка
const char* Dog::GetFavoriteToyName() const {
    return favoriteToyName;
}

// Реализация на виртуалната функция за извеждане на информация
void Dog::PrintInformation() const {
    std::cout << "Dog: " << GetName() << ", Age: " << GetAge()
              << " years old, Favorite toy: "
              << (favoriteToyName ? favoriteToyName : "none") << std::endl;
}

// Реализация на виртуалната функция за рев
void Dog::PrintRoar() const {
    std::cout << "Bark-bark!" << std::endl;
}

// ========== РЕАЛИЗАЦИЯ НА КЛАСА CAT ==========

// Конструктор с параметри
Cat::Cat(const char *name, unsigned age, bool isAggressive)
    : Animal(name, age), isAggressive(isAggressive) {}

// Копиращ конструктор
Cat::Cat(const Cat &other) : Animal(other), isAggressive(other.isAggressive) {}

// Деструктор (използва базовия деструктор)
Cat::~Cat() {}

// Оператор за присвояване
Cat& Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        isAggressive = other.isAggressive;
    }
    return *this;
}

// Сетър за агресивност
void Cat::SetIsAggressive(bool aggressive) {
    isAggressive = aggressive;
}

// Гетър за агресивност
bool Cat::GetIsAggressive() const {
    return isAggressive;
}

// Реализация на виртуалната функция за извеждане на информация
void Cat::PrintInformation() const {
    std::cout << "Cat: " << GetName() << ", Age: " << GetAge()
              << " years old, Agressive: " << (isAggressive ? "yes" : "no") << std::endl;
}

// Реализация на виртуалната функция за рев
void Cat::PrintRoar() const {
    std::cout << "Meow!" << std::endl;
}

// ========== РЕАЛИЗАЦИЯ НА КЛАСА EAGLE ==========

// Конструктор с параметри
Eagle::Eagle(const char *name, unsigned age, double wingSpan)
    : Animal(name, age), wingSpan(wingSpan) {}

// Копиращ конструктор
Eagle::Eagle(const Eagle &other) : Animal(other), wingSpan(other.wingSpan) {}

// Деструктор (използва базовия деструктор)
Eagle::~Eagle() {}

// Оператор за присвояване
Eagle& Eagle::operator=(const Eagle &other) {
    if (this != &other) {
        Animal::operator=(other);
        wingSpan = other.wingSpan;
    }
    return *this;
}

// Сетър за размах на крилете
void Eagle::SetWingSpan(double span) {
    wingSpan = span;
}

// Гетър за размах на крилете
double Eagle::GetWingSpan() const {
    return wingSpan;
}

// Реализация на виртуалната функция за извеждане на информация
void Eagle::PrintInformation() const {
    std::cout << "Eagle: " << GetName() << ", Age: " << GetAge()
              << " years old, Wing span: " << wingSpan << " m" << std::endl;
}

// Реализация на виртуалната функция за рев
void Eagle::PrintRoar() const {
    std::cout << "Screech!" << std::endl;
}

// ========== ДЕМОНСТРАЦИОННА ФУНКЦИЯ ==========

int main() {

    // Създаваме обекти от различните класове
    Dog myDog("Rex", 3, "ball");
    Cat myCat("Cleo", 2, true);
    Eagle myEagle("Falco", 5, 2.3);

    // Масив от указатели към базовия клас за демонстрация на полиморфизма
    Animal* animals[] = {&myDog, &myCat, &myEagle};

    // Извеждаме информацията за всички животни
    for (int i = 0; i < 3; i++) {
        animals[i]->PrintInformation();
        animals[i]->PrintRoar();
        std::cout << std::endl;
    }

    return 0;
}
