int __thiscall sub_432F30(int this, float a2)
{
  int v3; // edi
  double v4; // st7
  int v5; // eax
  LONG *v6; // ecx
  int v7; // eax
  LONG *v8; // ecx
  int v9; // eax
  int v10; // edi
  int v11; // ebx
  int v13; // [esp-4h] [ebp-2Ch]
  int v14; // [esp+18h] [ebp-10h]
  float v15; // [esp+1Ch] [ebp-Ch]
  LONG *v16; // [esp+20h] [ebp-8h]

  v14 = 0;
  if ( *(_BYTE *)(this + 4) )
  {
    if ( *(_BYTE *)(this + 60) )
    {
      if ( *(_BYTE *)(this + 600) )
      {
        v14 = 5;
      }
      else if ( *(_BYTE *)(this + 5) )
      {
        v14 = 4;
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
  v3 = **(_DWORD **)(this + 32);
  if ( v14 == 5 )
    v4 = 0.0;
  else
    v4 = 0.80000001;
  v15 = v4;
  sub_437110(v14, (float *)(v3 + 28), a2, v15);
  sub_437110(v14, (float *)(v3 + 68), a2, v15);
  v5 = *(_DWORD *)(this + 24);
  v6 = (LONG *)(this + 608);
  v16 = (LONG *)(this + 608);
  if ( *(_DWORD *)(*(_DWORD *)(v5 + 572) + 60) )
    sub_430950(v3, v6, v5);
  else
    sub_430C90(v6, v5, v3, 0.60000002);
  v7 = *(_DWORD *)(this + 24);
  v8 = (LONG *)(this + 624);
  v13 = this + 80;
  if ( *(_DWORD *)(*(_DWORD *)(v7 + 572) + 60) )
    sub_431020(v8, v7, v3, v13, 1, -1);
  else
    sub_431380(v8, v3, v7, v13, 1, -1);
  v9 = 2;
  if ( *(_BYTE *)(this + 604) )
    v9 = v14;
  v10 = *(_DWORD *)(*(_DWORD *)(this + 32) + 4);
  sub_437110(v9, (float *)(v10 + 28), a2, v15);
  v11 = *(_DWORD *)(this + 24);
  if ( *(_DWORD *)(*(_DWORD *)(v11 + 572) + 60) )
    return sub_430950(v10, v16, v11);
  else
    return sub_430C90(v16, v11, v10, 0.80000001);
}
