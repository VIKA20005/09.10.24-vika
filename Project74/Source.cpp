#include <iostream>

class MyString
{
private:
    char* data;
    size_t size;

public:

    MyString() : data(nullptr), size(0) {}


    MyString(const char* str)
    {
        if (str) {
            size = 0;
            while (str[size] != '\0')
            {
                size++;
            }
            data = new char[size + 1];
            for (size_t i = 0; i < size; ++i)
            {
                data[i] = str[i];
            }
            data[size] = '\0';
        }
        else
        {
            data = nullptr;
            size = 0;
        }
    }


    ~MyString()
    {
        delete[] data;
    }


    MyString(const MyString& other)
    {
        size = other.size;
        data = new char[size + 1];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
        data[size] = '\0';
    }


    MyString& operator=(const MyString& other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            data = new char[size + 1];
            for (size_t i = 0; i < size; ++i)
            {
                data[i] = other.data[i];
            }
            data[size] = '\0';
        }
        return *this;
    }


    const char* getData() const
    {
        return data ? data : "";
    }


    void input()
    {
        char buffer[1024];
        std::cin >> buffer;
        *this = MyString(buffer);
    }


    void output() const
    {
        std::cout << getData();
    }
};

int main()
{
    MyString str1;
    std::cout << "Введите строку: ";
    str1.input();

    std::cout << "Вы ввели: ";
    str1.output();
    std::cout << std::endl;

    MyString str2("Привет, мир!");
    std::cout << "Строка 2: ";
    str2.output();
    std::cout << std::endl;

    str1 = str2;
    std::cout << "После присваивания: ";
    str1.output();
    std::cout << std::endl;

    return 0;
}