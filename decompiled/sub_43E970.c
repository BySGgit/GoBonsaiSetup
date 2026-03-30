int __userpurge sub_43E970@<eax>(int a1@<eax>, int a2)
{
  int v2; // esi
  int v3; // ecx
  int v4; // edx
  _DWORD *v5; // eax

  v2 = *(_DWORD *)(a1 + 628);
  v3 = 0;
  if ( v2 <= 0 )
  {
LABEL_6:
    v5 = 0;
  }
  else
  {
    v4 = *(_DWORD *)(a1 + 624);
    while ( 1 )
    {
      v5 = *(_DWORD **)v4;
      if ( *(_DWORD *)(*(_DWORD *)v4 + 44) == 25 && v5[12] == 2 )
        break;
      ++v3;
      v4 += 4;
      if ( v3 >= v2 )
        goto LABEL_6;
    }
  }
  return (*(int (__thiscall **)(_DWORD *, int, _DWORD))(*v5 + 80))(v5, a2, 0);
}
