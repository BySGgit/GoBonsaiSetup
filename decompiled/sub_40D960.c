int __usercall sub_40D960@<eax>(int a1@<edi>)
{
  _DWORD *v1; // ebp
  _DWORD *v2; // esi
  _DWORD *v3; // ecx
  _DWORD *v4; // esi
  int v5; // ecx
  _DWORD *v6; // ecx
  int v7; // esi
  void **v8; // edx
  void **v9; // eax
  void *v10; // eax
  int v11; // eax
  float *v12; // esi
  int v14; // [esp+14h] [ebp-10h]

  if ( *(_DWORD *)(a1 + 240) )
  {
    v1 = *(_DWORD **)dword_4D8C10;
    for ( flt_4D52D4 = 10.0; v1 != (_DWORD *)dword_4D8C10; v1 = (_DWORD *)*v1 )
    {
      v2 = (_DWORD *)v1[3];
      if ( v2 )
      {
        if ( (dword_4D7CF8 & 1) == 0 )
        {
          dword_4D7CF8 |= 1u;
          sub_4079C0();
        }
        if ( byte_4D8225[11 * v2[1]] && v2[45] && (double)rand() / 32767.0 < 0.300000011920929 )
          (*(void (__thiscall **)(_DWORD *))(*v2 + 44))(v2);
      }
    }
    v3 = *(_DWORD **)(*(_DWORD *)(a1 + 240) + 168);
    v4 = (_DWORD *)*v3;
    if ( (_DWORD *)*v3 != v3 )
    {
      do
      {
        v5 = v4[2];
        v4 = (_DWORD *)*v4;
        (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 44))(v5);
      }
      while ( v4 != *(_DWORD **)(*(_DWORD *)(a1 + 240) + 168) );
    }
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a1 + 240) + 48))(*(_DWORD *)(a1 + 240));
    v6 = *(_DWORD **)(a1 + 240);
    flt_4D52D4 = 1.0;
    v7 = v6[45];
    if ( v7 )
    {
      v8 = *(void ***)(v7 + 168);
      v9 = (void **)*v8;
      if ( *v8 != v8 )
      {
        while ( v9[2] != v6 )
        {
          v9 = (void **)*v9;
          if ( v9 == v8 )
            goto LABEL_20;
        }
        v6[45] = 0;
        if ( v9 != *(void ***)(v7 + 168) )
        {
          *(_DWORD *)v9[1] = *v9;
          *((_DWORD *)*v9 + 1) = v9[1];
          operator delete(v9);
          --*(_DWORD *)(v7 + 172);
        }
      }
    }
LABEL_20:
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a1 + 240) + 8))(*(_DWORD *)(a1 + 240));
  }
  v10 = operator new(0x200u);
  if ( v10 )
    v11 = sub_417220((int)v10, a1);
  else
    v11 = 0;
  *(_DWORD *)(a1 + 240) = v11;
  v14 = rand();
  v12 = *(float **)(a1 + 236);
  *(_DWORD *)(a1 + 200) = 0;
  *(_BYTE *)(a1 + 220) = 0;
  *(float *)(a1 + 196) = (double)v14 / 32767.0 * 40.0 + 40.0;
  *(float *)(a1 + 216) = 0.0;
  return sub_408880(v12);
}
