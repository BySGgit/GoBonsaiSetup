void __userpurge sub_44E5D0(_DWORD *a1@<edi>, _DWORD *a2, _DWORD *a3, float a4)
{
  _DWORD *v4; // ebp
  char *v5; // eax
  int v6; // esi
  char *v7; // ebx
  _DWORD *v8; // eax

  v4 = a3;
  if ( a4 >= 0.0 && dword_4D8B78 )
  {
    v5 = (char *)*((_DWORD *)dword_4D8B74 + 1);
    v6 = *((_DWORD *)v5 + 2);
    a3 = (_DWORD *)v6;
    if ( v5 != dword_4D8B74 )
    {
      **((_DWORD **)v5 + 1) = *(_DWORD *)v5;
      *(_DWORD *)(*(_DWORD *)v5 + 4) = *((_DWORD *)v5 + 1);
      operator delete(v5);
      --dword_4D8B78;
    }
    v7 = dword_4D8B68;
    v8 = sub_40FD70(dword_4D8B68, *((_DWORD *)dword_4D8B68 + 1), &a3);
    if ( dword_4D8B6C == 1073741822 )
      std::_Xlength_error("list<T> too long");
    ++dword_4D8B6C;
    *((_DWORD *)v7 + 1) = v8;
    *(_DWORD *)v8[1] = v8;
    *(_DWORD *)v6 = *a2;
    *(_DWORD *)(v6 + 4) = a2[1];
    *(_DWORD *)(v6 + 8) = a2[2];
    *(_DWORD *)(v6 + 12) = *v4;
    *(_DWORD *)(v6 + 16) = v4[1];
    *(_DWORD *)(v6 + 20) = v4[2];
    *(_DWORD *)(v6 + 24) = *a1;
    *(_DWORD *)(v6 + 28) = a1[1];
    *(_DWORD *)(v6 + 32) = a1[2];
    *(_DWORD *)(v6 + 36) = a1[3];
    *(float *)(v6 + 40) = flt_4D8B4C + a4;
  }
}
