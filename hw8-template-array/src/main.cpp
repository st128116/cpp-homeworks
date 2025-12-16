#include <iostream>

constexpr int size = 5;

template <class T>
class Array {
private:
    T array[size];

public:
    Array() {
        for (int i = 0; i < size; ++i) {
            array[i] = T{};
        }
    }

    Array(T* b) {
        for (int i = 0; i < size; ++i) {
            array[i] = b[i];
        }
    }

    void show() const {
        for (int i = 0; i < size; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    T minimum(const Array<T>& other) const {
        T minVal = array[0];

        for (int i = 1; i < size; ++i) {
            if (array[i] < minVal) {
                minVal = array[i];
            }
        }

        for (int i = 0; i < size; ++i) {
            if (other.array[i] < minVal) {
                minVal = other.array[i];
            }
        }

        return minVal;
    }
};

int main() {
    int a[] = {5, 4, 3, 2, 1};
    int b[] = {10, 20, 30, 0, 40};

    Array<int> arr1(a);
    Array<int> arr2(b);

    arr1.show();
    arr2.show();

    std::cout << "Minimum: " << arr1.minimum(arr2) << std::endl;

    return 0;
}
