INT_PTR __stdcall DialogFunc(HWND hDlg, UINT a2, WPARAM a3, LPARAM a4)
{
  UINT v4; // eax
  HWND v5; // eax
  UINT v6; // eax
  INT_PTR result; // eax
  UINT v8; // eax
  char *EngineInstance; // edi
  const WCHAR *v10; // edi
  HWND DlgItem; // eax
  BOOL v12; // [esp-4h] [ebp-410h]
  HICON IconW; // [esp-4h] [ebp-410h]
  WCHAR String[512]; // [esp+8h] [ebp-404h] BYREF

  if ( a2 == 272 )
  {
    EngineInstance = (char *)GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v10 = (const WCHAR *)(EngineInstance + 7292);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    SetWindowTextW(hDlg, v10);
    IconW = LoadIconW(0, (LPCWSTR)0x7F02);
    DlgItem = GetDlgItem(hDlg, 256);
    SendMessageW(DlgItem, 0x172u, 1u, (LPARAM)IconW);
    sub_419310(
      String,
      (wchar_t *)L"This program needs to use the Direct3D %d reference device.  This device implements the entire Direct3D"
                  " %d feature set, but runs very slowly.  Do you wish to continue?",
      a4,
      a4);
    SetDlgItemTextW(hDlg, 257, String);
    SetDlgItemTextW(hDlg, 6, L"&Yes");
    SetDlgItemTextW(hDlg, 7, L"&No");
    SetDlgItemTextW(hDlg, 5, &off_4BBA64);
    return 0;
  }
  if ( a2 != 273 )
    return 0;
  switch ( (__int16)a3 )
  {
    case 2:
    case 6:
      v8 = IsDlgButtonChecked(hDlg, 5);
      EndDialog(hDlg, v8 != 1 ? 6 : 134);
      result = 1;
      break;
    case 5:
      v4 = IsDlgButtonChecked(hDlg, 5);
      CheckDlgButton(hDlg, 5, v4 != 1);
      v12 = IsDlgButtonChecked(hDlg, 5) != 1;
      v5 = GetDlgItem(hDlg, 7);
      EnableWindow(v5, v12);
      return 0;
    case 7:
      v6 = IsDlgButtonChecked(hDlg, 5);
      EndDialog(hDlg, v6 != 1 ? 7 : 135);
      result = 1;
      break;
    default:
      return 0;
  }
  return result;
}
