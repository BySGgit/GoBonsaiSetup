bool __thiscall sub_42D910(_DWORD *this, _DWORD *a2)
{
  int v2; // edx
  _DWORD *v3; // ecx
  int v4; // eax

  if ( (int)*(this + 1) <= 0 )
  {
LABEL_6:
    v4 = -1;
  }
  else
  {
    v2 = *(this + 1);
    v3 = (_DWORD *)*this;
    v4 = 0;
    while ( *a2 != *v3 )
    {
      ++v4;
      ++v3;
      if ( v4 >= v2 )
        goto LABEL_6;
    }
  }
  return v4 != -1;
}
