wchar_t *__thiscall sub_44D200(char *this, wchar_t *a2, wchar_t *a3)
{
  wchar_t *v3; // esi
  const _Ctypevec *v4; // edi

  v3 = a2;
  if ( a2 != a3 )
  {
    v4 = (const _Ctypevec *)(this + 8);
    do
    {
      *v3 = _Towupper(*v3, v4);
      ++v3;
    }
    while ( v3 != a3 );
  }
  return v3;
}
