void __thiscall sub_414E10(int this)
{
  double v2; // st7
  _DWORD *v3; // ecx
  _DWORD *v4; // ebx
  _DWORD *i; // eax
  int v6; // edi
  double v7; // st7
  int v8; // edi
  void (__thiscall *v9)(int); // eax
  float v10; // [esp+10h] [ebp-14h]
  float v11; // [esp+14h] [ebp-10h]

  if ( !*(_BYTE *)(this + 188) )
  {
    if ( *(_DWORD *)(this + 180) && (dword_4D7CF8 & 1) == 0 )
    {
      dword_4D7CF8 |= 1u;
      sub_4079C0();
    }
    v2 = 0.0;
    v3 = *(_DWORD **)(this + 168);
    *(float *)(this + 436) = 0.0;
    *(_DWORD *)(this + 480) = 0;
    *(float *)(this + 420) = 0.0;
    *(_DWORD *)(this + 484) = 0;
    v4 = (_DWORD *)*v3;
    v10 = 0.0;
    for ( i = (_DWORD *)*v3; i != v3; v10 = *(float *)(v6 + 428) + v10 )
    {
      v6 = i[2];
      i = (_DWORD *)*i;
    }
    if ( v4 != v3 )
    {
      while ( 1 )
      {
        v8 = v4[2];
        v4 = (_DWORD *)*v4;
        v11 = v10 <= v2 ? 1.0 / (double)*(unsigned int *)(this + 172) : *(float *)(v8 + 428) / v10;
        v9 = *(void (__thiscall **)(int))(*(_DWORD *)v8 + 36);
        *(float *)(v8 + 432) = v11 * *(float *)(this + 432);
        v9(v8);
        *(float *)(this + 420) = *(float *)(v8 + 420) + *(float *)(this + 420);
        *(_DWORD *)(this + 480) += *(_DWORD *)(v8 + 480);
        *(_DWORD *)(this + 484) += *(_DWORD *)(v8 + 484);
        *(float *)(this + 436) = *(float *)(v8 + 436) + *(float *)(this + 436);
        if ( v4 == *(_DWORD **)(this + 168) )
          break;
        v2 = 0.0;
      }
    }
    *(float *)(this + 424) = *(float *)(this + 424) + *(float *)(this + 420);
    *(float *)(this + 440) = *(float *)(this + 440) + 1.0;
    v7 = *(float *)(this + 448) * 0.5;
    if ( *(float *)(this + 444) >= v7 )
      *(float *)(this + 36) = *(float *)(this + 444);
    else
      *(float *)(this + 36) = v7;
  }
}
