void __thiscall sub_4401A0(_DWORD **this, void **Src)
{
  _DWORD *v3; // eax
  int v4[4]; // [esp+14h] [ebp-104h] BYREF
  int v5[42]; // [esp+24h] [ebp-F4h] BYREF
  void *v6[4]; // [esp+CCh] [ebp-4Ch] BYREF
  int v7; // [esp+DCh] [ebp-3Ch]
  unsigned int v8; // [esp+E0h] [ebp-38h]
  void *v9[4]; // [esp+E8h] [ebp-30h] BYREF
  int v10; // [esp+F8h] [ebp-20h]
  unsigned int v11; // [esp+FCh] [ebp-1Ch]
  int v12; // [esp+114h] [ebp-4h]

  sub_4442E0(v5, Src);
  v12 = 1;
  v11 = 7;
  v10 = 0;
  LOWORD(v9[0]) = 0;
  sub_44BFE0(v5, v9);
  v3 = sub_4403F0(this, v9);
  if ( v3 )
  {
    sub_440720(v3, v5);
  }
  else
  {
    v8 = 7;
    v7 = 0;
    LOWORD(v6[0]) = 0;
    sub_4032D0(L"Command not found", (int)v6, 0x11u);
    LOBYTE(v12) = 2;
    *(float *)v4 = 1.0;
    *(float *)&v4[1] = flt_4D63B0;
    *(float *)&v4[2] = flt_4D63B0;
    *(float *)&v4[3] = 1.0;
    sub_441E00(v4, (int)this, v6);
    if ( v8 >= 8 )
      operator delete(v6[0]);
    v8 = 7;
    v7 = 0;
    LOWORD(v6[0]) = 0;
  }
  if ( v11 >= 8 )
    operator delete(v9[0]);
  LOWORD(v9[0]) = 0;
  v11 = 7;
  v10 = 0;
  v12 = -1;
  sub_440350((char *)v5);
}
