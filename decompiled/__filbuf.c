int __cdecl _filbuf(FILE *File)
{
  int flag; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  _DWORD *v5; // edi
  _BYTE *v6; // eax
  int v7; // eax
  char *ptr; // ecx
  int result; // eax
  char *base; // [esp-8h] [ebp-Ch]
  unsigned int bufsiz; // [esp-4h] [ebp-8h]

  if ( !File )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  flag = File->_flag;
  if ( (flag & 0x83) == 0 || (flag & 0x40) != 0 )
    return -1;
  if ( (flag & 2) != 0 )
  {
    File->_flag = flag | 0x20;
    return -1;
  }
  v2 = flag | 1;
  File->_flag = v2;
  if ( (v2 & 0x10C) != 0 )
    File->_ptr = File->_base;
  else
    _getbuf(File);
  bufsiz = File->_bufsiz;
  base = File->_base;
  v3 = _fileno(File);
  v4 = _read(v3, base, bufsiz);
  File->_cnt = v4;
  if ( !v4 || v4 == -1 )
  {
    File->_flag |= v4 != 0 ? 32 : 16;
    File->_cnt = 0;
    return -1;
  }
  if ( (File->_flag & 0x82) == 0 )
  {
    if ( _fileno(File) == -1 || _fileno(File) == -2 )
    {
      v6 = &unk_4C9CB0;
    }
    else
    {
      v5 = (_DWORD *)(4 * (_fileno(File) >> 5) + 5099328);
      v6 = (_BYTE *)(*v5 + ((_fileno(File) & 0x1F) << 6));
    }
    if ( (v6[4] & 0x82) == 0x82 )
      File->_flag |= 0x2000u;
  }
  if ( File->_bufsiz == 512 )
  {
    v7 = File->_flag;
    if ( (v7 & 8) != 0 && (v7 & 0x400) == 0 )
      File->_bufsiz = 4096;
  }
  ptr = File->_ptr;
  --File->_cnt;
  result = (unsigned __int8)*ptr;
  File->_ptr = ptr + 1;
  return result;
}
