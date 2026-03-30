int __userpurge sub_431380@<eax>(LONG *a1@<ecx>, int a2@<edi>, int a3@<esi>, int a4, char a5, int a6)
{
  int result; // eax
  LONG v7; // edx
  LONG v8; // eax
  LONG v9; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // ebp
  int v15; // eax
  float v16; // [esp+20h] [ebp-94h]
  float v17; // [esp+24h] [ebp-90h]
  float v18; // [esp+28h] [ebp-8Ch]
  float v19; // [esp+30h] [ebp-84h]
  struct tagRECT rc; // [esp+4Ch] [ebp-68h] BYREF
  struct tagRECT v21; // [esp+5Ch] [ebp-58h] BYREF
  _BYTE v22[68]; // [esp+6Ch] [ebp-48h] BYREF

  if ( 0.0 == *(float *)(a2 + 104) )
    return 0;
  v7 = a1[1];
  rc.left = *a1;
  v8 = a1[2];
  v9 = a1[3];
  rc.top = v7;
  v10 = *(_DWORD *)(a3 + 540);
  rc.right = v8;
  v11 = *(_DWORD *)(a3 + 536);
  rc.bottom = v9;
  OffsetRect(&rc, v11, v10);
  if ( *(_BYTE *)(a3 + 21) )
    OffsetRect(&rc, 0, *(_DWORD *)(a3 + 552));
  v12 = *(_DWORD *)(a3 + 572);
  v16 = (float)*(unsigned int *)(v12 + 40);
  v18 = (float)*(unsigned int *)(v12 + 44);
  D3DXMatrixOrthoOffCenterLH(v22, 0.0, LODWORD(v16), 0.0, LODWORD(v18), LODWORD(flt_4CA5E8), 10.0);
  (*(void (__stdcall **)(_DWORD, _BYTE *))(**(_DWORD **)(*(_DWORD *)(a3 + 572) + 36) + 44))(
    *(_DWORD *)(*(_DWORD *)(a3 + 572) + 36),
    v22);
  v13 = *(_DWORD *)(a3 + 572);
  if ( v13 )
    v14 = *(_DWORD *)(*(_DWORD *)(v13 + 80) + 4 * *(_DWORD *)(*(_DWORD *)(a3 + 596) + 4 * *(_DWORD *)(a2 + 4)));
  else
    v14 = 0;
  if ( !a5
    || (v21 = rc,
        OffsetRect(&v21, 1, 1),
        v17 = (double)0 * 0.003921568859368563,
        v19 = 0.003921568859368563 * (double)(unsigned __int8)(__int64)(*(float *)(a2 + 104) * 255.0),
        result = (*(int (__stdcall **)(_DWORD, _DWORD, int, int, struct tagRECT *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(v14 + 532) + 60))(
                   *(_DWORD *)(v14 + 532),
                   *(_DWORD *)(*(_DWORD *)(a3 + 572) + 36),
                   a4,
                   a6,
                   &v21,
                   *(_DWORD *)(a2 + 8),
                   LODWORD(v17),
                   LODWORD(v17),
                   LODWORD(v17),
                   LODWORD(v19)),
        result >= 0) )
  {
    v15 = (*(int (__stdcall **)(_DWORD, _DWORD, int, int, struct tagRECT *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(v14 + 532) + 60))(
            *(_DWORD *)(v14 + 532),
            *(_DWORD *)(*(_DWORD *)(a3 + 572) + 36),
            a4,
            a6,
            &rc,
            *(_DWORD *)(a2 + 8),
            *(_DWORD *)(a2 + 92),
            *(_DWORD *)(a2 + 96),
            *(_DWORD *)(a2 + 100),
            *(_DWORD *)(a2 + 104));
    return v15 >= 0 ? 0 : v15;
  }
  return result;
}
