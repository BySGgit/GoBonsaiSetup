BOOL __thiscall sub_432E30(const RECT *this, POINT pt)
{
  BOOL result; // eax

  if ( PtInRect(this + 4, pt) )
    return 1;
  result = PtInRect(this + 38, pt);
  if ( result )
    return 1;
  return result;
}
