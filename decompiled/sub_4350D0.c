int __thiscall sub_4350D0(int this, float a2)
{
  double *EngineInstance; // esi
  int v4; // edi
  int v5; // eax
  LONG *v6; // ecx
  int v7; // edi
  int v8; // eax
  LONG *v9; // ecx
  int v10; // edi
  int v11; // eax
  LONG *v12; // ecx
  int v13; // edi
  LONG *v14; // ecx
  int v15; // ebx
  double v17; // [esp+18h] [ebp-8h]
  int v18; // [esp+18h] [ebp-8h]

  if ( *(_DWORD *)(this + 172) )
  {
    EngineInstance = (double *)GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v17 = EngineInstance[82];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( PtInRect((const RECT *)(this + 84), *(POINT *)(this + 164)) )
    {
      if ( *(_DWORD *)(this + 172) == 1 )
      {
        if ( v17 - *(double *)(this + 176) > 0.33 )
        {
          sub_434DA0(this, -1);
          *(double *)(this + 176) = v17;
          *(_DWORD *)(this + 172) = 3;
        }
      }
      else if ( *(_DWORD *)(this + 172) == 3 && v17 - *(double *)(this + 176) > 0.05 )
      {
        sub_434DA0(this, -1);
        *(double *)(this + 176) = v17;
      }
    }
    else if ( PtInRect((const RECT *)(this + 100), *(POINT *)(this + 164)) )
    {
      if ( *(_DWORD *)(this + 172) == 2 )
      {
        if ( v17 - *(double *)(this + 176) > 0.33 )
        {
          sub_434DA0(this, 1);
          *(double *)(this + 176) = v17;
          *(_DWORD *)(this + 172) = 4;
        }
      }
      else if ( *(_DWORD *)(this + 172) == 4 && v17 - *(double *)(this + 176) > 0.05 )
      {
        sub_434DA0(this, 1);
        *(double *)(this + 176) = v17;
      }
    }
  }
  v18 = 0;
  if ( *(_BYTE *)(this + 4) )
  {
    if ( *(_BYTE *)(this + 60) && *(_BYTE *)(this + 80) )
    {
      if ( *(_BYTE *)(this + 5) )
      {
        v18 = 4;
      }
      else if ( *(_BYTE *)(this + 6) )
      {
        v18 = 3;
      }
    }
    else
    {
      v18 = 1;
    }
  }
  else
  {
    v18 = 2;
  }
  v4 = **(_DWORD **)(this + 32);
  sub_437110(v18, (float *)(v4 + 28), a2, 0.80000001);
  v5 = *(_DWORD *)(this + 24);
  v6 = (LONG *)(this + 116);
  if ( *(_DWORD *)(*(_DWORD *)(v5 + 572) + 60) )
    sub_430950(v4, v6, *(_DWORD *)(this + 24));
  else
    sub_430C90(v6, v5, v4, 0.80000001);
  v7 = *(_DWORD *)(*(_DWORD *)(this + 32) + 4);
  sub_437110(v18, (float *)(v7 + 28), a2, 0.80000001);
  v8 = *(_DWORD *)(this + 24);
  v9 = (LONG *)(this + 84);
  if ( *(_DWORD *)(*(_DWORD *)(v8 + 572) + 60) )
    sub_430950(v7, v9, *(_DWORD *)(this + 24));
  else
    sub_430C90(v9, v8, v7, 0.60000002);
  v10 = *(_DWORD *)(*(_DWORD *)(this + 32) + 8);
  sub_437110(v18, (float *)(v10 + 28), a2, 0.80000001);
  v11 = *(_DWORD *)(this + 24);
  v12 = (LONG *)(this + 100);
  if ( *(_DWORD *)(*(_DWORD *)(v11 + 572) + 60) )
    sub_430950(v10, v12, *(_DWORD *)(this + 24));
  else
    sub_430C90(v12, v11, v10, 0.60000002);
  v13 = *(_DWORD *)(*(_DWORD *)(this + 32) + 12);
  sub_437110(v18, (float *)(v13 + 28), a2, 0.80000001);
  v14 = (LONG *)(this + 132);
  v15 = *(_DWORD *)(this + 24);
  if ( *(_DWORD *)(*(_DWORD *)(v15 + 572) + 60) )
    return sub_430950(v13, v14, v15);
  else
    return sub_430C90(v14, v15, v13, 0.60000002);
}
