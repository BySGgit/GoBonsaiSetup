wint_t __cdecl _ungetwc_nolock(wint_t Character, FILE *Stream)
{
  wint_t v2; // bx
  int flag; // eax
  _DWORD *v4; // edi
  char *v5; // eax
  _DWORD *v6; // edi
  _BYTE *v7; // eax
  wint_t v8; // dx
  int v9; // eax
  char *v10; // ecx
  int v11; // ecx
  char *v13; // eax
  char *ptr; // eax
  int v15; // eax
  int SizeConverted; // [esp+Ch] [ebp-10h] BYREF
  char MbCh[8]; // [esp+10h] [ebp-Ch] BYREF

  v2 = Character;
  if ( Character == 0xFFFF )
    return -1;
  flag = Stream->_flag;
  if ( (flag & 1) == 0 && ((flag & 0x80u) == 0 || (flag & 2) != 0) )
    return -1;
  if ( !Stream->_base )
    _getbuf(Stream);
  if ( (Stream->_flag & 0x40) != 0 )
  {
LABEL_30:
    v13 = Stream->_base + 2;
    if ( Stream->_ptr < v13 )
    {
      if ( Stream->_cnt || Stream->_bufsiz < 2u )
        return -1;
      Stream->_ptr = v13;
    }
    Stream->_ptr -= 2;
    ptr = Stream->_ptr;
    if ( (Stream->_flag & 0x40) != 0 )
    {
      if ( *(_WORD *)ptr != v2 )
      {
        Stream->_ptr = ptr + 2;
        return -1;
      }
    }
    else
    {
      *(_WORD *)ptr = v2;
    }
    v15 = Stream->_flag;
    Stream->_cnt += 2;
    Stream->_flag = v15 & 0xFFFFFFEE | 1;
    return v2;
  }
  if ( _fileno(Stream) == -1 || _fileno(Stream) == -2 )
  {
    v5 = (char *)&unk_4C9CB0;
  }
  else
  {
    v4 = (_DWORD *)(4 * (_fileno(Stream) >> 5) + 5099328);
    v5 = (char *)(*v4 + ((_fileno(Stream) & 0x1F) << 6));
  }
  if ( v5[4] >= 0 )
  {
    v2 = Character;
    goto LABEL_30;
  }
  if ( _fileno(Stream) == -1 || _fileno(Stream) == -2 )
  {
    v7 = &unk_4C9CB0;
  }
  else
  {
    v6 = (_DWORD *)(4 * (_fileno(Stream) >> 5) + 5099328);
    v7 = (_BYTE *)(*v6 + ((_fileno(Stream) & 0x1F) << 6));
  }
  if ( (v7[36] & 0x7F) != 0 )
  {
    v8 = Character;
    v9 = 2;
    *(_WORD *)MbCh = Character;
    SizeConverted = 2;
  }
  else
  {
    if ( wctomb_s(&SizeConverted, MbCh, 5u, Character) )
      return -1;
    v9 = SizeConverted;
    v8 = Character;
  }
  v10 = &Stream->_base[v9];
  if ( Stream->_ptr < v10 )
  {
    if ( !Stream->_cnt && v9 <= Stream->_bufsiz )
    {
      Stream->_ptr = v10;
      goto LABEL_25;
    }
    return -1;
  }
LABEL_25:
  v11 = v9 - 1;
  if ( v9 - 1 >= 0 )
  {
    do
      *--Stream->_ptr = MbCh[v11--];
    while ( v11 >= 0 );
    v9 = SizeConverted;
  }
  Stream->_cnt += v9;
  Stream->_flag = Stream->_flag & 0xFFFFFFEE | 1;
  return v8;
}
