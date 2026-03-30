void __thiscall sub_432820(int this, float a2)
{
  int v3; // edi
  int v4; // eax
  LONG *v5; // ecx
  int v6; // ebx

  if ( *(_BYTE *)(this + 4) )
  {
    v3 = **(_DWORD **)(this + 32);
    sub_437110(*(_BYTE *)(this + 60) == 0, (float *)(v3 + 68), a2, 0.69999999);
    v4 = this + 80;
    v5 = (LONG *)(this + 64);
    v6 = *(_DWORD *)(this + 24);
    if ( *(_DWORD *)(*(_DWORD *)(v6 + 572) + 60) )
      sub_431020(v5, v6, v3, v4, 1, -1);
    else
      sub_431380(v5, v3, v6, v4, 1, -1);
  }
}
