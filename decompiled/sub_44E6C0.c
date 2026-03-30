void __stdcall sub_44E6C0(int a1)
{
  int v1; // ecx
  _DWORD *v2; // esi
  double v3; // st7
  _DWORD *v4; // edi
  char *v5; // edi
  _DWORD *v6; // eax
  char *v7; // ecx
  char *v8; // esi
  double v9; // st7
  char *v10; // edi
  char *v11; // edi
  _DWORD *v12; // eax

  if ( byte_4CA648 )
  {
    v1 = dword_4D8B50;
    flt_4D8B4C = flt_4D8B4C + *(float *)&a1;
    v2 = *(_DWORD **)dword_4D8B50;
    while ( v2 != (_DWORD *)v1 )
    {
      v3 = *(float *)(v2[2] + 28);
      a1 = v2[2];
      if ( flt_4D8B4C <= v3 )
      {
        v2 = (_DWORD *)*v2;
      }
      else
      {
        v4 = (_DWORD *)*v2;
        if ( v2 != (_DWORD *)v1 )
        {
          *(_DWORD *)v2[1] = v4;
          *(_DWORD *)(*v2 + 4) = v2[1];
          operator delete(v2);
          --dword_4D8B54;
        }
        v2 = v4;
        v5 = dword_4D8B5C;
        v6 = sub_40FD70(dword_4D8B5C, *((_DWORD *)dword_4D8B5C + 1), &a1);
        if ( 1073741822 == dword_4D8B60 )
LABEL_16:
          std::_Xlength_error("list<T> too long");
        ++dword_4D8B60;
        *((_DWORD *)v5 + 1) = v6;
        *(_DWORD *)v6[1] = v6;
        v1 = dword_4D8B50;
      }
    }
    v7 = dword_4D8B68;
    v8 = *(char **)dword_4D8B68;
    while ( v8 != v7 )
    {
      v9 = *(float *)(*((_DWORD *)v8 + 2) + 40);
      a1 = *((int *)v8 + 2);
      if ( flt_4D8B4C <= v9 )
      {
        v8 = *(char **)v8;
      }
      else
      {
        v10 = *(char **)v8;
        if ( v8 != v7 )
        {
          **((_DWORD **)v8 + 1) = v10;
          *(_DWORD *)(*(_DWORD *)v8 + 4) = *((_DWORD *)v8 + 1);
          operator delete(v8);
          --dword_4D8B6C;
        }
        v8 = v10;
        v11 = dword_4D8B74;
        v12 = sub_40FD70(dword_4D8B74, *((_DWORD *)dword_4D8B74 + 1), &a1);
        if ( 1073741822 == dword_4D8B78 )
          goto LABEL_16;
        ++dword_4D8B78;
        *((_DWORD *)v11 + 1) = v12;
        *(_DWORD *)v12[1] = v12;
        v7 = dword_4D8B68;
      }
    }
  }
}
