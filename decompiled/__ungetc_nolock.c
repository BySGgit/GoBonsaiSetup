int __cdecl _ungetc_nolock(int Character, FILE *Stream)
{
  int v2; // eax
  _BYTE *v3; // ecx
  char *v4; // eax
  int flag; // eax
  char *v7; // eax
  int v8; // eax

  if ( (Stream->_flag & 0x40) == 0 )
  {
    v2 = _fileno(Stream);
    if ( v2 == -1 || v2 == -2 )
      v3 = &unk_4C9CB0;
    else
      v3 = (_BYTE *)(dword_4DCF40[v2 >> 5] + ((v2 & 0x1F) << 6));
    if ( (v3[36] & 0x7F) != 0
      || (v2 == -1 || v2 == -2
        ? (v4 = (char *)&unk_4C9CB0)
        : (v4 = (char *)(dword_4DCF40[v2 >> 5] + ((v2 & 0x1F) << 6))),
          v4[36] < 0) )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return -1;
    }
  }
  if ( Character == -1 )
    return -1;
  flag = Stream->_flag;
  if ( (flag & 1) == 0 && ((flag & 0x80u) == 0 || (flag & 2) != 0) )
    return -1;
  if ( !Stream->_base )
    _getbuf(Stream);
  if ( Stream->_ptr == Stream->_base )
  {
    if ( Stream->_cnt )
      return -1;
    ++Stream->_ptr;
  }
  v7 = --Stream->_ptr;
  if ( (Stream->_flag & 0x40) != 0 )
  {
    if ( *v7 != (_BYTE)Character )
    {
      Stream->_ptr = v7 + 1;
      return -1;
    }
  }
  else
  {
    *v7 = Character;
  }
  v8 = Stream->_flag;
  ++Stream->_cnt;
  Stream->_flag = v8 & 0xFFFFFFEE | 1;
  return (unsigned __int8)Character;
}
