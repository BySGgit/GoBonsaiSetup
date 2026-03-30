void *sub_4375D0()
{
  LARGE_INTEGER Frequency; // [esp+0h] [ebp-Ch] BYREF

  qword_4D8DD8 = 0;
  qword_4D8DE0 = 0;
  MEMORY[0x4D8DE4] = 0;
  qword_4D8DE8 = 0;
  MEMORY[0x4D8DEC] = 0;
  qword_4D8DF0 = 0;
  MEMORY[0x4D8DF4] = 0;
  Frequency.QuadPart = 0;
  byte_4D8DD1 = 1;
  QueryPerformanceFrequency(&Frequency);
  qword_4D8DD8 = Frequency.QuadPart;
  return &unk_4D8DD0;
}
