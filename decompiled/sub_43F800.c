int __thiscall sub_43F800(int this)
{
  int result; // eax
  int v3; // eax
  int v4; // [esp+44h] [ebp-1E0h]
  float v5; // [esp+44h] [ebp-1E0h]
  float v6; // [esp+48h] [ebp-1DCh] BYREF
  float v7; // [esp+4Ch] [ebp-1D8h]
  float v8; // [esp+50h] [ebp-1D4h] BYREF
  float v9[6]; // [esp+54h] [ebp-1D0h] BYREF
  _BYTE v10[48]; // [esp+6Ch] [ebp-1B8h] BYREF
  _BYTE v11[24]; // [esp+9Ch] [ebp-188h] BYREF
  int v12; // [esp+B4h] [ebp-170h]
  int v13; // [esp+B8h] [ebp-16Ch]
  int v14; // [esp+BCh] [ebp-168h]
  int v15; // [esp+C0h] [ebp-164h]

  if ( *(_DWORD *)(this + 4) )
    result = (*(int (__stdcall **)(_DWORD, int))(**(_DWORD **)(this + 4) + 32))(*(_DWORD *)(this + 4), 48);
  if ( *(_DWORD *)(this + 12) )
  {
    v3 = *(_DWORD *)(this + 12);
    LODWORD(v8) = 1;
    v6 = 0.0;
    (*(void (__stdcall **)(int, float *))(*(_DWORD *)v3 + 48))(v3, &v6);
    result = LODWORD(v6);
    if ( v6 != 0.0 )
    {
      (*(void (__stdcall **)(float, float *, _BYTE *, int, float, float))(*(_DWORD *)LODWORD(v6) + 244))(
        COERCE_FLOAT(LODWORD(v6)),
        &v8,
        v11,
        v4,
        COERCE_FLOAT(LODWORD(v6)),
        COERCE_FLOAT(LODWORD(v7)));
      v8 = (float)(unsigned int)(v13 + v15);
      LODWORD(v9[4]) = v12 + v14;
      v7 = (float)v13;
      v6 = (float)(unsigned int)(v12 + v14);
      v5 = (float)v12;
      D3DXMatrixOrthoOffCenterLH(v10, LODWORD(v5), LODWORD(v6), LODWORD(v7), LODWORD(v8), LODWORD(flt_4CA5E8), 10.0);
      (*(void (__stdcall **)(_DWORD, float *))(**(_DWORD **)(this + 12) + 44))(*(_DWORD *)(this + 12), v9);
      (*(void (__stdcall **)(_DWORD, int))(**(_DWORD **)(this + 12) + 12))(*(_DWORD *)(this + 12), 1);
      result = LODWORD(v6);
      if ( v6 != 0.0 )
        return (*(int (__stdcall **)(float))(*(_DWORD *)LODWORD(v6) + 8))(COERCE_FLOAT(LODWORD(v6)));
    }
  }
  return result;
}
