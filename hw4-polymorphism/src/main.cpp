#include <cstring>
#include <iostream>

class String {
private:
    char* data;
    size_t length;

public:
    // Конструктор
    String(const char* str = "") {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }

    // Конструктор копирования
    String(const String& other) {
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // Деструктор
    ~String() {
        delete[] data;
    }

    // Оператор присваивания
    String& operator=(const String& other) {
        if (this == &other) return *this;
        delete[] data;
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
        return *this;
    }

    // Вспомогательный класс для первого []
    class SubstringProxy {
    private:
        const String& str;
        size_t start;

    public:
        SubstringProxy(const String& s, size_t i)
            : str(s), start(i) {}

        String operator[](size_t end) const {
            size_t newLen = end - start;
            char* buffer = new char[newLen + 1];

            for (size_t i = 0; i < newLen; ++i) {
                buffer[i] = str.data[start + i];
            }
            buffer[newLen] = '\0';

            String result(buffer);
            delete[] buffer;
            return result;
        }
    };

    // Первый оператор []
    SubstringProxy operator[](size_t start) const {
        return SubstringProxy(*this, start);
    }

    // Для вывода
    friend std::ostream& operator<<(std::ostream& os, const String& s) {
        os << s.data;
        return os;
    }
};

int main() {
    String hello("hello");

    String hell = hello[0][4];
    String ell  = hello[1][4];
    String empty = hello[2][2];

    std::cout << hell << std::endl;   // hell
    std::cout << ell << std::endl;    // ell
    std::cout << empty << std::endl;  // пусто

    return 0;
}
