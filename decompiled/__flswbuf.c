int __cdecl _flswbuf(unsigned __int16 a1, FILE *FileHandle)
{
  int flag; // eax
  int v5; // eax
  unsigned int v6; // eax
  char *base; // eax
  char *ptr; // edi
  signed int v9; // edi
  _BYTE *v10; // eax
  __int64 v11; // rax
  unsigned __int16 v12; // bx
  int Buf; // [esp+4h] [ebp-4h] BYREF
  int FileHandlea; // [esp+14h] [ebp+Ch]

  FileHandlea = _fileno(FileHandle);
  flag = FileHandle->_flag;
  if ( (flag & 0x82) == 0 )
  {
    *_errno() = 9;
LABEL_3:
    FileHandle->_flag |= 0x20u;
    return 0xFFFF;
  }
  if ( (flag & 0x40) != 0 )
  {
    *_errno() = 34;
    goto LABEL_3;
  }
  if ( (flag & 1) != 0 )
  {
    FileHandle->_cnt = 0;
    if ( (flag & 0x10) == 0 )
    {
      FileHandle->_flag = flag | 0x20;
      return 0xFFFF;
    }
    FileHandle->_ptr = FileHandle->_base;
    FileHandle->_flag = flag & 0xFFFFFFFE;
  }
  v5 = FileHandle->_flag;
  FileHandle->_cnt = 0;
  Buf = 0;
  v6 = v5 & 0xFFFFFFED | 2;
  FileHandle->_flag = v6;
  if ( (v6 & 0x10C) == 0
    && (FileHandle != (FILE *)(sub_46311B() + 8) && FileHandle != (FILE *)(sub_46311B() + 16) || !_isatty(FileHandlea)) )
  {
    _getbuf(FileHandle);
  }
  if ( (FileHandle->_flag & 0x108) != 0 )
  {
    base = FileHandle->_base;
    ptr = FileHandle->_ptr;
    FileHandle->_ptr = base + 2;
    v9 = ptr - base;
    FileHandle->_cnt = FileHandle->_bufsiz - 2;
    if ( v9 <= 0 )
    {
      if ( FileHandlea == -1 || FileHandlea == -2 )
        v10 = &unk_4C9CB0;
      else
        v10 = (_BYTE *)(dword_4DCF40[FileHandlea >> 5] + ((FileHandlea & 0x1F) << 6));
      if ( (v10[4] & 0x20) != 0 )
      {
        v11 = _lseeki64(FileHandlea, 0, 2);
        if ( (HIDWORD(v11) & (unsigned int)v11) == 0xFFFFFFFF )
          goto LABEL_28;
      }
    }
    else
    {
      Buf = _write(FileHandlea, base, v9);
    }
    v12 = a1;
    *(_WORD *)FileHandle->_base = a1;
  }
  else
  {
    v9 = 2;
    v12 = a1;
    LOWORD(Buf) = a1;
    Buf = _write(FileHandlea, &Buf, 2u);
  }
  if ( Buf != v9 )
  {
LABEL_28:
    FileHandle->_flag |= 0x20u;
    return 0xFFFF;
  }
  return v12;
}
