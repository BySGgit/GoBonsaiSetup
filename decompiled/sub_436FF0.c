char __userpurge sub_436FF0@<al>(int a1@<eax>, int a2, int *a3)
{
  int v4; // eax
  int v5; // ebp
  int v6; // edi
  int v7; // eax

  *a3 = a2;
  if ( !*(_BYTE *)(a1 + 12) || (v4 = sub_436B30(a1), v4 >= 0) )
  {
    v4 = off_4D5258[0](*(_DWORD *)(a1 + 16));
    v5 = v4;
    if ( v4 )
    {
      v4 = off_4D525C(*(_DWORD *)(a1 + 16));
      if ( v4 )
      {
        v6 = *(_DWORD *)off_4D525C(*(_DWORD *)(a1 + 16));
        if ( a2 + 1 < v6 )
          v6 = a2 + 1;
        v7 = *(_DWORD *)off_4D525C(*(_DWORD *)(a1 + 16));
        if ( v7 > 0 )
        {
          while ( v6 < v7 - 1 )
          {
            LOBYTE(v4) = *(_BYTE *)(v6 + v5);
            if ( (v4 & 8) != 0 )
            {
              *a3 = v6;
              LOBYTE(v4) = (_BYTE)a3;
              return v4;
            }
            if ( (v4 & 2) != 0 && (*(_BYTE *)(v6 + v5 + 1) & 2) == 0 )
            {
              *a3 = v6 + 1;
              return v4;
            }
            ++v6;
            v7 = *(_DWORD *)off_4D525C(*(_DWORD *)(a1 + 16));
            if ( v7 <= 0 )
              break;
          }
        }
        v4 = *(_DWORD *)off_4D525C(*(_DWORD *)(a1 + 16)) - 1;
        *a3 = v4;
      }
    }
  }
  return v4;
}
