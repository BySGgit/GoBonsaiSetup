_DWORD *__thiscall sub_4461A0(void *this, _DWORD *a2, int a3, int a4, int a5, int a6, int a7, int a8, int *a9)
{
  int v9; // esi
  _DWORD *v11; // eax
  size_t v12; // eax
  int v13; // ebx
  int v14; // edx
  int v15; // edi
  int v16; // eax
  int v17; // esi
  void (__thiscall ***v18)(_DWORD, int); // esi
  int *v19; // eax
  int v20; // edx
  _DWORD *result; // eax
  int v22; // edx
  _DWORD *v23; // [esp+10h] [ebp-5Ch]
  int v24; // [esp+14h] [ebp-58h] BYREF
  int v25; // [esp+18h] [ebp-54h] BYREF
  int *v26; // [esp+1Ch] [ebp-50h]
  _DWORD *v27; // [esp+20h] [ebp-4Ch]
  int v28; // [esp+24h] [ebp-48h] BYREF
  _BYTE v29[8]; // [esp+28h] [ebp-44h] BYREF
  int v30; // [esp+30h] [ebp-3Ch]
  _BYTE v31[32]; // [esp+38h] [ebp-34h] BYREF
  int v32; // [esp+68h] [ebp-4h]

  v9 = a7;
  v27 = a2;
  v23 = (_DWORD *)a8;
  v26 = a9;
  v24 = 0;
  v11 = sub_44DB70(a7, a8, &v28);
  v32 = 0;
  v12 = sub_447780(&a5, (int)v11, (int)this, v31, (int)&a3, *(_DWORD *)(v9 + 20));
  v13 = _Stollx((int)v31, (int)&v25, v12, (int)&v24);
  v32 = -1;
  v30 = v14;
  if ( v28 )
  {
    v15 = v28;
    std::_Lockit::_Lockit((std::_Lockit *)v29, 0);
    v16 = *(_DWORD *)(v15 + 4);
    if ( v16 && v16 != -1 )
      *(_DWORD *)(v15 + 4) = v16 - 1;
    v17 = -(*(_DWORD *)(v15 + 4) == 0);
    std::_Lockit::~_Lockit((std::_Lockit *)v29);
    v18 = (void (__thiscall ***)(_DWORD, int))(v15 & v17);
    if ( v18 )
      (**v18)(v18, 1);
  }
  if ( (unsigned __int8)sub_44BB00(&a5, &a3) )
    *v23 |= 1u;
  if ( (_BYTE *)v25 == v31 || v24 )
  {
    *v23 |= 2u;
  }
  else
  {
    v19 = v26;
    v20 = v30;
    *v26 = v13;
    v19[1] = v20;
  }
  result = v27;
  v22 = a4;
  *v27 = a3;
  result[1] = v22;
  return result;
}
