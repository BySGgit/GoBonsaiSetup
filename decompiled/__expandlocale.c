char *__cdecl _expandlocale(char *Str, char *a2, rsize_t SizeInBytes, _WORD *a4, _DWORD *a5)
{
  const char *v5; // esi
  int v6; // eax
  unsigned __int16 *v7; // ebx
  size_t v9; // eax
  size_t v10; // [esp+10h] [ebp-B0h]
  _DWORD *Src; // [esp+14h] [ebp-ACh]
  char *Str1; // [esp+18h] [ebp-A8h]
  char *Source; // [esp+28h] [ebp-98h]
  CHAR LCData[144]; // [esp+2Ch] [ebp-94h] BYREF

  v5 = Str;
  v6 = _getptd();
  Src = (_DWORD *)(v6 + 196);
  v7 = (unsigned __int16 *)(v6 + 188);
  Str1 = (char *)(v6 + 200);
  Source = (char *)(v6 + 331);
  if ( !Str || !a2 || !SizeInBytes )
    return 0;
  if ( *Str == 67 && !Str[1] )
  {
    if ( !strcpy_s(a2, SizeInBytes, "C") )
    {
      if ( a4 )
      {
        *a4 = 0;
        a4[1] = 0;
        a4[2] = 0;
      }
      if ( a5 )
        *a5 = 0;
      return a2;
    }
LABEL_12:
    _invoke_watson(0, 0, 0, 0, 0);
  }
  v10 = strlen(Str);
  if ( v10 >= 0x83 || strcmp(Source, Str) && strcmp(Str1, Str) )
  {
    if ( !__lc_strtolc(LCData, Str) && __get_qualified_locale((int)LCData, (int)v7, LCData) )
    {
      *Src = v7[2];
      __lc_lctostr(Source, 0x83u, LCData);
      if ( !*Str || (v9 = v10, v10 >= 0x83) )
      {
        v9 = 0;
        v5 = (const char *)&unk_4BC05D;
      }
      if ( strncpy_s(Str1, 0x83u, v5, v9 + 1) )
        goto LABEL_12;
      goto LABEL_22;
    }
    return 0;
  }
LABEL_22:
  if ( a4 )
    memcpy_0(a4, v7, 6u);
  if ( a5 )
    memcpy_0(a5, Src, sizeof(_DWORD));
  if ( strcpy_s(a2, SizeInBytes, Source) )
    _invoke_watson(0, 0, 0, 0, 0);
  return Source;
}
