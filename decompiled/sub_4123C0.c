void __usercall sub_4123C0(int a1@<eax>)
{
  bool v1; // zf
  int v2; // eax
  int v3; // ecx

  v1 = byte_4D6327 == 0;
  *(_DWORD *)(a1 + 260) = 0;
  if ( v1 )
    sub_40D960(dword_4D7EE8);
  v2 = dword_4D7EEC;
  *(_BYTE *)(dword_4D7EEC + 388) = 0;
  *(_DWORD *)(v2 + 404) = dword_4D82D4;
  *(_DWORD *)(v2 + 408) = dword_4D82D8;
  v3 = dword_4D82DC;
  *(float *)(v2 + 416) = 0.78539819;
  *(float *)(v2 + 356) = 0.2;
  byte_4D6327 = 0;
  *(_DWORD *)(v2 + 412) = v3;
  *(float *)(v2 + 380) = 60.0;
  sub_402600((float *)v2);
  sub_450F00();
  flt_4D7EF4 = 0.0;
  sub_407060();
  sub_405710();
  if ( flt_4D526C < 150.0 )
    flt_4D526C = flt_4D52E8;
}
