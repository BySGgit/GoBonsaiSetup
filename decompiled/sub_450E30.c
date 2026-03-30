int __userpurge sub_450E30@<eax>(int a1@<ecx>, int *a2@<esi>, float *a3, float *a4, int a5)
{
  int v5; // edi
  float v7; // [esp+10h] [ebp-14h]
  int v8; // [esp+14h] [ebp-10h] BYREF
  float v9; // [esp+18h] [ebp-Ch]
  float v10; // [esp+1Ch] [ebp-8h]

  v5 = a1;
  if ( !a1 )
    v5 = dword_4D7EE4;
  dword_4D82B4 = a5;
  dword_4D82B0 = (int)a2;
  dword_4D82B8 = 0;
  sub_401430((float *)&v8, a3, a4);
  v7 = v9 * v9 + *(float *)&v8 * *(float *)&v8 + v10 * v10;
  sub_450CD0(v5, a3, a4, (float *)&v8, v7);
  dword_4D82AC += dword_4D82B8;
  sub_451320(a2, &a2[3 * dword_4D82B8], 12 * dword_4D82B8 / 12, (unsigned __int8 (*)(void))sub_450E10);
  return dword_4D82B8;
}
