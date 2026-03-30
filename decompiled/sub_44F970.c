void sub_44F970()
{
  _DWORD *EngineInstance; // esi
  int v1; // esi
  int v2; // esi
  float *v3; // eax
  double v4; // st7
  double v5; // st6
  float v6; // edx
  double v7; // st5
  int v8; // eax
  float *v9; // eax
  float v10; // ecx
  float v11; // edx
  float *v12; // eax
  float v13; // ecx
  float v14; // [esp+30h] [ebp-48h] BYREF
  int v15; // [esp+34h] [ebp-44h]
  float v16; // [esp+38h] [ebp-40h]
  float v17; // [esp+3Ch] [ebp-3Ch]
  float v18; // [esp+40h] [ebp-38h]
  float v19; // [esp+44h] [ebp-34h]
  float v20; // [esp+48h] [ebp-30h]
  float v21; // [esp+4Ch] [ebp-2Ch]
  float v22; // [esp+50h] [ebp-28h]
  float v23; // [esp+54h] [ebp-24h]
  float v24; // [esp+58h] [ebp-20h]
  float v25; // [esp+5Ch] [ebp-1Ch]
  float v26; // [esp+60h] [ebp-18h]
  float v27; // [esp+64h] [ebp-14h]
  float v28; // [esp+68h] [ebp-10h]
  float v29; // [esp+6Ch] [ebp-Ch]
  float v30; // [esp+70h] [ebp-8h]
  float v31; // [esp+74h] [ebp-4h]

  if ( !dword_4D7FB8 )
  {
    dword_4D7FC0 = 16;
    dword_4D7FC4 = 18;
    dword_4D7FBC = 5;
    dword_4D7FC8 = 32;
    dword_4D7FCC = 274;
    EngineInstance = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v1 = EngineInstance[1];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( (*(int (__stdcall **)(int, int, int, int, int, int *, _DWORD))(*(_DWORD *)v1 + 104))(
           v1,
           dword_4D7FC4 * dword_4D7FC8,
           8,
           dword_4D7FCC,
           1,
           &dword_4D7FB8,
           0) >= 0
      && (*(int (__stdcall **)(int, _DWORD, _DWORD, float *, _DWORD))(*(_DWORD *)dword_4D7FB8 + 44))(
           dword_4D7FB8,
           0,
           0,
           &v14,
           0) >= 0 )
    {
      v15 = 0;
      v22 = 1.0;
      v2 = 0;
      v25 = 0.0;
      v28 = -1.0;
      v31 = 0.0;
      do
      {
        v17 = (double)v15 * 0.125;
        v16 = (v17 + v17) * 3.141592741012573;
        v18 = cos(v16);
        v19 = v18;
        v18 = sin(v16);
        v3 = (float *)(v2 + LODWORD(v14));
        v4 = v19;
        ++v15;
        v20 = v19;
        v5 = v18;
        *v3 = v19;
        v21 = v5;
        v3[1] = v21;
        v3[2] = 1.0;
        v23 = v4;
        v6 = v14;
        v24 = v5;
        v7 = v17;
        *(float *)(v2 + LODWORD(v14) + 12) = v23;
        v8 = v2 + LODWORD(v6) + 12;
        *(float *)(v8 + 4) = v24;
        *(float *)(v8 + 8) = 0.0;
        *(float *)(v2 + LODWORD(v14) + 24) = v7;
        *(float *)(v2 + LODWORD(v14) + 28) = 0.0;
        v26 = v4;
        v9 = (float *)(v2 + LODWORD(v14) + 32);
        *v9 = v26;
        v27 = v5;
        v9[1] = v27;
        v29 = v4;
        v10 = v29;
        v9[2] = -1.0;
        v30 = v5;
        v11 = v30;
        v12 = (float *)(v2 + LODWORD(v14) + 44);
        *v12 = v10;
        v13 = v31;
        v12[1] = v11;
        v12[2] = v13;
        *(float *)(v2 + LODWORD(v14) + 56) = v7;
        v2 += 64;
        *(float *)(v2 + LODWORD(v14) - 4) = 1.0;
      }
      while ( v2 <= 512 );
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_4D7FB8 + 48))(dword_4D7FB8);
    }
  }
}
