void *__usercall sub_436890@<eax>(float *a1@<ecx>, int a2@<edi>)
{
  void *result; // eax
  int v4; // edx
  unsigned __int16 *v5; // eax
  unsigned int v6; // kr00_4
  int v7; // eax
  const WCHAR *Args_4; // [esp+4h] [ebp-498h]
  wchar_t Buffer[64]; // [esp+10h] [ebp-48Ch] BYREF
  unsigned __int16 v10[514]; // [esp+90h] [ebp-40Ch] BYREF

  v10[0] = 0;
  result = memset(&v10[1], 0, 0x3FEu);
  if ( a1 )
  {
    sub_419310(Buffer, (wchar_t *)L"%.9f ", *a1);
    v4 = 512;
    v5 = v10;
    while ( *v5 )
    {
      ++v5;
      if ( !--v4 )
        goto LABEL_7;
    }
    sub_4193D0(v4, &v10[512 - v4], (int)Buffer, 0x7FFFFFFF);
LABEL_7:
    v6 = wcslen(v10);
    if ( v6 )
      Buffer[v6 + 63] = 0;
    sub_436D90((const void **)(a2 + 80), v10);
    Args_4 = *(const WCHAR **)(a2 + 80);
    *(_DWORD *)(a2 + 304) = 0;
    v7 = lstrlenW(Args_4);
    sub_435650(v7, (_DWORD *)a2);
    result = *(void **)(a2 + 292);
    *(_DWORD *)(a2 + 300) = result;
  }
  return result;
}
