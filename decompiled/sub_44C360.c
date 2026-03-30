char *__stdcall sub_44C360(int a1, void *a2, char *a3)
{
  char *v3; // ebx
  char *v4; // edi
  int v6; // [esp+0h] [ebp-2Ch] BYREF
  _DWORD pExceptionObject[4]; // [esp+10h] [ebp-1Ch] BYREF
  int v8; // [esp+28h] [ebp-4h]

  pExceptionObject[3] = &v6;
  v3 = a3;
  v4 = (char *)operator new(0x34u);
  a3 = v4;
  if ( !v4 )
  {
    a3 = 0;
    std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&a3);
    pExceptionObject[0] = &std::bad_alloc::`vftable';
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  v8 = 0;
  *(_DWORD *)v4 = a1;
  *((_DWORD *)v4 + 1) = a2;
  LOBYTE(v8) = 1;
  if ( v4 != (char *)-8 )
  {
    *((_DWORD *)v4 + 6) = 0;
    *((_DWORD *)v4 + 7) = 7;
    *((_WORD *)v4 + 4) = 0;
    sub_4037B0(0xFFFFFFFF, (int)(v4 + 8), v3, 0);
    *((_DWORD *)v4 + 9) = *((_DWORD *)v3 + 7);
    *((_DWORD *)v4 + 10) = *((_DWORD *)v3 + 8);
    *((_DWORD *)v4 + 11) = *((_DWORD *)v3 + 9);
    *((_DWORD *)v4 + 12) = *((_DWORD *)v3 + 10);
  }
  return v4;
}
