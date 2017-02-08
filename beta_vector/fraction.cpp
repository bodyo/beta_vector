#include "fraction.h"
int gcd(int a, int b)
{
  int c;
  while (b)
  {
     c = a % b;
     a = b;
     b = c;
  }
  return abs(a);
}

void fraction::reduce()
{
  ch==0?zn=0:zn=zn;
  int a = gcd(ch>0?ch:-ch, zn>0?zn:-zn);
  ch/=a;
  zn/=a;
  if((ch > 0&&zn < 0)||((ch < 0&&zn < 0)))
  {
    ch=-ch;
    zn=-zn;
  }
}

fraction fraction::operator +=(const int val)
{
  ch = zn*val+ch;
  reduce();
  return *this;
}

fraction fraction::operator +=(const fraction &res)
{
  ch = ch*res.zn + zn*res.ch;
  zn = zn*res.zn;
  reduce();
  return *this;
}

fraction fraction::operator -=(const int val)
{
  ch = ch-val*zn;
  reduce();
  return *this;
}

fraction fraction::operator -=(const fraction &res)
{
  ch = ch*res.zn - zn*res.ch;
  zn = zn*res.zn;
  reduce();
  return *this;
}

fraction operator +(fraction first, const fraction &second)
{
  return first+=second;
}

fraction operator +(fraction first, const int val)
{
  return first+=val;
}

fraction operator +(const int val, fraction &first)
{
  return first+=val;
}

fraction operator -(fraction first, const fraction &second)
{
  return first-=second;
}

fraction operator -(fraction first, const int val)
{
  return first-=val;
}

fraction operator -(const int val, fraction first)
{
  return first-=val;
}

fraction fraction::operator *=(const fraction &res)
{
  ch*=res.ch;
  zn*=res.zn;
  reduce();
  return *this;
}

fraction fraction::operator *=(const int val)
{
  ch*=val;
  reduce();
  return *this;
}

fraction fraction::operator /=(const fraction &res)
{
  ch*=res.zn;
  zn*=res.ch;
  reduce();
  return *this;
}

fraction fraction::operator /=(const int val)
{
  zn*=val;
  reduce();
  return *this;
}

fraction operator *(fraction first, const fraction &second)
{
  return first*=second;
}

fraction operator *(fraction first, const int val)
{
  return first*=val;
}

fraction operator *(const int val, fraction first)
{
  return first*=val;
}

fraction operator /(fraction first, const fraction &second)
{
  return first/=second;
}

fraction operator /(fraction first, const int val)
{
  return first/=val;
}

fraction operator /(const int val, fraction first)
{
  first/=val;
  return first.swapp();
}

std::ostream& operator <<(std::ostream& ot,const fraction &fr)
{
  ot << fr.get_ch() << '/' << fr.get_zn() << ' ';
  return ot;
}

std::istream& operator >>(std::istream& os, fraction &temp)
{
  os >> temp.ch >> temp.zn;
  temp.reduce();
  return os;
}

fraction fraction::swapp()
{
  int a = ch;
  ch = zn;
  zn = a;
  reduce();
  return *this;
}

fraction& fraction::operator ++()
{
  ch = ch+zn;
  reduce();
  return *this;
}

fraction fraction::operator ++(int)
{
  fraction res = *this;
  ch = ch+zn;
  reduce();
  return res;
}

fraction& fraction::operator --()
{
  ch = ch-zn;
  reduce();
  return *this;
}

fraction fraction::operator --(int)
{
  fraction res = *this;
  ch = ch-zn;
  reduce();
  return res;
}

bool fraction::operator <(const fraction& result) const
{
  return ch*result.zn < zn*result.ch;
}

bool fraction::operator <=(const fraction& result) const
{
  return ch*result.zn <= zn*result.ch;
}

bool fraction::operator >(const fraction& result) const
{
  return ch*result.zn > zn*result.ch;
}

bool fraction::operator >=(const fraction& result) const
{
  return ch*result.zn >= zn*result.ch;
}

bool fraction::operator ==(const fraction& result) const
{
  return ch == result.ch&&zn == result.zn;
}

bool fraction::operator <(const int val) const
{
  return ch < val*zn;
}

bool fraction::operator >(const int val) const
{
  return ch > val*zn;
}

bool fraction::operator <=(const int val) const
{
  return ch <= val*zn;
}

bool fraction::operator >=(const int val) const
{
  return ch >= val*zn;
}

bool fraction::operator ==(const int val) const
{
  return ch == val && zn == 1;
}

bool operator <(const int val1, const fraction val2)
{
  return val2 >= val1;
}

bool operator >(const int val1, const fraction val2)
{
  return val2 <= val1;
}

bool operator >=(const int val1, const fraction val2)
{
  return val2 < val1;
}

bool operator <=(const int val1, const fraction val2)
{
  return val2 >= val1;
}

bool operator ==(const int val1, const fraction val2)
{
  return val2 == val1;
}

fraction fraction::operator-() const
{
  fraction res(*this);
  res.ch = -ch;
  return res;
}
