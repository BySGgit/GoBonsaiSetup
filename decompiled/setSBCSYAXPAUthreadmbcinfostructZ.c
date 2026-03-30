void __usercall setSBCS(_DWORD *a1@<eax>)
{
  _BYTE *v2; // eax
  int v3; // ecx
  int v4; // edi
  _BYTE *v5; // eax
  int v6; // esi

  memset(a1 + 7, 0, 0x101u);
  a1[1] = 0;
  a1[2] = 0;
  a1[3] = 0;
  a1[4] = 0;
  a1[5] = 0;
  a1[6] = 0;
  v2 = a1 + 7;
  v3 = &unk_4C93F8 - (_UNKNOWN *)a1;
  v4 = 257;
  do
  {
    *v2 = v2[v3];
    ++v2;
    --v4;
  }
  while ( v4 );
  v5 = (char *)a1 + 285;
  v6 = 256;
  do
  {
    *v5 = v5[v3];
    ++v5;
    --v6;
  }
  while ( v6 );
}
