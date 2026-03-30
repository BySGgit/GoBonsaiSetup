void __usercall setSBUpLow(int a1@<esi>)
{
  unsigned int i; // eax
  BYTE v2; // al
  BYTE *v3; // ebx
  unsigned int v4; // ecx
  unsigned int v5; // eax
  int v6; // eax
  WORD v7; // cx
  char v8; // cl
  unsigned int v9; // ecx
  _BYTE *v10; // eax
  char v11; // dl
  int v12; // [esp+8h] [ebp-51Ch]
  struct _cpinfo CPInfo; // [esp+Ch] [ebp-518h] BYREF
  WORD CharType[256]; // [esp+20h] [ebp-504h] BYREF
  WCHAR v15[128]; // [esp+220h] [ebp-304h] BYREF
  WCHAR DestStr[128]; // [esp+320h] [ebp-204h] BYREF
  CHAR MultiByteStr[256]; // [esp+420h] [ebp-104h] BYREF

  if ( GetCPInfo(*(_DWORD *)(a1 + 4), &CPInfo) )
  {
    for ( i = 0; i < 0x100; ++i )
      MultiByteStr[i] = i;
    v2 = CPInfo.LeadByte[0];
    MultiByteStr[0] = 32;
    if ( CPInfo.LeadByte[0] )
    {
      v3 = &CPInfo.LeadByte[1];
      do
      {
        v4 = v2;
        v5 = *v3;
        if ( v4 <= v5 )
          memset(&MultiByteStr[v4], 32, v5 - v4 + 1);
        v2 = v3[1];
        v3 += 2;
      }
      while ( v2 );
    }
    __crtGetStringTypeA(0, 1u, MultiByteStr, 256, CharType, *(_DWORD *)(a1 + 4), *(_DWORD *)(a1 + 12), 0);
    __crtLCMapStringA(0, *(_DWORD *)(a1 + 12), 0x100u, MultiByteStr, 256, DestStr, 256, *(_DWORD *)(a1 + 4), 0);
    __crtLCMapStringA(0, *(_DWORD *)(a1 + 12), 0x200u, MultiByteStr, 256, v15, 256, *(_DWORD *)(a1 + 4), 0);
    v6 = 0;
    while ( 1 )
    {
      v7 = CharType[v6];
      if ( (v7 & 1) != 0 )
      {
        *(_BYTE *)(a1 + v6 + 29) |= 0x10u;
        v8 = *((_BYTE *)DestStr + v6);
      }
      else
      {
        if ( (v7 & 2) == 0 )
        {
          *(_BYTE *)(a1 + v6 + 285) = 0;
          goto LABEL_16;
        }
        *(_BYTE *)(a1 + v6 + 29) |= 0x20u;
        v8 = *((_BYTE *)v15 + v6);
      }
      *(_BYTE *)(a1 + v6 + 285) = v8;
LABEL_16:
      if ( (unsigned int)++v6 >= 0x100 )
        return;
    }
  }
  v9 = 0;
  v12 = -97 - (a1 + 285);
  do
  {
    v10 = (_BYTE *)(a1 + v9 + 285);
    if ( (unsigned int)&v10[v12 + 32] <= 0x19 )
    {
      *(_BYTE *)(a1 + v9 + 29) |= 0x10u;
      v11 = v9 + 32;
LABEL_23:
      *v10 = v11;
      goto LABEL_25;
    }
    if ( (unsigned int)&v10[v12] <= 0x19 )
    {
      *(_BYTE *)(a1 + v9 + 29) |= 0x20u;
      v11 = v9 - 32;
      goto LABEL_23;
    }
    *v10 = 0;
LABEL_25:
    ++v9;
  }
  while ( v9 < 0x100 );
}
