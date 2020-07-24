# This script segment is generated automatically by AutoPilot

# clear list
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_begin
    cg_default_interface_gen_bundle_begin
    AESL_LIB_XILADAPTER::native_axis_begin
}

# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 7 \
    name tree_V \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename tree_V \
    op interface \
    ports { tree_V_address0 { O 10 vector } tree_V_ce0 { O 1 bit } tree_V_q0 { I 24 vector } tree_V_address1 { O 10 vector } tree_V_ce1 { O 1 bit } tree_V_q1 { I 24 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'tree_V'"
}
}


# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 8 \
    name nodo_V \
    type fifo \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_nodo_V \
    op interface \
    ports { nodo_V_dout { I 11 vector } nodo_V_empty_n { I 1 bit } nodo_V_read { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 9 \
    name fatherSearch \
    type fifo \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_fatherSearch \
    op interface \
    ports { fatherSearch_dout { I 1 vector } fatherSearch_empty_n { I 1 bit } fatherSearch_read { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 10 \
    name relationship_V \
    type fifo \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_relationship_V \
    op interface \
    ports { relationship_V_dout { I 2 vector } relationship_V_empty_n { I 1 bit } relationship_V_read { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 11 \
    name nodo_V_out \
    type fifo \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_nodo_V_out \
    op interface \
    ports { nodo_V_out_din { O 11 vector } nodo_V_out_full_n { I 1 bit } nodo_V_out_write { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 12 \
    name nodo_V_out1 \
    type fifo \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_nodo_V_out1 \
    op interface \
    ports { nodo_V_out1_din { O 11 vector } nodo_V_out1_full_n { I 1 bit } nodo_V_out1_write { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 13 \
    name fatherSearch_out \
    type fifo \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_fatherSearch_out \
    op interface \
    ports { fatherSearch_out_din { O 1 vector } fatherSearch_out_full_n { I 1 bit } fatherSearch_out_write { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 14 \
    name fatherSearch_out2 \
    type fifo \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_fatherSearch_out2 \
    op interface \
    ports { fatherSearch_out2_din { O 1 vector } fatherSearch_out2_full_n { I 1 bit } fatherSearch_out2_write { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 15 \
    name relationship_V_out \
    type fifo \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_relationship_V_out \
    op interface \
    ports { relationship_V_out_din { O 2 vector } relationship_V_out_full_n { I 1 bit } relationship_V_out_write { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 16 \
    name relationship_V_out3 \
    type fifo \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_relationship_V_out3 \
    op interface \
    ports { relationship_V_out3_din { O 2 vector } relationship_V_out3_full_n { I 1 bit } relationship_V_out3_write { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 17 \
    name in1_V_V \
    type fifo \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_in1_V_V \
    op interface \
    ports { in1_V_V_din { O 24 vector } in1_V_V_full_n { I 1 bit } in1_V_V_write { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 18 \
    name in2_V_V \
    type fifo \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_in2_V_V \
    op interface \
    ports { in2_V_V_din { O 24 vector } in2_V_V_full_n { I 1 bit } in2_V_V_write { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id -1 \
    name ap_ctrl \
    type ap_ctrl \
    reset_level 1 \
    sync_rst true \
    corename ap_ctrl \
    op interface \
    ports { ap_done { O 1 bit } ap_idle { O 1 bit } ap_continue { I 1 bit } } \
} "
}


# Adapter definition:
set PortName ap_clk
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_clock] == "cg_default_interface_gen_clock"} {
eval "cg_default_interface_gen_clock { \
    id -2 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_clk \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-113\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}


# Adapter definition:
set PortName ap_rst
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_reset] == "cg_default_interface_gen_reset"} {
eval "cg_default_interface_gen_reset { \
    id -3 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_rst \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-114\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}



# merge
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_end
    cg_default_interface_gen_bundle_end
    AESL_LIB_XILADAPTER::native_axis_end
}


