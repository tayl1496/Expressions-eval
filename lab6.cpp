#include <iostream>

#include "LinkedList.h"
#include "Rational.h"

int main() {

   std::cout << "Test Rational methods:"
             << std::endl;

   Rational zero;

   std::cout << "Default ctor = "
             << zero
             << std::endl;

   Rational one(1);

   std::cout << "One-arg ctor = "
             << one
             << std::endl;

   Rational oneHalf(17, 34);

   std::cout << "Two-arg ctor = "
             << oneHalf
             << std::endl;

   Rational anotherHalf(oneHalf);

   std::cout << "Copy ctor = "
             << anotherHalf
             << std::endl;

   std::cout << "Prefix Increment = "
             << ++oneHalf;
   std::cout << " oneHalf = "
             << oneHalf
             << std::endl;

   std::cout << "Postfix Increment = "
             << oneHalf++;
   std::cout << " oneHalf = "
             << oneHalf
             << std::endl;

   std::cout << "Prefix Decrement = "
             << --oneHalf;
   std::cout << " oneHalf = "
             << oneHalf
             << std::endl;

   std::cout << "Postfix Decrement = "
             << oneHalf--;
   std::cout << " oneHalf = "
             << oneHalf
             << std::endl;

   Rational twoThirds(2, 3);

   std::cout << "Is 1/2 Less Than 2/3: ";

   if (oneHalf < twoThirds) {
      std::cout << "OK."
                << std::endl;
   }
   else {
      std::cout << "ERROR."
                << std::endl;
   }

   std::cout << "Is 2/3 Less Than 1/2: ";

   if (twoThirds < oneHalf) {
      std::cout << "ERROR."
                << std::endl;
   }
   else {
      std::cout << "OK."
                << std::endl;
   }

   std::cout << "Is 1/2 Less Than 1/2: ";

   if (oneHalf < anotherHalf) {
      std::cout << "ERROR."
                << std::endl;
   }
   else {
      std::cout << "OK."
                << std::endl;
   }

   std::cout << "Is 1/2 Greater Than 2/3: ";

   if (oneHalf > twoThirds) {
      std::cout << "ERROR."
                << std::endl;
   }
   else {
      std::cout << "OK."
                << std::endl;
   }

   std::cout << "Is 2/3 Greater Than 1/2: ";

   if (twoThirds > oneHalf) {
      std::cout << "OK."
                << std::endl;
   }
   else {
      std::cout << "ERROR."
                << std::endl;
   }

   std::cout << "Is 1/2 Greater Than 1/2: ";

   if (oneHalf > anotherHalf) {
      std::cout << "ERROR."
                << std::endl;
   }
   else {
      std::cout << "OK."
                << std::endl;
   }

   std::cout << "Is 1/2 Less Than Or Equal To 2/3: ";

   if (oneHalf <= twoThirds) {
      std::cout << "OK."
                << std::endl;
   }
   else {
      std::cout << "ERROR."
                << std::endl;
   }

   std::cout << "Is 2/3 Less Than Or Equal To 1/2: ";

   if (twoThirds <= oneHalf) {
      std::cout << "ERROR."
                << std::endl;
   }
   else {
      std::cout << "OK."
                << std::endl;
   }

   std::cout << "Is 1/2 Less Than Or Equal To 1/2: ";

   if (oneHalf <= anotherHalf) {
      std::cout << "OK."
                << std::endl;
   }
   else {
      std::cout << "ERROR."
                << std::endl;
   }

   std::cout << "Is 1/2 Greater Than Or Equal To 2/3: ";

   if (oneHalf >= twoThirds) {
      std::cout << "ERROR."
                << std::endl;
   }
   else {
      std::cout << "OK."
                << std::endl;
   }

   std::cout << "Is 2/3 Greater Than Or Equal To 1/2: ";

   if (twoThirds >= oneHalf) {
      std::cout << "OK."
                << std::endl;
   }
   else {
      std::cout << "ERROR."
                << std::endl;
   }

   std::cout << "Is 1/2 Greater Than Or Equal To 1/2: ";

   if (oneHalf >= anotherHalf) {
      std::cout << "OK."
                << std::endl;
   }
   else {
      std::cout << "ERROR."
                << std::endl;
   }

   std::cout << "Is 1/2 Equal To 2/3: ";

   if (oneHalf == twoThirds) {
      std::cout << "ERROR."
                << std::endl;
   }
   else {
      std::cout << "OK."
                << std::endl;
   }

   std::cout << "Is 2/3 Equal To 1/2: ";

   if (twoThirds == oneHalf) {
      std::cout << "ERROR."
                << std::endl;
   }
   else {
      std::cout << "OK."
                << std::endl;
   }

   std::cout << "Is 1/2 Equal To 1/2: ";

   if (oneHalf == anotherHalf) {
      std::cout << "OK."
                << std::endl;
   }
   else {
      std::cout << "ERROR."
                << std::endl;
   }

   std::cout << "Is 1/2 Not Equal To 2/3: ";

   if (oneHalf != twoThirds) {
      std::cout << "OK."
                << std::endl;
   }
   else {
      std::cout << "ERROR."
                << std::endl;
   }

   std::cout << "Is 2/3 Not Equal To 1/2: ";

   if (twoThirds != oneHalf) {
      std::cout << "OK."
                << std::endl;
   }
   else {
      std::cout << "ERROR."
                << std::endl;
   }

   std::cout << "Is 1/2 Not Equal To 1/2: ";

   if (oneHalf != anotherHalf) {
      std::cout << "ERROR."
                << std::endl;
   }
   else {
      std::cout << "OK."
                << std::endl;
   }

   std::cout << "Addition:"
             << std::endl;

   std::cout << oneHalf
             << " + "
             << twoThirds
             << " = "
             << oneHalf + twoThirds
             << "; should be 7/6"
             << std::endl;

   std::cout << "Subtraction:"
             << std::endl;

   std::cout << oneHalf
             << " - "
             << twoThirds
             << " = "
             << oneHalf - twoThirds
             << "; should be -1/6"
             << std::endl;

   std::cout << "Multiplication:"
             << std::endl;

   std::cout << oneHalf
             << " * "
             << twoThirds
             << " = "
             << oneHalf * twoThirds
             << "; should be 1/3"
             << std::endl;

   std::cout << "Division:"
             << std::endl;

   std::cout << oneHalf
             << " / "
             << twoThirds
             << " = "
             << oneHalf / twoThirds
             << "; should be 3/4"
             << std::endl;


   std::cout << "Add and Assign:"
             << std::endl;

   Rational r(3, 4);

   std::cout << r
             << " += "
             << twoThirds
             << " = ";

   r += twoThirds;

   std::cout << r
             << "; should be 17/12"
             << std::endl;

   std::cout << "Subtract and Assign:"
             << std::endl;

   r = Rational(3, 4);

   std::cout << r
             << " -= "
             << twoThirds
             << " = ";

   r -= twoThirds;

   std::cout << r
             << "; should be 1/12"
             << std::endl;

   std::cout << "Multiply and Assign:"
             << std::endl;

   r = Rational(3, 4);

   std::cout << r
             << " *= "
             << twoThirds
             << " = ";

   r *= twoThirds;

   std::cout << r
             << "; should be 1/2"
             << std::endl;

   std::cout << "Divide and Assign:"
             << std::endl;

   r = Rational(3, 4);

   std::cout << r
             << " /= "
             << twoThirds
             << " = ";

   r /= twoThirds;

   std::cout << r
             << "; should be 9/8"
             << std::endl;

   std::cout << "Test of Double Conversion Operator:"
             << std::endl
             << twoThirds
             << " = "
             << (double)twoThirds
             << "; should be "
             << 2.0 / 3.0
             << std::endl;

   std::cout << "Test of Assign an Integer:"
             << std::endl;

   Rational three;

   three = 3;

   std::cout << "Three = "
             << three
             << "; should be 3/1"
             << std::endl;

   std::cout << "Test of Assign a Rational:"
             << std::endl;

   Rational anotherTwoThirds;

   anotherTwoThirds = twoThirds;

   std::cout << "anotherTwoThirds = "
             << anotherTwoThirds
             << "; should be 2/3"
             << std::endl;

   std::cout << "Test input streaming:"
             << std::endl;

   LinkedList<Rational> listOfRational;

   while (one != zero) {
      std::cout << "Enter a rational (zero quits): ";
      std::cin >> one;

      listOfRational.insert(listOfRational.getLength() + 1, one);
   }

   std::cout << "Here are the rationals you entered:"
             << std::endl;

   std::cout << listOfRational
             << std::endl;

   LinkedList<int> listOfInteger;

   int in = 1;

   while (in != 0) {
      std::cout << "Enter an int (zero quits): ";
      std::cin >> in;

      listOfInteger.insert(listOfInteger.getLength() + 1, in);
   }

   std::cout << "Here are the integers you entered:"
             << std::endl;

   std::cout << listOfInteger
             << std::endl;

   std::cout << "All done!"
             << std::endl;

   return EXIT_SUCCESS;
}
