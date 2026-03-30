double *__cdecl __libm_error_support(double *a1, double *a2, double *a3, int a4)
{
  double *result; // eax
  double *v5; // esi
  double v6; // st7
  double *v7; // ecx
  double v8; // st7
  int v9; // [esp+0h] [ebp-28h] BYREF
  const char *v10; // [esp+4h] [ebp-24h]
  double v11; // [esp+8h] [ebp-20h]
  double v12; // [esp+10h] [ebp-18h]
  double v13; // [esp+18h] [ebp-10h]
  double v14; // [esp+20h] [ebp-8h]

  v14 = 0.0;
  if ( dword_4DBEF8 )
    result = (double *)DecodePointer(dword_4DBEFC);
  else
    result = (double *)sub_46673E;
  if ( a4 > 166 )
  {
    switch ( a4 )
    {
      case 1000:
        v10 = "log";
        goto LABEL_38;
      case 1001:
        v10 = "log10";
        goto LABEL_38;
      case 1002:
        v10 = "exp";
        goto LABEL_38;
      case 1003:
        v10 = "atan";
        goto LABEL_38;
      case 1004:
        v10 = "ceil";
        goto LABEL_38;
      case 1005:
        v10 = "floor";
        goto LABEL_38;
      case 1006:
        goto LABEL_39;
      case 1007:
        v10 = "modf";
        goto LABEL_38;
      case 1008:
        goto LABEL_36;
      case 1009:
        goto LABEL_35;
      case 1010:
        v10 = "sin";
        goto LABEL_54;
      case 1011:
        v10 = "cos";
        goto LABEL_54;
      case 1012:
        v10 = "tan";
LABEL_54:
        v5 = a3;
        v8 = *a1 * v14;
        *a3 = v8;
        v11 = *a1;
        v12 = *a2;
        goto LABEL_55;
      default:
        return result;
    }
  }
  if ( a4 == 166 )
  {
    v9 = 3;
    v10 = "exp10";
LABEL_17:
    v5 = a3;
    v11 = *a1;
    v12 = *a2;
    v13 = *a3;
    result = (double *)((int (__cdecl *)(int *))result)(&v9);
    if ( !result )
    {
      result = (double *)_errno();
      *(_DWORD *)result = 34;
    }
    goto LABEL_57;
  }
  if ( a4 > 25 )
  {
    switch ( a4 )
    {
      case 26:
        *a3 = 1.0;
        return a3;
      case 27:
        v9 = 2;
LABEL_16:
        v10 = "pow";
        goto LABEL_17;
      case 28:
LABEL_39:
        v10 = "pow";
        break;
      case 29:
        v10 = "pow";
LABEL_38:
        v7 = a1;
        v5 = a3;
        *a3 = *a1;
LABEL_24:
        v11 = *v7;
        v12 = *a2;
        v8 = *v5;
LABEL_55:
        v13 = v8;
        v9 = 1;
        result = (double *)((int (__cdecl *)(int *))result)(&v9);
        if ( !result )
        {
          result = (double *)_errno();
          *(_DWORD *)result = 33;
        }
        goto LABEL_57;
      case 58:
LABEL_36:
        v10 = "acos";
        break;
      case 61:
LABEL_35:
        v10 = "asin";
        break;
      default:
        return result;
    }
LABEL_23:
    v7 = a1;
    v5 = a3;
    goto LABEL_24;
  }
  switch ( a4 )
  {
    case 25:
      v10 = "pow";
      goto LABEL_20;
    case 2:
      v9 = 2;
      v10 = "log";
      goto LABEL_17;
    case 3:
      v10 = "log";
      goto LABEL_23;
    case 8:
      v9 = 2;
      v10 = "log10";
      goto LABEL_17;
    case 9:
      v10 = "log10";
      goto LABEL_23;
    case 14:
      v9 = 3;
      v10 = "exp";
      goto LABEL_17;
  }
  if ( a4 != 15 )
  {
    if ( a4 != 24 )
      return result;
    v9 = 3;
    goto LABEL_16;
  }
  v10 = "exp";
LABEL_20:
  v5 = a3;
  v11 = *a1;
  v12 = *a2;
  v6 = *a3;
  v9 = 4;
  v13 = v6;
  result = (double *)((int (__cdecl *)(int *))result)(&v9);
LABEL_57:
  *v5 = v13;
  return result;
}
