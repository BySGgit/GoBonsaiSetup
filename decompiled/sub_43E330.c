int __userpurge sub_43E330@<eax>(int a1@<eax>, int a2)
{
  int v2; // esi
  int v3; // ecx
  int v4; // edx
  _DWORD *v5; // esi
  const unsigned __int16 *v6; // edi
  int result; // eax

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
    while ( *(_DWORD *)(*(_DWORD *)v4 + 44) != 17 || *(_DWORD *)(*(_DWORD *)v4 + 48) != 4 )
    {
      ++v3;
      v4 += 4;
      if ( v3 >= v2 )
        goto LABEL_6;
    }
    v5 = *(_DWORD **)v4;
  }
  v6 = sub_43EE70(a2);
  result = sub_434450(v5, v6);
  if ( result == -1 )
    return sub_434240((int)v6, v5, a2);
  return result;
}
