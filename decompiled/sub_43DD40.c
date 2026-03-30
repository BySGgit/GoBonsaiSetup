unsigned int __thiscall sub_43DD40(int *this, _DWORD *a2, unsigned int *a3)
{
  int v3; // esi
  int v4; // eax
  int v5; // edx
  _DWORD *v6; // ecx
  int v7; // eax
  unsigned int result; // eax
  unsigned int v9; // eax

  v3 = *(this + 157);
  v4 = 0;
  if ( v3 <= 0 )
  {
LABEL_6:
    v6 = 0;
  }
  else
  {
    v5 = *(this + 156);
    while ( 1 )
    {
      v6 = *(_DWORD **)v5;
      if ( *(_DWORD *)(*(_DWORD *)v5 + 44) == 9 && v6[12] == 4 )
        break;
      ++v4;
      v5 += 4;
      if ( v4 >= v3 )
        goto LABEL_6;
    }
  }
  v7 = v6[151];
  if ( v7 >= 0 )
  {
    v9 = *(_DWORD *)(*(_DWORD *)(v6[218] + 4 * v7) + 512);
    *a2 = (unsigned __int16)v9;
    result = HIWORD(v9);
    *a3 = result;
  }
  else
  {
    *a2 = 0;
    *a3 = 0;
    return 0;
  }
  return result;
}
