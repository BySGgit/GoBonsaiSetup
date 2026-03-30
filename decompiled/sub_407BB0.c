float *sub_407BB0()
{
  HWND v0; // esi
  HWND v1; // eax
  float *result; // eax
  HWND v3; // eax
  HWND v4; // eax
  struct tagPOINT Point; // [esp+Ch] [ebp-28h] BYREF
  struct tagPOINT v6; // [esp+14h] [ebp-20h] BYREF
  struct tagPOINT v7; // [esp+1Ch] [ebp-18h] BYREF
  int v8; // [esp+30h] [ebp-4h]

  v0 = (HWND)sub_41B5D0();
  if ( GetFocus() == v0 )
  {
    byte_4D8C9C = 0;
    if ( !(_BYTE)word_4D8C9A || HIBYTE(word_4D8C98) )
    {
      HIBYTE(word_4D8C9A) = 0;
    }
    else
    {
      byte_4D8C9C = HIBYTE(word_4D8C9A) == 0;
      HIBYTE(word_4D8C9A) = 1;
    }
    byte_4D8CA5 = 0;
    if ( (_BYTE)word_4D8CA3 )
    {
      byte_4D8CA5 = HIBYTE(word_4D8CA3) == 0;
      HIBYTE(word_4D8CA3) = 1;
    }
    else
    {
      word_4D8CA3 = 0;
    }
    byte_4D8CA0 = 0;
    if ( (_BYTE)word_4D8C9E || byte_4D8CA2 || (_BYTE)word_4D8C9A && HIBYTE(word_4D8C98) )
    {
      if ( !HIBYTE(word_4D8C9E) )
        byte_4D8CA0 = 1;
      HIBYTE(word_4D8C9E) = 1;
    }
    else
    {
      HIBYTE(word_4D8C9E) = 0;
    }
    byte_4D8CA2 = 0;
    qword_4D8CB4 = qword_4D8CAC;
    GetCursorPos(&v7);
    v3 = (HWND)sub_41B5D0();
    ScreenToClient(v3, &v7);
    *(float *)&Point.x = (float)v7.x;
    *(float *)&v6.x = (float)v7.y;
    LODWORD(qword_4D8CAC) = Point.x;
    Point.y = v6.x;
    HIDWORD(qword_4D8CAC) = v6.x;
    result = sub_407B90((float *)&v6.x, (float *)&qword_4D8CB4, (float *)&qword_4D8CAC);
    flt_4D8CBC = *result;
    flt_4D8CC0 = result[1];
    if ( (_BYTE)word_4D8CA3
      && (qword_4D8CAC = qword_4D8CB4,
          v6.x = (int)*(float *)&qword_4D8CB4,
          v6.y = (int)*((float *)&qword_4D8CB4 + 1),
          v4 = (HWND)sub_41B5D0(),
          ClientToScreen(v4, &v6),
          result = (float *)SetCursorPos(v6.x, v6.y),
          (_BYTE)word_4D8CA3) )
    {
      if ( !byte_4D8CC4 )
        result = (float *)ShowCursor(0);
      byte_4D8CC4 = 1;
    }
    else
    {
      if ( byte_4D8CC4 )
        result = (float *)ShowCursor(1);
      byte_4D8CC4 = 0;
    }
    if ( (dword_4D8EC0 & 1) == 0 )
    {
      dword_4D8EC0 |= 1u;
      v8 = 0;
      sub_43FD00();
      result = (float *)atexit(sub_472560);
    }
    if ( byte_4D8E90 )
    {
      dword_4D8C94 = 0;
      word_4D8C98 = 0;
    }
  }
  else
  {
    word_4D8C9A = 0;
    word_4D8C9E = 0;
    word_4D8CA3 = 0;
    qword_4D8CB4 = qword_4D8CAC;
    GetCursorPos(&Point);
    v1 = (HWND)sub_41B5D0();
    ScreenToClient(v1, &Point);
    *(float *)&v6.x = (float)Point.x;
    *(float *)&v6.y = (float)Point.y;
    qword_4D8CAC = (__int64)v6;
    result = sub_407B90((float *)&v6.x, (float *)&qword_4D8CB4, (float *)&qword_4D8CAC);
    flt_4D8CBC = *result;
    flt_4D8CC0 = result[1];
  }
  return result;
}
