_DWORD *__thiscall sub_445EE0(void *this, _DWORD *a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8, int a9)
{
  int v9; // esi
  _DWORD *v10; // ebp
  _DWORD *v12; // eax
  size_t v13; // eax
  int v14; // ebx
  int v15; // edi
  int v16; // eax
  int v17; // esi
  void (__thiscall ***v18)(_DWORD, int); // esi
  _DWORD *result; // eax
  int v20; // edx
  int v21; // [esp+14h] [ebp-48h] BYREF
  int v22; // [esp+18h] [ebp-44h] BYREF
  int *v23; // [esp+1Ch] [ebp-40h]
  int v24; // [esp+20h] [ebp-3Ch] BYREF
  _DWORD *v25; // [esp+24h] [ebp-38h]
  int v26; // [esp+28h] [ebp-34h] BYREF
  _BYTE v27[32]; // [esp+2Ch] [ebp-30h] BYREF
  int v28; // [esp+58h] [ebp-4h]

  v9 = a7;
  v10 = a8;
  v25 = a2;
  v23 = (int *)a9;
  v21 = 0;
  v12 = sub_44DB70(a7, a9, &v26);
  v28 = 0;
  v13 = sub_447780(&a5, (int)v12, (int)this, v27, (int)&a3, *(_DWORD *)(v9 + 20));
  v14 = _Stolx((int)v27, (int)&v22, v13, (int)&v21);
  v28 = -1;
  if ( v26 )
  {
    v15 = v26;
    std::_Lockit::_Lockit((std::_Lockit *)&v24, 0);
    v16 = *(_DWORD *)(v15 + 4);
    if ( v16 && v16 != -1 )
      *(_DWORD *)(v15 + 4) = v16 - 1;
    v17 = -(*(_DWORD *)(v15 + 4) == 0);
    std::_Lockit::~_Lockit((std::_Lockit *)&v24);
    v18 = (void (__thiscall ***)(_DWORD, int))(v15 & v17);
    if ( v18 )
      (**v18)(v18, 1);
  }
  if ( (unsigned __int8)sub_44BB00(&a5, &a3) )
    *v10 |= 1u;
  if ( (_BYTE *)v22 == v27 || v21 )
    *v10 |= 2u;
  else
    *v23 = v14;
  result = v25;
  v20 = a4;
  *v25 = a3;
  result[1] = v20;
  return result;
}
