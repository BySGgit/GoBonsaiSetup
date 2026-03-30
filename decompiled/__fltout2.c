_DWORD *__cdecl _fltout2(int a1, int a2, _DWORD *a3, char *a4, rsize_t SizeInBytes)
{
  _DWORD *v5; // ebx
  int v6; // eax
  char *v7; // esi
  int v9[2]; // [esp+Ch] [ebp-30h] BYREF
  __int16 v10; // [esp+14h] [ebp-28h]
  char *Destination; // [esp+18h] [ebp-24h]
  __int16 v12; // [esp+1Ch] [ebp-20h] BYREF
  char v13; // [esp+1Eh] [ebp-1Eh]
  char Source[24]; // [esp+20h] [ebp-1Ch] BYREF

  v5 = a3;
  Destination = a4;
  __dtold(v9, &a1);
  v6 = _I10_OUTPUT(v9[0], v9[1], v10, 17, 0, &v12);
  v7 = Destination;
  v5[2] = v6;
  *v5 = v13;
  v5[1] = v12;
  if ( strcpy_s(v7, SizeInBytes, Source) )
    _invoke_watson(0, 0, 0, 0, 0);
  v5[3] = v7;
  return v5;
}
