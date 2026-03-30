_DWORD *__usercall sub_44DB70@<eax>(int a1@<eax>, int a2@<ecx>, _DWORD *a3@<edi>)
{
  int v3; // esi
  int v4; // eax
  int v6; // [esp+0h] [ebp-4h] BYREF

  v6 = a2;
  v3 = **(_DWORD **)(a1 + 48);
  *a3 = v3;
  std::_Lockit::_Lockit((std::_Lockit *)&v6, 0);
  v4 = *(_DWORD *)(v3 + 4);
  if ( v4 != -1 )
    *(_DWORD *)(v3 + 4) = v4 + 1;
  std::_Lockit::~_Lockit((std::_Lockit *)&v6);
  return a3;
}
