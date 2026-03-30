void __stdcall sub_40EEE0(int a1)
{
  _DWORD *v1; // ebx
  int v2; // ebp
  int v3; // esi
  int v4; // esi
  _DWORD *v5; // edi
  float *v6; // eax
  float *v7; // eax
  double v8; // st7
  float *v9; // eax
  float *v10; // eax
  int v11; // esi
  int v12; // esi
  int v13; // eax
  _DWORD *v14; // eax
  int v15; // ecx
  float v16; // [esp+4h] [ebp-38h]
  float v17; // [esp+4h] [ebp-38h]
  int v18; // [esp+18h] [ebp-24h] BYREF
  int v19; // [esp+1Ch] [ebp-20h]
  int v20; // [esp+20h] [ebp-1Ch]
  int v21; // [esp+24h] [ebp-18h] BYREF
  int v22; // [esp+28h] [ebp-14h]
  int v23; // [esp+2Ch] [ebp-10h]
  float v24[3]; // [esp+30h] [ebp-Ch] BYREF

  v1 = (_DWORD *)a1;
  v2 = dword_4D7EE8;
  if ( 150.0 == flt_4D526C )
  {
    v3 = *(_DWORD *)(a1 + 180);
    if ( v3 )
      sub_450C80((_DWORD *)a1, v3);
    (*(void (__thiscall **)(_DWORD *))(*v1 + 8))(v1);
  }
  else if ( !*(_BYTE *)(a1 + 188) )
  {
    v4 = a1;
    v5 = (_DWORD *)sub_413CF0(a1);
    sub_40FCF0(v4);
    a1 = rand();
    *(float *)&v18 = (double)a1 / 32767.0 + (double)a1 / 32767.0 - 1.0;
    a1 = rand();
    *(float *)&v19 = (double)a1 / 32767.0 + (double)a1 / 32767.0 - 1.0;
    a1 = rand();
    *(float *)&v20 = (double)a1 / 32767.0 + (double)a1 / 32767.0 - 1.0;
    a1 = rand();
    *(float *)&v21 = (double)a1 / 32767.0 + (double)a1 / 32767.0 - 1.0;
    a1 = rand();
    *(float *)&v22 = (double)a1 / 32767.0 + (double)a1 / 32767.0 - 1.0;
    a1 = rand();
    *(float *)&v23 = (double)a1 / 32767.0 + (double)a1 / 32767.0 - 1.0;
    if ( sub_40FC70(v4) )
    {
      v18 = dword_4D82D4;
      v19 = dword_4D82D8;
      v20 = dword_4D82DC;
      v21 = dword_4D82D4;
      v22 = dword_4D82D8;
      v23 = dword_4D82DC;
    }
    v16 = flt_4D52D4;
    v6 = sub_401500(v24, (float *)&v18, 0.2);
    v7 = sub_401470((float *)&v18, v6, v16);
    v8 = flt_4D52D4;
    v5[122] = *(_DWORD *)v7;
    v5[123] = *((_DWORD *)v7 + 1);
    v17 = v8;
    v5[124] = *((_DWORD *)v7 + 2);
    v9 = sub_401500(v24, (float *)&v21, flt_4D63C0);
    v10 = sub_401470((float *)&v21, v9, v17);
    v5[125] = *(_DWORD *)v10;
    v5[126] = *((_DWORD *)v10 + 1);
    v5[127] = *((_DWORD *)v10 + 2);
    qmemcpy(v5 + 10, v1 + 26, 0x40u);
    v11 = v1[45];
    if ( v11 )
      sub_450C80(v1, v11);
    v12 = *(_DWORD *)(v2 + 204);
    v13 = *(_DWORD *)(v12 + 4);
    a1 = v1[46];
    v14 = sub_40FD70((char *)v12, v13, &a1);
    v15 = *(_DWORD *)(v2 + 208);
    if ( v15 == 1073741822 )
      std::_Xlength_error("list<T> too long");
    *(_DWORD *)(v2 + 208) = v15 + 1;
    *(_DWORD *)(v12 + 4) = v14;
    *(_DWORD *)v14[1] = v14;
  }
}
