#include "tx_api.h"
#include "klee/klee.h"
#include "klee_help.h"

extern TX_THREAD *    _tx_thread_current_ptr;

UCHAR                   pool_start[9120];

int main()
{
    klee_make_symbolic_controllable(&_tx_thread_current_ptr, sizeof(_tx_thread_current_ptr), "_tx_thread_current_ptr", false);
    _txm_module_kernel_call_dispatcher=_txm_module_manager_kernel_dispatch;
    TX_THREAD * KLEE_TX_thread_ptr;
    klee_make_symbolic_controllable(&KLEE_TX_thread_ptr, sizeof(KLEE_TX_thread_ptr), "KLEE_TX_thread_ptr", true);
    ULONG KLEE_TX_new_time_slice;
    klee_make_symbolic_controllable(&KLEE_TX_new_time_slice, sizeof(KLEE_TX_new_time_slice), "KLEE_TX_new_time_slice", true);
    ULONG * KLEE_TX_old_time_slice;
    klee_make_symbolic_controllable(&KLEE_TX_old_time_slice, sizeof(KLEE_TX_old_time_slice), "KLEE_TX_old_time_slice", true);
    m_txe_thread_time_slice_change(KLEE_TX_thread_ptr, KLEE_TX_new_time_slice, KLEE_TX_old_time_slice);
}