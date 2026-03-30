errno_t __cdecl wcstombs_s(
        size_t *PtNumOfCharConverted,
        char *Dst,
        size_t DstSizeInBytes,
        const wchar_t *Src,
        size_t MaxCountInBytes)
{
  return _wcstombs_s_l(PtNumOfCharConverted, Dst, DstSizeInBytes, Src, MaxCountInBytes, 0);
}
