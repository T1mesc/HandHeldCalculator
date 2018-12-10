#include "calc.h"

#define MIN -2100000000

Calc::Calc() {
  error = false;
  display = 0;
  oper = 'a';
  result = 0;
  memory = MIN;
}

Calc::Calc(const Calc &other) {
  error = other.error;
  display = other.display;
  oper = other.oper;
  result = other.result;
  memory = other.memory;
}

void Calc::digit(int digit) {
  display = display * 10 + digit;
//  std::cout << display << std::endl;
}

bool Calc::isError() const {
  return error;
}

void Calc::op(char op) {
  if (oper == 'a') {
    result = display;
  }
  else
    switch(oper) {
      case '+': result += display; break;
      case '-': result -= display; break;
      case '*': result *= display; break;
      case '/': result /= display; break;
    }
  oper = op;
  display = 0;
//  std::cout << "result in op " << result << std::endl;
}

void Calc::equals() {
  if (!error) {
    if (oper == '/' && display == 0) {
      result = 0;
      error = true;
    }
    else {
      switch(oper) {
        case '+': result += display; break;
        case '-': result -= display; break;
        case '*': result *= display; break;
        case '/': result /= display; break;
        default: result = display;
      }
//      std::cout << result << std::endl;
    display = result;
    }
  }
  else {
    result = 0;
    display = 0;
  }
  oper = 'a';
//  std::cout << "result in = " << result << std::endl;
}

void Calc::memPlus() {
  if (!error)
    memory = display;
}

void Calc::memClear() {
  memory = MIN;
}

void Calc::memRecall() {
  if (memory != MIN)
    display = memory;
  else
    result = 0;
}

void Calc::allClear() {
  memory = MIN;
  result = 0;
  display = 0;
  oper = 'a';
  error = false;
}

std::ostream &operator<< (std::ostream &out, const Calc &c) {
  std::cout << c.display;
  if (c.memory != MIN)
    std::cout << ' ' << "M: " << c.memory;
  if (c.isError())
    std::cout << " E";
  return std::cout;
}
