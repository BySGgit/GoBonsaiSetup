int *__cdecl _wfltin2(int *a1, int a2, int a3)
{
  int v3; // ebx
  int v4; // eax
  int v6; // [esp+Ch] [ebp-24h] BYREF
  int v7; // [esp+10h] [ebp-20h]
  int v8; // [esp+14h] [ebp-1Ch] BYREF
  int v9; // [esp+18h] [ebp-18h]
  int v10; // [esp+1Ch] [ebp-14h]
  unsigned __int16 v11[6]; // [esp+20h] [ebp-10h] BYREF

  v7 = a2;
  v3 = 0;
  v10 = __wstrgtold12_l(v11, &v6, a2, 0, 0, 0, 0, a3);
  if ( (v10 & 4) != 0 )
  {
    v3 = 512;
    v8 = 0;
    v9 = 0;
  }
  else
  {
    v4 = sub_46438A(v11, (unsigned int *)&v8);
    if ( (v10 & 2) != 0 || v4 == 1 )
      v3 = 128;
    if ( (v10 & 1) != 0 || v4 == 2 )
      v3 |= 0x100u;
  }
  a1[1] = (v6 - v7) >> 1;
  a1[4] = v8;
  a1[5] = v9;
  *a1 = v3;
  return a1;
}
