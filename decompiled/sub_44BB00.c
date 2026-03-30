int __usercall sub_44BB00@<eax>(int *a1@<edi>, int *a2@<esi>)
{
  int v2; // ecx
  __int16 **v3; // eax
  __int16 v4; // ax
  int v5; // ecx
  __int16 **v6; // eax
  __int16 v7; // ax

  if ( !*((_BYTE *)a2 + 4) )
  {
    v2 = *a2;
    if ( !*a2
      || ((v3 = *(__int16 ***)(v2 + 32), !*v3) || **(int **)(v2 + 48) <= 0
        ? (v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 24))(v2))
        : (v4 = **v3),
          v4 == -1) )
    {
      *a2 = 0;
    }
    else
    {
      *((_WORD *)a2 + 3) = v4;
    }
    *((_BYTE *)a2 + 4) = 1;
  }
  if ( !*((_BYTE *)a1 + 4) )
  {
    v5 = *a1;
    if ( !*a1
      || ((v6 = *(__int16 ***)(v5 + 32), !*v6) || **(int **)(v5 + 48) <= 0
        ? (v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 24))(v5))
        : (v7 = **v6),
          v7 == -1) )
    {
      *a1 = 0;
    }
    else
    {
      *((_WORD *)a1 + 3) = v7;
    }
    *((_BYTE *)a1 + 4) = 1;
  }
  if ( *a2 )
  {
    if ( !*a1 )
      return 0;
  }
  else if ( *a1 )
  {
    return 0;
  }
  return 1;
}
