BOOL __thiscall sub_4345B0(int this, POINT pt)
{
  BOOL result; // eax

  if ( PtInRect((const RECT *)(this + 64), pt) )
    return 1;
  result = PtInRect((const RECT *)(this + 108), pt);
  if ( result )
    return 1;
  return result;
}
