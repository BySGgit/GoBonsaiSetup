_DWORD *__thiscall sub_446640(void *this, _DWORD *a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8, double *a9)
{
  _DWORD *v9; // ebx
  int v10; // eax
  double X; // st7
  _DWORD *result; // eax
  int v13; // edx
  unsigned int v14; // [esp+30h] [ebp-5Ch] BYREF
  int v15; // [esp+34h] [ebp-58h] BYREF
  double *v16; // [esp+38h] [ebp-54h]
  _DWORD *v17; // [esp+3Ch] [ebp-50h]
  _BYTE *v18; // [esp+40h] [ebp-4Ch] BYREF
  double v19; // [esp+44h] [ebp-48h]
  _BYTE v20[60]; // [esp+4Ch] [ebp-40h] BYREF

  v9 = a8;
  v16 = a9;
  v17 = a2;
  v15 = 0;
  v14 = 0;
  v10 = sub_447D10(v20, &v14, (int)this, (int)&a3, (int)&a5, a7);
  X = _Stoldx(v20, &v18, v10, &v15);
  v19 = X;
  if ( v14 )
    v19 = ldexp(X, 4 * v14);
  if ( (unsigned __int8)sub_44BB00(&a5, &a3) )
    *v9 |= 1u;
  if ( v18 == v20 || v15 )
    *v9 |= 2u;
  else
    *v16 = v19;
  result = v17;
  v13 = a3;
  v17[1] = a4;
  *result = v13;
  return result;
}
