int __userpurge sub_42D830@<eax>(_DWORD *a1@<esi>, int a2, int a3)
{
  _DWORD *v4; // eax
  int v5; // edi
  int v6; // ecx
  _DWORD *v7; // edx
  _DWORD *v8; // eax
  int v9; // eax
  int v10; // edx
  _BYTE v11[64]; // [esp+8h] [ebp-60h] BYREF
  int v12; // [esp+48h] [ebp-20h]
  int v13; // [esp+4Ch] [ebp-1Ch]
  int v14; // [esp+50h] [ebp-18h]
  int v15; // [esp+54h] [ebp-14h]

  if ( !a1 )
    return -2147024809;
  v4 = sub_42B3D0();
  v5 = v4[15];
  v6 = 0;
  if ( v5 > 0 )
  {
    v7 = (_DWORD *)v4[14];
    while ( 1 )
    {
      v8 = (_DWORD *)*v7;
      if ( *(_DWORD *)*v7 == a2 )
        break;
      ++v6;
      ++v7;
      if ( v6 >= v5 )
        goto LABEL_11;
    }
    if ( v8[140] > a3 )
    {
      v9 = *(_DWORD *)(v8[139] + 4 * a3);
      if ( v9 )
      {
        *a1 = 640;
        a1[1] = 480;
        a1[2] = 60;
        a1[3] = 1;
        a1[4] = 29;
        a1[6] = 0;
        a1[5] = 0;
        (*(void (__stdcall **)(_DWORD, _BYTE *))(**(_DWORD **)(v9 + 8) + 28))(*(_DWORD *)(v9 + 8), v11);
        v10 = v15 - v13;
        *a1 = v14 - v12;
        a1[1] = v10;
      }
    }
  }
LABEL_11:
  if ( a1[4] == 87 )
    a1[4] = 28;
  return 0;
}
