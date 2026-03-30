BOOL _heap_init()
{
  hHeap = HeapCreate(0, 0x1000u, 0);
  return hHeap != 0;
}
