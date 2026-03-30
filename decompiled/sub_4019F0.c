void __thiscall sub_4019F0(void *this)
{
  _DWORD **v2; // ecx
  _DWORD *v3; // eax
  _DWORD *v4; // edi

  *(_DWORD *)this = &WorldObject::`vftable';
  v2 = (_DWORD **)*((_DWORD *)this + 42);
  v3 = *v2;
  *v2 = v2;
  *(_DWORD *)(*((_DWORD *)this + 42) + 4) = *((_DWORD *)this + 42);
  *((_DWORD *)this + 43) = 0;
  if ( v3 != *((_DWORD **)this + 42) )
  {
    do
    {
      v4 = (_DWORD *)*v3;
      operator delete(v3);
      v3 = v4;
    }
    while ( v4 != *((_DWORD **)this + 42) );
  }
  operator delete(*((void **)this + 42));
}
