BOOL __usercall sub_435A60@<eax>(_DWORD *a1@<edi>)
{
  BOOL result; // eax
  HANDLE ClipboardData; // eax
  void *v3; // ebp
  const WCHAR *v4; // ebx
  int v5; // eax

  sub_4357D0((int)a1);
  result = OpenClipboard(0);
  if ( result )
  {
    ClipboardData = GetClipboardData(0xDu);
    v3 = ClipboardData;
    if ( ClipboardData )
    {
      v4 = (const WCHAR *)GlobalLock(ClipboardData);
      if ( v4 )
      {
        if ( sub_436CD0((int)(a1 + 20), a1[73], v4) )
        {
          v5 = lstrlenW(v4);
          sub_435650(a1[73] + v5, a1);
        }
        a1[75] = a1[73];
        GlobalUnlock(v3);
      }
    }
    return CloseClipboard();
  }
  return result;
}
