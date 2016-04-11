#include "trade_bot.h"
#include <ctime>
#include <stdlib.h>
TradeBot::TradeBot()
{
    srand((unsigned int) time (NULL));
}

void TradeBot::make_trades(Stock *stk)
{
    // generate random ammount of trades between betweeen 1 and 100 trades
    for (int j = 0; j < rand()%100; j++) {
        //do trades with a random price and qty up to 1000 and either Buy or Sell
        switch(rand()%2) {
            case 1:
                stk->do_trade(rand()%1000, rand()%1000, Trade::Buy);
                break;
            default:
                stk->do_trade(rand()%1000, rand()%1000, Trade::Sell);
        }
    }
}
