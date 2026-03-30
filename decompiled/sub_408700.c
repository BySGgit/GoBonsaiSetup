int __userpurge sub_408700@<eax>(int a1@<edi>, int a2)
{
  bool v2; // zf
  int v3; // ebp
  _DWORD *v4; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // eax
  int v11; // edx
  int v12; // ecx
  int v14; // [esp-8h] [ebp-28h]
  int v15; // [esp+10h] [ebp-10h] BYREF
  int v16; // [esp+1Ch] [ebp-4h]

  sub_401830(a2);
  v16 = 0;
  v2 = (dword_4D8CC8 & 1) == 0;
  *(_DWORD *)a2 = &BonsaiPot::`vftable';
  *(_DWORD *)(a2 + 276) = a1;
  if ( v2 )
  {
    dword_4D8CC8 |= 1u;
    sub_40A200();
    LOBYTE(v16) = 0;
  }
  *(_DWORD *)(a2 + 4) = 1;
  if ( a1 )
  {
    v3 = *(_DWORD *)(a1 + 168);
    v14 = *(_DWORD *)(v3 + 4);
    v15 = a2;
    v4 = sub_40FD70((char *)v3, v14, &v15);
    v5 = *(_DWORD *)(a1 + 172);
    if ( v5 == 1073741822 )
      std::_Xlength_error("list<T> too long");
    *(_DWORD *)(a1 + 172) = v5 + 1;
    *(_DWORD *)(v3 + 4) = v4;
    *(_DWORD *)v4[1] = v4;
    *(_DWORD *)(a2 + 180) = a1;
  }
  sub_408880((float *)a2);
  v6 = *(_DWORD *)(a2 + 224);
  *(float *)(a2 + 196) = *(float *)(a2 + 204);
  v7 = *(_DWORD *)(a2 + 228);
  v8 = *(_DWORD *)(a2 + 232);
  *(float *)(a2 + 200) = *(float *)(a2 + 208);
  *(_DWORD *)(a2 + 212) = v6;
  v9 = *(_DWORD *)(a2 + 252);
  *(_DWORD *)(a2 + 216) = v7;
  v10 = *(_DWORD *)(a2 + 256);
  *(_DWORD *)(a2 + 236) = v9;
  v11 = *(_DWORD *)(a2 + 264);
  *(_DWORD *)(a2 + 220) = v8;
  v12 = *(_DWORD *)(a2 + 260);
  *(_DWORD *)(a2 + 240) = v10;
  *(_DWORD *)(a2 + 244) = v12;
  *(_DWORD *)(a2 + 248) = v11;
  return a2;
}
