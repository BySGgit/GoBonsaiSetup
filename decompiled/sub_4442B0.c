void __usercall sub_4442B0(int *a1@<esi>)
{
  _DWORD *v1; // ecx
  int v2; // ebx

  v1 = (_DWORD *)a1[1];
  if ( (_DWORD *)*a1 != v1 )
  {
    v2 = sub_44C450(v1, *a1, v1);
    sub_446B40(v2, a1[1]);
    a1[1] = v2;
  }
}
