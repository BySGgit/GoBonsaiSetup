int __thiscall sub_433400(int this)
{
  _DWORD *v2; // edi
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  int v15; // edx
  int v16; // edx
  _DWORD *v17; // ebx
  void (__thiscall *v18)(int); // eax
  int v19; // edx
  int v20; // eax
  int result; // eax
  int v22; // ecx
  int v23; // esi
  int v24; // eax
  int v25; // ecx
  int v26; // eax

  v2 = (_DWORD *)(this + 64);
  SetRect(
    (LPRECT)(this + 64),
    *(_DWORD *)(this + 8),
    *(_DWORD *)(this + 12),
    *(_DWORD *)(this + 8) + *(_DWORD *)(this + 16),
    *(_DWORD *)(this + 12) + *(_DWORD *)(this + 20));
  v3 = *(_DWORD *)(this + 68);
  v4 = *(_DWORD *)(this + 72);
  *(_DWORD *)(this + 824) = *v2;
  v5 = *(_DWORD *)(this + 76);
  *(_DWORD *)(this + 828) = v3;
  *(_DWORD *)(this + 832) = v4;
  v6 = *v2;
  *(_DWORD *)(this + 836) = v5;
  v7 = *(_DWORD *)(this + 832) + *(_DWORD *)(this + 828) - v5;
  v8 = *(_DWORD *)(this + 68);
  *(_DWORD *)(this + 808) = v6;
  v9 = *(_DWORD *)(this + 76);
  *(_DWORD *)(this + 812) = v8;
  v10 = v7;
  *(_DWORD *)(this + 820) = v9;
  *(_DWORD *)(this + 824) = v7;
  *(_DWORD *)(this + 816) = v7;
  v11 = *(_DWORD *)(this + 812);
  *(_DWORD *)(this + 840) = *(_DWORD *)(this + 808);
  v12 = *(_DWORD *)(this + 820);
  *(_DWORD *)(this + 844) = v11;
  *(_DWORD *)(this + 848) = v10;
  *(_DWORD *)(this + 852) = v12;
  OffsetRect((LPRECT)(this + 840), 0, (int)((double)(v12 - v11) * 0.8999999761581421));
  *(_DWORD *)(this + 852) += *(_DWORD *)(this + 612);
  *(_DWORD *)(this + 848) -= *(_DWORD *)(this + 800);
  v13 = *(_DWORD *)(this + 844);
  v14 = *(_DWORD *)(this + 848);
  *(_DWORD *)(this + 856) = *(_DWORD *)(this + 840);
  v15 = *(_DWORD *)(this + 852);
  *(_DWORD *)(this + 860) = v13;
  *(_DWORD *)(this + 864) = v14;
  *(_DWORD *)(this + 868) = v15;
  *(_DWORD *)(this + 856) += (int)((double)(v14 - *(_DWORD *)(this + 840)) * 0.1000000014901161);
  *(_DWORD *)(this + 864) += (int)((double)(*(_DWORD *)(this + 848) - *(_DWORD *)(this + 840)) * -0.1000000014901161);
  *(_DWORD *)(this + 860) += (int)(0.1000000014901161 * (double)(*(_DWORD *)(this + 852) - *(_DWORD *)(this + 844)));
  *(_DWORD *)(this + 868) += (int)(-0.1000000014901161 * (double)(*(_DWORD *)(this + 852) - *(_DWORD *)(this + 844)));
  v16 = *(_DWORD *)(this + 616);
  v17 = (_DWORD *)(this + 616);
  *(_DWORD *)(this + 628) = *(_DWORD *)(this + 844) + 2;
  v18 = *(void (__thiscall **)(int))(v16 + 76);
  *(_DWORD *)(this + 624) = v14;
  v18(this + 616);
  v19 = *(_DWORD *)(this + 616);
  v20 = *(_DWORD *)(this + 852) - *(_DWORD *)(this + 844) - 2;
  *(_DWORD *)(this + 632) = *(_DWORD *)(this + 800);
  *(_DWORD *)(this + 636) = v20;
  (*(void (__thiscall **)(int))(v19 + 76))(this + 616);
  result = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 24) + 572) + 80)
                     + 4 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 32) + 8) + 4));
  if ( result )
  {
    v22 = *(_DWORD *)(result + 520);
    if ( v22 )
    {
      sub_437460(this + 616, (*(_DWORD *)(this + 868) - *(_DWORD *)(this + 860)) / v22);
      v23 = *(_DWORD *)(this + 604);
      if ( v23 < 0 )
        v23 = 0;
      v24 = v17[40];
      if ( v23 >= v24 )
        v23 = v24 - 1;
      v25 = v17[37];
      if ( v25 <= v23 )
      {
        v26 = v17[38];
        if ( v26 + v25 > v23 )
          return sub_434D20((int)v17);
        v23 = v23 - v26 + 1;
      }
      v17[37] = v23;
      return sub_434D20((int)v17);
    }
  }
  return result;
}
