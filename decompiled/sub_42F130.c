int __userpurge sub_42F130@<eax>(const wchar_t *a1@<eax>, _DWORD *a2, int a3, int a4)
{
  _DWORD *v4; // ebx
  int v5; // esi
  int v7; // ebp
  int v8; // ecx
  const wchar_t *v9; // eax
  size_t v10; // eax
  _WORD *v11; // eax
  _WORD *v12; // esi
  int v14; // edx
  _WORD *v15; // eax
  char *v16; // edi
  __int16 v17; // cx
  _DWORD *v18; // edi
  int v19; // ebp
  _DWORD *v20; // esi
  int v21; // eax
  _DWORD *v22; // esi
  int v23; // eax

  v4 = a2;
  v5 = 0;
  if ( (int)a2[21] <= 0 )
  {
LABEL_11:
    v11 = operator new(0x218u);
    v12 = v11;
    if ( v11 )
    {
      memset(v11, 0, 0x218u);
      v14 = 260;
      v15 = v12;
      v16 = (char *)((char *)a1 - (char *)v12);
      while ( v14 != -2147483386 )
      {
        v17 = *(_WORD *)((char *)v15 + (_DWORD)v16);
        if ( !v17 )
          break;
        *v15++ = v17;
        if ( !--v14 )
        {
          --v15;
          break;
        }
      }
      *v15 = 0;
      *((_DWORD *)v12 + 130) = a3;
      v18 = a2 + 20;
      *((_DWORD *)v12 + 131) = a4;
      if ( sub_42DBC0(a2[21] + 1, (int)(a2 + 20)) >= 0 )
        *(_DWORD *)(*v18 + 4 * a2[21]++) = v12;
      v19 = a2[21];
      if ( a2[15] )
      {
        v20 = *(_DWORD **)(*v18 + 4 * v19 - 4);
        v21 = v20[132];
        if ( v21 )
        {
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v21 + 8))(v20[132]);
          v20[132] = 0;
        }
        D3DXCreateFontW(a2[15], v20[130], 0, v20[131], 1, 0, 1, 0, 0, 0, v20, v20 + 132);
        v4 = a2;
      }
      if ( v4[16] )
      {
        v22 = *(_DWORD **)(*v18 + 4 * v19 - 4);
        v23 = v22[133];
        if ( v23 )
        {
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v23 + 8))(v22[133]);
          v22[133] = 0;
        }
        D3DX10CreateFontW(v4[16], v22[130], 0, v22[131], 1, 0, 1, 0, 0, 0, v22, v22 + 133);
      }
      return v19 - 1;
    }
    else
    {
      return -1;
    }
  }
  else
  {
    while ( 1 )
    {
      v7 = *(_DWORD *)(a2[20] + 4 * v5);
      if ( a1 )
      {
        v8 = 260;
        v9 = a1;
        while ( *v9 )
        {
          ++v9;
          if ( !--v8 )
            goto LABEL_6;
        }
        v10 = 260 - v8;
      }
      else
      {
LABEL_6:
        v10 = 0;
      }
      if ( !_wcsnicmp((const wchar_t *)v7, a1, v10) && *(_DWORD *)(v7 + 520) == a3 && *(_DWORD *)(v7 + 524) == a4 )
        return v5;
      if ( ++v5 >= a2[21] )
        goto LABEL_11;
    }
  }
}
