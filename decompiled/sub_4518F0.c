int __usercall sub_4518F0@<eax>(int a1@<eax>, char *a2@<edi>, unsigned __int8 (__cdecl *a3)(int, int))
{
  int v4; // ecx
  int result; // eax
  char *v6; // esi
  int v7; // edx
  int v8; // eax
  int v9; // edx
  _DWORD v10[3]; // [esp+8h] [ebp-Ch] BYREF

  v4 = a1 - (_DWORD)a2;
  result = (a1 - (int)a2) / 12;
  if ( result > 1 )
  {
    v6 = (char *)(a1 - 12);
    do
    {
      v7 = *(_DWORD *)v6;
      v10[1] = *((_DWORD *)v6 + 1);
      v8 = *(_DWORD *)a2;
      v10[0] = v7;
      v9 = *((_DWORD *)v6 + 2);
      *(_DWORD *)v6 = v8;
      v10[2] = v9;
      *((_DWORD *)v6 + 1) = *((_DWORD *)a2 + 1);
      *((_DWORD *)v6 + 2) = *((_DWORD *)a2 + 2);
      sub_451B10(0, (int)a2, (v4 - 12) / 12, v10, a3);
      v6 -= 12;
      v4 = v6 - a2 + 12;
      result = v4 / 12;
    }
    while ( v4 / 12 > 1 );
  }
  return result;
}
