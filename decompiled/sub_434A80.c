int __thiscall sub_434A80(int this, float a2)
{
  double v3; // st7
  int v4; // edi
  int v5; // eax
  LONG *v6; // ecx
  int v7; // edi
  LONG *v8; // ecx
  int v9; // ebx
  int v11; // [esp+18h] [ebp-8h]
  float v12; // [esp+1Ch] [ebp-4h]

  v11 = 0;
  if ( !*(_BYTE *)(this + 4) )
  {
    v11 = 2;
LABEL_3:
    v3 = 0.80000001;
    goto LABEL_4;
  }
  if ( !*(_BYTE *)(this + 60) )
  {
    v11 = 1;
    goto LABEL_3;
  }
  if ( !*(_BYTE *)(this + 104) )
  {
    if ( *(_BYTE *)(this + 5) )
    {
      v11 = 4;
    }
    else if ( *(_BYTE *)(this + 6) )
    {
      v11 = 3;
    }
    goto LABEL_3;
  }
  v3 = 0.0;
  v11 = 5;
LABEL_4:
  v12 = v3;
  v4 = **(_DWORD **)(this + 32);
  sub_437110(v11, (float *)(v4 + 28), a2, v12);
  v5 = *(_DWORD *)(this + 24);
  v6 = (LONG *)(this + 64);
  if ( *(_DWORD *)(*(_DWORD *)(v5 + 572) + 60) )
    sub_430950(v4, v6, *(_DWORD *)(this + 24));
  else
    sub_430C90(v6, v5, v4, 0.80000001);
  v7 = *(_DWORD *)(*(_DWORD *)(this + 32) + 4);
  sub_437110(v11, (float *)(v7 + 28), a2, v12);
  v8 = (LONG *)(this + 108);
  v9 = *(_DWORD *)(this + 24);
  if ( *(_DWORD *)(*(_DWORD *)(v9 + 572) + 60) )
    return sub_430950(v7, v8, v9);
  else
    return sub_430C90(v8, v9, v7, 0.60000002);
}
