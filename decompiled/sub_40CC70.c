_DWORD *__cdecl sub_40CC70(int a1)
{
  _DWORD *result; // eax
  _DWORD *v2; // edi
  float v3[55]; // [esp+8h] [ebp-E0h] BYREF

  result = (_DWORD *)(*(_DWORD *)(a1 + 4) - 6);
  if ( *(_DWORD *)(a1 + 4) != 6 )
  {
    if ( *(_DWORD *)(a1 + 4) == 7 )
    {
      return (_DWORD *)sub_40CAB0((float *)a1);
    }
    else if ( *(_DWORD *)(a1 + 4) == 10 )
    {
      sub_40B380((int)v3);
      return (_DWORD *)sub_40CBA0(a1, v3);
    }
    else
    {
      result = *(_DWORD **)(a1 + 168);
      v2 = (_DWORD *)*result;
      if ( (_DWORD *)*result != result )
      {
        do
        {
          result = (_DWORD *)sub_40CC70(v2[2]);
          v2 = (_DWORD *)*v2;
        }
        while ( v2 != *(_DWORD **)(a1 + 168) );
      }
    }
  }
  return result;
}
