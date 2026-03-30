_DWORD *__thiscall sub_444FF0(
        void *this,
        _DWORD *a2,
        int a3,
        _DWORD *a4,
        __int64 *a5,
        unsigned __int16 a6,
        unsigned __int8 a7)
{
  bool v7; // zf
  _DWORD *v9; // eax
  struct std::locale::facet *v10; // eax
  int v11; // edi
  int v12; // eax
  int v13; // esi
  void (__thiscall ***v14)(_DWORD, int); // esi
  _DWORD *v15; // eax
  _DWORD *v16; // eax
  unsigned int v17; // esi
  int v18; // ecx
  int v19; // esi
  int *v20; // eax
  unsigned __int16 *v21; // eax
  int *v22; // eax
  int v23; // ecx
  _DWORD *v24; // ebx
  _DWORD *v25; // [esp-14h] [ebp-90h]
  int v26; // [esp+18h] [ebp-64h] BYREF
  _DWORD *v27; // [esp+1Ch] [ebp-60h]
  struct std::locale::facet *v28; // [esp+20h] [ebp-5Ch] BYREF
  void *v29[2]; // [esp+28h] [ebp-54h] BYREF
  void *v30[4]; // [esp+30h] [ebp-4Ch] BYREF
  unsigned int v31; // [esp+40h] [ebp-3Ch]
  unsigned int v32; // [esp+44h] [ebp-38h]
  void *v33[5]; // [esp+4Ch] [ebp-30h] BYREF
  unsigned int v34; // [esp+60h] [ebp-1Ch]
  int v35; // [esp+78h] [ebp-4h]

  v7 = (*((_DWORD *)a5 + 5) & 0x4000) == 0;
  v27 = a2;
  if ( v7 )
  {
    (*(void (__thiscall **)(void *, _DWORD *, int, _DWORD *, __int64 *, _DWORD, _DWORD))(*(_DWORD *)this + 28))(
      this,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7);
    return a2;
  }
  v9 = sub_44DB70((int)a5, (int)this, &v26);
  v35 = 0;
  v10 = sub_44B520((int)v9);
  v35 = -1;
  v11 = v26;
  v28 = v10;
  if ( v26 )
  {
    std::_Lockit::_Lockit((std::_Lockit *)v29, 0);
    v12 = *(_DWORD *)(v11 + 4);
    if ( v12 && v12 != -1 )
      *(_DWORD *)(v11 + 4) = v12 - 1;
    v13 = -(*(_DWORD *)(v11 + 4) == 0);
    std::_Lockit::~_Lockit((std::_Lockit *)v29);
    v14 = (void (__thiscall ***)(_DWORD, int))(v11 & v13);
    if ( v14 )
      (**v14)(v14, 1);
  }
  v32 = 7;
  v31 = 0;
  LOWORD(v30[0]) = 0;
  v35 = 1;
  if ( a7 )
  {
    v15 = (_DWORD *)sub_448C20((int)v28, (int)v33);
    LOBYTE(v35) = 2;
    sub_444AE0(v15, (int)v30);
    LOBYTE(v35) = 1;
    if ( v34 < 8 )
      goto LABEL_14;
  }
  else
  {
    v16 = (_DWORD *)sub_448C00((int)v28, (int)v33);
    LOBYTE(v35) = 3;
    sub_444AE0(v16, (int)v30);
    LOBYTE(v35) = 1;
    if ( v34 < 8 )
      goto LABEL_14;
  }
  operator delete(v33[0]);
LABEL_14:
  v17 = *((_DWORD *)a5 + 8);
  v18 = v31;
  if ( a5[4] <= 0 || v17 <= v31 )
    v19 = 0;
  else
    v19 = v17 - v31;
  if ( (*((_DWORD *)a5 + 5) & 0x1C0) != 0x40 )
  {
    v20 = sub_447710(v19, a6, v29, a3, a4);
    a3 = *v20;
    v18 = v31;
    a4 = (_DWORD *)v20[1];
    v19 = 0;
  }
  v21 = (unsigned __int16 *)v30[0];
  if ( v32 < 8 )
    v21 = (unsigned __int16 *)v30;
  v22 = sub_4476A0(v21, &v28, a3, a4, v18);
  v23 = *v22;
  v25 = (_DWORD *)v22[1];
  *((_DWORD *)a5 + 8) = 0;
  *((_DWORD *)a5 + 9) = 0;
  v24 = v27;
  sub_447710(v19, a6, v27, v23, v25);
  if ( v32 >= 8 )
    operator delete(v30[0]);
  return v24;
}
