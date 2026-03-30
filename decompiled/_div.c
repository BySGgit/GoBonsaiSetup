div_t __cdecl div(int Numerator, int Denominator)
{
  div_t result; // rax

  result.quot = Numerator / Denominator;
  result.rem = Numerator % Denominator;
  return result;
}
