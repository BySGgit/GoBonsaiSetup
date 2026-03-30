void sub_40E0A0()
{
  int v0; // esi
  _DWORD *i; // edi
  _DWORD *v2; // esi
  int v3; // ecx
  char *v4; // esi
  _DWORD *v5; // eax
  int v6; // edi
  char *v7; // eax
  int v8; // [esp+Ch] [ebp-14h] BYREF
  int v9; // [esp+10h] [ebp-10h] BYREF
  int v10; // [esp+1Ch] [ebp-4h]

  v0 = dword_4D7EE8;
  if ( dword_4D8670 )
  {
    v8 = *(_DWORD *)(*((_DWORD *)dword_4D866C + 1) + 8);
    sub_451210(&v9, (unsigned int *)&v8);
    if ( v9 == dword_4D8C10 )
      v6 = 0;
    else
      v6 = *(_DWORD *)(v9 + 12);
    v7 = (char *)*((_DWORD *)dword_4D866C + 1);
    if ( v7 != dword_4D866C )
    {
      **((_DWORD **)v7 + 1) = *(_DWORD *)v7;
      *(_DWORD *)(*(_DWORD *)v7 + 4) = *((_DWORD *)v7 + 1);
      operator delete(v7);
      --dword_4D8670;
    }
    if ( v6 && *(_DWORD *)(v6 + 180) )
      sub_40E230((float *)v6, v0);
  }
  else
  {
    for ( i = *(_DWORD **)dword_4D8C10; i != (_DWORD *)dword_4D8C10; i = (_DWORD *)*i )
    {
      v2 = (_DWORD *)i[3];
      if ( v2 )
      {
        if ( (dword_4D7CF8 & 1) == 0 )
        {
          dword_4D7CF8 |= 1u;
          v10 = 0;
          sub_4079C0();
          v10 = -1;
        }
        if ( byte_4D8225[11 * v2[1]] && v2[45] )
        {
          v3 = v2[46];
          v4 = dword_4D866C + 4;
          v8 = v3;
          v5 = sub_40FD70(dword_4D866C, *((_DWORD *)dword_4D866C + 1), &v8);
          if ( dword_4D8670 == 1073741822 )
            std::_Xlength_error("list<T> too long");
          ++dword_4D8670;
          *(_DWORD *)v4 = v5;
          *(_DWORD *)v5[1] = v5;
        }
      }
    }
  }
}
