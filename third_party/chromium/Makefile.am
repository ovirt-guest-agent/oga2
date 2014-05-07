SUBDIRS=third_party/icu

noinst_LTLIBRARIES=				\
	libbase.la					\
	libevent.la					\
	libipc.la					\
	$(NULL)

noinst_PROGRAMS=test
test_SOURCES=test.cc
test_LDFLAGS=-pthread -lpthread
test_LDADD=\
	libbase.la						\
	libevent.la						\
	libipc.la						\
	third_party/icu/libicui18n.la	\
	$(NULL)

libbase_la_CXXFLAGS=							\
	-DCOMPONENT_BUILD							\
	-DBASE_IMPLEMENTATION						\
	-DICU_UTIL_DATA_IMPL=ICU_UTIL_DATA_STATIC	\
	$(NULL)

#
# base/
#

libbase_la_SOURCES=						\
	base/at_exit.cc						\
	base/atomicops_internals_x86_gcc.cc	\
	base/barrier_closure.cc				\
	base/base64.cc						\
	third_party/modp_b64/modp_b64.cc	\
	base/base_paths.cc					\
	base/base_switches.cc				\
	base/base_switches.cc				\
	base/big_endian.cc					\
	base/bind_helpers.cc				\
	base/build_time.cc					\
	base/callback_helpers.cc			\
	base/callback_internal.cc			\
	base/command_line.cc				\
	base/cpu.cc							\
	base/environment.cc					\
	base/file_util.cc					\
	base/guid.cc						\
	base/hash.cc						\
	base/ini_parser.cc					\
	base/lazy_instance.cc				\
	base/md5.cc							\
	base/location.cc					\
	base/logging.cc						\
	base/path_service.cc				\
	base/pending_task.cc				\
	base/pickle.cc						\
	base/platform_file.cc				\
	base/rand_util.cc					\
	base/run_loop.cc					\
	base/scoped_native_library.cc		\
	base/sequence_checker_impl.cc		\
	base/sequenced_task_runner.cc		\
	base/sha1_portable.cc				\
	base/supports_user_data.cc			\
	base/sys_info.cc					\
	base/task_runner.cc					\
	base/thread_task_runner_handle.cc	\
	base/tracked_objects.cc				\
	base/tracking_info.cc				\
	base/value_conversions.cc			\
	base/values.cc						\
	base/version.cc						\
	base/vlog.cc						\
	$(NULL)

if OGA_OS_POSIX
libbase_la_SOURCES+=					\
	base/safe_strerror_posix.cc		\
	base/base_paths.cc				\
	base/guid_posix.cc				\
	base/native_library_posix.cc	\
	base/platform_file_posix.cc		\
	base/rand_util_posix.cc			\
	base/sync_socket_posix.cc			\
	$(NULL)

if OGA_OS_LINUX
libbase_la_SOURCES+=					\
	base/file_util_linux.cc			\
	base/linux_util.cc				\
	base/sys_info_linux.cc			\
	$(NULL)
else
# Generic POSIX
libbase_la_SOURCES+=					\
	base/file_util_posix.cc			\
	base/sys_info_posix.cc			\
	$(NULL)
endif
endif

if OGA_OS_WIN
libbase_la_SOURCES+=					\
	base/base_paths_win.cc			\
	base/file_util_win.cc			\
	base/file_version_info_win.cc	\
	base/guid_win.cc				\
	base/logging_win.cc				\
	base/native_library_win.cc		\
	base/platform_file_win.cc		\
	base/rand_util_win.cc			\
	base/sys_info_win.cc			\
	base/sync_socket_win.cc			\
	$(NULL)
endif


#
# base/memory
#

libbase_la_SOURCES+=							\
	base/memory/aligned_memory.cc					\
	base/memory/memory_pressure_listener.cc			\
	base/memory/ref_counted.cc						\
	base/memory/ref_counted_memory.cc				\
	base/memory/shared_memory_posix.cc				\
	base/memory/singleton.cc						\
	base/memory/weak_ptr.cc							\
	$(NULL)

if OGA_OS_WIN
libbase_la_SOURCES+=							\
	base/memory/shared_memory_win.cc				\
	$(NULL)
endif

if OGA_OS_POSIX
libbase_la_SOURCES+=							\
	base/memory/shared_memory_posix.cc				\
	$(NULL)
endif

#
# base/i18n
#
libbase_la_SOURCES+=								\
	base/i18n/bidi_line_iterator.cc					\
	base/i18n/break_iterator.cc						\
	base/i18n/build_utf8_validator_tables.cc		\
	base/i18n/case_conversion.cc					\
	base/i18n/char_iterator.cc						\
	base/i18n/file_util_icu.cc						\
	base/i18n/i18n_constants.cc						\
	base/i18n/icu_encoding_detection.cc				\
	base/i18n/icu_string_conversions.cc				\
	base/i18n/icu_util.cc							\
	base/i18n/number_formatting.cc					\
	base/i18n/rtl.cc								\
	base/i18n/streaming_utf8_validator.cc			\
	base/i18n/string_compare.cc						\
	base/i18n/string_search.cc						\
	base/i18n/time_formatting.cc					\
	base/i18n/timezone.cc							\
	base/i18n/utf8_validator_tables.cc				\
	$(NULL)



#
# base/files
#

libbase_la_SOURCES+=							\
	base/files/file.cc							\
	base/files/file_enumerator.cc				\
	base/files/file_path.cc						\
	base/files/file_path_constants.cc			\
	base/files/file_path_watcher.cc				\
	base/files/file_proxy.cc					\
	base/files/file_util_proxy.cc				\
	base/files/important_file_writer.cc			\
	base/files/memory_mapped_file.cc			\
	base/files/scoped_file.cc					\
	base/files/scoped_platform_file_closer.cc	\
	base/files/scoped_temp_dir.cc				\
	$(NULL)

#if OGA_OS_UNKNOWN
# Fake implementation when there's no kqueue, win, or inotify
#libbase_la_SOURCES+=						\
#	base/files/file_path_watcher_stub.cc		\
#	$(NULL)
#endif

if OGA_OS_WIN
libbase_la_SOURCES+=						\
	base/files/file_enumerator_win.cc			\
	base/files/file_path_watcher_win.cc			\
	base/files/memory_mapped_file_win.cc		\
	base/files/file_win.cc						\
	$(NULL)
endif
if OGA_OS_POSIX
libbase_la_SOURCES+=						\
	base/files/file_enumerator_posix.cc			\
	base/files/memory_mapped_file_posix.cc		\
	base/files/file_posix.cc					\
	$(NULL)
endif
if OGA_OS_LINUX
libbase_la_SOURCES+=						\
	base/files/file_path_watcher_linux.cc		\
	$(NULL)
endif

#if OGA_OS_FREEBSD
#libbase_la_SOURCES+=						\
#	base/files/file_path_watcher_kqueue.cc		\
#	$(NULL)
#endif


#
# base/time
#

libbase_la_SOURCES+=					\
	base/time/clock.cc					\
	base/time/default_clock.cc			\
	base/time/default_tick_clock.cc		\
	base/time/tick_clock.cc				\
	base/time/time.cc					\
	$(NULL)

if OGA_OS_POSIX
libbase_la_SOURCES+=		\
	base/time/time_posix.cc	\
	$(NULL)
endif

if OGA_OS_WIN
libbase_la_SOURCES+=		\
	base/time/time_win.cc	\
	$(NULL)
endif

#
# base/timer
#

libbase_la_SOURCES+=				\
	base/timer/elapsed_timer.cc		\
	base/timer/timer.cc				\
	$(NULL)

if OGA_OS_POSIX
libbase_la_SOURCES+=							\
	base/timer/hi_res_timer_manager_posix.cc	\
	$(NULL)
endif

if OGA_OS_WIN
libbase_la_SOURCES+=						\
	base/timer/hi_res_timer_manager_win.cc	\
	$(NULL)
endif

#
# base/power_monitor
#

libbase_la_SOURCES+=											\
	base/power_monitor/power_monitor.cc							\
	base/power_monitor/power_monitor_device_source.cc			\
	base/power_monitor/power_monitor_source.cc					\
	$(NULL)

if OGA_OS_POSIX
libbase_la_SOURCES+=											\
	base/power_monitor/power_monitor_device_source_posix.cc		\
	$(NULL)
endif

if OGA_OS_WIN
libbase_la_SOURCES+=											\
	base/power_monitor/power_monitor_device_source_win.cc		\
	$(NULL)
endif

#
# base/profiler
#

libbase_la_SOURCES+=					\
	base/profiler/alternate_timer.cc	\
	base/profiler/scoped_profile.cc		\
	base/profiler/tracked_time.cc		\
	$(NULL)

#
# base/debug
#

libbase_la_SOURCES+=									\
	base/debug/alias.cc									\
	base/debug/crash_logging.cc							\
	base/debug/debugger.cc								\
	base/debug/dump_without_crashing.cc					\
	base/debug/profiler.cc								\
	base/debug/sanitizer_options.cc						\
	base/debug/stack_trace.cc							\
	base/debug/trace_event_impl.cc						\
	base/debug/trace_event_impl_constants.cc			\
	base/debug/trace_event_memory.cc					\
	base/debug/trace_event_synthetic_delay.cc			\
	base/debug/trace_event_system_stats_monitor.cc		\
	$(NULL)

if OGA_OS_POSIX
libbase_la_SOURCES+=				\
	base/debug/debugger_posix.cc		\
	base/debug/stack_trace_posix.cc		\
	$(NULL)
endif

if OGA_OS_LINUX
libbase_la_SOURCES+=				\
	base/debug/proc_maps_linux.cc		\
	$(NULL)
endif

if OGA_OS_WIN
libbase_la_SOURCES+=				\
	base/debug/debugger_win.cc			\
	base/debug/gdi_debug_util_win.cc	\
	base/debug/stack_trace_win.cc		\
	base/debug/trace_event_win.cc		\
	$(NULL)
endif

#
# base/json
#

libbase_la_SOURCES+=							\
	base/json/json_file_value_serializer.cc 	\
	base/json/json_parser.cc 					\
	base/json/json_reader.cc 					\
	base/json/json_string_value_serializer.cc 	\
	base/json/json_writer.cc 					\
	base/json/string_escape.cc					\
	$(NULL)

#
# base/strings
#

libbase_la_SOURCES+=							\
	base/strings/latin1_string_conversions.cc		\
	base/strings/nullable_string16.cc				\
	base/strings/safe_sprintf.cc					\
	base/strings/string16.cc						\
	base/strings/string_number_conversions.cc		\
	base/strings/string_piece.cc					\
	base/strings/string_split.cc					\
	base/strings/string_util.cc						\
	base/strings/string_util_constants.cc			\
	base/strings/stringprintf.cc					\
	base/strings/utf_offset_string_conversions.cc	\
	base/strings/utf_string_conversion_utils.cc		\
	base/strings/utf_string_conversions.cc			\
	$(NULL)

if OGA_OS_WIN
libbase_la_SOURCES+= base/strings/sys_string_conversions_win.cc
else
libbase_la_SOURCES+= base/strings/sys_string_conversions_posix.cc
endif

#
# base/message_loop
#

libbase_la_SOURCES+=									\
	base/message_loop/incoming_task_queue.cc			\
	base/message_loop/message_loop.cc					\
	base/message_loop/message_loop_proxy.cc				\
	base/message_loop/message_loop_proxy_impl.cc		\
	base/message_loop/message_pump.cc					\
	base/message_loop/message_pump_default.cc			\
	base/message_loop/message_pump_libevent.cc			\
	$(NULL)

if OGA_OS_WIN
libbase_la_SOURCES+=									\
	base/message_loop/message_pump_win.cc				\
	$(NULL)
endif

#
# base/threading
#

libbase_la_SOURCES+=								\
	base/threading/non_thread_safe_impl.cc				\
	base/threading/post_task_and_reply_impl.cc			\
	base/threading/sequenced_worker_pool.cc				\
	base/threading/simple_thread.cc						\
	base/threading/thread.cc							\
	base/threading/thread_checker_impl.cc				\
	base/threading/thread_collision_warner.cc			\
	base/threading/thread_id_name_manager.cc			\
	base/threading/thread_local_storage.cc				\
	base/threading/thread_restrictions.cc				\
	base/threading/watchdog.cc							\
	base/threading/worker_pool.cc						\
	$(NULL)

# if OGA_OS_FREEBSD
# libbase_la_SOURCES+= threading/platform_thread_freebsd.cc
# endif

if OGA_OS_LINUX
libbase_la_SOURCES+=				\
	base/threading/platform_thread_linux.cc	\
	$(NULL)
endif

if OGA_OS_POSIX
libbase_la_SOURCES+=						\
	base/threading/platform_thread_posix.cc			\
	base/threading/thread_local_posix.cc			\
	base/threading/thread_local_storage_posix.cc	\
	base/threading/worker_pool_posix.cc				\
	$(NULL)
endif

if OGA_OS_WIN
libbase_la_SOURCES+=					\
	base/threading/platform_thread_win.cc		\
	base/threading/thread_local_storage_win.cc	\
	base/threading/thread_local_win.cc			\
	base/threading/worker_pool_win.cc			\
	$(NULL)
endif

#
# base/synchronization
#

libbase_la_SOURCES+=							\
	base/synchronization/cancellation_flag.cc	\
	base/synchronization/lock.cc				\
	$(NULL)

if OGA_OS_POSIX
libbase_la_SOURCES+=							\
	base/synchronization/condition_variable_posix.cc		\
	base/synchronization/lock_impl_posix.cc					\
	base/synchronization/waitable_event_posix.cc			\
	base/synchronization/waitable_event_watcher_posix.cc	\
	$(NULL)
endif

if OGA_OS_WIN
libbase_la_SOURCES+=									\
	base/synchronization/condition_variable_win.cc		\
	base/synchronization/lock_impl_win.cc				\
	base/synchronization/waitable_event_watcher_win.cc	\
	base/synchronization/waitable_event_win.cc			\
	$(NULL)
endif

libbase_la_SOURCES+=							\
	base/process/kill.cc						\
	base/process/launch.cc						\
	base/process/memory.cc						\
	base/process/process_iterator.cc			\
	base/process/process_metrics.cc				\
	$(NULL)

if OGA_OS_POSIX
libbase_la_SOURCES+=							\
	base/process/launch_posix.cc				\
	base/process/kill_posix.cc					\
	base/process/process_handle_posix.cc		\
	base/process/process_metrics_posix.cc		\
	base/process/process_posix.cc				\
	$(NULL)
#if OGA_OS_FREEBSD
#libbase_la_SOURCES+=							\
#	base/process/process_handle_freebsd.cc		\
#	base/process/process_iterator_freebsd.cc	\
#	base/process/process_metrics_freebsd.cc		\
#	$(NULL)
#endif
#if OGA_OS_OPENBSD
#libbase_la_SOURCES+=							\
#	base/process/process_handle_openbsd.cc		\
#	base/process/process_iterator_openbsd.cc	\
#	base/process/process_metrics_openbsd.cc		\
#	$(NULL)
#endif
if OGA_OS_LINUX
libbase_la_SOURCES+=							\
	base/process/internal_linux.cc				\
	base/process/memory_linux.cc				\
	base/process/process_handle_linux.cc		\
	base/process/process_info_linux.cc			\
	base/process/process_iterator_linux.cc		\
	base/process/process_metrics_linux.cc		\
	base/process/process_linux.cc				\
	$(NULL)
endif
else
if OGA_OS_WIN
libbase_la_SOURCES+=							\
	base/process/kill_win.cc					\
	base/process/launch_win.cc					\
	base/process/memory_win.cc					\
	base/process/process_handle_win.cc			\
	base/process/process_info_win.cc			\
	base/process/process_iterator_win.cc		\
	base/process/process_metrics_win.cc			\
	base/process/process_win.cc					\
	$(NULL)
else
libbase_la_SOURCES+=							\
	base/process/memory_stubs.cc				\
	$(NULL)
endif
endif



#
# base/third_party
#
libbase_la_SOURCES+=												\
	base/third_party/superfasthash/superfasthash.c					\
	base/third_party/dynamic_annotations/dynamic_annotations.c		\
	base/third_party/symbolize/demangle.cc							\
	base/third_party/symbolize/symbolize.cc							\
	base/third_party/nspr/prtime.cc									\
	base/third_party/icu/icu_utf.cc									\
	base/third_party/dmg_fp/dtoa.cc									\
	base/third_party/dmg_fp/dtoa_wrapper.cc							\
	base/third_party/dmg_fp/g_fmt.cc								\
	$(NULL)

#
# base/posix
#
if OGA_OS_POSIX
libbase_la_SOURCES+=									\
	base/posix/file_descriptor_shuffle.cc				\
	base/posix/global_descriptors.cc					\
	$(NULL)
endif

if OGA_OS_LINUX
libbase_la_SOURCES+=								\
	base/posix/unix_domain_socket_linux.cc			\
	$(NULL)
endif

#
# base/win
#
if OGA_OS_WIN
libbase_la_SOURCES+=								\
	base/win/enum_variant.cc						\
	base/win/event_trace_controller.cc				\
	base/win/event_trace_provider.cc				\
	base/win/i18n.cc								\
	base/win/iat_patch_function.cc					\
	base/win/iunknown_impl.cc						\
	base/win/message_window.cc						\
	base/win/metro.cc								\
	base/win/object_watcher.cc						\
	base/win/pe_image.cc							\
	base/win/registry.cc							\
	base/win/resource_util.cc						\
	base/win/scoped_bstr.cc							\
	base/win/scoped_handle.cc						\
	base/win/scoped_process_information.cc			\
	base/win/scoped_variant.cc						\
	base/win/shortcut.cc							\
	base/win/startup_information.cc					\
	base/win/windows_version.cc						\
	base/win/win_util.cc							\
	base/win/wrapped_window_proc.cc					\
	$(NULL)
endif

#
# ipc
#
libipc_la_CXXFLAGS=-DIPC_IMPLEMENTATION -I.
libipc_la_SOURCES=								\
	ipc/file_descriptor_set_posix.cc			\
	ipc/ipc_channel.cc							\
	ipc/ipc_channel_posix.cc					\
	ipc/ipc_channel_proxy.cc					\
	ipc/ipc_channel_reader.cc					\
	ipc/ipc_forwarding_message_filter.cc		\
	ipc/ipc_logging.cc							\
	ipc/ipc_message.cc							\
	ipc/ipc_message_utils.cc					\
	ipc/ipc_platform_file.cc					\
	ipc/ipc_switches.cc							\
	ipc/ipc_sync_channel.cc						\
	ipc/ipc_sync_message.cc						\
	ipc/ipc_sync_message_filter.cc				\
	ipc/message_filter.cc						\
	ipc/message_filter_router.cc				\
	$(NULL)

if OGA_OS_WIN
libipc_la_SOURCES+=								\
	ipc/ipc_channel_win.cc						\
	$(NULL)
else
libipc_la_SOURCES+=								\
	ipc/ipc_channel_factory.cc					\
	ipc/unix_domain_socket_util.cc				\
	$(NULL)
endif

#
# third_party/libevent
#

libevent_la_CFLAGS=-DHAVE_CONFIG_H
libevent_la_LDFLAGS=$(LDFLAGS)
libevent_la_SOURCES=								\
	third_party/libevent/buffer.c					\
	third_party/libevent/evbuffer.c					\
	third_party/libevent/evdns.c					\
	third_party/libevent/event.c					\
	third_party/libevent/event_tagging.c			\
	third_party/libevent/evrpc.c					\
	third_party/libevent/evutil.c					\
	third_party/libevent/http.c						\
	third_party/libevent/log.c						\
	third_party/libevent/poll.c						\
	third_party/libevent/select.c					\
	third_party/libevent/signal.c					\
	third_party/libevent/strlcpy.c					\
	$(NULL)

if OGA_OS_LINUX
libevent_la_LDFLAGS+=-lrt
libevent_la_CFLAGS+=-Ithird_party/libevent/linux
libevent_la_SOURCES+=third_party/libevent/epoll.c
endif

