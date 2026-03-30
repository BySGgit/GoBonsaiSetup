int __cdecl raise(int Signal)
{
  DWORD *v1; // edi
  DWORD *v2; // eax
  int result; // eax
  int *v4; // esi
  PVOID v5; // eax
  void (__cdecl *v6)(int, DWORD); // eax
  DWORD v7; // [esp+10h] [ebp-30h]
  DWORD v8; // [esp+14h] [ebp-2Ch]
  int i; // [esp+1Ch] [ebp-24h]
  void (__cdecl *v10)(int, DWORD); // [esp+20h] [ebp-20h]
  int v11; // [esp+24h] [ebp-1Ch]

  v1 = 0;
  v11 = 0;
  if ( Signal > 11 )
  {
    if ( Signal == 15 )
    {
      v4 = &dword_4D7C7C;
      v5 = (PVOID)dword_4D7C7C;
      goto LABEL_18;
    }
    if ( Signal == 21 )
    {
      v4 = &dword_4D7C74;
      v5 = (PVOID)dword_4D7C74;
      goto LABEL_18;
    }
    if ( Signal != 22 )
      goto LABEL_14;
    goto LABEL_15;
  }
  if ( Signal != 11 )
  {
    if ( Signal == 2 )
    {
      v4 = (int *)&dword_4D7C70;
      v5 = dword_4D7C70;
LABEL_18:
      v11 = 1;
      v6 = (void (__cdecl *)(int, DWORD))DecodePointer(v5);
      goto LABEL_19;
    }
    if ( Signal != 4 )
    {
      if ( Signal != 6 )
      {
        if ( Signal == 8 )
          goto LABEL_7;
LABEL_14:
        *_errno() = 22;
        _invalid_parameter_noinfo();
        return -1;
      }
LABEL_15:
      v4 = (int *)&dword_4D7C78;
      v5 = dword_4D7C78;
      goto LABEL_18;
    }
  }
LABEL_7:
  v2 = _getptd_noexit();
  v1 = v2;
  if ( !v2 )
    return -1;
  v4 = (int *)(siglookup(Signal, v2[23]) + 8);
  v6 = (void (__cdecl *)(int, DWORD))*v4;
LABEL_19:
  v10 = v6;
  result = 0;
  if ( v10 == (void (__cdecl *)(int, DWORD))1 )
    return result;
  if ( !v10 )
    _exit(3);
  if ( v11 )
    _lock(0);
  if ( Signal == 8 || Signal == 11 || Signal == 4 )
  {
    v8 = v1[24];
    v1[24] = 0;
    if ( Signal != 8 )
      goto LABEL_33;
    v7 = v1[25];
    v1[25] = 140;
  }
  if ( Signal == 8 )
  {
    for ( i = 3; i < 12; ++i )
      *(_DWORD *)(12 * i + v1[23] + 8) = 0;
    goto LABEL_37;
  }
LABEL_33:
  *v4 = (int)_encoded_null();
LABEL_37:
  if ( v11 )
    _unlock(0);
  if ( Signal == 8 )
    v10(8, v1[25]);
  else
    ((void (__cdecl *)(int))v10)(Signal);
  if ( Signal == 8 || Signal == 11 || Signal == 4 )
  {
    v1[24] = v8;
    if ( Signal == 8 )
      v1[25] = v7;
  }
  return 0;
}
