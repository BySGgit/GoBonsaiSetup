void __usercall sub_40D860(void *a1@<esi>)
{
  _DWORD **v1; // ecx
  _DWORD *v2; // eax
  _DWORD *v3; // edi

  *(_DWORD *)a1 = &off_4B78A0;
  v1 = (_DWORD **)*((_DWORD *)a1 + 51);
  v2 = *v1;
  *v1 = v1;
  *(_DWORD *)(*((_DWORD *)a1 + 51) + 4) = *((_DWORD *)a1 + 51);
  *((_DWORD *)a1 + 52) = 0;
  if ( v2 != *((_DWORD **)a1 + 51) )
  {
    do
    {
      v3 = (_DWORD *)*v2;
      operator delete(v2);
      v2 = v3;
    }
    while ( v3 != *((_DWORD **)a1 + 51) );
  }
  operator delete(*((void **)a1 + 51));
  sub_4019F0(a1);
}
