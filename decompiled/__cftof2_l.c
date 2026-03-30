int __usercall _cftof2_l@<eax>(
        char *Str@<ecx>,
        _DWORD *a2@<eax>,
        int a3,
        int Size,
        char a5,
        struct localeinfo_struct *a6)
{
  int v8; // esi
  char *v10; // esi
  int v11; // eax
  size_t v12; // eax
  char *v13; // esi
  size_t v14; // eax
  int v15; // edi
  int v16; // edi
  int v17; // [esp+Ch] [ebp-10h] BYREF
  int v18; // [esp+14h] [ebp-8h]
  char v19; // [esp+18h] [ebp-4h]

  v8 = a2[1] - 1;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v17, a6);
  if ( Str && a3 )
  {
    if ( a5 && v8 == Size )
      *(_WORD *)&Str[v8 + (*a2 == 45)] = 48;
    v10 = Str;
    if ( *a2 == 45 )
    {
      *Str = 45;
      v10 = Str + 1;
    }
    v11 = a2[1];
    if ( v11 > 0 )
    {
      v13 = &v10[v11];
    }
    else
    {
      v12 = strlen(v10);
      memcpy(v10 + 1, v10, v12 + 1);
      *v10 = 48;
      v13 = v10 + 1;
    }
    if ( Size > 0 )
    {
      v14 = strlen(v13);
      memcpy(v13 + 1, v13, v14 + 1);
      *v13 = ***(_BYTE ***)(v17 + 188);
      v15 = a2[1];
      if ( v15 < 0 )
      {
        v16 = -v15;
        if ( a5 || Size >= v16 )
          Size = v16;
        _shift(v13 + 1, Size);
        memset(v13 + 1, 48, Size);
      }
    }
    if ( v19 )
      *(_DWORD *)(v18 + 112) &= ~2u;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( v19 )
      *(_DWORD *)(v18 + 112) &= ~2u;
    return 22;
  }
}
