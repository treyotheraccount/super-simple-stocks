#pragma once
#ifndef _TRADE_BOT_H
#define _TRADE_BOT_H
#include "stock.h"
class TradeBot
{
    public:
        TradeBot();
        void make_trades(Stock*);
};
#endif
