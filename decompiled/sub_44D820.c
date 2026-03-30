int __usercall sub_44D820@<eax>(int **a1@<eax>)
{
  int *v2; // ecx
  int *v3; // esi
  unsigned __int16 *v4; // eax
  int *v6; // edx
  int *v7; // eax
  __int16 *v8; // ecx
  __int16 v9; // ax
  int *v10; // eax

  if ( !*a1[8] )
    goto LABEL_6;
  v2 = a1[12];
  if ( *v2 > 1 )
  {
    --*v2;
    v3 = a1[8];
    v4 = (unsigned __int16 *)(*v3 + 2);
    *v3 = (int)v4;
    return *v4;
  }
  v6 = a1[12];
  if ( *v6 > 0 )
  {
    --*v6;
    v7 = a1[8];
    v8 = (__int16 *)*v7;
    *v7 += 2;
    v9 = *v8;
  }
  else
  {
LABEL_6:
    v9 = ((int (__thiscall *)(int **))(*a1)[7])(a1);
  }
  if ( v9 == -1 )
    return 0xFFFF;
  v10 = a1[8];
  if ( *v10 && *a1[12] > 0 )
    return *(unsigned __int16 *)*v10;
  else
    return ((unsigned __int16 (__thiscall *)(int **))(*a1)[6])(a1);
}
