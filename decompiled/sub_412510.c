char sub_412510()
{
  char result; // al

  sub_44F260();
  if ( !sub_44F3F0(1, (wchar_t *)L"bark.png") )
    sub_44F480(1, 0xBB8u, (wchar_t *)L"bark");
  if ( !sub_44F3F0(2, (wchar_t *)L"leaf.png") )
    sub_44F480(2, 0xBB9u, (wchar_t *)L"leaf");
  if ( !sub_44F3F0(3, (wchar_t *)L"cloud.png") )
    sub_44F480(3, 0xBBAu, (wchar_t *)L"cloud");
  if ( !sub_44F3F0(4, (wchar_t *)L"pot.png") )
    sub_44F480(4, 0xBBBu, (wchar_t *)L"pot");
  if ( !sub_44F3F0(5, (wchar_t *)L"soil.png") )
    sub_44F480(5, 0xBBCu, (wchar_t *)L"soil");
  if ( !sub_44F3F0(6, (wchar_t *)L"circle.png") )
    sub_44F480(6, 0xBBDu, (wchar_t *)L"circle");
  result = sub_44F3F0(7, (wchar_t *)L"bumpTest.png");
  if ( !result )
    return sub_44F480(7, 0xBBEu, (wchar_t *)L"bumpTest");
  return result;
}
