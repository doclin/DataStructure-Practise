#include "polynomial.h"

int main()
{
   Polynomial ah,bh,ch;
   ah.input_poly();      //input polynomial a
   ah.output_poly();
   bh.input_poly();      //input polynomial b
   bh.output_poly();
   ch = ah*bh;
   ch.output_poly();     //output the result
   return 0;
}


/*
Please input a polynomial:
Input the coefficient: (input '0' to end)
1
Input the exponent: 
2
Nice, next one:
Input the coefficient: (input '0' to end)
-3
Input the exponent: 
4
Nice, next one:
Input the coefficient: (input '0' to end)
5
Input the exponent: 
3
Nice, next one:
Input the coefficient: (input '0' to end)
0
1x^(2)+5x^(+3)-3x^(+4)
Please input a polynomial:
Input the coefficient: (input '0' to end)
2
Input the exponent: 
2
Nice, next one:
Input the coefficient: (input '0' to end)
1
Input the exponent: 
0
Nice, next one:
Input the coefficient: (input '0' to end)
0
+1x^(+0)+2x^(+2)
+1x^(+2)+5x^(+3)-1x^(+4)+10x^(+5)-6x^(+6)
*/