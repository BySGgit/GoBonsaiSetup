int __cdecl _filwbuf(FILE *Stream)
{
  int flag; // eax
  int v2; // eax
  int v3; // eax
  unsigned int v4; // eax
  _DWORD *v5; // edi
  _BYTE *v6; // eax
  int v7; // eax
  char *ptr; // ecx
  int result; // eax
  char *base; // [esp-8h] [ebp-Ch]
  unsigned int bufsiz; // [esp-4h] [ebp-8h]

  if ( !Stream )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0xFFFF;
  }
  flag = Stream->_flag;
  if ( (flag & 0x83) == 0 || (flag & 0x40) != 0 )
    return 0xFFFF;
  if ( (flag & 2) != 0 )
  {
    Stream->_flag = flag | 0x20;
    return 0xFFFF;
  }
  v2 = flag | 1;
  Stream->_flag = v2;
  if ( (v2 & 0x10C) != 0 )
    Stream->_ptr = Stream->_base;
  else
    _getbuf(Stream);
  bufsiz = Stream->_bufsiz;
  base = Stream->_base;
  v3 = _fileno(Stream);
  v4 = _read(v3, base, bufsiz);
  Stream->_cnt = v4;
  if ( v4 < 2 || v4 == -1 )
  {
    Stream->_flag |= v4 != 0 ? 32 : 16;
    Stream->_cnt = 0;
    return 0xFFFF;
  }
  if ( (Stream->_flag & 0x82) == 0 )
  {
    if ( _fileno(Stream) == -1 || _fileno(Stream) == -2 )
    {
      v6 = &unk_4C9CB0;
    }
    else
    {
      v5 = (_DWORD *)(4 * (_fileno(Stream) >> 5) + 5099328);
      v6 = (_BYTE *)(*v5 + ((_fileno(Stream) & 0x1F) << 6));
    }
    if ( (v6[4] & 0x82) == 0x82 )
      Stream->_flag |= 0x2000u;
  }
  if ( Stream->_bufsiz == 512 )
  {
    v7 = Stream->_flag;
    if ( (v7 & 8) != 0 && (v7 & 0x400) == 0 )
      Stream->_bufsiz = 4096;
  }
  ptr = Stream->_ptr;
  Stream->_cnt -= 2;
  result = *(unsigned __int16 *)ptr;
  Stream->_ptr = ptr + 2;
  return result;
}
