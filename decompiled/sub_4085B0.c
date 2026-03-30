_DWORD *__userpurge sub_4085B0@<eax>(int a1@<ecx>, _DWORD *a2@<esi>, int a3)
{
  int v3; // edx
  int v4; // eax
  _DWORD v6[3]; // [esp+Ch] [ebp-10h] BYREF

  D3DXVec3TransformCoord(v6, a1, a3);
  v3 = v6[1];
  v4 = v6[2];
  *a2 = v6[0];
  a2[1] = v3;
  a2[2] = v4;
  return a2;
}
