int __usercall sub_44C450@<eax>(_DWORD *Src@<ecx>, int result@<eax>, _DWORD *a3)
{
  _DWORD *v3; // esi
  int v4; // edi

  v3 = Src;
  v4 = result;
  if ( Src != a3 )
  {
    do
    {
      if ( (_DWORD *)v4 != v3 )
      {
        if ( *(_DWORD *)(v4 + 20) >= 8u )
          operator delete(*(void **)v4);
        *(_DWORD *)(v4 + 20) = 7;
        *(_DWORD *)(v4 + 16) = 0;
        *(_WORD *)v4 = 0;
        if ( v3[5] >= 8u )
        {
          *(_DWORD *)v4 = *v3;
          *v3 = 0;
        }
        else
        {
          memcpy((void *)v4, v3, 2 * v3[4] + 2);
        }
        *(_DWORD *)(v4 + 16) = v3[4];
        *(_DWORD *)(v4 + 20) = v3[5];
        v3[5] = 7;
        v3[4] = 0;
        *(_WORD *)v3 = 0;
      }
      v3 += 7;
      v4 += 28;
    }
    while ( v3 != a3 );
    return v4;
  }
  return result;
}
