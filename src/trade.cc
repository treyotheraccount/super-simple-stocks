#include "trade.h"
#include <iostream>
#include <iomanip>
#include <string>

Trade::Trade(int qty, int p, TradeActions ta)
{
    time_stamp = time(0); // get current time
    quantity = qty;
    price = p;
    trade_actions = ta;
}

void Trade::print()
{
  std::string ta;
  switch (trade_actions)
  {
    case Buy:
      ta = "Buy";
      break;
    case Sell:
      ta = "Sell";
      break;
  }
  struct tm * timeinfo;
  char buffer[80];
  timeinfo = localtime(&time_stamp);
  strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
  std::string fmt_time(buffer);
  std::cout << std::setw(22) << std::left << fmt_time << std::setw(10) << std::left << quantity << std::setw(15) << std::left << price << std::setw(10) << std::left << ta << std::endl;

}

int Trade::get_price() {
    return price;
}

int Trade::get_quantity() {
    return quantity;
}

time_t Trade::get_time()
{
    return time_stamp;
}
