void __thiscall sub_450CD0(int this, float *a2, float *a3, float *a4, float a5)
{
  int v6; // ecx
  int v7; // eax
  float v8; // edx
  _DWORD **v9; // eax
  _DWORD *v10; // esi
  float v11; // [esp+14h] [ebp-20h]
  float v12; // [esp+14h] [ebp-20h]
  float v13; // [esp+18h] [ebp-1Ch]
  float v14; // [esp+18h] [ebp-1Ch]
  double v15[2]; // [esp+1Ch] [ebp-18h] BYREF
  float v16; // [esp+2Ch] [ebp-8h]
  float v17; // [esp+30h] [ebp-4h]

  if ( dword_4D82B8 < dword_4D82B4 && 0.0 != *(float *)(this + 20) )
  {
    v15[0] = *(float *)(this + 20);
    v11 = v15[0] * v15[0];
    if ( v11 >= sub_450860(a4, a2, (float *)(this + 8), a3, a5) )
    {
      v12 = sub_450970((float *)v15, a4, a2, (float *)(this + 24), a3, a5);
      v13 = *(float *)(this + 36) * *(float *)(this + 36);
      if ( v13 > (double)v12 )
      {
        v14 = sqrt(a5);
        v16 = v14 * *(float *)v15;
        *(float *)v15 = sqrt(v12);
        v6 = dword_4D82B8;
        v17 = *(float *)v15;
        v7 = dword_4D82B0 + 12 * dword_4D82B8;
        v8 = v16;
        *(_DWORD *)v7 = this;
        *(float *)(v7 + 4) = v8;
        *(float *)(v7 + 8) = v17;
        dword_4D82B8 = v6 + 1;
      }
      v9 = *(_DWORD ***)(this + 168);
      v10 = *v9;
      if ( *v9 != v9 )
      {
        do
        {
          sub_450CD0((int)a2, (int)a3, (int)a4, a5);
          v10 = (_DWORD *)*v10;
        }
        while ( v10 != *(_DWORD **)(this + 168) );
      }
    }
  }
}
