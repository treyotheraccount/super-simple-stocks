#include <iostream>
#include "exchange.h"
#include "stock.h"
#include "trade_bot.h"

int main()
{
    // setup
    Exchange exchange("GCBE");
    exchange.add_stock("TEA", 0, 100, Stock::StockType::Common, 0);
    exchange.add_stock("POP", 8, 100, Stock::StockType::Common, 0);
    exchange.add_stock("ALE", 23, 60, Stock::StockType::Common, 0);
    exchange.add_stock("GIN", 8, 100, Stock::StockType::Preferred, 0.02);
    exchange.add_stock("JOE", 13, 250, Stock::StockType::Common, 0);

    // do some trades
    TradeBot trader;
    for(Stock &s : exchange.get_stocks())
    {
        trader.make_trades(&s);
    }
    bool quit = false;
    while (!quit) {
        std::string input;
        std::system("clear");
        exchange.print();
        std::cout<<"Enter a stock symbol or type Quit to quit the program: ";
        std::getline(std::cin,input);
        if (input.compare("Quit") == 0 || input.compare("quit") == 0)
        {
            std::cout<<"Goodbye!";
            quit = true;
            continue;
        }
        exchange.find_and_print(input);
        std::cout<<"Press any key to continue..."<<std::endl;
        std::cin.ignore();
    }
    return 0;
}
