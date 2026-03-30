int __stdcall sub_452220(int a1, int a2, int a3, int a4, int a5)
{
  int result; // eax
  float *v6; // eax
  int v7; // ebx
  double v8; // st4
  double v9; // st7
  int v10; // edi
  int v11; // edx
  double v12; // rtt
  double v13; // st4
  double v14; // st7
  double v15; // rt0
  int v16; // eax
  double v17; // st7
  double v18; // rt1
  double v19; // st4
  HANDLE FirstFileW; // esi
  int v21; // eax
  float v22; // [esp+1Ch] [ebp-69Ch]
  int v23; // [esp+24h] [ebp-694h]
  int v24; // [esp+28h] [ebp-690h]
  int v25; // [esp+34h] [ebp-684h] BYREF
  __int64 v26; // [esp+38h] [ebp-680h]
  float v27[4]; // [esp+40h] [ebp-678h] BYREF
  struct _WIN32_FIND_DATAW FindFileData; // [esp+50h] [ebp-668h] BYREF
  wchar_t v29[256]; // [esp+2A0h] [ebp-418h] BYREF
  wchar_t Buffer[258]; // [esp+4A0h] [ebp-218h] BYREF
  int v31; // [esp+6B4h] [ebp-4h]

  if ( byte_4D59C0 )
    return sub_439920(*(float *)&a4);
  v6 = sub_411EA0(v27, dword_4D7EF0);
  if ( *v6 < 1.0 )
  {
    if ( *v6 > 0.0 )
    {
      v26 = (__int64)(*v6 * 255.0 + 0.5);
      v7 = v26;
    }
    else
    {
      v7 = 0;
    }
  }
  else
  {
    v7 = 255;
  }
  v8 = 1.0;
  v9 = 0.0;
  if ( v6[1] < 1.0 )
  {
    if ( v6[1] > 0.0 )
    {
      v26 = (__int64)(v6[1] * 255.0 + 0.5);
      v10 = v26;
    }
    else
    {
      v10 = 0;
    }
    v8 = 1.0;
    v9 = 0.0;
  }
  else
  {
    v10 = 255;
  }
  if ( v8 > v6[2] )
  {
    v12 = v8;
    v13 = v9;
    v14 = v12;
    if ( v13 < v6[2] )
    {
      v26 = (__int64)(v6[2] * 255.0 + 0.5);
      v11 = v26;
    }
    else
    {
      v11 = 0;
    }
    v15 = v13;
    v8 = v14;
    v9 = v15;
  }
  else
  {
    v11 = 255;
  }
  if ( v8 > v6[3] )
  {
    v18 = v8;
    v19 = v9;
    v17 = v18;
    if ( v19 < v6[3] )
    {
      v26 = (__int64)(255.0 * v6[3] + 0.5);
      v16 = v26;
    }
    else
    {
      v16 = 0;
    }
  }
  else
  {
    v16 = 255;
    v17 = v8;
  }
  v22 = v17;
  (*(void (__stdcall **)(int, _DWORD, _DWORD, int, int, _DWORD, _DWORD))(*(_DWORD *)a1 + 172))(
    a1,
    0,
    0,
    3,
    v11 | ((v10 | ((v7 | (v16 << 8)) << 8)) << 8),
    LODWORD(v22),
    0);
  result = (*(int (__stdcall **)(int))(*(_DWORD *)a1 + 164))(a1);
  if ( result >= 0 )
  {
    sub_413350();
    if ( *(_DWORD *)(dword_4D5C04 + 60) )
      sub_42E630((int)&unk_4D59C8, *(float *)&a4);
    else
      sub_42EB50(v10, a1, (int)&unk_4D59C8, a4, v23, v24);
    sub_4062E0(*(float *)&a4);
    if ( (dword_4D8EC0 & 1) == 0 )
    {
      dword_4D8EC0 |= 1u;
      v31 = 0;
      sub_43FD00();
      atexit(sub_472560);
      v31 = -1;
    }
    sub_4417C0((int)&dword_4D8E20);
    result = (*(int (__stdcall **)(int))(*(_DWORD *)a1 + 168))(a1);
  }
  if ( byte_4D7F9D )
  {
    CreateDirectoryW(L"SnapShots/", 0);
    FirstFileW = FindFirstFileW(L"SnapShots/Bonsai_*.jpg", &FindFileData);
    v21 = 0;
    v25 = 0;
    if ( FirstFileW == (HANDLE)-1 )
      goto LABEL_36;
    do
      swprintf_s(Buffer, 0x100u, L"%s", FindFileData.cFileName);
    while ( FindNextFileW(FirstFileW, &FindFileData) );
    swscanf_s(Buffer, L"Bonsai_%d%*s", &v25);
    v21 = v25 + 1;
    v25 = v21;
    if ( v21 < 10 )
    {
LABEL_36:
      swprintf_s(v29, 0x100u, L"SnapShots/Bonsai_000%d.jpg", v21);
    }
    else if ( v21 >= 100 )
    {
      if ( v21 >= 1000 )
      {
        if ( v21 < 10000 )
          swprintf_s(v29, 0x100u, L"SnapShots/Bonsai_%d.jpg", v21);
      }
      else
      {
        swprintf_s(v29, 0x100u, L"SnapShots/Bonsai_0%d.jpg", v21);
      }
    }
    else
    {
      swprintf_s(v29, 0x100u, L"SnapShots/Bonsai_00%d.jpg", v21);
    }
    result = sub_43FA40((int)v29);
    byte_4D7F9D = 0;
  }
  return result;
}
