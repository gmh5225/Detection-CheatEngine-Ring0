#define CE_STR_1 ("dbvm-mode")

__declspec(noinline) void DbgPrintCallback(_In_ PSTRING Output, _In_ ULONG ComponentId, _In_ ULONG Level)
{
    if (!Output)
    {
        return;
    }

    if (ComponentId == DPFLTR_MM_ID && Level == DPFLTR_SETUP_ID)
    {
        // TODO: check sth you want
    }

    if (ComponentId != DPFLTR_DEFAULT_ID)
    {
        return;
    }

    if (Level != DPFLTR_INFO_LEVEL)
    {
        return;
    }

    char szOutput[MAX_PATH + 1];
    RtlSecureZeroMemory(szOutput, sizeof(szOutput));
    SafeCopyMemory(szOutput, Output->Buffer, min(Output->Length, MAX_PATH));
    if (_strcmp_a(szOutput, CE_STR_1) == 0)
    {
        // TODO: report
        return; 
    }
}


// load
DbgSetDebugPrintCallback(DbgPrintCallback, TRUE);

// unload
DbgSetDebugPrintCallback(DbgPrintCallback, FALSE);
