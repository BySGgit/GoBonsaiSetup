_DWORD *__usercall sub_41A0C0@<eax>(_DWORD *a1@<edi>, _DWORD *a2@<esi>)
{
  bool v2; // zf
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  int v6; // ecx
  int v7; // edx

  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = byte_4CA649 == 0;
  v3 = a1[182];
  v4 = a1[183];
  *a2 = a1[181];
  v5 = a1[184];
  a2[1] = v3;
  v6 = a1[185];
  a2[2] = v4;
  v7 = a1[186];
  a2[3] = v5;
  a2[4] = v6;
  a2[5] = v7;
  if ( !v2 )
    LeaveCriticalSection(&CriticalSection);
  return a2;
}
