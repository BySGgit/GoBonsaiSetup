int __thiscall sub_43DC30(int *this, const unsigned __int16 *a2, int a3)
{
  int v3; // esi
  int v4; // eax
  int v5; // edx
  _DWORD *v6; // esi
  int result; // eax

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
    while ( *(_DWORD *)(*(_DWORD *)v5 + 44) != 28 || *(_DWORD *)(*(_DWORD *)v5 + 48) != 4 )
    {
      ++v4;
      v5 += 4;
      if ( v4 >= v3 )
        goto LABEL_6;
    }
    v6 = *(_DWORD **)v5;
  }
  result = sub_434450(v6, a2);
  if ( result == -1 )
    return sub_434240((int)a2, v6, a3);
  return result;
}
