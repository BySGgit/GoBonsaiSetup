int __userpurge sub_435650@<eax>(int a1@<eax>, _DWORD *a2)
{
  _DWORD *v2; // ebx
  int v3; // ebp
  int v5; // esi
  bool v6; // zf
  int result; // eax
  int v8; // ecx
  int v9; // ebp
  int v10; // edi
  int v11; // [esp+10h] [ebp-14h] BYREF
  int v12; // [esp+14h] [ebp-10h] BYREF
  int v13; // [esp+18h] [ebp-Ch] BYREF
  int v14; // [esp+1Ch] [ebp-8h] BYREF
  int v15; // [esp+20h] [ebp-4h] BYREF

  v2 = a2;
  v3 = a2[76];
  v5 = (int)(a2 + 20);
  a2[73] = a1;
  v6 = *(_BYTE *)(v5 + 12) == 0;
  v13 = 0;
  if ( v6 || sub_436B30(v5) >= 0 )
    off_4D524C[0](*(_DWORD *)(v5 + 16), v3, 0, (int)&v13);
  v6 = *(_BYTE *)(v5 + 12) == 0;
  v11 = 0;
  if ( v6 || sub_436B30(v5) >= 0 )
    off_4D524C[0](*(_DWORD *)(v5 + 16), a1, 0, (int)&v11);
  result = lstrlenW(*(LPCWSTR *)v5);
  if ( a1 == result )
  {
    v12 = v11;
  }
  else
  {
    v6 = *(_BYTE *)(v5 + 12) == 0;
    v12 = 0;
    if ( v6 || (result = sub_436B30(v5), result >= 0) )
      result = off_4D524C[0](*(_DWORD *)(v5 + 16), a1, 1, (int)&v12);
  }
  if ( v11 >= v13 )
  {
    v8 = v2[29];
    result = v2[27];
    if ( v12 > v13 + v8 - result )
    {
      v9 = v12 + result - v8;
      sub_436ED0(v5, (int *)&a2, v9, &v15);
      v6 = *(_BYTE *)(v5 + 12) == 0;
      v10 = (int)a2;
      v14 = 0;
      if ( v6 || (result = sub_436B30(v5), result >= 0) )
        result = off_4D524C[0](*(_DWORD *)(v5 + 16), v10, 0, (int)&v14);
      if ( v14 < v9 )
        a2 = (_DWORD *)((char *)a2 + 1);
      v2[76] = a2;
    }
  }
  else
  {
    v2[76] = a1;
  }
  return result;
}
