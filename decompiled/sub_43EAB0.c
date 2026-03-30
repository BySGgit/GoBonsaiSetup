int __thiscall sub_43EAB0(int *this, int a2, int a3)
{
  int v3; // esi
  int v4; // eax
  int v5; // edx
  _DWORD *v6; // ecx
  unsigned int v7; // esi
  int result; // eax
  _DWORD *v9; // edx
  int (__stdcall *v10)(int, _DWORD, _DWORD *, _DWORD); // edx

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
      if ( *(_DWORD *)(*(_DWORD *)v5 + 44) == 32 && v6[12] == 4 )
        break;
      ++v4;
      v5 += 4;
      if ( v4 >= v3 )
        goto LABEL_6;
    }
  }
  v7 = v6[219];
  result = 0;
  if ( v7 )
  {
    while ( 1 )
    {
      if ( result >= 0 && result < (int)v7 )
      {
        v9 = *(_DWORD **)(*(_DWORD *)(v6[218] + 4 * result) + 512);
        if ( v9 )
        {
          if ( *v9 == a2 && v9[1] == a3 )
            break;
        }
      }
      if ( ++result >= v7 )
        return result;
    }
    if ( result < v7 )
    {
      v6[151] = result;
      v6[152] = result;
      result = v6[6];
      v10 = *(int (__stdcall **)(int, _DWORD, _DWORD *, _DWORD))(result + 576);
      if ( v10 )
      {
        if ( *(_BYTE *)result )
          return v10(513, v6[11], v6, *(_DWORD *)(result + 580));
      }
    }
  }
  return result;
}
