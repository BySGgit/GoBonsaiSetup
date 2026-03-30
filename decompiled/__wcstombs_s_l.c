errno_t __cdecl _wcstombs_s_l(
        size_t *PtNumOfCharConverted,
        char *Dst,
        size_t DstSizeInBytes,
        const wchar_t *Src,
        size_t MaxCountInBytes,
        _locale_t Locale)
{
  size_t v6; // eax
  unsigned int v7; // eax
  int *v9; // eax
  size_t v10; // eax
  errno_t v11; // [esp-4h] [ebp-14h]
  errno_t v12; // [esp+Ch] [ebp-4h]

  v12 = 0;
  if ( Dst )
  {
    if ( DstSizeInBytes )
      goto LABEL_3;
LABEL_15:
    v9 = _errno();
    v11 = 22;
LABEL_16:
    *v9 = v11;
    _invalid_parameter_noinfo();
    return v11;
  }
  if ( DstSizeInBytes )
    goto LABEL_15;
LABEL_3:
  if ( Dst )
    *Dst = 0;
  if ( PtNumOfCharConverted )
    *PtNumOfCharConverted = 0;
  v6 = MaxCountInBytes;
  if ( MaxCountInBytes > DstSizeInBytes )
    v6 = DstSizeInBytes;
  if ( v6 > 0x7FFFFFFF )
    goto LABEL_15;
  v7 = _wcstombs_l_helper(Dst, Src, v6, (struct localeinfo_struct *)Locale);
  if ( v7 == -1 )
  {
    if ( Dst )
      *Dst = 0;
    return *_errno();
  }
  v10 = v7 + 1;
  if ( Dst )
  {
    if ( v10 > DstSizeInBytes )
    {
      if ( MaxCountInBytes != -1 )
      {
        *Dst = 0;
        if ( DstSizeInBytes <= v10 )
        {
          v9 = _errno();
          v11 = 34;
          goto LABEL_16;
        }
      }
      v10 = DstSizeInBytes;
      v12 = 80;
    }
    Dst[v10 - 1] = 0;
  }
  if ( PtNumOfCharConverted )
    *PtNumOfCharConverted = v10;
  return v12;
}
