int __cdecl mbtowc(wchar_t *DstCh, const char *SrcCh, size_t SrcSizeInBytes)
{
  return _mbtowc_l(DstCh, SrcCh, SrcSizeInBytes, 0);
}
