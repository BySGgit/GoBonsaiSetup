int __thiscall sub_429000(_DWORD *this, unsigned int a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *v4; // eax
  int v6; // ecx
  unsigned int v7; // eax
  int v8; // esi
  unsigned __int8 (__stdcall *v9)(_DWORD *, int, int, bool, _DWORD); // eax
  _DWORD *v10; // esi
  int v11; // eax
  _DWORD *v12; // edi
  int v14; // [esp+48h] [ebp-3Ch]
  int v15; // [esp+50h] [ebp-34h]
  int v16; // [esp+54h] [ebp-30h]
  _DWORD *v17; // [esp+58h] [ebp-2Ch]
  int i; // [esp+5Ch] [ebp-28h]
  unsigned int v19; // [esp+60h] [ebp-24h]
  _DWORD v20[6]; // [esp+68h] [ebp-1Ch]

  v4 = a4;
  v6 = 0;
  v17 = this;
  v20[0] = 21;
  v20[1] = 22;
  v20[2] = 35;
  v20[3] = 23;
  v20[4] = 25;
  v20[5] = 24;
  for ( i = 0; v6 < a4[1]; i = v6 )
  {
    v15 = *(_DWORD *)(*v4 + 4 * v6);
    v7 = 0;
    v19 = 0;
    while ( 2 )
    {
      v8 = 0;
      v16 = v20[v7];
      v14 = 0;
      do
      {
        if ( (v8 || a3[405])
          && (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int, int, int))(**(_DWORD **)(a2 + 4) + 36))(
               *(_DWORD *)(a2 + 4),
               *a3,
               *(this + 1),
               v15,
               v16,
               v8) >= 0
          && (!*(_BYTE *)(a2 + 16)
           || (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int, int, int, int))(**(_DWORD **)(a2 + 4) + 40))(
                *(_DWORD *)(a2 + 4),
                *a3,
                *(this + 1),
                v15,
                0x80000,
                3,
                v16) >= 0) )
        {
          v9 = *(unsigned __int8 (__stdcall **)(_DWORD *, int, int, bool, _DWORD))(a2 + 8);
          if ( !v9 || v9(this + 2, v15, v16, v8 != 0, *(_DWORD *)(a2 + 12)) )
          {
            v10 = operator new(0x58u);
            if ( !v10 )
              return -2147024882;
            v10[5] = 0;
            v10[6] = 0;
            v10[7] = 0;
            v10[8] = 0;
            v10[9] = 0;
            v10[10] = 0;
            v10[11] = 0;
            v10[12] = 0;
            v10[13] = 0;
            v10[14] = 0;
            v10[15] = 0;
            v10[16] = 0;
            v10[17] = 0;
            v10[18] = 0;
            v10[19] = 0;
            *v10 = *a3;
            v10[1] = *(this + 1);
            v10[2] = v15;
            v10[3] = v16;
            v10[4] = v14 != 0;
            sub_429330(v10, a2);
            sub_4293C0(v10, a2);
            if ( v10[9] )
            {
              sub_429460(v10, a2);
              sub_4294F0(a2, (int)this, v10);
              v10[21] = this;
              v10[20] = a3;
              v11 = *(this + 79);
              v12 = this + 78;
              if ( sub_42DBC0(v11 + 1, (int)v12) < 0 )
              {
                sub_429270((int)v10);
                operator delete(v10);
              }
              else
              {
                *(_DWORD *)(*v12 + 4 * v12[1]++) = v10;
              }
              this = v17;
            }
            else
            {
              sub_429270((int)v10);
              operator delete(v10);
            }
            v8 = v14;
          }
        }
        v14 = ++v8;
      }
      while ( v8 < 2 );
      v7 = v19 + 1;
      v19 = v7;
      if ( v7 < 6 )
        continue;
      break;
    }
    v4 = a4;
    v6 = i + 1;
  }
  return 0;
}
