int *__usercall sub_4490D0@<eax>(__int16 a1@<ax>, int a2, int *a3, char *Buf, size_t MaxCount, int a6, _DWORD *a7)
{
  _BYTE *v10; // eax
  int v11; // edi
  int *v12; // eax
  char *v13; // ebx
  size_t v14; // ebp
  int *v15; // eax
  int v16; // edx
  int v18; // [esp+10h] [ebp-14h] BYREF
  _DWORD v19[3]; // [esp+18h] [ebp-Ch] BYREF

  while ( 1 )
  {
    v10 = memchr(Buf, 0, MaxCount);
    v11 = v10 ? v10 - Buf : MaxCount;
    v12 = sub_448FF0(Buf, a2, &v18, a6, a7, v11);
    a6 = *v12;
    v13 = &Buf[v11];
    v14 = MaxCount - v11;
    a7 = (_DWORD *)v12[1];
    if ( !v14 )
      break;
    if ( a1 )
    {
      v15 = sub_447710(1, a1, v19, *v12, (_DWORD *)v12[1]);
      a6 = *v15;
      a7 = (_DWORD *)v15[1];
    }
    Buf = v13 + 1;
    MaxCount = v14 - 1;
  }
  v16 = *v12;
  a3[1] = v12[1];
  *a3 = v16;
  return a3;
}
