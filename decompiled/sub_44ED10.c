int *__stdcall sub_44ED10(int a1, char *a2, int *a3, int *a4, int a5)
{
  int *result; // eax
  _DWORD *v6; // eax
  int v7; // ecx
  _DWORD v8[9]; // [esp+0h] [ebp-24h] BYREF

  v8[5] = v8;
  result = a3;
  v8[4] = a3;
  v8[8] = 0;
  while ( result != a4 )
  {
    v6 = sub_44ECA0(a2, *((_DWORD *)a2 + 1), result + 2);
    v7 = *(_DWORD *)(a1 + 4);
    if ( v7 == 107374181 )
      std::_Xlength_error("list<T> too long");
    *(_DWORD *)(a1 + 4) = v7 + 1;
    *((_DWORD *)a2 + 1) = v6;
    *(_DWORD *)v6[1] = v6;
    result = (int *)*a3;
    a3 = (int *)*a3;
  }
  return result;
}
