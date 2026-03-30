int sub_438B90()
{
  int v0; // eax
  _DWORD *v1; // ecx
  int v2; // eax
  int v3; // eax
  _DWORD *v4; // ecx
  void (*v5)(void); // edx
  int v6; // eax
  _DWORD *v7; // ecx
  void (*v8)(void); // edx
  int v9; // eax
  _DWORD *v10; // edx
  int v11; // eax
  int v12; // eax
  int v14; // [esp+Ch] [ebp-4h] BYREF

  byte_4D53D9 = 1;
  sub_42F300((int)&unk_4D53D8, 0, L"Arial", 15, 400);
  sub_42F300((int)&unk_4D53D8, 1, L"Arial", 28, 700);
  v0 = 0;
  if ( dword_4D5648 > 0 )
  {
    while ( 1 )
    {
      v1 = *(_DWORD **)(dword_4D5644 + 4 * v0);
      if ( *v1 == 1 && !v1[1] )
        break;
      if ( ++v0 >= dword_4D5648 )
        goto LABEL_8;
    }
    if ( v1 != (_DWORD *)-8 )
    {
      v1[4] = 6;
      v14 = 0;
      sub_42FAE0((int)&unk_4D53D8, -1, (int)L"Direct3D Settings", 10, 5, 400, 50, &v14);
      v2 = **(_DWORD **)(v14 + 32);
      *(_DWORD *)(v2 + 4) = 1;
      *(_DWORD *)(v2 + 8) = 0;
    }
  }
LABEL_8:
  sub_42FAE0((int)&unk_4D53D8, -1, (int)L"API Version", 10, 35, 180, 23, 0);
  sub_42FE50((int)&unk_4D53D8, 27, 35, 300);
  sub_42FAE0((int)&unk_4D53D8, -1, (int)L"Display Adapter", 10, 60, 180, 23, 0);
  sub_42FE50((int)&unk_4D53D8, 3, 60, 300);
  sub_42FAE0((int)&unk_4D53D8, -1, (int)L"Render Device", 10, 85, 180, 23, 0);
  sub_42FE50((int)&unk_4D53D8, 4, 85, 300);
  sub_42FD50((int)&unk_4D53D8, 5, 256, (int)L"Windowed", 240, 115, 300, 16, 0);
  sub_42FC70(
    (int)&unk_4D53D8,
    25,
    (int)L"Clip to device when window spans across multiple monitors",
    250,
    136,
    400,
    16,
    0);
  sub_42FD50((int)&unk_4D53D8, 6, 256, (int)L"Full Screen", 240, 157, 300, 16, 0);
  sub_42FAE0((int)&unk_4D53D8, 8, (int)L"Adapter Format", 10, 175, 180, 23, 0);
  sub_42FE50((int)&unk_4D53D8, 7, 175, 300);
  sub_42FAE0((int)&unk_4D53D8, 10, (int)L"Resolution", 10, 200, 180, 23, 0);
  sub_42FE50((int)&unk_4D53D8, 9, 200, 200);
  v3 = 0;
  if ( dword_4D563C <= 0 )
  {
LABEL_12:
    v4 = 0;
  }
  else
  {
    while ( 1 )
    {
      v4 = *(_DWORD **)(dword_4D5638 + 4 * v3);
      if ( v4[11] == 9 && v4[12] == 4 )
        break;
      if ( ++v3 >= dword_4D563C )
        goto LABEL_12;
    }
  }
  v5 = *(void (**)(void))(*v4 + 76);
  v4[153] = 106;
  v5();
  sub_42FC70((int)&unk_4D53D8, 26, (int)L"Show All Aspect Ratios", 420, 200, 200, 23, 0);
  sub_42FAE0((int)&unk_4D53D8, 12, (int)L"Refresh Rate", 10, 225, 180, 23, 0);
  sub_42FE50((int)&unk_4D53D8, 11, 225, 300);
  sub_42FAE0((int)&unk_4D53D8, 14, (int)L"Back Buffer Format", 10, 260, 180, 23, 0);
  sub_42FE50((int)&unk_4D53D8, 13, 260, 300);
  sub_42FAE0((int)&unk_4D53D8, 16, (int)L"Depth/Stencil Format", 10, 285, 180, 23, 0);
  sub_42FE50((int)&unk_4D53D8, 15, 285, 300);
  sub_42FAE0((int)&unk_4D53D8, 18, (int)L"Multisample Type", 10, 310, 180, 23, 0);
  sub_42FE50((int)&unk_4D53D8, 17, 310, 300);
  sub_42FAE0((int)&unk_4D53D8, 20, (int)L"Multisample Quality", 10, 335, 180, 23, 0);
  sub_42FE50((int)&unk_4D53D8, 19, 335, 300);
  sub_42FAE0((int)&unk_4D53D8, 22, (int)L"Vertex Processing", 10, 360, 180, 23, 0);
  sub_42FE50((int)&unk_4D53D8, 21, 360, 300);
  sub_42FAE0((int)&unk_4D53D8, 24, (int)L"Vertical Sync", 10, 385, 180, 23, 0);
  sub_42FE50((int)&unk_4D53D8, 23, 385, 300);
  sub_42FAE0((int)&unk_4D53D8, 29, (int)L"Adapter Output", 10, 175, 180, 23, 0);
  sub_42FE50((int)&unk_4D53D8, 28, 175, 300);
  sub_42FAE0((int)&unk_4D53D8, 31, (int)L"Resolution", 10, 200, 180, 23, 0);
  sub_42FE50((int)&unk_4D53D8, 30, 200, 200);
  v6 = 0;
  if ( dword_4D563C <= 0 )
  {
LABEL_17:
    v7 = 0;
  }
  else
  {
    while ( 1 )
    {
      v7 = *(_DWORD **)(dword_4D5638 + 4 * v6);
      if ( v7[11] == 30 && v7[12] == 4 )
        break;
      if ( ++v6 >= dword_4D563C )
        goto LABEL_17;
    }
  }
  v8 = *(void (**)(void))(*v7 + 76);
  v7[153] = 106;
  v8();
  sub_42FAE0((int)&unk_4D53D8, 33, (int)L"Refresh Rate", 10, 225, 180, 23, 0);
  sub_42FE50((int)&unk_4D53D8, 32, 225, 300);
  sub_42FAE0((int)&unk_4D53D8, 35, (int)L"Back Buffer Format", 10, 260, 180, 23, 0);
  sub_42FE50((int)&unk_4D53D8, 34, 260, 300);
  sub_42FAE0((int)&unk_4D53D8, 37, (int)L"Multisample Count", 10, 285, 180, 23, 0);
  sub_42FE50((int)&unk_4D53D8, 36, 285, 300);
  sub_42FAE0((int)&unk_4D53D8, 39, (int)L"Multisample Quality", 10, 310, 180, 23, 0);
  sub_42FE50((int)&unk_4D53D8, 38, 310, 300);
  sub_42FAE0((int)&unk_4D53D8, 41, (int)L"Vertical Sync", 10, 335, 180, 23, 0);
  sub_42FE50((int)&unk_4D53D8, 40, 335, 300);
  sub_42FC70((int)&unk_4D53D8, 42, (int)L"Create Debug Device", 200, 365, 180, 23, 0);
  sub_42FBA0((int)&unk_4D53D8, 1, (int)&off_4BB0A4, 230, 440, 73, 31, 0, 0);
  sub_42FBA0((int)&unk_4D53D8, 2, (int)L"Cancel", 315, 440, 73, 31, 0, 1);
  word_4D56C8 = 257;
  sub_42F300((int)&word_4D56C8, 0, L"Arial", 15, 400);
  sub_42F300((int)&word_4D56C8, 1, L"Arial", 28, 700);
  v9 = 0;
  if ( dword_4D5938 > 0 )
  {
    while ( 1 )
    {
      v10 = *(_DWORD **)(dword_4D5934 + 4 * v9);
      if ( *v10 == 1 && !v10[1] )
        break;
      if ( ++v9 >= dword_4D5938 )
        goto LABEL_25;
    }
    if ( v10 != (_DWORD *)-8 )
    {
      v10[4] = 6;
      v14 = 0;
      sub_42FAE0((int)&word_4D56C8, -1, (int)L"Do you want to keep these display settings?", 10, 5, 640, 50, &v14);
      v11 = **(_DWORD **)(v14 + 32);
      *(_DWORD *)(v11 + 4) = 1;
      *(_DWORD *)(v11 + 8) = 0;
      sub_42FAE0((int)&word_4D56C8, 45, (int)word_4B765C, 10, 90, 640, 30, &v14);
      v12 = **(_DWORD **)(v14 + 32);
      *(_DWORD *)(v12 + 4) = 0;
      *(_DWORD *)(v12 + 8) = 0;
    }
  }
LABEL_25:
  sub_42FBA0((int)&word_4D56C8, 43, (int)L"Yes", 230, 50, 73, 31, 0, 0);
  return sub_42FBA0((int)&word_4D56C8, 44, (int)L"No", 315, 50, 73, 31, 0, 1);
}
