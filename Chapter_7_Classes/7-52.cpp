#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};

int main() {
    Sales_data item = {"978-0590353403", 25, 15.99};

    return 0;
}