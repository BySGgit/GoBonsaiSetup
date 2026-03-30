void __usercall _87except(int a1@<ebp>, int a2, int a3, __int16 *a4)
{
  __int16 v4; // cx
  bool v5; // zf
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  unsigned int v12; // [esp-88h] [ebp-94h] BYREF
  DWORD v13; // [esp-84h] [ebp-90h]
  double v14[8]; // [esp-80h] [ebp-8Ch] BYREF
  unsigned int v15; // [esp-40h] [ebp-4Ch]
  int v16; // [esp+0h] [ebp-Ch]
  void *v17; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v16 = a1;
  v17 = retaddr;
  v4 = *a4;
  v6 = *(_DWORD *)a3 - 1;
  v5 = *(_DWORD *)a3 == 1;
  v12 = (unsigned __int16)*a4;
  if ( v5 )
    goto LABEL_13;
  v7 = v6 - 1;
  if ( !v7 )
  {
    v13 = 4;
    goto LABEL_14;
  }
  v8 = v7 - 1;
  if ( !v8 )
  {
    v13 = 17;
    goto LABEL_14;
  }
  v9 = v8 - 1;
  if ( !v9 )
  {
    v13 = 18;
    goto LABEL_14;
  }
  v10 = v9 - 1;
  if ( !v10 )
  {
LABEL_13:
    v13 = 8;
LABEL_14:
    if ( !_handle_exc(v13, (double *)(a3 + 24), v4) )
    {
      if ( a2 == 16 || a2 == 22 || a2 == 29 )
      {
        v14[6] = *(double *)(a3 + 16);
        v15 = v15 & 0xFFFFFFE0 | 3;
      }
      else
      {
        v15 &= ~1u;
      }
      _raise_exc((ULONG_PTR)v14, &v12, v13, a2, (float *)(a3 + 8), (float *)(a3 + 24));
    }
    goto LABEL_21;
  }
  v11 = v10 - 2;
  if ( !v11 )
  {
    *(_DWORD *)a3 = 1;
    goto LABEL_21;
  }
  if ( v11 == 1 )
  {
    v13 = 16;
    goto LABEL_14;
  }
LABEL_21:
  _ctrlfp(v4);
  if ( *(_DWORD *)a3 == 8 || dword_4CA1B0 || !sub_46673E() )
    _set_errno_from_matherr(*(_DWORD *)a3);
}
