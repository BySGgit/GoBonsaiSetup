void __fastcall sub_440720(_DWORD *a1, int *a2)
{
  _BYTE *v4; // eax
  _BYTE *v5; // eax
  _DWORD *v6; // esi
  int v7; // ecx
  _BYTE *v8; // eax
  _BYTE *v9; // eax
  _BYTE *v10; // eax
  _BYTE *v11; // eax
  _BYTE *v12; // eax
  _BYTE *v13; // eax
  _BYTE *v14; // eax
  _BYTE *v15; // eax
  _BYTE *v16; // eax
  _BYTE *v17; // eax
  _BYTE *v18; // eax
  _BYTE *v19; // eax
  float *v20; // ebx
  _BYTE *v21; // eax
  _BYTE *v22; // eax
  _BYTE *v23; // eax
  _BYTE *v24; // eax
  _BYTE *v25; // eax
  float *v26; // ebp
  _BYTE *v27; // eax
  _BYTE *v28; // eax
  _BYTE *v29; // eax
  float *v30; // ebp
  _BYTE *v31; // eax
  _BYTE *v32; // eax
  _BYTE *v33; // eax
  _DWORD *v34; // esi
  float v35; // [esp+0h] [ebp-140h]
  float v36; // [esp+10h] [ebp-130h]
  float v37; // [esp+20h] [ebp-120h]
  float v38; // [esp+30h] [ebp-110h]
  double v39; // [esp+34h] [ebp-10Ch]
  int v40; // [esp+38h] [ebp-108h]
  int v41; // [esp+38h] [ebp-108h]
  unsigned __int16 v42; // [esp+38h] [ebp-108h]
  unsigned __int16 v43; // [esp+38h] [ebp-108h]
  int v44; // [esp+38h] [ebp-108h]
  float v45; // [esp+38h] [ebp-108h]
  int v46; // [esp+54h] [ebp-ECh] BYREF
  float v47; // [esp+58h] [ebp-E8h] BYREF
  float v48; // [esp+5Ch] [ebp-E4h]
  float v49; // [esp+60h] [ebp-E0h]
  float v50; // [esp+64h] [ebp-DCh]
  char v51[16]; // [esp+68h] [ebp-D8h] BYREF
  _DWORD v52[2]; // [esp+78h] [ebp-C8h] BYREF
  _DWORD v53[37]; // [esp+80h] [ebp-C0h] BYREF
  void *v54[5]; // [esp+114h] [ebp-2Ch] BYREF
  unsigned int v55; // [esp+128h] [ebp-18h]
  int v56; // [esp+13Ch] [ebp-4h]

  *(_DWORD *)v51 = &unk_4BBF70;
  v52[0] = &unk_4BBF78;
  v53[18] = &std::wios::`vftable';
  v56 = 0;
  v46 = 1;
  sub_444DD0(v51, (int)v53);
  v56 = 1;
  *(_DWORD *)&v51[*(_DWORD *)(*(_DWORD *)v51 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  sub_446910(v53);
  v53[0] = &std::wstringbuf::`vftable';
  v53[15] = 0;
  v53[16] = 0;
  v56 = 3;
  switch ( a1[8] )
  {
    case 1:
      sub_443460(a2, a1[7]);
      v40 = *(unsigned __int8 *)a1[7];
      v4 = sub_44A8C0(v52, a1);
      v5 = sub_44AB70(v4, L" = ");
      sub_4426B0(v5, v40);
      goto LABEL_3;
    case 2:
      v46 = (unsigned __int16)*(char *)a1[7];
      sub_443610((int)a2, &v46);
      *(_BYTE *)a1[7] = v46;
      v7 = *(char *)a1[7];
      goto LABEL_11;
    case 3:
      v46 = *(unsigned __int8 *)a1[7];
      sub_4437F0(a2, (int)&v46);
      *(_BYTE *)a1[7] = v46;
      v7 = *(unsigned __int8 *)a1[7];
      goto LABEL_11;
    case 4:
      sub_443610((int)a2, (_WORD *)a1[7]);
      v42 = *(_WORD *)a1[7];
      v10 = sub_44A8C0(v52, a1);
      v11 = sub_44AB70(v10, L" = ");
      sub_4428A0(v11, v42);
      goto LABEL_3;
    case 5:
      sub_4437F0(a2, a1[7]);
      v43 = *(_WORD *)a1[7];
      v12 = sub_44A8C0(v52, a1);
      v13 = sub_44AB70(v12, L" = ");
      sub_442AB0(v13, v43);
      goto LABEL_3;
    case 6:
      sub_4439A0((int)a2, (_DWORD *)a1[7]);
      v7 = *(_DWORD *)a1[7];
LABEL_11:
      v41 = v7;
      v8 = sub_44A8C0(v52, a1);
      v9 = sub_44AB70(v8, L" = ");
      sub_442CA0(v9, v41);
      goto LABEL_3;
    case 7:
      sub_443B80(a2, a1[7]);
      v44 = *(_DWORD *)a1[7];
      v14 = sub_44A8C0(v52, a1);
      v15 = sub_44AB70(v14, L" = ");
      sub_442E90(v15, v44);
      goto LABEL_3;
    case 8:
      sub_443D30(a2, a1[7]);
      v45 = *(float *)a1[7];
      v16 = sub_44A8C0(v52, a1);
      v17 = sub_44AB70(v16, L" = ");
      sub_443080(v17, v45);
      goto LABEL_3;
    case 9:
      sub_443EE0(a2, a1[7]);
      v39 = *(double *)a1[7];
      v18 = sub_44A8C0(v52, a1);
      v19 = sub_44AB70(v18, L" = ");
      sub_443270(v19, v39);
      goto LABEL_3;
    case 0xA:
      v20 = (float *)a1[7];
      sub_443D30(a2, (int)v20);
      sub_443D30(a2, (int)(v20 + 1));
      v38 = v20[1];
      v37 = *v20;
      v21 = sub_44A8C0(v52, a1);
      v22 = sub_44AB70(v21, L" = (");
      goto LABEL_20;
    case 0xB:
      v26 = (float *)a1[7];
      sub_443D30(a2, (int)v26);
      sub_443D30(a2, (int)(v26 + 1));
      sub_443D30(a2, (int)(v26 + 2));
      v38 = v26[2];
      v37 = v26[1];
      v36 = *v26;
      v27 = sub_44A8C0(v52, a1);
      v28 = sub_44AB70(v27, L" = (");
      goto LABEL_22;
    case 0xC:
      v30 = (float *)a1[7];
      sub_443D30(a2, (int)v30);
      sub_443D30(a2, (int)(v30 + 1));
      sub_443D30(a2, (int)(v30 + 2));
      sub_443D30(a2, (int)(v30 + 3));
      v38 = v30[3];
      v37 = v30[2];
      v36 = v30[1];
      v35 = *v30;
      v31 = sub_44A8C0(v52, a1);
      v32 = sub_44AB70(v31, L" = (");
      v33 = sub_443080(v32, v35);
      v28 = sub_44AE40(v33, ", ");
LABEL_22:
      v29 = sub_443080(v28, v36);
      v22 = sub_44AE40(v29, ", ");
LABEL_20:
      v23 = sub_443080(v22, v37);
      v24 = sub_44AE40(v23, ", ");
      v25 = sub_443080(v24, v38);
      sub_44AE40(v25, (const char *)L")");
      goto LABEL_3;
    case 0xD:
      ((void (__cdecl *)(int *))a1[7])(a2);
LABEL_3:
      if ( a1[8] != 13 )
      {
        v6 = (_DWORD *)sub_4443A0((int)v51, (int)v54);
        LOBYTE(v56) = 6;
        v47 = flt_4D63B0;
        v48 = 1.0;
        v50 = 1.0;
        v49 = flt_4D63B0;
        if ( (dword_4D8EC0 & 1) == 0 )
        {
          dword_4D8EC0 |= 1u;
          LOBYTE(v56) = 7;
          sub_43FD00();
          atexit(sub_472560);
          LOBYTE(v56) = 6;
        }
        sub_441E00((int *)&v47, (int)&dword_4D8E20, v6);
        if ( v55 >= 8 )
          operator delete(v54[0]);
        v55 = 7;
        v54[4] = 0;
        LOWORD(v54[0]) = 0;
      }
      break;
    default:
      sub_44AB70(v52, L"Data type not supported");
      v34 = (_DWORD *)sub_4443A0((int)v51, (int)v54);
      LOBYTE(v56) = 4;
      if ( (dword_4D8EC0 & 1) == 0 )
      {
        dword_4D8EC0 |= 1u;
        LOBYTE(v56) = 5;
        sub_43FD00();
        atexit(sub_472560);
        LOBYTE(v56) = 4;
      }
      v47 = 1.0;
      v48 = flt_4D63B0;
      v49 = flt_4D63B0;
      v50 = 1.0;
      sub_441E00((int *)&v47, (int)&dword_4D8E20, v34);
      if ( v55 >= 8 )
        operator delete(v54[0]);
      break;
  }
  v56 = -1;
  sub_440350(v51);
}
