#pragma once
#ifndef _EXCHANGE_H
#define _EXCHANGE_H
#include "stock.h"
#include <vector>
#include <string>

class Exchange
{
    public:
        Exchange(std::string);
        void add_stock(std::string, int, int, Stock::StockType, double);
        void print();
        void find_and_print(std::string);
        std::vector<Stock>& get_stocks();
    private:
        std::string name;
        std::vector<Stock> stocks;
        double calculate_geometric_mean();
};

#endif
