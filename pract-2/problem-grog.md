# Част 1: Инсталация на glog

## Вариант 1: Директна Инсталация
## MacOS
* Използване на homebrew

1. `brew install glog`
## Windows
* Използване на vcpkg
1. `.\vcpkg.exe install glog`
## Ubuntu
* Използване на apt-get

1. `sudo apt-get update`
2. `sudo apt-get install libgoogle-glog-dev`

## Вариант 2: Ръчна Инсталация от Източник

1. `git clone https://github.com/google/glog.git`
2. `cd glog`
3. Отворете glog/CMakeLists.txt с текстов редактор
4. Добавате следният код след `project`
- ```
  set(CMAKE_CXX_STANDARD 14)           # Request C++14
  set(CMAKE_CXX_STANDARD_REQUIRED ON)  # Enforce C++14, don't fallback
  set(CMAKE_CXX_EXTENSIONS OFF)        # Optional: Disable compiler-specific extensions
  ```
5. В папката glog изпълнете следните команди:
6. `cmake -S . -B build -G` // Генерира build файловете
7. `cmake --build build` // Компилира проекта
8. `cmake --build build --target test`// Изпълнява тестовете
9. `cmake --build build --target install` // Инсталира библиотеката

# Част 2: Използване на Библиотеката в Ваш Проект

1. Създадете папка myProject
2. Създадете файл CMakeLists.txt със следното съдържание
- ```
  make_minimum_required (VERSION 3.16)
  project (myproj VERSION 1.0)

  find_package (glog 0.7.1 REQUIRED)

  add_executable (myapp main.cpp)
  target_link_libraries (myapp glog::glog)
  ```
3. Създадете main.cpp със следното съдържание:
- ```
  #include <iostream>
  #include <glog/logging.h>

  int main(int argc, char* argv[]) {
      google::InitGoogleLogging(argv[0]); 
      FLAGS_logtostdout = 1; // Настройва glog да изписва логовете директно в стандартния изход (stdout)
      LOG(INFO) << "Found " << 1 << " cookies"; // Изписва информационно съобщение в логовете
  }
  ```
4. В терминалата изпълнете
   1. `cmake -S . -B build -G` // Генерира build файловете
   2. `cmake --build build` // Компилира проекта
5. При успешно изпълнение на командите е създаден изпълним файл в `build` директорията
