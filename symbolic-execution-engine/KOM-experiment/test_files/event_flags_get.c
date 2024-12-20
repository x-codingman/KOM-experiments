#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

UCHAR                   pool_start[9120];

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    _txm_module_kernel_call_dispatcher=_txm_module_manager_kernel_dispatch;
    TX_EVENT_FLAGS_GROUP * KLEE_TX_group_ptr;
    klee_make_symbolic_controllable(&KLEE_TX_group_ptr, sizeof(KLEE_TX_group_ptr), "KLEE_TX_group_ptr", true);
    ULONG KLEE_TX_requested_flags;
    klee_make_symbolic_controllable(&KLEE_TX_requested_flags, sizeof(KLEE_TX_requested_flags), "KLEE_TX_requested_flags", true);
    UINT KLEE_TX_get_option;
    klee_make_symbolic_controllable(&KLEE_TX_get_option, sizeof(KLEE_TX_get_option), "KLEE_TX_get_option", true);
    ULONG * KLEE_TX_actual_flags_ptr;
    klee_make_symbolic_controllable(&KLEE_TX_actual_flags_ptr, sizeof(KLEE_TX_actual_flags_ptr), "KLEE_TX_actual_flags_ptr", true);
    ULONG KLEE_TX_wait_option;
    klee_make_symbolic_controllable(&KLEE_TX_wait_option, sizeof(KLEE_TX_wait_option), "KLEE_TX_wait_option", true);
    m_txe_event_flags_get(KLEE_TX_group_ptr, KLEE_TX_requested_flags, KLEE_TX_get_option, KLEE_TX_actual_flags_ptr, KLEE_TX_wait_option);
}