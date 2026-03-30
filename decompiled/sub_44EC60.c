_DWORD *__usercall sub_44EC60@<eax>(int a1@<esi>)
{
  _DWORD *result; // eax
  _DWORD *v2; // edi

  result = **(_DWORD ***)a1;
  **(_DWORD **)a1 = *(_DWORD *)a1;
  *(_DWORD *)(*(_DWORD *)a1 + 4) = *(_DWORD *)a1;
  *(_DWORD *)(a1 + 4) = 0;
  if ( result != *(_DWORD **)a1 )
  {
    do
    {
      v2 = (_DWORD *)*result;
      operator delete(result);
      result = v2;
    }
    while ( v2 != *(_DWORD **)a1 );
  }
  return result;
}
