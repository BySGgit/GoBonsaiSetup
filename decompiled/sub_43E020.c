_DWORD *__thiscall sub_43E020(int *this, unsigned int a2, unsigned int a3)
{
  int v3; // esi
  int v4; // eax
  int v5; // edx
  _DWORD *v6; // edi
  wchar_t *v7; // eax
  int v8; // edx
  wchar_t v9; // cx
  _DWORD *result; // eax
  wchar_t Buffer[50]; // [esp+8h] [ebp-68h] BYREF

  v3 = *(this + 157);
  v4 = 0;
  if ( v3 <= 0 )
  {
LABEL_6:
    v6 = 0;
  }
  else
  {
    v5 = *(this + 156);
    while ( *(_DWORD *)(*(_DWORD *)v5 + 44) != 32 || *(_DWORD *)(*(_DWORD *)v5 + 48) != 4 )
    {
      ++v4;
      v5 += 4;
      if ( v4 >= v3 )
        goto LABEL_6;
    }
    v6 = *(_DWORD **)v5;
  }
  if ( a2 || a3 )
  {
    sub_419310(Buffer, (wchar_t *)L"%d Hz", a2 / a3);
  }
  else
  {
    v7 = Buffer;
    v8 = 50;
    while ( v8 != -2147483596 )
    {
      v9 = *(wchar_t *)((char *)v7 + (char *)L"Default Rate" - (char *)Buffer);
      if ( !v9 )
        break;
      *v7++ = v9;
      if ( !--v8 )
      {
        *(v7 - 1) = 0;
        goto LABEL_17;
      }
    }
    *v7 = 0;
  }
LABEL_17:
  result = (_DWORD *)sub_434450(v6, Buffer);
  if ( result == (_DWORD *)-1 )
  {
    result = operator new(8u);
    if ( result )
    {
      *result = a2;
      result[1] = a3;
      return (_DWORD *)sub_434240((int)Buffer, v6, (int)result);
    }
  }
  return result;
}
