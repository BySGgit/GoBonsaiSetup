int __usercall sub_4517D0@<eax>(int a1@<eax>, int a2, unsigned __int8 (__cdecl *a3)(_DWORD *, _DWORD *))
{
  int v4; // ebx
  int result; // eax
  int v6; // esi
  int i; // ecx
  int v8; // edx
  int v9; // ecx
  int v10; // eax
  int v11; // esi
  int v12; // edx
  int v13; // ecx
  int v14; // edi
  bool v15; // zf
  _DWORD *v16; // eax
  _DWORD *v17; // ecx
  _DWORD *v18; // ecx
  _DWORD *v19; // edx
  int v20; // [esp+8h] [ebp-14h]
  int v21; // [esp+Ch] [ebp-10h]
  _DWORD v22[3]; // [esp+10h] [ebp-Ch] BYREF
  int v23; // [esp+20h] [ebp+4h]

  v4 = (a1 - a2) / 12;
  result = v4 / 2;
  if ( v4 / 2 > 0 )
  {
    v6 = 2 * result + 2;
    for ( i = a2 + 12 * result; ; i = v20 )
    {
      v8 = *(_DWORD *)(i - 12);
      v9 = i - 12;
      v10 = result - 1;
      v11 = v6 - 2;
      v22[0] = v8;
      v12 = *(_DWORD *)(v9 + 4);
      v20 = v9;
      v13 = *(_DWORD *)(v9 + 8);
      v23 = v10;
      v21 = v11;
      v22[1] = v12;
      v22[2] = v13;
      v14 = v10;
      v15 = v11 == v4;
      if ( v11 < v4 )
      {
        do
        {
          if ( a3((_DWORD *)(a2 + 12 * v11), (_DWORD *)(a2 + 12 * v11 - 12)) )
            --v11;
          v16 = (_DWORD *)(a2 + 12 * v11);
          v17 = (_DWORD *)(a2 + 12 * v14);
          *v17 = *v16;
          v17[1] = v16[1];
          v14 = v11;
          v11 = 2 * v11 + 2;
          v17[2] = v16[2];
          v15 = v11 == v4;
        }
        while ( v11 < v4 );
        v10 = v23;
      }
      if ( v15 )
      {
        v18 = (_DWORD *)(a2 + 12 * v4 - 12);
        v19 = (_DWORD *)(a2 + 12 * v14);
        *v19 = *v18;
        v19[1] = v18[1];
        v19[2] = v18[2];
        v14 = v4 - 1;
      }
      result = sub_451C10(v14, a2, v10, v22, a3);
      if ( v23 <= 0 )
        break;
      v6 = v21;
      result = v23;
    }
  }
  return result;
}
