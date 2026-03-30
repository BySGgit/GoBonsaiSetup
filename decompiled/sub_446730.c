_DWORD *__thiscall sub_446730(void *this, _DWORD *a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8, int a9)
{
  _DWORD *v9; // ebx
  _DWORD *v11; // eax
  int v12; // edi
  int v13; // eax
  int v14; // esi
  void (__thiscall ***v15)(_DWORD, int); // esi
  _DWORD *result; // eax
  int v17; // ecx
  int v18; // [esp+10h] [ebp-54h] BYREF
  size_t MaxCount; // [esp+14h] [ebp-50h]
  int v20; // [esp+18h] [ebp-4Ch]
  int v21; // [esp+1Ch] [ebp-48h] BYREF
  size_t *v22; // [esp+20h] [ebp-44h]
  int v23; // [esp+24h] [ebp-40h] BYREF
  _DWORD *v24; // [esp+28h] [ebp-3Ch]
  _BYTE v25[4]; // [esp+2Ch] [ebp-38h] BYREF
  _BYTE v26[32]; // [esp+30h] [ebp-34h] BYREF
  int v27; // [esp+60h] [ebp-4h]

  v9 = a8;
  v24 = a2;
  v22 = (size_t *)a9;
  v18 = 0;
  v11 = sub_44DB70(a7, a9, &v23);
  v27 = 0;
  MaxCount = sub_447780(&a5, (int)v11, (int)this, v26, (int)&a3, 2048);
  v27 = -1;
  if ( v23 )
  {
    v12 = v23;
    std::_Lockit::_Lockit((std::_Lockit *)v25, 0);
    v13 = *(_DWORD *)(v12 + 4);
    if ( v13 && v13 != -1 )
      *(_DWORD *)(v12 + 4) = v13 - 1;
    v14 = -(*(_DWORD *)(v12 + 4) == 0);
    std::_Lockit::~_Lockit((std::_Lockit *)v25);
    v15 = (void (__thiscall ***)(_DWORD, int))(v12 & v14);
    if ( v15 )
      (**v15)(v15, 1);
  }
  MaxCount = _Stoulx((int)v26, (int)&v21, MaxCount, (int)&v18);
  v20 = 0;
  if ( (unsigned __int8)sub_44BB00(&a5, &a3) )
    *v9 |= 1u;
  if ( (_BYTE *)v21 == v26 || v18 )
    *v9 |= 2u;
  else
    *v22 = MaxCount;
  result = v24;
  v17 = a4;
  *v24 = a3;
  result[1] = v17;
  return result;
}
