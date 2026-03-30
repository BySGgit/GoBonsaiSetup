void *__cdecl memcpy_0(void *a1, const void *Src, size_t Size)
{
  _BYTE *v3; // esi
  _BYTE *v4; // edi
  size_t v5; // ecx
  void *result; // eax
  char *v7; // esi
  char *v8; // edi
  size_t v9; // ecx

  v3 = Src;
  v4 = a1;
  if ( a1 > Src && a1 < (char *)Src + Size )
  {
    v7 = (char *)Src + Size - 4;
    v8 = (char *)a1 + Size - 4;
    if ( ((unsigned __int8)v8 & 3) == 0 )
    {
      v9 = Size >> 2;
      if ( Size >> 2 >= 8 )
      {
        while ( v9 )
        {
          *(_DWORD *)v8 = *(_DWORD *)v7;
          v7 -= 4;
          v8 -= 4;
          --v9;
        }
        switch ( Size & 3 )
        {
          case 0u:
            goto TrailDown0_0;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
      switch ( Size & 3 )
      {
        case 0u:
          goto TrailDown0_0;
        case 1u:
          goto TrailDown1_0;
        case 2u:
          goto TrailDown2_0;
        case 3u:
          goto TrailDown3_0;
      }
    }
    switch ( Size )
    {
      case 0u:
TrailDown0_0:
        result = a1;
        break;
      case 1u:
TrailDown1_0:
        v8[3] = v7[3];
        result = a1;
        break;
      case 2u:
TrailDown2_0:
        v8[3] = v7[3];
        v8[2] = v7[2];
        result = a1;
        break;
      case 3u:
TrailDown3_0:
        v8[3] = v7[3];
        v8[2] = v7[2];
        v8[1] = v7[1];
        result = a1;
        break;
      default:
        __asm { jmp     dword ptr ds:ByteCopyDown_0+4[eax*4] }
        return result;
    }
  }
  else
  {
    if ( Size >= 0x80 )
    {
      if ( dword_4DD054 )
      {
        v3 = Src;
        v4 = a1;
        if ( ((unsigned __int8)a1 & 0xF) == ((unsigned __int8)Src & 0xF) )
        {
          if ( ((unsigned __int8)Src & 0xF) == 0 )
          {
            if ( Size >> 7 )
              JUMPOUT(0x458AAF);
            JUMPOUT(0x458B0C);
          }
          JUMPOUT(0x458B5E);
        }
      }
    }
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( Size >= 4 )
        __asm { jmp     dword ptr ds:CopyUnwindUp_0+4[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0_0[ecx*4]; jumptable 004555C9 case 0 }
    }
    v5 = Size >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0_0;
      case 1u:
        goto UnwindUp1_0;
      case 2u:
        goto UnwindUp2_0;
      case 3u:
        goto UnwindUp3_0;
      case 4u:
        goto UnwindUp4_0;
      case 5u:
        goto UnwindUp5_0;
      case 6u:
        goto UnwindUp6_0;
      case 7u:
        *(_DWORD *)&v4[4 * v5 - 28] = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6_0:
        *(_DWORD *)&v4[4 * v5 - 24] = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5_0:
        *(_DWORD *)&v4[4 * v5 - 20] = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4_0:
        *(_DWORD *)&v4[4 * v5 - 16] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3_0:
        *(_DWORD *)&v4[4 * v5 - 12] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2_0:
        *(_DWORD *)&v4[4 * v5 - 8] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1_0:
        *(_DWORD *)&v4[4 * v5 - 4] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 += 4 * v5;
UnwindUp0_0:
        switch ( Size & 3 )
        {
          case 0u:
            goto TrailUp0_0;
          case 1u:
            goto TrailUp1_0;
          case 2u:
            goto TrailUp2_0;
          case 3u:
            goto TrailUp3_0;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 += 4 * v5;
        switch ( Size & 3 )
        {
          case 0u:
TrailUp0_0:
            result = a1;
            break;
          case 1u:
TrailUp1_0:
            *v4 = *v3;
            result = a1;
            break;
          case 2u:
TrailUp2_0:
            *v4 = *v3;
            v4[1] = v3[1];
            result = a1;
            break;
          case 3u:
TrailUp3_0:
            *v4 = *v3;
            v4[1] = v3[1];
            v4[2] = v3[2];
            result = a1;
            break;
        }
        break;
    }
  }
  return result;
}
