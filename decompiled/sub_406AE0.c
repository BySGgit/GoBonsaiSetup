int __userpurge sub_406AE0@<eax>(wchar_t *Source@<ecx>, int a2@<esi>, char *a3)
{
  int v3; // eax
  char *v4; // eax
  char *v5; // edi
  _DWORD *v6; // eax
  int v8; // [esp+Ch] [ebp-1Ch] BYREF
  _DWORD pExceptionObject[3]; // [esp+10h] [ebp-18h] BYREF
  int v10; // [esp+24h] [ebp-4h]

  *(_DWORD *)a2 = a3;
  *(float *)(a2 + 4) = 0.0;
  v3 = dword_4D52E0;
  *(float *)(a2 + 8) = 0.0;
  *(_DWORD *)(a2 + 524) = ++v3;
  dword_4D52E0 = v3 + 1;
  *(_DWORD *)(a2 + 528) = v3 + 1;
  *(_WORD *)(a2 + 532) = 256;
  wcsncpy_s((wchar_t *)(a2 + 12), 0xFFu, Source, 0xFFFFFFFF);
  v8 = a2;
  if ( (dword_4D8E14 & 1) == 0 )
  {
    dword_4D8E14 |= 1u;
    v10 = 0;
    dword_4D8E0C = 0;
    v4 = (char *)operator new(0xCu);
    if ( !v4 )
    {
      a3 = 0;
      std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&a3);
      pExceptionObject[0] = &std::bad_alloc::`vftable';
      _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
    }
    dword_4D8E08 = v4;
    *(_DWORD *)v4 = v4;
    *((_DWORD *)dword_4D8E08 + 1) = dword_4D8E08;
    atexit(sub_472020);
    v10 = -1;
  }
  v5 = dword_4D8E08 + 4;
  v6 = sub_40FD70(dword_4D8E08, *((_DWORD *)dword_4D8E08 + 1), &v8);
  if ( dword_4D8E0C == 1073741822 )
    std::_Xlength_error("list<T> too long");
  ++dword_4D8E0C;
  *(_DWORD *)v5 = v6;
  *(_DWORD *)v6[1] = v6;
  return a2;
}
