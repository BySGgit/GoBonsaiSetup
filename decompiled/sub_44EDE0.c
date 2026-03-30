_DWORD *__userpurge sub_44EDE0@<eax>(_DWORD *a1@<edi>, int a2@<esi>, _DWORD **a3)
{
  _DWORD *v4; // ecx
  _DWORD *v6; // [esp+4h] [ebp+4h]

  v4 = *a3;
  v6 = *a3;
  if ( a3 == *(_DWORD ***)a2 )
  {
    *a1 = v4;
  }
  else
  {
    *a3[1] = *a3;
    (*a3)[1] = a3[1];
    operator delete(a3);
    --*(_DWORD *)(a2 + 4);
    *a1 = v6;
  }
  return a1;
}
