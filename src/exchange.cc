#include "exchange.h"
#include <cmath>
#include <iostream>
#include <iomanip>

Exchange::Exchange(std::string n)
{
    name = n;
}

void Exchange::add_stock(std::string sym, int ld, int par, Stock::StockType st, double fd)
{
    Stock t(sym, ld, par, st, fd);
    stocks.push_back(t);
}

double Exchange::calculate_geometric_mean()
{
    int n = 0;
    double p = 0;
    for (Stock &s : this->get_stocks())
    {
        p += s.get_price();
        n++;
    }
    double exp = 1.0/n;
    return std::pow(p, exp);
}

void Exchange::print()
{
    std::cout << std::setw(8) << std::left << "Symbol" << std::setw(12) << std::left << "Type" << std::setw(15) << std::left << "Last Dividend" << std::setw(16) << std::left << "Fixed Dividend" << std::setw(11) << std::left << "Par Value" << std::setw(12) << std::left << "Price" << std::endl;

    for (Stock &stock : this->get_stocks())
    {
        stock.print();
    }
    std::cout << "All Share Index: " << this->calculate_geometric_mean() << std::endl;
}
std::vector<Stock>& Exchange::get_stocks()
{
    return stocks;
}

void Exchange::find_and_print(std::string s)
{
    for (Stock &stock : this->get_stocks())
    {
        if (stock.get_symbol().compare(s) == 0)
        {
            stock.print_details();
            return;
        }
    }
    std::cout<<"Stock not found!"<<std::endl;
}
