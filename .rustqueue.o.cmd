savedcmd_rustqueue.o := OBJTREE=/usr/src/linux-headers-7.0.0-15-generic RUST_MODFILE=./rustqueue rustc --edition=2021 -Zbinary_dep_depinfo=y -Astable_features -Aunused_features -Dnon_ascii_idents -Dunsafe_op_in_unsafe_fn -Wmissing_docs -Wrust_2018_idioms -Wunreachable_pub -Wclippy::all -Wclippy::as_ptr_cast_mut -Wclippy::as_underscore -Wclippy::cast_lossless -Wclippy::ignored_unit_patterns -Wclippy::mut_mut -Wclippy::needless_bitwise_bool -Aclippy::needless_lifetimes -Wclippy::no_mangle_with_rust_abi -Wclippy::ptr_as_ptr -Wclippy::ptr_cast_constness -Wclippy::ref_as_ptr -Wclippy::undocumented_unsafe_blocks -Wclippy::unnecessary_safety_comment -Wclippy::unnecessary_safety_doc -Wrustdoc::missing_crate_level_docs -Wrustdoc::unescaped_backticks -Cpanic=abort -Cembed-bitcode=n -Clto=n -Cforce-unwind-tables=n -Ccodegen-units=1 -Csymbol-mangling-version=v0 -Crelocation-model=static -Zfunction-sections=n -Wclippy::float_arithmetic --target=aarch64-unknown-none-softfloat -Cforce-unwind-tables=n -Zbranch-protection=pac-ret -Zfixed-x18 -Copt-level=2 -Cdebug-assertions=n -Coverflow-checks=y -Cforce-frame-pointers=y -Zsanitizer=shadow-call-stack -Zdwarf-version=5 -Cdebuginfo=2  --cfg MODULE  @/usr/src/linux-headers-7.0.0-15-generic/include/generated/rustc_cfg -Zallow-features=asm_const,asm_goto,arbitrary_self_types,lint_reasons,offset_of_nested,raw_ref_op,slice_ptr_len,strict_provenance,used_with_arg -Zcrate-attr=no_std -Zcrate-attr='feature(asm_const,asm_goto,arbitrary_self_types,lint_reasons,offset_of_nested,raw_ref_op,slice_ptr_len,strict_provenance,used_with_arg)' -Zunstable-options --extern pin_init --extern kernel --crate-type rlib -L /usr/src/linux-headers-7.0.0-15-generic/rust/ --crate-name rustqueue --sysroot=/dev/null --out-dir ./ --emit=dep-info=./.rustqueue.o.d --emit=obj=rustqueue.o rustqueue.rs 

source_rustqueue.o := rustqueue.rs

deps_rustqueue.o := \
  /usr/src/linux-headers-7.0.0-15-generic/rust/libcore.rmeta \
  /usr/src/linux-headers-7.0.0-15-generic/rust/libkernel.rmeta \
  /usr/src/linux-headers-7.0.0-15-generic/rust/libffi.rmeta \
  /usr/src/linux-headers-7.0.0-15-generic/rust/libcompiler_builtins.rmeta \
  /usr/src/linux-headers-7.0.0-15-generic/rust/libpin_init.rmeta \
  /usr/src/linux-headers-7.0.0-15-generic/rust/libpin_init_internal.so \
  /usr/src/linux-headers-7.0.0-15-generic/rust/libmacros.so \
  /usr/src/linux-headers-7.0.0-15-generic/rust/libbuild_error.rmeta \
  /usr/src/linux-headers-7.0.0-15-generic/rust/libbindings.rmeta \
  /usr/src/linux-headers-7.0.0-15-generic/rust/libuapi.rmeta \

rustqueue.o: $(deps_rustqueue.o)

$(deps_rustqueue.o):
