void __cdecl sub_451320(int *a1, int *a2, int a3, unsigned __int8 (*a4)(void))
{
  int *v4; // ebx
  int *v5; // edi
  int v6; // eax
  int *v8; // ebp
  int *v9; // [esp+10h] [ebp-Ch] BYREF
  int *v10; // [esp+14h] [ebp-8h]

  v4 = a2;
  v5 = a1;
  v6 = ((char *)a2 - (char *)a1) / 12;
  if ( v6 <= 32 )
  {
LABEL_7:
    if ( v6 > 1 && v5 != v4 )
      sub_451990(v5, v4, (unsigned __int8 (__cdecl *)(int *, _DWORD *))a4);
  }
  else
  {
    while ( a3 > 0 )
    {
      sub_451460(&v9, v5, v4, a4);
      v8 = v10;
      a3 = a3 / 2 / 2 + a3 / 2;
      if ( ((char *)v9 - (char *)v5) / 12 >= ((char *)v4 - (char *)v10) / 12 )
      {
        sub_451320(v10, v4, a3, a4);
        v4 = v9;
      }
      else
      {
        sub_451320(v5, v9, a3, a4);
        v5 = v8;
      }
      v6 = ((char *)v4 - (char *)v5) / 12;
      if ( v6 <= 32 )
        goto LABEL_7;
    }
    if ( ((char *)v4 - (char *)v5) / 12 > 1 )
      sub_4517D0((int)v4, (int)v5, (unsigned __int8 (__cdecl *)(_DWORD *, _DWORD *))a4);
    sub_4518F0((int)v4, (char *)v5, (unsigned __int8 (__cdecl *)(int, int))a4);
  }
}
