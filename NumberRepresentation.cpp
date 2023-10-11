#include <iostream>
#include <bitset>

using namespace std;

union FloatUnion
{
  float number = 13.124f; // f is a suffix that tells the compiler to treat the number as a float literal instead of a double literal
  unsigned int FloatAsUInt;
} m;

union IntUnion
{
  short int number = -32;
  unsigned short int SIasUSI;
}n;

int main() 
{
  cout << "-32 stored in a short int variable\n";
  cout << bitset<16>(n.SIasUSI) << endl << endl;
  
  unsigned int SignBit = m.FloatAsUInt >> 31;
  unsigned int ExponentBits = (m.FloatAsUInt << 1) >> 24;
  unsigned int MantissaBits = m.FloatAsUInt & 0x7FFFFF;

  // Display the individual bits separated by spaces
  cout << "13.124 stored in a float variable\n";
  cout << "Sign Bit: " << SignBit << std::endl;
  cout << "Exponent Bits: " << bitset<8>(ExponentBits) << endl;
  cout << "Mantissa Bits: " << bitset<23>(MantissaBits) << endl;
  
  int d = 40000;
  short int ds = d;
  cout << "40000 stored in a short int variable\n";
  cout << d << " d   " << bitset<32>(ds) << endl;
  cout << ds << "  ds  " << bitset<16>(ds) << endl << endl;
  return 0;
}
