void __usercall sub_402880(int a1@<esi>)
{
  float *v1; // eax
  int v2; // ecx
  float *v3; // eax
  float *v4; // eax
  float *v5; // eax
  float *v6; // eax
  float *v7; // eax
  float *v8; // eax
  float v9; // [esp+10h] [ebp-8Ch]
  float v10; // [esp+10h] [ebp-8Ch]
  float v11; // [esp+1Ch] [ebp-80h]
  float v12[3]; // [esp+20h] [ebp-7Ch] BYREF
  float v13[3]; // [esp+2Ch] [ebp-70h] BYREF
  float v14[3]; // [esp+38h] [ebp-64h] BYREF
  float v15[3]; // [esp+44h] [ebp-58h] BYREF
  float v16[17]; // [esp+50h] [ebp-4Ch] BYREF

  v1 = sub_4013F0(v14, (float *)(a1 + 392), (float *)(a1 + 212));
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))D3DXMatrixRotationYawPitchRoll)(v16, *v1, v1[1], v1[2]);
  if ( 0.0 != flt_4D8CA8 )
  {
    v11 = flt_4D8CA8 * -1.0;
    *(float *)(a1 + 416) = v11 * 0.03333333507180214 + *(float *)(a1 + 416);
    if ( *(float *)(a1 + 416) >= 0.05235987901687622 )
    {
      if ( *(float *)(a1 + 416) > 1.0471976 )
        *(float *)(a1 + 416) = 1.0471976;
    }
    else
    {
      *(float *)(a1 + 416) = 0.052359879;
    }
    if ( 1.0471976 == *(float *)(a1 + 416) )
    {
      *(_DWORD *)(a1 + 404) = dword_4D82D4;
      *(_DWORD *)(a1 + 408) = dword_4D82D8;
      v2 = dword_4D82DC;
      *(float *)(a1 + 416) = 0.78539819;
      *(_DWORD *)(a1 + 412) = v2;
      *(_BYTE *)(a1 + 388) = 0;
      return;
    }
    flt_4D8CA8 = 0.0;
  }
  if ( (_BYTE)word_4D8CA3 )
  {
    v9 = flt_4D8CC0;
    v3 = sub_4015B0(v14, v16);
    v4 = sub_401470(v12, v3, v9);
    v5 = sub_401470(v13, v4, 0.02);
    *(float *)(a1 + 364) = *v5 + *(float *)(a1 + 364);
    *(float *)(a1 + 368) = v5[1] + *(float *)(a1 + 368);
    *(float *)(a1 + 372) = v5[2] + *(float *)(a1 + 372);
    v10 = -flt_4D8CBC;
    v6 = sub_401590(v13, v16);
    v7 = sub_401470(v12, v6, v10);
    v8 = sub_401470(v15, v7, 0.02);
    *(float *)(a1 + 364) = *(float *)(a1 + 364) + *v8;
    *(float *)(a1 + 368) = v8[1] + *(float *)(a1 + 368);
    *(float *)(a1 + 372) = v8[2] + *(float *)(a1 + 372);
  }
}
