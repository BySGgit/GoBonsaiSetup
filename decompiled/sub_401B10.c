float *__thiscall sub_401B10(int this, float *a2)
{
  float *v3; // eax
  float *v4; // ebx
  float *v5; // eax
  float *v6; // eax
  _DWORD **v7; // eax
  _DWORD *v8; // ebx
  float *v9; // eax
  float v11[3]; // [esp+14h] [ebp-40h] BYREF
  float v12[3]; // [esp+20h] [ebp-34h] BYREF
  float v13[3]; // [esp+2Ch] [ebp-28h] BYREF
  float v14[6]; // [esp+38h] [ebp-1Ch] BYREF

  v3 = sub_401500(v13, flt_4D5374, *(float *)(this + 36));
  v4 = sub_4013F0(v11, v3, (float *)(this + 24));
  v5 = sub_401500(v12, flt_4D5374, *(float *)(this + 36));
  v6 = sub_401430(v14, v5, (float *)(this + 24));
  *a2 = *v6;
  a2[1] = v6[1];
  a2[2] = v6[2];
  a2[3] = *v4;
  a2[4] = v4[1];
  a2[5] = v4[2];
  v7 = *(_DWORD ***)(this + 168);
  v8 = *v7;
  if ( *v7 != v7 )
  {
    do
    {
      v9 = (float *)sub_401B10(v14);
      sub_401610(v9, a2);
      v8 = (_DWORD *)*v8;
    }
    while ( v8 != *(_DWORD **)(this + 168) );
  }
  return a2;
}
