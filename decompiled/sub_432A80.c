int __thiscall sub_432A80(int this, float a2)
{
  int v3; // ecx
  int v4; // eax
  int v5; // edi
  double v6; // st7
  int v7; // eax
  int v8; // eax
  int v9; // edi
  int v10; // eax
  int v11; // ebx
  int v13; // [esp-4h] [ebp-3Ch]
  int v14; // [esp+14h] [ebp-24h]
  float v15; // [esp+18h] [ebp-20h]
  int v16; // [esp+1Ch] [ebp-1Ch]
  int v17; // [esp+20h] [ebp-18h]
  struct tagRECT rc; // [esp+24h] [ebp-14h] BYREF

  v3 = 0;
  v4 = 0;
  v14 = 0;
  if ( *(_BYTE *)(this + 4) )
  {
    if ( *(_BYTE *)(this + 60) )
    {
      if ( *(_BYTE *)(this + 600) )
      {
        v4 = 1;
        v14 = 5;
        v3 = 2;
      }
      else if ( *(_BYTE *)(this + 5) )
      {
        v4 = -1;
        v14 = 4;
        v3 = -2;
      }
      else if ( *(_BYTE *)(this + 6) )
      {
        v14 = 3;
      }
    }
    else
    {
      v14 = 1;
    }
  }
  else
  {
    v14 = 2;
  }
  v5 = **(_DWORD **)(this + 32);
  if ( v14 == 5 )
    v6 = 0.0;
  else
    v6 = 0.80000001;
  v15 = v6;
  rc = *(struct tagRECT *)(this + 64);
  OffsetRect(&rc, v4, v3);
  sub_437110(v14, (float *)(v5 + 28), a2, v15);
  sub_437110(v14, (float *)(v5 + 68), a2, v15);
  v7 = *(_DWORD *)(this + 24);
  if ( *(_DWORD *)(*(_DWORD *)(v7 + 572) + 60) )
    sub_430950(v5, &rc.left, *(_DWORD *)(this + 24));
  else
    sub_430C90(&rc.left, v7, v5, 0.80000001);
  v8 = *(_DWORD *)(this + 24);
  v17 = this + 80;
  v13 = this + 80;
  if ( *(_DWORD *)(*(_DWORD *)(v8 + 572) + 60) )
    sub_431020(&rc.left, v8, v5, v13, 0, -1);
  else
    sub_431380(&rc.left, v5, v8, v13, 0, -1);
  v16 = *(_DWORD *)(*(_DWORD *)(this + 32) + 4);
  v9 = v16;
  sub_437110(v14, (float *)(v16 + 28), a2, v15);
  sub_437110(v14, (float *)(v16 + 68), a2, v15);
  v10 = *(_DWORD *)(this + 24);
  if ( *(_DWORD *)(*(_DWORD *)(v10 + 572) + 60) )
  {
    sub_430950(v16, &rc.left, *(_DWORD *)(this + 24));
    v9 = v16;
  }
  else
  {
    sub_430C90(&rc.left, v10, v16, 0.60000002);
  }
  v11 = *(_DWORD *)(this + 24);
  if ( *(_DWORD *)(*(_DWORD *)(v11 + 572) + 60) )
    return sub_431020(&rc.left, v11, v9, v17, 0, -1);
  else
    return sub_431380(&rc.left, v9, v11, v17, 0, -1);
}
