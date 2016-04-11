#include "stock.h"
#include <strings.h>
#include <iostream>
#include <iomanip>

Stock::Stock(std::string sym, int ld, int par, StockType st, double fd)
{
    symbol = sym;
    last_dividend = ld;
    stock_type = st;
    fixed_dividend = fd;
    par_value = par;
    price = 0; // no trades have occured yet trades will be random
}
void Stock::print()
{
    std::string t;
    switch(stock_type)
    {
        case Common:
            t = "Common";
        case Preferred:
            t = "Preferred";
    }
    // make sure we have the latest stock prices
    this->calculate_stock_price();
    std::cout << std::setw(8) << std::left << symbol << std::setw(12) << std::left << t << std::setw(15) << std::left << last_dividend << std::setw(16) << std::left << fixed_dividend << std::setw(11) << std::left << par_value << std::setw(12) << std::left << price << std::endl;
}
double Stock::get_price()
{
    return price;
}
void Stock::do_trade(int qty, int price, Trade::TradeActions ta)
{
     Trade trade(qty, price, ta);
     trades.push_back(trade);
}

void Stock::calculate_stock_price()
{
    double total_price = 0;
    double total_qty = 0;
    for(Trade t : trades)
    {
        if (t.get_time() > t.get_time()-900)
        {
            total_price += t.get_price() * t.get_quantity();
            total_qty += t.get_quantity();
        }
    }

    price = total_price / total_qty;
}

double Stock::calculate_divedend_yield()
{
    switch(stock_type)
    {
        case Common:
            return last_dividend / price;
        case Preferred:
            return fixed_dividend * par_value / price;
    }
}

double Stock::calculate_p_e_ratio()
{
    return price / this->calculate_divedend_yield();
}
std::string Stock::get_symbol()
{
    return symbol;
}
std::vector<Trade>& Stock::get_trades()
{
    return trades;
}
void Stock::print_details() {
    std::cout<<"Symbol: "<<symbol<<std::endl;
    std::cout<<"Dividend Yeild: "<<this->calculate_divedend_yield()<<std::endl;
    std::cout<<"P/E Ratio: "<<this->calculate_p_e_ratio()<<std::endl;
    std::cout<<"TRADES:"<<std::endl;
    std::cout << std::setw(22) << std::left << "Time" << std::setw(10) << std::left << "Quantity" << std::setw(15) << std::left << "Price" << std::setw(10) << std::left << "Buy/Sell"<< std::endl;
    for (Trade &t : this->get_trades())
    {
      t.print();
    }
}
