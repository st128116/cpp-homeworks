#include <iostream>
#include <string>

class String {
private:
    std::string data;

    // Вспомогательный класс
    class SubstringProxy {
    private:
        const String& str;
        size_t start;
    public:
        SubstringProxy(const String& s, size_t i)
            : str(s), start(i) {}

        String operator[](size_t end) const {
            return String(str.data.substr(start, end - start));
        }
    };

public:
    String() = default;
    String(const char* s) : data(s) {}
    String(const std::string& s) : data(s) {}

    // Первый оператор []
    SubstringProxy operator[](size_t i) const {
        return SubstringProxy(*this, i);
    }

    const std::string& get() const {
        return data;
    }
};