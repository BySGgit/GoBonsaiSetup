const wchar_t *__cdecl _Getwctypes(
        const wchar_t *lpSrcStr,
        const wchar_t *a2,
        __int16 *lpCharType,
        const _Ctypevec *a4)
{
  GetStringTypeW(1u, lpSrcStr, a2 - lpSrcStr, (LPWORD)lpCharType);
  return a2;
}
