int __stdcall sub_413F50(int a1, int a2, const void *a3, int a4)
{
  float *v4; // ebx
  float v5; // edx
  float v6; // edx
  int v7; // edi
  _DWORD *v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // edx
  int v12; // eax
  double v13; // st7
  int v15; // [esp+14h] [ebp-2Ch]

  v4 = (float *)a4;
  sub_401830(a1);
  *(_DWORD *)a1 = &TreeSection::`vftable';
  *(float *)(a1 + 196) = flt_4D538C;
  *(float *)(a1 + 200) = flt_4D5390;
  v5 = flt_4D5394;
  *(float *)(a1 + 208) = 0.0;
  *(float *)(a1 + 212) = 0.0;
  *(float *)(a1 + 204) = v5;
  *(float *)(a1 + 216) = flt_4D538C;
  *(float *)(a1 + 220) = flt_4D5390;
  v6 = flt_4D5394;
  *(float *)(a1 + 228) = 0.0;
  *(float *)(a1 + 232) = 0.0;
  *(float *)(a1 + 224) = v6;
  *(_BYTE *)(a1 + 236) = 0;
  qmemcpy((void *)(a1 + 240), a3, 0x40u);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))D3DXQuaternionRotationYawPitchRoll)(a1 + 304, *v4, v4[1], v4[2]);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))D3DXQuaternionRotationYawPitchRoll)(a1 + 320, *v4, v4[1], v4[2]);
  *(_DWORD *)(a1 + 336) = dword_4D53A4;
  *(_DWORD *)(a1 + 340) = dword_4D53A8;
  *(_DWORD *)(a1 + 344) = dword_4D53AC;
  *(_DWORD *)(a1 + 348) = dword_4D53B0;
  qmemcpy((void *)(a1 + 352), &unk_4D8BA8, 0x40u);
  *(float *)(a1 + 420) = 0.0;
  *(float *)(a1 + 424) = 0.0;
  *(float *)(a1 + 428) = 0.0;
  *(float *)(a1 + 432) = 0.0;
  *(float *)(a1 + 436) = 0.0;
  *(float *)(a1 + 440) = 0.0;
  *(float *)(a1 + 444) = 0.0;
  *(float *)(a1 + 448) = 0.0;
  *(float *)(a1 + 456) = 1.0;
  *(float *)(a1 + 460) = 0.0;
  *(_DWORD *)(a1 + 416) = 0;
  *(float *)(a1 + 464) = 0.0;
  *(_DWORD *)(a1 + 468) = dword_4D82D4;
  *(_DWORD *)(a1 + 472) = dword_4D82D8;
  *(_DWORD *)(a1 + 476) = dword_4D82DC;
  *(_DWORD *)(a1 + 480) = 0;
  *(_DWORD *)(a1 + 484) = 0;
  if ( (dword_4D7CF8 & 1) == 0 )
  {
    dword_4D7CF8 |= 1u;
    sub_4079C0();
  }
  *(_DWORD *)(a1 + 4) = 5;
  sub_450BD0((char *)a1);
  if ( a2 )
  {
    v7 = *(_DWORD *)(a2 + 168);
    v15 = *(_DWORD *)(v7 + 4);
    a4 = a1;
    v8 = sub_40FD70((char *)v7, v15, &a4);
    v9 = *(_DWORD *)(a2 + 172);
    if ( 1073741822 == v9 )
      std::_Xlength_error("list<T> too long");
    *(_DWORD *)(a2 + 172) = v9 + 1;
    *(_DWORD *)(v7 + 4) = v8;
    *(_DWORD *)v8[1] = v8;
    *(_DWORD *)(a1 + 180) = a2;
    if ( (dword_4D7CF8 & 1) == 0 )
    {
      dword_4D7CF8 |= 1u;
      sub_4079C0();
    }
    if ( byte_4D8225[11 * *(_DWORD *)(a2 + 4)] )
    {
      *(_DWORD *)(a1 + 416) = *(_DWORD *)(a2 + 416);
      *(_DWORD *)(a1 + 196) = *(_DWORD *)(a2 + 196);
      *(_DWORD *)(a1 + 200) = *(_DWORD *)(a2 + 200);
      v10 = *(_DWORD *)(a2 + 204);
      *(_DWORD *)(a1 + 204) = v10;
      v11 = *(_DWORD *)(a1 + 196);
      *(float *)(a1 + 208) = *(float *)(a2 + 208);
      v12 = *(_DWORD *)(a1 + 200);
      *(float *)(a1 + 212) = *(float *)(a2 + 212);
      *(_DWORD *)(a1 + 216) = v11;
      v13 = *(float *)(a1 + 208);
      *(_DWORD *)(a1 + 220) = v12;
      *(float *)(a1 + 228) = v13;
      *(_DWORD *)(a1 + 224) = v10;
      *(float *)(a1 + 232) = *(float *)(a1 + 212);
    }
  }
  return a1;
}
