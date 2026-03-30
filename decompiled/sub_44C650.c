void __usercall sub_44C650(_DWORD *a1@<esi>)
{
  _DWORD *v1; // ebx
  int v2; // ebp
  int v3; // eax
  _BYTE v4[4]; // [esp+10h] [ebp-4h] BYREF

  a1[12] = 0;
  a1[2] = 0;
  a1[4] = 0;
  a1[5] = 513;
  a1[6] = 6;
  a1[7] = 0;
  a1[8] = 0;
  a1[9] = 0;
  a1[10] = 0;
  a1[11] = 0;
  a1[3] = 0;
  v1 = operator new(4u);
  if ( v1 )
  {
    *v1 = std::locale::_Init();
    v2 = sub_452C79();
    std::_Lockit::_Lockit((std::_Lockit *)v4, 0);
    v3 = *(_DWORD *)(v2 + 4);
    if ( v3 != -1 )
      *(_DWORD *)(v2 + 4) = v3 + 1;
    std::_Lockit::~_Lockit((std::_Lockit *)v4);
    a1[12] = v1;
  }
  else
  {
    a1[12] = 0;
  }
}
