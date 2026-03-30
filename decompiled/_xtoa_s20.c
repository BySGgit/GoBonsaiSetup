int __userpurge xtoa_s@<eax>(unsigned int a1@<eax>, _BYTE *a2@<ecx>, unsigned int a3, unsigned int a4, int a5)
{
  _BYTE *v5; // esi
  unsigned int v6; // ebx
  int *v8; // eax
  char *v9; // edi
  char v10; // dl
  unsigned int v11; // et2
  char v12; // dl
  char *v13; // ecx
  char v14; // al
  int v15; // [esp-8h] [ebp-10h]

  v5 = a2;
  v6 = 0;
  if ( !a2 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  if ( !a3 )
    goto LABEL_4;
  *a2 = 0;
  if ( a3 <= (unsigned int)(a5 != 0) + 1 )
  {
LABEL_7:
    v8 = _errno();
    v15 = 34;
    goto LABEL_5;
  }
  if ( a4 - 2 > 0x22 )
  {
LABEL_4:
    v8 = _errno();
    v15 = 22;
LABEL_5:
    *v8 = v15;
    _invalid_parameter_noinfo();
    return v15;
  }
  if ( a5 )
  {
    v6 = 1;
    *a2++ = 45;
    a1 = -a1;
  }
  v9 = a2;
  do
  {
    v11 = a1 % a4;
    a1 /= a4;
    v10 = v11;
    if ( v11 <= 9 )
      v12 = v10 + 48;
    else
      v12 = v10 + 87;
    *a2++ = v12;
    ++v6;
  }
  while ( a1 && v6 < a3 );
  if ( v6 >= a3 )
  {
    *v5 = 0;
    goto LABEL_7;
  }
  *a2 = 0;
  v13 = a2 - 1;
  do
  {
    v14 = *v13;
    *v13-- = *v9;
    *v9++ = v14;
  }
  while ( v9 < v13 );
  return 0;
}
