void __userpurge sub_429460(_DWORD *a1@<esi>, int a2)
{
  int v2; // ecx
  int v3; // ebp
  int v4; // eax
  int v5; // ebx
  int v6; // ecx
  int v7; // eax
  int v8; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < a1[6]; i = v2 )
  {
    v3 = *(_DWORD *)(a1[5] + 4 * v2);
    v4 = 0;
    v8 = 0;
    if ( (int)a1[9] > 0 )
    {
      do
      {
        v5 = *(_DWORD *)(a1[8] + 4 * v4);
        if ( (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int, _DWORD, int, _DWORD))(**(_DWORD **)(a2 + 4) + 44))(
               *(_DWORD *)(a2 + 4),
               *a1,
               a1[1],
               v3,
               a1[4],
               v5,
               0) < 0
          && sub_42DB00(a1[18] + 1, (int)(a1 + 17)) >= 0 )
        {
          v6 = a1[18];
          v7 = a1[17];
          *(_DWORD *)(v7 + 8 * v6) = v3;
          *(_DWORD *)(v7 + 8 * v6 + 4) = v5;
          ++a1[18];
        }
        v4 = v8 + 1;
        v8 = v4;
      }
      while ( v4 < a1[9] );
      v2 = i;
    }
    ++v2;
  }
}
