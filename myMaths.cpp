#include "myMaths.h"

bool isPrime(const uint number) {
  // В цикле перебираем числа от 2 до Sqrt(number) + 1.
  uint iEnd{ static_cast<uint>(qSqrt(number) + 1) };
  for (uint i{ 2 }; i < iEnd; ++i)
    if (number % i == 0) // Если number делится без остатка на i - возвращаем false (число не простое).
      return false;

  // Если программа дошла до данного оператора, то возвращаем true (число простое) - проверка пройдена.
  return true;
}

bool isPerfect(const uint number) {
  // В цикле для полученного функцией аргумента
  //  будем находить его сомножители, путем деления его на все
  //  целые числа в интервале от 1 до (number / 2).
  uint sum{};
  for (uint i{ 1 }; i <= number / 2; ++i)
    if (number % i == 0)
      sum += i;

  // Вернёт true (совершенное число), если число и сумма его сомножителей равны.
  return sum == number;
}


QString perfects(const uint number) {
  QString perfects{};
  // Цикл от единицы до заданного числа (конечное число диапазона поиска).
  for (uint i{ 1 }; i <= number; ++i) {
    if (isPerfect(i)) {
      perfects += QString::number(i) + ' ';
    }
  }

  return perfects;
}
