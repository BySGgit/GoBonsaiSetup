_DWORD *__usercall sub_4157C0@<eax>(int a1@<edi>)
{
  _DWORD **v1; // ecx
  _DWORD *result; // eax
  float *v3; // ecx
  _DWORD *v4; // esi

  v1 = *(_DWORD ***)(a1 + 168);
  result = *v1;
  if ( *v1 != v1 )
  {
    do
    {
      v3 = (float *)result[2];
      v4 = (_DWORD *)*result;
      if ( 0.0 == v3[114] )
        (*(void (__thiscall **)(float *))(*(_DWORD *)v3 + 44))(v3);
      result = v4;
    }
    while ( v4 != *(_DWORD **)(a1 + 168) );
  }
  return result;
}
