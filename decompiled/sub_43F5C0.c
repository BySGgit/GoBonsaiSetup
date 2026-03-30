int __userpurge sub_43F5C0@<eax>(float *a1@<esi>, int a2, char a3)
{
  int result; // eax
  double v4; // st4
  double v5; // st7
  int v6; // edx
  int v7; // ecx
  double v8; // rtt
  double v9; // st4
  double v10; // st7
  double v11; // rt0
  int v12; // eax
  int v13; // [esp+18h] [ebp-1Ch]
  struct tagRECT rc; // [esp+1Ch] [ebp-18h] BYREF

  if ( !*(_DWORD *)a1 && !*((_DWORD *)a1 + 2) )
    return -2147024809;
  SetRect(&rc, *((_DWORD *)a1 + 8), *((_DWORD *)a1 + 9), 0, 0);
  if ( *(_DWORD *)a1 )
  {
    if ( a1[4] < 1.0 )
    {
      if ( a1[4] > 0.0 )
        v13 = (__int64)(a1[4] * 255.0 + 0.5);
      else
        v13 = 0;
    }
    else
    {
      v13 = 255;
    }
    v4 = 1.0;
    v5 = 0.0;
    if ( a1[5] < 1.0 )
    {
      if ( a1[5] > 0.0 )
        v6 = (__int64)(a1[5] * 255.0 + 0.5);
      else
        v6 = 0;
      v4 = 1.0;
      v5 = 0.0;
    }
    else
    {
      v6 = 255;
    }
    if ( v4 > a1[6] )
    {
      v8 = v4;
      v9 = v5;
      v10 = v8;
      if ( v9 < a1[6] )
        v7 = (__int64)(a1[6] * 255.0 + 0.5);
      else
        v7 = 0;
      v11 = v9;
      v4 = v10;
      v5 = v11;
    }
    else
    {
      v7 = 255;
    }
    if ( v4 > a1[7] )
    {
      if ( v5 < a1[7] )
        v12 = (__int64)(255.0 * a1[7] + 0.5);
      else
        v12 = 0;
    }
    else
    {
      v12 = 255;
    }
    result = (*(int (__stdcall **)(_DWORD, _DWORD, int, int, struct tagRECT *, int, int))(**(_DWORD **)a1 + 60))(
               *(_DWORD *)a1,
               *((_DWORD *)a1 + 1),
               a2,
               -1,
               &rc,
               256,
               v7 | ((v6 | ((v13 | (v12 << 8)) << 8)) << 8));
  }
  else
  {
    result = (*(int (__stdcall **)(_DWORD, _DWORD, int, int, struct tagRECT *, int, _DWORD, _DWORD, _DWORD, _DWORD))(**((_DWORD **)a1 + 2) + 60))(
               *((_DWORD *)a1 + 2),
               *((_DWORD *)a1 + 3),
               a2,
               -1,
               &rc,
               256,
               *((_DWORD *)a1 + 4),
               *((_DWORD *)a1 + 5),
               *((_DWORD *)a1 + 6),
               *((_DWORD *)a1 + 7));
  }
  if ( result >= 0 )
  {
    if ( a3 )
      *((_DWORD *)a1 + 9) -= *((_DWORD *)a1 + 10);
    else
      *((_DWORD *)a1 + 9) += *((_DWORD *)a1 + 10);
    return 0;
  }
  return result;
}
