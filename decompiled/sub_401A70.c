_DWORD *__usercall sub_401A70@<eax>(int a1@<edi>)
{
  _DWORD *v1; // eax
  _DWORD *v2; // esi
  _DWORD **v3; // ecx
  _DWORD *result; // eax
  _DWORD *v5; // esi

  v1 = *(_DWORD **)(a1 + 168);
  v2 = (_DWORD *)*v1;
  if ( (_DWORD *)*v1 != v1 )
  {
    do
    {
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v2[2] + 8))(v2[2]);
      *(_DWORD *)(v2[2] + 180) = 0;
      v2 = (_DWORD *)*v2;
    }
    while ( v2 != *(_DWORD **)(a1 + 168) );
  }
  v3 = *(_DWORD ***)(a1 + 168);
  result = *v3;
  *v3 = v3;
  *(_DWORD *)(*(_DWORD *)(a1 + 168) + 4) = *(_DWORD *)(a1 + 168);
  *(_DWORD *)(a1 + 172) = 0;
  if ( result != *(_DWORD **)(a1 + 168) )
  {
    do
    {
      v5 = (_DWORD *)*result;
      operator delete(result);
      result = v5;
    }
    while ( v5 != *(_DWORD **)(a1 + 168) );
  }
  return result;
}
