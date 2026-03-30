unsigned int __cdecl _raise_exc_ex(
        ULONG_PTR Arguments,
        unsigned int *a2,
        DWORD dwExceptionCode,
        int a4,
        float *a5,
        float *a6,
        int a7)
{
  char v7; // cl
  unsigned int *v8; // esi
  char v9; // al
  int v10; // eax
  unsigned int *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  unsigned int *v14; // eax
  unsigned int v15; // ecx
  float *v16; // edi
  ULONG_PTR v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  unsigned int v21; // eax
  int v22; // eax
  int v23; // eax
  unsigned int result; // eax

  v7 = dwExceptionCode;
  *(_DWORD *)(Arguments + 4) = 0;
  *(_DWORD *)(Arguments + 8) = 0;
  *(_DWORD *)(Arguments + 12) = 0;
  if ( (v7 & 0x10) != 0 )
  {
    *(_DWORD *)(Arguments + 4) |= 1u;
    dwExceptionCode = -1073741681;
  }
  if ( (v7 & 2) != 0 )
  {
    *(_DWORD *)(Arguments + 4) |= 2u;
    dwExceptionCode = -1073741677;
  }
  if ( (v7 & 1) != 0 )
  {
    *(_DWORD *)(Arguments + 4) |= 4u;
    dwExceptionCode = -1073741679;
  }
  if ( (v7 & 4) != 0 )
  {
    *(_DWORD *)(Arguments + 4) |= 8u;
    dwExceptionCode = -1073741682;
  }
  if ( (v7 & 8) != 0 )
  {
    *(_DWORD *)(Arguments + 4) |= 0x10u;
    dwExceptionCode = -1073741680;
  }
  v8 = a2;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(16 * *a2)) & 0x10;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(2 * *v8)) & 8;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(*v8 >> 1)) & 4;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(*v8 >> 3)) & 2;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(*v8 >> 5)) & 1;
  v9 = _statfp();
  if ( (v9 & 1) != 0 )
    *(_DWORD *)(Arguments + 12) |= 0x10u;
  if ( (v9 & 4) != 0 )
    *(_DWORD *)(Arguments + 12) |= 8u;
  if ( (v9 & 8) != 0 )
    *(_DWORD *)(Arguments + 12) |= 4u;
  if ( (v9 & 0x10) != 0 )
    *(_DWORD *)(Arguments + 12) |= 2u;
  if ( (v9 & 0x20) != 0 )
    *(_DWORD *)(Arguments + 12) |= 1u;
  v10 = *v8 & 0xC00;
  switch ( v10 )
  {
    case 0:
      *(_DWORD *)Arguments &= 0xFFFFFFFC;
      break;
    case 1024:
      v11 = (unsigned int *)Arguments;
      v12 = *(_DWORD *)Arguments & 0xFFFFFFFC | 1;
      goto LABEL_27;
    case 2048:
      v11 = (unsigned int *)Arguments;
      v12 = *(_DWORD *)Arguments & 0xFFFFFFFC | 2;
LABEL_27:
      *v11 = v12;
      break;
    case 3072:
      *(_DWORD *)Arguments |= 3u;
      break;
  }
  v13 = *v8 & 0x300;
  switch ( v13 )
  {
    case 0:
      v14 = (unsigned int *)Arguments;
      v15 = *(_DWORD *)Arguments & 0xFFFFFFE3 | 8;
      goto LABEL_36;
    case 512:
      v14 = (unsigned int *)Arguments;
      v15 = *(_DWORD *)Arguments & 0xFFFFFFE3 | 4;
LABEL_36:
      *v14 = v15;
      break;
    case 768:
      *(_DWORD *)Arguments &= 0xFFFFFFE3;
      break;
  }
  *(_DWORD *)Arguments ^= (*(_DWORD *)Arguments ^ (32 * a4)) & 0x1FFE0;
  *(_DWORD *)(Arguments + 32) |= 1u;
  v16 = a6;
  if ( a7 )
  {
    *(_DWORD *)(Arguments + 32) &= 0xFFFFFFE1;
    *(float *)(Arguments + 16) = *a5;
    *(_DWORD *)(Arguments + 96) |= 1u;
    *(_DWORD *)(Arguments + 96) &= 0xFFFFFFE1;
    *(float *)(Arguments + 80) = *v16;
  }
  else
  {
    *(_DWORD *)(Arguments + 32) = *(_DWORD *)(Arguments + 32) & 0xFFFFFFE1 | 2;
    *(double *)(Arguments + 16) = *(double *)a5;
    *(_DWORD *)(Arguments + 96) |= 1u;
    *(_DWORD *)(Arguments + 96) = *(_DWORD *)(Arguments + 96) & 0xFFFFFFE1 | 2;
    *(double *)(Arguments + 80) = *(double *)v16;
  }
  _clrfp();
  RaiseException(dwExceptionCode, 0, 1u, &Arguments);
  v17 = Arguments;
  if ( (*(_BYTE *)(Arguments + 8) & 0x10) != 0 )
    *v8 &= ~1u;
  if ( (*(_BYTE *)(v17 + 8) & 8) != 0 )
    *v8 &= ~4u;
  if ( (*(_BYTE *)(v17 + 8) & 4) != 0 )
    *v8 &= ~8u;
  if ( (*(_BYTE *)(v17 + 8) & 2) != 0 )
    *v8 &= ~0x10u;
  if ( (*(_BYTE *)(v17 + 8) & 1) != 0 )
    *v8 &= ~0x20u;
  v18 = *(_DWORD *)v17 & 3;
  if ( !v18 )
  {
    *v8 &= 0xFFFFF3FF;
    goto LABEL_59;
  }
  v19 = v18 - 1;
  if ( !v19 )
  {
    v21 = *v8 & 0xFFFFF3FF | 0x400;
    goto LABEL_56;
  }
  v20 = v19 - 1;
  if ( !v20 )
  {
    v21 = *v8 & 0xFFFFF3FF | 0x800;
LABEL_56:
    *v8 = v21;
    goto LABEL_59;
  }
  if ( v20 == 1 )
    *v8 |= 0xC00u;
LABEL_59:
  v22 = (*(_DWORD *)v17 >> 2) & 7;
  if ( !v22 )
  {
    result = *v8 & 0xFFFFF0FF | 0x300;
    goto LABEL_65;
  }
  v23 = v22 - 1;
  if ( !v23 )
  {
    result = *v8 & 0xFFFFF1FF | 0x200;
LABEL_65:
    *v8 = result;
    goto LABEL_66;
  }
  result = v23 - 1;
  if ( !result )
    *v8 &= 0xFFFFF3FF;
LABEL_66:
  if ( a7 )
    *v16 = *(float *)(v17 + 80);
  else
    *(double *)v16 = *(double *)(v17 + 80);
  return result;
}
