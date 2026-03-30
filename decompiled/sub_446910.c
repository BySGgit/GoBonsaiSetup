_DWORD *__stdcall sub_446910(_DWORD *a1)
{
  _DWORD *v1; // edi
  int v2; // ebx
  int v3; // eax
  _BYTE v5[4]; // [esp+10h] [ebp-10h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  *a1 = &std::wstreambuf::`vftable';
  std::_Mutex::_Mutex((std::_Mutex *)(a1 + 1));
  v6 = 0;
  v1 = operator new(4u);
  if ( v1 )
  {
    *v1 = std::locale::_Init();
    v2 = sub_452C79();
    std::_Lockit::_Lockit((std::_Lockit *)v5, 0);
    v3 = *(_DWORD *)(v2 + 4);
    if ( v3 != -1 )
      *(_DWORD *)(v2 + 4) = v3 + 1;
    std::_Lockit::~_Lockit((std::_Lockit *)v5);
  }
  else
  {
    v1 = 0;
  }
  a1[4] = a1 + 2;
  a1[8] = a1 + 6;
  a1[9] = a1 + 7;
  a1[14] = v1;
  a1[5] = a1 + 3;
  a1[12] = a1 + 10;
  a1[13] = a1 + 11;
  a1[3] = 0;
  *(_DWORD *)a1[9] = 0;
  *(_DWORD *)a1[13] = 0;
  *(_DWORD *)a1[4] = 0;
  *(_DWORD *)a1[8] = 0;
  *(_DWORD *)a1[12] = 0;
  return a1;
}
