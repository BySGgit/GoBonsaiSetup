_DWORD *__userpurge sub_446550@<eax>(
        int a1@<ecx>,
        double X@<st0>,
        _DWORD *a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        _DWORD *a9,
        double *a10)
{
  _DWORD *v10; // ebx
  int v11; // eax
  _DWORD *result; // eax
  int v13; // edx
  unsigned int v14; // [esp+30h] [ebp-5Ch] BYREF
  int v15; // [esp+34h] [ebp-58h] BYREF
  double *v16; // [esp+38h] [ebp-54h]
  _DWORD *v17; // [esp+3Ch] [ebp-50h]
  char *EndPtr; // [esp+40h] [ebp-4Ch] BYREF
  double v19; // [esp+44h] [ebp-48h]
  char String[60]; // [esp+4Ch] [ebp-40h] BYREF

  v10 = a9;
  v16 = a10;
  v17 = a3;
  v15 = 0;
  v14 = 0;
  v11 = sub_447D10(String, &v14, a1, (int)&a4, (int)&a6, a8);
  _Stodx(String, &EndPtr, v11, (int)&v15);
  v19 = X;
  if ( v14 )
    v19 = ldexp(X, 4 * v14);
  if ( (unsigned __int8)sub_44BB00(&a6, &a4) )
    *v10 |= 1u;
  if ( EndPtr == String || v15 )
    *v10 |= 2u;
  else
    *v16 = v19;
  result = v17;
  v13 = a4;
  v17[1] = a5;
  *result = v13;
  return result;
}
