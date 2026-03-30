int sub_411B60()
{
  _DWORD *EngineInstance; // esi
  int v1; // esi
  int result; // eax
  int i; // edi
  float *v4; // eax
  double v5; // st6
  double v6; // st6
  int v7; // esi
  double v8; // st6
  double v9; // st5
  double v10; // st4
  double v11; // st3
  int v12; // edx
  double v13; // st3
  int v14; // ecx
  double v15; // st7
  int v16; // eax
  double v17; // rt0
  double v18; // st4
  double v19; // st6
  int v20; // [esp+34h] [ebp-2Ch] BYREF
  __int64 v21; // [esp+38h] [ebp-28h]
  float v22; // [esp+44h] [ebp-1Ch] BYREF
  float v23; // [esp+48h] [ebp-18h]
  float v24; // [esp+4Ch] [ebp-14h]
  float v25; // [esp+50h] [ebp-10h]
  float v26; // [esp+54h] [ebp-Ch]
  float v27; // [esp+58h] [ebp-8h]
  float v28; // [esp+5Ch] [ebp-4h]

  dword_4D7ED4 = 5000;
  dword_4D7ED8 = 5000;
  dword_4D7ED0 = 1;
  dword_4D7EDC = 16;
  dword_4D7EE0 = 66;
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = EngineInstance[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  result = (*(int (__stdcall **)(int, int, int, int, int, int *, _DWORD))(*(_DWORD *)v1 + 104))(
             v1,
             dword_4D7ED8 * dword_4D7EDC,
             8,
             dword_4D7EE0,
             1,
             &dword_4D7ECC,
             0);
  if ( result >= 0 )
  {
    result = (*(int (__stdcall **)(int, _DWORD, _DWORD, int *, _DWORD))(*(_DWORD *)dword_4D7ECC + 44))(
               dword_4D7ECC,
               0,
               0,
               &v20,
               0);
    if ( result >= 0 )
    {
      for ( i = 0; i < 80000; i += 16 )
      {
        sub_40D610(&v22);
        *(float *)&v21 = (double)rand() / 32767.0 + 0.0;
        v25 = (double)rand() / 32767.0 + 0.0;
        v26 = (double)rand() / 32767.0 + 0.0;
        v27 = (double)rand() / 32767.0 + 0.0;
        *(float *)&v21 = pow(*(float *)&v21, 3.0);
        v28 = *(float *)&v21;
        v4 = (float *)(i + v20);
        v22 = v22 * 8000.0;
        v5 = v23;
        *v4 = v22;
        v23 = v5 * 8000.0;
        v4[1] = v23;
        v24 = 8000.0 * v24;
        v4[2] = v24;
        v6 = v25;
        if ( v25 < 1.0 )
        {
          if ( v6 > 0.0 )
          {
            v21 = (__int64)(v6 * 255.0 + 0.5);
            v7 = v21;
            v9 = 255.0;
            v10 = 0.5;
            v8 = 0.0;
          }
          else
          {
            v8 = 0.0;
            v7 = 0;
            v9 = 255.0;
            v10 = 0.5;
          }
        }
        else
        {
          v7 = 255;
          v8 = 0.0;
          v9 = 255.0;
          v10 = 0.5;
        }
        v11 = v26;
        if ( v26 < 1.0 )
        {
          if ( v11 > v8 )
          {
            v21 = (__int64)(v11 * v9 + v10);
            v12 = v21;
          }
          else
          {
            v12 = 0;
          }
        }
        else
        {
          v12 = 255;
        }
        v13 = v27;
        if ( v27 < 1.0 )
        {
          if ( v13 > v8 )
          {
            v21 = (__int64)(v13 * v9 + v10);
            v14 = v21;
          }
          else
          {
            v14 = 0;
          }
        }
        else
        {
          v14 = 255;
        }
        v15 = v28;
        if ( v28 < 1.0 )
        {
          v17 = v10;
          v18 = v8;
          v19 = v17;
          if ( v18 < v15 )
          {
            v21 = (__int64)(v15 * v9 + v19);
            v16 = v21;
          }
          else
          {
            v16 = 0;
          }
        }
        else
        {
          v16 = 255;
        }
        *(_DWORD *)(i + v20 + 12) = v14 | ((v12 | ((v7 | (v16 << 8)) << 8)) << 8);
      }
      return (*(int (__stdcall **)(int))(*(_DWORD *)dword_4D7ECC + 48))(dword_4D7ECC);
    }
  }
  return result;
}
