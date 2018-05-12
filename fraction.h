#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
int gcd(int a, int b);

class fraction
{
public:
  inline int get_zn()const { return zn; }
  inline int get_ch()const { return ch; }
  void reduce();
  fraction(): ch(0), zn(1){}
  fraction(int c, int z): ch(c), zn(z){ reduce(); }
  fraction operator+=(const fraction&);
  fraction operator-=(const fraction&);
  fraction operator/=(const fraction&);
  fraction operator*=(const fraction&);
  fraction operator+=(const int);
  fraction operator-=(const int);
  fraction operator/=(const int);
  fraction operator*=(const int);
  bool operator <(const fraction&) const;
  bool operator >(const fraction&) const;
  bool operator >=(const fraction&) const;
  bool operator <=(const fraction&) const;
  bool operator ==(const fraction&) const;
  bool operator <(const int) const;
  bool operator >(const int) const;
  bool operator >=(const int) const;
  bool operator <=(const int) const;
  bool operator ==(const int) const;
  fraction& operator++();
  fraction operator++(int);
  fraction& operator--();
  fraction operator--(int);
  fraction operator-() const;
  inline fraction operator+()
  {
    return *this;
  }

  fraction swapp();
  friend std::istream& operator>> (std::istream &os, fraction &temp);
private:
  int ch, zn;
};
fraction operator +(fraction first, const fraction &second);
fraction operator +(fraction first, const int val);
fraction operator +(const int val, fraction first);
fraction operator -(fraction first, const fraction &second);
fraction operator -(fraction first, const int val);
fraction operator -(const int val, fraction first);
fraction operator *(fraction first, const fraction &second);
fraction operator *(fraction first, const int val);
fraction operator *(const int val, fraction first);
fraction operator /(fraction first, const fraction &second);
fraction operator /(fraction first, const int val);
fraction operator /(const int val, fraction first);
bool operator <(const int, const fraction);
bool operator >(const int, const fraction);
bool operator <=(const int, const fraction);
bool operator >=(const int, const fraction);
bool operator ==(const int, const fraction);
std::ostream& operator <<(std::ostream& ot,const fraction &fr);
#endif // FRACTION_H
