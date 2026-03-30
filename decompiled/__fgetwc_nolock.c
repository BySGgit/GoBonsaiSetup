wint_t __cdecl _fgetwc_nolock(FILE *Stream)
{
  FILE *v1; // esi
  _DWORD *v2; // edi
  _BYTE *v3; // eax
  bool v4; // sf
  int v5; // eax
  wint_t result; // ax
  int v7; // eax
  _DWORD *v8; // edi
  char *v9; // eax
  size_t v10; // edi
  int v11; // eax
  int v12; // eax
  char SrcCh[4]; // [esp+Ch] [ebp-4h] BYREF

  v1 = Stream;
  if ( (Stream->_flag & 0x40) == 0 )
  {
    if ( _fileno(Stream) == -1 || _fileno(v1) == -2 )
    {
      v3 = &unk_4C9CB0;
    }
    else
    {
      v2 = (_DWORD *)(4 * (_fileno(v1) >> 5) + 5099328);
      v3 = (_BYTE *)(*v2 + ((_fileno(v1) & 0x1F) << 6));
    }
    if ( (v3[36] & 0x7F) != 0 )
    {
      v4 = --v1->_cnt < 0;
      if ( v4 )
        v5 = _filbuf(v1);
      else
        v5 = *(unsigned __int8 *)v1->_ptr++;
      if ( v5 != -1 )
      {
        v4 = --v1->_cnt < 0;
        LOBYTE(Stream) = v5;
        if ( v4 )
          v7 = _filbuf(v1);
        else
          v7 = *(unsigned __int8 *)v1->_ptr++;
        if ( v7 != -1 )
        {
          BYTE1(Stream) = v7;
          return (unsigned __int16)Stream;
        }
      }
      return -1;
    }
    if ( (v1->_flag & 0x40) == 0 )
    {
      if ( _fileno(v1) == -1 || _fileno(v1) == -2 )
      {
        v9 = (char *)&unk_4C9CB0;
      }
      else
      {
        v8 = (_DWORD *)(4 * (_fileno(v1) >> 5) + 5099328);
        v9 = (char *)(*v8 + ((_fileno(v1) & 0x1F) << 6));
      }
      if ( v9[4] < 0 )
      {
        v10 = 1;
        v4 = --v1->_cnt < 0;
        if ( v4 )
          v11 = _filbuf(v1);
        else
          v11 = *(unsigned __int8 *)v1->_ptr++;
        if ( v11 == -1 )
          return -1;
        SrcCh[0] = v11;
        if ( isleadbyte((unsigned __int8)v11) )
        {
          v4 = --v1->_cnt < 0;
          if ( v4 )
            v12 = _filbuf(v1);
          else
            v12 = *(unsigned __int8 *)v1->_ptr++;
          if ( v12 == -1 )
          {
            ungetc(SrcCh[0], v1);
            return -1;
          }
          SrcCh[1] = v12;
          v10 = 2;
        }
        if ( mbtowc((wchar_t *)&Stream, SrcCh, v10) != -1 )
          return (unsigned __int16)Stream;
        *_errno() = 42;
        return -1;
      }
    }
  }
  v4 = v1->_cnt - 2 < 0;
  v1->_cnt -= 2;
  if ( v4 )
    return _filwbuf(v1);
  result = *(_WORD *)v1->_ptr;
  v1->_ptr += 2;
  return result;
}
