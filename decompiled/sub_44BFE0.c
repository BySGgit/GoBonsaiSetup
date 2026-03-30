int *__cdecl sub_44BFE0(int *a1, _DWORD *a2)
{
  int v2; // ecx
  int v3; // esi
  _DWORD *v4; // eax
  struct std::locale::facet *v5; // eax
  int v6; // edi
  int v7; // eax
  int v8; // esi
  void (__thiscall ***v9)(_DWORD, int); // esi
  int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  int v13; // edi
  int v14; // ecx
  unsigned __int16 **v15; // eax
  unsigned __int16 v16; // ax
  int v17; // esi
  int **v18; // eax
  int v19; // eax
  bool v20; // zf
  _DWORD *v21; // ecx
  int v22; // eax
  int v23; // eax
  int v24; // ecx
  int v26; // [esp+0h] [ebp-48h] BYREF
  unsigned int v27; // [esp+14h] [ebp-34h]
  int *v28; // [esp+1Ch] [ebp-2Ch]
  char v29; // [esp+20h] [ebp-28h]
  struct std::locale::facet *v30; // [esp+24h] [ebp-24h]
  _BYTE v31[4]; // [esp+28h] [ebp-20h] BYREF
  int v32; // [esp+2Ch] [ebp-1Ch] BYREF
  int v33; // [esp+30h] [ebp-18h]
  char v34; // [esp+37h] [ebp-11h]
  int *v35; // [esp+38h] [ebp-10h]
  int v36; // [esp+44h] [ebp-4h]

  v35 = &v26;
  v2 = *(int *)((char *)a1 + *(_DWORD *)(*a1 + 4) + 56);
  v3 = 0;
  v33 = 0;
  v34 = 0;
  v28 = a1;
  if ( v2 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 4))(v2);
  v36 = 0;
  v29 = sub_44D8E0((int)a1);
  v36 = 1;
  if ( v29 )
  {
    v4 = sub_44DB70((int)a1 + *(_DWORD *)(*a1 + 4), *a1, &v32);
    LOBYTE(v36) = 2;
    v5 = sub_44D670((int)v4);
    LOBYTE(v36) = 1;
    v6 = v32;
    v30 = v5;
    if ( v32 )
    {
      std::_Lockit::_Lockit((std::_Lockit *)v31, 0);
      v7 = *(_DWORD *)(v6 + 4);
      if ( v7 && v7 != -1 )
        *(_DWORD *)(v6 + 4) = v7 - 1;
      v8 = -(*(_DWORD *)(v6 + 4) == 0);
      std::_Lockit::~_Lockit((std::_Lockit *)v31);
      v9 = (void (__thiscall ***)(_DWORD, int))(v6 & v8);
      if ( v9 )
        (**v9)(v9, 1);
    }
    sub_403440(0xFFFFFFFF, 0, a2);
    LOBYTE(v36) = 3;
    v10 = *(_DWORD *)(*a1 + 4);
    v11 = *(int *)((char *)a1 + v10 + 36);
    v12 = *(int *)((char *)a1 + v10 + 32);
    if ( __SPAIR64__(v11, v12) <= 0 || (v27 = *(int *)((char *)a1 + v10 + 36), v12 >= 0x7FFFFFFE) )
    {
      v13 = 2147483646;
    }
    else
    {
      v27 = v11;
      v13 = v12;
    }
    v14 = *(int *)((char *)a1 + v10 + 56);
    v15 = *(unsigned __int16 ***)(v14 + 32);
    if ( *v15 && **(int **)(v14 + 48) > 0 )
      v16 = **v15;
    else
      v16 = (*(int (__thiscall **)(int))(*(_DWORD *)v14 + 24))(v14);
    v17 = v16;
    while ( v13 )
    {
      if ( (_WORD)v17 == 0xFFFF )
      {
        v33 |= 1u;
        break;
      }
      if ( (*(unsigned __int8 (__thiscall **)(struct std::locale::facet *, int, int))(*(_DWORD *)v30 + 8))(v30, 72, v17) )
        break;
      sub_444B50((int)a2, v17);
      v18 = *(int ***)((char *)a1 + *(_DWORD *)(*a1 + 4) + 56);
      v34 = 1;
      --v13;
      v17 = (unsigned __int16)sub_44D820(v18);
    }
    v36 = 1;
    v3 = v33;
  }
  v19 = *(_DWORD *)(*a1 + 4);
  v20 = v34 == 0;
  *(int *)((char *)a1 + v19 + 32) = 0;
  *(int *)((char *)a1 + v19 + 36) = 0;
  if ( v20 )
    v3 |= 2u;
  v21 = (int *)((char *)a1 + *(_DWORD *)(*a1 + 4));
  if ( v3 )
  {
    v22 = v3 | v21[3];
    if ( !v21[14] )
      LOBYTE(v22) = v22 | 4;
    v23 = v22 & 0x17;
    v21[3] = v23;
    if ( (v23 & v21[4]) != 0 )
      sub_44DDA0(0);
  }
  v36 = -1;
  v24 = *(int *)((char *)v28 + *(_DWORD *)(*v28 + 4) + 56);
  if ( v24 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v24 + 8))(v24);
  return a1;
}
