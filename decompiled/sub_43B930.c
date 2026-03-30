int __thiscall sub_43B930(int *this)
{
  int v1; // eax
  int *v2; // edx
  int v3; // ecx
  int v4; // esi
  int v5; // edx
  unsigned __int8 v6; // cl
  int v7; // edx
  _DWORD *v8; // esi
  int v9; // esi
  int v10; // eax
  _DWORD *v11; // edx
  int v12; // esi
  int v13; // eax
  _DWORD *v14; // edx
  int v15; // esi
  int v16; // eax
  _DWORD *v17; // edx
  int v18; // esi
  int v19; // eax
  _DWORD *v20; // edx
  int v21; // esi
  int v22; // eax
  _DWORD *v23; // edx
  int v24; // esi
  int v25; // eax
  _DWORD *v26; // edx
  int v27; // esi
  int v28; // eax
  _DWORD *v29; // edx
  int v30; // esi
  int v31; // eax
  _DWORD *v32; // edx
  int v33; // esi
  int v34; // eax
  _DWORD *v35; // edx
  int v36; // esi
  int v37; // eax
  _DWORD *v38; // edx
  int v39; // esi
  int v40; // eax
  _DWORD *v41; // edx
  int v42; // esi
  int v43; // eax
  _DWORD *v44; // edx
  int v45; // esi
  int v46; // eax
  _DWORD *v47; // edx
  _DWORD *v48; // eax
  int v49; // esi
  _DWORD *v50; // edi
  int v51; // eax
  int *v52; // edx
  int v53; // ecx
  int v54; // edx
  int v55; // eax
  _DWORD **v56; // ecx
  _DWORD *v57; // eax
  int i; // ebx
  int v59; // eax
  int v60; // ecx
  const unsigned __int16 *v61; // edi
  int v62; // eax
  int v63; // esi
  _DWORD *v64; // esi
  int result; // eax
  int v66; // eax
  _DWORD *v67; // eax
  int v68; // ecx
  int v69; // eax
  int v70; // eax
  _DWORD *v71; // ebx
  void *v72; // eax
  int v73; // eax
  int v74; // esi
  int v75; // eax
  _DWORD *v76; // ebx
  int v77; // eax
  _DWORD *v78; // ebx
  unsigned __int8 v79; // [esp+44h] [ebp-54h]
  _DWORD *v80; // [esp+44h] [ebp-54h]
  int v82; // [esp+4Ch] [ebp-4Ch]
  _DWORD *v83; // [esp+4Ch] [ebp-4Ch]
  int v84; // [esp+4Ch] [ebp-4Ch]
  int v85; // [esp+50h] [ebp-48h]
  int v86; // [esp+50h] [ebp-48h]
  int v87; // [esp+54h] [ebp-44h]
  int v88; // [esp+58h] [ebp-40h]
  int Args; // [esp+5Ch] [ebp-3Ch]
  int v90[5]; // [esp+70h] [ebp-28h] BYREF
  _DWORD v91[4]; // [esp+84h] [ebp-14h] BYREF

  v1 = *(this + 157);
  v2 = this + 4;
  v3 = 0;
  if ( v1 <= 0 )
  {
LABEL_6:
    v5 = 0;
  }
  else
  {
    v4 = v2[152];
    while ( 1 )
    {
      v5 = *(_DWORD *)v4;
      if ( *(_DWORD *)(*(_DWORD *)v4 + 44) == 5 && *(_DWORD *)(v5 + 48) == 3 )
        break;
      ++v3;
      v4 += 4;
      if ( v3 >= v1 )
        goto LABEL_6;
    }
  }
  v6 = *(_BYTE *)(v5 + 604);
  v7 = 0;
  v79 = v6;
  if ( v1 > 0 )
  {
    v8 = (_DWORD *)*(this + 156);
    while ( *(_DWORD *)(*v8 + 44) != 8 )
    {
      ++v7;
      ++v8;
      if ( v7 >= v1 )
        goto LABEL_13;
    }
    (*(void (__thiscall **)(_DWORD, bool))(*(_DWORD *)*v8 + 56))(*v8, v6 == 0);
  }
LABEL_13:
  v9 = *(this + 157);
  v10 = 0;
  if ( v9 > 0 )
  {
    v11 = (_DWORD *)*(this + 156);
    while ( *(_DWORD *)(*v11 + 44) != 10 )
    {
      ++v10;
      ++v11;
      if ( v10 >= v9 )
        goto LABEL_19;
    }
    (*(void (__thiscall **)(_DWORD, bool))(*(_DWORD *)*v11 + 56))(*v11, v79 == 0);
  }
LABEL_19:
  v12 = *(this + 157);
  v13 = 0;
  if ( v12 > 0 )
  {
    v14 = (_DWORD *)*(this + 156);
    while ( *(_DWORD *)(*v14 + 44) != 12 )
    {
      ++v13;
      ++v14;
      if ( v13 >= v12 )
        goto LABEL_25;
    }
    (*(void (__thiscall **)(_DWORD, bool))(*(_DWORD *)*v14 + 56))(*v14, v79 == 0);
  }
LABEL_25:
  v15 = *(this + 157);
  v16 = 0;
  if ( v15 > 0 )
  {
    v17 = (_DWORD *)*(this + 156);
    while ( *(_DWORD *)(*v17 + 44) != 29 )
    {
      ++v16;
      ++v17;
      if ( v16 >= v15 )
        goto LABEL_31;
    }
    (*(void (__thiscall **)(_DWORD, bool))(*(_DWORD *)*v17 + 56))(*v17, v79 == 0);
  }
LABEL_31:
  v18 = *(this + 157);
  v19 = 0;
  if ( v18 > 0 )
  {
    v20 = (_DWORD *)*(this + 156);
    while ( *(_DWORD *)(*v20 + 44) != 31 )
    {
      ++v19;
      ++v20;
      if ( v19 >= v18 )
        goto LABEL_37;
    }
    (*(void (__thiscall **)(_DWORD, bool))(*(_DWORD *)*v20 + 56))(*v20, v79 == 0);
  }
LABEL_37:
  v21 = *(this + 157);
  v22 = 0;
  if ( v21 > 0 )
  {
    v23 = (_DWORD *)*(this + 156);
    while ( *(_DWORD *)(*v23 + 44) != 33 )
    {
      ++v22;
      ++v23;
      if ( v22 >= v21 )
        goto LABEL_43;
    }
    (*(void (__thiscall **)(_DWORD, bool))(*(_DWORD *)*v23 + 56))(*v23, v79 == 0);
  }
LABEL_43:
  v24 = *(this + 157);
  v25 = 0;
  if ( v24 > 0 )
  {
    v26 = (_DWORD *)*(this + 156);
    while ( *(_DWORD *)(*v26 + 44) != 7 )
    {
      ++v25;
      ++v26;
      if ( v25 >= v24 )
        goto LABEL_49;
    }
    (*(void (__thiscall **)(_DWORD, bool))(*(_DWORD *)*v26 + 56))(*v26, v79 == 0);
  }
LABEL_49:
  v27 = *(this + 157);
  v28 = 0;
  if ( v27 > 0 )
  {
    v29 = (_DWORD *)*(this + 156);
    while ( *(_DWORD *)(*v29 + 44) != 9 )
    {
      ++v28;
      ++v29;
      if ( v28 >= v27 )
        goto LABEL_55;
    }
    (*(void (__thiscall **)(_DWORD, bool))(*(_DWORD *)*v29 + 56))(*v29, v79 == 0);
  }
LABEL_55:
  v30 = *(this + 157);
  v31 = 0;
  if ( v30 > 0 )
  {
    v32 = (_DWORD *)*(this + 156);
    while ( *(_DWORD *)(*v32 + 44) != 26 )
    {
      ++v31;
      ++v32;
      if ( v31 >= v30 )
        goto LABEL_61;
    }
    (*(void (__thiscall **)(_DWORD, bool))(*(_DWORD *)*v32 + 56))(*v32, v79 == 0);
  }
LABEL_61:
  v33 = *(this + 157);
  v34 = 0;
  if ( v33 > 0 )
  {
    v35 = (_DWORD *)*(this + 156);
    while ( *(_DWORD *)(*v35 + 44) != 11 )
    {
      ++v34;
      ++v35;
      if ( v34 >= v33 )
        goto LABEL_67;
    }
    (*(void (__thiscall **)(_DWORD, bool))(*(_DWORD *)*v35 + 56))(*v35, v79 == 0);
  }
LABEL_67:
  v36 = *(this + 157);
  v37 = 0;
  if ( v36 > 0 )
  {
    v38 = (_DWORD *)*(this + 156);
    while ( *(_DWORD *)(*v38 + 44) != 25 )
    {
      ++v37;
      ++v38;
      if ( v37 >= v36 )
        goto LABEL_73;
    }
    (*(void (__thiscall **)(_DWORD, unsigned __int8))(*(_DWORD *)*v38 + 56))(*v38, v79);
  }
LABEL_73:
  v39 = *(this + 157);
  v40 = 0;
  if ( v39 > 0 )
  {
    v41 = (_DWORD *)*(this + 156);
    while ( *(_DWORD *)(*v41 + 44) != 28 )
    {
      ++v40;
      ++v41;
      if ( v40 >= v39 )
        goto LABEL_79;
    }
    (*(void (__thiscall **)(_DWORD, bool))(*(_DWORD *)*v41 + 56))(*v41, v79 == 0);
  }
LABEL_79:
  v42 = *(this + 157);
  v43 = 0;
  if ( v42 > 0 )
  {
    v44 = (_DWORD *)*(this + 156);
    while ( *(_DWORD *)(*v44 + 44) != 30 )
    {
      ++v43;
      ++v44;
      if ( v43 >= v42 )
        goto LABEL_85;
    }
    (*(void (__thiscall **)(_DWORD, bool))(*(_DWORD *)*v44 + 56))(*v44, v79 == 0);
  }
LABEL_85:
  v45 = *(this + 157);
  v46 = 0;
  if ( v45 > 0 )
  {
    v47 = (_DWORD *)*(this + 156);
    while ( *(_DWORD *)(*v47 + 44) != 32 )
    {
      ++v46;
      ++v47;
      if ( v46 >= v45 )
        goto LABEL_91;
    }
    (*(void (__thiscall **)(_DWORD, bool))(*(_DWORD *)*v47 + 56))(*v47, v79 == 0);
  }
LABEL_91:
  if ( !dword_4D7DF0 )
  {
    dword_4D7E24 = v79;
    LOBYTE(v82) = (dword_4D7E30 & 4) != 0;
    if ( v79 )
    {
      v66 = sub_41BA20();
      if ( !v66 )
        return -2147467259;
      result = (*(int (__stdcall **)(int, int, _DWORD *))(*(_DWORD *)v66 + 32))(v66, dword_4D7DF4, v91);
      if ( result < 0 )
        return result;
      v67 = sub_41B790(v90);
      v68 = v67[2];
      v69 = v67[3];
      if ( v68 && v69 )
      {
        *(_DWORD *)::Args = v68;
        dword_4D7E08 = v69;
      }
      else
      {
        *(_DWORD *)::Args = v91[0];
        dword_4D7E08 = v91[1];
      }
      dword_4D7DFC = v91[3];
      *(_DWORD *)dword_4D7E34 = v91[2];
    }
    Args = *(_DWORD *)::Args;
    v88 = dword_4D7DFC;
    v87 = dword_4D7E08;
    v86 = *(_DWORD *)dword_4D7E34;
    sub_43E970((int)this, v82);
    v70 = sub_4374E0((int)(this + 4), 7);
    v71 = (_DWORD *)v70;
    if ( v70 )
    {
      sub_434340(v70);
      v72 = sub_428650();
      v73 = sub_4295B0((int)v72, dword_4D7DF4, dword_4D7DF8);
      v84 = v73;
      if ( v73 )
      {
        if ( v79 )
        {
          sub_43DB80(this, v88);
        }
        else
        {
          v74 = 0;
          if ( *(int *)(v73 + 316) > 0 )
          {
            while ( 1 )
            {
              sub_43DB80(this, *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v73 + 312) + 4 * v74++) + 8));
              if ( v74 >= *(_DWORD *)(v84 + 316) )
                break;
              v73 = v84;
            }
          }
        }
        sub_4344D0(v71, v88);
        result = sub_43C2F0(this);
        if ( result < 0 )
          return result;
        v75 = sub_4374E0((int)(this + 4), 9);
        v76 = (_DWORD *)v75;
        if ( v79 )
        {
          sub_434340(v75);
          sub_43DC90(this, Args, v87);
        }
        sub_4344D0(v76, (unsigned __int16)Args | ((unsigned __int16)v87 << 16));
        result = sub_43C650(this);
        if ( result < 0 )
          return result;
        v77 = sub_4374E0((int)(this + 4), 11);
        v78 = (_DWORD *)v77;
        if ( v79 )
        {
          sub_434340(v77);
          sub_43DEF0(v86, (int)this, v86);
        }
        sub_4344D0(v78, v86);
        result = sub_43C9C0((int)this);
        if ( result < 0 )
          return result;
        return 0;
      }
    }
    return -2147467259;
  }
  if ( dword_4D7DF0 != 1 )
    return 0;
  dword_4D7E30 = v79;
  v48 = sub_42B3D0();
  v49 = *(this + 157);
  v50 = v48;
  v51 = 0;
  if ( v49 <= 0 )
  {
LABEL_98:
    v53 = 0;
  }
  else
  {
    v52 = (int *)*(this + 156);
    while ( 1 )
    {
      v53 = *v52;
      if ( *(_DWORD *)(*v52 + 44) == 28 && *(_DWORD *)(v53 + 48) == 4 )
        break;
      ++v51;
      ++v52;
      if ( v51 >= v49 )
        goto LABEL_98;
    }
  }
  v83 = (_DWORD *)v53;
  sub_434340(v53);
  v54 = v50[15];
  v55 = 0;
  if ( v54 <= 0 )
  {
LABEL_103:
    v80 = 0;
  }
  else
  {
    v56 = (_DWORD **)v50[14];
    while ( **v56 != dword_4D7DF4 )
    {
      ++v55;
      ++v56;
      if ( v55 >= v54 )
        goto LABEL_103;
    }
    v80 = *v56;
  }
  v57 = v80;
  for ( i = 0; i < v80[140]; ++i )
  {
    v59 = *(_DWORD *)(v57[139] + 4 * i);
    v85 = *(_DWORD *)(v59 + 4);
    v60 = *(this + 157);
    v61 = (const unsigned __int16 *)(v59 + 12);
    v62 = 0;
    if ( v60 <= 0 )
    {
LABEL_110:
      v64 = 0;
    }
    else
    {
      v63 = *(this + 156);
      while ( *(_DWORD *)(*(_DWORD *)v63 + 44) != 28 || *(_DWORD *)(*(_DWORD *)v63 + 48) != 4 )
      {
        ++v62;
        v63 += 4;
        if ( v62 >= v60 )
          goto LABEL_110;
      }
      v64 = *(_DWORD **)v63;
    }
    if ( sub_434450(v64, v61) == -1 )
      sub_434240((int)v61, v64, v85);
    v57 = v80;
  }
  sub_4344D0(v83, dword_4D7DFC);
  result = sub_43C070(this);
  if ( result >= 0 )
    return 0;
  return result;
}
