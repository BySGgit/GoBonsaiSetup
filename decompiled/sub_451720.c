int __usercall sub_451720@<eax>(int *a1@<eax>, int *a2, int *a3, unsigned __int8 (*a4)(void))
{
  int v5; // eax
  int v6; // eax
  int v7; // ebp
  int v8; // ebx
  int *v10; // [esp+8h] [ebp-4h]

  v5 = ((char *)a3 - (char *)a1) / 12;
  if ( v5 <= 40 )
    return sub_451A80(a1, a2, a3, a4);
  v6 = (v5 + 1) / 8;
  v7 = 24 * v6;
  v8 = 12 * v6;
  v10 = &a1[3 * v6];
  sub_451A80(a1, v10, &a1[6 * v6], a4);
  sub_451A80(&a2[v8 / 0xFFFFFFFC], a2, &a2[v8 / 4u], a4);
  sub_451A80(&a3[v7 / 0xFFFFFFFC], &a3[v8 / 0xFFFFFFFC], a3, a4);
  return sub_451A80(v10, a2, &a3[v8 / 0xFFFFFFFC], a4);
}
