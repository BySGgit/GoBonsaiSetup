int __stdcall sub_40D6F0(int a1)
{
  _DWORD *v1; // eax
  bool v2; // zf
  char *v3; // eax
  int v4; // eax
  char *v6[2]; // [esp+18h] [ebp-20h] BYREF
  _DWORD pExceptionObject[3]; // [esp+20h] [ebp-18h] BYREF
  int v8; // [esp+34h] [ebp-4h]

  sub_401830(a1);
  v8 = 0;
  *(_DWORD *)a1 = &off_4B78A0;
  *(_DWORD *)(a1 + 208) = 0;
  v1 = operator new(0xCu);
  if ( !v1 )
  {
    v6[0] = 0;
    std::exception::exception((std::exception *)pExceptionObject, (const char *const *)v6);
    pExceptionObject[0] = &std::bad_alloc::`vftable';
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  *(_DWORD *)(a1 + 204) = v1;
  *v1 = v1;
  *(_DWORD *)(*(_DWORD *)(a1 + 204) + 4) = *(_DWORD *)(a1 + 204);
  LOBYTE(v8) = 1;
  v2 = (dword_4D8CE8 & 1) == 0;
  *(_DWORD *)(a1 + 240) = 0;
  if ( v2 )
  {
    dword_4D8CE8 |= 1u;
    sub_40F8F0();
    LOBYTE(v8) = 1;
  }
  *(_DWORD *)(a1 + 4) = 4;
  v3 = (char *)operator new(0x120u);
  v6[1] = v3;
  LOBYTE(v8) = 3;
  if ( v3 )
    v4 = sub_408700(a1, (int)v3);
  else
    v4 = 0;
  LOBYTE(v8) = 1;
  *(_DWORD *)(a1 + 236) = v4;
  sub_40D960(a1);
  *(_DWORD *)(a1 + 224) = dword_4D82D4;
  *(_DWORD *)(a1 + 228) = dword_4D82D8;
  *(_DWORD *)(a1 + 232) = dword_4D82DC;
  qmemcpy((void *)(a1 + 40), &unk_4D8BA8, 0x40u);
  *(_BYTE *)(a1 + 220) = 0;
  return a1;
}
