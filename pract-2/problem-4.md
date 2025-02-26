**Задание: Създаване и използване на статична библиотека в CMake проект**

### Описание:
Целта на задачата е да се покаже как да се създаде статична библиотека в C++ и как да се използва в CMake проект. Ще създадете библиотека, която съдържа няколко математически функции, и ще я използвате в основен проект.

### Задача:
1. **Създайте статична библиотека:**
   - Създайте папка `mathlib`, която ще съдържа библиотеката.
   - В папката `mathlib` създайте следните файлове:
     - `mathlib.h` – декларация на функциите.
     - `mathlib.cpp` – имплементация на функциите.
     - `CMakeLists.txt` – CMake файл за компилиране на библиотеката.

2. **Функции в библиотеката:**
   - **Функция за сума**: `int add(int a, int b)` – Връща сумата на `a` и `b`.
   - **Функция за разлика**: `int subtract(int a, int b)` – Връща разликата между `a` и `b`.
   - **Функция за произведение**: `int multiply(int a, int b)` – Връща произведението на `a` и `b`.
   - **Функция за частно**: `double divide(int a, int b)` – Връща частното на `a` и `b`. Ако `b` е 0, връща 0.

3. **Създайте основен проект:**
   - Създайте папка `main_project`, която ще съдържа основния проект.
   - В папката `main_project` създайте следните файлове:
     - `main.cpp` – основна функция за демонстрация на функционалността.
     - `CMakeLists.txt` – CMake файл за компилиране на основния проект.

4. **Интеграция на библиотеката:**
   - В `CMakeLists.txt` на основния проект добавете логика за намиране и линкване на статичната библиотека `mathlib`.

### Подсказки:
- Използвайте `#ifndef`, `#define` и `#endif` в заглавния файл за предпазване от многократно включване.
- В `CMakeLists.txt` на библиотеката използвайте `add_library(mathlib STATIC mathlib.cpp)`.
- В `CMakeLists.txt` на основния проект използвайте `find_library` и `target_link_libraries`.

### Примерна структура на проекта:
```
project/
│── mathlib/
│   │── mathlib.h
│   │── mathlib.cpp
│   │── CMakeLists.txt
│── main_project/
│   │── main.cpp
│   │── CMakeLists.txt
```

CmakeLists.txt in mathlib:
```
cmake_minimum_required(VERSION 3.10)
project(mathlib)

add_library(mathlib STATIC mathlib.cpp)
```

CmakeLists.txt in main_project
```
cmake_minimum_required(VERSION 3.10)
project(main_project)

add_executable(main_project main.cpp)

find_library(MATHLIB mathlib PATHS ../mathlib)
target_link_libraries(main_project ${MATHLIB})
```