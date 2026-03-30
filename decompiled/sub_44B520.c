struct std::locale::facet *__usercall sub_44B520@<eax>(int a1@<edi>)
{
  int v1; // ebx
  unsigned int v2; // esi
  int v3; // eax
  struct std::locale::facet *v4; // ecx
  int v5; // eax
  struct std::locale::facet *v6; // esi
  int v7; // eax
  struct std::locale::facet *v9; // [esp+10h] [ebp-24h] BYREF
  _BYTE v10[4]; // [esp+14h] [ebp-20h] BYREF
  _BYTE v11[4]; // [esp+18h] [ebp-1Ch] BYREF
  _BYTE pExceptionObject[12]; // [esp+1Ch] [ebp-18h] BYREF
  int v13; // [esp+30h] [ebp-4h]

  std::_Lockit::_Lockit((std::_Lockit *)v11, 0);
  v13 = 0;
  v1 = dword_4D8DC8;
  v9 = (struct std::locale::facet *)dword_4D8DC8;
  if ( !dword_4DBEEC )
  {
    std::_Lockit::_Lockit((std::_Lockit *)v10, 0);
    if ( !dword_4DBEEC )
      dword_4DBEEC = ++dword_4D6DA8;
    std::_Lockit::~_Lockit((std::_Lockit *)v10);
  }
  v2 = dword_4DBEEC;
  v3 = *(_DWORD *)a1;
  if ( (unsigned int)dword_4DBEEC >= *(_DWORD *)(*(_DWORD *)a1 + 12) )
  {
    v4 = 0;
  }
  else
  {
    v4 = *(struct std::locale::facet **)(*(_DWORD *)(v3 + 8) + 4 * dword_4DBEEC);
    if ( v4 )
    {
LABEL_11:
      v6 = v4;
LABEL_12:
      if ( v6 )
        goto LABEL_20;
      goto LABEL_13;
    }
  }
  if ( !*(_BYTE *)(v3 + 20) )
    goto LABEL_11;
  v5 = sub_452C79();
  if ( v2 < *(_DWORD *)(v5 + 12) )
  {
    v6 = *(struct std::locale::facet **)(*(_DWORD *)(v5 + 8) + 4 * v2);
    goto LABEL_12;
  }
LABEL_13:
  if ( v1 )
  {
    v6 = (struct std::locale::facet *)v1;
  }
  else
  {
    if ( sub_44BBB0(&v9, a1) == -1 )
    {
      sub_453AFB((std::exception *)pExceptionObject, "bad cast");
      _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_cast_std__);
    }
    v6 = v9;
    dword_4D8DC8 = (int)v9;
    std::_Lockit::_Lockit((std::_Lockit *)v10, 0);
    v7 = *((_DWORD *)v6 + 1);
    if ( v7 != -1 )
      *((_DWORD *)v6 + 1) = v7 + 1;
    std::_Lockit::~_Lockit((std::_Lockit *)v10);
    std::locale::facet::_Facet_Register(v6);
  }
LABEL_20:
  v13 = -1;
  std::_Lockit::~_Lockit((std::_Lockit *)v11);
  return v6;
}
