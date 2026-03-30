int sub_450F00()
{
  int result; // eax
  int *v1; // ebp
  int v2; // esi
  int v3; // edi
  void **v4; // ecx
  void **v5; // eax
  int v6; // [esp+10h] [ebp-4h] BYREF

  result = dword_4D8C10;
  v1 = *(int **)dword_4D8C10;
  while ( v1 != (int *)result )
  {
    v2 = v1[3];
    if ( *(_BYTE *)(v2 + 188) )
    {
      v3 = *(_DWORD *)(v2 + 180);
      if ( v3 )
      {
        v4 = *(void ***)(v3 + 168);
        v5 = (void **)*v4;
        if ( *v4 != v4 )
        {
          while ( v5[2] != (void *)v2 )
          {
            v5 = (void **)*v5;
            if ( v5 == v4 )
              goto LABEL_10;
          }
          *(_DWORD *)(v2 + 180) = 0;
          if ( v5 != *(void ***)(v3 + 168) )
          {
            *(_DWORD *)v5[1] = *v5;
            *((_DWORD *)*v5 + 1) = v5[1];
            operator delete(v5);
            --*(_DWORD *)(v3 + 172);
          }
        }
      }
LABEL_10:
      v1 = (int *)*sub_451040(&v6, v1);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v2 + 4))(v2, 1);
      result = dword_4D8C10;
    }
    else
    {
      v1 = (int *)*v1;
    }
  }
  dword_4D82AC = 0;
  return result;
}
