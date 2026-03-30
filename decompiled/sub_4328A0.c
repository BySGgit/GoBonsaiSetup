int __usercall sub_4328A0@<eax>(int a1@<eax>, int a2@<ecx>)
{
  _WORD *v3; // eax
  int v4; // edx
  int v5; // esi
  __int16 v6; // cx

  if ( a2 )
  {
    v3 = (_WORD *)(a1 + 80);
    v4 = 260;
    v5 = a2 - (_DWORD)v3;
    while ( v4 != -2147483386 )
    {
      v6 = *(_WORD *)((char *)v3 + v5);
      if ( !v6 )
        break;
      *v3++ = v6;
      if ( !--v4 )
      {
        *(v3 - 1) = 0;
        return 0;
      }
    }
    *v3 = 0;
    return 0;
  }
  else
  {
    *(_WORD *)(a1 + 80) = 0;
    return 0;
  }
}
