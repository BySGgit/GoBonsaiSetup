__int64 __thiscall sub_44CE30(void ***this, char *Src, __int64 a3)
{
  int v3; // edi
  __int64 v4; // rax
  int v5; // ebx
  unsigned int v6; // esi
  __int64 v9; // [esp+10h] [ebp-8h]

  v3 = HIDWORD(a3);
  v9 = 0;
  if ( a3 > 0 )
  {
    do
    {
      v4 = sub_44CE00((int)this);
      v5 = HIDWORD(v4);
      v6 = v4;
      if ( v4 <= 0 )
      {
        if ( ((unsigned __int16 (__thiscall *)(void ***, _DWORD))(*this)[3])(this, *(unsigned __int16 *)Src) == 0xFFFF )
          return v9;
        Src += 2;
        ++v9;
        v3 = (__PAIR64__(v3, a3) - 1) >> 32;
        a3 = __PAIR64__(v3, (int)a3 - 1);
      }
      else
      {
        if ( __SPAIR64__(v3, a3) < v4 )
        {
          v6 = a3;
          v5 = v3;
        }
        memcpy_0(**(this + 9), Src, 2 * v6);
        Src += 2 * v6;
        v9 += __PAIR64__(v5, v6);
        a3 -= __PAIR64__(v5, v6);
        **(this + 13) = (char *)**(this + 13) - v6;
        **(this + 9) = (char *)**(this + 9) + 2 * v6;
        v3 = HIDWORD(a3);
      }
    }
    while ( v3 > 0 || v3 >= 0 && (_DWORD)a3 );
  }
  return v9;
}
