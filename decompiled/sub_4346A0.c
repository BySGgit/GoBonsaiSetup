int __usercall sub_4346A0@<eax>(_DWORD *a1@<eax>, int a2@<ecx>)
{
  int v2; // edx
  float v4; // [esp+8h] [ebp-8h]

  v2 = a1[16];
  v4 = (double)(a1[22] - a1[21]) / (double)(a1[18] - v2);
  return (int)(v4 * (double)(a2 - v2) + (double)(int)a1[21] + 0.5);
}
