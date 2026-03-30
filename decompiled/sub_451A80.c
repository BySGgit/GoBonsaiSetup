int __usercall sub_451A80@<eax>(int *a1@<edi>, int *a2@<esi>, int *a3, unsigned __int8 (*a4)(void))
{
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  int result; // eax
  int v11; // ecx
  int v12; // edx

  if ( a4() )
  {
    v4 = *a2;
    v5 = a2[1];
    v6 = a2[2];
    *a2 = *a1;
    a2[1] = a1[1];
    a2[2] = a1[2];
    *a1 = v4;
    a1[1] = v5;
    a1[2] = v6;
  }
  if ( ((unsigned __int8 (__cdecl *)(int *, int *))a4)(a3, a2) )
  {
    v7 = *a3;
    v8 = a3[1];
    v9 = a3[2];
    *a3 = *a2;
    a3[1] = a2[1];
    a3[2] = a2[2];
    *a2 = v7;
    a2[1] = v8;
    a2[2] = v9;
  }
  result = ((int (__cdecl *)(int *, int *))a4)(a2, a1);
  if ( (_BYTE)result )
  {
    result = *a2;
    v11 = a2[1];
    v12 = a2[2];
    *a2 = *a1;
    a2[1] = a1[1];
    a2[2] = a1[2];
    *a1 = result;
    a1[1] = v11;
    a1[2] = v12;
  }
  return result;
}
