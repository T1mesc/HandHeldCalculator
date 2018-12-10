#ifndef CALC_H
#define CALC_H
#include <iostream>

struct Calc {
  Calc();
  Calc(const Calc &other);

  bool error;
  int display;
  char oper;
  int result;
  int memory;

  void digit(int digit); // add numbers 0-9 to the end of the display value
  void op(char oper); // set the operator field
  void equals(); // display the result

  void memPlus(); // behave like M+ on a hand-held calculator
  void memClear(); // behave like MC on a hand-held calculator
  void memRecall(); // behave like MR on a hand-held calculator

  bool isError() const;

  void allClear();
};

std::ostream &operator<<(std::ostream &out, const Calc &c);

#endif

