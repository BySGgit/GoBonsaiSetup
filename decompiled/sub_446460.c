_DWORD *__userpurge sub_446460@<eax>(
        int a1@<ecx>,
        double a2@<st0>,
        _DWORD *a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        _DWORD *a9,
        float *a10)
{
  _DWORD *v10; // ebx
  int v11; // eax
  int v12; // edx
  float v14; // [esp+18h] [ebp-54h] BYREF
  float v15; // [esp+1Ch] [ebp-50h]
  int v16; // [esp+20h] [ebp-4Ch] BYREF
  float *v17; // [esp+24h] [ebp-48h]
  char *EndPtr; // [esp+28h] [ebp-44h] BYREF
  char String[60]; // [esp+2Ch] [ebp-40h] BYREF

  v10 = a9;
  v17 = a10;
  v16 = 0;
  v14 = 0.0;
  v11 = sub_447D10(String, (unsigned int *)&v14, a1, (int)&a4, (int)&a6, a8);
  _Stofx(String, &EndPtr, v11, (int)&v16);
  v15 = a2;
  if ( v14 != 0.0 )
  {
    v14 = ldexp(v15, 4 * LODWORD(v14));
    v15 = v14;
  }
  if ( (unsigned __int8)sub_44BB00(&a6, &a4) )
    *v10 |= 1u;
  if ( EndPtr == String || v16 )
    *v10 |= 2u;
  else
    *v17 = v15;
  v12 = a4;
  a3[1] = a5;
  *a3 = v12;
  return a3;
}
