#pragma once
#ifndef _STOCKS_H
#define _STOCKS_H
#include "trade.h"
#include <vector>
#include <string>
class Stock
{
    public:
        enum StockType
        {
            Common,
            Preferred
        };
        Stock(std::string, int, int, StockType, double);
        void print();
        void do_trade(int, int, Trade::TradeActions);
        void calculate_stock_price();
        double calculate_divedend_yield();
        double calculate_p_e_ratio();
        double get_price();
        std::string get_symbol();
        std::vector<Trade>& get_trades();
        void print_details();
    private:
        std::string symbol;
        double price;
        StockType stock_type;
        int last_dividend;
        double fixed_dividend;
        int par_value;
        std::vector<Trade> trades;
};

#endif
