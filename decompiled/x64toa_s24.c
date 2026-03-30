int __userpurge x64toa_s@<eax>(char *a1@<edi>, __int64 a2, unsigned int a3, unsigned int a4, int a5)
{
  int *v5; // eax
  int v6; // esi
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rcx
  char *v10; // esi
  char v11; // cl
  unsigned int v12; // ecx
  char *v13; // esi
  char v14; // cl
  unsigned __int64 v15; // [esp-14h] [ebp-24h]
  int v16; // [esp-4h] [ebp-14h]
  int v17; // [esp+Ch] [ebp-4h]
  char *v18; // [esp+28h] [ebp+18h]

  if ( !a1 || !a3 )
    goto LABEL_2;
  *a1 = 0;
  if ( a3 <= (unsigned int)(a5 != 0) + 1 )
  {
    v5 = _errno();
    v16 = 34;
    goto LABEL_3;
  }
  if ( a4 - 2 > 0x22 )
  {
LABEL_2:
    v5 = _errno();
    v16 = 22;
LABEL_3:
    v6 = v16;
    *v5 = v16;
LABEL_4:
    _invalid_parameter_noinfo();
    return v6;
  }
  LODWORD(v8) = HIDWORD(a2);
  HIDWORD(v9) = a2;
  v17 = 0;
  v10 = a1;
  if ( a5 )
  {
    HIDWORD(v9) = -(int)a2;
    *a1 = 45;
    v10 = a1 + 1;
    v17 = 1;
    LODWORD(v8) = (unsigned __int64)-a2 >> 32;
  }
  v18 = v10;
  while ( 1 )
  {
    v15 = __PAIR64__(v8, HIDWORD(v9));
    v9 = __PAIR64__(v8, HIDWORD(v9)) % a4;
    v8 = v15 / a4;
    HIDWORD(v9) = v8;
    LODWORD(v8) = HIDWORD(v8);
    v11 = (unsigned int)v9 <= 9 ? v9 + 48 : (unsigned __int8)v9 + 87;
    *v10++ = v11;
    v12 = ++v17;
    if ( !HIDWORD(v8) && !HIDWORD(v9) )
      break;
    if ( v12 >= a3 )
    {
      v12 = v17;
      break;
    }
  }
  if ( v12 >= a3 )
  {
    *a1 = 0;
    *_errno() = 34;
    v6 = 34;
    goto LABEL_4;
  }
  *v10 = 0;
  v13 = v10 - 1;
  do
  {
    v14 = *v13;
    *v13-- = *v18;
    *v18++ = v14;
  }
  while ( v18 < v13 );
  return 0;
}
