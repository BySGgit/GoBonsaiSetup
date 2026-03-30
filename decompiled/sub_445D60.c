_DWORD *__thiscall sub_445D60(void *this, _DWORD *a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8, int a9)
{
  int v9; // esi
  _DWORD *v10; // ebp
  _DWORD *v12; // eax
  size_t v13; // ebx
  int v14; // edi
  int v15; // eax
  int v16; // esi
  void (__thiscall ***v17)(_DWORD, int); // esi
  int v18; // eax
  int v19; // ebx
  _DWORD *result; // eax
  int v21; // ecx
  char *v22; // [esp+14h] [ebp-4Ch]
  int v23; // [esp+18h] [ebp-48h] BYREF
  int v24; // [esp+1Ch] [ebp-44h] BYREF
  int *v25; // [esp+20h] [ebp-40h]
  int v26; // [esp+24h] [ebp-3Ch] BYREF
  _DWORD *v27; // [esp+28h] [ebp-38h]
  int v28; // [esp+2Ch] [ebp-34h] BYREF
  char v29; // [esp+30h] [ebp-30h] BYREF
  _BYTE v30[31]; // [esp+31h] [ebp-2Fh] BYREF
  int v31; // [esp+5Ch] [ebp-4h]

  v9 = a7;
  v10 = a8;
  v27 = a2;
  v25 = (int *)a9;
  v23 = 0;
  v12 = sub_44DB70(a7, a9, &v26);
  v31 = 0;
  v13 = sub_447780(&a5, (int)v12, (int)this, &v29, (int)&a3, *(_DWORD *)(v9 + 20));
  v31 = -1;
  if ( v26 )
  {
    v14 = v26;
    std::_Lockit::_Lockit((std::_Lockit *)&v24, 0);
    v15 = *(_DWORD *)(v14 + 4);
    if ( v15 && v15 != -1 )
      *(_DWORD *)(v14 + 4) = v15 - 1;
    v16 = -(*(_DWORD *)(v14 + 4) == 0);
    std::_Lockit::~_Lockit((std::_Lockit *)&v24);
    v17 = (void (__thiscall ***)(_DWORD, int))(v14 & v16);
    if ( v17 )
      (**v17)(v17, 1);
  }
  if ( v29 == 45 )
  {
    v22 = v30;
    v18 = _Stoulx((int)v30, (int)&v28, v13, (int)&v23);
  }
  else
  {
    v22 = &v29;
    v18 = _Stoulx((int)&v29, (int)&v28, v13, (int)&v23);
  }
  v19 = v18;
  if ( (unsigned __int8)sub_44BB00(&a5, &a3) )
    *v10 |= 1u;
  if ( (char *)v28 == v22 || v23 )
  {
    *v10 |= 2u;
  }
  else
  {
    if ( v29 == 45 )
      v19 = -v19;
    *v25 = v19;
  }
  result = v27;
  v21 = a4;
  *v27 = a3;
  result[1] = v21;
  return result;
}
