int __usercall sub_44A230@<eax>(int a1@<esi>)
{
  _DWORD **v1; // ecx
  int *v2; // edx
  __int16 **v3; // ecx
  __int16 *v4; // eax
  __int16 v5; // ax

  v1 = *(_DWORD ***)a1;
  if ( !*(_DWORD *)a1
    || (!*v1[8] || (v2 = v1[12], *v2 <= 0)
      ? (v5 = ((int (__thiscall *)(_DWORD **))(*v1)[7])(v1))
      : (--*v2, v3 = (__int16 **)v1[8], v4 = *v3, ++*v3, v5 = *v4),
        v5 == -1) )
  {
    *(_DWORD *)a1 = 0;
    *(_BYTE *)(a1 + 4) = 1;
    return a1;
  }
  else
  {
    *(_BYTE *)(a1 + 4) = 0;
    return a1;
  }
}
