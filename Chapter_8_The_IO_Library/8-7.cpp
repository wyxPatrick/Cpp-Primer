#include <string>
#include <iostream>
#include <fstream>

class Sales_data;
std::istream &read(std::istream &, Sales_data &);

class Sales_data {
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);

public:
    Sales_data() : Sales_data("", 0, 0.0) {}
    explicit Sales_data(const std::string& no) : Sales_data(no, 0, 0.0) {}
    Sales_data(const std::string& no, unsigned us, double price) : bookNo(no), units_sold(us), revenue(price * us) {}
    explicit Sales_data(std::istream& is) : Sales_data() {read(is, *this);}

    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);

private:
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream &read(std::istream &is, Sales_data &item) {
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
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

inline
double Sales_data::avg_price() const {
    return units_sold ? revenue / units_sold : 0;
}

int process_transaction(std::istream& in, std::ostream& out) {
    Sales_data total;
    if (read(in, total)) {
        Sales_data trans;
        while (read(in, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }
            else {
                print(out, total) << std::endl;
                total = trans;
            }
        }
        print(out, total) << std::endl;
    }
    else {
        std::cerr << "No data!" << std::endl;
        return -1;
    }
    return 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: 8.7 <input filename> [<output filename>]" << std::endl;
        return -3;
    }
    std::ifstream in(argv[1]);
    if (!in) {
        std::cerr << "Fail to open file: " << argv[1] << std::endl;
        return -2;
    }
    if (argc >= 3) {
        std::ofstream out(argv[2]);
        if (!out) {
            std::cerr << "Fail to open file: " << argv[1] << std::endl;
            return -2;
        }
        process_transaction(in, out);
    }
    else {
        process_transaction(in, std::cout);
    }

    return 0;
}