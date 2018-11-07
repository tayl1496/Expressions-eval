#ifndef RATIONAL_
#define RATIONAL_

#include <iostream>

class Rational {
private:
   int numerator = 0;
   int denominator = 1;

   void lowTerms();
   void normalize();

public:
   Rational(int num = 0,
            int den = 1);

   Rational(const Rational&);

   virtual ~Rational() = default;

   /* Unary member operators that act on 'this'. */
   Rational& operator++();
   Rational operator++(int);
   Rational& operator--();
   Rational operator--(int);

   operator double() const;

   /* Binary member operators acting on 'this' and the right-hand
      side. */
   Rational& operator=(const Rational&);

   Rational& operator=(const int&);

   Rational& operator+=(const Rational&);
   Rational& operator-=(const Rational&);
   Rational& operator*=(const Rational&);
   Rational& operator/=(const Rational&);

   /* Binary non-member operators acting on two Rational arguments:
      left-hand side and right-hand side. */
   friend bool operator<(const Rational&,
                         const Rational&);
   friend bool operator>(const Rational&,
                         const Rational&);
   friend bool operator<=(const Rational&,
                          const Rational&);
   friend bool operator>=(const Rational&,
                          const Rational&);
   friend bool operator==(const Rational&,
                          const Rational&);
   friend bool operator!=(const Rational&,
                          const Rational&);

   friend const Rational operator+(const Rational&,
                                   const Rational&);
   friend const Rational operator-(const Rational&,
                                   const Rational&);
   friend const Rational operator*(const Rational&,
                                   const Rational&);
   friend const Rational operator/(const Rational&,
                                   const Rational&);

   /* Binary non-member operator acting on two arguments: an
      std::ostream object on the left-hand side and a Rational on the
      right-hand side. */
   friend std::ostream& operator<<(std::ostream&,
                                   const Rational&);

   /* Binary non-member operator acting on two arguments: an
      std::istream object on the left-hand side and a Rational on the
      right-hand side. */
   friend std::istream& operator>>(std::istream&,
                                   Rational&);
};

#endif
