int __cdecl _setmbcp_nolock(int a1, _DWORD *a2)
{
  int SystemCP; // edi
  unsigned int i; // eax
  BYTE *v5; // esi
  BYTE v6; // cl
  unsigned int j; // eax
  _BYTE *v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // edi
  _WORD *v11; // eax
  int v12; // ecx
  _WORD *v13; // ecx
  int v14; // edx
  _BYTE *v15; // eax
  int v16; // ecx
  int v17; // edx
  unsigned int v18; // [esp+Ch] [ebp-20h]
  int v19; // [esp+10h] [ebp-1Ch]
  _BYTE *v20; // [esp+10h] [ebp-1Ch]
  struct _cpinfo CPInfo; // [esp+14h] [ebp-18h] BYREF
  int v22; // [esp+34h] [ebp+8h]

  SystemCP = getSystemCP(a1);
  v22 = SystemCP;
  if ( SystemCP )
  {
    v19 = 0;
    for ( i = 0; i < 60; i += 12 )
    {
      if ( dword_4C9828[i] == SystemCP )
      {
        memset(a2 + 7, 0, 0x101u);
        v18 = 0;
        v8 = (char *)&unk_4C9838 + 48 * v19;
        v20 = v8;
        do
        {
          while ( *v8 )
          {
            LOBYTE(v9) = v8[1];
            if ( !(_BYTE)v9 )
              break;
            v10 = (unsigned __int8)*v8;
            v9 = (unsigned __int8)v9;
            while ( v10 <= v9 )
            {
              *((_BYTE *)a2 + v10 + 29) |= byte_4C9824[v18];
              v9 = (unsigned __int8)v8[1];
              ++v10;
            }
            SystemCP = v22;
            v8 += 2;
          }
          ++v18;
          v8 = v20 + 8;
          v20 += 8;
        }
        while ( v18 < 4 );
        a2[1] = SystemCP;
        a2[2] = 1;
        a2[3] = CPtoLCID(SystemCP);
        v11 = a2 + 4;
        v13 = (_WORD *)((char *)&unk_4C982C + v12);
        v14 = 6;
        do
        {
          *v11++ = *v13++;
          --v14;
        }
        while ( v14 );
LABEL_26:
        setSBUpLow((int)a2);
        return 0;
      }
      ++v19;
    }
    if ( SystemCP == 65000 || SystemCP == 65001 || !IsValidCodePage((unsigned __int16)SystemCP) )
      return -1;
    if ( GetCPInfo(SystemCP, &CPInfo) )
    {
      memset(a2 + 7, 0, 0x101u);
      a2[1] = SystemCP;
      a2[3] = 0;
      if ( CPInfo.MaxCharSize <= 1 )
      {
        a2[2] = 0;
      }
      else
      {
        if ( CPInfo.LeadByte[0] )
        {
          v5 = &CPInfo.LeadByte[1];
          do
          {
            v6 = *v5;
            if ( !*v5 )
              break;
            for ( j = *(v5 - 1); j <= v6; ++j )
              *((_BYTE *)a2 + j + 29) |= 4u;
            v5 += 2;
          }
          while ( *(v5 - 1) );
        }
        v15 = (char *)a2 + 30;
        v16 = 254;
        do
        {
          *v15++ |= 8u;
          --v16;
        }
        while ( v16 );
        a2[3] = CPtoLCID(a2[1]);
        a2[2] = v17;
      }
      a2[4] = 0;
      a2[5] = 0;
      a2[6] = 0;
      goto LABEL_26;
    }
    if ( !dword_4D72C0 )
      return -1;
  }
  setSBCS(a2);
  return 0;
}
