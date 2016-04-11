#pragma once
#ifndef _TRADE_H
#define _TRADE_H
#include <ctime>
class Trade
{
    public:
        enum TradeActions
        {
            Buy,
            Sell
        };
        Trade(int, int, TradeActions);
        void print();
        int get_price();
        int get_quantity();
        time_t get_time();
    private:
        time_t time_stamp;
        int quantity;
        int price;
        TradeActions trade_actions;
};
#endif
