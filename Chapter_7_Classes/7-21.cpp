#include <string>
#include <iostream>

class Sales_data;
std::istream &read(std::istream &, Sales_data &);

class Sales_data {
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);

public:
    Sales_data() : bookNo(""), units_sold(0), revenue(0.0) { }
    Sales_data(const std::string &no) : bookNo(no) { }
    Sales_data(const std::string &no, unsigned us, double price):
               bookNo(no), units_sold(us), revenue(price * us) { }
    Sales_data(std::istream &is) {read(is, *this);}
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue;
        // << " " << item.avg_price();
    return os;
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

int main() {
    Sales_data total(std::cin);
    if (std::cin) {
        Sales_data trans(std::cin);
        while (std::cin) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }
            else {
                print(std::cout, total) << std::endl;
                total = trans;
            }
            read(std::cin, trans);
        }
        print(std::cout, total) << std::endl;
    }
    else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}