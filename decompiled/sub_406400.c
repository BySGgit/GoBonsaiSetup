int sub_406400()
{
  int v0; // esi
  int v1; // eax
  double v2; // st7
  double v3; // st7
  int v4; // eax
  float *EngineInstance; // esi
  int result; // eax
  float v7; // [esp+1Ch] [ebp-254h]
  float v8; // [esp+1Ch] [ebp-254h]
  float v9; // [esp+1Ch] [ebp-254h]
  float v10[4]; // [esp+30h] [ebp-240h] BYREF
  float v11; // [esp+40h] [ebp-230h]
  float v12; // [esp+44h] [ebp-22Ch]
  float v13; // [esp+48h] [ebp-228h]
  float v14; // [esp+4Ch] [ebp-224h]
  int v15; // [esp+50h] [ebp-220h]
  int v16; // [esp+54h] [ebp-21Ch]
  int v17; // [esp+58h] [ebp-218h]
  int v18; // [esp+5Ch] [ebp-214h]
  wchar_t Buffer[256]; // [esp+60h] [ebp-210h] BYREF
  int v20; // [esp+26Ch] [ebp-4h]

  LODWORD(v10[0]) = dword_4D82C0;
  LODWORD(v10[1]) = dword_4D82C4;
  v11 = 1.0;
  v10[2] = 0.0;
  v10[3] = 0.0;
  v12 = 1.0;
  v13 = 1.0;
  v14 = 1.0;
  v15 = 0;
  v16 = 0;
  v17 = 22;
  v18 = 0;
  v20 = 0;
  sub_43F800((int)v10);
  v0 = dword_4D7EE8;
  v15 = dword_4CA628 - 220;
  v11 = 1.0;
  v12 = 1.0;
  v13 = 1.0;
  v14 = 1.0;
  v16 = 10;
  v7 = *(float *)(dword_4D7EE8 + 216) / 365.0;
  v1 = sub_406360(v7);
  v8 = *(float *)(v0 + 216) / 365.0;
  swprintf_s(Buffer, 0x100u, L"age:  %.2f y (%s)", v8, v1);
  sub_43F5C0(v10, (int)Buffer, 0);
  v2 = sub_4153D0(*(_DWORD *)(dword_4D7EE8 + 240));
  swprintf_s(Buffer, 0x100u, L"height:  %.1f cm", v2);
  sub_43F5C0(v10, (int)Buffer, 0);
  v3 = sub_403BA0(dword_4D7EE8);
  swprintf_s(Buffer, 0x100u, L"diameter:  %.1f cm", v3);
  sub_43F5C0(v10, (int)Buffer, 0);
  swprintf_s(Buffer, 0x100u, L"stored energy:  %.0f", *(float *)(dword_4D7EE8 + 196) * 0.04800000041723251);
  sub_43F5C0(v10, (int)Buffer, 0);
  v4 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(dword_4D7EE8 + 240) + 60))(*(_DWORD *)(dword_4D7EE8 + 240));
  swprintf_s(Buffer, 0x100u, L"leaves:  %d", v4);
  sub_43F5C0(v10, (int)Buffer, 0);
  swprintf_s(Buffer, 0x100u, L"buds:  %d", *(_DWORD *)(dword_4D7EE8 + 200));
  sub_43F5C0(v10, (int)Buffer, 0);
  swprintf_s(Buffer, 0x100u, L"objects:  %d", dword_4D8C14);
  sub_43F5C0(v10, (int)Buffer, 0);
  swprintf_s(Buffer, 0x100u, L"collisions:  %d", dword_4D82AC);
  sub_43F5C0(v10, (int)Buffer, 0);
  EngineInstance = (float *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v9 = EngineInstance[173];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  swprintf_s(Buffer, 0x100u, L"fps: %.0f", v9);
  sub_43F5C0(v10, (int)Buffer, 0);
  sub_43F930((int)v10);
  v20 = -1;
  result = v18;
  if ( v18 )
    return (*(int (__stdcall **)(int))(*(_DWORD *)v18 + 8))(v18);
  return result;
}
