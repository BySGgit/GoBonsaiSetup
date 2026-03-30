int __cdecl __BuildCatchObject(int a1, int *a2, int *a3, int a4)
{
  int *v4; // ebx
  int v5; // eax
  int result; // eax

  if ( *a3 >= 0 )
    v4 = (int *)((char *)a2 + a3[2] + 12);
  else
    v4 = a2;
  v5 = __BuildCatchObjectHelper(a1, a2, a3, a4) - 1;
  if ( v5 )
  {
    result = v5 - 1;
    if ( !result )
    {
      __AdjustPointer(*(_DWORD *)(a1 + 24), (_DWORD *)(a4 + 8));
      return sub_455903((int)v4, *(_DWORD *)(a4 + 24));
    }
  }
  else
  {
    __AdjustPointer(*(_DWORD *)(a1 + 24), (_DWORD *)(a4 + 8));
    return sub_455903((int)v4, *(_DWORD *)(a4 + 24));
  }
  return result;
}
