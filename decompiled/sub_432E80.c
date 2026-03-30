int __thiscall sub_432E80(struct tagRECT *this)
{
  _DWORD *v2; // edi
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // ecx
  int result; // eax

  v2 = this + 4;
  SetRect(
    this + 4,
    this->right,
    this->bottom,
    this->right + *((_DWORD *)this + 4),
    this->bottom + *((_DWORD *)this + 5));
  v3 = *((_DWORD *)this + 17);
  v4 = *((_DWORD *)this + 18);
  *((_DWORD *)this + 152) = *v2;
  v5 = *((_DWORD *)this + 19);
  *((_DWORD *)this + 153) = v3;
  *((_DWORD *)this + 154) = v4;
  v6 = *v2;
  *((_DWORD *)this + 155) = v5;
  v7 = v5 - *((_DWORD *)this + 153);
  *((_DWORD *)this + 156) = v6;
  v8 = *((_DWORD *)this + 19);
  *((_DWORD *)this + 154) = *((_DWORD *)this + 152) + v7;
  v9 = v3;
  v10 = *((_DWORD *)this + 18);
  *((_DWORD *)this + 157) = v9;
  *((_DWORD *)this + 158) = v10;
  *((_DWORD *)this + 159) = v8;
  result = (int)((double)(*((_DWORD *)this + 154) - *((_DWORD *)this + 152)) * 1.25);
  *((_DWORD *)this + 156) += result;
  return result;
}
