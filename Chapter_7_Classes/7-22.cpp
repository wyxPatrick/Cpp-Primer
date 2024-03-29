#include <iostream>
#include <string>

class Person {
    friend std::istream& read(std::istream&, Person&);

public:
    Person() = default;
    Person(const std::string& n) : name(n) {}
    Person(const std::string& n, const std::string& a) : name(n), address(a) {}
    Person(std::istream&);

    std::string getName() const { return name; }
    std::string getAddress() const { return address; }

private:
    std::string name;
    std::string address;
};

std::istream& read(std::istream& is, Person& rhs) {
    is >> rhs.name >> rhs.address;
    return is;
}

std::ostream& print(std::ostream& os, const Person& rhs) {
    os << rhs.getName() << " " << rhs.getAddress();
    return os;
}

Person::Person(std::istream& is) {
    read(is, *this);
}

int main() {
    Person p;
    read(std::cin, p);
    print(std::cout, p);

    return 0;
}