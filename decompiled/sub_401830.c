int __stdcall sub_401830(int a1)
{
  int v1; // edx
  int v2; // edx
  _DWORD *v3; // eax
  int v4; // eax
  bool v5; // zf
  int v6; // eax
  int v7; // eax
  int v8; // edi
  _DWORD *v9; // eax
  char *v11; // [esp-8h] [ebp-48h]
  int v12; // [esp-4h] [ebp-44h]
  char *v13; // [esp+18h] [ebp-28h] BYREF
  int v14[2]; // [esp+1Ch] [ebp-24h] BYREF
  _DWORD pExceptionObject[4]; // [esp+24h] [ebp-1Ch] BYREF
  int v16; // [esp+3Ch] [ebp-4h]

  *(_DWORD *)a1 = &WorldObject::`vftable';
  *(_DWORD *)(a1 + 8) = dword_4D82D4;
  *(_DWORD *)(a1 + 12) = dword_4D82D8;
  v1 = dword_4D82DC;
  *(float *)(a1 + 20) = 0.0;
  *(_DWORD *)(a1 + 16) = v1;
  *(_DWORD *)(a1 + 24) = dword_4D82D4;
  *(_DWORD *)(a1 + 28) = dword_4D82D8;
  v2 = dword_4D82DC;
  *(float *)(a1 + 36) = 0.0;
  *(_DWORD *)(a1 + 32) = v2;
  qmemcpy((void *)(a1 + 40), &unk_4D8BA8, 0x40u);
  qmemcpy((void *)(a1 + 104), &unk_4D8BA8, 0x40u);
  *(_DWORD *)(a1 + 172) = 0;
  v3 = operator new(0xCu);
  if ( !v3 )
  {
    v13 = 0;
    std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&v13);
    pExceptionObject[0] = &std::bad_alloc::`vftable';
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  *(_DWORD *)(a1 + 168) = v3;
  *v3 = v3;
  *(_DWORD *)(*(_DWORD *)(a1 + 168) + 4) = *(_DWORD *)(a1 + 168);
  v16 = 0;
  v4 = dword_4CA630 + 1;
  v5 = (dword_4D7CEC & 1) == 0;
  *(_DWORD *)(a1 + 180) = 0;
  dword_4CA630 = v4;
  *(_DWORD *)(a1 + 184) = v4;
  *(_BYTE *)(a1 + 188) = 0;
  *(_DWORD *)(a1 + 192) = 0;
  if ( v5 )
  {
    dword_4D7CEC |= 1u;
    v6 = sub_4017D0();
    sub_401730(v6);
    LOBYTE(v16) = 0;
  }
  v7 = *(_DWORD *)(a1 + 184);
  *(_DWORD *)(a1 + 4) = 0;
  v8 = *(_DWORD *)dword_4D8C10;
  v12 = *(_DWORD *)(*(_DWORD *)dword_4D8C10 + 4);
  v11 = *(char **)dword_4D8C10;
  v14[0] = v7;
  v14[1] = a1;
  v9 = sub_403230(v14, v11, v12);
  if ( dword_4D8C14 == 536870910 )
    std::_Xlength_error("list<T> too long");
  ++dword_4D8C14;
  *(_DWORD *)(v8 + 4) = v9;
  *(_DWORD *)v9[1] = v9;
  sub_402CD0(&byte_4D8C0C, (int)v14, (unsigned int *)(*(_DWORD *)dword_4D8C10 + 8), *(_DWORD ***)dword_4D8C10);
  return a1;
}
