void __usercall sub_4417C0(int a1@<edi>)
{
  int v1; // eax
  double v2; // st7
  int v3; // eax
  int v4; // edx
  int v5; // eax
  int v6; // edx
  double v7; // st7
  int (__thiscall *v8)(void *); // eax
  int EngineInstance; // esi
  int v10; // esi
  int v11; // eax
  int v12; // eax
  void *v13; // esi
  int v14; // eax
  double v15; // st7
  float *v16; // eax
  void *v17; // ecx
  void *v18; // eax
  _DWORD *v19; // eax
  _DWORD *v20; // ebp
  int v21; // ebx
  _DWORD *v22; // esi
  _DWORD *v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // esi
  int v27; // esi
  int v28; // eax
  float *v29; // eax
  void *v30; // ecx
  int v31; // eax
  int v32; // esi
  unsigned int v33; // ebp
  int v34; // ebx
  _DWORD *v35; // eax
  unsigned int v36; // ebp
  int v37; // ebx
  _DWORD *v38; // eax
  int v39; // eax
  void *v40; // [esp+0h] [ebp-6Ch]
  _DWORD *v41; // [esp+0h] [ebp-6Ch]
  _DWORD *v42; // [esp+0h] [ebp-6Ch]
  float v43; // [esp+18h] [ebp-54h]
  float v44; // [esp+18h] [ebp-54h]
  float v45; // [esp+18h] [ebp-54h]
  float v46; // [esp+18h] [ebp-54h]
  float v47; // [esp+1Ch] [ebp-50h]
  float v48; // [esp+1Ch] [ebp-50h]
  float v49; // [esp+1Ch] [ebp-50h]
  int v50; // [esp+20h] [ebp-4Ch]
  int v51; // [esp+24h] [ebp-48h]
  int v52; // [esp+28h] [ebp-44h]
  float v53; // [esp+2Ch] [ebp-40h]
  float v54; // [esp+2Ch] [ebp-40h]
  float v55; // [esp+2Ch] [ebp-40h]
  float v56; // [esp+30h] [ebp-3Ch] BYREF
  float v57; // [esp+34h] [ebp-38h]
  float v58; // [esp+38h] [ebp-34h]
  float v59; // [esp+3Ch] [ebp-30h]
  void *v60; // [esp+40h] [ebp-2Ch] BYREF
  float v61; // [esp+44h] [ebp-28h]
  float v62; // [esp+48h] [ebp-24h]
  float v63; // [esp+4Ch] [ebp-20h]
  int v64; // [esp+50h] [ebp-1Ch]
  unsigned int v65; // [esp+54h] [ebp-18h]
  int v66; // [esp+68h] [ebp-4h]

  if ( 0.0 != *(float *)(a1 + 116) )
  {
    v53 = (double)(*(int (__thiscall **)(void *))(*(_DWORD *)dword_4D82D0 + 4))(dword_4D82D0) * flt_4CA64C;
    v1 = (*(int (__thiscall **)(void *))(*(_DWORD *)dword_4D82D0 + 8))(dword_4D82D0);
    v43 = *(float *)(a1 + 116);
    v56 = *(float *)(v1 + 40);
    v2 = 0.0;
    if ( v43 >= 0.0 )
    {
      v2 = 1.0;
      if ( v43 <= 1.0 )
        v2 = v43;
    }
    v44 = v2;
    v54 = (v53 - 0.0) * v44 + 0.0;
    v45 = v54 - (double)SLODWORD(v56);
    v3 = (**(int (__thiscall ***)(void *))dword_4D82D0)(dword_4D82D0);
    v4 = *(_DWORD *)dword_4D82D0;
    v56 = *(float *)&v3;
    v55 = (float)v3;
    v5 = (*(int (__thiscall **)(void *))(v4 + 4))(dword_4D82D0);
    v6 = *(_DWORD *)dword_4D82D0;
    v56 = *(float *)&v5;
    v7 = (double)v5;
    v8 = *(int (__thiscall **)(void *))(v6 + 8);
    *(float *)&v60 = v7;
    v47 = (float)*(int *)(v8(dword_4D82D0) + 40);
    v56 = v55 * 0.5;
    v57 = v45 - 0.5 * *(float *)&v60 + v47 + 4.0;
    EngineInstance = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v10 = *(_DWORD *)(EngineInstance + 4);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v10 + 228))(v10, 137, 1);
    *(float *)&v60 = 0.0;
    v61 = 0.0;
    v62 = 0.0;
    v63 = 0.2;
    sub_43FAD0(&v56);
    v11 = (*(int (__thiscall **)(void *))(*(_DWORD *)dword_4D82D0 + 8))(dword_4D82D0);
    sub_43F800(v11);
    v12 = (*(int (__thiscall **)(void *))(*(_DWORD *)dword_4D82D0 + 8))(dword_4D82D0);
    *(_DWORD *)(v12 + 32) = 20;
    *(_DWORD *)(v12 + 36) = (int)v45;
    LOWORD(v60) = 0;
    v65 = 7;
    v64 = 0;
    sub_4037B0(a1 + 48, 0);
    v66 = 0;
    v13 = dword_4D82D0;
    v14 = *((_DWORD *)dword_4D82D0 + 64);
    if ( v14 == -1 )
      v15 = 0.0;
    else
      v15 = (double)(dword_4D7F94 - v14) / 1000.0 + flt_4D7F98;
    v48 = v15;
    if ( (int)(v48 * flt_4CA650) % 2 )
    {
      sub_444B50(95);
      v13 = dword_4D82D0;
    }
    v16 = (float *)(*(int (__thiscall **)(void *))(*(_DWORD *)v13 + 8))(v13);
    v16[4] = 1.0;
    v16[5] = 1.0;
    v16[6] = 1.0;
    v17 = dword_4D82D0;
    v16[7] = 1.0;
    v18 = v60;
    if ( v65 < 8 )
      v18 = &v60;
    v40 = v18;
    (*(void (__thiscall **)(void *))(*(_DWORD *)v17 + 8))(v17);
    sub_43F5C0(v40, 1);
    v19 = *(_DWORD **)(a1 + 36);
    v20 = (_DWORD *)*v19;
    if ( (_DWORD *)*v19 != v19 )
    {
      do
      {
        v21 = v20[9];
        v22 = v20 + 2;
        v51 = v20[11];
        v50 = v20[10];
        v52 = v20[12];
        v23 = (_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)dword_4D82D0 + 8))(dword_4D82D0);
        v23[4] = v21;
        v23[5] = v50;
        v23[6] = v51;
        v23[7] = v52;
        if ( v20[7] >= 8u )
          v22 = (_DWORD *)*v22;
        (*(void (**)(void))(*(_DWORD *)dword_4D82D0 + 8))();
        sub_43F5C0(v22, 1);
        v20 = (_DWORD *)*v20;
      }
      while ( v20 != *(_DWORD **)(a1 + 36) );
    }
    v24 = (*(int (__thiscall **)(void *))(*(_DWORD *)dword_4D82D0 + 8))(dword_4D82D0);
    sub_43F930(v24);
    v66 = -1;
    if ( v65 >= 8 )
      operator delete(v60);
    v25 = *(_DWORD *)(a1 + 76);
    v65 = 7;
    v64 = 0;
    LOWORD(v60) = 0;
    if ( v25 != *(_DWORD *)(a1 + 80) )
    {
      v46 = (double)*(int *)((*(int (__thiscall **)(void *))(*(_DWORD *)dword_4D82D0 + 8))(dword_4D82D0) + 40)
          + 4.0
          + v45;
      if ( (unsigned int)((*(_DWORD *)(a1 + 80) - *(_DWORD *)(a1 + 76)) / 28) > 1 )
      {
        v49 = (double)(unsigned int)((*(_DWORD *)(a1 + 80) - *(_DWORD *)(a1 + 76)) / 28 - 1)
            * (double)*(int *)((*(int (__thiscall **)(void *))(*(_DWORD *)dword_4D82D0 + 8))(dword_4D82D0) + 40);
        (*(void (__thiscall **)(void *))(*(_DWORD *)dword_4D82D0 + 8))(dword_4D82D0);
        *(float *)&v60 = 180.0;
        v61 = v46 + v49 * 0.5 + 4.0;
        v26 = GetEngineInstance();
        if ( byte_4CA649 )
          EnterCriticalSection(&CriticalSection);
        v27 = *(_DWORD *)(v26 + 4);
        if ( byte_4CA649 )
          LeaveCriticalSection(&CriticalSection);
        (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v27 + 228))(v27, 137, 1);
        v56 = 0.0;
        v57 = 0.0;
        v58 = 0.0;
        v59 = 0.2;
        sub_43FAD0(&v60);
      }
      v28 = (*(int (__thiscall **)(void *))(*(_DWORD *)dword_4D82D0 + 8))(dword_4D82D0);
      sub_43F800(v28);
      v29 = (float *)(*(int (__thiscall **)(void *))(*(_DWORD *)dword_4D82D0 + 8))(dword_4D82D0);
      v29[4] = 0.80000001;
      v29[5] = 0.80000001;
      v29[6] = 0.80000001;
      v30 = dword_4D82D0;
      v29[7] = 1.0;
      v31 = (*(int (__thiscall **)(void *))(*(_DWORD *)v30 + 8))(v30);
      *(_DWORD *)(v31 + 32) = 30;
      *(_DWORD *)(v31 + 36) = (int)v46;
      v32 = *(_DWORD *)(a1 + 76);
      v33 = *(_DWORD *)(a1 + 108) + 1;
      if ( v33 < (*(_DWORD *)(a1 + 80) - v32) / 28 )
      {
        v34 = 28 * v33;
        do
        {
          v35 = (_DWORD *)(v34 + v32);
          if ( *(_DWORD *)(v34 + v32 + 20) >= 8u )
            v35 = (_DWORD *)*v35;
          v41 = v35;
          (*(void (**)(void))(*(_DWORD *)dword_4D82D0 + 8))();
          sub_43F5C0(v41, 0);
          v32 = *(_DWORD *)(a1 + 76);
          ++v33;
          v34 += 28;
        }
        while ( v33 < (*(_DWORD *)(a1 + 80) - v32) / 28 );
      }
      v36 = 0;
      if ( *(_DWORD *)(a1 + 108) )
      {
        v37 = 0;
        do
        {
          v38 = (_DWORD *)(v37 + *(_DWORD *)(a1 + 76));
          if ( v38[5] >= 8u )
            v38 = (_DWORD *)*v38;
          v42 = v38;
          (*(void (**)(void))(*(_DWORD *)dword_4D82D0 + 8))();
          sub_43F5C0(v42, 0);
          ++v36;
          v37 += 28;
        }
        while ( v36 < *(_DWORD *)(a1 + 108) );
      }
      v39 = (*(int (__thiscall **)(void *))(*(_DWORD *)dword_4D82D0 + 8))(dword_4D82D0);
      sub_43F930(v39);
    }
  }
}
