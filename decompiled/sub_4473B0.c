_DWORD *__cdecl sub_4473B0(int a1, _DWORD *a2, int a3, __int16 a4, char *Buf, size_t MaxCount, int a7, _DWORD *a8)
{
  int v8; // ecx
  char *v9; // ebp
  size_t v10; // ebx
  _DWORD *v11; // eax
  int v12; // edi
  int v13; // eax
  int v14; // esi
  void (__thiscall ***v15)(_DWORD, int); // esi
  char v16; // al
  char v17; // al
  void **v18; // eax
  void **v19; // eax
  void **v20; // eax
  size_t v21; // esi
  int v22; // edi
  unsigned int v23; // esi
  int v24; // esi
  int v25; // eax
  int *v26; // eax
  int *v27; // eax
  __int16 v28; // ax
  int *v29; // eax
  int v30; // ecx
  _DWORD *v32; // [esp-1Ch] [ebp-78h]
  int v33; // [esp+14h] [ebp-48h] BYREF
  void **v34; // [esp+18h] [ebp-44h]
  int v35; // [esp+1Ch] [ebp-40h]
  int v36[2]; // [esp+20h] [ebp-3Ch] BYREF
  struct std::locale::facet *v37; // [esp+28h] [ebp-34h]
  int v38; // [esp+2Ch] [ebp-30h] BYREF
  void *v39[5]; // [esp+30h] [ebp-2Ch] BYREF
  unsigned int v40; // [esp+44h] [ebp-18h]
  int v41; // [esp+58h] [ebp-4h]

  v9 = Buf;
  v10 = MaxCount;
  v35 = a1;
  v36[0] = a3;
  v11 = sub_44DB70(a3, v8, &v38);
  v41 = 0;
  v37 = sub_44B520((int)v11);
  v41 = -1;
  if ( v38 )
  {
    v12 = v38;
    std::_Lockit::_Lockit((std::_Lockit *)&v33, 0);
    v13 = *(_DWORD *)(v12 + 4);
    if ( v13 && v13 != -1 )
      *(_DWORD *)(v12 + 4) = v13 - 1;
    v14 = -(*(_DWORD *)(v12 + 4) == 0);
    std::_Lockit::~_Lockit((std::_Lockit *)&v33);
    v15 = (void (__thiscall ***)(_DWORD, int))(v12 & v14);
    if ( v15 )
      (**v15)(v15, 1);
  }
  sub_44A290((int)v37, (int)v39);
  v41 = 1;
  v16 = *Buf;
  if ( *Buf == 43 || v16 == 45 )
  {
    v33 = 1;
  }
  else if ( v16 == 48 && ((v17 = Buf[1], v17 == 120) || v17 == 88) )
  {
    v33 = 2;
  }
  else
  {
    v33 = 0;
  }
  v18 = (void **)v39[0];
  if ( v40 < 0x10 )
    v18 = v39;
  if ( *(_BYTE *)v18 != 127 )
  {
    v19 = (void **)v39[0];
    if ( v40 < 0x10 )
      v19 = v39;
    if ( *(char *)v19 > 0 )
    {
      v34 = v40 < 0x10 ? v39 : (void **)v39[0];
      LOBYTE(v20) = *(_BYTE *)v34;
      v21 = MaxCount;
      if ( *(_BYTE *)v34 != 127 )
      {
        do
        {
          if ( (char)v20 <= 0 )
            break;
          v20 = (void **)(char)v20;
          if ( (char)v20 >= v21 - v33 )
            break;
          v21 -= (unsigned int)v20;
          memmove_s(&Buf[v21 + 1], v10 - v21 + 1, &Buf[v21], v10 - v21 + 1);
          v20 = v34;
          Buf[v21] = 0;
          ++v10;
          if ( *((char *)v20 + 1) > 0 )
          {
            v20 = (void **)((char *)v20 + 1);
            v34 = v20;
          }
          LOBYTE(v20) = *(_BYTE *)v20;
        }
        while ( (_BYTE)v20 != 127 );
      }
    }
  }
  v22 = v36[0];
  v23 = *(_DWORD *)(v36[0] + 32);
  if ( *(__int64 *)(v36[0] + 32) <= 0 || v23 <= v10 )
    v24 = 0;
  else
    v24 = v23 - v10;
  v25 = *(_DWORD *)(v36[0] + 20) & 0x1C0;
  if ( v25 != 64 )
  {
    if ( v25 == 256 )
    {
      v27 = sub_448FF0(Buf, v35, v36, a7, a8, v33);
      v9 = &Buf[v33];
      v10 -= v33;
      v26 = sub_447710(v24, a4, v36, *v27, (_DWORD *)v27[1]);
    }
    else
    {
      v26 = sub_447710(v24, a4, v36, a7, a8);
    }
    a7 = *v26;
    a8 = (_DWORD *)v26[1];
    v24 = 0;
  }
  v28 = (*(int (__thiscall **)(struct std::locale::facet *))(*(_DWORD *)v37 + 8))(v37);
  v29 = sub_4490D0(v28, v35, v36, v9, v10, a7, a8);
  v30 = *v29;
  v32 = (_DWORD *)v29[1];
  *(_DWORD *)(v22 + 32) = 0;
  *(_DWORD *)(v22 + 36) = 0;
  sub_447710(v24, a4, a2, v30, v32);
  if ( v40 >= 0x10 )
    operator delete(v39[0]);
  return a2;
}
