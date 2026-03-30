void __userpurge sub_441E00(int *a1@<ecx>, int a2@<edi>, _DWORD *a3)
{
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  int *v7; // eax
  int v8; // esi
  char *v9; // eax
  int v10; // ecx
  void *v11[5]; // [esp+8h] [ebp-3Ch] BYREF
  unsigned int v12; // [esp+1Ch] [ebp-28h]
  int v13; // [esp+24h] [ebp-20h]
  int v14; // [esp+28h] [ebp-1Ch]
  int v15; // [esp+2Ch] [ebp-18h]
  int v16; // [esp+30h] [ebp-14h]
  int v17; // [esp+40h] [ebp-4h]

  LOWORD(v11[0]) = 0;
  v12 = 7;
  v11[4] = 0;
  sub_4037B0(0xFFFFFFFF, (int)v11, a3, 0);
  v4 = a1[1];
  v5 = a1[2];
  v13 = *a1;
  v6 = a1[3];
  v14 = v4;
  v15 = v5;
  v16 = v6;
  v17 = 0;
  v7 = *(int **)(a2 + 36);
  v8 = *v7;
  v9 = sub_44C360(*v7, *(void **)(*v7 + 4), (char *)v11);
  v10 = *(_DWORD *)(a2 + 40);
  if ( v10 == 97612892 )
    std::_Xlength_error("list<T> too long");
  *(_DWORD *)(a2 + 40) = v10 + 1;
  *(_DWORD *)(v8 + 4) = v9;
  **((_DWORD **)v9 + 1) = v9;
  if ( v12 >= 8 )
    operator delete(v11[0]);
}
