int __thiscall sub_4283D0(_DWORD *Val, void *a2, _DWORD *a3)
{
  _DWORD *v3; // esi
  char v5; // al
  bool v6; // dl
  char v7; // bl
  bool v8; // [esp+11h] [ebp-183h]
  bool v9; // [esp+12h] [ebp-182h]
  char v10; // [esp+13h] [ebp-181h]
  _DWORD *v11; // [esp+14h] [ebp-180h]
  int v12; // [esp+18h] [ebp-17Ch]
  unsigned int v13[24]; // [esp+20h] [ebp-174h] BYREF
  int v14; // [esp+80h] [ebp-114h]
  int v15[23]; // [esp+84h] [ebp-110h] BYREF
  _DWORD v16[24]; // [esp+E0h] [ebp-B4h] BYREF
  _BYTE v17[76]; // [esp+140h] [ebp-54h] BYREF

  v3 = Val;
  v11 = Val;
  v12 = 0;
  if ( !a2 )
    return -2147024809;
  if ( !Val )
  {
    memset(v17, 0, 0x44u);
    v11 = v17;
    v3 = v17;
  }
  v10 = sub_41FD50();
  v5 = sub_41FE70();
  if ( !v10 && !v5 )
  {
    v10 = 1;
    v5 = 1;
  }
  v8 = 0;
  v9 = 0;
  if ( *v3 == 1 && a3 )
  {
    v8 = *a3 == 1;
    v9 = *a3 == 0;
  }
  v6 = 0;
  if ( *v3 && a3 )
    v6 = *a3 == 0;
  v7 = 0;
  qmemcpy(v16, a3, sizeof(v16));
  if ( v5 && !v6 && !v9 )
  {
    if ( sub_41BA60() )
    {
      sub_42B3D0();
      memset(v13, 0, 0x5Cu);
      if ( *a3 )
        qmemcpy(v13, a3 + 1, 0x5Cu);
      else
        sub_4386C0(v13, a3 + 1);
      v14 = 1;
      sub_42C7D0(v15, (int)v13, v11);
      v16[0] = 1;
      v12 = sub_42C6B0(&v16[1], v13, v11, v15);
      if ( v12 >= 0 )
        v7 = 1;
    }
    else
    {
      v12 = v8 - 2147219199;
    }
  }
  if ( v10 )
  {
    if ( v7 )
      goto LABEL_31;
    if ( !v8 )
    {
      sub_428650();
      memset(v13, 0, 0x48u);
      if ( *a3 == 1 )
        sub_4385D0(a3 + 1, v13);
      else
        qmemcpy(v13, a3 + 1, 0x48u);
      v14 = 0;
      sub_429DC0(v15, v13, v11);
      v16[0] = 0;
      v12 = sub_429BF0((int)v13, v11, &v16[1], v15);
      if ( v12 >= 0 )
        goto LABEL_31;
    }
  }
  else if ( v7 )
  {
LABEL_31:
    qmemcpy(a2, v16, 0x60u);
    return 0;
  }
  return v12;
}
