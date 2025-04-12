#include <iostream>
#include <cstring>

using namespace std;

class String {

    public:
        // Конструктор:
        String( const char * = nullptr );
        // Деструктор:
        ~String();
        // Копи-конструктор:
        String( const String & );
        // Оператор за присвояване:
        String & operator=( const String & );
        // Метод за конкатениране на низ към текущия:
        String & Concatenate( const String & );
        // Връща стойността на низа като масив от символи:
        const char* GetValue() const;
        // Връща дължината на низа:
        size_t GetLength() const;

    private:

        void deleteString();
        void copyStringArray( const char * );

        // Поле, представляващо указател, сочещ динамичния масив от символи,
        // в който се съдържа низа:
        char *str = nullptr;
};

/// Публични член-функции:

String::String( const char *newStr ) {

    copyStringArray( newStr );
}

String::~String() {

    deleteString();
}

String::String( const String &other ) {

    copyStringArray( other.str );
}

String & String::operator=( const String &other ) {

    if ( this != &other )
    {
        deleteString();
        copyStringArray( other.str );
    }
    return *this;
}

String & String::Concatenate( const String &stringToAdd ) {

    if ( stringToAdd.str != nullptr )
    {
        char *newStr = new char[ this->GetLength() + stringToAdd.GetLength() + 1 ];
        strcpy( newStr, str );
        strcat( newStr, stringToAdd.str );
        deleteString();
        str = newStr;
    }
    return *this;
}

const char * String::GetValue() const {

    return str;
}

size_t String::GetLength() const {

    return strlen( str );
}

/// END публични член-функции

/// Частни член-функции:

void String::deleteString() {

    delete[] str;
    str = nullptr;
}


void String::copyStringArray( const char *newStr ) {

    if ( newStr == nullptr )
    {
        str = new char( '\0' );
    }
    else
    {
        str = new char[ strlen( newStr ) + 1 ];
        strcpy( str, newStr );
    }
}

/// END частни член-функции

void PrintString( const String &argument ) {

    cout
        << "Value: " << argument.GetValue() << endl
        << "Length: " << argument.GetLength() << endl << endl;
}

int main() {

    const char * const LINE_BREAK = "----------------\n\n";

    String string1( "Hello" );
    PrintString( string1 );
    cout << LINE_BREAK;

    String string2 = string1;
    PrintString( string1 );
    PrintString( string2 );
    cout << LINE_BREAK;

    String string3;
    PrintString( string3 );
    string3 = string1;
    PrintString( string3 );
    cout << LINE_BREAK;

    String stringToAdd( " everybody!" );
    string3.Concatenate( stringToAdd );
    PrintString( string3 );
    cout << LINE_BREAK;

    stringToAdd = " How are ";
    cout << string3
        .Concatenate( stringToAdd )
        .Concatenate( String() )
        .Concatenate( String( "you doing?\n" ) )
        .GetValue();

    return 0;
}
